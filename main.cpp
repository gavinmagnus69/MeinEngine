#include <iostream>
#include "AppWindow.h"
int main() {
    AppWindow app;
    bool b = app.init();
    //std::cout << b ;
    if(b){

        while (app.isRun())
            app.broadcast();

    }

    return 0;
}
