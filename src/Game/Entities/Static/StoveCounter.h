#pragma once
#include "Item.h"
#include "Entity.h"
//#include "Restaurant.h"
#include "BaseCounter.h"

class StoveCounter: public BaseCounter {
    private:
        Item *item;
        bool isCooking = false;
        ofImage spriteSheet, patty; 
        int counter = 0;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        void cookPatty();
        int getCounter(){return counter;}
        void setCounter(int resetTicks){counter = resetTicks;}
        void setIsCooking(bool b){isCooking = b;}
        bool getIsCooking(){return isCooking;}

};
