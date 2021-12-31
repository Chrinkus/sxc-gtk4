set(tutorial_sources
	"example-0.c"
	"example-1.c"
	"example-2.c"
	"example-3.c"
	"example-4.c"
)

foreach(file ${tutorial_sources})
	get_filename_component(exe_name ${file} NAME_WE)
	add_executable(${exe_name} ${file})
	target_link_libraries(${exe_name} PRIVATE ${GTK_LIBRARIES})
endforeach()

add_subdirectory(example-5)

