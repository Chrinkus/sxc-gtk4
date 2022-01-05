# Generate GLib resources
# Adapted from: https://stackoverflow.com/questions/63697778/how-to-use-glib-compile-resources-with-cmake

find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_OUT resources.c)
set(GRESOURCE_XML example_app.gresource.xml)

add_custom_command(
	OUTPUT			${GRESOURCE_OUT}
	WORKING_DIRECTORY	${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND			${GLIB_COMPILE_RESOURCES}
	ARGS
		${GRESOURCE_XML}
		--target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_OUT}
		--generate-source
	VERBATIM
	MAIN_DEPENDENCY		${GRESOURCE_XML}
	DEPENDS
		window.ui
		gears-menu.ui
		prefs.ui
)

execute_process(COMMAND glib-compile-schemas
				--targetdir=${CMAKE_BINARY_DIR}
				${CMAKE_CURRENT_SOURCE_DIR}
)

# Application target
add_executable(example-5
	main.c
	example_app.c
	example_app_win.c
	example_app_prefs.c
	${GRESOURCE_OUT}
)

target_link_libraries(example-5 PUBLIC ${GTK_LIBRARIES})

