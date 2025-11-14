#define CONFIG_KEYMODES_ENTRY \
	{ MODKEY,                       XK_Escape,     setkeymode,             {.ui = COMMANDMODE} },

#define CONFIG_KEYMODES_CMDKEYS \
  static const Key cmdkeys[] = { \
	/* modifier                    keys                     function         argument */ \
	{ 0,                           XK_Escape,               clearcmd,        {0} }, \
	{ ControlMask,                 XK_c,                    clearcmd,        {0} }, \
	{ 0,                           XK_i,                    setkeymode,      {.ui = INSERTMODE} },\
  };

#define CONFIG_KEYMODES_COMMANDS \
static const Command commands[] = { \
    /* modifier (4 keys)                          keysyms (4 keys)                                function         argument */ \
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_h,     0,         0},            setlayout,       {.v = &layouts[0]} }, \
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_o,     0,         0},            setlayout,       {.v = &layouts[2]} }, \
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_o,     0,         0},            onlyclient,      {0} }, \
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_v,     0,         0},            setlayout,       {.v = &layouts[0]} }, \
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = -0.05} }, \
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = +0.05} }, \
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_0,     0,         0},            setmfact,        {.f = +1.50} }, \
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_e,     0,         0},            spawn,           {.v = dmenucmd} }, \
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_o,     0,         0},            spawn,           {.v = dmenucmd} }, \
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_q,     XK_Return, 0},            quit,            {0} }, \
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_d,      XK_Return},    killclient,      {0} }, \
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = +1} }, \
    { {ShiftMask,   0,          ShiftMask, 0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = -1} }, \
};
