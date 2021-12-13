#include "GameState.h"

GameState::GameState() {
	gameMusic.load("Sounds/bensound-jazzyfrenchy.mp3");
	jukebox.load("images/jukebox.png");
	//^Load all music
	jukeboxSong.load("Sounds/lookslikechristmas.mp3");
	jukeboxSong1.load("Sounds/hollyjollychristmas.mp3");
	jukeboxSong2.load("Sounds/santababy.mp3");
	jukeboxSong3.load("Sounds/feliznavidad.mp3");
	jukeboxSong4.load("Sounds/wantForChristmas.mp3");
	this->restaurant = new Restaurant();
	//^button music
	this->musicButton = new Button(680, 230, 150, 200, jukebox);
	this->musicOption = 1; 
}
Restaurant* GameState::getRestaurant() {
	return this->restaurant; 
}
void GameState::tick() {
	//^Start the original music when the all the juke music stop
	if(!gameMusic.isPlaying() && !jukeboxSong.isPlaying()
	&&!jukeboxSong1.isPlaying() &&  !jukeboxSong2.isPlaying() 
	&&  !jukeboxSong3.isPlaying() &&  !jukeboxSong4.isPlaying()){ // Beginning music play
		gameMusic.play();
	}
	//^Stop the original music if the juke music is playing
	if(gameMusic.isPlaying() && jukeboxSong.isPlaying()
	|| jukeboxSong1.isPlaying() ||  jukeboxSong2.isPlaying() 
	|| jukeboxSong3.isPlaying() ||  jukeboxSong4.isPlaying()){
		gameMusic.stop();
	}
	restaurant->tick();
	//if money is 100 you win
	if(restaurant->getMoney() >= 100) {
		gameMusic.stop();
		gameMusic.stop();
		{
		jukeboxSong.stop();
		jukeboxSong1.stop();
		jukeboxSong2.stop();
		jukeboxSong3.stop();
		jukeboxSong4.stop();
		}
		setNextState("Win");
		setFinished(true);
		restaurant = new Restaurant(); 
		musicOption = 1;
	}
	//if 10 client leave you lose
	if(restaurant->getEntityManager()->leavingClients >= 10) {
		gameMusic.stop();
		{
			jukeboxSong.stop();
			jukeboxSong1.stop();
			jukeboxSong2.stop();
			jukeboxSong3.stop();
			jukeboxSong4.stop();
		}
		setNextState("Lose");
		setFinished(true);
		restaurant = new Restaurant();
		musicOption = 1;
	}
	musicButton->tick();
    if(musicButton->wasPressed()){
		//gameMusic.stop();
		switch(musicOption) {//change  the music and the musicOption is the counter who decide ehat music is going to play
            case 1: 
				jukeboxSong4.stop();
            	jukeboxSong.play();
                break;
            case 2: 
                jukeboxSong.stop();
            	jukeboxSong1.play();
                break;
            case 3: 
                jukeboxSong1.stop();
            	jukeboxSong2.play();
                break;
            case 4:
                jukeboxSong2.stop();
            	jukeboxSong3.play();
                break;
            case 5:
                jukeboxSong3.stop();
            	jukeboxSong4.play();
                musicOption = 0;
                break; 
        }
		musicOption += 1; //change the music
	} 
	
}
void GameState::render() { //draw the restaurant and the music button
	restaurant->render();
	musicButton->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	musicButton->mousePressed(x, y); // check if mouse pressed the button
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	musicOption = 1;
	setFinished(false);
	setNextState("");
}
void GameState::resetMusic() {
	this->musicOption = 1;
}
void GameState::playMusic() {
	this->gameMusic.play();
}