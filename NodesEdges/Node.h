#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>

using namespace std;

class Edge;



class Node
{
public:

	Node() : m_id(generateId()) { }

	Node(string id);

	const string& getID() const { return m_id; }

	list<Edge*>& getOutgoingEdges() { return m_outgoingEdges; }


protected:

	static string generateId();

	string m_id;

	static int s_numInstances;

	list<Edge*> m_outgoingEdges;

};


#endif