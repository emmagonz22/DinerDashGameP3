#pragma once

#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
    spriteSheet.load("images/burger.png");
    patty.cropFrom(spriteSheet, 30, 134, 103, 48);
}

void StoveCounter::cookPatty() {
    //starts cooking the patty at the beginning of the game
    if(counter == 0) isCooking = true;
    //patty is done cooking
    if(counter == 50) {
            isCooking = true;
            ofSetColor(125,79,0);
            this->showItem();
            ofSetColor(255);

    }
    //increment counter, serves as a timer
    if(counter < 50)
        {
            counter++;
        }
}