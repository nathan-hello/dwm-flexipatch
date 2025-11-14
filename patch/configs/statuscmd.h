#define CONFIG_BAR_STATUSCMD_DWMBLOCKS_DEFS \
	/* This defines the name of the executable that handles the bar (used for signalling purposes) */ \
	#define CONFIG_STATUSBAR "dwmblocks"

#define CONFIG_BAR_STATUSCMD_ARRAY \
	/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */ \
	static const StatusCmd statuscmds[] = { \
		{ "notify-send Volume$BUTTON", 1 }, \
		{ "notify-send CPU$BUTTON", 2 }, \
		{ "notify-send Battery$BUTTON", 3 }, \
	}; \
	/* test the above with: xsetroot -name "$(printf '\x01Volume |\x02 CPU |\x03 Battery')" */ \
	static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };
