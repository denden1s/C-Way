#include"third_lab.h"
#include<iostream>
#include <cstring> 
#include <iomanip>
using namespace std;

MyString& MyString::operator= (const MyString &obj)
{
    cout << "Operator =" << endl;
    if (this->str != nullptr)
    {
        delete str; 
    }
    str = new char[strlen(obj.str) + 1];
    for (size_t i = 0; i < strlen(obj.str); i++)
    {
        str[i] = obj.str[i];
    }
    str[strlen(obj.str)] = '\0';
    return *this;
}

MyString& MyString::operator+= (const MyString &obj)
{
  cout << "Operator +=" << endl;
  char* result;
  result = new char[strlen(str) + 1];
  for (size_t i = 0; i < strlen(str); i++)
  {
      result[i] = str[i];
  }
  result[strlen(str)] = '\0';
  delete str;

  str = new char[strlen(result) + strlen(obj.str) + 1];
  for (size_t i = 0; i < strlen(result); i++)
  {
      str[i] = result[i];
  }
  int index = 0;
  for (size_t i = strlen(result); i < strlen(str)-1; i++)
  {
      str[i] = obj.str[index++];
  }
  str[strlen(str)] = '\0';

  return *this;
}

bool MyString::operator== (const MyString &obj)
{
    cout << "Operator ==" << endl;
    if (strlen(this->str) == strlen(obj.str))
    {
        for (size_t i = 0; i < strlen(this->str); i++)
        {
            if (this->str[i] != obj.str[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MyString::operator!= (const MyString &obj)
{
    cout << "Operator !=" << endl;
    return (strcmp(this->str, obj.str) != 0);
}

bool MyString::operator< (const MyString& obj)
{
    cout << "Operator <" << endl;
    return (strcmp(this->str, obj.str) < 0);
}

bool MyString::operator> (const MyString& obj)
{
    cout << "Operator >" << endl;
    return (strcmp(this->str, obj.str) > 0);
}

bool MyString::operator<= (const MyString& obj)
{
    cout << "Operator <=" << endl;
    return (strcmp(this->str, obj.str) <= 0);
}

bool MyString::operator>= (const MyString& obj)
{
    cout << "Operator >=" << endl;
    return (strcmp(this->str, obj.str) >= 0);
}

void Display(MyString &obj)
{
    for (size_t i = 0; i < strlen(obj.str); i++)
    {
        cout << obj.str[i];
    }
    cout << endl;
}
void ChangeStr(MyString& obj)
{
    if (obj.str != nullptr)
    {
        delete obj.str;
    }
    string newStr;
    cout << "Enter new string: ";
    cin >> newStr;
    obj.str = new char[newStr.length()+1];
    for (size_t i = 0; i < newStr.length(); i++)
    {
        obj.str[i] = newStr[i];
    }
    obj.str[newStr.length()] = '\0';
}

std::ostream& operator<< (std::ostream& out, const MyString& str)
{
    out << "Operator <<" << endl;
    out << str.str << endl;
    return out;
}

std::istream& operator>> (std::istream& in, MyString& str)
{
    cout << "Enter new string: ";
    in >> str.str;
    return in;
}

void ViewThirdLab()
{
    char str[] = "Denis";
    char str1[] = "Nikitin";
    MyString fObj(str);
    MyString sObj(str1);
    cout << fObj;
    cout << sObj;
    
    cout << (fObj != sObj) << endl; // 1
    cout << (fObj > sObj) << endl; // 0
    cout << (fObj < sObj) << endl; // 1
    cout << (fObj >= sObj) << endl; // 0
    fObj = sObj;
    cout << fObj; // Nikitin
    cout << sObj; // Nikitin
    cout << (fObj == sObj) << endl; // 1
    cout << (fObj <= sObj) << endl; // 1
    fObj += sObj; 
    cout << fObj;// NikitinNikitin
    cin >> sObj;
    cout << sObj;
    cout << "end" << endl;
    /*MyString str2 = fObj;
    cout << str2;*/

}