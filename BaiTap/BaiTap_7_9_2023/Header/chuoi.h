#ifndef CHUOI_H
#define CHUOI_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
typedef struct Chuoi_node{
    char *arr;
    uint8_t length;
    uint8_t locate_check;
}Words_chuoi;
typedef struct Tree_node {
  Words_chuoi word_name;
  struct Tree_node *left, *right;
}Tree_words;

void nameAfterSort(char *arr);
#endif // CHUOI_H