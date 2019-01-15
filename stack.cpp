/* stack.cpp
* Aufgabe 10 Containerklassen
* Autor: Harald Loose
* 17.01.2018
*/

#include <iostream>
#include <string>
using namespace std;
#ifndef TEMPLATE
#include "stack.h"

Stack::Stack(const Stack &st)
{
	data = NULL;
	if (this != &st) *this = st;
}

// Operator =
const Stack& Stack::operator = (const Stack &st)
{
	if (&st != this)
	{
		max = st.getSize();
		anzahl = st.getCount();
		if (data) delete[] data;
		data = new T[max];
		for (int k = 0; k < st.getSize(); k++)
			data[k] = st.data[k];
	}
	return *this;
}

T& Stack::operator [] (int id) const
{
	if (id >= 0 && id < anzahl)
	{
		return data[id];
	}
	else
		throw string("Unzulaessiger Index");
}
// E/A über Streams

bool operator == (const Stack& s1, const Stack& s2)
{
	if (s1.anzahl == s2.anzahl)
		if (s1.max == s2.max)
			if (memcmp(s1.data, s2.data, s1.anzahl * sizeof(T)))
				return true;
	return false;
}

bool operator != (const Stack& s1, const Stack& s2)
{
	return (s1 == s2);
}
// E/A über Streams
ostream& operator << (ostream& s, const Stack& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << z.getSize() << " ";
		for (int k = 0; k < z.getCount(); k++)
			s << z.data[k] << " ";
		return s << endl;
	}
	else
	{
		s.write((char*)&z.anzahl, sizeof(int));
		if (typeid(T) == typeid(int))
		{
			s.write((char*)z.data, z.anzahl * sizeof(T));
		}
		else
		{
			for (int k = 0; k < z.getCount(); k++)
				s << z[k];
		}
		return s;
	}

}
istream& operator >> (istream& s, Stack& z)
{
	T tmp;
	int max;
	if (typeid(s) == typeid(cin))
	{
		cout << "Anzahl: " << endl;
		s >> max;
		Stack st(max);
		for (int k = 0; k < max; k++)
		{
			cout << "k: " << k << endl;
			s >> tmp;
			st.push(tmp);
		}
		z = Stack(st);
	}
	else
	{
		s.read((char *)&max, sizeof(int));
		Stack st(max);
		for (int k = 0; k < max; k++)
		{
			if (typeid(T) == typeid(int))
			{
				s.read((char *)&tmp, sizeof(T));
			}
			else
			{
				s >> tmp;
			}
			st.push(tmp);
		}
		z = Stack(st);
	}
	return s;
}

#else

template <class T>
Stack <T>::Stack(const Stack &st)
{
	data = NULL;
	if (this != &st) *this = st;
}

// Operator =
template <class T>
const Stack<T>& Stack <T>::operator = (const Stack &st)
{
	if (&st != this)
	{
		max = st.getSize();
		anzahl = st.getCount();
		if (data) delete[] data;
		data = new T[max];
		for (int k = 0; k < st.getSize(); k++)
			data[k] = st.data[k];
	}
	return *this;
}

// Operator []
template <class T>
T& Stack <T>::operator [] (int id) const
{
	if (id >= 0 && id < anzahl)
	{
		return data[id];
	}
	else
		throw string("Unzulaessiger Index");
}

//	// E/A über Streams
template <class T>
ostream& operator << (ostream& s, const Stack<T>& z)
{
	s << z.getSize() << " ";
	for (int k = 0; k < z.getCount(); k++)
		s << z.data[k] << " ";
	return s << endl;
}

//
template <class T>
istream& operator >> (istream& s, Stack<T>& z)
{
	T tmp;
	int max;
	cout << "Anzahl: " << endl;
	s >> max;
	Stack st(max);
	for (int k = 0; k < max; k++)
	{
		cout << "k: " << k << endl;
		s >> tmp;
		st.push(tmp);
	}
	z = Stack(st);
	return s;
}

#endif
