set tmp=
set temp=

call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86

mkdir build32
cd build32
cmake -G "Visual Studio 10" ..

msbuild JDFOpenSrc.sln /p:Configuration=Debug /m
msbuild JDFOpenSrc.sln /p:Configuration=Release /m

pause
