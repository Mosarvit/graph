#include "Graph.h"

#include <map>
#include <limits>
 

struct tDijkstraNodeEntry
{
	double distance;
	Node* prevNode;
	Edge* prevEdge;
};


//-------------------------------------------------------------------------------------------------

Graph::~Graph()
{

	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		//Node* currentNode = *it;
		//delete currentNode;
		delete *it;
	}

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); it++)
	{
		delete *it;
	}

}


//-------------------------------------------------------------------------------------------------

void Graph::addNode(Node* pNode)
{
	m_nodes.push_back(pNode);
}


//-------------------------------------------------------------------------------------------------

void Graph::addEdge(Edge* pEdge)
{
	m_edges.push_back(pEdge);
	pEdge->getSrcNode().getOutgoingEdges().push_back(pEdge);
}


//-------------------------------------------------------------------------------------------------

void Graph::deleteNode(Node* pNode)
{
	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); )
	{
		Edge* pCurrentEdge = *it;

		// der Node ist Source-Node der aktuellen Kante
		if (&pCurrentEdge->getSrcNode() == pNode)
		{
			it = m_edges.erase(it);
			delete pCurrentEdge;
		}
		// der Node ist Destination-Node der aktuellen Kante
		else if (&pCurrentEdge->getDstNode() == pNode)
		{
			pCurrentEdge->getSrcNode().getOutgoingEdges().remove(pCurrentEdge);
			it = m_edges.erase(it);
			delete pCurrentEdge;
		}
		// nichts tun, weiter zum nächsten Element
		else
		{
			it++;
		}
	}

	m_nodes.remove(pNode);
	delete pNode;

}


//-------------------------------------------------------------------------------------------------

void Graph::deleteEdge(Edge* pEdge)
{
	pEdge->getSrcNode().getOutgoingEdges().remove(pEdge);
	m_edges.remove(pEdge);
	delete pEdge;
}


//-------------------------------------------------------------------------------------------------

std::string Graph::toString()
{
	std::string result;

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); it++)
	{
		result += (*it)->toString() + "\n";
	}

	return result;
}


//-------------------------------------------------------------------------------------------------

void Graph::dijkstraShortestPath(std::deque<Edge*>& result, Node* pSrc, Node* pDst)
{
	std::list<Node*> Q;
	std::map<Node*, tDijkstraNodeEntry> nodeEntry;
	//std::map<Node*, double> dist;
	//std::map<Node*, Node*> prev;

	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		Q.push_back(*it);
							// distance, prevNode, prevEdge
		nodeEntry[*it] = { std::numeric_limits<double>::max(), NULL, NULL };
	}

	nodeEntry[pSrc].distance = 0;

	// solange Q nicht leer ist
	while (!Q.empty())
	{
		Node* u = Q.front();
		for (std::list<Node*>::iterator it = Q.begin(); it != Q.end(); it++)
		{
			if (nodeEntry[*it].distance < nodeEntry[u].distance)
			{
				u = *it;
			}
		}

		// u ist jetzt der Knoten mit der kleinsten Distanz dist aus Q.
		Q.remove(u); // entferne u aus Q

		std::list<Edge*>& neighbours = u->getOutgoingEdges();

		for (std::list<Edge*>::iterator it = neighbours.begin(); it != neighbours.end(); it++)
		{
			Node* v = &(*it)->getDstNode();
			
			double alt = nodeEntry[u].distance + (*it)->getCheapestPrice();
			if (alt < nodeEntry[v].distance)
			{
				nodeEntry[v].distance = alt;
				nodeEntry[v].prevNode = u;
				nodeEntry[v].prevEdge = *it;
			}
		}
	}

	Node* currentNode = pDst;
	while (nodeEntry[currentNode].prevNode != NULL)
	{
		result.push_front(nodeEntry[currentNode].prevEdge);
		currentNode = nodeEntry[currentNode].prevNode;
	}
	//result.push_front(nodeEntry[currentNode].prevEdge); // fügt auch den Startknoten mit ein!
}



