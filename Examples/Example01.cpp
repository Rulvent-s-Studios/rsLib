#include "rsLib/rsLib.h"
#include <random>
/*
* 
* rsLib: Example01
*
*/

int main() {

	rsLib::CreateWindow window;
	window.settings(sf::VideoMode(600, 600), "Flappy Bird", sf::Style::Close);
	sf::RectangleShape block1(sf::Vector2f(25, 25));
	sf::RectangleShape pipebottom(sf::Vector2f(50, 300));
	sf::RectangleShape pipetop(sf::Vector2f(50,  500));
	sf::RectangleShape block2(sf::Vector2f(700, 500));
	sf::RectangleShape d(sf::Vector2f(100,10));
	rsLib::Action actions;
 	rsLib::Math math;
 	rsLib::Collision col;
	rsLib::Animator animator(rsLib::easing::linear);
	rsLib::PhysicsEngine engine;
	rsLib::Action action;
	sf::View view;
	view.setSize((float)window.window.getSize().x , (float)window.window.getSize().y);
	
 
	action.setSettings(sf::Keyboard::Space, sf::Keyboard::Unknown, sf::Keyboard::Unknown, sf::Keyboard::Unknown);
	bool loose = false;
	float speed = 200;
	block1.setPosition(sf::Vector2f(30, 100));
	block2.setPosition(0, 500);
	block2.setFillColor(sf::Color::Color(100,100,255, 200));
	int offset =  300;
 	pipebottom.setFillColor(sf::Color::Green); pipetop.setFillColor(sf::Color::Green);
	offset = rand() % 300 + 200;
	pipetop.setPosition((float)window.window.getSize().x, (float)-offset - block1.getSize().y - 20);
	block1.setOrigin(sf::Vector2f(block1.getGlobalBounds().width / 2, block1.getGlobalBounds().height / 2));
	pipebottom.setPosition((float)window.window.getSize().x, (float)window.window.getSize().y - pipebottom.getGlobalBounds().height);
	while (window.isOpen()) {
		window.useDeltaTime();
		engine.implementPhysics(3 * 60 * window.deltaTime, 3 * 60 * window.deltaTime);


 		while (window.pollevents()) {
			window.useDefaultPolls();
		} 
			action.move(block1, window.deltaTime, rsLib::actions::USE_SMOOTH_MOVEMENT , 2);
		 
				engine.effectbyGravity(block1);
				if (loose    ) {
					action.setSettings(sf::Keyboard::Unknown, sf::Keyboard::Unknown, sf::Keyboard::Unknown, sf::Keyboard::Unknown);

		}
			 
			 
 		if (col.checkCollision(block1, block2, rsLib::collider::COLLIDER2)) {
			loose = true;
		}
		if (col.checkCollision(block1, pipetop, rsLib::collider::COLLIDER2)) {
			loose = true;


		}
		if (col.checkCollision(block1, pipebottom, rsLib::collider::COLLIDER2)) {
			loose = true;


		}
		
		if (pipebottom.getPosition().x and pipetop.getPosition().x >= -162.839){
			pipebottom.move(-speed * window.deltaTime, 0);
			pipetop.move(-speed * window.deltaTime, 0);

		}
		else if (!loose) {
			offset = rand() % 300 + 200;
			pipetop.setPosition((float)window.window.getSize().x, (float)-offset - block1.getSize().y - 20);
			pipebottom.setPosition((float)window.window.getSize().x, (float)window.window.getSize().y - pipebottom.getGlobalBounds().height    );
		} 
		

		if (action.pup) {
			 
				block1.setRotation(60);
	 
		}
		else {
			block1.setRotation(90);
		}
	 
		window.clear(sf::Color(44, 44, 44));
		window.draw(block1);
		window.draw(pipebottom);
		window.draw(pipetop);
		window.draw(block2);
		window.display();
	}

}