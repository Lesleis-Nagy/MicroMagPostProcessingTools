qt_add_executable(qt-vtk-ex001
        MainWindow.ui
        MainWindow.cpp
        main.cpp
)

target_link_libraries(qt-vtk-ex001
        PRIVATE Qt6::Core
                ${VTK_LIBRARIES}
)

target_include_directories(qt-vtk-ex001
        PUBLIC ${VTK_INCLUDE_DIRS}
)
