cmake_minimum_required(VERSION 3.16)
project(face_blur_gui_app)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    src/types
    src/image
    src/gui
)

add_executable(face_blur_gui_app
    src/main.cpp
    src/image/face_detection.cpp
    src/image/blur_faces.cpp
    src/image/file_utils.cpp
    src/gui/gui_window.cpp
)

target_link_libraries(face_blur_gui_app
    Qt6::Widgets
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
)
