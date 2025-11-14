#define CONFIG_FOCUSADJACENTTAG_KEYS \
	{ MODKEY,                       XK_Left,       viewtoleft,             {0} }, /* note keybinding conflict with focusdir */ \
	{ MODKEY,                       XK_Right,      viewtoright,            {0} }, /* note keybinding conflict with focusdir */ \
	{ MODKEY|ShiftMask,             XK_Left,       tagtoleft,              {0} }, /* note keybinding conflict with shifttag */ \
	{ MODKEY|ShiftMask,             XK_Right,      tagtoright,             {0} }, /* note keybinding conflict with shifttag */ \
	{ MODKEY|ControlMask,           XK_Left,       tagandviewtoleft,       {0} }, /* note keybinding conflict with placedir */ \
	{ MODKEY|ControlMask,           XK_Right,      tagandviewtoright,      {0} }, /* note keybinding conflict with placedir */
