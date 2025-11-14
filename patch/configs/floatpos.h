#define CONFIG_FLOATPOS_CONSTS \
	static int floatposgrid_x                = 5;  /* float grid columns */ \
	static int floatposgrid_y                = 5;  /* float grid rows */

#define CONFIG_FLOATPOS_KEYS \
	/* Note that due to key limitations the below example kybindings are defined with a Mod3Mask, */ \
	/* which is not always readily available. Refer to the patch wiki for more details. */ \
	/* Client position is limited to monitor window area */ \
	{ Mod3Mask,                     XK_u,            floatpos,               {.v = "-26x -26y" } }, /* ↖ */ \
	{ Mod3Mask,                     XK_i,            floatpos,               {.v = "  0x -26y" } }, /* ↑ */ \
	{ Mod3Mask,                     XK_o,            floatpos,               {.v = " 26x -26y" } }, /* ↗ */ \
	{ Mod3Mask,                     XK_j,            floatpos,               {.v = "-26x   0y" } }, /* ← */ \
	{ Mod3Mask,                     XK_l,            floatpos,               {.v = " 26x   0y" } }, /* → */ \
	{ Mod3Mask,                     XK_m,            floatpos,               {.v = "-26x  26y" } }, /* ↙ */ \
	{ Mod3Mask,                     XK_comma,        floatpos,               {.v = "  0x  26y" } }, /* ↓ */ \
	{ Mod3Mask,                     XK_period,       floatpos,               {.v = " 26x  26y" } }, /* ↘ */ \
	/* Absolute positioning (allows moving windows between monitors) */ \
	{ Mod3Mask|ControlMask,         XK_u,            floatpos,               {.v = "-26a -26a" } }, /* ↖ */ \
	{ Mod3Mask|ControlMask,         XK_i,            floatpos,               {.v = "  0a -26a" } }, /* ↑ */ \
	{ Mod3Mask|ControlMask,         XK_o,            floatpos,               {.v = " 26a -26a" } }, /* ↗ */ \
	{ Mod3Mask|ControlMask,         XK_j,            floatpos,               {.v = "-26a   0a" } }, /* ← */ \
	{ Mod3Mask|ControlMask,         XK_l,            floatpos,               {.v = " 26a   0a" } }, /* → */ \
	{ Mod3Mask|ControlMask,         XK_m,            floatpos,               {.v = "-26a  26a" } }, /* ↙ */ \
	{ Mod3Mask|ControlMask,         XK_comma,        floatpos,               {.v = "  0a  26a" } }, /* ↓ */ \
	{ Mod3Mask|ControlMask,         XK_period,       floatpos,               {.v = " 26a  26a" } }, /* ↘ */ \
	/* Resize client, client center position is fixed which means that client expands in all directions */ \
	{ Mod3Mask|ShiftMask,           XK_u,            floatpos,               {.v = "-26w -26h" } }, /* ↖ */ \
	{ Mod3Mask|ShiftMask,           XK_i,            floatpos,               {.v = "  0w -26h" } }, /* ↑ */ \
	{ Mod3Mask|ShiftMask,           XK_o,            floatpos,               {.v = " 26w -26h" } }, /* ↗ */ \
	{ Mod3Mask|ShiftMask,           XK_j,            floatpos,               {.v = "-26w   0h" } }, /* ← */ \
	{ Mod3Mask|ShiftMask,           XK_k,            floatpos,               {.v = "800W 800H" } }, /* · */ \
	{ Mod3Mask|ShiftMask,           XK_l,            floatpos,               {.v = " 26w   0h" } }, /* → */ \
	{ Mod3Mask|ShiftMask,           XK_m,            floatpos,               {.v = "-26w  26h" } }, /* ↙ */ \
	{ Mod3Mask|ShiftMask,           XK_comma,        floatpos,               {.v = "  0w  26h" } }, /* ↓ */ \
	{ Mod3Mask|ShiftMask,           XK_period,       floatpos,               {.v = " 26w  26h" } }, /* ↘ */ \
	/* Client is positioned in a floating grid, movement is relative to client's current position */ \
	{ Mod3Mask|Mod1Mask,            XK_u,            floatpos,               {.v = "-1p -1p" } }, /* ↖ */ \
	{ Mod3Mask|Mod1Mask,            XK_i,            floatpos,               {.v = " 0p -1p" } }, /* ↑ */ \
	{ Mod3Mask|Mod1Mask,            XK_o,            floatpos,               {.v = " 1p -1p" } }, /* ↗ */ \
	{ Mod3Mask|Mod1Mask,            XK_j,            floatpos,               {.v = "-1p  0p" } }, /* ← */ \
	{ Mod3Mask|Mod1Mask,            XK_k,            floatpos,               {.v = " 0p  0p" } }, /* · */ \
	{ Mod3Mask|Mod1Mask,            XK_l,            floatpos,               {.v = " 1p  0p" } }, /* → */ \
	{ Mod3Mask|Mod1Mask,            XK_m,            floatpos,               {.v = "-1p  1p" } }, /* ↙ */ \
	{ Mod3Mask|Mod1Mask,            XK_comma,        floatpos,               {.v = " 0p  1p" } }, /* ↓ */ \
	{ Mod3Mask|Mod1Mask,            XK_period,       floatpos,               {.v = " 1p  1p" } }, /* ↘ */
