cmake_minimum_required(VERSION 3.16)

project(gtk-tuts VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)
include_directories(${GTK_INCLUDE_DIRS})

add_subdirectory(src)

# Since I run most stuff while in build dir
set(media_dirs
	"ui"
)

foreach(dir ${media_dirs})
	file(CREATE_LINK "${PROJECT_SOURCE_DIR}/${dir}"
		"${PROJECT_SOURCE_DIR}/build/${dir}" SYMBOLIC)
endforeach()

