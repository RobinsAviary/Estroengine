include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(Estroengine Estrocolors.cpp Estroengine.cpp Estrovector.cpp Estroimpl.cpp Estroassets.cpp)

target_link_libraries(Estroengine PRIVATE SFML::Graphics)