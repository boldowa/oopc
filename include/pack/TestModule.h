#pragma once
/**
 * TestModule.h
 */

/* constractor */
Class TestModule_new(const char*);

/* destractor */
void TestModule_delete(Class*);

/* member valriable / methods */
typedef struct {
	/* member variable */
	int pubvalue;

	/* member methods */
	const char* (*hello_get)(Class);
	int (*value_get)(Class);
	void (*value_set)(Class, int);
} TestModule;

