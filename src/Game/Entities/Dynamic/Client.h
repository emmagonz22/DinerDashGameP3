#pragma once
#include "Entity.h"
#include "Burger.h"


class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
        int turnRed;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        void turnToRed();
        Burger* getBurger(){return burger;}
        bool equals(Burger*); 
        int getPatience(){return patience;}
        int setPatience(int p){patience = p;}
};