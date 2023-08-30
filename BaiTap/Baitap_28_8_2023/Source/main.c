#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/*
* Function: inHoa
* Description: This function will capitalize the letters after the .
* Input:
*   char arr[]
* Output:
*   printf the array after capitalize
*/
 void inHoa(char arr[]){
    int FIRST_CAPITALIZE=0;
    for(FIRST_CAPITALIZE=0;arr[FIRST_CAPITALIZE]!='\0';FIRST_CAPITALIZE++){
        if(arr[FIRST_CAPITALIZE]=='.') break;
    }
    if(arr[FIRST_CAPITALIZE]=='\0'){

    } 
    else{
        for(int i=FIRST_CAPITALIZE+1;arr[i]!='\0';i++){
            if((arr[i]>='a')&&(arr[i]<='z')){
                arr[i]=(char)(arr[i]-'a'+'A');
            }
               
        }  
    }
    for(int i=0;arr[i]!='\0';i++){
        printf("%c",arr[i]);
    }
    printf("\n");
}
/*
* Function: findArr
* Description: This function will find the array in the document .
* Input:
*   char ARR_FIND[]- the array will be found
*   char DOCUMENT[]- The document where is the place to find
* Output:
*   if have printf Yes and the place to find it
*   if no print No
*/
void findArr(char DOCUMENT[],char ARR_FIND[]){
    bool CHECK_ARR=false;
    for(int i=0;DOCUMENT[i]!='\0';i++){
        if(DOCUMENT[i]==ARR_FIND[0]){
            bool CHECK=true;
            for(int j=1;ARR_FIND[j]!='\0';j++){
                if(ARR_FIND[j]!=DOCUMENT[i+j]) {
                    CHECK=false;
                    break;
                }
            }
            if (CHECK){
                if (!CHECK_ARR){
                    CHECK_ARR=true;
                    printf("YES, that in place: %d",i);
                }
                else{
                    printf(", %d",i);
                }
            }
            else{
                continue;
            }
        }
    }
    if(!CHECK_ARR) printf("No");
    printf("\n");
}
typedef struct node{
    char *arr;
    uint8_t length;
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
        WORD_HEAD->next=NULL;
        WORD_CURRENT=WORD_HEAD;
    }
    else{
        Words *WORD_NEW=(struct node*) malloc(sizeof(struct node));
        WORD_NEW->arr=arr;
        WORD_NEW->length=length;
        WORD_NEW->next=NULL;
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
* Function: findReplace
* Description: This function delete the list of words in the arrays after return the value;
* Input:
*   char *DOCUMENTCHANGE - name of the DOCUMENT
*   char *FIND_ARR - name of ARRAY need to find
*   char *ARR_REPLACE - name of ARRAY will replace
* Output:
*   returns the DOCUMENT AFTER REPLACE.
*/
static char *findReplace(char *DOCUMENTCHANGE,char *FIND_ARR,char *ARR_REPLACE){
    int BEGIN_CHARACTER=0;
    int count=0;
    int SIZE_FIND_ARR=0;
    
    for(SIZE_FIND_ARR=0;FIND_ARR[SIZE_FIND_ARR]!='\0';SIZE_FIND_ARR++);
    int SIZE_DOCUMENCHANGE;
    for(SIZE_DOCUMENCHANGE=0;DOCUMENTCHANGE[SIZE_DOCUMENCHANGE]!='\0';SIZE_DOCUMENCHANGE++){
        if(FIND_ARR[0]==DOCUMENTCHANGE[SIZE_DOCUMENCHANGE]){
            bool CHECK=true;
            for(int j=1;FIND_ARR[j]!='\0';j++){
                if(FIND_ARR[j]!=DOCUMENTCHANGE[SIZE_DOCUMENCHANGE+j]){
                    CHECK=false;
                    break;
                }
            }
            if(CHECK){
                count++;
                insertWords(DOCUMENTCHANGE+BEGIN_CHARACTER,SIZE_DOCUMENCHANGE-BEGIN_CHARACTER);
                BEGIN_CHARACTER=SIZE_DOCUMENCHANGE+SIZE_FIND_ARR;
                SIZE_DOCUMENCHANGE=BEGIN_CHARACTER-1;
            }
            else{
                continue;
            }
        }
        if (DOCUMENTCHANGE[SIZE_DOCUMENCHANGE+1]=='\0') break;
    }
    insertWords(DOCUMENTCHANGE+BEGIN_CHARACTER,SIZE_DOCUMENCHANGE+1-BEGIN_CHARACTER);
    int sizeMAKE=0;
    if((sizeof(ARR_REPLACE))-sizeof(FIND_ARR)>0)
        sizeMAKE=sizeof(ARR_REPLACE)-sizeof(FIND_ARR);
    else
        sizeMAKE=-sizeof(ARR_REPLACE)+sizeof(FIND_ARR);

    char *NEWDOCUMENT=(char *)malloc(sizeof(DOCUMENTCHANGE)-count*(sizeMAKE+1));
    if(WORD_HEAD==NULL) return DOCUMENTCHANGE;
    else{
        int LOCATE=0;
        Words *WORD_CHECK=WORD_HEAD;
        while(WORD_CHECK!=WORD_CURRENT){
            for(int i=0;i<WORD_CHECK->length;i++){
                NEWDOCUMENT[LOCATE]=WORD_CHECK->arr[i];
                LOCATE++;
            }
            for(int i=0;ARR_REPLACE[i]!='\0';i++){
                NEWDOCUMENT[LOCATE]=ARR_REPLACE[i];
                LOCATE++;
            }
            WORD_CHECK=WORD_CHECK->next;
        }
        for(int i=0;i<WORD_CURRENT->length;i++){
                NEWDOCUMENT[LOCATE]=WORD_CURRENT->arr[i];
                LOCATE++;
        }
        NEWDOCUMENT[LOCATE]='\0';
        deleteListWords();
        return NEWDOCUMENT;
    }
    
    
}
int main(){
    char ARR_IN_HOA[]="ai.my";
    inHoa(ARR_IN_HOA);
    char ARR_FIND[]="how to do";
    char DOCUMENT[]="DO you know how to do the work and how to do homework ";
    findArr(DOCUMENT,ARR_FIND);
    char *DOCUMENTCHANGE="Chao Hi ban nha Hi ne";
    char *FIND_ARR="Hi";
    char *replace="cc";
    char *x=findReplace(DOCUMENTCHANGE,FIND_ARR,replace);
    for(int i=0;x[i]!='\0';i++){
        printf("%c",x[i]);
    }
    return 0;
}
