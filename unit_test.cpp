#include "gtest/gtest.h"

#include "tests/testtest.hpp"
#include "tests/queueTests.hpp"
#include "tests/boardTestConstructors.hpp"
#include "tests/boardTestSetStage.hpp"
#include "tests/boardTestDraw.hpp"
#include "tests/boardTestClear.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}