/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* Include all patch configurations */
#include "patch/configs/include.h"

/* appearance */
#if ROUNDED_CORNERS_PATCH
CONFIG_ROUNDED_CORNERS_CONSTS
#else
static const unsigned int borderpx       = 1;   /* border pixel of windows */
#endif // ROUNDED_CORNERS_PATCH
#if BAR_BORDER_PATCH
CONFIG_BAR_BORDER_CONSTS
#endif // BAR_BORDER_PATCH
static const unsigned int snap           = 32;  /* snap pixel */
#if SWALLOW_PATCH
CONFIG_SWALLOW_CONSTS
#endif // SWALLOW_PATCH
#if BAR_TAGPREVIEW_PATCH
CONFIG_BAR_TAGPREVIEW_CONSTS
#endif // BAR_TAGPREVIEW_PATCH
#if NO_MOD_BUTTONS_PATCH
CONFIG_NO_MOD_BUTTONS_CONSTS
#endif // NO_MOD_BUTTONS_PATCH
#if VANITYGAPS_PATCH
CONFIG_VANITYGAPS_CONSTS
#endif // VANITYGAPS_PATCH
#if AUTOSTART_PATCH
CONFIG_AUTOSTART_CONSTS
#endif // AUTOSTART_PATCH
#if BAR_ANYBAR_PATCH
CONFIG_BAR_ANYBAR_CONSTS
#endif // BAR_ANYBAR_PATCH
#if BAR_HOLDBAR_PATCH
CONFIG_BAR_HOLDBAR_CONSTS
#else
static const int showbar                 = 1;   /* 0 means no bar */
#endif // BAR_HOLDBAR_PATCH
static const int topbar                  = 1;   /* 0 means bottom bar */
#if TAB_PATCH
CONFIG_TAB_ENUM
CONFIG_TAB_PATCH_CONSTS
#endif // TAB_PATCH
#if BAR_HEIGHT_PATCH
CONFIG_BAR_HEIGHT_CONSTS
#endif // BAR_HEIGHT_PATCH
#if BAR_PADDING_PATCH
CONFIG_BAR_PADDING_CONSTS
#endif // BAR_PADDING_PATCH
#if BAR_WINICON_PATCH
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 5  /* space between icon and title */
#endif // BAR_WINICON_PATCH
#if FOCUSONCLICK_PATCH
CONFIG_FOCUSONCLICK_CONSTS
#endif // FOCUSONCLICK_PATCH
#if FLOATPOS_PATCH
CONFIG_FLOATPOS_CONSTS
#endif // FLOATPOS_PATCH
#if RIODRAW_PATCH
CONFIG_RIODRAW_CONSTS
#if SWALLOW_PATCH
CONFIG_RIODRAW_SWALLOW_CONSTS
#endif // SWALLOW_PATCH
#endif // RIODRAW_PATCH
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
#if BAR_STATUSALLMONS_PATCH
CONFIG_BAR_STATUSALLMONS_CONSTS
#elif BAR_STATICSTATUS_PATCH
CONFIG_BAR_STATICSTATUS_CONSTS
#else
static const int statusmon               = 'A';
#endif // BAR_STATUSALLMONS_PATCH | BAR_STATICSTATUS_PATCH
#if BAR_STATUSPADDING_PATCH
CONFIG_BAR_STATUSPADDING_CONSTS
#endif // BAR_STATUSPADDING_PATCH
#if BAR_STATUSBUTTON_PATCH
CONFIG_BAR_STATUSBUTTON_CONSTS
#endif // BAR_STATUSBUTTON_PATCH
#if BAR_SYSTRAY_PATCH
CONFIG_BAR_SYSTRAY_CONSTS
#endif // BAR_SYSTRAY_PATCH
#if BAR_TAGLABELS_PATCH
CONFIG_BAR_TAGLABELS_CONSTS
#endif // BAR_TAGLABELS_PATCH
#if BAR_UNDERLINETAGS_PATCH
CONFIG_BAR_UNDERLINETAGS_CONSTS
#endif // BAR_UNDERLINETAGS_PATCH

