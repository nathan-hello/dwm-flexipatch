#define INPLACEROTATE_KEYS \
	{ MODKEY|Mod4Mask,              XK_j,          inplacerotate,          {.i = +2 } }, /* same as rotatestack */ \
	{ MODKEY|Mod4Mask,              XK_k,          inplacerotate,          {.i = -2 } }, /* same as reotatestack */ \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_j,          inplacerotate,          {.i = +1} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    XK_k,          inplacerotate,          {.i = -1} },
