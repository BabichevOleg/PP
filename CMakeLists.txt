cmake_minimum_required(VERSION 3.5)

project(lab1)

find_package(Python COMPONENTS NumPy REQUIRED)

file(GLOB PYTHON_SCRIPTS "*.py")
 


if(MSVC)
  add_executable(lab1 main.cpp)
  target_compile_definitions(lab1 PUBLIC _DEBUG)
  target_compile_options(lab1 PUBLIC /MDd)
else()
  add_executable(lab1 main.cpp)
  target_compile_definitions(lab1 PUBLIC -D_DEBUG)
endif()

#add_custom_target(run_check_script
#  COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/check.py
#  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#)

#add_dependencies(lab1 run_check_script)

target_link_libraries(lab1 ${Python_LIBRARIES})

add_executable(lab1py ${PYTHON_SCRIPTS})

set_target_properties(lab1py PROPERTIES LINKER_LANGUAGE Python)