#if NAMETAG_PATCH
#if NAMETAG_PREPEND_PATCH
/* The format in which the tag is written when named. E.g. %d: %.12s will write the tag number
 * followed the first 12 characters of the given string. You can also just use "%d: %s" here. */
#define NAMETAG_FORMAT "%d: %.12s"
#else
#define NAMETAG_FORMAT "%s"
#endif // NAMETAG_PREPEND_PATCH
/* The maximum amount of bytes reserved for each tag text. */
#define MAX_TAGLEN 16
/* The command to run (via popen). This can be tailored by adding a prompt, passing other command
 * line arguments or providing name options. Optionally you can use other dmenu like alternatives
 * like rofi -dmenu. */
#define NAMETAG_COMMAND "dmenu < /dev/null"
#endif // NAMETAG_PATCH

#if ALT_TAB_PATCH
CONFIG_ALT_TAB_CONSTS
#endif // ALT_TAB_PATCH

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
#if FAKEFULLSCREEN_CLIENT_PATCH && !FAKEFULLSCREEN_PATCH
CONFIG_FAKEFULLSCREEN_CLIENT_CONSTS
#endif // FAKEFULLSCREEN_CLIENT_PATCH
#if ALWAYSONTOP_PATCH
CONFIG_ALWAYSONTOP_CONSTS
#endif // ALWAYSONTOP_PATCH
#if ONLYQUITONEMPTY_PATCH
CONFIG_ONLYQUITONEMPTY_CONSTS
#endif // ONLYQUITONEMPTY_PATCH
#if BAR_EXTRASTATUS_PATCH
CONFIG_BAR_EXTRASTATUS_CONSTS
#endif // BAR_EXTRASTATUS_PATCH
#if BAR_TABGROUPS_PATCH
#if MONOCLE_LAYOUT
CONFIG_BAR_TABGROUPS_MONOCLE_CONSTS
#else
CONFIG_BAR_TABGROUPS_DEFAULT_CONSTS
#endif // MONOCLE_LAYOUT
#endif // BAR_TABGROUPS_PATCH
#if BAR_PANGO_PATCH
CONFIG_BAR_PANGO_CONSTS
#else
static const char *fonts[]               = { "monospace:size=10" };
#endif // BAR_PANGO_PATCH
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

#if BAR_LTSYMBOL_SCHEME_PATCH
CONFIG_BAR_LTSYMBOL_SCHEME_CONSTS
#endif // BAR_LTSYMBOL_SCHEME_PATCH

#if RENAMED_SCRATCHPADS_PATCH
CONFIG_RENAMED_SCRATCHPADS_CONSTS
#endif // RENAMED_SCRATCHPADS_PATCH

#if BAR_FLEXWINTITLE_PATCH
CONFIG_BAR_FLEXWINTITLE_CONSTS
#endif // BAR_FLEXWINTITLE_PATCH

#if BAR_ALPHA_PATCH
CONFIG_BAR_ALPHA_CONSTS
CONFIG_BAR_ALPHA_ARRAY
#endif // BAR_ALPHA_PATCH
#if BAR_VTCOLORS_PATCH
CONFIG_BAR_VTCOLORS_CONSTS
CONFIG_BAR_VTCOLORS_ARRAY
#endif // BAR_VTCOLORS_PATCH

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	#if BAR_LTSYMBOL_SCHEME_PATCH
        CONFIG_BAR_LTSYMBOL_SCHEME_COLORS
	#endif // BAR_LTSYMBOL_SCHEME_PATCH
	#if RENAMED_SCRATCHPADS_PATCH
        CONFIG_RENAMED_SCRATCHPADS_COLORS
	#endif // RENAMED_SCRATCHPADS_PATCH
	#if BAR_FLEXWINTITLE_PATCH
        CONFIG_BAR_FLEXWINTITLE_COLORS
	#endif // BAR_FLEXWINTITLE_PATCH
};

#if BAR_POWERLINE_STATUS_PATCH
CONFIG_BAR_POWERLINE_STATUS_ARRAY
#endif // BAR_POWERLINE_STATUS_PATCH

#if BAR_LAYOUTMENU_PATCH
CONFIG_BAR_LAYOUTMENU_CONSTS
#endif

#if BAR_LAUNCHER_PATCH
CONFIG_BAR_LAUNCHER_ARRAY
#endif // BAR_LAUNCHER_PATCH

