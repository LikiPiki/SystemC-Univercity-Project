include_directories(${CMAKE_CURRENT_LIST_DIR})

# .cpp files to include
set( SRC
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/switch.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cpu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/helper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/antenna.cpp
    ${CMAKE_CURRENT_LIST_DIR}/control_center.cpp
    ${CMAKE_CURRENT_LIST_DIR}/channel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/gelio.cpp )
