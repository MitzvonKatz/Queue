/* stack.cpp
* Aufgabe 10 Containerklassen
* Autor: Harald Loose
* 17.01.2018
*/

#include <iostream>
#include <string>
using namespace std;
#include "queue.h"

// Operator =
const Queue& Queue::operator = (const Queue &st)
{
	if (&st != this)
	{
		max = st.getSize();
		first = st.first;
		last = st.last;
		if (data) delete[] data;
		data = new TQ[max];
		for (int k = first; k <= st.last; k++)
			data[k] = st.data[k];
	}
	return *this;
}

TQ& Queue::operator [] (int id) const
{
	if (id >= first && id <= last)
	{
		return data[id];
	}
	else
		throw string("Unzulaessiger Index");
}
// E/A über Streams

bool operator == (const Queue& s1, const Queue& s2)
{
	if (s1.first == s2.first)
		if (s1.last == s2.last)
			if (s1.max == s2.max)
				if (memcmp(&s1.data[s1.first], &s2.data[s2.first], s1.getSize() * sizeof(TQ)))
					return true;
	return false;
}

bool operator != (const Queue& s1, const Queue& s2)
{
	return !(s1 == s2);
}
// E/A über Streams
ostream& operator << (ostream& s, const Queue& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << z.getSize() << " ";
		for (int k = z.first; k < z.last; k++)
			s << z.data[k] << " ";
		return s << endl;
	}
	else
	{
		int anzahl = z.getSize();
		s.write((char*)&anzahl, sizeof(int));
		if (typeid(TQ) == typeid(int))
		{
			s.write((char*)z.data, z.getSize() * sizeof(TQ));
		}
		else
		{
			for (int k = 0; k < z.getSize(); k++)
				s << z[k];
		}
		return s;
	}

}
istream& operator >> (istream& s, Queue& z)
{
	TQ tmp;
	int max;
	if (typeid(s) == typeid(cin))
	{
		cout << "Anzahl: " << endl;
		s >> max;
		Queue st(max);
		for (int k = 0; k < max; k++)
		{
			cout << "k: " << k << endl;
			s >> tmp;
			st.push(tmp);
		}
		z = Queue(st);
	}
	else
	{
		s.read((char *)&max, sizeof(int));
		Queue st(max);
		for (int k = 0; k < max; k++)
		{
			if (typeid(TQ) == typeid(int))
			{
				s.read((char *)&tmp, sizeof(TQ));
			}
			else
			{
				s >> tmp;
			}
			st.push(tmp);
		}
		z = Queue(st);
	}
	return s;
}
