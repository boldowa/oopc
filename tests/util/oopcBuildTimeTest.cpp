#include "CppUTest/TestHarness.h"
#include "oopcBuildTime.h"

TEST_GROUP(oopcBuildTime)
{
  oopcBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new oopcBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(oopcBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}

