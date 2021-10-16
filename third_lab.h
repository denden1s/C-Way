#include<iostream>
#include <cstring> 
#include <iomanip>
using namespace std;

class MyString
{
  private:
  char *str;
  public:
  MyString(char *_str)
  {
    str = new char[strlen(_str)+1];
    for (size_t i = 0; i < strlen(_str); i++)
    {
      str[i] = _str[i];
    } 
    str[strlen(_str)] = '\0';
  }
  MyString(const MyString& obj)
  {
    str = new char[strlen(obj.str)+1];
    cout << "copy constructor is called" << endl;
    for (size_t i = 0; i < strlen(obj.str); i++)
    {
      str[i] = obj.str[i];
    }
    str[strlen(obj.str)] = '\0';
  }  
  ~MyString()
  {
    cout << "destructor is called" << endl;
    delete str;
  }

  MyString& operator = (const MyString&);
  MyString& operator += (const MyString&);
  bool operator == (const MyString&);
  bool operator != (const MyString&);
  bool operator < (const MyString&);
  bool operator > (const MyString&);
  
  bool operator <= (const MyString&);
  bool operator >= (const MyString&);
  friend void Display(MyString&);
  friend void ChangeStr(MyString&);
  friend std::ostream& operator<< (std::ostream& out, const MyString& point);
  friend std::istream& operator>> (std::istream& in, MyString& point);
};
void ViewThirdLab();
