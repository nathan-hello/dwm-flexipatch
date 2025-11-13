#define RENAMED_SCRATCHPADS_CMD \
	static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};

#define RENAMED_SCRATCHPADS_CONSTS \
	static char scratchselfgcolor[]          = "#FFF7D4"; \
	static char scratchselbgcolor[]          = "#77547E"; \
	static char scratchselbordercolor[]      = "#894B9F"; \
	static char scratchselfloatcolor[]       = "#894B9F"; \
	static char scratchnormfgcolor[]         = "#FFF7D4"; \
	static char scratchnormbgcolor[]         = "#664C67"; \
	static char scratchnormbordercolor[]     = "#77547E"; \
	static char scratchnormfloatcolor[]      = "#77547E";

#define RENAMED_SCRATCHPADS_KEYS \
	{ MODKEY,                       XK_grave,      togglescratch,          {.v = scratchpadcmd } }, \
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.v = scratchpadcmd } }, \
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.v = scratchpadcmd } },

#define RENAMED_SCRATCHPADS_COLORS \ 
	[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },     \
	[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor }, \

