#include"../8 lab (catch string exception)/Validation.h"
#include<iostream>
#include<string>
using namespace std;

class OnlyNums : public DataValidation
  {
  public:
    OnlyNums()
    {
      ex = new MyEx("String have not only nums");
    }
    void FindException(string str)
    {
      for(int i = 0; i < str.size(); i++)
        if((str[i] < '0' || str[i] > '9'))
        {
          cin.setstate(std::ios::failbit);
          throw ex;
        }
    }
  };

class BankAccount
{
  friend std::ostream& operator<<(std::ostream& os, BankAccount& data)
  {
    cout << "card num: " << data.cardNumber << endl;
    return os;
  }
  friend std::istream& operator>>(std::istream& is, BankAccount& data)
  {
    is.setstate(std::ios::goodbit);
    is >> data.cardNumber;
    data.validation->FindException(data.cardNumber);
    return is;
  }
private:
  string cardNumber; 
  DataValidation *validation;
public:
  BankAccount(DataValidation *_validation = new OnlyNums())
  {
    validation = _validation;
  }
  void InputCardNum()
  {
    cout << "enter card number" << endl;
      do
      {
        try
        {
          cin.clear();//очистка состояний потока
          //rewind(stdin); можно чистить сам поток
          cin >> *this;
        }
        catch(MyEx* exception)
        {
          exception->Show();
          cout << "please enter correct card number" << endl;
        }
      } while (!cin.good());
      cout << "data is valid" << endl;
  }
};

int main()
{
  BankAccount myAccount(new OnlyNums());
  myAccount.InputCardNum();
  cout << myAccount;
  return 1;
}