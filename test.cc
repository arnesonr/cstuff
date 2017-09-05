#include "mcmc.h"

int main(){
  MCMCFile file("mcmc.dat");
  for(int column = 0; column <= file.getNumColumns(); ++column) {
    std::cout << file.getMean(column) << ", " << file.getStdDev(column) << std::endl;
  }
  return 0;
}
