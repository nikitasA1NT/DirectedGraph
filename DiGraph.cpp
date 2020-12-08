#include "DiGraph.h"

int DiGraph::GraphNode::numberCount = 0;

void sortVect(std::vector<int>& vect)
{
	for (unsigned int i = 0; i < vect.size(); i++)
		for (std::vector<int>::iterator it = vect.begin(); it < vect.end() - 1; it++)
			if (*it > *(it + 1))
			{
				int biggest = *it;
				*it = *(it + 1);
				*(it + 1) = *it;
			}
}

void removeRepets(std::vector<int>& vect)
{
	sortVect(vect);
	std::vector<int> tmpVect;

	for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		if (it != vect.end() - 1)
		{
			if (*it != *(it + 1))
				tmpVect.push_back(*it);
		}
		else
			tmpVect.push_back(*it);

	vect = tmpVect;
}

DiGraph::DiGraph(const std::initializer_list<std::initializer_list<int>>& list)
{
	// Copy external initializer list to vector<vector<int>> for sort
	// and to remove repetitions
	std::vector<std::vector<int>> tmpVect(list.size());
	std::vector<std::vector<int>>::iterator itTmpVect = tmpVect.begin();

	for (std::initializer_list<int> externalElement : list)
	{
		for (int internalElement : externalElement)
			itTmpVect->push_back(internalElement);
		itTmpVect++;
	}

	// Sort internal vectors and remove repetitions in them
	for (itTmpVect = tmpVect.begin(); itTmpVect < tmpVect.end(); itTmpVect++)
		removeRepets(*itTmpVect);

	// Creating vertices of a graph
	vertices.resize(tmpVect.size());

	// Filling vertex edges
	std::vector<GraphNode>::iterator itVertices = vertices.begin();
	
	for (std::vector<std::vector<int>>::iterator itExternal = tmpVect.begin(); itExternal < tmpVect.end(); itExternal++)
	{
		for (std::vector<int>::iterator itInternal = itExternal->begin(); itInternal < itExternal->end(); itInternal++)
			if (*itInternal > 0 && *itInternal <= (int)vertices.size())
				itVertices->edges.push_back(&*(vertices.begin() + *(itInternal) - 1));
		itVertices++;
	}
}
