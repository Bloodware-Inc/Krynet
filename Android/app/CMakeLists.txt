cmake_minimum_required(VERSION 3.18) # Bumped for better modern Android NDK support

project(krynet VERSION 1.0.0 LANGUAGES CXX)

# Force modern CMake standards and prevention of decay to older standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the shared library target
add_library(krynet SHARED
    app/src/main/cpp/main.cpp
)

# --- Compiler Flags & Optimizations ---
# Hide symbols by default for better performance and smaller binary size (security best practice)
set_target_properties(krynet PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

target_compile_options(krynet PRIVATE
    -Wall -Wextra -Wpedantic # Strict warnings
    $<$<CONFIG:Release>:-O3 -flto> # Enable aggressive optimization & Link-Time Optimization in Release
)

if(NOT ANDROID)
    message(FATAL_ERROR "This CMakeLists.txt is tailored strictly for the Android NDK platform.")
endif()

# --- Include Directories (Modern Target-Based Scoping) ---
target_include_directories(krynet PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app/sciter/include
)

# --- Imported Prebuilt Libraries ---
# Instead of linking raw paths, we define the static prebuilt library properly
add_library(sciter_android STATIC IMPORTED)
set_target_properties(sciter_android PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/app/sciter/libsciter-android.a"
)

# --- Link Libraries ---
target_link_libraries(krynet PRIVATE
    sciter_android
    log
    android
)
