add_executable(example-5
	main.c
	example_app.c
	example_app_win.c
	resources.c
)
target_link_libraries(example-5 PUBLIC ${GTK_LIBRARIES})

