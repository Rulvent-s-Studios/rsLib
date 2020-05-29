#include "PhysicsEngine.h"

void rsLib::PhysicsEngine::implementPhysics(float mass, float gravity)
{
	// calculate
	force = mass * gravity;
	acceleration = force / mass;
	
}

void rsLib::PhysicsEngine::effectbyGravity(sf::Transformable& trans)
{
 
	trans.move(sf::Vector2f(0,acceleration));
}
 