/* queue.h
* Aufgabe 10 Containerklassen
* Autor: Harald Loose
* 17.01.2018
*/
#pragma once

#include <iostream>
#include <string>
using namespace std;

// Aufgabe 10d //////////////////////////////////////////////////////////

// Eine Klasse zum definieren von eigenen Ausnahmen
class QueueException
{
private:
	string message;
public:
	QueueException(string message = string(""))
	{
		this->message = message;
	}
	string getMessage() const { return message; }
};

// Die Implementierung des Queues erfolgt als double bzw. als Template
typedef double TQ;

class Queue
{
private:
	/* Instanzvariablen */
	TQ * data;
	int first, last;
	int max;
	bool isFull() const { return (last - first) == max ? true : false; }
	bool isEmpty() const { return (last - first) == 0 ? true : false; }
public:
	/* Konstruktoren */
	Queue(int max = 3)
	{
		first = 0;
		last = 0;
		this->max = max > 0 ? max : 3;
		data = new TQ[max];
	}
	Queue(const Queue &st)
	{
		if (this != &st) *this = st;
	}

	~Queue()
	{
		if (data) delete[] data;
		first = 0;
		last = 0;
	}
	/* Methoden */
	int getCount() const { return last -first; }
	int getSize() const { return max; }
	void push(TQ adr)
	{
		if (!isFull())
			data[last++] = adr;
		else
			throw  QueueException("Queue ist voll");
	}
	TQ pop()
	{
		if (!isEmpty())
		{
			TQ tmp = data[first];
			for (int k = 0; k < last; k++)
				data[k] = data[k + 1];
			last--;
			return tmp;
		}
		else
			throw  QueueException("Queue ist leer");
	}
	TQ top() const
	{
		if (!isEmpty())
			return data[first];
		else
			throw new QueueException("Queue ist leer");
	}
	// Operator =
	const Queue& operator = (const Queue &st);
	TQ& operator [] (int id) const;

	// E/A über Streams
	friend ostream& operator << (ostream& s, const Queue& z);
	friend istream& operator >> (istream& s, Queue& z);

	// E/A über Streams
	friend bool operator == (const Queue& s1, const Queue& s2);
	friend bool operator != (const Queue& s1, const Queue& s2);
}; 
