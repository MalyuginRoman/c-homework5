cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(gr_editor VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

add_executable(gr_editor_cli main.cpp)
add_library(gr_editor_lib lib.cpp)
set_target_properties(gr_editor_cli gr_editor_lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(gr_editor_lib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(gr_editor_cli PRIVATE
    gr_editor_lib
)

if (MSVC)
    target_compile_options(gr_editor_cli PRIVATE
        /W4
    )
    target_compile_options(gr_editor_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(gr_editor_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(gr_editor_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS gr_editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)