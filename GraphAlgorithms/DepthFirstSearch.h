#pragma once

#include <iostream>

class Graph;

void Previsit(Graph* graph, int currentgVertex);
void Postvisit(Graph* graph, int currentgVertex);
void Explore(Graph* graph, int startingVertex); // ���������� ���� ������, ���������� �� ������
void DepthFirstSearch(Graph* graph);