#include "Edge.h"

Edge::Edge(Node & rSrc, Node & rDst, double distFlight, double distTrain) : m_srcNode(rSrc), m_dstNode(rDst), m_distFlight(distFlight), m_distTrain(distTrain)
{

	if (((80.0 + m_distFlight*0.1) < (m_distTrain*0.18)) || (m_distTrain == 0)) {

		m_cheapestDistance = m_distFlight;
		m_cheapestPrice = 80.0 + m_distFlight*0.1;
		m_cheapestDuration = m_distFlight/700;
		m_flightIsCheaper = true;
	}
	else {

		m_cheapestDistance = m_distTrain;
		m_cheapestPrice = m_distTrain*0.18;
		m_cheapestDuration = m_distTrain / 75.0;
		m_flightIsCheaper = false;

	}
}

string Edge::StringPadding(string original, size_t charCount)
{
	original.resize(charCount, ' ');
	return original;
}


