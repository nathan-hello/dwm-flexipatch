/* See LICENSE file for copyright and license details. */
/* This file includes all patch configuration files */



/* Bar functionality */
#if BAR_ALPHA_PATCH
#include "bar_alpha.h"
#endif
#if BAR_ALTERNATIVE_TAGS_PATCH
#include "bar_alternativetags.h"
#endif
#if BAR_ANYBAR_PATCH
#include "bar_anybar.h"
#endif
#if BAR_HOLDBAR_PATCH
#include "bar_holdbar.h"
#endif
#if BAR_LAUNCHER_PATCH
#include "bar_launcher.h"
#endif
#if BAR_LTSYMBOL_PATCH
#include "bar_ltsymbol.h"
#endif
#if BAR_POWERLINE_STATUS_PATCH
#include "bar_powerline_status.h"
#endif
#if BAR_STATUSBUTTON_PATCH
#include "bar_statusbutton.h"
#endif
#if BAR_SYSTRAY_PATCH
#include "bar_systray.h"
#endif
#if BAR_TABGROUPS_PATCH
#include "bar_tabgroups.h"
#endif
#if BAR_TAGLABELS_PATCH
#include "bar_taglabels.h"
#endif
#if BAR_TAGPREVIEW_PATCH
#include "bar_tagpreview.h"
#endif
#if BAR_VTCOLORS_PATCH
#include "bar_vtcolors.h"
#endif
#if BAR_FLEXWINTITLE_PATCH
#include "bar_flexwintitle.h"
#endif
#if BAR_LAYOUTMENU_PATCH
#include "bar_layoutmenu.h"
#endif
#if BAR_WINTITLEACTIONS_PATCH
#include "bar_wintitleactions.h"
#endif

