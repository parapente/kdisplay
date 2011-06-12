set(kdisplay_SRCS
   kdpygraphicsview.cpp
   kdpyoutputgraphicsgroup.cpp
   kdpyoutputwidget.cpp
   kdpymainwidget.cpp
   kdisplay.cpp
   main.cpp
 )

kde4_add_ui_files(kdisplay_SRCS details.ui)

kde4_add_executable(kdisplay ${kdisplay_SRCS})

target_link_libraries(kdisplay ${KDE4_KDEUI_LIBS} ${ERR_LIBRARIES})

install(TARGETS kdisplay ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### install files ###############

install( PROGRAMS kdisplay.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES kdisplay.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
