#define CONFIG_SCRATCHPADS_KEYS \
	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } }, \
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } }, \
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },

#define CONFIG_SCRATCHPADS_ARRAYS \
       const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL }; \
       static Sp scratchpads[] = { \
          /* name          cmd  */ \
          {"spterm",      spcmd1}, \
       };

#define CONFIG_SCRATCHPADS_RULES \
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
