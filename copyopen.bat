Q:
cd \cmpINFRA_CommonParsers
del /S/Q/F *.1 *.2 *.3 *.4 *.5 *.keep *.contrib
C:
CD \snapshots
rmdir /s/q JDFOpensrc
mkdir JDFOpensrc
mkdir JDFOpensrc\docs
Q:
xcopy /H/E/Y /EXCLUDE:JDFOpensrc\exclude.txt .\JDFOpensrc C:\Snapshots\JDFOpensrc
cd snapshots