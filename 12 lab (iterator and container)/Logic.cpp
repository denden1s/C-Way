#pragma once
#include"Stack.h"
#include"Algorythms.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
  Stack <int>stack(6);
 
  stack.push(36);
  stack.push(-4);
  stack.push(15);
  stack.push(-3);
  stack.push(9);
  stack.push(1);
  auto iterator = Stack<int>::Iterator(stack.Begin(), stack.End());
  Algorythm<int> algs(stack.Begin(), stack.End());
  algs.view();
  algs.sort();
  algs.view();
  algs.viewReverse();
  algs.deleteByIndex(0);
  algs.view();
  algs.deleteByIndex(1);
  algs.view();
  algs.deleteByIndex(3);
  algs.view();

  return 0;
}