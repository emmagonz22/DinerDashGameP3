//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H

#include "Item.h"
#include "Entity.h"
#include <bits/stdc++.h>

class Burger {
private:
    bool canTakeMoney;
    int x,y,width,height;
    stack <Item*> ingredients, temp;

public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void deleteIngredient();
    void render();
    void clear();
    void setY(int y){
        this->y = y;
    }
    stack<Item*> getIngredient(){return ingredients;}
    bool getCanTakeMoney(){return this->canTakeMoney;}
    void setCanTakeMoney(bool b){
        canTakeMoney = b;
    }
};


#endif //APGAMEENGINE_BURGER_H
