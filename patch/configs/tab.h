#define TAB_KEYS \
	{ MODKEY|ControlMask,           XK_b,          tabmode,                {-1} },

#define TAB_PATCH_CONSTS \
	static const int showtab                 = showtab_auto;        /* Default tab bar show mode */ \
	static const int toptab                  = False;               /* False means bottom tab bar */

/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
#define TAB_ENUM \
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
