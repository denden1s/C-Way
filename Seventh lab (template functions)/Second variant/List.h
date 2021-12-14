#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

template<typename T>
class List
{
private:
  Node<T>* first;
  Node<T>* last;
  void removeFirst() {
      if (isEmpty()) return;
      Node<T>* p = first;
      first = p->next;
      delete p;
  }

  void removeLast() {
    if (isEmpty()) return;
    if (first == last) {
        removeFirst();
        return;
    }
    Node<T>* p = first;
    while (p->next != last) p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
  }
public:
  List(): first(nullptr), last(nullptr) {}
    ~List()
  {

  }
  bool isEmpty()
  {
    return first == nullptr;
  }
  void remove(T _val)
  {
    if (isEmpty()) return;
    if (first->value == _val) {
        removeFirst();
        return;
    }
    else if (last->value == _val) {
        removeLast();
        return;
    }
    Node<T>* slow = first;
    Node<T>* fast = first->next;
    while (fast && fast->value != _val)
    {
      fast = fast->next;
      slow = slow->next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
  }
  void pushStart(const T &t)
  {
    if( Node<T>* node = new Node<T>(t))
    {
      node->next = first;
      first = node;
    }
  }
  void pushBack(T _val) {
    Node<T>* p = new Node<T>(_val);
    if (isEmpty()) {
      first = p;
      last = p;
      return;
    }
    last->next = p;
    last = p;
  }
  void findCount(T _val)
  {
    int counter = 0;
    if (isEmpty()) return;
    Node<T>* p = first;
    while (p)
    {
      counter += p->value == _val ? 1 : 0;
      p = p->next;
    }
    cout << "Количество элементов со значением: " << _val << " в списке: " << counter << endl;
  }
  void print()
  {
    if (isEmpty()) return;
    Node<T>* p = first;
    while (p) {
      cout << p->value << " ";
      p = p->next;
    }
    cout << endl;
  }
};