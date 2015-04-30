#include <cstdlib>
#include <fstream>

#include "lorentz.h"

using namespace std;

int main ()
{
  theta_init();
  int i;
  ofstream file;
  file.open("theta.dat");
  for(i=0;i<1e5;i++) file << theta() << endl;
  file.close();
  return 0;
}