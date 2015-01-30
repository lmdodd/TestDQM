#!/bin/bash
cmsRun CTP7ToDigi_cfg.py >& capture.log

cmsRun CTP7DQM_cfg.py   >& dqm.log 
root -b -q fastplotter.C >& plots.log 


foldername=$(date +%Y%m%d_%H%M%S)
mkdir -p "$foldername" 
mv *png *log "$foldername"
cp testFile.txt "$foldername"
mv outputFile.txt "$foldername"
cp index.html "$foldername"

mv CTP7DQM.root  "$foldername"
rm DQM_V0001_R000000001__L1TMonitor__Calo__CTP7.root

mkdir -p ~/www/CTP7DQMTESTS/Test
cp  "$foldername"/* ~/www/CTP7DQMTESTS/Test

mkdir -p ~/www/CTP7DQMTESTS/
mv "$foldername"  ~/www/CTP7DQMTESTS/
