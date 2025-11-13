#define DWMC_SIGNALS \
/* signal definitions */  \
/* signum must be greater than 0 */  \
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */  \
static const Signal signals[] = {                                          \
	/* signum                    function */                           \
	{ "focusstack",              focusstack },                         \
	{ "setmfact",                setmfact },                           \
	{ "togglebar",               togglebar },                          \
	#if TOGGLETOPBAR_PATCH                                             \
	{ "toggletopbar",            toggletopbar },                       \
	#endif /* TOGGLETOPBAR_PATCH */                                    \
	{ "incnmaster",              incnmaster },                         \
	{ "togglefloating",          togglefloating },                     \
	{ "focusmon",                focusmon },                           \
	#if STACKER_PATCH                                                  \
	{ "pushstack",               pushstack },                          \
	#endif /* STACKER_PATCH */                                         \
	#if FLOATPOS_PATCH                                                 \
	{ "floatpos",                floatpos },                           \
	#endif /* FLOATPOS_PATCH */                                        \
	#if FOCUSURGENT_PATCH                                              \
	{ "focusurgent",             focusurgent },                        \
	#endif /* FOCUSURGENT_PATCH */                                     \
	#if FOCUSADJACENTTAG_PATCH                                         \
	{ "viewtoleft",              viewtoleft },                         \
	{ "viewtoright",             viewtoright },                        \
	{ "tagtoleft",               tagtoleft },                          \
	{ "tagtoright",              tagtoright},                          \
	{ "tagandviewtoleft",        tagandviewtoleft },                   \
	{ "tagandviewtoright",       tagandviewtoright },                  \
	#endif /* FOCUSADJACENTTAG_PATCH */                                \
	#if SWAPFOCUS_PATCH && PERTAG_PATCH                                \
	{ "swapfocus",               swapfocus },                          \
	#endif /* SWAPFOCUS_PATCH */                                       \
	#if SWITCHCOL_PATCH                                                \
	{ "switchcol",               switchcol },                          \
	#endif /* SWITCHCOL_PATCH */                                       \
	#if ROTATESTACK_PATCH                                              \
	{ "rotatestack",             rotatestack },                        \
	#endif /* ROTATESTACK_PATCH */                                     \
	#if INPLACEROTATE_PATCH                                            \
	{ "inplacerotate",           inplacerotate },                      \
	#endif /* INPLACEROTATE_PATCH */                                   \
	#if PUSH_PATCH || PUSH_NO_MASTER_PATCH                             \
	{ "pushdown",                pushdown },                           \
	{ "pushup",                  pushup },                             \
	#endif /* PUSH_PATCH / PUSH_NO_MASTER_PATCH  */                    \
	#if FLEXTILE_DELUXE_LAYOUT                                         \
	{ "incnstack",               incnstack },                          \
	{ "rotatelayoutaxis",        rotatelayoutaxis },                   \
	{ "setlayoutaxisex",         setlayoutaxisex },                    \
	{ "mirrorlayout",            mirrorlayout },                       \
	#endif /* FLEXTILE_DELUXE_LAYOUT */                                \
	#if CFACTS_PATCH                                                   \
	{ "setcfact",                setcfact },                           \
	#endif /* CFACTS_PATCH */                                          \
	#if MOVECENTER_PATCH                                               \
	{ "movecenter",              movecenter },                         \
	#endif /* MOVECENTER_PATCH */                                      \
	#if MOVEPLACE_PATCH                                                \
	{ "moveplace",               moveplace },                          \
	#endif /* MOVEPLACE_PATCH */                                       \
	#if NAMETAG_PATCH                                                  \
	{ "nametag",                 nametag },                            \
	#endif /* NAMETAG_PATCH */                                         \
	#if EXRESIZE_PATCH                                                 \
	{ "explace",                 explace },                            \
	{ "togglehorizontalexpand",  togglehorizontalexpand },             \
	{ "toggleverticalexpand",    toggleverticalexpand },               \
	{ "togglemaximize",          togglemaximize },                     \
	#endif /* EXRESIZE_PATCH */                                        \
	#if KEYMODES_PATCH                                                 \
	{ "setkeymode",              setkeymode },                         \
	#endif /* KEYMODES_PATCH */                                        \
	#if TRANSFER_PATCH                                                 \
	{ "transfer",                transfer },                           \
	#endif /* TRANSFER_PATCH */                                        \
	#if TRANSFER_ALL_PATCH                                             \
	{ "transferall",             transferall },                        \
	#endif /* TRANSFER_ALL_PATCH */                                    \
	{ "tagmon",                  tagmon },                             \
	{ "zoom",                    zoom },                               \
	#if VANITYGAPS_PATCH                                               \
	{ "incrgaps",                incrgaps },                           \
	{ "incrigaps",               incrigaps },                          \
	{ "incrogaps",               incrogaps },                          \
	{ "incrihgaps",              incrihgaps },                         \
	{ "incrivgaps",              incrivgaps },                         \
	{ "incrohgaps",              incrohgaps },                         \
	{ "incrovgaps",              incrovgaps },                         \
	{ "togglegaps",              togglegaps },                         \
	{ "defaultgaps",             defaultgaps },                        \
	{ "setgaps",                 setgapsex },                          \
	#endif /* VANITYGAPS_PATCH */                                      \
	{ "view",                    view },                               \
	{ "viewall",                 viewallex },                          \
	{ "viewex",                  viewex },                             \
	{ "toggleview",              toggleview },                         \
	#if BAR_WINTITLEACTIONS_PATCH                                      \
	{ "showhideclient",          showhideclient },                     \
	#endif /* BAR_WINTITLEACTIONS_PATCH */                             \
	#if SHIFTBOTH_PATCH                                                \
	{ "shiftboth",               shiftboth },                          \
	#endif /* SHIFTBOTH_PATCH */                                       \
	#if SHIFTTAG_PATCH                                                 \
	{ "shifttag",                shifttag },                           \
	#endif /* SHIFTTAG_PATCH */                                        \
	#if SHIFTTAGCLIENTS_PATCH                                          \
	{ "shifttagclients",         shifttagclients },                    \
	#endif /* SHIFTTAGCLIENTS_PATCH */                                 \
	#if SHIFTVIEW_PATCH                                                \
	{ "shiftview",               shiftview },                          \
	#endif /* SHIFTVIEW_PATCH */                                       \
	#if SHIFTVIEW_CLIENTS_PATCH                                        \
	{ "shiftviewclients",        shiftviewclients },                   \
	#endif /* SHIFTVIEW_CLIENTS_PATCH */                               \
	#if SHIFTSWAPTAGS_PATCH && SWAPTAGS_PATCH                          \
	{ "shiftswaptags",           shiftswaptags },                      \
	#endif /* SHIFTSWAPTAGS_PATCH */                                   \
	#if SELFRESTART_PATCH                                              \
	{ "self_restart",            self_restart },                       \
	#endif /* SELFRESTART_PATCH */                                     \
	#if BAR_TAGGRID_PATCH                                              \
	{ "switchtag",               switchtag },                          \
	#endif /* BAR_TAGGRID_PATCH */                                     \
	#if STICKY_PATCH                                                   \
	{ "togglesticky",            togglesticky },                       \
	#endif /* STICKY_PATCH */                                          \
	#if SETBORDERPX_PATCH                                              \
	{ "setborderpx",             setborderpx },                        \
	#endif /* SETBORDERPX_PATCH */                                     \
	#if CYCLELAYOUTS_PATCH                                             \
	{ "cyclelayout",             cyclelayout },                        \
	#endif /* CYCLELAYOUTS_PATCH */                                    \
	#if MPDCONTROL_PATCH                                               \
	{ "mpdchange",               mpdchange },                          \
	{ "mpdcontrol",              mpdcontrol },                         \
	#endif /* MPDCONTROL_PATCH */                                      \
	{ "toggleviewex",            toggleviewex },                       \
	{ "tag",                     tag },                                \
	{ "tagall",                  tagallex },                           \
	{ "tagex",                   tagex },                              \
	{ "toggletag",               toggletag },                          \
	{ "toggletagex",             toggletagex },                        \
	#if TAGALLMON_PATCH                                                \
	{ "tagallmon",               tagallmon },                          \
	#endif /* TAGALLMON_PATCH */                                       \
	#if TAGSWAPMON_PATCH                                               \
	{ "tagswapmon",              tagswapmon},                          \
	#endif /* TAGSWAPMON_PATCH */                                      \
	#if BAR_ALTERNATIVE_TAGS_PATCH                                     \
	{ "togglealttag",            togglealttag },                       \
	#endif /* BAR_ALTERNATIVE_TAGS_PATCH */                            \
	#if TOGGLEFULLSCREEN_PATCH                                         \
	{ "togglefullscreen",        togglefullscreen },                   \
	#endif /* TOGGLEFULLSCREEN_PATCH */                                \
	#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH           \
	{ "togglefakefullscreen",    togglefakefullscreen },               \
	#endif /* FAKEFULLSCREEN_CLIENT_PATCH */                           \
	#if FULLSCREEN_PATCH                                               \
	{ "fullscreen",              fullscreen },                         \
	#endif /* FULLSCREEN_PATCH */                                      \
	#if MAXIMIZE_PATCH                                                 \
	{ "togglehorizontalmax",     togglehorizontalmax },                \
	{ "toggleverticalmax",       toggleverticalmax },                  \
	{ "togglemax",               togglemax },                          \
	#endif /* MAXIMIZE_PATCH */                                        \
	#if SCRATCHPADS_PATCH && !RENAMED_SCRATCHPADS_PATCH                \
	{ "togglescratch",           togglescratch },                      \
	#endif /* SCRATCHPADS_PATCH */                                     \
	#if UNFLOATVISIBLE_PATCH                                           \
	{ "unfloatvisible",          unfloatvisible },                     \
	#endif /* UNFLOATVISIBLE_PATCH */                                  \
	{ "killclient",              killclient },                         \
	#if WINVIEW_PATCH                                                  \
	{ "winview",                 winview },                            \
	#endif /* WINVIEW_PATCH */                                         \
	#if XRDB_PATCH || XRESOURCES_PATCH                                 \
	{ "xrdb",                    xrdb },                               \
	#endif /* XRDB_PATCH | XRESOURCES_PATCH */                         \
	#if TAGOTHERMONITOR_PATCH                                          \
	{ "tagnextmonex",            tagnextmonex },                       \
	{ "tagprevmonex",            tagprevmonex },                       \
	#endif /* TAGOTHERMONITOR_PATCH */                                 \
	{ "quit",                    quit },                               \
	{ "setlayout",               setlayout },                          \
	{ "setlayoutex",             setlayoutex },                        \
};
