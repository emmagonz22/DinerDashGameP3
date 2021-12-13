#include "State.h"
#include "Restaurant.h"

class GameState: public State{
    public: 
        GameState();
		Restaurant* getRestaurant();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		void resetMusic();
		void playMusic();
	
	private:
		Restaurant *restaurant;
		ofSoundPlayer gameMusic;
		Button *musicButton;
    	int musicOption = 1;
    	ofSoundPlayer jukeboxSong,jukeboxSong1, jukeboxSong2, jukeboxSong3, jukeboxSong4, jukeboxSong5;
		ofImage jukebox;
};