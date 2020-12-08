#pragma once
#include <vector>

// Directed graph
class DiGraph
{
	struct GraphNode	// Vertex of a graph
	{
		int number;	// Number of a vertex

		std::vector<GraphNode*> edges;	// Edges from this vertex

		GraphNode()
		{
			number = ++numberCount;
		}

	private:

		static int numberCount;
	};

	std::vector<GraphNode> vertices;	// Vertices of a graph

	// Prevent copy constructor
	DiGraph(const DiGraph& diGraph);

public:

	// External list - number of vertices.
	// Internal lists - edges from the current vertex. Edges with numbers to nonexistent
	// vertices are ignored.
	DiGraph(const std::initializer_list<std::initializer_list<int>>& list);
};
