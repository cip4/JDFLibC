S:
cd S:\cmpINFRA_CommonParsers
del /S/Q/F *.1 *.2 *.3 *.4 *.5 *.keep *.contrib
D:
CD \snapshots
rmdir /s/q JDFOpensrc
mkdir JDFOpensrc
S:
xcopy /H/E/Y /EXCLUDE:JDFOpensrc\exclude.txt .\JDFOpensrc D:\Snapshots\JDFOpensrc
D:
cd snapshots