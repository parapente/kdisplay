project(kdisplay)

find_package(KDE4 REQUIRED)
find_package(EasyRandR REQUIRED)

include (KDE4Defaults)

include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} ${ERR_INCLUDE_DIRS} )

#add_subdirectory( doc )
add_subdirectory( src )
add_subdirectory( icons )
