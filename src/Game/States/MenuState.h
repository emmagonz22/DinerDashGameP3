#pragma once

#include "State.h"
#include "Button.h"
#include "ofxGui.h"

class MenuState : public State {
private:
	ofImage menuScreen;
	Button *startButton;
	ofTrueTypeFont font;
	ofTrueTypeFont font2;
	ofSoundPlayer startMusic;
	

public:
	MenuState();
	void setup();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	string text;
	string titleText;
	ofxPanel guiPanel;
	bool guiHide;
	//Instruction Labels for menuState
	ofxLabel label1;
	ofxLabel label2;
	ofxLabel label3;
	ofxLabel label4;
	ofxLabel label5;
	ofxLabel label6;
	const string labelText1 = "Press h hide/show panel";
	const string labelText2 = "Press e to pick ingredient";
	const string labelText3 = "Press s to serve";
	const string labelText4 = "Press u to remove last ingredient added";
	const string labelText5 = "Press jukebox to change music";
	const string labelText6 = "You can only pick the burger when the stove is off";
	ofSoundPlayer buttonSound;
	
};
