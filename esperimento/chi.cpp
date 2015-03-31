#include <iostream>
#include <TMath.h>
#include <cmath>
#include <TMinuit.h>
#include <TRandom3.h>

double pi= 3.1415;

double alpha_v[3];
double alpha_m[3];
double alpha_r[3];
double sigma = 1./120. ;
double pars[4];
int npars = 4;

void minimizz();
void min_func(Int_t &npars, Double_t* gin, Double_t &f, Double_t* pars, Int_t iflag);

void chi(){
  TRandom3 rndgen;

  double r1,r2;
  r1 =rndgen.Uniform();
  r2 =rndgen.Uniform();

  // prova 1
  alpha_v[0] = pi*r1;
  alpha_v[1] = (pi-alpha_v[0])*r2;
  alpha_v[2] = pi -alpha_v[0]-alpha_v[1];
  // prova 2  somma altezze : estrai punto triangolo equilatero + distanza punto-retta

  //smearing gaussiano
  for (int i=0;i<3;i++){
    r1 = rndgen.Uniform();
    r2 = rndgen.Uniform();
    double gauss = sqrt(-2*log(r1))*cos(2*pi*r2);
    alpha_m[i]= alpha_v[i]+sigma*gauss;
  }

  //minimizza  F= chi- vincolo
  minimizz();  



}


/////////////////////////////////////////////////////////////////////////////////////

// funzione da minimizzare 

void min_func(Int_t &npars, Double_t* gin, Double_t &f, Double_t* pars, Int_t iflag) {
  double chi2 = 0;
  for (int i = 0; i < 3; i++) {    
    //   chi2 += TMath::Power((y[i]-pars[0]*x[i]-pars[1]*x[i]*x[i])/sigma,2);
    chi2 += TMath::Power((alpha_m[i]-pars[i])/sigma,2);
  }
  chi2 += pars[3]*(pi-pars[0]-pars[1]-pars[2]); 
  f = chi2;
}


void minimizz() {

  Int_t ierflg = 0;

  double pars_error[4]; 
  double pars_init[4];
  
  // inizializza minuit con npars e gli attribuisce fcn da minimizzare
  TMinuit* minuit = new TMinuit(npars);
  minuit->SetFCN(min_func);
  
  

  //inizializzazione parametri & errori

  for (int i = 0; i < 4; i++) {
    //cout << "inizializza parametro " <<i+1<<" ="<<endl;
    //cin >> pars_init[i];
    pars_init[0] = alpha_m[0];
    pars_init[1] = alpha_m[1];
    pars_init[2] = alpha_m[2];
    pars_init[3] = 1.;
    pars[i] = pars_init[i];
  }

  for (int j=0; j<4; j++){
    //cout << " errore iniziale parametro " <<j<<" ="<<endl;
    //cin >> pars_error[j];
    pars_error[j] = 0.000001;
  }
   
  // SET PARAMETRI : (indice, nome, valore iniziale, errore, limiti)
  minuit->DefineParameter( 0, "a1", pars_init[0], pars_error[0], 0. ,0. );
  minuit->DefineParameter( 1, "a2", pars_init[1], pars_error[1], 0. ,0. );
  minuit->DefineParameter( 2, "a3", pars_init[2], pars_error[2], 0. ,0. );
  minuit->DefineParameter( 3, "lambda", pars_init[3], pars_error[3], 0. ,0. );

  /* double pars_step[];
     for (int j=1; j<=npars; j++){
     pars_step[j] = 0.000001;
     }
     ALTRA DICHIARAZIONE PARAMETRI (indice,nome, valore iniziale, step iniziale, limiti ) 
     minuit->mnparm(0,"m",pars_init[0],pars_step[0],0,0,ierflg);
     minuit->mnparm(1,"a",pars_init[1],pars_step[1],0,0,ierflg); */

  minuit->mnexcm("SET PRInt levl 3",NULL ,0,ierflg);
  minuit->mnexcm("SCAN", NULL, 0, ierflg);
  minuit->mnexcm("MIGRAD", NULL, 0, ierflg);
  minuit->mnexcm("HESSE", NULL, 0, ierflg);


  Double_t amin, edm, errdef;
  Int_t nvpar, nparx, icstat;
  // forma output 
  minuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
  
  minuit->mnprin(3,amin);
  
  
}

