#define CONFIG_ON_EMPTY_KEYS_ARRAY \
	static const char* firefoxcmd[] = {"firefox", NULL}; \
	static const Key on_empty_keys[] = { \
		/* modifier key            function                argument */ \
		{ 0,        XK_f,          spawn,                  {.v = firefoxcmd } }, \
	};
