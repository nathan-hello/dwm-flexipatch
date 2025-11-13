#define EXRESIZE_KEYS \
	{ MODKEY,                       XK_KP_7,       explace,                {.ui = EX_NW }},   /* XK_KP_Home,  */ \
	{ MODKEY,                       XK_KP_8,       explace,                {.ui = EX_N  }},   /* XK_KP_Up,    */ \
	{ MODKEY,                       XK_KP_9,       explace,                {.ui = EX_NE }},   /* XK_KP_Prior, */ \
	{ MODKEY,                       XK_KP_4,       explace,                {.ui = EX_W  }},   /* XK_KP_Left,  */ \
	{ MODKEY,                       XK_KP_5,       explace,                {.ui = EX_C  }},   /* XK_KP_Begin, */ \
	{ MODKEY,                       XK_KP_6,       explace,                {.ui = EX_E  }},   /* XK_KP_Right, */ \
	{ MODKEY,                       XK_KP_1,       explace,                {.ui = EX_SW }},   /* XK_KP_End,   */ \
	{ MODKEY,                       XK_KP_2,       explace,                {.ui = EX_S  }},   /* XK_KP_Down,  */ \
	{ MODKEY,                       XK_KP_3,       explace,                {.ui = EX_SE }},   /* XK_KP_Next,  */ \
	\
	{ MODKEY|ShiftMask,             XK_KP_8,       exresize,               {.v = (int []){   0,  25 }}},  /* XK_KP_Up,    */ \
	{ MODKEY|ShiftMask,             XK_KP_2,       exresize,               {.v = (int []){   0, -25 }}},  /* XK_KP_Down,  */ \
	{ MODKEY|ShiftMask,             XK_KP_6,       exresize,               {.v = (int []){  25,   0 }}},  /* XK_KP_Right, */ \
	{ MODKEY|ShiftMask,             XK_KP_4,       exresize,               {.v = (int []){ -25,   0 }}},  /* XK_KP_Left,  */ \
	{ MODKEY|ShiftMask,             XK_KP_5,       exresize,               {.v = (int []){  25,  25 }}},  /* XK_KP_Begin, */ \
	{ MODKEY|ShiftMask|ControlMask, XK_KP_5,       exresize,               {.v = (int []){ -25, -25 }}},  /* XK_KP_Begin, */ \
	\
	{ MODKEY|ControlMask,           XK_KP_6,       togglehorizontalexpand, {.i = +1} },  /* XK_KP_Right, */ \
	{ MODKEY|ControlMask,           XK_KP_3,       togglehorizontalexpand, {.i =  0} },  /* XK_KP_Next,  */ \
	{ MODKEY|ControlMask,           XK_KP_4,       togglehorizontalexpand, {.i = -1} },  /* XK_KP_Left,  */ \
	{ MODKEY|ControlMask,           XK_KP_8,       toggleverticalexpand,   {.i = +1} },  /* XK_KP_Up,    */ \
	{ MODKEY|ControlMask,           XK_KP_1,       toggleverticalexpand,   {.i =  0} },  /* XK_KP_End,   */ \
	{ MODKEY|ControlMask,           XK_KP_2,       toggleverticalexpand,   {.i = -1} },  /* XK_KP_Down,  */ \
	{ MODKEY|ControlMask,           XK_KP_9,       togglemaximize,         {.i = -1} },  /* XK_KP_Prior, */ \
	{ MODKEY|ControlMask,           XK_KP_7,       togglemaximize,         {.i = +1} },  /* XK_KP_Home,  */ \
	{ MODKEY|ControlMask,           XK_KP_5,       togglemaximize,         {.i =  0} },  /* XK_KP_Begin, */
