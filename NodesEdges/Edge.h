#ifndef EDGE_H
#define EDGE_H

#include <string>

#include "Node.h"

using namespace std;

class Edge
{
public:

	Edge(Node& rSrc, Node& rDst, double distFlight, double distTrain) ;

	string toString() { return StringPadding(m_srcNode.getID(), 10)
								+ " -> "
								+ StringPadding(m_dstNode.getID() , 10)
								+ "Duration  : "
								+ StringPadding(to_string(m_cheapestDuration), 10)
								+ "Going by "
								+ StringPadding((m_flightIsCheaper ? "Airplane" : "Train"), 10)
								+ "Price : "
								+ StringPadding(to_string(m_cheapestPrice), 10)
								; }
	string toStringSrcToDst() {
		return StringPadding(m_srcNode.getID(), 10)
			+ " -> "
			+ StringPadding(m_dstNode.getID(), 10)
			;
	}

	virtual double getCheapestPrice() { return m_cheapestPrice; }



	Node& getSrcNode() { return m_srcNode; }
	Node& getDstNode() { return m_dstNode; }
 

	string StringPadding(string original, size_t charCount);

 

private:

	Node& m_srcNode;
	Node& m_dstNode;
	double m_distFlight;
	double m_distTrain;
	double m_cheapestDistance;
	double m_cheapestPrice;
	double m_cheapestDuration;
	bool m_flightIsCheaper;

};


#endif