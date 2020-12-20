#pragma once
#include <vector>

// Directed graph. Vertex numbers start at 1
class DiGraph
{
	struct GraphNode	// Vertex of a graph
	{
		int number;	// Number of a vertex

		std::vector<GraphNode*> edges;	// Edges from this vertex

		GraphNode() { number = ++numberCount; }

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

	// Return two-dimensial vector whose internal vectors are ways from v1 to v2.
	// If there are no such vertices, info about this is displayed in the console.
	std::vector<std::vector<int>> GetWays(int v1, int v2);

private:

	void r_GetWays(GraphNode* v1, GraphNode* v2, std::vector<std::vector<int>>& ways, std::vector<int> currentWay);
};
