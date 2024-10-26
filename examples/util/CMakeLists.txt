project(usefulcxx)

add_executable(ResultExample ResultExample.cc)

install(TARGETS ResultExample RUNTIME DESTINATION "${BIN_DIR}/examples")
