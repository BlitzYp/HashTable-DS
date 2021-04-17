#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node {
    const char* key;
	const char* value;
	struct node* next;
} node;

typedef struct hashTable {
	size_t maxSize;
	node** values;
} hashTable;

void initHash(hashTable* table, size_t maxSize) {
	table->maxSize = maxSize;
	table->values = (node**)calloc(maxSize, sizeof(node*));
	if (table->values == NULL) {
		printf("Could not init\n");
		exit(1);
	}
	for (int i = 0; i < maxSize; i++)
		table->values[i] = NULL;
}

int hash(const char* key, size_t maxSize) {
	int hash = 0;
	for (int i = 0; i < strlen(key); i++) 
        hash = (hash + key[i]);
	return hash % maxSize;
}

node* createNode(const char* key, const char* value) {
	node* n = (node*)calloc(1, sizeof(node));
    if (n == NULL) {
        perror("Could not allocate memory for node");
        exit(1);
    }
	n->value = value;
    n->key = key;
	n->next = NULL;
	return n;
}

void add(const char* key, const char* value, hashTable* table) {
	int index = hash(key, table->maxSize);
    printf("%d\n", index);
	node* newNode = createNode(key, value);
	node* curr = table->values[index];
    newNode->next = curr;
    table->values[index] = newNode;
}

const char* get(const char* key, hashTable* table) {
    node* res = table->values[hash(key, table->maxSize)];
    if (res == NULL) return NULL;
    node* curr = res;
    while (curr->key != key && curr->next != NULL) 
        curr = curr->next;
    if (curr->key != key) return NULL;
    return curr->value;
}

int main(void) {
	hashTable* table = (hashTable*)malloc(sizeof(hashTable));
	initHash(table, 6);
	add("Blitz", "Epic", table);
    add("John", "Cut my hair baby", table);
    add("Hagrid", "penis man",table);
    add("Justin", "something",table);
    add("pepeman", "oh yes",table);
    add("2", "hentai", table);
    assert(strcmp(get("2", table), "hentai") == 0);
    assert(strcmp(get("Blitz", table), "Epic") == 0);
    assert(get("Mama mia", table) == NULL);
	return 0;
}
