#pragma once
#include"Employee.h"
using std::string;
#include<iostream>
using namespace std;

class ItemWorker : Employee
{
private:
  double priceOnItem;
  int itemsCountByWeek;
public:
  ItemWorker(string _name, string _lastName, double _price = 0, int _itemsCount = 0) : Employee(_name,_lastName)
  {
    priceOnItem = _price;
    itemsCountByWeek = _itemsCount;
  }
  ~ItemWorker()
  {
    cout << "Delete Item worker" << endl;
  }
  void SetPrice(double _price)
  {
    priceOnItem = _price >=0 ? _price : 0;
  }
  double GetPrice()
  {
    return priceOnItem;
  }
  void SetItemsCount(int _count)
  {
    itemsCountByWeek = _count > 0 ? _count : 0; 
  }
  int GetItemsCount()
  {
    return itemsCountByWeek;
  }
    void ViewInfo()
  {
    cout << "Рабтник: " << GetName() << " " << GetLastName() 
    << " Цена за единицу товара: " << priceOnItem << " Кол-во товара в неделю: " << itemsCountByWeek << endl;
  }
};