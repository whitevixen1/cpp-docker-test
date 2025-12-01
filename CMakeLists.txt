cmake_minimum_required(VERSION 3.10)

# プロジェクト名と使用する言語
project(MyCppApp LANGUAGES CXX)

# C++ 標準を指定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# メインアプリケーション
add_executable(myapp src/main.cpp)

# GoogleTest を利用したテスト設定
enable_testing()

# テスト用の実行ファイル
add_executable(test_sample tests/test_sample.cpp)
add_executable(test1 tests/test1.cpp)
add_executable(test2 tests/test2.cpp)
add_executable(test3 tests/test3.cpp)

# GoogleTest ライブラリをリンク
find_package(GTest REQUIRED)
target_link_libraries(test_sample GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test1 GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test2 GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test3 GTest::gtest GTest::gtest_main pthread)

#テスト登録
add_test(NAME sample_test COMMAND test_sample)
add_test(NAME test1 COMMAND test1)
add_test(NAME test2 COMMAND test2)
add_test(NAME test3 COMMAND test3)
