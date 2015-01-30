#ifndef LINKDQM_H
#define LINKDQM_H

// system include files
#include <memory>
#include <unistd.h>


#include <iostream>
#include <fstream>
#include <vector>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

// DQM
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

//Include LinkDQM class
#include "CTP7Tests/LinkMonitor/interface/LinkMonitor.h"
//
// class declaration
//

class LinkDQM : public edm::EDAnalyzer {

public:

// Constructor
  LinkDQM(const edm::ParameterSet& ps);

// Destructor
 virtual ~LinkDQM();

protected:
// Analyze
 void analyze(const edm::Event& e, const edm::EventSetup& c);

// BeginRun
  void beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup);

// BeginJob
 void beginJob(void);

// EndJob
void endJob(void);

private:
  // ----------member data ---------------------------
  DQMStore * dbe;

  //CTP7 Link information
  MonitorElement* ctp7LinkMonitor_;
  MonitorElement* ctp7LinkMonitorNot15_;
  MonitorElement* ctp7LinkMonitor2D_;
  MonitorElement* ctp7LinkMonitorNot15_2D_;

  int nev_; // Number of events processed
  std::string outputFile_; //file name for ROOT ouput
  bool verbose_;
  bool monitorDaemon_;
  std::ofstream logFile_;
  
  edm::EDGetTokenT<LinkMonitorCollection> ctp7Source_LMCollection_;

};

#endif
