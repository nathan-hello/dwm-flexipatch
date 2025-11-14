#define CONFIG_SHIFTBOTH_KEYS \
	{ MODKEY|ControlMask,           XK_Left,       shiftboth,              { .i = -1 } }, /* note keybinding conflict with focusadjacenttag tagandviewtoleft placedir */ \
	{ MODKEY|ControlMask,           XK_Right,      shiftboth,              { .i = +1 } }, /* note keybinding conflict with focusadjacenttag tagandviewtoright placedir */
