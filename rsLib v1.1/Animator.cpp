#include "Animator.h"

rsLib::Animator::Animator(easing ease)
{
	this->ease = ease;
}

bool rsLib::Animator::animate(float delta, bool X, bool Y,  sf::Transformable& effected , sf::Vector2f to, float  time  , float startValue, float changeInValue, float  duration )
{

	Easing easing;
	if (effected.getPosition().x != to.x or effected.getPosition().y != to.y  )
	{
		switch (this->ease)
		{
		case easing::linear:
			if (X and !Y) {
				effected.move(easing.linear( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier)  , 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.linear( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier)  );

			}
			if (X and Y) {
				effected.move(easing.linear( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier) , easing.linear( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier) );

			} 
			break;
		case easing::easingOut:
			if (X and !Y) {
				effected.move(easing.easingOut( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easingOut( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easingOut( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easingOut( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;

		case easing::easeInQuad:
			if (X and !Y) {
				effected.move(easing.easeInQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInOutQuad:
			if (X and !Y) {
				effected.move(easing.easeInOutQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInOutQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInOutQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInOutQuad( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInCubic:
			if (X and !Y) {
				effected.move(easing.easeInCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInCirc:
			if (X and !Y) {
				effected.move(easing.easeInCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeOutCirc:
			if (X and !Y) {
				effected.move(easing.easeOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInOutCirc:
			if (X and !Y) {
				effected.move(easing.easeInOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInOutCirc( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easingInOutCubic:
			if (X and !Y) {
				effected.move(easing.easingInOutCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easingInOutCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easingInOutCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easingInOutCubic( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInQuart:
			if (X and !Y) {
				effected.move(easing.easeInQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeOutQuart:
			if (X and !Y) {
				effected.move(easing.easeOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInOutQuart:
			if (X and !Y) {
				effected.move(easing.easeInOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInOutQuart( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInSine:
			if (X and !Y) {
				effected.move(easing.easeInSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInOutSine:
			if (X and !Y) {
				effected.move(easing.easeInOutSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInOutSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInOutSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInOutSine( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInExpo:
			if (X and !Y) {
				effected.move(easing.easeInExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeInExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeOutExpo:
			if (X and !Y) {
				effected.move(easing.easeOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		case easing::easeInOutExpo:
			if (X and !Y) {
				effected.move(easing.easeInOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), 0.f);
			}
			else if (Y and !X) {
				effected.move(0.0f, easing.easeInOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			if (X and Y) {
				effected.move(easing.easeInOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier), easing.easeOutExpo( time * delta * multiplier, startValue, changeInValue,  duration * delta * multiplier));

			}
			break;
		default:
			
			break; 
		}
		return false;
	}
	else {
		return true;
	}


}

 