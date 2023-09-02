
#include <C:/Embedded/Baitap_1_9_2023/Header/chuoiso.h>

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
        WORD_HEAD->next=NULL;
        WORD_HEAD->previous=NULL;
        WORD_CURRENT=WORD_HEAD;
    }
    else{
        Words *WORD_NEW=(struct node*) malloc(sizeof(struct node));
        WORD_NEW->arr=arr;
        WORD_NEW->length=length;
        WORD_NEW->next=NULL;
        WORD_NEW->previous=WORD_CURRENT;
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
* Function: printNguoc
* Description: This function will print from the bottom 
* Input:
*   char arr*-> the string
*   uint8_t length-> length of the words
* Output:
*   the string has change 
*/
void printNguoc(char *arr){
/* 
    B1 tach chuoi
    B2 in nguoc ra
*/  
    //B1
    int begin_character=0;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==' '){
            
            char *newarr=arr+begin_character;
            uint8_t length=i-begin_character;
            insertWords(newarr,length);
            begin_character=i+1;
        }
        if(arr[i+1]=='\0'){
            char *newarr=arr+begin_character;
            uint8_t length=i-begin_character+1;
            insertWords(newarr,length);
        }
    }
    
    
    //B2
    printf("Chuoi in nguoc la: \n");
    
    Words *word_check=WORD_CURRENT;
    while(word_check!=NULL){
        for(int i=0;i<word_check->length;i++) printf("%c",word_check->arr[i]);
        printf(" ");
        word_check=word_check->previous;
    }
    
    //B3 free bo nho
    deleteListWords();
}