#pragma once
#include "SFML/Graphics.hpp"
#include "flags.h"
#include "Action.h"
namespace rsLib {
	class Collision : rsLib::Action
	{
	public:
 		bool checkCollision(sf::RectangleShape& _Give, sf::RectangleShape _Effected , collider method);
		void giveCollider(sf::RectangleShape& _Give, sf::RectangleShape _Effected, collider method );
		sf::FloatRect nextpos;
	private:
	};

}