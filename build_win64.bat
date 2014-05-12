set tmp=
set temp=

call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" amd64

mkdir build64
cd build64
cmake -G "Visual Studio 10 Win64" ..

msbuild JDFOpenSrc.sln /p:Configuration=Debug /m
msbuild JDFOpenSrc.sln /p:Configuration=Release /m

pause
