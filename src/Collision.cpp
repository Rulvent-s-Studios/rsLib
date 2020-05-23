#include "Collision.h"

 

bool rsLib::Collision::checkCollision(sf::RectangleShape& _Give, sf::RectangleShape _Effected, collider method){
	if (method == collider::COLLIDER1) {
		sf::Vector2f otherposition = _Effected.getPosition();
		sf::Vector2f otherHalfSize = sf::Vector2f(_Effected.getSize().x / 2.0f, _Effected.getSize().y / 2.0f);
		sf::Vector2f thisposition = _Give.getPosition();
		sf::Vector2f thisHalfSize = sf::Vector2f(_Give.getSize().x / 2.0f, _Give.getSize().y / 2.0f);

		float deltaX = otherposition.x - thisposition.x;
		float deltaY = otherposition.y - thisposition.y;
		float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
		float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);


		if (intersectX < 0.0f && intersectY < 0.0f) {
			return true;

		}
		else {
			return false;
		}
	}
	else if (method == collider::COLLIDER2) {
		return _Give.getGlobalBounds().intersects(_Effected.getGlobalBounds());
	}
	else if (method == collider::COLLIDER3) {
		if (_Give.getPosition().x < _Effected.getPosition().x + _Effected.getSize().x &&
			_Give.getPosition().x + _Give.getSize().x > _Effected.getPosition().x&&
			_Give.getPosition().y < _Effected.getPosition().y + _Effected.getSize().y &&
			_Give.getPosition().y + _Give.getSize().y > _Effected.getPosition().y) {
			return true;
		}
		return false;
		 
	}
	return false;
}

void rsLib::Collision::giveCollider(sf::RectangleShape& _Give, sf::RectangleShape _Effected, collider method){
	if (method == collider::COLLIDER1) {
		sf::Vector2f otherposition = _Effected.getPosition();
		sf::Vector2f otherHalfSize = sf::Vector2f(_Effected.getSize().x / 2.0f, _Effected.getSize().y / 2.0f);
		sf::Vector2f thisposition = _Give.getPosition();
		sf::Vector2f thisHalfSize = sf::Vector2f(_Give.getSize().x / 2.0f, _Give.getSize().y / 2.0f);

		float deltaX = otherposition.x - thisposition.x;
		float deltaY = otherposition.y - thisposition.y;
		float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
		float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);


		if (intersectX < 0.0f && intersectY < 0.0f) {
			if (intersectX > intersectY) {
				if (deltaX > 0.0f) {
					_Give.move(intersectX * 1.0f, 0.0f);

				}
				else {
					_Give.move(-intersectX * 1.0f, 0.0f);
				}
			}
			else {

				if (deltaY > 0.0f) {
					_Give.move(0.0f, intersectY * 1.0f);
				}
				else {
					_Give.move(0.0f, -intersectY * 1.0f);

				}
			}
		}
	}
	else if  (method == collider::COLLIDER2) {
		
		sf::FloatRect playerbounds = _Give.getGlobalBounds();
		sf::FloatRect wallbounds = _Effected.getGlobalBounds();
		nextpos = playerbounds;
		nextpos.left += this->position.x * 10;
		nextpos.top += this->position.y * 10;
		
		if (nextpos.intersects(wallbounds)) {

			// bottom 
			if (playerbounds.top < wallbounds.top &&
				playerbounds.top + playerbounds.height < wallbounds.top + wallbounds.height &&
				playerbounds.left < wallbounds.left + wallbounds.width &&
				playerbounds.left + playerbounds.width> wallbounds.left) {
				this->position.y = 0.f;
				_Give.setPosition(playerbounds.left, wallbounds.top - playerbounds.height);

			}
			else if (playerbounds.top > wallbounds.top&&
				playerbounds.top + playerbounds.height > wallbounds.top + wallbounds.height &&
				playerbounds.left < wallbounds.left + wallbounds.width &&
				playerbounds.left + playerbounds.width> wallbounds.left) {
				this->position.y = 0.f;
				_Give.setPosition(playerbounds.left, wallbounds.top + wallbounds.height);

			}


			else if (playerbounds.left < wallbounds.left &&
				playerbounds.left + playerbounds.width < wallbounds.left + wallbounds.width &&
				playerbounds.top < wallbounds.top + wallbounds.height &&
				playerbounds.top + playerbounds.height > wallbounds.top) {
				this->position.x = 0.f;
				_Give.setPosition(wallbounds.left - playerbounds.width, playerbounds.top);
			}

			else if (playerbounds.left > wallbounds.left&&
				playerbounds.left + playerbounds.width > wallbounds.left + wallbounds.width &&
				playerbounds.top < wallbounds.top + wallbounds.height &&
				playerbounds.top + playerbounds.height > wallbounds.top) {
				this->position.x = 0.f;
				_Give.setPosition(wallbounds.left + wallbounds.width, playerbounds.top);
			}



		}


	}
	else if (method == collider::COLLIDER3) {

		/* No colider 3  has been implemented */
		return;
	}


}