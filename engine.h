#ifndef ENGINE_H
#define ENGINE_H

#include "graph.h"

class Engine
{
        public:
                Engine();

                void generateInput(int vertices, int jump, qreal chance);
                void generateOutput();

                Graph mInputGraph;
                Graph mOutputGraph;
};

#endif // ENGINE_H
