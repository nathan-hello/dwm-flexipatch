#define MOVERESIZE_KEYS \
	{ MODKEY|Mod4Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } }, \
	{ MODKEY|Mod4Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } }, \
	{ MODKEY|Mod4Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } }, \
	{ MODKEY|Mod4Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
