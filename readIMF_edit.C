{
     int iyear, iday, ihour, imin, min_count=0;
     double B, Bx, By, Bz , B_day=0.0;
     double V, Vx, Vy, Vz; 
    
     double fday; 

     ifstream inf("y2000.txt");


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

	    //if(B>1000) continue;	
		if(min_count<1440)
		{	
			min_count++;
			if(B>B_day)
			{
				B_day=B;
			}
		}
		if(min_count==1400)
		{
			min_count=0;
			if(B>B_day)
			{
				B_day=B;
			}
			g1->SetPoint(npt, iday, B_day);
			npt++;
			B_day=0.0;
        }
	  }

     g1->Draw("ALP");
 
    c1->SaveAs("IMF.pdf"); 

}
