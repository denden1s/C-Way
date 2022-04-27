#pragma once  
#include<iostream>
#include "Stack.h"
using namespace std;

template<typename T>
class Algorythm
{
private:
  //typename Stack<T>::Iterator *iterator;
  T* first;
  T* last;
public:
  Algorythm(T* firstElement, T* lastElement)
  {
   
    first = firstElement;
    last = lastElement;
    //iterator = new typename Stack<T>::Iterator(firstElement, lastElement);
  }
 /* ~Algorythm()
  {
    delete iterator;
  }*/
  void sort()
  {
    cout << "Start sorting" << endl;
    typename Stack<T>::Iterator iter(first, last);
    T* temp = nullptr;
    int itemsCount = 0;
    int index = 0;
    while(&(iter + index) != last) 
      index++;

    itemsCount = index + 1;
    for (size_t i = 0; i < itemsCount; i++)
    {
      for (size_t j = itemsCount - 1; j > i; j--)
      {
        temp = nullptr;
        int tmpj  = j-1;
        if((iter +  j) < (iter + tmpj))
        {
          T* linkForNextValue = &(iter +  tmpj);
          T nextValue = (iter +  tmpj);
          T* linkForCurrentValue = &(iter +  j);
          temp = &(iter +  tmpj);
          *linkForNextValue = (iter + j);
          *linkForCurrentValue = nextValue;
        }
      }
    }
  }

  void view()
  {
    typename Stack<T>::Iterator iter(first, last);
    int index = 0;
    cout << "data:" << endl;
    while(&(iter + index) != last)
    {
      cout << (iter + index) << endl;
      index++;
    }
    cout << (iter + index) << endl;
  } 

  void viewReverse()
  {
    typename Stack<T>::Iterator iter(first, last);
    int index = 0;
    cout << "reverse data:" << endl;
    //получаем количество элементов в контейнере
    while(&(iter + index) != last)
      index++;
    //реверсивный вывод данных
    while(index > -1)
      cout << (iter + index--) << endl;
  }
  void deleteByIndex(int _index)
  {
    typename Stack<T>::Iterator iter(first, last);
    int index = 0;
    cout << "delete by index:[" << _index <<"]" << endl;
    //получаем количество элементов в контейнере
    while(&(iter + index) != last)
      index++;

    if(_index >= 0 || _index <= index)
    {
      if(_index != index)
        for (size_t i = _index; i < index; i++)
          (iter + i) = (iter + (i+1));//начинаем смещение элементов массива влево с удаляемого элемента 

      //полюбому нужно будет очистить последний элемент
      //однако при повторном удалении лишняя операция выполняется
      (iter + index) = NULL;
    }
    else
      cout << "Index was outside of container" << endl;
  }

};



//вывод в реверсе 
// удаление по условию