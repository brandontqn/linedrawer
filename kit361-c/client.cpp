#include <iostream>
#include "client.h"
#include <math.h>

Client::Client(Drawable *drawable)
{
    this->drawable = drawable;
}


void Client::nextPage() {
    static int pageNumber = 0;
    pageNumber++;
    std::cout << "PageNumber " << pageNumber << std::endl;

    switch(pageNumber % 4) {
    case 1:
        draw_rect(0, 0, 750, 750, 0xffff0080);
        draw_rect( 50,  50, 350, 350, 0xff00ff40);
        draw_rect(400,  50, 700, 350, 0xff40ff00);
        draw_rect( 50, 400, 350, 700, 0xffff8000);
        draw_rect(400, 400, 700, 700, 0xffffff00);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        // fall through...
    default:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(400, 400, 700, 700, 0xff00ff40);
        drawable->updateScreen();
    }
}

void Client::draw_rect(int x1, int y1, int x2, int y2, unsigned int color) {
    for(int x = x1; x<x2; x++) {
        for(int y=y1; y<y2; y++) {
            drawable->setPixel(x, y, color);
        }
    }
}


void Client::draw_starburst(int x1, int y1, int x2, int y2, int len, int numlin, unsigned int color) {
    int theta = 360/numlin;
    int dx = x2-x1;
    int two_dx = 2*dx;
    int two_dy = 2*(y2-y1);
    int t2 = two_dy-two_dx;
    int err = two_dy-dx;
    int y = y1;
    drawable->setPixel(x1,y1,color);

    for(int i = x1+1; i<x2/2; i++) {
        if(err>=0){
            err += t2;
            y += 1;
        }
        else{
            err += two_dy;
        }
        drawable->setPixel(i,y,colour);
    }
}
