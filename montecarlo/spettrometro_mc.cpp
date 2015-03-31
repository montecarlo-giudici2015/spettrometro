#include <iostream>
#include "genera_ev.C"
#include "lorentz.h"
#include "lorentz.cpp"
// Idealmente qui vorrei solo includere i vostri file, assicuratevi di avere già voi le librerie necessarie


// serie di costanti usabili da chiunque

const int N = 1000; // # di eventi da simulare

const double smear = 0; // costante di smearing, da cambiare
const double p_kick = 1e308; // impulso dato dal magnete, da cambiare

const double z1 = 1;  // distanze dei rivelatori, da cambiare
const double z2 = 2;
const double z3 = 3;
const double z4 = 4;

void spettrometro_mc()  // lei fa tutta la magia
{
	double* x11 = new double[N]; // vettori dei risultati, definiti nella maniera più facile possibile
	double* x12 = new double[N];
	double* x13 = new double[N];
	double* x14 = new double[N];
	
	double* x21 = new double[N];
	double* x22 = new double[N];
	double* x23 = new double[N];
	double* x24 = new double[N];
	
	double* y11 = new double[N]; // vettori dei risultati, definiti nella maniera più facile possibile
	double* y12 = new double[N];
	double* y13 = new double[N];
	double* y14 = new double[N];
	
	double* y21 = new double[N];
	double* y22 = new double[N];
	double* y23 = new double[N];
	double* y24 = new double[N];
	
	double* cammino = new double[N];
	double* energia = new double[N];
	
	double* th1 = new double[N];
	double* th2 = new double[N];
	double* p1  = new double[N];
	double* p2  = new double[N];
	
	genera_ev_init();  // init 1
	theta_init();      // init 2
	
	for (int i=0; i<N; ++i)
	{
		// punto 1
		energia[i] = genera_ev_energia();
		cammino[i] = genera_ev_cammino(energia[i]);
		
		// punto 2
		double th_cm = genera_theta();
		th1[i] = genera_th1(th_cm, energia[i]);
		th2[i] = genera_th2(th_cm, energia[i]);
		p1 [i] = genera_p1 (th_cm, energia[i]);
		p2 [i] = genera_p2 (th_cm, energia[i]);
		
		// punto 3
		//double x11_provv = la funzione che fa l'intersezione, e così via...
		
		// punto 4
		//double phi = una qualche funzione che estrae \phi
		//x11[i] = una qualche funzione di \phi che ruota i punti intorno l'asse del fascio, "smeara" e restituisce x
		//così via per tutte le x e le y dei primi 2 rivelatori
		
		// punto 5
		//x13[i] = una qualche funzione di x11, x12, y11, y12 e p_kick che restituisca la coord sul terzo ril.
		// così via per y e per tutti i rivelatori e la 2° particella
		
	}
	// a questo punto i vettori sono pieni, si passa alla scrittura su file
	
	// punto 6a
	// aprite un file, scriveteci dentro le cose, ci sono svariati modi di farlo, non sto a imporne uno
	// do_some_magic_with_files_and_all_the_arrays(...);
	
	// stampa un messaggio che dice all'utonto che tutto è andato a buon fine
	
	// ci vediamo sull'altro file
}

int main(int, char**)
{
	// questa funzione non serve a nulla, solo a farlo compilare con g++
	spettrometro_mc();
	return 0;
}

