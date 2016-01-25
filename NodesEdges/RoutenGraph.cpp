#include "RoutenGraph.h"

RoutenGraph::RoutenGraph()
{
}

RoutenGraph::~RoutenGraph()
{
}

 


void RoutenGraph::addStadt(Stadt* pStadt)
{
	m_staedte.push_back(pStadt);
}


//-------------------------------------------------------------------------------------------------

void RoutenGraph::addRoute(Route* pRoute)
{
	m_routes.push_back(pRoute);
	pRoute->getSrcNode().getOutgoingEdges().push_back(pRoute);
}

 

list<Route*> RoutenGraph::cheapestRoute(Stadt * pStartdStadt, Stadt * pZielStadt)
{
	map<Stadt*, stadtStatus> bestSteps;

	for (Stadt* stadt : this->m_staedte) {

		bestSteps[stadt];
	}

	bestSteps[pStartdStadt].distanceToOrigin = 0;

	list<Route*> result = djStep(pStartdStadt, bestSteps);


	for (auto valPair : bestSteps) {

		cout << valPair.first->getID() << valPair.second.distanceToOrigin << valPair.second.done << valPair.second.pSrc->getID() << endl;
	}

	return result;
}

list<Route*> RoutenGraph::djStep(Stadt* pCurrentStadt, map<Stadt*, stadtStatus> bestSteps)
{

	//for (Route* pOutR : (pCurrentStadt->getOutgoingRoutes())) {

	//	Stadt* pNachbarStadt = pOutR->getZielStadt;

	//	if (!bestSteps[pNachbarStadt].done) {
	//		if (bestSteps[pCurrentStadt].distanceToOrigin + pOutR->getDistanceOfCheapest() <  bestSteps[pNachbarStadt].distanceToOrigin) {
	//			bestSteps[pNachbarStadt].distanceToOrigin = bestSteps[pCurrentStadt].distanceToOrigin + pOutR->getDistanceOfCheapest;
	//		}
	//	}
	//}



	return list<Route*>();
}