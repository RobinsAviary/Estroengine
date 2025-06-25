set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(Estroengine
        src/Estrocolors.cpp
        src/Estroengine.cpp
        src/backends/SFML/Estroimpl.cpp
        src/backends/SFML/Estroassets.cpp
        src/Estroinput.cpp
        src/Estroextras.cpp
        include/Estroassets.h
        include/Estrocolors.h
        include/Estrodefs.h
        include/Estroengine.h
        include/Estroextras.h
        include/Estroimpl.h
        include/Estroinput.h
        include/Estrolist.h
        include/Estrotypes.h
        include/Estroframework.h
        src/backends/SFML/Estroframework.cpp
        include/Estronodes.h
        src/Estronodes.cpp
)

function(add_git_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
    target_compile_options(${libName} PRIVATE "-w")
endfunction()

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
add_git_dependency(
        box2d
        https://github.com/erincatto/box2d.git
        v3.1.1
)

target_link_libraries(Estroengine PRIVATE SFML::Graphics SFML::Audio)

target_link_libraries(Estroengine PRIVATE box2d)