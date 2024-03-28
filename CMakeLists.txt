cmake_minimum_required(VERSION 3.10)

project(filesystem-test)

add_executable(${PROJECT_NAME} main.cpp)

if(PLATFORM_PSP)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        pspdebug
        pspdisplay
        pspctrl
        pspge
    )
    create_pbp_file(
        TARGET ${PROJECT_NAME}
        ICON_PATH NULL
        BACKGROUND_PATH NULL
        PREVIEW_PATH NULL
        TITLE ${PROJECT_NAME}
    )
endif()