set(DOCTEST_INCLUDE_DIR ../external)


add_executable (Test Tests.cpp ${game_src})
target_link_libraries(Test PUBLIC ${SFML_LINK_LIBRARIES})
target_include_directories(Test PUBLIC ${SFML_INCLUDE_DIRS})
target_include_directories(Test PUBLIC /usr/local/include)

doctest_discover_tests(Test "GameTests")