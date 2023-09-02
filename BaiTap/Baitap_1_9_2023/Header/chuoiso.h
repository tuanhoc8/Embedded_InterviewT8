#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node{
    char *arr;
    uint8_t length;
    struct node *next;
    struct node *previous;
}Words;
void insertWords(char *arr, uint8_t length);
void deleteListWords();
void printNguoc(char *arr);