#if COOL_AUTOSTART_PATCH
CONFIG_COOL_AUTOSTART_ARRAY
#endif // COOL_AUTOSTART_PATCH

#if RENAMED_SCRATCHPADS_PATCH
CONFIG_RENAMED_SCRATCHPADS_CMD
#elif SCRATCHPADS_PATCH
CONFIG_SCRATCHPADS_ARRAYS
#endif // SCRATCHPADS_PATCH

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
#if NAMETAG_PATCH
static char tagicons[][NUMTAGS][MAX_TAGLEN] =
#else
static char *tagicons[][NUMTAGS] =
#endif // NAMETAG_PATCH
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

#if BAR_TAGGRID_PATCH
CONFIG_BAR_TAGGRID_DEFS
CONFIG_BAR_TAGGRID_CONSTS
#endif // BAR_TAGGRID_PATCH

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	#if RENAMED_SCRATCHPADS_PATCH
        CONFIG_RENAMED_SCRATCHPADS_RULES
	#elif SCRATCHPADS_PATCH
        CONFIG_SCRATCHPADS_RULES
	#endif // SCRATCHPADS_PATCH
};

#if MONITOR_RULES_PATCH
#if PERTAG_PATCH
CONFIG_PERTAG_RULES
#else
CONFIG_MONITOR_RULES_RULES
#endif // PERTAG_PATCH
#endif // MONITOR_RULES_PATCH

