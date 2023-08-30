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
    int firstCapitalize=0;
    for(firstCapitalize=0;arr[firstCapitalize]!='\0';firstCapitalize++){
        if(arr[firstCapitalize]=='.') break;
    }
    if(arr[firstCapitalize]=='\0'){

    } 
    else{
        for(int i=firstCapitalize+1;arr[i]!='\0';i++){
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
*   char arrFind[]- the array will be found
*   char DOCUMENT[]- The document where is the place to find
* Output:
*   if have printf Yes and the place to find it
*   if no print No
*/
void findArr(char document[],char arrFind[]){
    bool checkArr=false;
    for(int i=0;document[i]!='\0';i++){
        if(document[i]==arrFind[0]){
            bool check=true;
            for(int j=1;arrFind[j]!='\0';j++){
                if(arrFind[j]!=document[i+j]) {
                    check=false;
                    break;
                }
            }
            if (check){
                if (!checkArr){
                    checkArr=true;
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
    if(!checkArr) printf("No");
    printf("\n");
}
typedef struct node{
    char *arr;
    uint8_t length;
    struct node *next;
}Words;
Words *word_Head=NULL;
Words *word_Current=NULL;
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
    if(word_Head==NULL) {
        word_Head=(struct node*) malloc(sizeof(struct node));
        word_Head->arr=arr;
        word_Head->length=length;
        word_Head->next=NULL;
        word_Current=word_Head;
    }
    else{
        Words *word_New=(struct node*) malloc(sizeof(struct node));
        word_New->arr=arr;
        word_New->length=length;
        word_New->next=NULL;
        word_Current->next=word_New;
        word_Current=word_New;
        
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
    if(word_Head!=NULL){
        Words *word_Head_New=word_Head;
        word_Head=word_Head->next;
        free(word_Head_New);
    }
    
}
/*
* Function: findReplace
* Description: This function delete the list of words in the arrays after return the value;
* Input:
*   char *documentChange - name of the DOCUMENT
*   char *findArr - name of ARRAY need to find
*   char *arrReplace - name of ARRAY will replace
* Output:
*   returns the DOCUMENT AFTER REPLACE.
*/
static char *findReplace(char *documentChange,char *findArr,char *arrReplace){
    int beginCharacter=0;
    int count=0;
    int SIZE_findArr=0;
    
    for(SIZE_findArr=0;findArr[SIZE_findArr]!='\0';SIZE_findArr++);
    int sizeDocumentchange;
    for(sizeDocumentchange=0;documentChange[sizeDocumentchange]!='\0';sizeDocumentchange++){
        if(findArr[0]==documentChange[sizeDocumentchange]){
            bool check=true;
            for(int j=1;findArr[j]!='\0';j++){
                if(findArr[j]!=documentChange[sizeDocumentchange+j]){
                    check=false;
                    break;
                }
            }
            if(check){
                count++;
                insertWords(documentChange+beginCharacter,sizeDocumentchange-beginCharacter);
                beginCharacter=sizeDocumentchange+SIZE_findArr;
                sizeDocumentchange=beginCharacter-1;
            }
            else{
                continue;
            }
        }
        if (documentChange[sizeDocumentchange+1]=='\0') break;
    }
    insertWords(documentChange+beginCharacter,sizeDocumentchange+1-beginCharacter);
    int sizeMAKE=0;
    if((sizeof(arrReplace))-sizeof(findArr)>0)
        sizeMAKE=sizeof(arrReplace)-sizeof(findArr);
    else
        sizeMAKE=-sizeof(arrReplace)+sizeof(findArr);

    char *newDocument=(char *)malloc(sizeof(documentChange)-count*(sizeMAKE+1));
    if(word_Head==NULL) return documentChange;
    else{
        int locate=0;
        Words *WORD_check=word_Head;
        while(WORD_check!=word_Current){
            for(int i=0;i<WORD_check->length;i++){
                newDocument[locate]=WORD_check->arr[i];
                locate++;
            }
            for(int i=0;arrReplace[i]!='\0';i++){
                newDocument[locate]=arrReplace[i];
                locate++;
            }
            WORD_check=WORD_check->next;
        }
        for(int i=0;i<word_Current->length;i++){
                newDocument[locate]=word_Current->arr[i];
                locate++;
        }
        newDocument[locate]='\0';
        deleteListWords();
        return newDocument;
    }
    
    
}
int main(){
    char arrInHoa[]="ai.my";
    inHoa(arrInHoa);
    char arrFind[]="how to do";
    char document[]="DO you know how to do the work and how to do homework ";
    findArr(document,arrFind);
    char *documentChange="Chao Hi ban nha Hi ne";
    char *findArr="Hi";
    char *replace="cc";
    char *x=findReplace(documentChange,findArr,replace);
    for(int i=0;x[i]!='\0';i++){
        printf("%c",x[i]);
    }
    return 0;
}