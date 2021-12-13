#include "MenuState.h"

MenuState::MenuState() {
	//Load everything needed
	buttonSound.load("Sounds/buttonSound.mp3");
	startMusic.load("Sounds/bensound-retrosoul.mp3");
	menuScreen.load("images/dinerDashTitle1.png"); //Load menu screen
	menuScreen.resize(820,768);
	text = "Start";
	titleText = "Dinner dash";
	font.load("font/DailyHours.ttf",32); //load font
	font2.load("font/DailyHours.ttf",60); //load font
	startButton = new Button(ofGetWidth() / 2 - font.stringWidth(text) / 2, ofGetHeight() / 2 - font.stringHeight(text) /2 + 35, font.stringWidth(text), font.stringHeight(text), text);

    // ADDED

    guiPanel.setup("Instruction:", "settings.xml", 60, 20);
	//Print instruction in the menu screen
    guiPanel.add(label1.setup(labelText1, guiPanel.getWidth() + 50, 20));
	guiPanel.add(label2.setup(labelText2, guiPanel.getWidth() + 50, 20));
	guiPanel.add(label3.setup(labelText3, guiPanel.getWidth() + 50, 20));
	guiPanel.add(label4.setup(labelText4, guiPanel.getWidth() + 120, 20));
	guiPanel.add(label5.setup(labelText5, guiPanel.getWidth() + 120, 20));
	guiPanel.add(label6.setup(labelText6, guiPanel.getWidth() + 210, 20));
    guiHide = false;
}
void MenuState::tick() {
	if(startMusic.isPlaying()==false){ // Beginning music play
		startMusic.play();
	}
	startButton->tick();
	if(startButton->wasPressed()){
		buttonSound.play();
		startMusic.stop();
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	//Draw the panel with instruction 
	menuScreen.draw(ofGetWidth() / 2 - menuScreen.getWidth() / 2, ofGetHeight() / 2 - menuScreen.getHeight() / 2);
	if (!guiHide)
    {
        guiPanel.draw();
    }
	//change the start button depending in mouse location
	ofSetColor(172,41,72);
	if(ofGetMouseX() > ofGetWidth() / 2 - font.stringWidth(text)/2 && ofGetMouseX() < ofGetWidth() / 2 + font.stringWidth(text)/2 && ofGetMouseY() > ofGetHeight() / 2 - font.stringHeight(text)/2 + 35&& ofGetMouseY() < ofGetHeight() / 2 + font.stringHeight(text)/2 + 35)
	{
		ofSetColor(215, 186, 0);
		font.drawString(text,ofGetWidth() / 2 - font.stringWidth(text) / 2, ofGetHeight() / 2 - font.stringHeight(text) / 2 + 70);
		ofSetColor(172,41,72);
	}else
	{
		font.drawString(text,ofGetWidth() / 2 - font.stringWidth(text) / 2, ofGetHeight() / 2 - font.stringHeight(text) / 2 + 70);
	}
	font2.drawString(titleText,ofGetWidth() / 2 - font2.stringWidth(titleText) / 2, ofGetHeight() / 2 - font2.stringHeight(titleText) / 2 - 150);
	ofSetColor(256,256,256);
}

void MenuState::keyPressed(int key){
	switch (key) //Press h to hide the instruction
    {
    case 'h':
    case 'H':
        guiHide = !guiHide;
        break;
	}
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}