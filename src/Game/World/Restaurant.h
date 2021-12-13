//
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
#include "Button.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        ofTrueTypeFont font;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        int getMoney();
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        //images variable
        ofImage carpet, chair, floor, sprite, floorTest,backCounter, christmasTree, gifts,
                sprites2, table, tabletops, inspector, kitchenWithFlame, stoveCounterWithFlameImg, lights,
                snowGlobe;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        void randomIngredient(Burger*);
        int getTicks();
        EntityManager* getEntityManager();
        ofSoundPlayer doorBell;
        int counter = 0;
};


#endif //APGAMEENGINE_RESTAURANT_H
