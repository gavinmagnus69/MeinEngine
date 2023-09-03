//
// Created by Roman on 01.09.2023.
//

#ifndef MEINENGINE_WINDOW_H
#define MEINENGINE_WINDOW_H
#include <windows.h>

class Window {
public:
    Window();
    ~Window();
    bool init();
    //initialize window
    bool release();
    //release window
    bool broadcast();
    bool isRun();
    //events
    virtual void onCreate() = 0;
    virtual void onUpdate() = 0;
    virtual void onDestroy();

protected:
    HWND m_hwnd;
    bool m_is_run;

};


#endif //MEINENGINE_WINDOW_H
