#include "gtest/gtest.h"


TEST (DummyTest, firstone) {
  EXPECT_EQ (18.0, 19.0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