#if INSETS_PATCH
CONFIG_INSETS_CONSTS
#endif // INSETS_PATCH

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	#if BAR_STATUSBUTTON_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
	#endif // BAR_STATUSBUTTON_PATCH
	#if BAR_LAUNCHER_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_launcher,           draw_launcher,          click_launcher,          NULL,                    "launcher" },
	#endif // BAR_LAUNCHER_PATCH
	#if BAR_POWERLINE_TAGS_PATCH
	{  0,        0,     BAR_ALIGN_LEFT,   width_pwrl_tags,          draw_pwrl_tags,         click_pwrl_tags,         hover_pwrl_tags,         "powerline_tags" },
	#endif // BAR_POWERLINE_TAGS_PATCH
	#if BAR_TAGS_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	#endif // BAR_TAGS_PATCH
	#if BAR_TAGLABELS_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_taglabels,          draw_taglabels,         click_taglabels,         hover_taglabels,         "taglabels" },
	#endif // BAR_TAGLABELS_PATCH
	#if BAR_TAGGRID_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_taggrid,            draw_taggrid,           click_taggrid,           NULL,                    "taggrid" },
	#endif // BAR_TAGGRID_PATCH
	#if BAR_SYSTRAY_PATCH
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	#endif // BAR_SYSTRAY_PATCH
	#if BAR_LTSYMBOL_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	#endif // BAR_LTSYMBOL_PATCH
	#if BAR_STATUSCOLORS_PATCH && BAR_STATUSCMD_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_statuscolors,       draw_statuscolors,      click_statuscmd,         NULL,                    "statuscolors" },
	#elif BAR_STATUSCOLORS_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_statuscolors,       draw_statuscolors,      click_statuscolors,      NULL,                    "statuscolors" },
	#elif BAR_STATUS2D_PATCH && BAR_STATUSCMD_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_statuscmd,         NULL,                    "status2d" },
	#elif BAR_STATUS2D_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	#elif BAR_POWERLINE_STATUS_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_pwrl_status,        draw_pwrl_status,       click_pwrl_status,       NULL,                    "powerline_status" },
	#elif BAR_STATUS_PATCH && BAR_STATUSCMD_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_statuscmd,         NULL,                    "status" },
	#elif BAR_STATUS_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	#endif // BAR_STATUS2D_PATCH | BAR_STATUSCMD_PATCH
	#if XKB_PATCH
	{  0,        0,     BAR_ALIGN_RIGHT,  width_xkb,                draw_xkb,               click_xkb,               NULL,                    "xkb" },
	#endif // XKB_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_flexwintitle,       draw_flexwintitle,      click_flexwintitle,      NULL,                    "flexwintitle" },
	#elif BAR_TABGROUPS_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_bartabgroups,       draw_bartabgroups,      click_bartabgroups,      NULL,                    "bartabgroups" },
	#elif BAR_AWESOMEBAR_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
	#elif BAR_FANCYBAR_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_fancybar,           draw_fancybar,          click_fancybar,          NULL,                    "fancybar" },
	#elif BAR_WINTITLE_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
	#endif // BAR_TABGROUPS_PATCH | BAR_AWESOMEBAR_PATCH | BAR_FANCYBAR_PATCH | BAR_WINTITLE_PATCH
	#if BAR_EXTRASTATUS_PATCH
	#if BAR_STATUSCOLORS_PATCH && BAR_STATUSCMD_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_statuscolors_es,    draw_statuscolors_es,   click_statuscmd_es,      NULL,                    "statuscolors_es" },
	#elif BAR_STATUSCOLORS_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_statuscolors_es,    draw_statuscolors_es,   click_statuscolors,      NULL,                    "statuscolors_es" },
	#elif BAR_STATUS2D_PATCH && BAR_STATUSCMD_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_status2d_es,        draw_status2d_es,       click_statuscmd_es,      NULL,                    "status2d_es" },
	#elif BAR_STATUS2D_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_status2d_es,        draw_status2d_es,       click_status2d,          NULL,                    "status2d_es" },
	#elif BAR_POWERLINE_STATUS_PATCH
	{ statusmon, 1,     BAR_ALIGN_RIGHT,  width_pwrl_status_es,     draw_pwrl_status_es,    click_pwrl_status,       NULL,                    "powerline_status" },
	#elif BAR_STATUSCMD_PATCH && BAR_STATUS_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_status_es,          draw_status_es,         click_statuscmd_es,      NULL,                    "status_es" },
	#elif BAR_STATUS_PATCH
	{ statusmon, 1,     BAR_ALIGN_CENTER, width_status_es,          draw_status_es,         click_status,            NULL,                    "status_es" },
	#endif // BAR_STATUS2D_PATCH | BAR_STATUSCMD_PATCH
	#endif // BAR_EXTRASTATUS_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	#if BAR_WINTITLE_HIDDEN_PATCH
	{ -1,        1,  BAR_ALIGN_RIGHT_RIGHT, width_wintitle_hidden,  draw_wintitle_hidden,   click_wintitle_hidden,   NULL,                    "wintitle_hidden" },
	#endif
	#if BAR_WINTITLE_FLOATING_PATCH
	{ -1,        1,     BAR_ALIGN_LEFT,   width_wintitle_floating,  draw_wintitle_floating, click_wintitle_floating, NULL,                    "wintitle_floating" },
	#endif // BAR_WINTITLE_FLOATING_PATCH
	#endif // BAR_FLEXWINTITLE_PATCH
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
#if FLEXTILE_DELUXE_LAYOUT
CONFIG_FLEXTILE_DELUXE_NSTACK_CONSTS
#endif // FLEXTILE_DELUXE_LAYOUT
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */
#if PLACEMOUSE_PATCH
CONFIG_PLACEMOUSE_CONSTS
#endif // PLACEMOUSE_PATCH
#if DRAGMFACT_PATCH
CONFIG_DRAGMFACT_CONSTS
#endif // DRAGMFACT_PATCH
#if DRAGCFACT_PATCH
CONFIG_DRAGCFACT_CONSTS
#endif // DRAGCFACT_PATCH
#if DECORATION_HINTS_PATCH
CONFIG_DECORATION_HINTS_CONSTS
#endif // DECORATION_HINTS_PATCH

#if NROWGRID_LAYOUT
CONFIG_NROWGRID_DEFS
#endif

#if TAPRESIZE_PATCH
/* mouse scroll resize */
CONFIG_TAPRESIZE_CONSTS
CONFIG_TAPRESIZE_ARRAY
#endif // TAPRESIZE_PATCH

