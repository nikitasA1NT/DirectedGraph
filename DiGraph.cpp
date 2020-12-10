#include "DiGraph.h"
#include <iostream>

int DiGraph::GraphNode::numberCount = 0;

void SortVect(std::vector<int>& vect)
{
	for (unsigned int i = 0; i < vect.size(); i++)
		for (std::vector<int>::iterator it = vect.begin(); it < vect.end() - 1; it++)
			if (*it > *(it + 1))
			{
				int biggest = *it;
				*it = *(it + 1);
				*(it + 1) = biggest;
			}
}

void RemoveRepets(std::vector<int>& vect)
{
	SortVect(vect);
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

bool Search(std::vector<int> vect, int key)
{
	SortVect(vect);

	int left = 0;
	int right = vect.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		std::vector<int>::const_iterator it = vect.cbegin() + middle;
		if (key == *it)
			return true;
		if (*it > key)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return false;
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
		RemoveRepets(*itTmpVect);

	// Creating vertices of a graph
	vertices.resize(tmpVect.size());

	// Filling vertex edges
	std::vector<GraphNode>::iterator itVertices = vertices.begin();
	
	for (std::vector<std::vector<int>>::iterator itExternal = tmpVect.begin(); itExternal < tmpVect.end(); itExternal++)
	{
		for (std::vector<int>::iterator itInternal = itExternal->begin(); itInternal < itExternal->end(); itInternal++)
			// If internal > 0, <= amount of vertices and != current vertex number
			if (*itInternal > 0 && *itInternal <= (int)vertices.size() && *itInternal != itVertices->number)
				itVertices->edges.push_back(&*(vertices.begin() + *(itInternal) - 1));
		itVertices++;
	}
}

std::vector<std::vector<int>> DiGraph::GetWays(int v1, int v2)
{
	std::vector<std::vector<int>> ways;

	// If v1/v2 <= 0, > amount of vertices or v1 == v2 return empty "ways"
	if ((v1 <= 0 || v1 > (int)vertices.size()) || (v2 <= 0 || v2 > (int)vertices.size()) || v1 == v2)
	{
		std::cerr << "ERROR: One of the transmitted vertices is missing or v1 = v2." << std::endl;
		return ways;
	}

	std::vector<int> currentWay;

	r_GetWays(&vertices[v1 - 1], &vertices[v2 - 1], ways, currentWay);

	return ways;
}

void DiGraph::r_GetWays(GraphNode* v1, GraphNode* v2, std::vector<std::vector<int>>& ways, std::vector<int> currentWay)
{
	if (!Search(currentWay, v1->number))
	{
		// Add number of current vertex
		currentWay.push_back(v1->number);

		// If v1 == v2
		if (v1->number == v2->number)
		{
			ways.push_back(currentWay);
			return;
		}

		//for (int i = 0; i < v1->edges.size(); i++)
		for (std::vector<GraphNode*>::iterator it = v1->edges.begin(); it < v1->edges.end(); it++)
			r_GetWays(*it, v2, ways, currentWay);
	}

	
}
