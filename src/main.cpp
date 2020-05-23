#include "rsLib.h"
using namespace std;
#define font "dejavusansmono.ttf"
int main()
{
	rsLib::CreateWindow window;
	window.settings(sf::VideoMode(1500, 900), "rsLib testing grounds", sf::Style::Resize | sf::Style::Close);

	rsLib::LabelButton button;

	button.createLabelButton(font, "demo01", sf::Vector2f(750 - 100, 900 / 2), sf::Vector2f(213, 50), 18, sf::Color(255, 255, 255), sf::Color(48, 48, 48), sf::Color(70, 70, 70), sf::Color(0, 0, 0, 0));
	rsLib::LabelButton button2;
	button2.createLabelButton(font, "Exit", sf::Vector2f(550, 900 / 2 + 60), sf::Vector2f(213, 50), 18, sf::Color(255, 255, 255), sf::Color(48, 48, 48), sf::Color(70, 70, 70), sf::Color(0, 0, 0, 0));
	sf::RectangleShape sprite(sf::Vector2f(200, 200));
	sf::RectangleShape player(sf::Vector2f(20,20));
	rsLib::newLabel label;
	label.createLabel(font, "rsLib demo: ", sf::Vector2f(1500 / 2, 900 / 2 - 30), 20, sf::Color(88, 88, 88) ) ;
	rsLib::newLabel info;
	info.createLabel(font, "", sf::Vector2f(200 , 200), 20, sf::Color(233, 233, 233));
	rsLib::Animator movement(rsLib::easing::easingOut);
	sf::Texture texture;
	texture.loadFromFile("SpriteSheet Demo.png");
	rsLib::SpriteSheetAnimation animation(&texture , sf::Vector2u(11,1),0.1f);
	sprite.setTexture(&texture);
	rsLib::Action action;
	action.setSettings(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);
	while (window.isOpen())
	{
		window.useDeltaTime();
		while (window.pollevents()) {
			window.useDefaultPolls();

		}
 
		if (movement.animate(window.deltaTime, true, false, button2.button, sf::Vector2f(750, 900 / 2 + 60))) {



		}
		else {
			button2.updateTextPos();
		}



		if (movement.animate(window.deltaTime, true, false, button.button, sf::Vector2f(750, 900 / 2  ))) {



		}
		else {
			button.updateTextPos();
		}
		action.move(player, window.deltaTime, rsLib::actions::USE_SMOOTH_MOVEMENT );
		button.run(window);
		button2.run(window);
		if (button.pressedLeft) {
			info.setString("Button 1 pressed!");
		}
		if (button2.pressedLeft) {
			info.setString("Button 2 pressed!");
			window.window.close();
		}
		animation.update(0, window.deltaTime, false);
		sprite.setTextureRect(animation.uvrect);
		window.clear();
		window.draw(sprite);
		window.draw(player);
		label.draw(window);
		info.draw(window);
		button.draw(window);
		button2.draw(window);
 		window.display();

	}
}