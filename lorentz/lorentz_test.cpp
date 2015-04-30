#include <fstream>

#include "lorentz.h"

using namespace std;

int main ()
{
  theta_init();
  int i;
  double th_cm;
  ofstream file;
  file.open("lorentz.dat");
  for (i=0;i<1e5;i++)
  {
    th_cm = theta();
    file << th1(th_cm, 100.) << " " << th2(th_cm, 100.) << " " << p1(th_cm, 100.) << " " << p2(th_cm, 100.) << endl;
  }
  file.close();
} 
