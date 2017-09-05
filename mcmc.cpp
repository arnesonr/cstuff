#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main(){
  std::ifstream ifs("mcmc.dat");
  std::vector<double> vec;
  
  double n;
  while(ifs >> n)
    {
      vec.push_back(n);
    }  
  //cout << vec.size() << endl;
  //cout << vec[0] << endl;

  //L1 (or the first three elements of the vector) np, n2, n3
  //L2 (np elements) 
  //L3 (np+1 elements)*n3 followed by (n2 elements)*n3
  //L3 repeated L3 repeated n2 times
  //***
  //
  //**See lines.cpp for clever way of counting elements per line**
  //
  //***
  int np=vec[0];
  int n2=vec[1];
  int n3=vec[2];
  int elements=vec.size();
  //start at line 4 (320 elements in L3)
  for(int j=0; j < 20; j++){
    double holder = 0.0;
    double stdhold =0.0;
    double mean =0.0;
    double rms =0.0;
    for(int i=342+j; i<elements; i+=320){
      holder += vec[i];
      rms += pow(vec[i],2);
      //cout << vec[i] << endl;
    }
    mean = (holder/n2);
    rms = sqrt(rms/n2);
    cout << "The mean of parameter: " << j << " is: " << mean << endl;
    cout << "The rms of parameter: " << j << " is: " << rms << endl;
    //calculate the standard deviation
    for(int i=342+j; i<elements; i+=320){
      stdhold += pow((vec[i]-mean),2);
    }
    cout << "The stddev of parameter: " << j << " is: " << sqrt(stdhold/n2) << endl;
  }
  return 0;
}
