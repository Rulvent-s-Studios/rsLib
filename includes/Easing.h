#pragma once
#include  <SFML/Graphics.hpp>
namespace rsLib {
	class Easing
	{
	public:


		float easeInCirc		(float t, float b, float  c, float d); // .
		float easeOutCirc		(float t, float b, float  c, float d); // .
		float easeInOutCirc		(float t, float b, float  c, float d); // .
		float linear			(float t, float b, float  c, float d); // .
		float easeInQuad		(float t, float b, float  c, float d); // .
		float easeInOutQuad		(float t, float b, float  c, float d); // .
		float easeInCubic		(float t, float b, float  c, float d); //.
		float easingOut			(float t, float b, float  c, float d); // .
		float easingInOutCubic	(float t, float b, float  c, float d);  // . 
		float easeInQuart		(float t, float b, float  c, float d); // .
		float easeOutQuart		(float t, float b, float  c, float d); // .
		float easeInOutQuart	(float t, float b, float  c, float d); // .
		float easeInSine		(float t, float b, float  c, float d); // .
		float easeInOutSine		(float t, float b, float  c, float d); // .
		float easeInExpo		(float t, float b, float  c, float d); // .
		float easeOutExpo		(float t, float b, float  c, float d); // .
		float easeInOutExpo		(float t, float b, float  c, float d); // .
	private:
		double PI = 3.14;
	};

};