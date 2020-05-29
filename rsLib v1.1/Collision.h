#pragma once
#include "SFML/Graphics.hpp"
#include "flags.h"
#include "Action.h"
namespace rsLib {
	class Collision : rsLib::Action
	{
	public:
 		bool checkCollision(sf::RectangleShape& _Give, sf::RectangleShape& _Effected , collider method);
		void giveCollider(sf::RectangleShape& _Give, sf::RectangleShape& _Effected, collider method );
		void giveCircleCollision(sf::CircleShape& object1, sf::CircleShape& _Effected);
		bool checkCircleCollision(sf::CircleShape& object1, sf::CircleShape& _Effected);
		sf::FloatRect nextpos;
	private:
		sf::FloatRect playerbounds;
		sf::FloatRect wallbounds;
		sf::Vector2f otherposition;
		sf::Vector2f otherHalfSize;
		sf::Vector2f thisposition;
		sf::Vector2f thisHalfSize;
		sf::Vector2f distance;
	 
	 
	 
	 

		float radisum = 0.0f;
		float length=0.0f;
		float unit_x=0.0f;
		float unit_y=0.0f;
		float deltaX=0.0f;
		float deltaY=0.0f;
		float intersectX = 0.0f;
		float intersectY =0.0f;


		
	};

}