# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "k21_controller: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ik21_controller:/home/rizky/k21_robocon2022/src/k21_controller/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(k21_controller_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_custom_target(_k21_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "k21_controller" "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" ""
)

get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_custom_target(_k21_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "k21_controller" "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/k21_controller
)
_generate_msg_cpp(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/k21_controller
)

### Generating Services

### Generating Module File
_generate_module_cpp(k21_controller
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/k21_controller
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(k21_controller_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(k21_controller_generate_messages k21_controller_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_cpp _k21_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_cpp _k21_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(k21_controller_gencpp)
add_dependencies(k21_controller_gencpp k21_controller_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS k21_controller_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/k21_controller
)
_generate_msg_eus(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/k21_controller
)

### Generating Services

### Generating Module File
_generate_module_eus(k21_controller
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/k21_controller
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(k21_controller_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(k21_controller_generate_messages k21_controller_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_eus _k21_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_eus _k21_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(k21_controller_geneus)
add_dependencies(k21_controller_geneus k21_controller_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS k21_controller_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/k21_controller
)
_generate_msg_lisp(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/k21_controller
)

### Generating Services

### Generating Module File
_generate_module_lisp(k21_controller
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/k21_controller
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(k21_controller_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(k21_controller_generate_messages k21_controller_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_lisp _k21_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_lisp _k21_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(k21_controller_genlisp)
add_dependencies(k21_controller_genlisp k21_controller_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS k21_controller_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/k21_controller
)
_generate_msg_nodejs(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/k21_controller
)

### Generating Services

### Generating Module File
_generate_module_nodejs(k21_controller
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/k21_controller
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(k21_controller_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(k21_controller_generate_messages k21_controller_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_nodejs _k21_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_nodejs _k21_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(k21_controller_gennodejs)
add_dependencies(k21_controller_gennodejs k21_controller_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS k21_controller_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller
)
_generate_msg_py(k21_controller
  "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller
)

### Generating Services

### Generating Module File
_generate_module_py(k21_controller
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(k21_controller_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(k21_controller_generate_messages k21_controller_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/VelCmd.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_py _k21_controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rizky/k21_robocon2022/src/k21_controller/msg/Gripper.msg" NAME_WE)
add_dependencies(k21_controller_generate_messages_py _k21_controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(k21_controller_genpy)
add_dependencies(k21_controller_genpy k21_controller_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS k21_controller_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/k21_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/k21_controller
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(k21_controller_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(k21_controller_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/k21_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/k21_controller
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(k21_controller_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(k21_controller_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/k21_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/k21_controller
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(k21_controller_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(k21_controller_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/k21_controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/k21_controller
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(k21_controller_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(k21_controller_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/k21_controller
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(k21_controller_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(k21_controller_generate_messages_py geometry_msgs_generate_messages_py)
endif()
