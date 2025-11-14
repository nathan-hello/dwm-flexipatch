#define CONFIG_BAR_POWERLINE_STATUS_ARRAY \
	static char *statuscolors[][ColCount] = { \
		/*                       fg                bg                border                float */ \
		[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor }, \
		[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor }, \
		[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor }, \
		[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor }, \
		[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor }, \
		[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor }, \
		[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 }, \
		[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 }, \
		[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor }, \
	};
