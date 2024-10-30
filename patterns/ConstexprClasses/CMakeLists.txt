project(usefulcxx)

add_executable(ConstexprClasses ConstexprClasses.cc)

install(TARGETS ConstexprClasses RUNTIME DESTINATION "${BIN_DIR}/patterns")
