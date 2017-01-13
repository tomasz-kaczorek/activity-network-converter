#include "graph.h"

Graph::Graph(int vertices) :
        mVertices(QVector<Vertex>(vertices, Vertex()))
{
}

Graph::operator QString() const
{
        QString output = QString::number(mVertices.size()) + "\n";
        foreach (Edge edge, mEdges)
        {
                output += QString::number(edge.mTail) + " " + QString::number(edge.mHead) + (edge.mFake ? " fake\n" : "\n");
        }
        return output;
}

void Graph::sort()
{
        std::sort(mEdges.begin(), mEdges.end());
}

void Graph::addVertex()
{
        mVertices.append(Vertex());
}

void Graph::addEdge(int tail, int head)
{
        mEdges.append(Edge(tail, head));
        ++mVertices[head].mIndegree;
        ++mVertices[tail].mOutdegree;
}

void Graph::fakeEdge(Edge & edge, int head)
{
        --mVertices[edge.mHead].mIndegree;
        edge.mHead = head;
        edge.mFake = true;
}
