#define RENAMED_SCRATCHPADS_KEYS \
	{ MODKEY,                       XK_grave,      togglescratch,          {.v = scratchpadcmd } }, \
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.v = scratchpadcmd } }, \
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.v = scratchpadcmd } },

#define SCRATCHPADS_KEYS \
	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } }, \
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } }, \
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
