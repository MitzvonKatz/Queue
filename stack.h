/* stack.h
/* stack.cpp
* Aufgabe 10 Containerklassen
* Autor: Harald Loose
* 17.01.2018
*/
#pragma once
//#define TEMPLATE

#include <iostream>
#include <string>
using namespace std;

// Eine Klasse zum definieren von eigenen Ausnahmen
class StackException
{
private:
	string message;
public:
	StackException(string message = string(""))
	{
		this->message = message;
	}
	string getMessage() const { return message; }
};

// Die Implementierung des Stacks erfolgt als double bzw. als Template
#ifndef TEMPLATE
typedef double T;

class Stack
{
private:
	/* Instanzvariablen */
	T * data;
	int anzahl;
	int max;
	bool isFull() const { return anzahl == max ? true : false; }
	bool isEmpty() const { return anzahl == 0 ? true : false; }
public:
	/* Konstruktoren */
	Stack(int max = 3)
	{
		anzahl = 0;
		this->max = max > 0 ? max : 3;
		data = new T[max];
	}
	Stack(const Stack &st);
	~Stack()
	{
		if (data) delete[] data;
		anzahl = 0;
	}
	/* Methoden */
	int getCount() const { return anzahl; }
	int getSize() const { return max; }
	void setSize(int mx)
	{
		T* d = new T[mx];
		for (int k = 0; k < max; k++)
			d[k] = data[k];
		max = mx;
		delete[] data;
		data = d;
	}

	void push(T adr, bool dyn = false)
	{
		if (!isFull())
			data[anzahl++] = adr;
		else if (dyn)
		{
			setSize(max + 3);
			push(adr, false);
		}
		else
			throw  StackException("Stack ist voll");
	}
	T pop()
	{
		if (!isEmpty())
			return data[--anzahl];
		else
			throw  StackException("Stack ist leer");
	}
	T top() const
	{
		if (!isEmpty())
			return data[anzahl - 1];
		else
			throw new StackException("Stack ist leer");
	}
	// Operator =
	const Stack& operator = (const Stack &st);
	T& operator [] (int id) const;

	// E/A über Streams
	friend ostream& operator << (ostream& s, const Stack& z);
	friend istream& operator >> (istream& s, Stack& z);

	// E/A über Streams
	friend bool operator == (const Stack& s1, const Stack& s2);
	friend bool operator != (const Stack& s1, const Stack& s2);
}; 

#else

template<class T> class Stack;
template<class T>
    ostream& operator<<(ostream&, const Stack<T>&);
template<class T>
	istream& operator<<(istream&, Stack<T>&);

template <class T> 
class Stack
{
private:
	/* Instanzvariablen */
	T * data;
	int anzahl;
	int max;
	bool isFull() const { return anzahl == max ? true : false; }
	bool isEmpty() const { return anzahl == 0 ? true : false; }
public:
	/* Konstruktoren */
	Stack(int max = 3) 
	{
		anzahl = 0;
		this->max = max > 0 ? max : 3;
		data = new T[max];
	}
	Stack(const Stack &st);
	~Stack() 
	{ 
		if (data) delete[] data;
		anzahl = 0;
	}
	/* Methoden */
	int getCount() const { return anzahl; }
	int getSize() const { return max; }
	void push(T adr)
	{ 
		if (!isFull())
			data[anzahl++] = adr;
		else
			throw  StackException("Stack ist voll");
	}
	T pop()
	{
		if (!isEmpty())
			return data[--anzahl];
		else
			throw  StackException("Stack ist leer");
	}
	T top() const
	{
		if (!isEmpty())
			return data[anzahl-1];
		else
			throw new StackException("Stack ist leer");
	}
	// Operator =
	const Stack& operator = (const Stack &st);
	T& operator [] (int id) const;
		// E/A über Streams
	friend ostream& operator << <T> (ostream& s, const Stack<T>& z);
	friend istream& operator >> <T> (istream& s, Stack& z);
};

#endif

#include "stack.cpp"
