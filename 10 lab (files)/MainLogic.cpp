#pragma ones
#include"Circle.h"
#include<fstream>
#include<iostream>
#include <vector>
#include<cstring>
using namespace std;


const string fileName = "TenLab.txt";
const char separator = '?';
const int elements = 3;
vector <Circle> Circles;

//проверка существования файла
bool IsEmpty()
{
  ifstream fileToRead(fileName);
  return !fileToRead;
}

void Write(Circle circle)
{
  ofstream fileToWrite;
  if(IsEmpty())
  {
    //создание файла
    ofstream file(fileName);
    file << circle.x << separator << circle.y << separator << circle.r << separator << endl;
    cout << "Create file" << endl;
    file.close();
  }
  else
  {
    cout << "0 - добавление в конец файла, 1 - перезапись" << endl;
    int flag = -1;
    cin >> flag;
    switch (flag)
    {
    case 0:
      fileToWrite.open(fileName, ios_base::app);
      break;
    case 1: 
      fileToWrite.open(fileName, ios_base::trunc);
      break;
    default:
      throw;
      break;
    }
    fileToWrite << circle.x << separator << circle.y << separator << circle.r << separator << endl;
    fileToWrite.close();
  }
}
//читать данные через разделитель
void Read()
{
  ifstream fileToRead;
  //проверка существования файла
  if(!IsEmpty())
  {
    fileToRead.open(fileName, ios_base::in);
    Circle circle;
    string data;
    //очистка перед записью в список
    while(!Circles.empty())
    {
      Circles.pop_back();
    }
    //пока происходит считывание по строке читаем
    while(getline(fileToRead,data))
    {
      int arr[elements];
      int indexForArray = 0;
      string val = "";
      //парсим полученную из файла строку
      for (size_t i = 0; i < data.length(); i++)
      {
        if(data[i] != separator)
          val+= data[i];
        else
        {
          arr[indexForArray++] = stoi(val);
          val = "";
        }
      }
      circle.x = arr[0];
      circle.y = arr[1];
      circle.r = arr[2];
      Circles.push_back(circle);
    }
    fileToRead.close();
  }
  else throw;
}

void BinaryRead()
{
  ifstream fileToRead;
  //проверка существования файла
  if(!IsEmpty())
  {
    while(!Circles.empty())
    {
      Circles.pop_back();
    }
    fileToRead.open(fileName, ios_base::binary);
    int index = 0;
    int arr[elements];
    int buf = 0;
    Circle circle;
    while(!fileToRead.eof())
    {
      if(index < elements)
      {
        fileToRead.read((char*)&buf, sizeof(int));
        arr[index] = buf;
        index++;
      }
      else
      {
        circle.x = arr[0];
        circle.y = arr[1];
        circle.r = arr[2];
        Circles.push_back(circle);
        index = 0;
      }
    }
  }
}

void BinaryWrite(Circle circle)
{
   ofstream fileToWrite;
  if(IsEmpty())
  {
    //создание файла
    ofstream file(fileName, ios_base::binary);
    file.write((char*)&circle.x, sizeof(int));
    file.write((char*)&circle.y, sizeof(int));
    file.write((char*)&circle.r, sizeof(int));
    cout << "Create file" << endl;
    file.close();
  }
  else
  {
    cout << "0 - добавление в конец файла, 1 - перезапись" << endl;
    int flag = -1;
    cin >> flag;
    switch (flag)
    {
    case 0:
      fileToWrite.open(fileName, ios_base::app | ios_base::binary);
      break;
    case 1: 
      fileToWrite.open(fileName, ios_base::trunc | ios_base::binary);
      break;
    default:
      throw;
      break;
    }
      fileToWrite.write((char*)&circle.x, sizeof(int));
      fileToWrite.write((char*)&circle.y, sizeof(int));
      fileToWrite.write((char*)&circle.r, sizeof(int));
      fileToWrite.close();
  }
}

void View()
{
  cout << "X\tY\tr\t"<< endl;
  for (size_t i = 0; i < Circles.size(); i++)
  {
    Circle c = Circles[i];
    cout << c.x << "\t" << c.y << "\t" << c.r <<"\n";
  }
}

int main()
{
  int choise = -1;
  try
  {
    while(true)
    {
      cout << "Выберите действие:" << endl << "1 - записать в файл\t" << "2 - просмотр файла\t"<<"др. выход" <<  endl;
      cin >> choise;
      switch (choise)
      {
        case 1:
          Circle circle;
          cout << "Введите x, y, z" << endl;
          cin >> circle.x >> circle.y >> circle.r;
          BinaryWrite(circle);
          break;
        case 2: 
          BinaryRead();
          View();
          break;
        default:
          exit(1);
          break;
      }
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << endl;
  }
  return 0;
}