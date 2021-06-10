#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
 
HashTable* create_hash(int size){
	HashTable *r;
	
	r = (HashTable *)malloc(sizeof(HashTable));
	if(r == NULL) return NULL;
	
	r->bucket = (HashEntry **)malloc(size * sizeof(HashEntry *));
	if(r->bucket == NULL){
		free(r);
		return NULL;
	}
	
	r->size = size;
	r->last_error = HASH_OK;
	return r;
}

