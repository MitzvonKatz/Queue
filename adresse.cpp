/* adresse.cpp 
 * Aufgabe 8
 * Klassendefinitionen  
 * Autor: Harald Loose
 * 12.12.2012
*/
 
#include <string>
#include "adresse.h"

/* Konstruktoren */
Adresse::Adresse( const string StrasseNr, const string PLZStadt)
{
	this->StrasseNr = StrasseNr;
	this->PLZStadt = PLZStadt;
}

Adresse::Adresse(const Adresse &adr) 
{
	this->StrasseNr = adr.StrasseNr;
	this->PLZStadt = adr.PLZStadt;
}

// E/A über Streams
ostream& operator << (ostream& s, const Adresse& adr)
{
	if (typeid(s) == typeid(cout))
	{
		return s << adr.getStrasseNr() << " " << adr.getPLZStadt() << endl;
	}
	else
	{
		int sz = adr.StrasseNr.length();
		s.write((char*)&sz, sizeof(int));
		s.write((char*) adr.StrasseNr.c_str(), sz);
		sz = adr.PLZStadt.length();
		s.write((char*)&sz, sizeof(int));
		s.write((char*) adr.PLZStadt.c_str(), sz);
		return s;
	}
}

istream& operator >> (istream& s, Adresse& z)	
{
	if (typeid(s) == typeid(cin))
	{
		string strasseNr, PLZStadt;
		s >> strasseNr >> PLZStadt;
		z = Adresse(strasseNr, PLZStadt);
	}
	else
	{
		int sz;
		char buffer[100];
		s.read((char*)&sz, sizeof(int));
		s.read((char*) buffer, sz);
		buffer[sz] = 0;
		string strasseNr(buffer);
		s.read((char*)&sz, sizeof(int));
		s.read((char*)buffer, sz);
		buffer[sz] = 0;
		string PLZStadt(buffer);
		z = Adresse(strasseNr, PLZStadt);
	}
	return s;
}	

bool operator == (const Adresse& s1, const Adresse& s2)
{
	if (s1.getStrasseNr()==s2.getStrasseNr())
		if (s1.getPLZStadt() == s2.getPLZStadt())
				return true;
	return false;
}

bool operator != (const Adresse& s1, const Adresse& s2)
{
	return !(s1 == s2);
}

