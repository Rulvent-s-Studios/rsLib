#include "Action.h"

 

void rsLib::Action::setSettings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
}

 

void rsLib::Action::move(sf::RectangleShape& transform, float delta, actions action ,float speed, float drag, float maxVelocity, float mutiplier)
{
	if (action == actions::USE_SMOOTH_MOVEMENT) {
		position.x = 0, position.y = 0;
		if (sf::Keyboard::isKeyPressed(up)) {
			pup = true;
			position.y = -1.f;

			if (currentVelocity.y > -maxVelocity)
				currentVelocity.y += speed * position.y * delta * mutiplier;
		}
		else {
			pup = false;
		}
		if (sf::Keyboard::isKeyPressed(down)) {
			pdown = true;
			position.y = 1.f;

			if (currentVelocity.y > -maxVelocity)
				currentVelocity.y += speed * position.y * delta * mutiplier;

		}
		else {
			pdown = false;

		}
		if (sf::Keyboard::isKeyPressed(left)) {
			pleft = true;
			position.x = -1.f;
			if (currentVelocity.x > -maxVelocity)
				currentVelocity.x += speed * position.x * delta * mutiplier;

		}
		else {
			pleft = false;
		}
		if (sf::Keyboard::isKeyPressed(right)) {
			pright = true;
			position.x = 1.f;

			if (currentVelocity.x < maxVelocity)
				currentVelocity.x += speed * position.x * delta * mutiplier;
		}
		else {
			pright = false;
		}
		// drag
		if (currentVelocity.x > 0.f) {
			currentVelocity.x -= drag * delta * mutiplier;
			if (currentVelocity.x < 0.f) {
				currentVelocity.x = 0.f;

			}

		}
		else if (currentVelocity.x < 0.f) {
			currentVelocity.x += drag * delta * mutiplier;
			if (currentVelocity.x > 0.f) {
				currentVelocity.x = 0.f;

			}

		}


		if (currentVelocity.y > 0.f) {
			currentVelocity.y -= drag * delta * mutiplier;
			if (currentVelocity.y < 0.f) {
				currentVelocity.y = 0.f;

			}

		}
		else if (currentVelocity.y < 0.f) {
			currentVelocity.y += drag * delta * mutiplier;
			if (currentVelocity.y > 0.f) {
				currentVelocity.y = 0.f;

			}

		}
		transform.move(currentVelocity.x * delta * mutiplier, currentVelocity.y * delta * mutiplier);
	}
	else if (action == actions::USE_REGULAR_MOVEMENT) {
			position.x = 0, position.y = 0;
			if (sf::Keyboard::isKeyPressed(up)) {
				pup = true;
				position.y = -speed * delta;
			}
			else { pup = false; }
			if (sf::Keyboard::isKeyPressed(down)) {
				pdown = true;
				position.y = speed * delta;

			}
			else { pdown = false; }
			if (sf::Keyboard::isKeyPressed(left)) {
				pleft = true;
				position.x = -speed * delta;

			}
			else { pleft = false; }
			if (sf::Keyboard::isKeyPressed(right)) {
				pright = true;
				position.x = speed * delta;
			}
			else { pright = false; }

			transform.move(position.x * mutiplier , position.y * mutiplier);
		}
	else if (action == actions::NO_ACTION) {

		return;

	}

	
}
