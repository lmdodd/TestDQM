import FWCore.ParameterSet.Config as cms

l1tctp7 = cms.EDAnalyzer("L1TCTP7",
    DQMStore = cms.untracked.bool(True),
    disableROOToutput = cms.untracked.bool(False),
    outputFile = cms.untracked.string('./L1TDQM.root'),
    ctp7Source = cms.InputTag("ctp7ToDigi"),
    verbose = cms.untracked.bool(False)
)

ctp7link = cms.EDAnalyzer("L1TCTP7",
    DQMStore = cms.untracked.bool(True),
    disableROOToutput = cms.untracked.bool(False),
    outputFile = cms.untracked.string('./L1TDQM.root'),
    ctp7Source = cms.InputTag("ctp7ToDigi"),
    verbose = cms.untracked.bool(False)
)


p = cms.Path(
    cms.SequencePlaceholder("l1tctp7")
    )




