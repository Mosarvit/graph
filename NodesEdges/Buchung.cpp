#include "Buchung.h"

Buchung::Buchung(string vorname, string name, string adresse, deque<Edge*> route) : m_vorname(vorname), m_name(name), m_adresse(adresse), m_edges(route) {

	m_Buchungen.push_back(this);

	//cout << "Buchung created, number of edges : " << m_edges.size()  << "mBuchungen size : " << m_Buchungen.size() << endl;

	//cout << "Size of the buchung : " << this->m_edges.size() << endl;
	//cout << "Size of the buchung : " << ((*next(m_Buchungen.begin(), 0))->m_edges.size()) << endl;
}
 
double Buchung::getGesamtPrice()
{
	double db = 0.0;
	for (auto edge : m_edges) {

		db += edge->getCheapestPrice();
	}

	return db;
}

string Buchung::printAll()
{
	
	stringstream ss;
	
	for (Buchung *buchung : m_Buchungen) {

		ss << "Address: " << buchung->m_adresse << endl;

		ss << "Route : " << endl;

		cout << "Size of the buchung : " << buchung->m_edges.size() << endl;

		for (Edge* edge : buchung->m_edges) {

			cout << edge->toString() << endl;
		}
	}

	return ss.str();
}
;

list<Buchung*> Buchung::m_Buchungen;

Buchung::~Buchung()
{
}