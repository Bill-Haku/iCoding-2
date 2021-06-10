#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "hash.h"

#include <string.h>

int Find(HashTable* table, const char* key, int value, long keyhash) {
    HashEntry* Head = table->bucket[keyhash];
    while (Head && strcmp(Head->key.str_value, key)) {
        Head = Head->next;
    }
    if (!Head) {
        return -1;
    }
    else if (Head->value.int_value == value) {
        return 1;
    }
    else {
        Head->value.int_value = value;
        return 0;
    }
}

HASH_RESULT hash_add_int(HashTable* table, const char* key, int value) {
    int p;
    long keyhash = hash_string(key) % table->size;
    p = Find(table, key, value, keyhash);
    if (p == -1) {
        HashEntry* Node = (HashEntry*)malloc(sizeof(HashEntry));
        if (!Node)
            return HASH_ERROR;
        Node->key.str_value = (char*)malloc(100);
        if (Node->key.str_value == NULL) {
            return HASH_ERROR;
        }
        Node->key.str_value = (char*)key;
        Node->value.int_value = value;
        //Node->next = table->bucket[keyhash]; //？
        table->bucket[keyhash] = Node;
        return HASH_ADDED;
    } 
    else if (p == 0) {
        return HASH_REPLACED_VALUE;
    }
    else {
        return HASH_ALREADY_ADDED;
    }
}
