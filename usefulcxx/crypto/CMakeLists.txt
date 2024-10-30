project(usefulcxx)

add_library(usefulcxx_crypto Util.cc Base64.cc)

install(TARGETS usefulcxx_crypto RUNTIME DESTINATION "${LIB_DIR}")
