#pragma once
#include <vector>

class DiGraph
{
	struct GraphNode
	{
		int number;

		std::vector<GraphNode*> edges;

		/*GraphNode(int number, std::vector<GraphNode*> edges)
		{
			this->number = number;
			this->edges = edges;
		}*/
	};

	std::vector<GraphNode> vertices;
};
