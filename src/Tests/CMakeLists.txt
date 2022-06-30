set(DOCTEST_INCLUDE_DIR ../external)


add_executable (Test Tests.cpp ${game_src})
target_link_libraries(Test PUBLIC sfml-graphics sfml-audio sfml-window sfml-system)

doctest_discover_tests(Test "GameTests")