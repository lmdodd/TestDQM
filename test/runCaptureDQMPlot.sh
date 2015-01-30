#!/bin/bash 
COUNTER=1
until [  $COUNTER -gt 1 ]; do
    echo COUNTER $COUNTER
    # Run CMSSW Programs
    cmsRun CTP7ToDigi_cfg.py >& capture.log
    cmsRun CTP7DQM_cfg.py   >& dqm.log 
    
    # Plot
    root -b -q fastplotter.C >& plots.log 
    root -b -q pumplotter.C >& pumplots.log 
    root -b -q linkplotter.C >& linkplots.log 
    
    # Format for web
   
    foldername=$COUNTER$(date +_%Y%m%d_%H%M%S)
    mkdir -p "$foldername" 
    mv *png  "$foldername"
    mv *log "$foldername"
    mv outputFile.txt "$foldername"
    cp index.html "$foldername"
    cp *Details.html "$foldername"
    
    mv CTP7DQM.root  "$foldername"
    rm DQM_V0001_R000000001__L1TMonitor__Calo__CTP7.root
    
    mkdir -p ~/www/CTP7DQMTESTS/live
    cp  "$foldername"/* ~/www/CTP7DQMTESTS/live/
    
    mkdir -p ~/www/CTP7DQMTESTS/
    mv "$foldername"  ~/www/CTP7DQMTESTS/
 
    let COUNTER+=1
done
    
