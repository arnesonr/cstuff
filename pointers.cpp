#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
  int a = 20;
  int b = 10;
  
  char * c = "hello";

  cout << "This is c: " << c << endl;
  cout << "This is c[1]: " << c[1] << endl;
  cout << "This is *c: " << *c << endl;
  *c++;
  cout << "This is *c+1 : " << *c << endl;
  cout << "This is &c: " << &c << endl;

  return 0;
}
