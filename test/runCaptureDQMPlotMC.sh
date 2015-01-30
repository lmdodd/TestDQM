#!/bin/bash
cmsRun CTP7DQMMC_cfg.py   >& dqm.log 
root -b -q fastplotterMC.C >& plots.log 

foldername=$(date +%Y%m%d_%H%M%S)
mkdir -p "mc_$foldername" 
mv *png *log "mc_$foldername"
cp indexMC.html "mc_$foldername"/index.html

mv CTP7DQMMC.root  "mc_$foldername"
rm DQM_V0001_R000000001__L1TMonitor__Calo__CTP7.root

mkdir -p ~/www/CTP7DQMTESTS/mc
cp  "mc_$foldername"/* ~/www/CTP7DQMTESTS/mc

mkdir -p ~/www/CTP7DQMTESTS/
mv "mc_$foldername"  ~/www/CTP7DQMTESTS/
