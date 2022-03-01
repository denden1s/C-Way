#include<iostream>
#include<string>
#include "Input.h"
using namespace std;
using namespace inputException;

int main()
{
  string name = "";
  EnglishSymbols *valid = new EnglishSymbols();
  Input denis(valid);
  name = denis.InputData();
  cout << "denis name: " << name << endl;
  Input q;
  name = q.InputData();
  cout << name << endl;
  return 0;
}
