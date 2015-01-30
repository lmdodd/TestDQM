TFile * file0 ;

void fastplotter(TString fileName="CTP7DQM.root"){

 gROOT->LoadMacro("tdrstyle.C");
 setTDRStyle();
  

 file0 = new TFile(fileName,"READONLY");

 doHisto("RctBitHfPlusTauEtaPhi","Hf Plus Tau Bit");;
 doHisto("RctEmIsoEmEtEtaPhi","EmIso Occupancy (ET in z axis)");;
 doHisto("RctEmIsoEmOccEtaPhi","EmIso Occupancy");;
 doHisto("RctEmNonIsoEmEtEtaPhi","EmNonIso Occupancy (ET in z axis)");;
 doHisto("RctEmNonIsoEmOccEtaPhi","EmNonIso Occupancy");;
 doHisto("RctRegionsEtEtaPhi","Regions Occupancy (ET in z axis)");
 doHisto("RctRegionsOccEtaPhi","Regions Occupancy");;
 doHisto("RctEmIsoEmRank","EmIso Rank",false);;
 doHisto("RctEmNonIsoEmRank","EmNonIso Rank",false);;
 doHisto("RctRegionRank","Regions Rank",false);;
 doHisto("RctRegionRank","Regions Rank Zoomed",false,false,true);;
 doHisto("RctBitMipEtaPhi","Mip Bit");
 doHisto("RctBitOverFlowEtaPhi", "Overflow bit");
 doHisto("RctBitQuietEtaPhi", "Quiet bit");
 doHisto("RctBitTauVetoEtaPhi", "TauVeto bit");
}

//doPUM option used in pumplotter.cc
void doHisto(TString name="RctBitHfPlusTauEtaPhi", TString label="Test", bool do2D=true, bool doPUM=false, bool doZoom=false){
 TCanvas* C1= new TCanvas("T"+name);
 TH1F *histo=(TH1F*)file0->Get("DQMData/L1T/L1TCTP7/"+name);
 if(do2D) {
          histo->Draw("colz,text");
          histo->SetXTitle("#eta");
          histo->SetYTitle("#phi");
          histo->SetTitle(label);
 }
 else if(doPUM){
          histo->Draw("colz,text");
          histo->SetXTitle("PUM bin");
          histo->SetYTitle("Rank");
          histo->SetTitle(label);
 }
 else if(doZoom){
          histo->Draw("hist");
          name=name+"_zoom";
          histo->SetName(name);
          histo->SetXTitle("Rank");
          histo->SetTitle(label);
          histo->SetYTitle("Events");
          histo->SetLineWidth(2);
          histo->GetXaxis()->SetRangeUser(0,50);
 }
 else     {histo->Draw("hist"); 
           C1->SetLogy(true); 
          histo->SetXTitle("RANK");  
          histo->SetYTitle("Events");
          histo->SetLineWidth(2);
          histo->SetTitle(label);
 }


 C1->SaveAs(name+".png");
if (doPUM) doProfile(name,"Avg "+label);;
}
//Duplicate function-- moved pum plots to pumplotter.cc
void doProfile(TString name="RctRegionsPumEta10",TString label="Test"){
 TCanvas* C1= new TCanvas("T"+name);
 TH2F *histo=(TH2F*)file0->Get("DQMData/L1T/L1TCTP7/"+name);
 histo->Draw("colz,text");
 histo->SetXTitle("PUM bin");
 histo->SetYTitle("Average ET");
 histo->SetTitle(label);
 TProfile *prof=histo->ProfileX();
 prof->Draw();
 C1->SaveAs(name+"Avg"+".png");
}

