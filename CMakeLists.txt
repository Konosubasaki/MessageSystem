cmake_minimum_required( VERSION 2.8 )
project(SandraDuricinFishlabs)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set( EXE_NAME test )
add_executable( ${EXE_NAME} MessageSystem.cpp main.cpp   )
install( TARGETS ${EXE_NAME} RUNTIME DESTINATION bin )

