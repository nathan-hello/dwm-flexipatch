#define BAR_VTCOLORS_CONSTS \
	static const char title_bg_dark[]   = "#303030"; \
	static const char title_bg_light[]  = "#fdfdfd";
#define BAR_VTCOLORS_ARRAY \
	static const int color_ptrs[][ColCount] = { \
		/*                       fg      bg      border  float */ \
		[SchemeNorm]         = { -1,     -1,     5,      12 }, \
		[SchemeSel]          = { -1,     -1,     11,     13 }, \
		[SchemeTitleNorm]    = { 6,      -1,     -1,     -1 }, \
		[SchemeTitleSel]     = { 6,      -1,     -1,     -1 }, \
		[SchemeTagsNorm]     = { 2,      0,      0,      -1 }, \
		[SchemeTagsSel]      = { 6,      5,      5,      -1 }, \
		[SchemeHidNorm]      = { 5,      0,      0,      -1 }, \
		[SchemeHidSel]       = { 6,      -1,     -1,     -1 }, \
		[SchemeUrg]          = { 7,      9,      9,      15 }, \
		[SchemeLtSymbol]     = { -1,     3,      0,       0 }, \
	};
