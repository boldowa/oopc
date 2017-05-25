#include <assert.h>
extern "C"
{
#include "common/class.h"
#include "pack/TestModule.h"
#include "pack/TestChild.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TestChild)
{
	/* assert value */
	const char* TestString = "Hello, OOPC Child!\n";

	/* test target */
	Class instance;
	TestChild* testChild;

	void setup()
	{
		instance = TestChild_new(TestString);
		assert(instance);
		testChild = (TestChild*)instance->pub;
	}

	void teardown()
	{
		TestChild_delete(&instance);
	}
};

/**
 * Check object create
 */
TEST(TestChild, new)
{
	CHECK(NULL != testChild);

	/* check initial value */
	LONGS_EQUAL(0, testChild->add);
}

/**
 * Check object delete
 */
TEST(TestChild, delete)
{
	TestChild_delete(&instance);

	/* check delete */
	POINTERS_EQUAL(NULL, instance);
}

/**
 * Check add variable
 */
TEST(TestChild, add)
{
	testChild->add = 1000;
	LONGS_EQUAL(1000, testChild->add);
}

/**
 * Check super variable
 */
TEST(TestChild, super)
{
	TestModule* super;
	super = (TestModule*)instance->pub;

	/* check super method (Call hello_get method as representative) */
	STRCMP_EQUAL(TestString, super->hello_get(instance));
}

/**
 * Check value_get overrided method
 */
TEST(TestChild, value_get)
{
	/* interface */
	TestModule* super = (TestModule*)testChild;

	LONGS_EQUAL(0, super->value_get(instance));
	super->value_set(instance, 30);
	LONGS_EQUAL(30, super->value_get(instance));

	testChild->add = 1000;
	LONGS_EQUAL(1030, super->value_get(instance));
}

