/*
Тема 4, Деревья 2, 4.31:

Задан ориентированный граф в виде множества вершин (узлов) и множества дуг (соединений).
Указаны две вершины этого графа v1 и v2. Найти все пути от v1 до v2.

Автор - Пирожков Никита Вячеславович, группа ИТ-21
*/

#include <iostream>
#include <iomanip>
#include "DiGraph.h"
#include "VectAlgorithms.h"

void PrintWays(const std::vector<std::vector<int>>& ways)
{
    for (auto itExternal = ways.cbegin(); itExternal < ways.cend(); itExternal++)
    {
        for (auto itInternal = itExternal->cbegin(); itInternal < itExternal->cend(); itInternal++)
            std::cout << std::setw(4) << *itInternal;
        std::cout << std::endl;
    }
}

bool Foo(std::vector<int>& vect)
{
    vect.resize(10);
    return true;
}

int main()
{
    DiGraph graph       // Directed graph from "Graph.png"
    {
        { 2, 3 },       // 1 vertex
        { 4 },          // 2
		{ 1, 4, 6 },    // 3
		{ 3, 5, 6 },    // 4
        { 2 },          // 5
        { 5, 7 },       // 6
        { 8 },          // 7
        { 6, 7 }        // 8
    };

    std::cout << "Ways from vertex 1 to vertex 4:" << std::endl;
    PrintWays(graph.GetWays(1, 4));
    std::cout << std::endl;

    std::cout << "Ways from vertex 3 to vertex 8:" << std::endl;
    PrintWays(graph.GetWays(3, 8));
    std::cout << std::endl;

    std::cout << "Ways from vertex 2 to vertex 7:" << std::endl;
    PrintWays(graph.GetWays(2, 7));
    std::cout << std::endl;

    std::cout << "Ways from vertex 5 to vertex 6:" << std::endl;
    PrintWays(graph.GetWays(5, 6));
    std::cout << std::endl;

    std::cout << "Ways from vertex 8 to vertex 2:" << std::endl;
    PrintWays(graph.GetWays(8, 2));
    std::cout << std::endl;



    // Graph - tree

    DiGraph graph1       // Directed graph from "Tree1.png"
    {
        { 2, 8 },        // 1 vertex
        { 3, 6 },        // 2
        { 4, 5 },        // 3
        { },             // 4
        { },             // 5
        { 7 },           // 6
        { },             // 7
        { 9 },           // 8
        { 10, 11 },      // 9
        { },             // 10
        { }              // 11
    };

    DiGraph graph2       // Directed graph from "Tree2.png"
    {
        { 2, 8 },        // 1 vertex
        { 1, 3, 6 },     // 2
        { 4, 5 },        // 3
        { },             // 4
        { },             // 5
        { 7 },           // 6
        { },             // 7
        { 9 },           // 8
        { 10, 11 },      // 9
        { },             // 10
        { }              // 11
    };

    DiGraph graph3       // Directed graph from "Tree3.png"
    {
        { 2 },           // 1 vertex
        { 3, 6 },        // 2
        { 4, 5 },        // 3
        { },             // 4
        { },             // 5
        { 7 },           // 6
        { 9 },           // 7
        { 9 },           // 8
        { 10, 11 },      // 9
        { },             // 10
        { }              // 11
    };

    

    return 0;
}
