#define BAR_TABGROUPS_MONOCLE_CONSTS \
	static void (*bartabmonfns[])(Monitor *) = { monocle /* , customlayoutfn */ };
#define BAR_TABGROUPS_DEFAULT_CONSTS \
	static void (*bartabmonfns[])(Monitor *) = { NULL /* , customlayoutfn */ };
