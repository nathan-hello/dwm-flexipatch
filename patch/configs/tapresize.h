#define CONFIG_TAPRESIZE_CONSTS \
	static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

#define CONFIG_TAPRESIZE_ARRAY \
	/* resizemousescroll direction argument list */ \
	static const int scrollargs[][2] = { \
		/* width change         height change */ \
		{ +scrollsensetivity,	0 }, \
		{ -scrollsensetivity,	0 }, \
		{ 0, 				  	+scrollsensetivity }, \
		{ 0, 					-scrollsensetivity }, \
	};
