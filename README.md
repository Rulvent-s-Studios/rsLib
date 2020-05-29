# rsLib
rsLib, rulvent's studios library for game development.

# Games: 
There aren't  games created with rsLib yet! it's fairly new

# Needs:
You need SFML linked! 


# Hello world in rsLib:
Check if rsLib has linked successfully.

```CPP
#include "rsLib/rsLib.h"

int main() {

	rsLib::CreateWindow window;
	window.settings(sf::VideoMode(600, 600), "rsLib works!", sf::Style::Close);
	sf::RectangleShape block_withMoveableProperties(sf::Vector2f(100,100));
	
	rsLib::Action actions;
	actions.setSettings(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);
	
	while (window.isOpen()) {
		window.useDeltaTime();

		while (window.pollevents()) {
			window.useDefaultPolls();
		}


		actions.move(block_withMoveableProperties, window.deltaTime, rsLib::actions::USE_SMOOTH_MOVEMENT);
		window.clear(sf::Color(44, 44, 44));
		window.draw(block_withMoveableProperties);
		window.display();
	}

}
```


# Modules

[rsLib 1.0]
`CreateWindow` - Used for creating a window is rsLib

`Action` - Used for movements in rsLib

`Collision` - Collision response and Collision Detection

`flags.h` - For setting up some modules in rslib.

`Easing.h` - Easing methods. 

`Animator.h` - Vector Animaton

`SpriteSheetAnimation.h` - For spriteSheets.

`Button` - Creating a button

`LabelButton` - Creating a button with text centered

`newTextBox` - Getting keyboard input and displaying it.

`newLabel` - Printing out text.

`Math` - Math functions that can be used native to regular cpp files. (with out any libraries)

`PhysicsEngine` - small physics engine


# ChangeLogs:
- published rsLib v1.0

- Updated README.MD

- Published rsLib v1.1
	Releasing: an small physics engine and circle collisions!


Rulvent Studios



