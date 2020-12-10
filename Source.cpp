/*
Тема 4, Деревья 2, 4.31:

Задан ориентированный граф в виде множества вершин (узлов) и множества дуг (соединений).
Указаны две вершины этого графа v1 и v2. Найти все пути от v1 до v2.

Автор - Пирожков Никита Вячеславович, группа ИТ-21
*/

#include <iostream>
#include "DiGraph.h"

//void PrintWays(const std::vector<std::vector<int>>& ways)
//{
//    for (size_t i = 0; i < length; i++)
//    {
//
//    }
//}

int main()
{
    DiGraph graph
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

    std::vector<std::vector<int>> ways = graph.GetWays(1, 4);

    return 0;
}
