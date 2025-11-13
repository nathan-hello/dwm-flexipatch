#define FSIGNAL_SIGNALS \
  /* signal definitions */ \
  /* signum must be greater than 0 */ \
  /* trigger signals using `xsetroot -name "fsignal:<signum>"` */ \ 
  static Signal signals[] = { \
  	/* signum       function        argument  */ \
  	{ 1,            setlayout,      {.v = 0} }, \
  };