#if FLEXTILE_DELUXE_LAYOUT
CONFIG_FLEXTILE_DELUXE_LAYOUTS_ARRAY
#else
static const Layout layouts[] = {
	/* symbol     arrange function */
	#if TILE_LAYOUT
	{ "[]=",      tile },    /* first entry is default */
	#endif
	{ "><>",      NULL },    /* no layout function means floating behavior */
	#if MONOCLE_LAYOUT
	{ "[M]",      monocle },
	#endif
	#if BSTACK_LAYOUT
	{ "TTT",      bstack },
	#endif
	#if BSTACKHORIZ_LAYOUT
	{ "===",      bstackhoriz },
	#endif
	#if CENTEREDMASTER_LAYOUT
	{ "|M|",      centeredmaster },
	#endif
	#if CENTEREDFLOATINGMASTER_LAYOUT
	{ ">M>",      centeredfloatingmaster },
	#endif
	#if COLUMNS_LAYOUT
	{ "|||",      col },
	#endif
	#if DECK_LAYOUT
	{ "[D]",      deck },
	#endif
	#if FIBONACCI_SPIRAL_LAYOUT
	{ "(@)",      spiral },
	#endif
	#if FIBONACCI_DWINDLE_LAYOUT
	{ "[\\]",     dwindle },
	#endif
	#if GRIDMODE_LAYOUT
	{ "HHH",      grid },
	#endif
	#if HORIZGRID_LAYOUT
	{ "---",      horizgrid },
	#endif
	#if GAPPLESSGRID_LAYOUT
	{ ":::",      gaplessgrid },
	#endif
	#if NROWGRID_LAYOUT
	{ "###",      nrowgrid },
	#endif
};
#endif // FLEXTILE_DELUXE_LAYOUT

#if XKB_PATCH
CONFIG_XKB_LAYOUTS_ARRAY
#endif // XKB_PATCH

/* key definitions */
#define MODKEY Mod1Mask
#if COMBO_PATCH && SWAPTAGS_PATCH && TAGOTHERMONITOR_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ControlMask,  KEY,      tagprevmon,     {.ui = 1 << TAG} },
#elif COMBO_PATCH && SWAPTAGS_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} },
#elif COMBO_PATCH && TAGOTHERMONITOR_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ControlMask,  KEY,      tagprevmon,     {.ui = 1 << TAG} },
#elif COMBO_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#elif SWAPTAGS_PATCH && TAGOTHERMONITOR_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ControlMask,  KEY,      tagprevmon,     {.ui = 1 << TAG} },
#elif SWAPTAGS_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} },
#elif TAGOTHERMONITOR_PATCH
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ControlMask,  KEY,      tagprevmon,     {.ui = 1 << TAG} },
#else
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#endif // COMBO_PATCH / SWAPTAGS_PATCH / TAGOTHERMONITOR_PATCH

#if STACKER_PATCH
CONFIG_STACKER_KEYS
#endif // STACKER_PATCH

#if BAR_HOLDBAR_PATCH
CONFIG_BAR_HOLDBAR_DEFS
#endif // BAR_HOLDBAR_PATCH

/* commands */
#if !NODMENU_PATCH
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
#endif // NODMENU_PATCH
static const char *dmenucmd[] = {
	"dmenu_run",
	#if !NODMENU_PATCH
	"-m", dmenumon,
	#endif // NODMENU_PATCH
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	#if BAR_DMENUMATCHTOP_PATCH
	topbar ? NULL : "-b",
	#endif // BAR_DMENUMATCHTOP_PATCH
	NULL
};
static const char *termcmd[]  = { "st", NULL };

#if BAR_STATUSCMD_PATCH
#if BAR_DWMBLOCKS_PATCH
CONFIG_BAR_STATUSCMD_DWMBLOCKS_DEFS
#else
CONFIG_BAR_STATUSCMD_ARRAY
#endif // BAR_DWMBLOCKS_PATCH
#endif // BAR_STATUSCMD_PATCH

#if ON_EMPTY_KEYS_PATCH
CONFIG_ON_EMPTY_KEYS_ARRAY
#endif // ON_EMPTY_KEYS_PATCH

#if XRESOURCES_PATCH
CONFIG_XRESOURCES_ARRAY
#endif // XRESOURCES_PATCH

