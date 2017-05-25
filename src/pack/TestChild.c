/**
 * TestChild.c
 *   ... This module extends public member of TestModule.
 */
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "common/class.h"
#include "pack/TestModule.h"
#include "TestModule.private.h"  /* inherit TestModule */
#include "pack/TestChild.h"

/* prototypes */
static int value_get(Class);


/*--------------- Constructor / Destructor ---------------*/

/**
 * @brief Create object instance
 *
 * @param str string
 *
 * @return Object instance
 */
Class TestChild_new(const char* str)
{
	Class instance;
	TestChild* pub;

	/* make object */
	pub = malloc(sizeof(TestChild));
	instance = TestModule_new(str);

	/* check whether object creatin succeeded */
	assert(pub);
	assert(instance);

	/*--- set public member */
	memcpy(&pub->super, (TestModule*)instance->pub, sizeof(TestModule));	/* copy super object */
	pub->super.value_get = value_get; /* <=== extend from TestModule */
	pub->add = 0;

	/* inherit */
	free(instance->pub);
	instance->pub = pub;

	return instance;
}

/**
 * @brief Delete object instance
 *
 * @param instance the pointer of object instance
 */
void TestChild_delete(Class* instance)
{
	assert(instance);

	if(NULL == (*instance)) return;

	free((*instance)->pub);
	free((*instance)->pri);
	free(*instance);
	(*instance) = NULL;
}




/*--------------- internal methods ---------------*/

/**
 * @brief Get <value>'s value and <add>'s sum
 *
 * @param instance Object instance
 *
 * @return value that <value> has + <add> has
 */
static int value_get(Class instance)
{
	assert(instance);

	return ((TestModule_private*)instance->pri) ->value
		+ ((TestChild*)instance->pub) ->add;
}
