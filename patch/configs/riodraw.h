#define RIODRAW_CONSTS \
	static const char slopspawnstyle[]       = "-t 0 -c 0.92,0.85,0.69,0.3 -o"; /* do NOT define -f (format) here */ \
	static const char slopresizestyle[]      = "-t 0 -c 0.92,0.85,0.69,0.3"; /* do NOT define -f (format) here */ \
	static const int riodraw_borders         = 0;  /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
#define RIODRAW_SWALLOW_CONSTS \
	static const int riodraw_matchpid        = 1;  /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
