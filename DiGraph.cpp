#include "DiGraph.h"
#include <iostream>
#include "VectAlgorithms.h"

int DiGraph::GraphNode::numberCount = 0;

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
	
	for (auto itExternal = tmpVect.begin(); itExternal < tmpVect.end(); itExternal++)
	{
		for (auto itInternal = itExternal->begin(); itInternal < itExternal->end(); itInternal++)
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
		if (v1 == v2)
		{
			ways.push_back(currentWay);
			return;
		}

		for (std::vector<GraphNode*>::const_iterator it = v1->edges.cbegin(); it < v1->edges.cend(); it++)
			r_GetWays(*it, v2, ways, currentWay);
	}
}

int DiGraph::EdgesAmount()
{
	int amount = 0;

	for (auto it_e = vertices.cbegin(); it_e < vertices.cend(); it_e++)
		for (auto it_i = it_e->edges.cbegin(); it_i < it_e->edges.cend(); it_i++)
			amount++;

	return amount;
}

bool DiGraph::IsTree()
{
	int verticesAmount = vertices.size();

	if (verticesAmount == EdgesAmount() - 1)
	{
		// Graph traversal
	}
	else
		return false;
}
