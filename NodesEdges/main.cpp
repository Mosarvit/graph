#include <iostream>

#include "Edge.h"
#include "Node.h"
#include "Graph.h"
#include "Buchung.h"

int main()
{

	Node* node_berlin = new Node("Berlin");
	Node* node_madrid = new Node("Madrid");
	Node* node_wien = new Node("Wien");
	Node* node_barcelona = new Node("Barcelona");
	Node* node_london = new Node("London");
	Node* node_ny = new Node("New York");

	Graph g;
	g.addNode(node_berlin);
	g.addNode(node_madrid);
	g.addNode(node_wien);
	g.addNode(node_barcelona);
	g.addNode(node_london);
	g.addNode(node_ny);

	g.addEdge(new Edge(*node_berlin, *node_madrid, 1900, 2300));
	g.addEdge(new Edge(*node_berlin, *node_wien, 530, 680));
	g.addEdge(new Edge(*node_wien, *node_madrid, 1800, 2450));
	g.addEdge(new Edge(*node_madrid, *node_barcelona, 505, 619));
	g.addEdge(new Edge(*node_berlin, *node_london, 930, 0));
	g.addEdge(new Edge(*node_london, *node_ny, 5600, 0));

	std::cout << g.toString() << std::endl;


//	list<Route*> cheapestRoute = g.cheapestRoute(node_berlin, node_barcelona);



	//cheapestRoute.push_back(new Route(*node_berlin, *node_madrid, 1900, 2300));
	//cheapestRoute.push_back(new Route(*node_berlin, *node_wien, 530, 680));
	//cheapestRoute.push_back(new Route(*node_wien, *node_madrid, 1800, 2450));
	//cheapestRoute.push_back(new Route(*node_madrid, *node_barcelona, 505, 619));
	//cheapestRoute.push_back(new Route(*node_berlin, *node_london, 930, 0));
	//cheapestRoute.push_back(new Route(*node_london, *node_ny, 5600, 0));



	deque<Edge*> result;
	g.dijkstraShortestPath(result, node_berlin, node_barcelona);

	for (Edge* edge : result) {

		cout << edge->toString() << endl;
	}

	//string name1;
	//getline(std::cin, name1);

	list<Buchung> buchungen;

	while (1) {

		Node* srcCity = NULL;
		Node* dstCity = NULL;

		cout << "Hello, from where would you like to go? Please select a number" << endl << endl;

		int i = 0;

		for (auto node : g.getNodes()) {

			//if (!(node->getOutgoingEdges()).empty())
			cout << to_string(++i) << ". " << node->getID() << endl;
		}

		int option;
		cin >> option;

		srcCity = *(next(g.getNodes().begin(), option-1));

		// cout << "From " << srcCity->getID() << endl;

		cout << "Where do you want to go? Please select a number: " << endl << endl;

		i = 0;

		for (auto node : g.getNodes()) {

			//if (!(node->getOutgoingEdges()).empty())
			cout << to_string(++i) << ". " << node->getID() << endl;
		}

		cin >> option;

		dstCity = *(next(g.getNodes().begin(), option - 1));

		cout << "From " << srcCity->getID() << " To " << dstCity->getID() << endl << endl;

		

		result.clear();
		g.dijkstraShortestPath(result, srcCity, dstCity);

		if (result.size() == 0) {

			cout << "No root possible " << endl << endl;
		}
		else {

			cout << "All right, here is a path we suggest: " << endl << endl;

			for (Edge* edge : result) {

				cout << edge->toString() << endl;
			}

			cout << "Would you like to book this rout? " << endl << "1. yes" << endl << "2. no" << endl;

			cin >> option;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (!(option - 1)) {

				string name, vorname, adresse;

				cout << endl << "Please enter the first name of the traveler : " << endl;

				getline(cin, vorname);
				//		cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << endl << "Please enter the last name of the traveler : " << endl;

				getline(cin, name);

				cout << endl << "Please enter the adress of the traveler : " << endl;

				getline(cin, adresse);



				buchungen.push_back(Buchung(vorname, name, adresse, result));



				//for (auto buchung2 : buchungen) {

				//	cout << "Address2: " << buchung2->getAdresse() << endl;

				//}			
			}
		}		
		
		bool finished = false;	
		
		while ((!finished)&&(buchungen.size()>0)) {

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

					for (Edge* edge : buchung2.getEdges()) {

						cout << edge->toString() << endl;
					}

					cout << "Gesamtprice: " << buchung2.getGesamtPrice() << endl;

					db += buchung2.getGesamtPrice();
					cout << endl;
				}	

				cout << "Gesamtkosten: " << db << endl ;



			}
			else {

				finished = true;
			}
		}

		
	}

	return 0;
}

 


