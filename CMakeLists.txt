cmake_minimum_required(VERSION 3.15)
project(workbuddy CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(frontend)
add_executable(${PROJECT_NAME} main.cpp ${RESOURCES})
qt5_use_modules(${PROJECT_NAME} Quick)

get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${WINDEPLOYQT_EXECUTABLE} --qmldir "${CMAKE_CURRENT_LIST_DIR}/frontend/qml" --verbose 2 ${CMAKE_BINARY_DIR})