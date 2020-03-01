# A-study-of-solar-wind-data-during-geomagnetic-storms

#1. Abstract

Coronal mass ejections (CMEs) are eruptions from the Sun's corona which throw out huge
amount of solar plasma into interplanetary space. Geomagnetic storms are triggered by CMEs 
particularly when the interplanetary magnetic field (IMF) carried by them are strongly south oriented. The geomagnetic storms can disrupt critical communication infrastructures in space and ground and large power grids. The solar wind data including IMF and plasma velocities measured at Lagrangian 1 (L1) point are made available by NASA at https://omniweb.gsfc.nasa.gov/  This report presents the study of solar wind data during a geomagnetic storm. A code has been developed to read the IMF data from the above-mentioned site and presented graphically.

#2. Introduction

i. Solar Flares and Coronal Mass Ejection

A solar flare occurs when magnetic energy that has built up in the solar atmosphere is suddenly released. On the Sun's surface, there are huge magnetic loops called prominences. When they touch, they short circuit each other, setting off explosions. The amount of energy released is 1020 joules of energy. A solar flare contains high energy photons and particles. It is released from the Sun in a relatively short amount of time (a few minutes).
Solar flares affect all layers of the solar atmosphere (photosphere, chromosphere, and corona). The plasma medium is heated to tens of millions of Kelvin, while electrons, protons, and heavier ions are accelerated to near the speed of light. Flares produce electromagnetic radiation across the electromagnetic spectrum at all wavelengths, from radio waves to gamma rays. Most of the energy is spread over frequencies outside the visual range and so the majority of the flares are not visible to the naked eye and must be observed with special instruments.
Flares occur in active regions around sunspots, where intense magnetic fields penetrate the photosphere to link the corona to the solar interior. Flares are powered by the sudden (timescales of minutes to tens of minutes) release of magnetic energy stored in the corona. The same energy releases may produce coronal mass ejections (CMEs).
The frequency of occurrence of solar flares varies, from several per day when the Sun is particularly active to less than one every week when the Sun is inactive, following the 11-year cycle (the solar cycle).

ii. Geomagnetic Storms

A geomagnetic storm is a temporary disturbance of the Earth's magnetosphere caused by a solar wind shock or cloud of the magnetic field that interacts with the Earth's magnetic field.
During the main phase of a geomagnetic storm, an electric current in the magnetosphere creates a magnetic force that pushes out the boundary between the magnetosphere and the solar wind. The disturbance in the interplanetary medium that drives the storm may be due to a solar coronal mass ejection (CME) or a high-speed stream (co-rotating interaction region or CIR) of the solar wind originating from a region of a weak magnetic field on the Sun's surface. The frequency of geomagnetic storms increases and decreases with the sunspot cycle. CME driven storms are more common during the maximum of the solar cycle, while CIR driven storms are more common during the minimum of the solar cycle.

iii. Effects on Earth                                                                                             X-rays and UV radiation emitted by solar flares can affect Earth's ionosphere and disrupt long-range radio communications. Along with energetic ultraviolet radiation, they heat the Earth’s outer atmosphere, causing it to expand. This increases the drag on Earth-orbiting satellites, reducing their lifetime in orbit. Also, both intense radio emission from flares and    these changes in the atmosphere can degrade the precision of the Global Positioning System (GPS) measurements.
#3. External Tools Used

i. ROOT: Data Analysis Framework
ROOT is a software framework for data analysis and I/O; a powerful tool to cope with the demanding tasks typical of the state of the scientific data analysis. Among its prominent features are an advanced graphical user interface, ideal for interactive analysis, an interpreter for the C++ programming language, for rapid and efficient prototyping and a persistence mechanism for C++ objects, used also to write every year petabytes of data recorded by the Large Hadron Collider experiments. The ROOT Data Analysis Framework itself is written in and heavily relies on the C++ programming language. It is an open source project coordinated by the European Organisation for Nuclear Research, Geneva.

