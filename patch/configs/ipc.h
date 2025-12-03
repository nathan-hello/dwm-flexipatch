#define CONFIG_IPC_IPCSOCKETPATH \
static const char *ipcsockpath = "/tmp/dwm.sock";
#define CONFIG_IPC_IPCCOMMANDS \
static IPCCommand ipccommands[] = {                              \
	IPCCOMMAND( focusmon, 1, {ARG_TYPE_SINT} ),              \
	IPCCOMMAND( focusstack, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( incnmaster, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( killclient, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( quit, 1, {ARG_TYPE_NONE} ),                  \
	IPCCOMMAND( setlayoutsafe, 1, {ARG_TYPE_PTR} ),          \
	IPCCOMMAND( setmfact, 1, {ARG_TYPE_FLOAT} ),             \
	IPCCOMMAND( setstatus, 1, {ARG_TYPE_STR} ),              \
	IPCCOMMAND( tag, 1, {ARG_TYPE_UINT} ),                   \
	IPCCOMMAND( tagmon, 1, {ARG_TYPE_UINT} ),                \
	IPCCOMMAND( togglebar, 1, {ARG_TYPE_NONE} ),             \
#if TOGGLETOPBAR_PATCH                                   \
	IPCCOMMAND( toggletopbar, 1, {ARG_TYPE_NONE} ),          \
#endif /* TOGGLETOPBAR_PATCH */                          \
	IPCCOMMAND( togglefloating, 1, {ARG_TYPE_NONE} ),        \
	IPCCOMMAND( toggletag, 1, {ARG_TYPE_UINT} ),             \
	IPCCOMMAND( toggleview, 1, {ARG_TYPE_UINT} ),            \
	IPCCOMMAND( view, 1, {ARG_TYPE_UINT} ),                  \
	IPCCOMMAND( zoom, 1, {ARG_TYPE_NONE} ),                  \
#if BAR_ALTERNATIVE_TAGS_PATCH                           \
	IPCCOMMAND( togglealttag, 1, {ARG_TYPE_NONE} ),          \
#endif /* BAR_ALTERNATIVE_TAGS_PATCH */                  \
#if BAR_TAGGRID_PATCH                                    \
	IPCCOMMAND( switchtag, 1, {ARG_TYPE_UINT} ),             \
#endif /* BAR_TAGGRID_PATCH */                           \
#if CFACTS_PATCH                                         \
	IPCCOMMAND( setcfact, 1, {ARG_TYPE_FLOAT} ),             \
#endif /* CFACTS_PATCH */                                \
#if CYCLELAYOUTS_PATCH                                   \
	IPCCOMMAND( cyclelayout, 1, {ARG_TYPE_SINT} ),           \
#endif /* CYCLELAYOUTS_PATCH */                          \
#if EXRESIZE_PATCH                                       \
	IPCCOMMAND( explace, 1, {ARG_TYPE_UINT} ),               \
	IPCCOMMAND( togglehorizontalexpand, 1, {ARG_TYPE_SINT} ),\
	IPCCOMMAND( toggleverticalexpand, 1, {ARG_TYPE_SINT} ),  \
	IPCCOMMAND( togglemaximize, 1, {ARG_TYPE_SINT} ),        \
#endif /* EXRESIZE_PATCH */                              \
#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH \
	IPCCOMMAND( togglefakefullscreen, 1, {ARG_TYPE_NONE} ),  \
#endif /* FAKEFULLSCREEN_CLIENT_PATCH */                 \
#if FLOATPOS_PATCH                                       \
	IPCCOMMAND( floatpos, 1, {ARG_TYPE_STR} ),               \
#endif /* FLOATPOS_PATCH */                              \
#if FULLSCREEN_PATCH                                     \
	IPCCOMMAND( fullscreen, 1, {ARG_TYPE_NONE} ),            \
#endif /* FULLSCREEN_PATCH */                            \
#if FLEXTILE_DELUXE_LAYOUT                               \
	IPCCOMMAND( incnstack, 1, {ARG_TYPE_SINT} ),             \
	IPCCOMMAND( rotatelayoutaxis, 1, {ARG_TYPE_SINT} ),      \
	IPCCOMMAND( setlayoutaxisex, 1, {ARG_TYPE_SINT} ),       \
	IPCCOMMAND( mirrorlayout, 1, {ARG_TYPE_NONE} ),          \
#endif /* FLEXTILE_DELUXE_LAYOUT */                      \
#if FOCUSURGENT_PATCH                                    \
	IPCCOMMAND( focusurgent, 1, {ARG_TYPE_NONE} ),           \
#endif /* FOCUSURGENT_PATCH */                           \
#if FOCUSADJACENTTAG_PATCH                               \
	IPCCOMMAND( viewtoleft, 1, {ARG_TYPE_NONE} ),            \
	IPCCOMMAND( viewtoright, 1, {ARG_TYPE_NONE} ),           \
	IPCCOMMAND( tagtoleft, 1, {ARG_TYPE_NONE} ),             \
	IPCCOMMAND( tagtoright, 1, {ARG_TYPE_NONE} ),            \
	IPCCOMMAND( tagandviewtoleft, 1, {ARG_TYPE_NONE} ),      \
	IPCCOMMAND( tagandviewtoright, 1, {ARG_TYPE_NONE} ),     \
#endif /* FOCUSADJACENTTAG_PATCH */                      \
#if INPLACEROTATE_PATCH                                  \
	IPCCOMMAND( inplacerotate, 1, {ARG_TYPE_SINT} ),         \
#endif /* INPLACEROTATE_PATCH */                         \
#if KEYMODES_PATCH                                       \
	IPCCOMMAND( setkeymode, 1, {ARG_TYPE_UINT} ),            \
#endif /* KEYMODES_PATCH */                              \
#if MAXIMIZE_PATCH                                       \
	IPCCOMMAND( togglehorizontalmax, 1, {ARG_TYPE_NONE} ),   \
	IPCCOMMAND( toggleverticalmax, 1, {ARG_TYPE_NONE} ),     \
	IPCCOMMAND( togglemax, 1, {ARG_TYPE_NONE} ),             \
#endif /* MAXIMIZE_PATCH */                              \
#if MPDCONTROL_PATCH                                     \
	IPCCOMMAND( mpdchange, 1, {ARG_TYPE_SINT} ),             \
	IPCCOMMAND( mpdcontrol, 1, {ARG_TYPE_NONE} ),            \
#endif /* MPDCONTROL_PATCH */                            \
#if MOVECENTER_PATCH                                     \
	IPCCOMMAND( movecenter, 1, {ARG_TYPE_NONE} ),            \
#endif /* MOVECENTER_PATCH */                            \
#if MOVEPLACE_PATCH                                      \
	IPCCOMMAND( moveplace, 1, {ARG_TYPE_UINT} ),             \
#endif /* MOVEPLACE_PATCH */                             \
#if MOVERESIZE_PATCH                                     \
	IPCCOMMAND( moveresize, 1, {ARG_TYPE_STR} ),             \
#endif /* MOVERESIZE_PATCH */                            \
#if NAMETAG_PATCH                                        \
	IPCCOMMAND( nametag, 1, {ARG_TYPE_NONE} ),               \
#endif /* NAMETAG_PATCH */                               \
#if RIODRAW_PATCH                                        \
	IPCCOMMAND( rioresize, 1, {ARG_TYPE_NONE} ),             \
#endif /* RIODRAW_PATCH */                               \
#if PUSH_PATCH || PUSH_NO_MASTER_PATCH                   \
	IPCCOMMAND( pushdown, 1, {ARG_TYPE_NONE} ),              \
	IPCCOMMAND( pushup, 1, {ARG_TYPE_NONE} ),                \
#endif /* PUSH_PATCH / PUSH_NO_MASTER_PATCH */           \
#if ROTATESTACK_PATCH                                    \
	IPCCOMMAND( rotatestack, 1, {ARG_TYPE_SINT} ),           \
#endif /* ROTATESTACK_PATCH */                           \
#if SCRATCHPADS_PATCH && !RENAMED_SCRATCHPADS_PATCH      \
	IPCCOMMAND( togglescratch, 1, {ARG_TYPE_UINT} ),         \
#endif /* SCRATCHPADS_PATCH */                           \
#if SELFRESTART_PATCH                                    \
	IPCCOMMAND( self_restart, 1, {ARG_TYPE_NONE} ),          \
#endif /* SELFRESTART_PATCH */                           \
#if SETBORDERPX_PATCH                                    \
	IPCCOMMAND( setborderpx, 1, {ARG_TYPE_SINT} ),           \
#endif /* SETBORDERPX_PATCH */                           \
#if BAR_WINTITLEACTIONS_PATCH                            \
	IPCCOMMAND( showhideclient, 1, {ARG_TYPE_NONE} ),        \
#endif /* BAR_WINTITLEACTIONS_PATCH */                   \
#if SHIFTBOTH_PATCH                                      \
	IPCCOMMAND( shiftboth, 1, {ARG_TYPE_SINT} ),             \
#endif /* SHIFTBOTH_PATCH */                             \
#if SHIFTTAG_PATCH                                       \
	IPCCOMMAND( shifttag, 1, {ARG_TYPE_SINT} ),              \
#endif /* SHIFTTAG_PATCH */                              \
#if SHIFTTAGCLIENTS_PATCH                                \
	IPCCOMMAND( shifttagclients, 1, {ARG_TYPE_SINT} ),       \
#endif /* SHIFTVIEWCLIENTS_PATCH */                      \
#if SHIFTVIEW_PATCH                                      \
	IPCCOMMAND( shiftview, 1, {ARG_TYPE_SINT} ),             \
#endif /* SHIFTVIEW_PATCH */                             \
#if SHIFTVIEW_CLIENTS_PATCH                              \
	IPCCOMMAND( shiftviewclients, 1, {ARG_TYPE_SINT} ),      \
#endif /* SHIFTVIEW_CLIENTS_PATCH */                     \
#if SHIFTSWAPTAGS_PATCH && SWAPTAGS_PATCH                \
	IPCCOMMAND( shiftswaptags, 1, {ARG_TYPE_SINT} ),         \
#endif /* SHIFTSWAPTAGS_PATCH */                         \
#if STACKER_PATCH                                        \
	IPCCOMMAND( pushstack, 1, {ARG_TYPE_SINT} ),             \
#endif /* STACKER_PATCH */                               \
#if STICKY_PATCH                                         \
	IPCCOMMAND( togglesticky, 1, {ARG_TYPE_NONE} ),          \
#endif /* STICKY_PATCH */                                \
#if SWAPFOCUS_PATCH && PERTAG_PATCH                      \
	IPCCOMMAND( swapfocus, 1, {ARG_TYPE_SINT} ),             \
#endif /* SWAPFOCUS_PATCH */                             \
#if SWITCHCOL_PATCH                                      \
	IPCCOMMAND( switchcol, 1, {ARG_TYPE_NONE} ),             \
#endif /* SWITCHCOL_PATCH */                             \
#if TAGALLMON_PATCH                                      \
	IPCCOMMAND( tagallmon, 1, {ARG_TYPE_SINT} ),             \
#endif /* TAGALLMON_PATCH */                             \
#if TAGOTHERMONITOR_PATCH                                \
	IPCCOMMAND( tagnextmonex, 1, {ARG_TYPE_UINT} ),          \
	IPCCOMMAND( tagprevmonex, 1, {ARG_TYPE_UINT} ),          \
#endif /* TAGOTHERMONITOR_PATCH */                       \
#if TAGSWAPMON_PATCH                                     \
	IPCCOMMAND( tagswapmon, 1, {ARG_TYPE_SINT} ),            \
#endif /* TAGSWAPMON_PATCH */                            \
#if TOGGLEFULLSCREEN_PATCH                               \
	IPCCOMMAND( togglefullscreen, 1, {ARG_TYPE_NONE} ),      \
#endif /* TOGGLEFULLSCREEN_PATCH */                      \
#if TRANSFER_PATCH                                       \
	IPCCOMMAND( transfer, 1, {ARG_TYPE_NONE} ),              \
#endif /* TRANSFER_PATCH */                              \
#if TRANSFER_ALL_PATCH                                   \
	IPCCOMMAND( transferall, 1, {ARG_TYPE_NONE} ),           \
#endif /* TRANSFER_ALL_PATCH */                          \
#if UNFLOATVISIBLE_PATCH                                 \
	IPCCOMMAND( unfloatvisible, 1, {ARG_TYPE_NONE} ),        \
#endif /* UNFLOATVISIBLE_PATCH */                        \
#if VANITYGAPS_PATCH                                     \
	IPCCOMMAND( incrgaps, 1, {ARG_TYPE_SINT} ),              \
	IPCCOMMAND( incrigaps, 1, {ARG_TYPE_SINT} ),             \
	IPCCOMMAND( incrogaps, 1, {ARG_TYPE_SINT} ),             \
	IPCCOMMAND( incrihgaps, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( incrivgaps, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( incrohgaps, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( incrovgaps, 1, {ARG_TYPE_SINT} ),            \
	IPCCOMMAND( togglegaps, 1, {ARG_TYPE_NONE} ),            \
	IPCCOMMAND( defaultgaps, 1, {ARG_TYPE_NONE} ),           \
	IPCCOMMAND( setgapsex, 1, {ARG_TYPE_SINT} ),             \
#endif /* VANITYGAPS_PATCH */                            \
#if WINVIEW_PATCH                                        \
	IPCCOMMAND( winview, 1, {ARG_TYPE_NONE} ),               \
#endif /* WINVIEW_PATCH */                               \
#if XRDB_PATCH || XRESOURCES_PATCH                       \
	IPCCOMMAND( xrdb, 1, {ARG_TYPE_NONE} ),                  \
#endif /* XRDB_PATCH | XRESOURCES_PATCH */               \
};
