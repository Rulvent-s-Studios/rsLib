#pragma once
#include <SFML/Graphics.hpp>
namespace rsLib {
	class Math
	{
	public:
		double pythagorasTheorem(double a, double b);

		// area
		float squareArea(float side);
		float parallelogramArea(float b, float h);
		float rectangleArea(float width, float length);
		float triangleArea(float base, float height);
		float trapezoidArea(float base1, float base2, float height);
		double circleArea(int radius);
		double ellipseArea(int radius1, int radius2);
		// normalize Functions
		sf::Vector2<double> normalize(sf::Vector2<double> vectorToNormalize);
		sf::Vector2<double> normalize(float x, float y);
		std::vector<float> bubbleSort(std::vector<float> a);
		constexpr double rad_to_degree(float radian);


	private:
		double pi = 3.14;
	};
}
