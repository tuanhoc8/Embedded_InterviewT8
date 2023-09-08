#include <BaiTap_7_9_2023/Header/tien.h>

Words *WORD_TAIL=NULL;
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
    if(WORD_TAIL==NULL) {
        WORD_TAIL=(struct node*) malloc(sizeof(struct node));
        WORD_TAIL->arr=arr;
        WORD_TAIL->length=length;
        WORD_TAIL->prev=NULL;
        WORD_TAIL->next=NULL;
        WORD_CURRENT=WORD_TAIL;
    }
    else{
        Words *WORD_NEW=(struct node*) malloc(sizeof(struct node));
        WORD_NEW->arr=arr;
        WORD_NEW->length=length;
        WORD_NEW->next=WORD_CURRENT;
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
    if(WORD_TAIL!=NULL){
        Words *WORD_TAIL_NEW=WORD_TAIL;
        WORD_TAIL=WORD_TAIL->prev;
        free(WORD_TAIL_NEW);
    }
    
}
/*
* Function: printfNumber
* Description: This function change from number to VIETNAMESE WORD;
* Input:
*   uint8_t number
*   
* Output:
*   returns char VIetNAMESE
*/
static char *printfNumber(NUMBER_VALUE so){
    switch(so){
        NUMBER_IN(NUMBER_INRA,;)
        default: return NULL;
    }
}
static char *printfPhanCach(MENH_GIA menhgia){
    switch(menhgia){
        MENH_GIA_IN(MENH_GIA_IN_RA,;)
        default: return NULL;
    }
}
/*
* Function: lengthArr
* Description: This function return the length of array;
* Input:
*   char *arr - the array
*   
* Output:
*   returns uint8_t length of the array
*/
uint8_t lengthArr(char *arr){
    uint8_t length=0;
    if (arr==NULL) return length;
    for(length=0;arr[length]!='\0';length++);
    return length;
}
uint8_t heSo(uint8_t i){
    if(i==3) return 1;
    else{
        return 10*heSo(i+1);
    }
}
void makeValue(uint16_t number){
    if((number%100==0)){

    }
    else if((number%100<10)){
        char *arr=printfNumber(number%100);
        insertWords(arr,lengthArr(arr));
        insertWords("LE",2);
    }
    else if(number%100<20){
        char *arr=printfNumber(number%10);
        insertWords(arr,lengthArr(arr));
        insertWords("MUOIf",5);
    }
    else {
        char *arr=printfNumber(number%10);
        insertWords(arr,lengthArr(arr));
        insertWords("MUOI",4);
        arr=printfNumber((number%100)/10);
        insertWords(arr,lengthArr(arr));
    }
    if(number>99) {
        number/=100;
        char *arr=printfNumber(number);
        insertWords("TRAM",4);
        insertWords(arr,lengthArr(arr));
    }
}
void printfMenhGia(){
    Words *WORD_CHECK=WORD_CURRENT;
    while(WORD_CHECK!=NULL){
        for(int i=0;i<WORD_CHECK->length;i++){
            printf("%c",WORD_CHECK->arr[i]);
        }
        if(WORD_CHECK->arr!=NULL) printf(" ");
        WORD_CHECK=WORD_CHECK->next;
    }
    deleteListWords();
}
void MenhGia(char arr[]){
    int8_t locate=0;
    char *end_arr="DONG";
    insertWords(end_arr,4);
    locate=lengthArr(arr);
    MENH_GIA menh_gia=1;
    while(locate>0){
        uint16_t number=0;
        for(int i=3;i>0;i--){
            if(locate<=0) break;
            else{
                number=number+(arr[locate-1]-'0')*heSo(i);  
                locate--;
            }
        }
        char *arr_menh_gia=printfPhanCach(menh_gia);
        insertWords(arr_menh_gia,lengthArr(arr_menh_gia));
        makeValue(number);
        if((menh_gia)&& (locate>0) &&( number >0) &&(number<10)){
            arr_menh_gia="KHONG TRAM";
            insertWords(arr_menh_gia,lengthArr(arr_menh_gia));
        }
        menh_gia<<=1;

    }
    // printf("%c---%c---,%c---,%c\n",WORD_CURRENT->arr[0],WORD_CURRENT->next->arr[0],WORD_CURRENT->next->next->arr[0],WORD_CURRENT->next->next->next->arr[0]);
    printfMenhGia();
}

