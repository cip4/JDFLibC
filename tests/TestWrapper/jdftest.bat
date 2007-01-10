echo off 
rem This batch file creates a description of a three part job of a college textbook
rem a.) cover
rem b.) students insert
rem c.) teachers insert
rem 
rem Process nodes are appended using addJDF and the completed file is consumed by 
rem by eatJDF process simulaters
rem spawning and merging is shown using cutJDF and mergeJDF
rem all intermediate files are stored for reference

rem create an intent
bookJDF bookintent.jdf
checkJDF -q bookintent.jdf

rem create some high level container processes for cover
rem add a Finishing subprocess to the cover
addJDF -i bookintent.jdf -o bookfinish.jdf -J1 -k"Cover Finishing" -tProcessGroup -qComponent -pFoldingParams
checkJDF -q bookfinish.jdf 
rem add a Press subprocess to the cover
addJDF -i bookfinish.jdf -o bookpress.jdf -u -tConventionalPrinting -cMedia -pConventionalPrintingParams -hExposedMedia -k"Cover Press"
checkJDF -q bookpress.jdf 
rem add a Prepress subprocess to the cover
addJDF -i bookpress.jdf -o bookprepress.jdf -u -rExposedMedia -k"Cover Prepress"  -tProcessGroup
checkJDF -q bookprepress.jdf 

rem add platemaking of the cover
addJDF -i bookprepress.jdf -o bookplate1.jdf  -rExposedMedia -tImageSetting -kPlateMaking -cMedia -n5 -pImageSetterParams  -hExposedMedia -sCyan,Magenta,Yellow,Black,SpotGreen -k"Cover Platemaking"
checkJDF -q bookplate1.jdf  
rem add filmmaking of the cover
addJDF -i bookplate1.jdf -o bookrip1.jdf  -u -rExposedMedia -tCombined -TImageSetting,Rendering,Screening,Interpreting -k"FilmMaking and Ripping" -cMedia -n5 -pImageSetterParams  -PRenderingParams -sCyan,Magenta,Yellow,Black,SpotGreen -k"Cover Filmmaking"
checkJDF -q bookrip1.jdf  

rem add folding of the cover
addJDF -i bookrip1.jdf  -o bookfold1.jdf -J5 -pFoldingParams -qComponent -tFolding -k"Cover Folding"
checkJDF -q bookfold1.jdf 
rem add cutting of the cover
addJDF -i bookfold1.jdf -o bookcut1.jdf -u -pCuttingParams -qComponent -tCutting -k"Cover Cutting"
checkJDF -q bookcut1.jdf 


rem add a Finishing subprocess to the teachers insert
addJDF -i bookcut1.jdf  -o bookfinish2.jdf -J2 -k"Teacher Insert Finishing" -tProcessGroup -qComponent -pHoleMakingParams
checkJDF -q bookfinish2.jdf 
rem add a Press subprocess to the teachers insert
addJDF -i bookfinish2.jdf -o bookpress2.jdf -u -tConventionalPrinting -cMedia -pConventionalPrintingParams -hExposedMedia -k"Teacher Insert Printing"
checkJDF -q bookpress2.jdf 
rem add a Prepress subprocess to the teachers insert
addJDF -i bookpress2.jdf -o bookprepress2.jdf  -u -rExposedMedia -kPrepress  -tProcessGroup -k"Teacher Insert Prepress"
checkJDF -q bookprepress2.jdf  

rem add platemaking of the teachers insert
addJDF -i bookprepress2.jdf -o bookplate2.jdf  -rExposedMedia -tImageSetting -cMedia -n5 -pImageSetterParams  -hExposedMedia -sCyan,Magenta,Yellow,Black,SpotGreen -k"Teacher Insert PlateMaking"
checkJDF -q bookplate2.jdf  
rem add filmmaking of the teachers insert
addJDF -i bookplate2.jdf -o bookrip2.jdf  -u -rExposedMedia -tCombined -TImageSetting,Rendering,Screening,Interpreting -k"FilmMaking and Ripping" -cMedia -n5 -pImageSetterParams  -PRenderingParams -sCyan,Magenta,Yellow,Black,SpotGreen -k"Teacher Insert FilmMaking"
checkJDF -q bookrip2.jdf  

