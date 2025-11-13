#define RENAMED_SCRATCHPADS_CMD \
	static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};
#define SCRATCHPADS_ARRAYS \
	const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL }; \
	static Sp scratchpads[] = { \
	   /* name          cmd  */ \
	   {"spterm",      spcmd1}, \
	};