ii. SPDF OMNIweb
The OMNI data set primarily consist of data about the near-Earth solar wind magnetic field and plasma parameter from several spacecraft in geocentric or L1 (Lagrange point) orbits. The data have been extensively cross-compared, and, for some spacecraft and parameters, cross-normalized.
It also provides other widely accessed data that are frequently used with solar wind data. In particular, fluxes of protons with energies above 1, 2, 4, 10, 30, and 60 MeV from several IMP and GOES spacecraft, and provides a wide range of geomagnetic and solar activity indices.


#4. The Code


i. Input Data

The following data for a specific time period was downloaded in the form of text files from SPDF OMNIweb :-


 1 IMF magnitude average, nT

The Interplanetary Magnetic Field (IMF) is a part of the Sun's magnetic field that is carried into interplanetary space by the solar wind. The IMF data is in nanoTesla (nT).

 2 Bx, nT (GSE, GSM)

 3 By, nT (GSE)

 4 Bz, nT (GSE)

The IMF is a vector quantity with three directional components, two of which (Bx and By) are oriented parallel to the ecliptic. The third component Bz is perpendicular to the ecliptic and is created by waves and other disturbances in the solar wind. When the IMF and geomagnetic field lines are oriented opposite or antiparallel to each other, they can merge or reconnect, resulting in the transfer of energy, mass, and momentum from the solar wind flow to magnetosphere The strongest coupling with the most dramatic magnetospheric effects occurs when the Bz component is oriented southward.


 5 Speed, km/s

 6 Vx Velocity,km/s

 7 Vy Velocity, km/s

 8 Vz Velocity, km/s        

V is again a vector quantity with three components Vx, Vy, Vz.        
The downloaded data is usually in the following format - “YYYY-DOY-HR-MIN”        


ii. The Code

A Canvas is an area mapped to a window directly under the control of the display manager. A Canvas may be subdivided into independent graphical areas: the Pads. A canvas has a default pad which has the name of the canvas itself. The function TCanvas( ) creates a new canvas for that specific program.
TGraph is a Graph default constructor provided by ROOT.
The argument of the method Draw("ALP") is important here. It tells the TGraph class to show the axes and to plot markers at the x and y positions of the specified data points.
The downloaded data has chances of noise i.e. some error values. Thus to eliminate these errors, all values of ‘B’ that are greater than 1000 are eliminated.


{
    int iyear, iday, ihour, imin;
    double B, Bx, By, Bz;
    double V, Vx, Vy, Vz; 
   
    double fday; 

    ifstream inf("data.txt");

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
And similarly graphs representing the other values can be obtained by adding the following lines iteratively in the code in place of g1->SetPoint(npt, fday, B); 


g2->SetPoint(npt, fday, Bx);
g3->SetPoint(npt, fday, By);
g4->SetPoint(npt, fday, Bz);
g5->SetPoint(npt, fday, V);
g6->SetPoint(npt, fday, Vx);
g7->SetPoint(npt, fday, Vy);
g8->SetPoint(npt, fday, Vz);

iii. Sample Output
The following is a sample output for the dates 6 May 2005 - 9 May 2005
On the x-axis is the Day Number (Day Of the Year) whereas the y-axis represents the Field Magnitude Average in unit nanotesla (nT).
The peak seen on day 129 clearly depicts that a geomagnetic storm occurred on May 9, 2005.
These values obtained from the above graph can be verified with ‘NASA and the ACE Science Center (SWEPAM, MAG instruments teams) and/or NASA/NOAA DSCOVR (PlasMag instrument team)’ from which we can infer that a geomagnetic storm of Average Field Magnitude 12-14nT was recorded on  8-9 May 2005.


#5. Conclusion
The above code takes the input data of a geomagnetic storm in the form of a text file and produces a graph as the output geomagnetic storms as depicting peaks.





