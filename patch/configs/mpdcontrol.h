#define CONFIG_MPDCONTROL_KEYS \
	{ MODKEY,                       XK_F1,         mpdchange,              {.i = -1} }, \
	{ MODKEY,                       XK_F2,         mpdchange,              {.i = +1} }, \
	{ MODKEY,                       XK_Escape,     mpdcontrol,             {0} },
