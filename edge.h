#ifndef EDGE_H
#define EDGE_H


struct Edge
{
        Edge(int tail = -1, int head = -1, bool fake = false);

        bool operator<(Edge const & edge);

        int mHead;
        int mTail;
        bool mFake;
};

inline bool Edge::operator<(Edge const & edge)
{
        return mHead < edge.mHead;
}

#endif // EDGE_H
