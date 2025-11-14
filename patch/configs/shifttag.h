#define CONFIG_SHIFTTAG_KEYS \
	{ MODKEY|ShiftMask,             XK_Left,       shifttag,               { .i = -1 } }, /* note keybinding conflict with focusadjacenttag tagtoleft */ \
	{ MODKEY|ShiftMask,             XK_Right,      shifttag,               { .i = +1 } }, /* note keybinding conflict with focusadjacenttag tagtoright */
