#include <TRandom.h>
//generazione del fascio
//gerera l'energia e la distanza di decadimento

//energia media del fascio (GeV)
#define ENERGY 100

//varianza del fascio (Gev)
#define SPREAD 30

//cammino libero medio del K (m)
#define CTAU 15.34

//massa del K (MeV)
#define KMASS 497.614

TRandom* generatore;

//inizializza il generatore di eventi
void genera_ev_init(int seed=65539){
 //inizializza il generatore
 generatore = new TRandom(seed);
}


//restituisce un'energia da gauss prendendo in argomento il seed
double genera_ev_energia() {

 //generazione di un numero casuale distribuito con una gaussiana di media ENERGY e sigma SPREAD
 double energia=generatore->Gaus(ENERGY, SPREAD);

 return energia;
}

//restituisce un cammino da exp
//prende in argomento l'energia perchè questa allunga il cammino libero medio e il seed del generatore
double genera_ev_cammino(double energia) {

 //converto l'energia in MeV
 energia=1000*energia;
 
 //estrazione costante di dilatazione beta*gamma
 double bg= sqrt(energia*energia-KMASS*KMASS)/KMASS;

 //calcolo del valore del cammino libero medio
 double camminomedio= CTAU*bg;

 //generazione di un numero casuale distribuito come un'esponenziale
 double cammino=generatore->Exp(camminomedio);

 return cammino;
}
