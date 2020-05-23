#include "SpriteSheetAnimation.h"
rsLib::SpriteSheetAnimation::SpriteSheetAnimation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime)
{

	this->switchTime = switchTime;
	this->imagecount = imagecount;
	totalTime = 0.0f;
	currentimage.x = 0;

	// calculate height and width
	uvrect.width = texture->getSize().x / (unsigned)(imagecount.x);
	uvrect.height = texture->getSize().y / (unsigned)(imagecount.y);

}

void rsLib::SpriteSheetAnimation::update(int row, float deltatime, bool faceRight)
{

	currentimage.y = row;
	totalTime += deltatime;

	if (totalTime >= switchTime/*the  time * delta * multiplier given to switch the frame*/) {
		totalTime -= switchTime; // smoother animation
		currentimage.x++; // switches the current image we have ex 0- > 1 x

		if (currentimage.x >= imagecount.x) {
			currentimage.x = 0; // if it's heigher then the amount we have in total, it will return back to 0.

		}

	}


	uvrect.top = currentimage.y * uvrect.height;

	if (faceRight) {
		uvrect.left = currentimage.x * uvrect.width;

		uvrect.width = abs(uvrect.width);

	}
	else {

		uvrect.left = (currentimage.x + 1) * abs(uvrect.width);
		uvrect.width = -abs(uvrect.width);
	}

}
