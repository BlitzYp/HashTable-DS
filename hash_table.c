#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <string.h>

struct data 
{
    const uint8_t* key;
    uint8_t value;
    struct data* next;
};

struct hash_table 
{
    uint8_t size;
    struct data** table;
    struct data* head; 
};

uint8_t hash(const uint8_t* key, size_t size);
struct hash_table* create(size_t size);
void add(const uint8_t* key, const uint8_t value, struct hash_table* dict) ;
uint8_t get(struct hash_table* dict, const uint8_t* key);
uint8_t** keys(struct hash_table* dict);

int main()
{
    struct hash_table* dict = create(5);
    add("apple", 4, dict);
    add("pearr", 5, dict);
    uint8_t apple_value = get(dict, "pearr");
    uint8_t** values = keys(dict);
    printf("%s\n", values[1]);
    free(values);
    free(dict);
}


uint8_t hash(const uint8_t* key, size_t size)
{
    uint8_t hash = 0;
    for (uint8_t i = 0; i < strlen(key); i++)
        hash = (hash + key[i] * i) % size;

    return hash;
}

struct hash_table* create(size_t size)
{
    struct hash_table* res = malloc(sizeof(struct hash_table));
    res->size = size;
    res->table = malloc(sizeof(struct data) * size);
    for (uint8_t i = 0; i < size; i++)
        res->table[i] = NULL;
    return res;
}

void add(const uint8_t* key, uint8_t value, struct hash_table* dict) 
{
    uint8_t h = hash(key, dict->size);
    struct data* d = malloc(sizeof(struct data));
    d->key = key;
    d->value = value;
    d->next = dict->head;
    dict->head = d;
    dict->table[h] = d;
}

uint8_t get(struct hash_table* dict, const uint8_t* key)
{
    uint8_t h = hash(key, dict->size);
    struct data* res = dict->table[h];
    if (res == NULL) 
    {
        printf("KeyError\n");
        return 0;
    }
    printf("%d\n", res->value);
    return res->value;
}

uint8_t** keys(struct hash_table* dict)
{
    uint8_t** keys = malloc(sizeof(char*) * dict->size);
    struct data* current = dict->head;

    for (uint8_t i = 0; current != NULL; i++, current = current->next)
        keys[i] = (uint8_t*) current->key;

    return keys;
}