

#include "Button.h"
Button::Button(){
   this->xPos = ofGetWidth()/2;
    this->yPos = ofGetHeight()/2;
    this->width = 64;
    this->height = 20; 
}
Button::Button(int xPos, int yPos, int width, int height, string buttonText){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonText = buttonText;
}
// makes an image a button
Button::Button(int xPos, int yPos, int width, int height, ofImage buttonImage){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonImage = buttonImage;
}

void Button::reset(){
    pressedCounter = -1;
    pressed = false;
}
void Button::tick(){
    pressedCounter--;
    if(pressedCounter == 0){
        pressed = false;
        pressedCounter = -1;
    }

}

void Button::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
    }
}

void Button::render(){
    ofSetColor(255);
    if(!this->buttonText.empty()) {
    ofDrawBitmapString(buttonText, xPos+width/2, yPos+height/2);
    }
    //draws image with the same parameters as in the constructor
    else {
    this->buttonImage.draw(xPos, yPos, width, height);
    }
}

bool Button::wasPressed(){
    return pressed;
}