#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
  vector < vector < double > > info;
  ifstream file("mcmc.dat");
  string line;
  while ( getline(file, line) )
    {
      vector < double > data;
      double value;
      istringstream iss(line);
      while (iss >> value)
	{
	  data.push_back(value);
	}
      info.push_back(data);
    }
  for ( vector < vector < double > > :: size_type i = 0, size = info.size(); i < size; ++i)
    {
      cout << "line " << i + 1 << ": ";
      /*for ( vector < double > :: size_type j = 0, length = info[i].size(); j < length; ++j)
	{
	  cout << info[i][j] << " ";
	}
      cout << endl;
      */
      cout << info[i].size() << endl;
    }

  
  return 0;
}
