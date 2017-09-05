#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cmath>

#include "mcmc.h"

MCMCFile::MCMCFile(const std::string filename){
  std::ifstream ifs(filename.c_str());
  double n;
  while(ifs >> n) {
    _vec.push_back(n);
  }  
}

double MCMCFile::getNumColumns() const{
  return _vec[0];
}

double MCMCFile::getMean(int col) const{
  int elements = _vec.size();
  int n2 = _vec[1];
  double mean(0.0);
  double holder(0.0);
  for(int i=342 + col; i<elements; i+=320) {
    holder += _vec[i];
  }
  return(holder/n2);
}

double MCMCFile::getStdDev(int col) const{
  double stdhold(0.0);
  int elements = _vec.size();
  int n2 = _vec[1];
  double mean = getMean(col);
  for(int i=342+col; i<elements; i+=320){
      stdhold += std::pow((_vec[i]-mean),2);
    }
  return std::sqrt(stdhold/n2);
}

int main(){
  MCMCFile file("mcmc.dat");
  for(int column = 0; column <= file.getNumColumns(); ++column) {
    std::cout << file.getMean(column) << ", " << file.getStdDev(column) << std::endl;
  }
  return 0;
}
