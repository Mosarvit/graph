#ifndef PAPH_H
#define PAPH_H

#include <string>

#include "Edge.h"
#include "Stadt.h"

class Stadt;

class Route : public Edge
{

public:

	 
	
	double &getPriceOfCheapest(){ return m_priceOfCheapest; };
	double &getFahrtZeitOfCheapest() { return m_fahrtZeitOfCheapest; };
	double &getDistanceOfCheapest() { return m_distanceOfCheapest; };
	bool &getFlightIsCheapest() { return m_flightIsCheapest; };

	Stadt& getZielStadt() { return m_zielStadt; }
	Stadt& getVonStadt() { return m_vonStadt; }
	Route(Stadt & rSrc, Stadt & rDst, double dFl, double dBs);
	// string getDistance
	~Route();

private:

	double m_dintanceFlight;
	double m_dintanceBus;
	double m_priceOfCheapest;
	double m_fahrtZeitOfCheapest;
	double m_distanceOfCheapest;
	bool m_flightIsCheapest;
	Stadt& m_zielStadt;
	Stadt& m_vonStadt;

};

#endif


