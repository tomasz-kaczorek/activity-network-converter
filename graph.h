#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "vertex.h"

#include <QVector>

struct Graph
{
        Graph(int mVertices = 0);

        operator QString() const;

        void sort();
        void addVertex();
        void addEdge(int tail, int head);
        void fakeEdge(Edge & edge, int head);

        QVector<Vertex> mVertices;
        QVector<Edge> mEdges;
};

#endif // GRAPH_H
