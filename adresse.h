/* adresse.h 
 * Aufgabe 8
 * Klassendefinitionen  
 * Autor: Harald Loose
 * 12.12.2012
*/

#include <iostream>
using namespace std;

#ifndef _H_ADRESSE
#define _H_ADRESSE

class Adresse
{
private:
	/* Instanzvariablen */
	string StrasseNr;
	string PLZStadt;
public:
	/* Konstruktoren */
	Adresse() {}
	Adresse(const string StrasseNr,const string PLZStadt);
	Adresse(const Adresse &kt);
	~Adresse() { }
	void setStrasseNr(string StrasseNr) {this->StrasseNr = StrasseNr;}
	string getStrasseNr() const {return StrasseNr;}
	void setPLZStadt(string PLZStadt) {this->PLZStadt = PLZStadt;}
	string getPLZStadt() const {return PLZStadt;}
	/* Methoden */
	// E/A �ber Streams
	friend bool operator == (const Adresse& s1, const Adresse& s2);
	friend bool operator != (const Adresse& s1, const Adresse& s2);
	friend ostream& operator << (ostream& s, const Adresse& z);
	friend istream& operator >> (istream& s, Adresse& z);

};
#endif