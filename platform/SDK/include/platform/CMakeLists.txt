##############################################################################
#Copyright 2012,TD-Tech. Co., Ltd.
#Filename: Itf - CMakeList.txt 
#Author:	WuGang
#Created: 2012/07/21 14:50
#Description: 
##############################################################################

##############################################################################
#                         source files                                       #
##############################################################################
set(PROTO_FILE_NAME "platform_msg.proto")
set(PROTO_FILE_FULL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE_NAME}")
set(CPP_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.cpp" targetCppFile ${PROTO_FILE_NAME})	
string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.cc" intermCcFile ${PROTO_FILE_NAME})	
string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.h" targetHFile ${PROTO_FILE_NAME})	

EXEC_PROGRAM(${Protobuf_EXECUTABLE_PROTOC} ARGS "-I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=dllexport_decl=PB_MSG_IMPORT_EXPORT:${CPP_OUT_DIR} ${PROTO_FILE_FULL_DIR}")
EXEC_PROGRAM(${CMAKE_COMMAND} ARGS "-E copy ${CMAKE_CURRENT_BINARY_DIR}/${intermCcFile}	${CMAKE_CURRENT_BINARY_DIR}/${targetCppFile}")
EXEC_PROGRAM(${CMAKE_COMMAND} ARGS "-E remove -f ${CMAKE_CURRENT_BINARY_DIR}/${intermCcFile}")

set(PROTO_FILE_NAME "sca_msg.proto")
set(PROTO_FILE_FULL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE_NAME}")
set(CPP_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.cpp" targetCppFile ${PROTO_FILE_NAME})	
string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.cc" intermCcFile ${PROTO_FILE_NAME})	
string(REGEX REPLACE "(.*)\\..*$" "\\1.pb.h" targetHFile ${PROTO_FILE_NAME})	

EXEC_PROGRAM(${Protobuf_EXECUTABLE_PROTOC} ARGS "-I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=dllexport_decl=PB_MSG_IMPORT_EXPORT:${CPP_OUT_DIR} ${PROTO_FILE_FULL_DIR}")
EXEC_PROGRAM(${CMAKE_COMMAND} ARGS "-E copy ${CMAKE_CURRENT_BINARY_DIR}/${intermCcFile}	${CMAKE_CURRENT_BINARY_DIR}/${targetCppFile}")
EXEC_PROGRAM(${CMAKE_COMMAND} ARGS "-E remove -f ${CMAKE_CURRENT_BINARY_DIR}/${intermCcFile}")