#include "WinState.h"

WinState::WinState() {
	//load everything needed
	buttonSound.load("Sounds/buttonSound.mp3");
	restartButton = new Button(ofGetWidth()/2 - 62, ofGetHeight()/2 - 7, 118, 32, "                                  ");
	sound.load("Sounds/bensound-energy.mp3");
    background.load("images/winScreen.jpg");
	background2.load("images/winScreenHighlighted.jpg");
}
void WinState::tick() {
	restartButton->tick();
	if(sound.isPlaying()==false){ // Beginning music play
		sound.play();
	}
	if(restartButton->wasPressed()){ // change state if button is pressed
		buttonSound.play();
		sound.stop();
		setNextState("Game");
		setFinished(true);
	}
}
void WinState::render() {
	//Change the try again button depending over mouse location
	if(ofGetMouseX() < ofGetWidth()/2 + 62  && ofGetMouseX() > ofGetWidth()/2 - 62 
	&& ofGetMouseY() < ofGetHeight()/2 + 29 && ofGetMouseY() > ofGetHeight()/2 - 6)
	{
		background2.draw(0, 0, ofGetWidth(), ofGetHeight()); 
	}else
	{
		background.draw(0, 0, ofGetWidth(), ofGetHeight()); 
	}
	restartButton->render();
	ofSetColor(255);
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}