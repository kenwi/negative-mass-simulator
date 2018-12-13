cmake_minimum_required(VERSION 3.12)
project(mass_simulator)

set(CMAKE_CXX_FLAGS  "-lstdc++fs")
set(CMAKE_CXX_STANDARD 17)

add_executable(mass_simulator main.cpp Simulator.cpp Simulator.h Setup.cpp Setup.h Export.cpp Export.h)

# HDF5
set(HDF5_min_ver 1.10.0.1)
find_package(HDF5 ${HDF5_min_ver})

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/HighFive/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/xtensor-io/include
                    /usr/include/hdf5/serial)

# HighFive
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/HighFive)

# Boost
set(boost_min_ver 1.50.0)
set(boost_libs system filesystem)
find_package(Boost ${boost_min_ver})

if(Boost_FOUND)
    find_package(Boost ${boost_min_ver} COMPONENTS ${boost_libs})
endif()

target_link_libraries(mass_simulator ${Boost_LIBRARIES} ${HDF5_LIBRARIES})
