#ifndef ROUTENGRAPH_H
#define ROUTENGRAPH_H


#include <string>
#include <list>
 

#include "Graph.h"
#include "Route.h"
#include "Stadt.h"



using namespace std;

struct stadtStatus
{
	Node* pSrc;
	int distanceToOrigin = 99999;
	bool done = false;
};

class RoutenGraph : public Graph
{
public:
	RoutenGraph();
	~RoutenGraph();

	void addStadt(Stadt* pStadt);

	void addRoute(Route* pRoute);

	list<Route*> cheapestRoute(Stadt* pSrc, Stadt* pDst);

	list<Route*> djStep(Stadt* pCurrentStadt, map<Stadt*, stadtStatus> bestSteps);

private:

	std::list<Stadt*> m_staedte;
	std::list<Route*> m_routes;

};

 




#endif
