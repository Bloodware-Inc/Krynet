cmake_minimum_required(VERSION 3.18)
project(krynet LANGUAGES CXX)

# Force modern C++17 optimizations without standard library bloat extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Direct target definition
add_library(krynet SHARED app/src/main/cpp/main.cpp)

# Production Performance & Size Optimizations
set_target_properties(krynet PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    POSITION_INDEPENDENT_CODE ON
)

target_compile_options(krynet PRIVATE
    -O3                             # Peak performance optimization
    -flto                           # Link-Time Optimization (interprocedural analysis)
    -fomit-frame-pointer            # Frees up a register for performance
    -fvisibility=hidden             # Strips unnecessary symbols to shrink binary size
    -fdata-sections -ffunction-sections # Prepares dead code for stripping
)

target_link_options(krynet PRIVATE
    -Wl,--gc-sections               # Dead code elimination (strips unused Sciter functions)
    -Wl,--icf=all                   # Identical Code Folding (merges duplicate functions)
    -Wl,-s                          # Strip all symbols/debug details completely
)

# Minimal target scoping
target_include_directories(krynet PRIVATE app/sciter/include)

# Fast direct linking (Minimal tracking overhead)
target_link_libraries(krynet PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app/sciter/libsciter-android.a
    log
    android
)
