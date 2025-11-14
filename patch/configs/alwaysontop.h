#define CONFIG_ALWAYSONTOP_CONSTS \
	static int aotindicatortype              = INDICATOR_TOP_LEFT_LARGER_SQUARE;

#define CONFIG_ALWAYSONTOP_KEYS \
	{ MODKEY|ShiftMask,             XK_space,      togglealwaysontop,      {0} },
