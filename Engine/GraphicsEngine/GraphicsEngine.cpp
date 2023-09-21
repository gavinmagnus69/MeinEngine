//
// Created by Roman on 03.09.2023.
//

#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine() {

}

GraphicsEngine::~GraphicsEngine() {

}

bool GraphicsEngine::init() {
    D3D_DRIVER_TYPE driver_types[] =
            {
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP,
            D3D_DRIVER_TYPE_REFERENCE
            };
    D3D_FEATURE_LEVEL feature_levels[] =
            {
                    D3D_FEATURE_LEVEL_11_0


            };
    HRESULT res = 0;
    UINT num_feature_levels = ARRAYSIZE(feature_levels);
    UINT num_driver_types = ARRAYSIZE(driver_types);
    for(UINT drive_type_index = 0; drive_type_index < num_driver_types; ){
         res = D3D11CreateDevice(NULL, driver_types[drive_type_index], NULL, NULL, feature_levels, num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device,
                          &m_feature_level, &m_imm_context);

        if(SUCCEEDED(res)){
            break;
        }
        ++drive_type_index;

    }
    if(FAILED(res)){
        return false;
    }
    m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
    m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
    m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);
    m_dxgi_factory->CreateSwapChain()
    return true;
}

bool GraphicsEngine::release() {

    m_imm_context->Release();
    m_d3d_device->Release();
    return true;
}

GraphicsEngine *GraphicsEngine::get() {


    static GraphicsEngine engine;

    return &engine;
}
