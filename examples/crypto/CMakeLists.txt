project(usefulcxx)

add_executable(base64_example base64_example.cc)
target_link_libraries(base64_example usefulcxx_crypto)
target_link_libraries(base64_example crypto)

install(TARGETS base64_example RUNTIME DESTINATION "${BIN_DIR}/examples")
