#include "Menu.h"

void Menu::startMenu(Graph g)
{
	Node* srcCity = NULL;
	Node* dstCity = NULL;

	list<Buchung> buchungen;
	deque<Edge*> result;

	bool finished = false;
	int option;
	int i = 0;


	while (1) {

		// Wenn es eine Bestellung bereits aufgegen wurde, kann man sich diese anzeigen lassen

		while ((!finished) && (buchungen.size()>0)) {

			cout << endl << "What would you like to do now? \n1. Make a new Order \n2. View my orders " << endl;

			cin >> option;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if ((option - 1)) {

				int j = 0;
				double db = 0.0;
				for (auto buchung2 : buchungen) {

					cout << "Buchung Nr.: " << ++j << endl;
					cout << "Vorname : " << buchung2.getVorname() << endl;
					cout << "Name : " << buchung2.getName() << endl;
					cout << "Address: " << buchung2.getAdresse() << endl;
					cout << "Routen: " << endl;

					// alle Routen der Buchung werdne ausgegeben

					for (Edge* edge : buchung2.getEdges()) {

						cout << edge->toString() << endl;
					}

					cout << "Gesamtprice: " << buchung2.getGesamtPrice() << endl;

					// Alle Preise jeder Buchung werde aufaddiert und ausgegeben

					db += buchung2.getGesamtPrice();

					cout << endl;
				}

				cout << "Gesamtkosten: " << db << endl;
			}
			else {

				finished = true;
			}
		}

		// Zuerst sucht sich der User eine Startstadt aus

		cout << "Hello, from where would you like to go? Please select a number" << endl << endl;		

		for (auto node : g.getNodes()) {

			cout << to_string(++i) << ". " << node->getID() << endl;
		}
		
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Die eingegebene Nummer definiert die Startstadt

		srcCity = *(next(g.getNodes().begin(), option - 1));
		
		// danach die Zielstadt

		cout << "Where do you want to go? Please select a number: " << endl << endl;

		i = 0;

		for (auto node : g.getNodes()) {

			cout << to_string(++i) << ". " << node->getID() << endl;
		}

		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Die eingegebene Nummer definiert die Zielstadt

		dstCity = *(next(g.getNodes().begin(), option - 1));
		
		result.clear();
		g.dijkstraShortestPath(result, srcCity, dstCity);

		// Eine leere Route ist ein Fehler

		if (result.size() == 0) {

			cout << "No root possible " << endl << endl;
		}
		else
		{

			// Eine Nichtleere Route wird vorgeschlagen

			cout << "All right, here is a path we suggest: " << endl << endl;

			for (Edge* edge : result) {

				cout << edge->toString() << endl;
			}

			cout << "Would you like to book this rout? \n1. yes \n2. no" << endl;

			cin >> option;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// Falls die Route gebucht werden soll, werden die Personalien entgegengenommen und die Buchung wird erstellt und zu der Buchungenliste zugefuegt

			if (!(option - 1)) {

				string name, vorname, adresse;

				cout << endl << "Please enter the first name of the traveler : " << endl;

				getline(cin, vorname);

				cout << endl << "Please enter the last name of the traveler : " << endl;

				getline(cin, name);

				cout << endl << "Please enter the adress of the traveler : " << endl;

				getline(cin, adresse);

				buchungen.push_back(Buchung(vorname, name, adresse, result));
		
			}
		}
	}	 
}
