#pragma once

#include "State.h"
#include "Button.h"

class LoseState : public State {
private:
	ofImage background;
	ofImage background2;
	Button *restartButton;
	ofSoundPlayer sound;

public:
	LoseState();
	void setup();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	ofSoundPlayer buttonSound;
};
