//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    canTakeMoney = true;
}

void Burger::addIngredient(Item *item) {
    ingredients.push(item);
}

void Burger::deleteIngredient() {
    if(!ingredients.empty()) ingredients.pop();
}

void Burger::render(){
   int n = ingredients.size();
    for(int i = 0; i < n; i++) {
        temp.push(ingredients.top());
        ingredients.pop();
    }
    for (int j = 0; j < n; j++) {
        ingredients.push(temp.top());
        if(ingredients.top()->name == "patty")
        {
            ofSetColor(125,79,0);
        }
        ingredients.top()->sprite.draw(x,y-(j * 10),width,height);
        ofSetColor(256,256,256);
        temp.pop();
    }
}

void Burger::clear(){
    ingredients.empty();
}