include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(
  test_hello
  test_hello.cpp
)
target_link_libraries(
  test_hello
  GTest::gtest_main
  ODBC_Wrapper
)
include(GoogleTest)
gtest_discover_tests(test_hello)
