#ifndef TIEN_H
#define TIEN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define NUMBER_IN(X,S)                      \
    X(MOT) S                                \
    X(HAI) S                                \
    X(BA) S                                 \
    X(BON) S                                \
    X(NAM) S                                \
    X(SAU) S                                \
    X(BAY) S                                \
    X(TAM) S                                \
    X(CHIN) S                                
#define NUMBER_INRA(D) case D: return #D
#define MENH_GIA_IN(X,S)                    \
    X(NGAN) S                               \
    X(TRIEU) S                              \
    X(TY) S                                
#define MENH_GIA_IN_RA(D) case D: return #D
typedef enum{
    NGAN=1<<1,
    TRIEU=1<<2,
    TY=1<<3
}MENH_GIA;

typedef enum{
    MOT=1,
    HAI=2,
    BA=3,
    BON=4,
    NAM=5,
    SAU=6,
    BAY=7,
    TAM=8,
    CHIN=9,
}NUMBER_VALUE;
typedef struct node{
    char *arr;
    uint8_t length;
    struct node *next;
    struct node *prev;
}Words;
void MenhGia(char arr[]);



#endif // TIEN_H