/* Other patches */
#if ALT_TAB_PATCH
#include "alttab.h"
#endif
#if ALWAYSONTOP_PATCH
#include "alwaysontop.h"
#endif
#if ASPECTRESIZE_PATCH
#include "aspectresize.h"
#endif
#if AUTOSTART_PATCH
#include "autostart.h"
#endif
#if BAR_BORDER_PATCH
#include "barborder.h"
#endif
#if BAR_HEIGHT_PATCH
#include "barheight.h"
#endif
#if CFACTS_PATCH
#include "cfacts.h"
#endif
#if COOL_AUTOSTART_PATCH
#include "cool_autostart.h"
#endif
#if CYCLELAYOUTS_PATCH
#include "cyclelayouts.h"
#endif
#if DECORATION_HINTS_PATCH
#include "decorationhints.h"
#endif
#if DISTRIBUTETAGS_PATCH
#include "distributetags.h"
#endif
#if DRAGCFACT_PATCH && CFACTS_PATCH
#include "dragcfact.h"
#endif
#if DRAGMFACT_PATCH
#include "dragmfact.h"
#endif
#if DWMC_PATCH
#include "dwmc.h"
#elif FSIGNAL_PATCH
#include "fsignal.h"
#endif
#if EXRESIZE_PATCH
#include "exresize.h"
#endif
#if BAR_STATUS_PATCH
#include "extrastatus.h"
#endif
#if !FAKEFULLSCREEN_PATCH && FAKEFULLSCREEN_CLIENT_PATCH
#include "fakefullscreenclient.h"
#endif
#if FLOATPOS_PATCH
#include "floatpos.h"
#endif
#if FOCUSADJACENTTAG_PATCH
#include "focusadjacenttag.h"
#endif
#if FOCUSDIR_PATCH
#include "focusdir.h"
#endif
#if FOCUSMASTER_PATCH || FOCUSMASTER_RETURN_PATCH
#include "focusmaster.h"
#endif
#if FOCUS_ON_CLICK_PATCH
#include "focusonclick.h"
#endif
#if FOCUSURGENT_PATCH
#include "focusurgent.h"
#endif
#if FULLSCREEN_PATCH
#include "fullscreen.h"
#endif
#if INPLACEROTATE_PATCH
#include "inplacerotate.h"
#endif
#if INSETS_PATCH
#include "insets.h"
#endif
#if IPC_PATCH
#include "ipc.h"
#endif
#if KEYMODES_PATCH
#include "keymodes.h"
#endif
#if KILLUNSEL_PATCH
#include "killunsel.h"
#endif
#if MAXIMIZE_PATCH
#include "maximize.h"
#endif
#if MPDCONTROL_PATCH
#include "mpdcontrol.h"
#endif
#if MOVECENTER_PATCH
#include "movecenter.h"
#endif
#if MOVEPLACE_PATCH
#include "moveplace.h"
#endif
#if MOVERESIZE_PATCH
#include "moveresize.h"
#endif
#if MOVESTACK_PATCH
#include "movestack.h"
#endif
#if MONITOR_RULES_PATCH
#include "monitorrules.h"
#endif
#if NAMETAG_PATCH
#include "nametag.h"
#endif
#if NO_MOD_BUTTONS_PATCH
#include "nomodbuttons.h"
#endif
#if ONE_EMPTY_KEYS_PATCH
#include "onemptykeys.h"
#endif
#if ONLY_QUIT_ON_EMPTY_PATCH
#include "onlyquitonempty.h"
#endif
#if BAR_PADDING_PATCH
#include "padding.h"
#endif
#if PANGO_PATCH
#include "pango.h"
#endif
#if PLACEDIR_PATCH
#include "placedir.h"
#endif
#if PLACEMOUSE_PATCH
#include "placemouse.h"
#endif
#if PUSH_NO_MASTER_PATCH
#include "push.h"
#elif PUSH_PATCH
#include "push.h"
#endif
#if RENAMED_SCRATCHPADS_PATCH
#include "renamed_scratchpads.h"
#endif
#if REORGANIZETAGS_PATCH
#include "reorganizetags.h"
#endif
#if RESTARTSIG_PATCH
#include "restartsig.h"
#endif
#if RIODRAW_PATCH
#include "riodraw.h"
#endif
#if ROTATESTACK_PATCH
#include "rotatestack.h"
#endif
#if ROUNDED_CORNERS_PATCH
#include "roundedcorners.h"
#endif
#if SCRATCHPADS_PATCH
#include "scratchpad.h"
#endif
#if SCRATCHPAD_ALT_1_PATCH
#include "scratchpad_alt_1.h"
#endif
#if SELFRESTART_PATCH
#include "selfrestart.h"
#endif
#if SETBORDERPX_PATCH
#include "setborderpx.h"
#endif
#if SHIFTBOTH_PATCH || SHIFTSWAPTAGS_PATCH || SHIFTTAG_PATCH || SHIFTTAGCLIENTS_PATCH || SHIFTVIEW_PATCH || SHIFTVIEW_CLIENTS_PATCH
#include "shiftboth.h"
#endif
#if SHIFTSWAPTAGS_PATCH && SWAPTAGS_PATCH
#include "shiftswaptags.h"
#endif
#if SHIFTTAG_PATCH
#include "shifttag.h"
#endif
#if SHIFTTAGCLIENTS_PATCH
#include "shifttagclients.h"
#endif
#if SHIFTVIEW_PATCH
#include "shiftview.h"
#endif
#if SHIFTVIEW_CLIENTS_PATCH
#include "shiftviewclients.h"
#endif
#if STACKER_PATCH
#include "stacker.h"
#endif
#if STATUS_ALL_MONITORS_PATCH
#include "statusallmons.h"
#endif
#if BAR_STATUSCMD_PATCH
#include "statuscmd.h"
#endif
#if STATUS_PADDING_PATCH
#include "statuspadding.h"
#endif
#if STICKY_PATCH
#include "sticky.h"
#endif
#if SWALLOW_PATCH
#include "swallow.h"
#endif
#if SWAPFOCUS_PATCH && PERTAG_PATCH
#include "swapfocus.h"
#endif
#if SWITCHCOL_PATCH
#include "switchcol.h"
#endif
#if TAB_PATCH
#include "tab.h"
#endif
#if TAGALL_PATCH
#include "tagall.h"
#endif
#if TAGALLMON_PATCH
#include "tagallmon.h"
#endif
#if TAG_GRID_PATCH
#include "taggrid.h"
#endif
#if TAGSWAPMON_PATCH
#include "tagswapmon.h"
#endif
#if TAPRESIZE_PATCH
#include "tapresize.h"
#endif
#if TOGGLEFULLSCREEN_PATCH
#include "togglefullscreen.h"
#endif
#if TOGGLETOPBAR_PATCH
#include "toggletopbar.h"
#endif
#if TRANSFER_PATCH
#include "transfer.h"
#endif
#if TRANSFER_ALL_PATCH
#include "transferall.h"
#endif
#if UNDERLINE_TAGS_PATCH
#include "underlinetags.h"
#endif
#if UNFLOATVISIBLE_PATCH
#include "unfloatvisible.h"
#endif
#if VANITYGAPS_PATCH
#include "vanitygaps.h"
#endif
#if WINVIEW_PATCH
#include "winview.h"
#endif
#if XKB_PATCH
#include "xkb.h"
#endif
#if XRESOURCES_PATCH
#include "xresources.h"
#elif XRDB_PATCH
#include "xrdb.h"
#endif

/* Layouts */
#if COLUMNS_LAYOUT
#include "layout_columns.h"
#endif
#if FLEXTILE_DELUXE_LAYOUT
#include "layout_flextile-deluxe.h"
#endif
#if NROWGRID_LAYOUT
#include "layout_nrowgrid.h"
#endif
