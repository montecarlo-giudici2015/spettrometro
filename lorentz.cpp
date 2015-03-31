//Ho usato le formule che ho scritto nel file fact_sheet.pdf. Se ho scritto cazzate dovrebbe vedersi subito.

#include "lorentz.h"

#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

#define XI ((double)rand()/RAND_MAX)
#define m_K 0.49765 //GeV/c^2
#define m_pi 0.139570 //GeV/c^2
#define p_cm (sqrt(pow(m_K,2)/4.-pow(m_pi,2))) //impulso di un singolo pione nel riferimento del cm
#define E_cm (m_K/2.) //Energia di un singolo pione nel riferimento del cm


//Da mettere nel main per inizializzare il generatore
void theta_init()
{
  srand(time(NULL));
}


//Sorteggia un angolo theta da una distribuzione sferica (tale che cos(theta) sia uniforme)
double genera_theta()
{
  return acos(2*XI-1);
}


//Trasformazione th_cm -> th_lab: la funzione restituisce la tangente dell'angolo nel lab. Altre informazioni nel file fact_sheet.pdf
double genera_th1(double th_cm, double E_K)
{
  const double gamma = E_K/m_K;
  const double beta = 1.-0.5*pow(m_K/E_K,2); //l'ordine successivo è -0.125*pow(m_K/E_K,4)
  return sin(th_cm)/gamma/(beta*E_cm/p_cm+cos(th_cm));
}


//Idem per l'angolo \pi-theta_cm
double genera_th2(double th_cm, double E_K)
{
  const double gamma = E_K/m_K;
  const double beta = 1.-0.5*pow(m_K/E_K,2); //l'ordine successivo è -0.125*pow(m_K/E_K,4)
  return sin(th_cm)/gamma/(beta*E_cm/p_cm-cos(th_cm));
}


//Trasformazione pz1_cm -> pz1_lab. L'unità di misura è il Gev/c
double genera_p1(double th_cm, double E_K)
{
  const double gamma = E_K/m_K;
  const double beta = 1.-0.5*pow(m_K/E_K,2); //l'ordine successivo è -0.125*pow(m_K/E_K,4)
  return gamma*(beta*E_cm+p_cm*cos(th_cm));
}


//Idem per il secondo pione
double genera_p2(double th_cm, double E_K)
{
  const double gamma = E_K/m_K;
  const double beta = 1.-0.5*pow(m_K/E_K,2); //l'ordine successivo è -0.125*pow(m_K/E_K,4)
  return gamma*(beta*E_cm+p_cm*cos(th_cm));
}




