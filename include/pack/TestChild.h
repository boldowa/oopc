#pragma once
/**
 * TestChild.h
 */

/* constractor */
Class TestChild_new(const char*);

/* destractor */
void TestChild_delete(Class*);

/* member valriable / methods */
typedef struct {
	/* super */
	TestModule super;

	/* member variable */
	int add;
} TestChild;
