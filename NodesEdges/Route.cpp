#include "Route.h"

 

Route::Route(Stadt & rSrc, Stadt & rDst, double dFl, double dBs) : Edge(rSrc, rDst), m_zielStadt(rDst), m_vonStadt(rSrc), m_dintanceFlight(dFl), m_dintanceBus(dBs)
{

	if ((80.0 + m_dintanceFlight*0.1)<(m_dintanceBus*0.18)|| m_dintanceBus==0) {

		m_distanceOfCheapest = m_dintanceFlight;
		m_priceOfCheapest = 80.0 + m_dintanceFlight*0.1;
		m_fahrtZeitOfCheapest = m_dintanceFlight / 700;
		m_flightIsCheapest = true;		
	}
	else {

		m_distanceOfCheapest = m_dintanceBus;
		m_priceOfCheapest = m_dintanceBus*0.18;
		m_fahrtZeitOfCheapest = m_dintanceBus / 75;
		m_flightIsCheapest = false;
	}
}

Route::~Route()
{
}
