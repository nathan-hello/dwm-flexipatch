#define INSETS_CONSTS \
	static const Inset default_inset = { \
		.x = 0, \
		.y = 30, \
		.w = 0, \
		.h = 0, \
	};

#define INSETS_KEYS \
	{ MODKEY|ShiftMask|ControlMask, XK_a,          updateinset,            {.v = &default_inset } },
