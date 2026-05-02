# Создаем библиотеку из lib.cpp
add_library(hairSalon hairSalon.cpp)
add_library(hairDresser hairDresser.cpp)
add_library(saveCSV saveCSV.cpp)

# Указываем, где искать заголовки для этой библиотеки
target_include_directories(hairSalon PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_include_directories(hairDresser PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_include_directories(saveCSV PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


# Создаем основной исполняемый файл
add_executable(hairSalonSimulation main.cpp)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries(hairSalon PRIVATE hairDresser)
target_link_libraries(hairSalonSimulation PRIVATE hairSalon)
target_link_libraries(hairSalonSimulation PRIVATE hairDresser)
target_link_libraries(hairSalonSimulation PRIVATE saveCSV)