rem add folding of the teachers insert
addJDF -i bookrip2.jdf  -o bookfold2.jdf -J12 -pFoldingParams -qComponent -tFolding -k"Teacher Insert Folding"
checkJDF -q bookfold2.jdf 
rem add filmmaking of the teachers insert
addJDF -i bookfold2.jdf -o bookcut2.jdf -u -pCuttingParams -qComponent -tCutting -k"Teacher Insert Cutting"
checkJDF -q bookcut2.jdf 


rem add a Finishing subprocess to the students insert
addJDF -i bookcut2.jdf  -o bookfinish3.jdf -J4 -kFinishing -tProcessGroup -qComponent -pHoleMakingParams -k"Student Insert Finishing"
checkJDF -q bookfinish3.jdf 
rem add a Press subprocess to the students insert
addJDF -i bookfinish3.jdf -o bookpress3.jdf -u -tConventionalPrinting -cMedia -pConventionalPrintingParams -hExposedMedia -k"Student Insert Printing"
checkJDF -q bookpress3.jdf 
rem add a Prepress subprocess to the students insert
addJDF -i bookpress3.jdf -o bookprepress3.jdf  -u -rExposedMedia -tProcessGroup -k"Student Insert Prepress"
checkJDF -q bookprepress3.jdf  

rem add platemaking of the students insert
addJDF -i bookprepress3.jdf -o bookplate3.jdf  -rExposedMedia -tImageSetting -cMedia -n5 -pImageSetterParams  -hExposedMedia -sCyan,Magenta,Yellow,Black,SpotGreen -k"Student Insert PlateMaking"
checkJDF -q bookplate3.jdf  
rem add filmmaking of the students insert
addJDF -i bookplate3.jdf -o bookrip3.jdf  -u -rExposedMedia -tCombined -TImageSetting,Rendering,Screening,Interpreting -k"FilmMaking and Ripping" -cMedia -n5 -pImageSetterParams  -PRenderingParams -sCyan,Magenta,Yellow,Black,SpotGreen -k"Student Insert FilmMaking"
checkJDF -q bookrip3.jdf  

rem add folding of the students insert
addJDF -i bookrip3.jdf  -o bookfold3.jdf -J19 -pFoldingParams -qComponent -tFolding -k"Student Insert Folding"
checkJDF -q bookfold3.jdf 
rem add filmmaking of the students insert
addJDF -i bookfold3.jdf -o bookcut3.jdf -u -pCuttingParams -qComponent -tCutting -k"Student Insert Cutting"
checkJDF -q bookcut3.jdf 


rem now some process simulation:
eatJDF -i bookcut3.jdf -o bookDoneFilm.jdf -tCombined
checkJDF -q bookDoneFilm.jdf 
eatJDF -i bookDoneFilm.jdf -o bookDonePlate.jdf -tImageSetting
checkJDF -q bookDonePlate.jdf 
rem this one is a snafu - no plates...
eatJDF -i bookDoneFilm.jdf -o bookDoneNoPlate.jdf -tConventionalPrinting 
checkJDF -q bookDoneNoPlate.jdf 
rem this press part is inline
eatJDF -i bookDonePlate.jdf -o bookDonePress.jdf -tConventionalPrinting 
checkJDF -q bookDonePress.jdf 

rem spawn the cover conventional printing
SpawnJDF -i bookdoneplate.jdf -o cutCoverPress.jdf -p6
checkJDF -q cutCoverPress.jdf 
checkJDF -q _bookdoneplate.jdf 
rem process spawned cover conventional printing
eatJDF -i cutCoverPress.jdf -o CoverDonePress.jdf -tConventionalPrinting 
checkJDF -q CoverDonePress.jdf 
rem merge back the cover conventional printing
rem note the _ in _bookdoneplate.jdf -- the file is created by cutJDF
mergeJDF _bookdoneplate.jdf CoverDonePress.jdf -o CoverMerged.jdf
checkJDF -q CoverMerged.jdf
