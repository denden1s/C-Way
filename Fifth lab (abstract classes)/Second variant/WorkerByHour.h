#pragma once
using std::string;
#include"Employee.h"
#include<iostream>
using namespace std;

class WorkerByHour : public Employee
{
private:
  int hoursByWeek;
  double earningRatio;
public:
  WorkerByHour(string _name, string _lastName, int _hours = 0, double ratio = 1):Employee(_name, _lastName)
  {
    hoursByWeek = _hours;
    earningRatio = ratio;
  }
  ~WorkerByHour()
  {
    cout << "Delete worker by hour" << endl;
  }
  void SetHours(int _hours)
  {
    hoursByWeek = _hours >= 0 ? _hours : 0;  
  }
  int GetHours()
  {
    return hoursByWeek;
  }
  void SetRatio(double _ratio)
  {
    earningRatio = _ratio >= 0 ? _ratio : 1;  
  }
  void ViewInfo()
  {
    cout << "Рабтник: " << GetName() << " " << GetLastName() 
    << " Кол-во часов в неделю: " << hoursByWeek << " ставка: " << earningRatio << endl;
  }
};