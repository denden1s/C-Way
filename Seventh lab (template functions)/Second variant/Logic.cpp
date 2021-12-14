#include"List.h"
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
  setlocale(LC_ALL, "Russian");
  List <int>list;
  std:: cout << list.isEmpty() << endl;
  for (size_t i = 0; i < 5; i++)
  {
    list.pushBack(i);
  }
  list.print();
  list.pushStart(222222);
  list.findCount(4);
  list.remove(3);
  cout << "First list after remove" << endl;
  list.print();

  List<string>secondList;
  secondList.pushBack("Diana");
  secondList.pushBack("Pochernyaeva");
  secondList.pushBack("Made");
  secondList.pushStart("This lab");
  std:: cout << secondList.isEmpty() << endl;
  secondList.print();
  secondList.findCount("Diana");
  secondList.remove("Made");
  cout << "Second list after remove" << endl;
  secondList.print();
  return 0;
}