#pragma once
using std::string;
#include<iostream>
using namespace std;

class Employee
{
private:
  string name;
  string lastName;
public:
  Employee(){}
  Employee(string _name, string _lastName)
  {
    name = _name;
    lastName = _lastName;
  }
  ~Employee() 
  {
  cout << "Base destructor"<< endl;
  };
  void SetName(string _name)
  {
    name = _name; 
  }
  void SetLastName(string _lastName)
  {
    lastName = _lastName;
  }
  string GetName()
  {
    return name;
  }
  string GetLastName()
  {
    return lastName;
  }
   //Чисто виртуальная функция - создает абстракцию
  virtual void ViewInfo() =0;
};