//
// Created by Roman on 21.09.2023.
//

#include "SwapChain.h"
#include "GraphicsEngine.h"

bool SwapChain::init(HWND hwnd, UINT width, UINT height) {

    ID3D11Device* device = GraphicsEngine::get()->m_d3d_device;
    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.BufferCount = 1;
    desc.BufferDesc.Width = width;
    desc.BufferDesc.Height = height;
    desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.BufferDesc.RefreshRate.Numerator = 60;
    desc.BufferDesc.RefreshRate.Denominator = 1;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.OutputWindow = hwnd;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Windowed = TRUE;

    HRESULT hr = GraphicsEngine::get()->m_dxgi_factory->CreateSwapChain(device, &desc ,&m_swap_chain);
    if(FAILED(hr)){

        return false;

    }
    return true;
}

bool SwapChain::release() {
    return true;
}
