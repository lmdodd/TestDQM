TFile * file0 ;
 
void linkplotter(TString fileName="CTP7DQM_link.root"){

 gROOT->LoadMacro("tdrstyle.C");
 setTDRStyle();
// see TError.h and set gErrorIgnoreLevel to one of the values:
// gErrorIgnoreLevel = 3000;
//
 file0 = new TFile(fileName,"READONLY");

 doHisto("RctLinkMonitor","Rct Link Monitor","Link Status", false);;
 doHisto("RctLinkMonitorNot15","Rct Link Monitor Not 0xF","Link Status =/= 0xf", false);;
 doHisto("RctLinkMonitor2D","Link Number Vs 1=!0xf","Link Number", true,true);;
 doHisto("RctLinkMonitorNot15_2D","Rct Link Monitor Not 0xF per Link","Link Number", true);;
}

void doHisto(TString name="RctBitHfPlusTauEtaPhi", TString label="Test", TString xaxis="X Axis",  bool do2D=true, bool do01=false){
 TCanvas* C1= new TCanvas("T"+name);
 TH1F *histo=(TH1F*)file0->Get("DQMData/L1T/LinkDQM/"+name);
 if(do2D) {
          histo->Draw("colz,text");
          histo->SetXTitle(xaxis);
          if (do01){histo->SetYTitle("0 == 0xf");}
          else{histo->SetYTitle("Link Status");}
          histo->SetTitle(label);
 }
 else     {histo->Draw("hist"); 
           C1->SetLogy(true); 
          histo->SetXTitle(xaxis);  
          histo->SetYTitle("Events");
          histo->SetLineWidth(2);
          histo->SetTitle(label);
 }
 C1->SaveAs(name+".png");
}


