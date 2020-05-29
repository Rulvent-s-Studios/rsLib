#pragma once
#include "SFML/Graphics.hpp"

namespace rsLib {
	class PhysicsEngine
	{
	public:
		void implementPhysics(
			float mass, float gravity
		);

		void effectbyGravity(sf::Transformable& trans);

	private:
		float force = 0.0f;
		float acceleration = 0.0f;
 


	};

}