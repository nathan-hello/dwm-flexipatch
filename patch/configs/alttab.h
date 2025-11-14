#define ALT_TAB_CONSTS \
	/* alt-tab configuration */ \
	static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */ \
	static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */ \
	static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */ \
	static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */ \
	static const unsigned int maxwtab          = 600;  /* tab menu width */ \
	static const unsigned int maxhtab          = 200;  /* tab menu height */

#define ALT_TAB_KEYS \
	{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
