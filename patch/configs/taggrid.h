#define BAR_TAGGRID_DEFS \
	/* grid of tags */ \
	#define SWITCHTAG_UP                1 << 0 \
	#define SWITCHTAG_DOWN              1 << 1 \
	#define SWITCHTAG_LEFT              1 << 2 \
	#define SWITCHTAG_RIGHT             1 << 3 \
	#define SWITCHTAG_TOGGLETAG         1 << 4 \
	#define SWITCHTAG_TAG               1 << 5 \
	#define SWITCHTAG_VIEW              1 << 6 \
	#define SWITCHTAG_TOGGLEVIEW        1 << 7

#define BAR_TAGGRID_CONSTS \
	static const int tagrows = 2;

#define BAR_TAGGRID_KEYS \
	{ MODKEY|ControlMask,           XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_VIEW } }, \
	{ MODKEY|ControlMask,           XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_VIEW } }, \
	{ MODKEY|ControlMask,           XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_VIEW } }, /* note keybinding conflict with placedir */ \
	{ MODKEY|ControlMask,           XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_VIEW } }, /* note keybinding conflict with placedir */ \
	{ MODKEY|Mod4Mask,              XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_TAG | SWITCHTAG_VIEW } }, \
	{ MODKEY|Mod4Mask,              XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_TAG | SWITCHTAG_VIEW } }, \
	{ MODKEY|Mod4Mask,              XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_TAG | SWITCHTAG_VIEW } }, \
	{ MODKEY|Mod4Mask,              XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
