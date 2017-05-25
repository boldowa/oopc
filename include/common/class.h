/**
 * class.h
 */

typedef struct _stClass {
	void * pub;	/* public  member */
	void * pri;	/* private member */
}stClass;

typedef stClass* Class;	/* pointer for class instance */
