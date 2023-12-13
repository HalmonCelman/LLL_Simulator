cmake_minimum_required(VERSION 3.25.0)

project(llls VERSION 1.0)

set(llls_INCLUDE_DIRECTORIES
LLL/
.
)

add_subdirectory(LLL)

add_executable(${PROJECT_NAME} ${lllc_SOURCE_FILES} main.cpp driver.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${llls_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} lll)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
