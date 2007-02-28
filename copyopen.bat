P:
cd \
C:
CD \snapshots
rmdir /s/q JDFLibC
mkdir JDFLibC
mkdir JDFLibC\docs
P:
xcopy /H/E/Y /EXCLUDE:JDFLibC\exclude.txt .\JDFLibC C:\Snapshots\JDFLibC