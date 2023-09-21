//
// Created by Roman on 03.09.2023.
//

#ifndef MEINENGINE_GRAPHICSENGINE_H
#define MEINENGINE_GRAPHICSENGINE_H
#include <d3d11.h>


class SwapChain;

class GraphicsEngine {
public:
    GraphicsEngine();
    ~GraphicsEngine();
    //initialize the graph eng and directx 11 device
    bool init();

    //release all the resources loaded

    bool release();
public:
    static GraphicsEngine* get();

private:
    ID3D11Device * m_d3d_device;
    D3D_FEATURE_LEVEL m_feature_level;
    ID3D11DeviceContext * m_imm_context;

private:
    IDXGIDevice * m_dxgi_device;
    IDXGIAdapter * m_dxgi_adapter;
    IDXGIFactory * m_dxgi_factory;
private:
    friend class SwapChain;
};


#endif //MEINENGINE_GRAPHICSENGINE_H
