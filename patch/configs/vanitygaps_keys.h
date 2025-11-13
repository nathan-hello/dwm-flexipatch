#define VANITYGAPS_KEYS \
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } }, \
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
