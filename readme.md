# Diner Dash Game

A festive-themed restaurant management game where players control a chef who must prepare and serve burgers to customers before they lose patience and leave. The game includes special features like random inspector visits and a jukebox with Christmas music.

## Game Description

In Diner Dash, you take on the role of a busy chef in a diner. Your objective is to earn $100 by serving correctly prepared burgers to customers. Be careful though - if 10 customers leave unsatisfied, you lose! Watch out for the inspector who might show up randomly - failing to serve them will cost you half your earnings.

### Key Features
- Customer satisfaction system with visual patience indicator
- Random burger orders with various ingredients
- Special inspector character who affects gameplay
- Interactive cooking mechanics
- Jukebox with multiple Christmas songs
- Money tracking system

## Tech Stack

- **Programming Language**: C++
- **Framework**: OpenFramework
- **Graphics**: OpenFramework's graphics utilities
- **Sound**: OpenFramework's sound player
- **UI Components**: ofxGui addon
- **Build System**: Make/Visual Studio

## Project Structure

```
src/
├── Main/                 # Application entry point and core app files
│   ├── main.cpp          # Program entry point
│   ├── ofApp.h/cpp       # Main application class
│
├── Game/                 # Game-specific code
│   ├── States/           # Game state management
│   │   ├── State.h       # Base state class
│   │   ├── MenuState.h/cpp
│   │   ├── GameState.h/cpp
│   │   ├── WinState.h/cpp
│   │   ├── LoseState.h/cpp
│   │
│   ├── Entities/         # Game entities
│   │   ├── Entity.h/cpp  # Base entity class
│   │   ├── Player.h/cpp  # Player character
│   │   ├── EntityManager.h/cpp
│   │   │
│   │   └── Dynamic/      # Moving entities
│   │       ├── Client.h/cpp
│   │       └── Inspector.h/cpp
│   │
│   │   └── Static/       # Non-moving entities
│   │       ├── BaseCounter.h/cpp
│   │       ├── StoveCounter.h/cpp
│   │       ├── Burger.h/cpp
│   │       └── Item.h/cpp
│   │
│   └── World/            # Game world
│       └── Restaurant.h/cpp
│
├── Game/UI/              # User interface elements
│   └── Button.h/cpp      # Button class
│
└── Resources/            # Resource management
    ├── Images.h          # Image loading and management
    └── Animation.h/cpp   # Animation system
```

## How to Play
- Press 'e' to pick up ingredients
- Press 's' to serve customers
- Press 'u' to remove the last ingredient added
- Press 'h' to hide/show the instruction panel
- Click on the jukebox to change music
- Note: You can only pick up the burger patty when the stove is off

## Copyrighted Resource 

Music link
https://www.bensound.com/index.php?route=product/search&search=retro
https://www.bensound.com
Music name:
jazzyfrenchy
psychedelic
retrosoul
energy

Button sound:
https://www.zapsplat.com/sound-effect-category/button-clicks/page/2/

Feature:
Click jukebox picture to change music:

Jukebox music:
Link: https://www.youtube.com/watch?v=Mk_GmhD053E&ab_channel=EarthaKittVEVO
Name: Santa Baby - Eartha Kitt

Link: https://www.youtube.com/watch?v=fRyhqobl0sk&ab_channel=MariahCarey-Topic
Name: All I Want for Christmas is You - Mariah Carey

Link: https://www.youtube.com/watch?v=RTtc2pM1boE&ab_channel=LeonB
Name: Feliz Navidad - José Feliciano

Link: https://www.youtube.com/watch?v=Dkq3LD-4pmM&ab_channel=MichaelBubl%C3%A9
Name: Holly Jolly Christmas - Michael Bublé

Link: https://www.youtube.com/watch?v=KmddeUJJEuU&ab_channel=PerryComoVEVO
Name: Its Beginning to Look a Lot like Christmas - Perry Como

Some image where found in Pinterest:
https://www.pinterest.com/
