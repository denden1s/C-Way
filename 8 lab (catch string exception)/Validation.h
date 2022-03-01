#include <iostream>
#include <string> 
#include "MyEx.h"
using namespace std;

  class DataValidation
  {
    protected:
    MyEx *ex;
    public:
    DataValidation()
    {
      ex = new MyEx("Default exception");
    }
    virtual void FindException(string str)
    {
      cout << "standart" << endl;
    }
  };

  class EnglishSymbols : public DataValidation
  { 
    public:
    EnglishSymbols() : DataValidation()
    {
      ex = new MyEx("English symbols exception");
    }
    void FindException(string str)
    {
      for(int i = 0; i < str.size(); i++)
        if((str[i] <= 'a' || str[i] >= 'z') &&(str[i] <='A' || str[i] >='Z'))
        {
          cin.setstate(std::ios::failbit);
          throw ex;
        }
    }
  };

  class Nums : public DataValidation
  {
    public:
    Nums() : DataValidation(){
      ex = new MyEx("Num exception");
    }
    void FindException(string str)
    {
      for(int i = 0; i < str.size(); i++)
      {
        for(int j = 0; j < 9; j++)
        {
          //converting j to char
          if(str[i] == j+'0')
          {
            cin.setstate(std::ios::failbit);
            throw ex;
          } 
        }
      }
    }
  };