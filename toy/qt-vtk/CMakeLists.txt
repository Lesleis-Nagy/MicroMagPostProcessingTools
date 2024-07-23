qt_add_executable(qt-vtk
        MainWindow.ui
        MainWindow.cpp
        main.cpp
)

target_link_libraries(qt-vtk
        PRIVATE Qt6::Core
                ${VTK_LIBRARIES}
)

target_include_directories(qt-vtk
        PUBLIC ${VTK_INCLUDE_DIRS}
)
