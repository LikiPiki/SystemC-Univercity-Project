include_directories(${CMAKE_CURRENT_LIST_DIR})

# .cpp files to include
set( SRC
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/gyroscope.cpp
    ${CMAKE_CURRENT_LIST_DIR}/switch.cpp
    ${CMAKE_CURRENT_LIST_DIR}/engine.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cpu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/gelio.cpp
    ${CMAKE_CURRENT_LIST_DIR}/antenna.cpp
    ${CMAKE_CURRENT_LIST_DIR}/camera.cpp
    ${CMAKE_CURRENT_LIST_DIR}/logger.cpp)
