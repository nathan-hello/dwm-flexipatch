#define NO_MOD_BUTTONS_CONSTS \
	static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */

#define NO_MOD_BUTTONS_KEYS \
	{ MODKEY|ShiftMask,             XK_Escape,     togglenomodbuttons,     {0} },
