#include "Graph.h"


int Graph::NumberOfVertices()
{
	return representation_->Size();
}


Graph::Graph(GraphRepresentation* representation)
	: representation_(representation), connectedComponentsNumber_(0), timer_(1)
{
	visited_.resize(representation_->Size());
	connectedComponents_.resize(representation_->Size());
	times_.resize(representation_->Size());
}


void Graph::AddVertex()
{
	representation_->AddVertex();
	visited_.resize(representation_->Size() + 1);
	connectedComponents_.resize(representation_->Size() + 1);
	times_.resize(representation_->Size() + 1);
}


bool Graph::IsVerticesConnected(int begin, int end) const
{
	return representation_->IsVerticesConnected(begin, end);
}


void Graph::VisitVertex(int vertexNumber)
{
	visited_[vertexNumber] = true;
}


bool Graph::IsVertexVisited(int vertexNumber) const
{
	return visited_[vertexNumber];
}


vector<int>::iterator Graph::Begin(int startVertex)
{
	return representation_->Begin(startVertex);
}


vector<int>::iterator Graph::End(int startVertex)
{
	return representation_->End(startVertex);
}


ptrdiff_t Graph::NextVertex(vector<int>::iterator first, vector<int>::iterator last)
{
	return representation_->NextVertex(first, last);
}


void Graph::ResetGraph()
{
	connectedComponentsNumber_ = 0;
	timer_ = 1;

	std::fill(visited_.begin(), visited_.end(), false);
	std::fill(connectedComponents_.begin(), connectedComponents_.end(), 0);
	std::fill(times_.begin(), times_.end(), std::make_pair(0, 0));
}


void Graph::AddConnectedComponent()
{
	++connectedComponentsNumber_;
}


void Graph::SetVertexConnectedComponentNumber(int vertex)
{
	connectedComponents_[vertex] = connectedComponentsNumber_;
}


void Graph::IncreaseTime()
{
	++timer_;
}


void Graph::SetVertexInTime(int vertex)
{
	times_[vertex].first = timer_;
}


void Graph::SetVertexOutTime(int vertex)
{
	times_[vertex].second = timer_;
}


void DirectedGraph::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
}


bool DirectedGraph::IsAcyclic()
{
	DepthFirstSearch(this);

	int numberVertices = NumberOfVertices();
	
	for (int i = 0; i < numberVertices; ++i)
	{
		for (vector<int>::iterator iter = Begin(i); iter != End(i); ++iter)
		{
			int nextVertex = NextVertex(Begin(i), iter);
			if (nextVertex != -1)
			{
				if (times_[nextVertex].first < times_[i].first && times_[i].second < times_[nextVertex].second)
					return true;
			}
		}
	}
	return false;
}


void DirectedGraph::TopologicallySort() const
{	
	// B, A, D, C, E, F
	// directed acyclic graphs or dags
	// с помощью поиска в глубину, расположить вершины в порядке убывания их post-значений
}


void UndirectedGraph::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
	representation_->AddEdge(endVertex, beginVertex);
}

