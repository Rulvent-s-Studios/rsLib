#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace rsLib {
	class SpriteSheetAnimation
	{

	public:
		SpriteSheetAnimation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime = 0.0f);
		void update(int row, float deltatime, bool faceRight);
		sf::IntRect uvrect;

	private:
		sf::Vector2u imagecount;
		sf::Vector2u currentimage;

		float totalTime = 0.f;
		float switchTime = 0.f;


	};

}