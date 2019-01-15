/* main.cpp 
* Aufgabe 10 Containerklassen
* Autor: Harald Loose
* 17.01.2018
*/
#include <iostream>
#include <string>
using namespace std;

#include "adresse.h"
#include "stack.h"
#include "queue.h"

#define QU_D
int main (int argc, char * argv[])
{
#ifndef TEMPLATE
#ifdef QU_D
	Queue stInt;
	try {
		stInt.push(1);
		stInt.push(2);
		stInt.push(3);
		cout << stInt;
		stInt.push(4);
	}
	catch (QueueException e) { cout << e.getMessage() << endl; }

	cout << "stInst " << stInt;

	Queue stInt2;
	stInt2 = stInt;
	cout << "stInst2 " << stInt2;

	Queue stInt3(stInt);
	cout << "stInst3 " << stInt3;

	try {
		cout << "pop:" << stInt.pop() << endl;
		cout << stInt;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
	}
	catch (QueueException e) { cout << e.getMessage() << endl; }

	//try {
	//	cin >> stInt2;
	//	cout << stInt2;
	//}
	////	catch (StackException e) { cout << (e.getMessage()).c_str << endl; }
	//catch (QueueException e) { cout << e.getMessage() << endl; }
#else
	Stack stInt;
	try {
		stInt.push(1);
		stInt.push(2);
		stInt.push(3);
		cout << stInt;
		stInt.push(4);
	}
	catch (StackException e) { cout << e.getMessage() << endl; }

	stInt.push(4,true);

	cout << "stInst " << stInt;

	Stack stInt2;
	stInt2 = stInt;
	cout << "stInst2 " << stInt2;

	Stack stInt3(stInt);
	cout << "stInst3 " << stInt3;

	try {
		cout << "pop:" << stInt.pop() << endl;
		cout << stInt;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
	}
	catch (StackException e) { cout << e.getMessage() << endl; }

	try {
		cin >> stInt2;
		cout << stInt2;
	}
	//	catch (StackException e) { cout << (e.getMessage()).c_str << endl; }
	catch (StackException e) { cout << e.getMessage() << endl; }
#endif
#else
	Adresse a("Hof 1", "01221 Dorf");
	cout << a << endl;
	Adresse a1("Hof 2", "01221 Dorf");
	cout << a1 << endl;
	Adresse a2("Hof 3", "01221 Dorf");
	cout << a2 << endl;

	Stack <Adresse> stInt(2);
	try {
		stInt.push(a);
		stInt.push(a1);
		cout << stInt;
		stInt.push(a2);
	}
	catch (StackException e) { cout << e.getMessage() << endl; }
	cout << "stInst " << stInt;

	Stack <Adresse> stInt2;
	stInt2 = stInt;
	cout << "stInst2 " << stInt2;

	Stack <Adresse> stInt3(stInt);
	cout << "stInst3 " << stInt3;

	try {
		cout << "pop:" << stInt.pop() << endl;
		cout << stInt;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
	}
	catch (StackException e) { cout << e.getMessage() << endl; }
	///////////// TEST für Integer ///////////////////////////////////////////////////
	Stack stInt;
	try	{
		stInt.push(1);
		stInt.push(2);
		stInt.push(3);
		cout << stInt;
		stInt.push(4);
	}
	catch (StackException e) { cout << e.getMessage() << endl; }
	cout << "stInst " << stInt;

	Stack stInt2;
	stInt2 = stInt;
	cout << "stInst2 " << stInt2;

	Stack stInt3(stInt);
	cout << "stInst3 " << stInt3;

	try	{
		cout << "pop:" << stInt.pop() << endl;
		cout << stInt;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
		cout << "pop:" << stInt.pop() << endl;
	}
	catch (StackException e) { cout << e.getMessage() << endl; }

	try	{
		cin >> stInt2;
		cout << stInt2;
	}
	//	catch (StackException e) { cout << (e.getMessage()).c_str << endl; }
	catch (StackException e) { cout << e.getMessage() << endl; }
#endif
	printf("\n");
	system("pause");
	return 0;
}
