//
// Created by Roman on 21.09.2023.
//

#ifndef MEINENGINE_SWAPCHAIN_H
#define MEINENGINE_SWAPCHAIN_H


class SwapChain {
public:
    SwapChain();
    ~SwapChain();

    //initialize swapchain for a window
    bool init();
    //release the swapchain
    bool release();
};


#endif //MEINENGINE_SWAPCHAIN_H
