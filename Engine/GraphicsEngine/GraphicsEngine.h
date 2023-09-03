//
// Created by Roman on 03.09.2023.
//

#ifndef MEINENGINE_GRAPHICSENGINE_H
#define MEINENGINE_GRAPHICSENGINE_H
#include <d3d11.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    ~GraphicsEngine();
    //initialize the graph eng and directx 11 device
    bool init();

    //release all the resources loaded

    bool release();



};


#endif //MEINENGINE_GRAPHICSENGINE_H
