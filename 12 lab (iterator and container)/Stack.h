#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of the stack
#define SIZE 10
 
template<typename T>
// A class to represent a stack
class Stack
{
	T *arr;
	int top;
	int capacity;

public:
	// Constructor to initialize the stack
	Stack(int size = SIZE)
	{
		arr = new T[size];
		capacity = size;
		top = -1;
	}
	//Методы нужны для возвращения ссылок в итератор
	T* Begin()
	{
		return &arr[0];
	}
	T* End()
	{
		return &arr[top];
	}


	~Stack(){delete[] arr;}

	//Добавление элемента x в стек 
	void push(T x)
	{
		if (isFull())
		{
			cout << "Overflow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}

		cout << "Inserting " << x << endl;
		arr[++top] = x;
	}

	//Удаление верхнего элемента из стека
	T pop()
	{
		//Сначала нужно проверить не пуст ли стек
		if (isEmpty())
		{
			cout << "Underflow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
		cout << "Removing " << peek() << endl;
		return arr[top--];
	}

	//Метод возвращает значение вершины стека
	T peek()
	{
		if (!isEmpty()) 
			return arr[top];
		else 
			exit(EXIT_FAILURE);
	}

	//Метод возвращает размер стека
	int size(){return top + 1;}
	
	//Мето проверяет стек на пустоту
	bool isEmpty(){return top == -1;}

	//Метод проверяет стек на заполненность
	bool isFull(){return top == capacity - 1;}
	
	
	//вложенный класс итератора
	class Iterator
	{
	private:
		T* first;
		T* last;
		T* current;
	public: 
		Iterator(T* firstElement, T* lastElement)
		{
			first = firstElement;
			current = firstElement;
			last = lastElement;
		}
		
		//возвращаем указатель на элемент, который расположен от
		//текущего элемента на n позиций
		T& operator+(int n)
		{
			if((current + n) <= last)
				return *(current + n);
			else
				return *last;
		}

		//аналог предыдущего оператора, 
		T& operator-(int n)
		{
			if((current - n) >= first)
				return *(current - n);
			else
				return *first;
		}
		//переход на следующий элемент контейнера
		T& operator++(int)
		{
			if(current != last)
				return *current++;
			return *last;
		}//?
		T& operator++()
		{
			if(current != last)
				return *++current;
			return *last;
		}
		
		//переход на предыдущий элемент контейнера
		T& operator--(int)
		{
			if(current != first)
				return *current--;
			return *first;
		}

		T& operator--()
		{
			if(current != first)
				return *--current;
			return *first;
		}

		bool operator!=(const Iterator &iterator){return current != iterator.current;}
		bool operator==(const Iterator &iterator){return current == iterator.current;} 
		bool operator== (T *value){return current == value;}
		bool operator!= (T *value){return current != value;}
		T& operator*(){return *current;} 
	};
};
