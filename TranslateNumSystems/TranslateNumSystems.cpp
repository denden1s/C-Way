#include<string>
#include<iostream>
#include<math.h>

using namespace std;

//нужен для преобразования из 10 системы счисления в иную, которая указана
//вторым агрументом
string ConvertingFromTen(int value, int toNotation)
{
  char *arr = new char[35];
  int index = 0;
  while (value >= toNotation)
    {
      int temp = value % toNotation;
      value = value / toNotation;
      //приведение к символьному виду если системы счисления от 11
      if(temp > 9 && toNotation > 10)
        arr[index++] = (char)(temp + 55);
      else
        arr[index++] = (char)(temp+48);
    }
    //аналогично высшему условию
    if(value > 9 && toNotation > 10)
      arr[index] = (char)(value + 55);
    else
      arr[index] = (char)(value + 48);
    string res = "";
    while (index >=0)
    {
      // т.к. запись по алгоритму идет в обратном порядке, то нужно 
      //сделать реверс (в теории можно было использовать стек)
        res+= arr[index--];
    }
    return res;
}

//приведение в 10 систему счисления
string ConvertingToTen(string nums, int fromNotation)
{
  int result = 0;//запишем результат
  int index = 0;//индекс для перебора массива arr
  int power = nums.length()-1; //значение степеней
  int arr[nums.length()];
  for (size_t i = 0; i < nums.length(); i++)
  {
    //если значением является символ, то происходит приведение к числу
    if((int)nums[i] > 55)
      arr[i] = (int) (nums[i] - 55);
    else
      arr[i] = (int)nums[i] - 48;
  }

  //главный алгоритм приведения
  while(power >=0)
  {
    result+= arr[index++]*pow(fromNotation,power--);
  }
  return to_string(result);
}
int main()
{
  try
  {
    int fromNotation = 0;
    int toNotation = 0;
    cout << "Введите систему счисления из которой нужно будет конвертировать"<< endl;
    cin >> fromNotation;
    cout << "Введите систему счисления в которую нужно будет конвертировать"<< endl;
    cin >> toNotation;
    string value = "";
    cout << "Введите число в системе счисления" << endl;
    cin >> value;
    string tempRes = ConvertingToTen(value, fromNotation);
    string finalResult = ConvertingFromTen(stoi(tempRes), toNotation);
    cout << "Результат приведения: " << finalResult << endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}