cmake_minimum_required(VERSION 3.16)

project(mqtt_tutorial_cpp
  DESCRIPTION "examples to communicate with mqtt"
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set( PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include )

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(Mosquitto REQUIRED)

set(CLIENT_PUBLISHER_MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/client_publisher/main.cpp
  )

add_executable(mqtt_client_publisher)
target_sources(mqtt_client_publisher
 PRIVATE
    ${CLIENT_PUBLISHER_MAIN_SOURCES}
)
target_include_directories(mqtt_client_publisher SYSTEM
 PRIVATE
  include
  ${CMAKE_CURRENT_BINARY_DIR}
  ${MOSQUITTO_INCLUDE_DIR}
)
target_link_libraries(mqtt_client_publisher
 PRIVATE
  ${MOSQUITTO_LIBRARIES}
)

