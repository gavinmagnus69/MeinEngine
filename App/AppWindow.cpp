//
// Created by Roman on 03.09.2023.
//

#include "AppWindow.h"

AppWindow::AppWindow() {

}

AppWindow::~AppWindow() {

}

void AppWindow::onUpdate() {

}

void AppWindow::onCreate() {
    //Window::onCreate();
    GraphicsEngine::get()->init();
}

void AppWindow::onDestroy() {

    Window::onDestroy();
    GraphicsEngine::get()->release();
}




