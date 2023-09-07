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
private:
    ID3D11Device * m3_d3d_device;
    D3D_FEATURE_LEVEL m_feature_level;
    ID3D11DeviceContext * m_imm_context;



};


#endif //MEINENGINE_GRAPHICSENGINE_H
