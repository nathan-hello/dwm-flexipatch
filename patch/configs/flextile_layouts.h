#define FLEXTILE_DELUXE_LAYOUTS_ARRAY \
	static const Layout layouts[] = { \
		/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */ \
		{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, /* default tile layout */ \
	 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */ \
		{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, /* monocle */ \
		{ "|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, /* columns (col) layout */ \
		{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, /* floating master */ \
		{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, /* deck */ \
		{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, /* bstack */ \
		{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, /* bstackhoriz */ \
		{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, /* centeredmaster */ \
		{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, /* centeredmaster horiz */ \
		{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, /* gappless grid */ \
		{ "[\\\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, /* fibonacci dwindle */ \
		{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, /* fibonacci spiral */ \
		{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, /* tatami mats */ \
		#if TILE_LAYOUT \
		{ "[]=",      tile,             {0} }, \
		#endif \
		#if MONOCLE_LAYOUT \
		{ "[M]",      monocle,          {0} }, \
		#endif \
		#if BSTACK_LAYOUT \
		{ "TTT",      bstack,           {0} }, \
		#endif \
		#if BSTACKHORIZ_LAYOUT \
		{ "===",      bstackhoriz,      {0} }, \
		#endif \
		#if CENTEREDMASTER_LAYOUT \
		{ "|M|",      centeredmaster,   {0} }, \
		#endif \
		#if CENTEREDFLOATINGMASTER_LAYOUT \
		{ ">M>",      centeredfloatingmaster, {0} }, \
		#endif \
		#if COLUMNS_LAYOUT \
		{ "|||",      col,              {0} }, \
		#endif \
		#if DECK_LAYOUT \
		{ "[D]",      deck,             {0} }, \
		#endif \
		#if FIBONACCI_SPIRAL_LAYOUT \
		{ "(@)",      spiral,           {0} }, \
		#endif \
		#if FIBONACCI_DWINDLE_LAYOUT \
		{ "[\\\\]",     dwindle,          {0} }, \
		#endif \
		#if GRIDMODE_LAYOUT \
		{ "HHH",      grid,             {0} }, \
		#endif \
		#if HORIZGRID_LAYOUT \
		{ "---",      horizgrid,        {0} }, \
		#endif \
		#if GAPPLESSGRID_LAYOUT \
		{ ":::",      gaplessgrid,      {0} }, \
		#endif \
		#if NROWGRID_LAYOUT \
		{ "###",      nrowgrid,         {0} }, \
		#endif \
	};
