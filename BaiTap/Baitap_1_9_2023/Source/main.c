#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <C:/Embedded/Baitap_1_9_2023/Header/chuoiso.h>
#include <C:/Embedded/Baitap_1_9_2023/Header/ngaythangnam.h>

int main(int *argc,char *argv){
    char arr[]="hello em";
    printNguoc(arr);
    printf("\n");
    Date a={1,4,2000};
    
    printWeekDay(a);
    
    
}