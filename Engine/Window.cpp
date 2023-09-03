//
// Created by Roman on 01.09.2023.
//

#include "Window.h"
//#include <iostream>

Window::Window() {}

Window::~Window() {}
Window * window = NULL;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){
    switch(msg){
        case WM_CREATE:
            //event fired when the window will be created
            //Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
            // .. and then stored for later lookup
            //SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
            window->onCreate();
            break;
        case WM_DESTROY:
            //event fired when the window will be destroyed
            window->onDestroy();
            ::PostQuitMessage(0);


            break;
        default:
            return ::DefWindowProc(hwnd, msg, wparam, lparam);




    }
    return NULL;


}

bool Window::init() {
    //registration of the class
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = "MeinWindowClass";
    wc.lpszMenuName = "";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;



    if(!::RegisterClassEx(&wc)) {
        //std::cout << "case 1\n";
        return false;
    }

     if(!window){
      window = this;

    }

    //creation of the window
    m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MeinWindowClass", "DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
                            NULL, NULL, NULL, this);

    if(!m_hwnd){
        //std::cout << "case2\n";
        return false;

    }
    //show window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);




   //flag that window is running and initialized
    m_is_run = true;

    return true;
}

bool Window::release() {
    //destroying the window
    if(::DestroyWindow(m_hwnd)){
        return false;
    }
    return true;
}

bool Window::broadcast() {

    MSG msg;

    while(::PeekMessage(&msg , NULL ,0 , 0 , PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);

        DispatchMessage(&msg);




    }
    window->onUpdate();
    Sleep(0);




    return true;
}

void Window::onDestroy() {
    m_is_run = false;

}


bool Window::isRun() {
    return m_is_run;
}