static const Key keys[] = {
	/* modifier                     key            function                argument */
	#if KEYMODES_PATCH
	CONFIG_KEYMODES_ENTRY
	#endif // KEYMODES_PATCH
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	#if RIODRAW_PATCH
	CONFIG_RIODRAW_KEYS
	#endif // RIODRAW_PATCH
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	#if TOGGLETOPBAR_PATCH
	CONFIG_TOGGLETOPBAR_KEYS
	#endif // TOGGLETOPBAR_PATCH
	#if TAB_PATCH
	TAB_KEYS
	#endif // TAB_PATCH
	#if FOCUSMASTER_PATCH || FOCUSMASTER_RETURN_PATCH
	CONFIG_FOCUSMASTER_KEYS
	#endif // FOCUSMASTER_PATCH / FOCUSMASTER_RETURN_PATCH
	#if STACKER_PATCH
        CONFIG_STACKER_KEYS
	#else
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	#endif // STACKER_PATCH
	#if FOCUSDIR_PATCH
	CONFIG_FOCUSDIR_KEYS
	#endif // FOCUSDIR_PATCH
	#if PLACEDIR_PATCH
	CONFIG_PLACEDIR_KEYS
	#endif // PLACEDIR_PATCH
	#if SWAPFOCUS_PATCH && PERTAG_PATCH
	CONFIG_SWAPFOCUS_KEYS
	#endif // SWAPFOCUS_PATCH
	#if SWITCHCOL_PATCH
	CONFIG_SWITCHCOL_KEYS
	#endif // SWITCHCOL_PATCH
	#if ROTATESTACK_PATCH
	CONFIG_ROTATESTACK_KEYS
	#endif // ROTATESTACK_PATCH
	#if INPLACEROTATE_PATCH
	CONFIG_INPLACEROTATE_KEYS
	#endif // INPLACEROTATE_PATCH
	#if PUSH_PATCH || PUSH_NO_MASTER_PATCH
	CONFIG_PUSH_KEYS
	#endif // PUSH_PATCH / PUSH_NO_MASTER_PATCH
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	#if FLEXTILE_DELUXE_LAYOUT
	CONFIG_FLEXTILE_DELUXE_KEYS
	#endif // FLEXTILE_DELUXE_LAYOUT
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	#if CFACTS_PATCH
	CONFIG_CFACTS_KEYS
	#endif // CFACTS_PATCH
	#if ASPECTRESIZE_PATCH
	CONFIG_ASPECTRESIZE_KEYS
	#endif // ASPECTRESIZE_PATCH
	#if MOVERESIZE_PATCH
	CONFIG_MOVERESIZE_KEYS
	#endif // MOVERESIZE_PATCH
	#if MOVESTACK_PATCH
	CONFIG_MOVESTACK_KEYS
	#endif // MOVESTACK_PATCH
	#if TRANSFER_PATCH
	CONFIG_TRANSFER_KEYS
	#endif // TRANSFER_PATCH
	#if TRANSFER_ALL_PATCH
	CONFIG_TRANSFER_ALL_KEYS
	#endif // TRANSFER_ALL_PATCH
	#if REORGANIZETAGS_PATCH
	CONFIG_REORGANIZETAGS_KEYS
	#endif // REORGANIZETAGS_PATCH
	#if DISTRIBUTETAGS_PATCH
	CONFIG_DISTRIBUTETAGS_KEYS
	#endif // DISTRIBUTETAGS_PATCH
	#if INSETS_PATCH
	CONFIG_INSETS_KEYS
	#endif // INSETS_PATCH
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	#if VANITYGAPS_PATCH
	CONFIG_VANITYGAPS_KEYS
	#endif // VANITYGAPS_PATCH
	#if ALT_TAB_PATCH
	CONFIG_ALT_TAB_KEYS
	#else
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	#endif // ALT_TAB_PATCH
	#if SHIFTTAG_PATCH
	CONFIG_SHIFTTAG_KEYS
	#endif // SHIFTTAG_PATCH
	#if SHIFTTAGCLIENTS_PATCH
	CONFIG_SHIFTTAGCLIENTS_KEYS
	#endif // SHIFTTAGCLIENTS_PATCH
	#if SHIFTVIEW_PATCH
	CONFIG_SHIFTVIEW_KEYS
	#endif // SHIFTVIEW_PATCH
	#if SHIFTVIEW_CLIENTS_PATCH
	CONFIG_SHIFTVIEW_CLIENTS_KEYS
	#endif // SHIFTVIEW_CLIENTS_PATCH
	#if SHIFTBOTH_PATCH
	CONFIG_SHIFTBOTH_KEYS
	#endif // SHIFTBOTH_PATCH
	#if SHIFTSWAPTAGS_PATCH && SWAPTAGS_PATCH
	CONFIG_SHIFTSWAPTAGS_KEYS
	#endif // SHIFTSWAPTAGS_PATCH
	#if BAR_WINTITLEACTIONS_PATCH
	CONFIG_BAR_WINTITLEACTIONS_KEYS
	#endif // BAR_WINTITLEACTIONS_PATCH
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	#if KILLUNSEL_PATCH
	CONFIG_KILLUNSEL_KEYS
	#endif // KILLUNSEL_PATCH
	#if SELFRESTART_PATCH
	CONFIG_SELFRESTART_KEYS
	#endif // SELFRESTART_PATCH
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	#if RESTARTSIG_PATCH
	CONFIG_RESTARTSIG_KEYS
	#endif // RESTARTSIG_PATCH
	#if FOCUSURGENT_PATCH
	CONFIG_FOCUSURGENT_KEYS
	#endif // FOCUSURGENT_PATCH
	#if BAR_HOLDBAR_PATCH
	{ 0,                            HOLDKEY,       holdbar,                {0} },
	#endif // BAR_HOLDBAR_PATCH
	#if WINVIEW_PATCH
	CONFIG_WINVIEW_KEYS
	#endif // WINVIEW_PATCH
	#if XRDB_PATCH || XRESOURCES_PATCH
	XRDB_KEYS
	#endif // XRDB_PATCH | XRESOURCES_PATCH
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	#if COLUMNS_LAYOUT
	CONFIG_COLUMNS_LAYOUT_KEYS
	#endif // COLUMNS_LAYOUT
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	#if ALWAYSONTOP_PATCH
	CONFIG_ALWAYSONTOP_KEYS
	#endif // ALWAYSONTOP_PATCH
	#if MAXIMIZE_PATCH
	CONFIG_MAXIMIZE_KEYS
	#endif // MAXIMIZE_PATCH
	#if NO_MOD_BUTTONS_PATCH
	CONFIG_NO_MOD_BUTTONS_KEYS
	#endif // NO_MOD_BUTTONS_PATCH
	#if RENAMED_SCRATCHPADS_PATCH
	CONFIG_RENAMED_SCRATCHPADS_KEYS
	#elif SCRATCHPADS_PATCH
	CONFIG_SCRATCHPADS_KEYS
	#endif // SCRATCHPADS_PATCH | RENAMED_SCRATCHPADS_PATCH
	#if UNFLOATVISIBLE_PATCH
	CONFIG_UNFLOATVISIBLE_KEYS
	#endif // UNFLOATVISIBLE_PATCH
	#if TOGGLEFULLSCREEN_PATCH
	CONFIG_TOGGLEFULLSCREEN_KEYS
	#endif // TOGGLEFULLSCREEN_PATCH
	#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH
	CONFIG_FAKEFULLSCREEN_KEYS
	#endif // FAKEFULLSCREEN_CLIENT_PATCH
	#if FULLSCREEN_PATCH
	CONFIG_FULLSCREEN_KEYS
	#endif // FULLSCREEN_PATCH
	#if STICKY_PATCH
	CONFIG_STICKY_KEYS
	#endif // STICKY_PATCH
	#if SCRATCHPAD_ALT_1_PATCH
	CONFIG_SCRATCHPAD_ALT_1_KEYS
	#elif SCRATCHPADS_PATCH && !RENAMED_SCRATCHPADS_PATCH
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	#else
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	#endif // SCRATCHPAD_ALT_1_PATCH
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	#if FOCUSADJACENTTAG_PATCH
	CONFIG_FOCUSADJACENTTAG_KEYS
	#endif // FOCUSADJACENTTAG_PATCH
	#if TAGALL_PATCH
	CONFIG_TAGALL_KEYS
	#endif // TAGALL_PATCH
	#if TAGALLMON_PATCH
	CONFIG_TAGALLMON_KEYS
	#endif // TAGALLMON_PATCH
	#if TAGSWAPMON_PATCH
	CONFIG_TAGSWAPMON_KEYS
	#endif // TAGSWAPMON_PATCH
	#if BAR_ALTERNATIVE_TAGS_PATCH
	CONFIG_BAR_ALTERNATIVE_TAGS_KEYS
	#endif // BAR_ALTERNATIVE_TAGS_PATCH
	#if NAMETAG_PATCH
	CONFIG_NAMETAG_KEYS
	#endif // NAMETAG_PATCH
	#if BAR_TAGGRID_PATCH
	CONFIG_BAR_TAGGRID_KEYS
	#endif // BAR_TAGGRID_PATCH
	#if MOVECENTER_PATCH
	CONFIG_MOVECENTER_KEYS
	#endif // MOVECENTER_PATCH
	#if MOVEPLACE_PATCH
	CONFIG_MOVEPLACE_KEYS
	#endif // MOVEPLACE_PATCH
	#if EXRESIZE_PATCH
	CONFIG_EXRESIZE_KEYS
	#endif // EXRESIZE_PATCH
	#if FLOATPOS_PATCH
	CONFIG_FLOATPOS_KEYS
	#endif // FLOATPOS_PATCH
	#if SETBORDERPX_PATCH
	CONFIG_SETBORDERPX_KEYS
	#endif // SETBORDERPX_PATCH
	#if CYCLELAYOUTS_PATCH
	CONFIG_CYCLELAYOUTS_KEYS
	#endif // CYCLELAYOUTS_PATCH
	#if MPDCONTROL_PATCH
	CONFIG_MPDCONTROL_KEYS
	#endif // MPDCONTROL_PATCH
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

#if KEYMODES_PATCH
KEYMODES_CMDKEYS
KEYMODES_COMMANDS
#endif // KEYMODES_PATCH

/* button definitions */
#if STATUSBUTTON_PATCH
/* click can be ClkButton, ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
#else
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
#endif //
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	#if BAR_STATUSBUTTON_PATCH
	{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenucmd } },
	#endif // BAR_STATUSBUTTON_PATCH
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	#if BAR_LAYOUTMENU_PATCH
	{ ClkLtSymbol,          0,                   Button3,        layoutmenu,     {0} },
	#else
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	#endif // BAR_LAYOUTMENU_PATCH
	#if BAR_WINTITLEACTIONS_PATCH
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	#endif // BAR_WINTITLEACTIONS_PATCH
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	#if BAR_STATUSCMD_PATCH && BAR_DWMBLOCKS_PATCH
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	#elif BAR_STATUSCMD_PATCH
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button3,        spawn,          {.v = statuscmd } },
	#else
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	#endif // BAR_STATUSCMD_PATCH
	#if PLACEMOUSE_PATCH
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	#else
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	#endif // PLACEMOUSE_PATCH
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	#if TAPRESIZE_PATCH
	{ ClkClientWin,         MODKEY,              Button4,        resizemousescroll, {.v = &scrollargs[0]} },
	{ ClkClientWin,         MODKEY,              Button5,        resizemousescroll, {.v = &scrollargs[1]} },
	{ ClkClientWin,         MODKEY,              Button6,        resizemousescroll, {.v = &scrollargs[2]} },
	{ ClkClientWin,         MODKEY,              Button7,        resizemousescroll, {.v = &scrollargs[3]} },
	#endif // TAPRESIZE_PATCH
	#if DRAGCFACT_PATCH && CFACTS_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	#endif // DRAGCFACT_PATCH
	#if DRAGMFACT_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	#endif // DRAGMFACT_PATCH
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
	#if TAB_PATCH
	{ ClkTabBar,            0,                   Button1,        focuswin,       {0} },
	#endif // TAB_PATCH
};

#if DWMC_PATCH
CONFIG_DWMC_SIGNALS
#elif FSIGNAL_PATCH
CONFIG_FSIGNAL_SIGNALS
#endif // DWMC_PATCH

#if IPC_PATCH
CONFIG_IPC_IPCSOCKETPATH
CONFIG_IPC_IPCCOMMANDS
#endif // IPC_PATCH
