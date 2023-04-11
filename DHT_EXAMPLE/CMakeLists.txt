cmake_minimum_required(VERSION 3.5)

# Set the name of your project
project(DHT11_Code)

# Use the ESP32 PICO SDK
set(EXTRA_COMPONENT_DIRS "components")

# Add the main executable
add_executable(${PROJECT_NAME}
    "DHT11_Code.c"
)

# Add the DHT11 component
add_subdirectory("components/esp32-DHT11")

# Include the DHT11 header files
target_include_directories(${PROJECT_NAME} PUBLIC
    "components/esp32-DHT11/include"
)

# Link the DHT11 library
target_link_libraries(${PROJECT_NAME} PUBLIC
    esp32-DHT11
)

# Set the target to use C++11
set(CMAKE_CXX_STANDARD 11)

# Print the size of the binary after it's built
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} ARGS --format=berkeley $<TARGET_FILE:${PROJECT_NAME}>
)
