#define CONFIG_XRESOURCES_ARRAY \
	/* \
	* Xresources preferences to load at startup. \
	* \
	*     Name                      Type       Address \
	*    ------------------------------------------------ \
	*     "nmaster"                 INTEGER    &nmaster \
	*     "mfact"                   FLOAT      &mfact \
	*     "color1"                  STRING     &color1 \
	* \
	* In the Xresources file setting resources shoud be prefixed with "dwm.", e.g. \
	* \
	*    dwm.nmaster: 1 \
	*    dwm.mfact: 0.50 \
	*    dwm.color1: #FA6EFA \
	* \
	* Note that the const qualifier must be removed from the variables if you plan on \
	* overriding them with values from Xresources. While resources can be reloaded \
	* using the xrdb function some changes may only take effect following a restart. \
	*/ \
	ResourcePref resources[] = { \
		/* Resource name            Type       Address                */ \
		{ "normfgcolor",            STRING,    &normfgcolor }, \
		{ "normbgcolor",            STRING,    &normbgcolor }, \
		{ "normbordercolor",        STRING,    &normbordercolor }, \
		{ "normfloatcolor",         STRING,    &normfloatcolor }, \
		{ "selfgcolor",             STRING,    &selfgcolor }, \
		{ "selbgcolor",             STRING,    &selbgcolor }, \
		{ "selbordercolor",         STRING,    &selbordercolor }, \
		{ "selfloatcolor",          STRING,    &selfloatcolor }, \
		{ "titlenormfgcolor",       STRING,    &titlenormfgcolor }, \
		{ "titlenormbgcolor",       STRING,    &titlenormbgcolor }, \
		{ "titlenormbordercolor",   STRING,    &titlenormbordercolor }, \
		{ "titlenormfloatcolor",    STRING,    &titlenormfloatcolor }, \
		{ "titleselfgcolor",        STRING,    &titleselfgcolor }, \
		{ "titleselbgcolor",        STRING,    &titleselbgcolor }, \
		{ "titleselbordercolor",    STRING,    &titleselbordercolor }, \
		{ "titleselfloatcolor",     STRING,    &titleselfloatcolor }, \
		{ "tagsnormfgcolor",        STRING,    &tagsnormfgcolor }, \
		{ "tagsnormbgcolor",        STRING,    &tagsnormbgcolor }, \
		{ "tagsnormbordercolor",    STRING,    &tagsnormbordercolor }, \
		{ "tagsnormfloatcolor",     STRING,    &tagsnormfloatcolor }, \
		{ "tagsselfgcolor",         STRING,    &tagsselfgcolor }, \
		{ "tagsselbgcolor",         STRING,    &tagsselbgcolor }, \
		{ "tagsselbordercolor",     STRING,    &tagsselbordercolor }, \
		{ "tagsselfloatcolor",      STRING,    &tagsselfloatcolor }, \
		{ "hidnormfgcolor",         STRING,    &hidnormfgcolor }, \
		{ "hidnormbgcolor",         STRING,    &hidnormbgcolor }, \
		{ "hidselfgcolor",          STRING,    &hidselfgcolor }, \
		{ "hidselbgcolor",          STRING,    &hidselbgcolor }, \
		{ "urgfgcolor",             STRING,    &urgfgcolor }, \
		{ "urgbgcolor",             STRING,    &urgbgcolor }, \
		{ "urgbordercolor",         STRING,    &urgbordercolor }, \
		{ "urgfloatcolor",          STRING,    &urgfloatcolor }, \
		#if RENAMED_SCRATCHPADS_PATCH \
		{ "scratchselfgcolor",      STRING,    &scratchselfgcolor }, \
		{ "scratchselbgcolor",      STRING,    &scratchselbgcolor }, \
		{ "scratchselbordercolor",  STRING,    &scratchselbordercolor }, \
		{ "scratchselfloatcolor",   STRING,    &scratchselfloatcolor }, \
		{ "scratchnormfgcolor",     STRING,    &scratchnormfgcolor }, \
		{ "scratchnormbgcolor",     STRING,    &scratchnormbgcolor }, \
		{ "scratchnormbordercolor", STRING,    &scratchnormbordercolor }, \
		{ "scratchnormfloatcolor",  STRING,    &scratchnormfloatcolor }, \
		#endif /* RENAMED_SCRATCHPADS_PATCH */ \
		#if BAR_FLEXWINTITLE_PATCH \
		{ "normTTBbgcolor",         STRING,    &normTTBbgcolor }, \
		{ "normLTRbgcolor",         STRING,    &normLTRbgcolor }, \
		{ "normMONObgcolor",        STRING,    &normMONObgcolor }, \
		{ "normGRIDbgcolor",        STRING,    &normGRIDbgcolor }, \
		{ "normGRD1bgcolor",        STRING,    &normGRD1bgcolor }, \
		{ "normGRD2bgcolor",        STRING,    &normGRD2bgcolor }, \
		{ "normGRDMbgcolor",        STRING,    &normGRDMbgcolor }, \
		{ "normHGRDbgcolor",        STRING,    &normHGRDbgcolor }, \
		{ "normDWDLbgcolor",        STRING,    &normDWDLbgcolor }, \
		{ "normSPRLbgcolor",        STRING,    &normSPRLbgcolor }, \
		{ "normfloatbgcolor",       STRING,    &normfloatbgcolor }, \
		{ "actTTBbgcolor",          STRING,    &actTTBbgcolor }, \
		{ "actLTRbgcolor",          STRING,    &actLTRbgcolor }, \
		{ "actMONObgcolor",         STRING,    &actMONObgcolor }, \
		{ "actGRIDbgcolor",         STRING,    &actGRIDbgcolor }, \
		{ "actGRD1bgcolor",         STRING,    &actGRD1bgcolor }, \
		{ "actGRD2bgcolor",         STRING,    &actGRD2bgcolor }, \
		{ "actGRDMbgcolor",         STRING,    &actGRDMbgcolor }, \
		{ "actHGRDbgcolor",         STRING,    &actHGRDbgcolor }, \
		{ "actDWDLbgcolor",         STRING,    &actDWDLbgcolor }, \
		{ "actSPRLbgcolor",         STRING,    &actSPRLbgcolor }, \
		{ "actfloatbgcolor",        STRING,    &actfloatbgcolor }, \
		{ "selTTBbgcolor",          STRING,    &selTTBbgcolor }, \
		{ "selLTRbgcolor",          STRING,    &selLTRbgcolor }, \
		{ "selMONObgcolor",         STRING,    &selMONObgcolor }, \
		{ "selGRIDbgcolor",         STRING,    &selGRIDbgcolor }, \
		{ "selGRD1bgcolor",         STRING,    &selGRD1bgcolor }, \
		{ "selGRD2bgcolor",         STRING,    &selGRD2bgcolor }, \
		{ "selGRDMbgcolor",         STRING,    &selGRDMbgcolor }, \
		{ "selHGRDbgcolor",         STRING,    &selHGRDbgcolor }, \
		{ "selDWDLbgcolor",         STRING,    &selDWDLbgcolor }, \
		{ "selSPRLbgcolor",         STRING,    &selSPRLbgcolor }, \
		{ "selfloatbgcolor",        STRING,    &selfloatbgcolor }, \
		#endif /* BAR_FLEXWINTITLE_PATCH */ \
		#if BAR_LTSYMBOL_SCHEME_PATCH \
		{ "ltsymbolfgcolor",        STRING,    &ltsymbolfgcolor }, \
		{ "ltsymbolbgcolor",        STRING,    &ltsymbolbgcolor }, \
		#endif /* BAR_LTSYMBOL_SCHEME_PATCH */ \
	};
