#include <assert.h>
extern "C"
{
#include "common/class.h"
#include "pack/TestModule.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TestModule)
{
	/* assert value */
	const char* TestString = "Hello, OOPC World!\n";

	/* test target */
	Class instance;
	TestModule* testModule;

	void setup()
	{
		instance = TestModule_new(TestString);
		assert(instance);
		testModule = (TestModule*)instance->pub;
	}

	void teardown()
	{
		TestModule_delete(&instance);
	}
};

/**
 * Check object create
 */
TEST(TestModule, new)
{
	CHECK(NULL != testModule);

	/* check initial value */
	LONGS_EQUAL(0, testModule->value_get(instance));
	LONGS_EQUAL(0, testModule->pubvalue);
}

/**
 * Check object delete
 */
TEST(TestModule, delete)
{
	TestModule_delete(&instance);

	/* check delete */
	POINTERS_EQUAL(NULL, instance);
}

/**
 * Check pubvalue variable
 */
TEST(TestModule, pubvalue)
{
	testModule->pubvalue = 1024;
	LONGS_EQUAL(1024, testModule->pubvalue);
}

/**
 * Check hello_get method
 */
TEST(TestModule, hello_get)
{
	STRCMP_EQUAL(TestString, testModule->hello_get(instance));
}

/**
 * Check value_get method
 */
TEST(TestModule, value_get)
{
	/* Nothing to do */
}

/**
 * Check value_set method
 */
TEST(TestModule, value_set)
{
	testModule->value_set(instance, 999);
	LONGS_EQUAL(999, testModule->value_get(instance));
}
