#include <gtest/gtest.h>
#include <sstream>

#include "../src/unlambda.hpp"

using Unlambda::operator""_unl;

TEST(Unlambda, HelloWorld) {
  // Test case 1

  std::stringstream output;
  "`.!`.d`.l`.r`.o`.w`. `.,`.o`.l`.l`.e`.Hi"_unl.evaluate(output,
                                                          Unlambda::noInput);

  EXPECT_EQ(output.str(), "Hello World");
}
