#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <string>
#include <deque>
#include <iostream>
#include <map>

#include "Node.h"
#include "Edge.h"
#include "Route.h"



class Graph
{

public:

	void addNode(Node* pNode);
	
	void addEdge(Edge* pEdge);
	
	void deleteNode(Node* pNode);

	void deleteEdge(Edge* pEdge);

	std::string toString();

	virtual ~Graph();

	void dijkstraShortestPath(std::deque<Edge*>& result, Node* pSrc, Node* pDst);

	list<Node*> &getNodes() { return m_nodes; };

protected:

	std::list<Node*> m_nodes;
	std::list<Edge*> m_edges;
	
};



#endif