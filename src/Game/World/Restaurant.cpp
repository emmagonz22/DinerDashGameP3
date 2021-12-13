//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"
#include "Inspector.h"
Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

int Restaurant::getMoney() {
    return this->money; 
}

Restaurant::Restaurant() {
    ofImage carpetSheet, decorationSheet,chritsmasDeco;
    //Load decoration
    decorationSheet.load("images/rpg_maker_vx_ace___vx_like_xp_tile_by_ayene_chan_d7t1yi0.png");
    chritsmasDeco.load("images/Maru's MV Bits.png");
    floorTest.load("images/redfloor.png");
    inspector.load("images/People/inspector.png");
    lights.cropFrom(chritsmasDeco,97, 48,143,32);
    doorBell.load("Sounds/doorBell.wav");
    font.load("font/sherloks.otf", 30);
    floor.load("images/floor.jpg");
    christmasTree.cropFrom(chritsmasDeco,95,532, 98,113);
    gifts.cropFrom(chritsmasDeco,288,720, 96,48);
    table.cropFrom(decorationSheet, 193, 264, 61, 61); 
    carpetSheet.load("images/celianna_mansiontiles1.png");
    sprite.load("images/sprite.png");
    sprites2.load("images/candle.png");
    snowGlobe.load("images/snowman.png");
    backCounter.cropFrom(decorationSheet, 0, 484, 256, 27); // top bun
    carpet.cropFrom(carpetSheet,19,615,95,63);
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);  
    initItems();
    initCounters();
    initClients();
    generateClient();
    this->money = 0;

}
void Restaurant::initItems(){
    //load burger items
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    //load counters
    int counterWidth = 96;
    int yOffset = 500;  ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    kitchenWithFlame.load("images/kitchenWithFlamess.png");
    stoveCounterWithFlameImg.cropFrom(kitchenWithFlame, 224,12,32,43);
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    //load characters
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    StoveCounter* sc = player->getActiveStoveCounter();
    ticks++;
    if(ticks % 400 == 0){
            int tryInspector = ofRandom(10);
            if(tryInspector == 5) // 1 in 10 chance to apperar the inspector
            { //The inspector had sunglasses
                generateInspector();
            }else
            {
                generateClient();
            }
    }
    player->tick();
    entityManager->tick();
    if(entityManager->firstClient->getPatience() == 1)
    {
        if(dynamic_cast<Inspector *>(entityManager->firstClient))
        {//Half money if inspector reach 1 in patience
            this->money /= 2;
        }
    }
}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    randomIngredient(b); //random burger
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
    if(counter != 0)
    {
        doorBell.play();    
    }
    counter++;

}
void Restaurant::generateInspector(){
    Burger* inspectorBurger = new Burger(72, 100, 50, 25);
    inspectorBurger->addIngredient(botBread);
    randomIngredient(inspectorBurger); //random ingredient for inspector burger
    inspectorBurger->addIngredient(topBread);
    entityManager->addInspector(new Inspector(0, 50, 64, 72,inspector, inspectorBurger));
    if(counter != 0)
    {
        doorBell.play();    
    }
    counter++;

}
void Restaurant::render() {
    StoveCounter* sc = player->getActiveStoveCounter();
    // crops specific objects
    chair.cropFrom(sprite, 109, 52, 34, 38);
    tabletops.cropFrom(sprites2, 281, 63, 192, 303);

    //draw objects
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    floorTest.resize(814,768 - 200);
    floorTest.draw(0,0,ofGetWidth(), ofGetHeight()-168);
    table.draw(455, 40, 140, 140);
    chair.draw(410, 85, 50, 50);
    chair.draw(600, 85, 50, 50);
    snowGlobe.draw(495, 55, 60, 60);

    table.draw(455, 305, 140, 140);
    chair.draw(410, 350, 50, 50);
    chair.draw(600, 350, 50, 50);
    snowGlobe.draw(495, 320, 60, 60);

    table.draw(215, 150, 140, 140);
    chair.draw(170, 195, 50, 50);
    chair.draw(360, 195, 50, 50);
    snowGlobe.draw(258, 165, 60, 60);

    //carpet.draw(0, 0, 95, 63);
    {//Christmas deco draw
    christmasTree.resize(125,146);
    christmasTree.draw(455,130);
        {
            lights.draw(0,0, 205, 50), lights.draw(205,0, 205, 50);
            lights.draw(205*2,0, 205, 50), lights.draw(205*3,0, 205, 50);
        }
        gifts.draw(466,255, 96,48);
    }
    backCounter.draw(0, 711, 820, 57);
    player->render();
    entityManager->render();
    //if(dynamic_cast<StoveCounter*>(sc) != NULL){
        if(player->getStoveCounter() < 50)
        {
            stoveCounterWithFlameImg.draw(96 * 2, 500, 96,102);
        }
  //  }
    ofSetColor(2,213, 2);
    font.drawString("Money: " + to_string(money), ofGetWidth()/2 - font.stringWidth("Money: ")/2, 30);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        if(entityManager->firstClient->getBurger()->getCanTakeMoney())
        {
            //add money if it found and equal burger
            money += entityManager->firstClient->serve(player->getBurger());
        }
        
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    } 
}
EntityManager* Restaurant::getEntityManager() {
    return this->entityManager;
}

void Restaurant::randomIngredient(Burger* b)
{
    for(int k = 0; k < 5; k++) // can be change the k < 5 for more ingredient in the burger
    {
        int randomNumber = ofRandom(0,4); 
        switch (randomNumber) // select random ingredient
        {
        case 0:
            b->addIngredient(burger);
            break;
        case 1:
            b->addIngredient(cheese);
            break;
        case 2:       
            b->addIngredient(tomato);
            break;
        case 3:
            b->addIngredient(lettuce);
            break;
        }
    }
}