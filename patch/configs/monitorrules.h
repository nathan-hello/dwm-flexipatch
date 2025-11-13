#define MONITOR_RULES_PERTAG_ARRAY \
	static const MonitorRule monrules[] = { \
		/* monitor  tag   layout  mfact  nmaster  showbar  topbar */ \
		{  1,       -1,   2,      -1,    -1,      -1,      -1     }, /* use a different layout for the second monitor */ \
		{  -1,      -1,   0,      -1,    -1,      -1,      -1     }, /* default */ \
	};
