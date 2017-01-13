#include "engine.h"

#include <QDebug>
#include <QElapsedTimer>

Engine::Engine()
{
        qsrand(time(Q_NULLPTR));
}

void Engine::generateInput(int vertices, int jump, qreal chance)
{
        mInputGraph = Graph(vertices);

        for(int vertex = 0; vertex < vertices - 1; ++vertex)
        {
                for(int offset = qMin(vertices - vertex - 1, jump); offset > 0; --offset)
                {
                        if(qrand() < chance * RAND_MAX)
                        {
                                mInputGraph.addEdge(vertex, vertex + offset);
                        }
                }
                if(mInputGraph.mVertices[vertex].mOutdegree == 0)
                {
                        mInputGraph.addEdge(vertex, vertex + 1);
                }
        }
        mInputGraph.sort();
}

void Engine::generateOutput()
{
        mOutputGraph = Graph(mInputGraph);

        //index of next vertex in chosen order
        int next = 0;

        //vertex count in input graph
        //chosen as index of root in output graph
        int vsize = mOutputGraph.mVertices.size();

        //edge count in input graph
        int esize = mOutputGraph.mEdges.size();

        //add new root vertex
        //it is always necessary and always lacking
        mOutputGraph.addVertex();

        for(int i = 0; i < esize;)
        {
                //currently visited vertex
                int head = mOutputGraph.mEdges[i].mHead;

                //no edge is incident to next - it was root vertex in input graph
                //connect it to new root in output graph
                if(next < head)
                {
                        mOutputGraph.addEdge(vsize, next);
                        ++next;
                }
                //an edge incident to next has been found
                else
                {
                        //indegree of current vertex or number of following edges incident to head
                        int indegree = mOutputGraph.mVertices[head].mIndegree;
                        //indegree greater than 1 is not allowed in output graph
                        if(indegree > 1)
                        {
                                //search for best predecessor
                                int base = -1;
                                for(int j = 0; j < indegree && i + j < esize; ++j)
                                {
                                        int tail = mOutputGraph.mEdges[i + j].mTail;
                                        if(mOutputGraph.mVertices[tail].mOutdegree == 1)
                                        {
                                                base = tail;
                                                break;
                                        }
                                }
                                //no good predecessor was found, create one
                                if(base == -1)
                                {
                                        base = mOutputGraph.mVertices.size();
                                        mOutputGraph.addVertex();
                                        mOutputGraph.addEdge(base, head);
                                }
                                //fix incident edges
                                for(int j = 0; j < indegree && i + j < esize; ++j)
                                {
                                        Edge & edge = mOutputGraph.mEdges[i + j];
                                        if(base != edge.mTail)
                                        {
                                                mOutputGraph.fakeEdge(edge, base);
                                        }
                                }
                        }
                        i += indegree;
                        ++next;
                }
        }
}
