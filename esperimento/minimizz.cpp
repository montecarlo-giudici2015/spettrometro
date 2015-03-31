#include <iostream>
#include <TMath.h>
#include <cmath>
#include <TMinuit.h>


double sigma = 0.01;
const int nmeas = 5;
Double_t x[nmeas], y[nmeas];


// fissa numero parametri
const int npars = 2;
//cout << "fissa numero parametri "<<endl;
//cin >>npars;



// SET FCN : definire funzione esterna da minimizzare  npars= numero parametri liberi; f = valore finale funzione ; pars=vettore parametri liberi e costanti; 
void min_func(Int_t &npars, Double_t* gin, Double_t &f, Double_t* pars, Int_t iflag) {
  double chi2 = 0;
  for (int i = 0; i < nmeas; i++) {    
    chi2 += TMath::Power((y[i]-pars[0]*x[i]-pars[1]*x[i]*x[i])/sigma,2);
  }

  // f = 2*pars[0]*pars[0]+3*pars[1]*pars[1]+1;  
  f = chi2;
}


void minimizz() {

  Int_t ierflg = 0;

  double* pars = new double[npars];
  double m_t = 6;
  double a_t = -4;
  double pars_error[npars]; 
  double pars_init[npars];

  // inizializza minuit con npars e gli attribuisce fcn da minimizzare
  TMinuit* minuit = new TMinuit(npars);
  minuit->SetFCN(min_func);
  
  for (int i = 0; i < nmeas; i++){
    x[i] = double(i);
    y[i] = m_t*x[i]+a_t*x[i]*x[i];
  }

  

  //inizializzazione parametri & errori

  for (int i = 0; i < npars; i++) {
    //cout << "inizializza parametro " <<i+1<<" ="<<endl;
    //cin >> pars_init[i];
    pars_init[0] = 8;
    pars_init[1] = 6;
    pars[i] = pars_init[i];
  }

  for (int j=1; j<=npars; j++){
    //cout << " errore iniziale parametro " <<j<<" ="<<endl;
    //cin >> pars_error[j];
    pars_error[j] = 0.000001;
  }
   
  // SET PARAMETRI : (indice, nome, valore iniziale, errore, limiti)
  minuit->DefineParameter( 0, "m", pars_init[0], pars_error[0], 0. ,0. );
  minuit->DefineParameter( 1, "a", pars_init[1], pars_error[1], 0. ,0. );

  /* double pars_step[npars];
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
