#define CONFIG_FAKEFULLSCREEN_CLIENT_CONSTS \
	static int fakefsindicatortype           = INDICATOR_PLUS; \
	static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;

#define CONFIG_FAKEFULLSCREEN_KEYS \
	{ MODKEY|ShiftMask,             XK_y,          togglefakefullscreen,   {0} },
