#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}
void Client::render(){
    burger->render(); // draw burger
    if(nextClient != nullptr){
        nextClient->turnToRed(); //turn the client to red over 
    }
    sprite.draw(x, y, width, height);
    ofSetColor(255,255,255);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
        if(nextClient == nullptr)  //Check if burger are equal through every client
            {
                if(equals(burger))
                {
                    this->burger->setCanTakeMoney(false);
                    isLeaving = true;
                    return 10;
                }
            }
        if(equals(burger))
        {
            if(nextClient->getBurger()->getCanTakeMoney())
            {
                isLeaving = true;
                this->burger->setCanTakeMoney(false);
                return 10;// + nextClient->serve(burger);
            }

            return nextClient->serve(burger);
        }else
        {
            if(nextClient != nullptr){
                return nextClient->serve(burger);
            }else
            {
                return 0;
            }
        }
}

void Client::turnToRed() //Change client to red when their patience drop
{

        turnRed = 255 - patience / 8;
        ofSetColor(255, 255 - turnRed, 255 - turnRed);
    
}

bool Client::equals(Burger* targetBurger ) //Check if burger are equals
{
    if(!this->burger->getCanTakeMoney()) return false;
    if(targetBurger->getIngredient().empty() || targetBurger->getIngredient().size() < 6) return false;
    stack<Item*> chefBurger = targetBurger->getIngredient(); //temporary stack
    stack<Item*> clientBurger = this->burger->getIngredient(); //temporary stack
    int stackSize = clientBurger.size();
    if(chefBurger.size() != this->burger->getIngredient().size()) return false; //check if size are equals
    if(chefBurger.top()->name != "topBun" || clientBurger.top()->name != "topBun") return false;//check if top buns are right
    for(int i = 0; i < stackSize; i++)//check if bottomBun is equal in both burger
    {
        
        if(chefBurger.size() - 1 == chefBurger.empty())
        {
            if(chefBurger.top()->name == "bottomBun" && clientBurger.top()->name == "bottomBun")
            {
                break; 
            }else
            {
                return false;
            }
        }
        chefBurger.pop();
        clientBurger.pop();
    }
    chefBurger = targetBurger->getIngredient();
    clientBurger = this->burger->getIngredient();
    bool flag = false;
    vector<Item*> tempBurgerVector; //Change one stack to the vector so is easier to check if they are the same
    while(!chefBurger.empty()){
        tempBurgerVector.push_back(chefBurger.top());
        chefBurger.pop();
    }

        while(clientBurger.size() != 0){
            for(int i = 0; i < tempBurgerVector.size(); i++)
            {
                if(tempBurgerVector[i]->name == clientBurger.top()->name)
                {
                    clientBurger.pop();
                    tempBurgerVector.erase(tempBurgerVector.begin() + i);
                    flag = true;
                    break;
                }
                
            }
            if(!flag) return false;
            flag = false;
            if(clientBurger.size() == 0)
            {
                return true;
            }
    }
    
    return false;
}
