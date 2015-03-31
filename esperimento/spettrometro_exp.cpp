#include <iostream>
// Idealmente qui vorrei solo includere i vostri file, assicuratevi di avere già voi le librerie necessarie


// serie di costanti usabili da chiunque

const double p_kick = 1e308; // impulso dato dal magnete, da cambiare

const double z1 = 1;  // distanze dei rivelatori, da cambiare
const double z2 = 2;
const double z3 = 3;
const double z4 = 4;


int spettrometro_exp()
{
	// punto 6b
	// leggiamo il file scritto prima, troviamo il numero di eventi
	// (o lo supponiamo noto, dipende come vi sta comodo) e sistemiamo tutti i numerelli negli array
	// do_the_reverse_magic_with_files_and_all_the_arrays(...);
	
	/*
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
	
	double* cammino = new double[N];  // non li abbiamo davvero, servono solo a vedere se torna il risultato
	double* energia = new double[N];
	
	double* th1 = new double[N];
	double* th2 = new double[N];
	double* p1  = new double[N];
	double* p2  = new double[N];
	*/
	
	double* cammino_ric = new double[N];  // qui ci vanno i ricostruiti
	double* energia_ric = new double[N];
	
	double* th1_ric = new double[N];
	double* th2_ric = new double[N];
	double* p1_ric  = new double[N];
	double* p2_ric  = new double[N];
	
	/* definizioni di svariati istogrammi e canvas*/
	
	int i;
	for (i=0; i<N; ++i) {
		// punto 7
		//double delta_theta1 = una qualche funzione che mangi tutte le coordinate possibili e ritorni la variazione d'angolo dovuta al campo
		//double delta_theta2 = una qualche funzione che mangi tutte le coordinate possibili e ritorni la variazione d'angolo dovuta al campo
		//p1_ric[i] = magic(delta_theta1, p_kick) // dove magic() ritorna il momento ricostruito 
		//p2_ric[i] = magic(delta_theta2, p_kick) // dove magic() ritorna il momento ricostruito 
		
		//punto 8
		//cammino_ric[i]= formulaccia che mangia le coordinate e da la coordinata ricostruita
		
		// punto 9
		// idem a sopra, ma com energia_ric[i]
		// idem a sopra, ma calcoliamo la massa invariante
		
		// NOTA: per ogni valore generato lo mettiamo anche nel suo istogramma
	}
	
	/* plot di qualsiasi cosa*/
	
	return 0;
}

int main(int, char**)
{
	// questa funzione non serve a nulla, solo a farlo compilare con g++
	spettrometro_exp();
	return 0;
}
