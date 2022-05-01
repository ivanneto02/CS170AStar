CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	src/Board.cpp
	src/Queue.cpp
    src/Problem.cpp
    src/GameDriver.cpp
    src/HeuristicStrategy.cpp
	unit_test.cpp
)

ADD_EXECUTABLE(ASTar
    src/Board.cpp
    src/GameDriver.cpp
    src/Problem.cpp
    src/Queue.cpp
    src/HeuristicStrategy.cpp
    main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)