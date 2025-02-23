#include <gtest/gtest.h>
#include "Main.h"

int Runner(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
