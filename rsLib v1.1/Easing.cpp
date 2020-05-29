#include "Easing.h"
float rsLib::Easing::linear(float t, float b, float  c, float d) {
	return static_cast<float>(c * (t / d) + b);

}
float rsLib::Easing::easeInQuad(float t, float b, float  c, float d) {
	t /= d;
	return static_cast<float>(-c * t * (t - 2) + b);
}
float rsLib::Easing::easeInOutQuad(float t, float b, float  c, float d) {
	t /= d / 2;
	if (t < 1) {
		return static_cast<float>(c / 2 * t * t + b);
	}
	t--;
	return static_cast<float>(-c / 2 * (t * (t - 2) - 1) + b);
}
float rsLib::Easing::easeInCubic(float t, float b, float  c, float d) {
	t /= d;
	return static_cast<float>(c * t * t * t + b);
}
float rsLib::Easing::easingOut(float t, float b, float  c, float d) {
	t /= d;
	t--;
	return static_cast<float>(c * (t * t * t + 1) + b);
}
float rsLib::Easing::easingInOutCubic(float t, float b, float  c, float d) {
	t /= d / 2;
	if (t < 1) {
		return static_cast<float>(c / 2 * t * t * t + b);
	}
	t -= 2;
	return static_cast<float>(c / 2 * (t * t * t + 2) + b);
}
float rsLib::Easing::easeInQuart(float t, float b, float  c, float d) {
	t /= d;
	return static_cast<float>(c * t * t * t * t + b);
}
float rsLib::Easing::easeOutQuart(float t, float b, float  c, float d) {
	t /= d;
	t--;
	return static_cast<float>(-c * (t * t * t * t - 1) + b);
}
float rsLib::Easing::easeInOutQuart(float t, float b, float  c, float d) {
	t /= d / 2;
	if (t < 1) {

		return static_cast<float>(c / 2 * t * t * t * t + b);
	}
	t -= 2;
	return static_cast<float>(-c / 2 * (t * t * t * t - 2) + b);
}
float rsLib::Easing::easeInSine(float t, float b, float  c, float d) {
	return  static_cast<float>(-c * cos(t / d * (PI / 2)) + c + b);
}
float rsLib::Easing::easeInOutSine(float t, float b, float  c, float d)
{
	return static_cast<float>(-c / 2 * (cos(PI * t / d) - 1) + b);

}
float rsLib::Easing::easeInExpo(float t, float b, float  c, float d)
{
	return static_cast<float>(c * pow(2, 10 * (t / d - 1)) + b);
}
float rsLib::Easing::easeOutExpo(float t, float b, float  c, float d)
{
	return static_cast<float>(c * (-pow(2, -10 * t / d) + 1) + b);
}
float rsLib::Easing::easeInOutExpo(float t, float b, float  c, float d)
{
	t /= d / 2;
	if (t < 1) {
		return static_cast<float>(c / 2 * pow(2, 10 * (t - 1)) + b);
	}
	t--;
	return static_cast<float>(c / 2 * (-pow(2, -10 * t) + 2) + b);
}
float rsLib::Easing::easeInCirc(float t, float b, float  c, float d)
{


	t /= d;
	return -c * (sqrt(1 - t * t) - 1) + b;
};
float rsLib::Easing::easeOutCirc(float t, float b, float  c, float d) {
	t /= d;
	t--;
	return static_cast<float>(c * sqrt(1 - t * t) + b);

}
float rsLib::Easing::easeInOutCirc(float t, float b, float  c, float d) {

	if (t < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
	t -= 2;
	return static_cast<float>(c / 2 * (sqrt(1 - t * t) + 1) + b);
}