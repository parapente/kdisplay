set(kdisplay_SRCS
   kdisplay.cpp
   main.cpp
   kdisplayview.cpp
 )

kde4_add_ui_files(kdisplay_SRCS kdisplayview_base.ui prefs_base.ui)

kde4_add_kcfg_files(kdisplay_SRCS settings.kcfgc )

kde4_add_executable(kdisplay ${kdisplay_SRCS})

target_link_libraries(kdisplay ${KDE4_KDEUI_LIBS} )

install(TARGETS kdisplay ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### install files ###############

install( PROGRAMS kdisplay.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES kdisplay.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
install( FILES kdisplayui.rc  DESTINATION  ${DATA_INSTALL_DIR}/kdisplay )
