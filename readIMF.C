{

     int iyear, iday, ihour, imin;
     double B, Bx, By, Bz;
     double V, Vx, Vy, Vz; 
    
     double fday; 

     ifstream inf("april.txt");


     TCanvas   *c1  = new TCanvas("c1");

     TGraph *g1=new TGraph();

     int npt=0;
     while (1) 
      {

		inf>>iyear;
                if(!inf.good()) break;
                inf>>iday>>ihour>>imin;
		inf>>B>>Bx>>By>>Bz;
		inf>>V>>Vx>>Vy>>Vz;

	        if(B>1000) continue;	

		fday =  iday + ihour/24.0 + imin/1440.0;
		g1->SetPoint(npt, fday, B);
		npt++;
        }

     g1->Draw("ALP");
 
    c1->SaveAs("IMF.pdf"); 

}
