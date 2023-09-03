//
// Created by Roman on 03.09.2023.
//

#ifndef MEINENGINE_APPWINDOW_H
#define MEINENGINE_APPWINDOW_H
#include "Window.h"

class AppWindow : public Window{
public:
    AppWindow();
    ~AppWindow();
    //inherited via Window class
    virtual void onCreate() override;
    virtual void onUpdate() override;
    virtual void onDestroy() override;


};


#endif //MEINENGINE_APPWINDOW_H
