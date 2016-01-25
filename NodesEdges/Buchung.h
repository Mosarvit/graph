#ifndef BUCHUNG_H
#define BUCHUNG_H


#include <string>
#include <list>
#include <sstream>
#include <unordered_set>
#include <deque>
#include <iostream>

#include "Edge.h"
#include "Route.h"

using namespace std; 


//class Edge;
//class Buchung;

class Buchung
{

public:
	
	Buchung(string vorname, string name, string adresse, deque<Edge*> result);

	string &getVorname() { return m_vorname; };
	string &getName() { return m_name; };
	string &getAdresse() { return m_adresse; };
	deque<Edge*> &getEdges() { return m_edges;  };

	double getGesamtPrice();
	
	static string printAll();
	~Buchung();

private:

	static list<Buchung*> m_Buchungen;
	string m_vorname;
	string m_name;
	string m_adresse;
	deque<Edge*> m_edges;	
};

#endif
