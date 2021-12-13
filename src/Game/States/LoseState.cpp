#include "LoseState.h"

LoseState::LoseState() {
	buttonSound.load("Sounds/buttonSound.mp3");
	background.load("images/loseScreen.jpg"); 
	background2.load("images/loseScreenHighlighted.jpg"); 
	sound.load("Sounds/bensound-psychedelic.mp3");
	restartButton = new Button(ofGetWidth()/2 - 69.5, ofGetHeight()/2 - 31, 135, 30, "                       ");

}
void LoseState::tick() {
	restartButton->tick();
	if(sound.isPlaying()==false){ // Beginning music play
		sound.play();
	}
	if(restartButton->wasPressed()){
		buttonSound.play();
		sound.stop();
		setNextState("Menu");
		setFinished(true);

	}
}
void LoseState::render() {
	if(ofGetMouseX() < ofGetWidth()/2 + 65.5  && ofGetMouseX() > ofGetWidth()/2 - 71 
	&& ofGetMouseY() < ofGetHeight()/2 + 31/4 && ofGetMouseY() > ofGetHeight()/2 - 31)
	{
		background2.draw(0, 0, ofGetWidth(), ofGetHeight());
	}else
	{
    	background.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
    restartButton->render();
    ofSetColor(255);
}

void LoseState::keyPressed(int key){

}

void LoseState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}