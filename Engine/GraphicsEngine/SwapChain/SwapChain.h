//
// Created by Roman on 21.09.2023.
//

#ifndef MEINENGINE_SWAPCHAIN_H
#define MEINENGINE_SWAPCHAIN_H

#include <d3d11.h>
class SwapChain {
public:
    SwapChain();
    ~SwapChain();

    //initialize swapchain for a window
    bool init(HWND hwnd, UINT width, UINT height);
    //release the swapchain
    bool release();
private:
    IDXGISwapChain* m_swap_chain;
};


#endif //MEINENGINE_SWAPCHAIN_H
