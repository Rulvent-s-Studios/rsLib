#pragma once
#include "flags.h"
#include "Easing.h"
#include "SFML/Graphics.hpp"
namespace rsLib {
	class Animator
	{
	public:
		Animator(easing ease);
		bool animate(float delta , bool X, bool Y,  sf::RectangleShape & effected , sf::Vector2f to , float  time  =1.f, float startValue=1.f, float  changeInValue=1.f, float  duration = 1.f);


	private:
		easing ease;
		float  multiplier = 60.0f;
	};
};

