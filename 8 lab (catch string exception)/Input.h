#include<iostream>
#include<string>
#include "Validation.h"
using namespace std;
namespace inputException
{
  //Its functional class, need one object in system
  class Input
  {
    private:
      string data;
      DataValidation *validation;
    public: 
    Input(DataValidation* _validation = new Nums())
    {
      validation = _validation;
    }
    friend std::istream& operator>>(std::istream& is, Input& data)
    {
      is.setstate(std::ios::goodbit);
      is >> data.data;
      data.validation->FindException(data.data);
      return is;
    }
    //function take string and change him in main program
    string InputData()
    {
      cout << "enter text" << endl;
      do
      {
        try
        {
          cin.clear();// rewind better
          //проверка английских символов
          cin >> *this;
        }
        catch(MyEx* exception)
        {
          exception->Show();
          cout << "please enter correct data" << endl;
        }
      } while (!cin.good());// if set state: failbad cin.bad() return 0! 
      cout << "data is valid" << endl;
      return this->data;
    } 
  };
} // namespace inputException