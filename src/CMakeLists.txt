add_executable(
	trunk
	main.cxx
)

#install(FILES RUNTIME DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

target_include_directories(
	trunk
	PUBLIC
		argparse::argparse
)

target_link_libraries(
	trunk
	argparse::argparse
)

install(TARGETS trunk RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

