add_executable(
	trunk
	main.cxx
)

#install(FILES RUNTIME DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

target_include_directories(
	trunk
	PUBLIC
		argparse::argparse
		fmt::fmt-header-only
)

target_link_libraries(
	trunk
	argparse::argparse
	fmt::fmt-header-only
)

install(TARGETS trunk RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

