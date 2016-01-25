#include "Menu.h"
#include "Edge.h"
#include "Node.h"
#include "Graph.h" 

int main()
{
	// Zuerst werden alle Staedte und Routen in den Graph eingegeben

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

	// Danach wird der Graph ins Menu ubergeben, dan Menu wird gestartet

	Menu m;
	m.startMenu(g);

	return 0;
}

 


