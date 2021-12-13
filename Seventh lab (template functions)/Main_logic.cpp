#include <iostream>
#include <cstring>
#include "SmartPoint.cpp"
using namespace std;

template <typename T>
T max(T& firstEl, T& secondEl)
{
  cout << "called template method" << endl; 
  return firstEl > secondEl ? firstEl : secondEl;
}

char * max(char * f, char * s)
{
  cout << "called overloaded method" << endl;
  return strlen(f) > strlen(s) ? f : s;
}

int main()
{
  char* inputStr = new char[20];
  char* inputSecondStr = new char[20];
  SmartPoint<char> a("a",new char[20]);
  SmartPoint<char> b("b",new char[20]);
  SmartPoint<char> c("c", new char[20]);
  c = a;
  cout << "Enter first string" << endl;
  cin >> inputStr;
  cout << "Enter second string" << endl;
  cin >> inputSecondStr;
  a.SetValue(inputStr);
  b.SetValue(inputSecondStr);
  char* charResult = max(a.GetValue(),b.GetValue()); // called overloaded method
  int num, sNum;
  cout << "Enter first num" << endl;
  cin >> num;
  cout << "Enter second num" << endl;
  cin >> sNum;
  int result = -1;
  result = max(num, sNum);
  bool t = true;
  bool f = false;
  bool res = max(t,f);
  cout << "char: " << charResult << endl;
  cout << "int: " << result << endl;
  cout << "bool: " << res << endl;
  return 0;
}