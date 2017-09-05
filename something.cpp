#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;
#define max1 1000
#define max6 100
#define max5 20;
int p1(){
  int a = 3;
  int b = 5;
  int sum = 0;
  int multa = 0;
  int multb = 0;
  do{
    multa += a;
    sum += multa;
  }while((multa+a) < max1);
  do{
    multb += b;
    sum += multb;
  }while((multb+b) < max1);
  //cout << "The sum is " << sum << endl;
  return sum;
}

int p6(){
  int s_squared = 0;
  int squared_s = 0;
  for(int i=0;i<max6;i++){
    s_squared += (i+1);
    squared_s += pow((i+1),2);
  };
  s_squared *= s_squared;
  return (s_squared - squared_s);
}

int p5(){
  int num = max5;
  while(num % 2!=0 || num % 3!=0 || num%4!=0 || num%5!=0 || num%6!=0 || num%7!=0 || num%8!=0 || num%9!=0 || num%10!=0 || num % 11!=0 || num % 12!=0 || num%13!=0 || num%14!=0 || num%15!=0 || num%16!=0 || num %17!=0 || num%18!=0 || num%19!=0 || num%20!=0){
    num++;
  }
  
  return num;
}

int main(){
  cout << "The answer to Problem 1: " << p1() << endl;
  cout << "The answer to Problem 5: " << p5() << endl;
  cout << "The answer to Problem 6: " << p6() << endl;
  return 0;
}

