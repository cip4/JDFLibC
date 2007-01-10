/* include/slist.h : same as k1/a4/slist, but extended with
    erase()
    clear()   for destructor und op=
    empty()
    size()
    iterator::operator==()
    copy c'tor, destructor, assignment operator
*/
#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <vector>
#include <cassert>

//using namespace std;

template<class T>
class slist
{
  public:
    typedef T value_type;
//    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    slist() : firstElement(0), Count(0) {}
    ~slist()
    {
       clear();
    }
    slist(const slist& S) { construct(S);}
    slist& operator=(const slist& S)
    {
         if(this != &S)
         {
            clear();
            construct(S);
         }
         return *this;
    }

    void push_front(const T& Datum) // insert at beginning
    {
      ListElement *temp =  new ListElement(Datum, firstElement);
      firstElement = temp;
      ++Count;
    }
    size_t size() const { return Count;}
    bool empty() const { return Count == 0;}

  private:
    struct ListElement
    {
        T Data;
        ListElement *Next;
        ListElement(const T& Datum, ListElement* p)
        : Data(Datum), Next(p) {}
    };

    ListElement *firstElement;
    size_t Count;

    /* The list consists of list elements whose type is defined inside
       the list class as a nested public class (struct). In a
       structure, direct access to internal data is possible, but this
       is no problem here because the data is located in the private
       section of the slist class. Each list element carries the
       pertinent data, for example a number, together with a pointer
       to the next list element. firstElement is the pointer to the
       first list element. The class slist provides an iterator type
       iterator which is located in the public section since it is to
       be publicly accessible. It is also used in the following main()
       program. An iterator object stores the current container
       position in the current attribute. The methods satisfy the
       requirements formulated for iterators. */

  public:
    class iterator
    {
       public:
         friend class slist<T>;
         iterator(ListElement* Init = 0)
         : current(Init){}

         T& operator*()              // dereferencing
         {
             return current->Data;
         }

         const T& operator*() const  // dereferencing
         {
             return current->Data;
         }

         iterator& operator++()       // prefix
         {
            if(current) // not yet arrived at the end?
               current = current->Next;
            return *this;
         }

         iterator operator++(int)   // postfix
         {
            iterator temp = *this;
            ++*this;
            return temp;
         }

         bool operator==(const iterator& x) const
         {
            return current == x.current;
         }
		bool operator!=(const iterator& x) const
         {
            return current != x.current;
         }

         int operator-(iterator fromWhere)
         {
            int Count = 0;
            while(fromWhere.current != current // not yet reached
                && fromWhere != iterator())  // not yet at the end
           {
              ++Count;
              ++fromWhere;
           }
           assert(current == fromWhere.current);
           return Count;
         }
       private:        
         ListElement* current; // pointer to current element 
    }; // iterator

    iterator begin() const { return iterator(firstElement);}
    iterator end()   const { return iterator();}

      iterator erase(iterator position)
      {
         if(!firstElement) return end(); // empty list
         iterator Successor = position;
         ++Successor;

         // look for predecessor
         ListElement *toBeDeleted = position.current,
                       *Predecessor = firstElement;

          if(toBeDeleted != firstElement)
          {
              while(Predecessor->Next != toBeDeleted)
                  Predecessor = Predecessor->Next;
              Predecessor->Next =
                     toBeDeleted->Next;
         }
         else // delete at firstElement
             firstElement = toBeDeleted->Next;
         delete toBeDeleted;
         Count--;
         return Successor;
      }

      void clear()
      {
         while(begin() != end())
             erase(begin());
      }
      void construct(const slist& S)
      {
         Count = 0;
         firstElement = 0;
         if(S.size())
         {
            /* to guarantee the correct order of sequence, a vector
             buf is used as intermediate storage for pointers
             to the elements */

            ListElement **buf = new ListElement*[S.size()];
            size_t index = S.size();
            ListElement* temp = S.firstElement;
            while(index)
            {
              buf[--index] = temp; // store in reverse order
              temp = temp->Next;
            }
            for(; index < S.size(); index++)
               push_front(buf[index]->Data);
            delete [] buf;
         }
      }
};


#endif // slist

