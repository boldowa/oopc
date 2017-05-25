/**
 * TestModule.c
 */
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "common/class.h"
#include "pack/TestModule.h"

/* this header isn't read from anything other */
/* than inherited object.                     */ 
#include "TestModule.private.h"

/* prototypes */
static const char* hello_get(Class);
static int value_get(Class);
static void value_set(Class, int);


/*--------------- Constructor / Destructor ---------------*/

/**
 * @brief Create object instance
 *
 * @param str string
 *
 * @return Object instance
 */
Class TestModule_new(const char* str)
{
	Class instance;
	TestModule* pub;
	TestModule_private* pri;

	/* make objects */
	pub = malloc(sizeof(TestModule));
	pri = malloc(sizeof(TestModule_private));
	instance = malloc(sizeof(stClass));

	/* check whether object creatin succeeded */
	assert(pub);
	assert(pri);
	assert(instance);

	/*--- set private member */
	pri->hello = str;
	pri->value = 0;

	/*--- set public member */
	pub->pubvalue = 0;
	pub->hello_get = hello_get;
	pub->value_get = value_get;
	pub->value_set = value_set;

	/* init Class object */
	{
		stClass init = {pub, pri};
		memcpy(instance, &init, sizeof(stClass));
	}
	return instance;
}

/**
 * @brief Delete object instance
 *
 * @param instance the pointer of object instance
 */
void TestModule_delete(Class* instance)
{
	/* This is the template that default destractor. */
	assert(instance);
	if(NULL == (*instance)) return;
	free((*instance)->pub);
	free((*instance)->pri);
	free(*instance);
	(*instance) = NULL;
}




/*--------------- internal methods ---------------*/

/**
 * @brief Get <hello>'s strings
 *
 * @param instance Object instance
 *
 * @return strings that <hello> has
 */
static const char* hello_get(Class instance)
{
	assert(instance);
	return ((TestModule_private*)instance->pri) ->hello;
}

/**
 * @brief Get <value>'s value
 *
 * @param instance Object instance
 *
 * @return value that <value> has
 */
static int value_get(Class instance)
{
	assert(instance);
	return ((TestModule_private*)instance->pri) ->value ;
}

/**
 * @brief set value to <value>
 *
 * @param instance Object instance
 * @param value value to set in <value>
 */
static void value_set(Class instance, int value)
{
	assert(instance);
	((TestModule_private*)instance->pri) ->value = value;
}
