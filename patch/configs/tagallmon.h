#define CONFIG_TAGALLMON_KEYS \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_comma,      tagallmon,              {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_period,     tagallmon,              {.i = -1 } },
