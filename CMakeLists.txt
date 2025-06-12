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
        src/Estrotypes.cpp
        src/backends/SFML/Estroimpl-SFML.cpp
        src/backends/SFML/Estroassets-SFML.cpp
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
)

target_link_libraries(Estroengine PRIVATE SFML::Graphics SFML::Audio)