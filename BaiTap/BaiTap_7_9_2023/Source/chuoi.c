#include <BaiTap_7_9_2023/Header/chuoi.h>
uint8_t countWords(char *arr){
    if(arr==NULL) return 0;
    else{
        uint8_t count=1;
        for(int i=0;arr[i]!='\0';i++){
            if (arr[i]==' ') count++;
        }
        return count;
    }
}
/*
* Function: newNode
* Description: This function create the word if it don't add into;
* Input:
*   Words: the words add
*   
* Output:
*   add that words into the binarytree;
*/
Tree_words *newNode(Words_chuoi item) {
  struct Tree_node *temp = (struct Tree_node*)malloc(sizeof(struct Tree_node));
  temp->word_name = item;
  temp->left = temp->right = NULL;
  return temp;
}
/*
* Function: toLeftOrRight
* Description: This function return that word_add is after or before word_check;
* Input:
*    2 Words: word_check and  word_add
*   
* Output:
*   return true if it is after
    return false if else
*/
bool toLeftOrRight(Words_chuoi word_check,Words_chuoi word_add){
    for(;word_add.locate_check<=word_add.length;word_add.locate_check++){
        if(word_add.locate_check>word_check.length) return true;
        else{
            if(word_add.arr[word_add.locate_check]>word_check.arr[word_add.locate_check]) return true;
            else if(word_add.arr[word_add.locate_check]<word_check.arr[word_add.locate_check]) return false;
        }
    }
    return false;
}
/*
* Function: insertTreeWords
* Description: This function return the length of array;
* Input:
*   Words: the words add
*   
* Output:
*   add that words into the binarytree;
*/
Tree_words *insertTreeWords(Tree_words *tree_word,Words_chuoi new_word){
    if(tree_word==NULL) return newNode(new_word);
    else{
        if(toLeftOrRight(tree_word->word_name,new_word)){
            tree_word->right=insertTreeWords(tree_word->right,new_word);
        }
        else{
            tree_word->left=insertTreeWords(tree_word->left,new_word);
        }
    }
    return tree_word;
}

void inOrder(Tree_words *root) {
  if (root != NULL) {
    // Traverse left
    inOrder(root->left);

    // Traverse root
    for(int i=0;i<root->word_name.length;i++) printf("%c",root->word_name.arr[i]);
    printf(" ");
    // Traverse right
    inOrder(root->right);
  }
}
void nameAfterSort(char *arr){
    Tree_words *root=NULL;
    int beginWord=0;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==' '){
            Words_chuoi new_word;
            new_word.length=i-beginWord;
            new_word.arr=arr+beginWord;
            new_word.locate_check=0;
            beginWord=i+1;
            root = insertTreeWords(root, new_word);

        }
        if(arr[i+1]=='\0'){
            Words_chuoi new_word;
            new_word.length=i+1-beginWord;
            new_word.arr=arr+beginWord;
            new_word.locate_check=0;
            beginWord=i+1;
            root = insertTreeWords(root, new_word);
        }
    }
    inOrder(root);
    
}