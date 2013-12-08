cmake_minimum_required(VERSION 2.8.3)

project(mr_rqt)

MACRO (QT4_WRAP_UI2 outfiles )
  QT4_EXTRACT_OPTIONS(ui_files ui_options ${ARGN})

  FOREACH (it ${ui_files})
    GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
    GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
    SET(outfile ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/${outfile}.h) # Here we set output
    ADD_CUSTOM_COMMAND(OUTPUT ${outfile}
      COMMAND ${QT_UIC_EXECUTABLE}
      ARGS ${ui_options} -o ${outfile} ${infile}
      MAIN_DEPENDENCY ${infile})
    SET(${outfiles} ${${outfiles}} ${outfile})
  ENDFOREACH (it)

ENDMACRO (QT4_WRAP_UI2)


find_package(catkin REQUIRED COMPONENTS rqt_gui rqt_gui_cpp)
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)

include(${QT_USE_FILE})

set(rqt_image_view_SRCS
    src/mr_rqt/MrRqt.cpp
)

set(rqt_image_view_HDRS
    include/mr_rqt/MrRqt.h
    include/mr_rqt/VelocityWidget.h
    include/mr_rqt/KeyboardTeleop.h
)

set(rqt_image_view_UIS
    ui/MrmControllerUi.ui
)

set(rqt_image_view_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS ${rqt_image_view_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS rqt_gui rqt_gui_cpp
)

file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)

catkin_python_setup()

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_CPP(rqt_image_view_MOCS ${rqt_image_view_HDRS})
QT4_WRAP_UI2(rqt_image_view_UIS_H ${rqt_image_view_UIS})

include_directories(${rqt_image_view_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS})
add_library(${PROJECT_NAME} ${rqt_image_view_SRCS} ${rqt_image_view_MOCS} ${rqt_image_view_UIS_H} ${QT_RESOURCES_CPP})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

find_package(class_loader)
class_loader_hide_library_symbols(${PROJECT_NAME})

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

install(DIRECTORY resources
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# install(PROGRAMS scripts/rqt_marble
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
