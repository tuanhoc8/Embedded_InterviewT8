#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
typedef struct node{
    char *arr;
    uint8_t length;
    int numberWords;
    struct node *next;
}Words;
Words *WORD_HEAD=NULL;
Words *WORD_CURRENT=NULL;
/*
* Function: insertWords
* Description: This function insert a new word in a string to cha
* Input:
*   char *arr - name of the new word
*   uint8_t length - length of the new word
* Output:
*   returns the new words.
*/
void insertWords(char *arr, uint8_t length){
    if(WORD_HEAD==NULL) {
        WORD_HEAD=(struct node*) malloc(sizeof(struct node));
        WORD_HEAD->arr=arr;
        WORD_HEAD->length=length;
        WORD_HEAD->numberWords=1;
        WORD_HEAD->next=NULL;
        WORD_CURRENT=WORD_HEAD;
    }
    else{
        Words *WORD_NEW=(struct node*) malloc(sizeof(struct node));
        WORD_NEW->arr=arr;
        WORD_NEW->length=length;
        WORD_NEW->next=NULL;
        WORD_NEW->numberWords=1;
        WORD_CURRENT->next=WORD_NEW;
        WORD_CURRENT=WORD_NEW;
        
    }
}
/*
* Function: deleteListWords
* Description: This function delete the list of words in the arrays after return the value;
* Input:
*   char *arr - name of the new word
*   uint8_t length - length of the new word
* Output:
*   returns the new words.
*/
void deleteListWords(){
    if(WORD_HEAD!=NULL){
        Words *WORD_HEAD_NEW=WORD_HEAD;
        WORD_HEAD=WORD_HEAD->next;
        free(WORD_HEAD_NEW);
    }
    
}
/*
* Function: compareWords
* Description: This function will check that words is a new or old
* Input:
*   arr*-> locate of the words
*   uint8_t length-> length of the words
* Output:
*   if the word is new, it will be added in the list Words to print
*   else number of that old word will +1 
*/
void compareWords(char *arr, uint8_t length){
    if (WORD_HEAD==NULL){
        insertWords(arr,length);
    }
    else{
        Words *WORD_CHECK=WORD_HEAD;
        while((WORD_CHECK!=NULL)){
            if(WORD_CHECK->length!=length){
                WORD_CHECK=WORD_CHECK->next;
            }
            else{
                bool CHECK_HAVE=true;
                for(int i=0;i<length;i++){
                    if(WORD_CHECK->arr[i]!=arr[i]) {
                        CHECK_HAVE=false;
                        break;
                    }
                }
                
                if(!CHECK_HAVE){
                    WORD_CHECK=WORD_CHECK->next;
                }
                else{
                    WORD_CHECK->numberWords=WORD_CHECK->numberWords+1;
                    break;
                }
            }
            if(WORD_CHECK==NULL) insertWords(arr,length);
        }
    }
    
}
/*
* Function: printWords
* Description: This function print out the words and number of those words
*/
void printWords(){
    Words *WORD_CHECK=WORD_HEAD;
    while(WORD_CHECK!=NULL){
        for (int i=0;i<WORD_CHECK->length;i++)printf("%c",WORD_CHECK->arr[i]);  
        printf(": Xuat hien ");
        printf("%d",WORD_CHECK->numberWords);
        printf(" lan\n");
        WORD_CHECK=WORD_CHECK->next;
    }
    deleteListWords();
}
/*
* Function: countWords
* Description: This function get out the number of words in the string
* Input:
*   array[]- the array 
* Output:
*   returns the words and the number of those words
*/
void countWords(char array[]){
    int LOCATE_CHARACTER_HEAD=0;
    for(int i=0;array[i]!='\0';i++){
        if(array[i-1]==' ') LOCATE_CHARACTER_HEAD=i;
        if(array[i]==' '){
            uint8_t length=i-LOCATE_CHARACTER_HEAD;
            char *arr=array+LOCATE_CHARACTER_HEAD;
            compareWords(arr,length);
        }
        if(array[i+1]=='\0'){
            uint8_t length=i+1-LOCATE_CHARACTER_HEAD;
            char *arr=array+LOCATE_CHARACTER_HEAD;
            compareWords(arr,length);
        }
    }
    printWords();
}

int main()
{
    char array[]="mot hai hai mot ba";
    countWords(array);
    return 0;
}
