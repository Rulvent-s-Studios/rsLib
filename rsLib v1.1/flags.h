#pragma once
namespace rsLib {
	enum class actions
	{
		USE_SMOOTH_MOVEMENT, USE_REGULAR_MOVEMENT, NO_ACTION = -1
	};

	enum class	collider {
			COLLIDER1 , COLLIDER2, COLLIDER3  
	 
	};
	
	enum class easing {
		easeInCirc,
		easeOutCirc,
		easeInOutCirc,
		linear,
		easeInQuad,
		easeInOutQuad,
		easeInCubic,
		easingOut,
		easingInOutCubic,
		easeInQuart,
		easeOutQuart,
		easeInOutQuart,
		easeInSine,
		easeInOutSine,
		easeInExpo,
		easeOutExpo,
		easeInOutExpo,
		
	};

	 
}
 