#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;


typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;


// Creates a new node and resets all its values
// In case "calloc" failed - exit
node* newNode(char data){
    node *p=NULL;
    p =(node*) calloc (1,sizeof(node));
    if (!p) exit(1);
    p->letter =data;
    p->count =0;
    for (size_t i = 0; i < NUM_LETTERS; i++){
        p->children[i]=NULL;
    }
    return p;   
}




/*
Receives node and receives "char c".
In case c is one of the characters that signify that we have finished a word
we will add 1 to the current count.
if it is a capital letter we will activate "tolower" on it
And if it is a normal letter
go into the recursion function again for the son corresponding to the letter until
we reach the end of the word.
In case we have reached the end of the input the function will return FALSE
else TRUE
*/
boolean insert(node *n){
    char c;
    int e=scanf("%c",&c);
    if (e==EOF || c=='\n' || c==' ' || c=='\t'){
        n->count++;
        if (e==EOF) return FALSE;
        else return TRUE;
    }
    if ('A'<= c && 'Z'>=c){
        c=tolower(c);
    }
    if ('a'<=c && 'z'>=c){
        int i=c-'a';
        if(!(n->children[i])){
           n->children[i]=newNode(c);
        }
            return insert(n->children[i]);
           
    }else{
      return insert(n);  
    }
}



/*
Passing each node activates the recursion function on all its non-null children.
Finally it also releases the node itself.
This is how we basically release all the nodes in the tree
*/
void freeNode(node *n){
    if (!n) return;
    for (size_t i = 0; i < NUM_LETTERS; i++){
        freeNode(n->children[i]);
    }
    free(n);
}


/*
Goes through the whole tree.
At each level threads the new character to the word
and in case it appears at least once it prints it.
That's basically how he will print all the words.
Since the for loop starts from 0 and the i increases
then basically it will reach every word the lexicographic order goes up
*/

void print_words_up(node *n,char *str,int len){
    if (!n) return;
    len++;
    char new_str[len+1];
    strcpy(new_str,str);
    new_str[len-1]=n->letter;
    new_str[len]='\0';
    if (n->count>0){
         printf("%s %ld\n",new_str,n->count);
    }
    for (size_t i = 0; i < NUM_LETTERS; i++){
        if (n->children[i])
        {
            print_words_up(n->children[i],new_str,len);
        }
    }

}


// Gets the root and runs "print_words_up" on the tree
void print_root_up(node *n){
    if (!n) return;
    for (size_t i = 0; i < NUM_LETTERS; i++){
        print_words_up(n->children[i],"",0);
        }
}




/*  Exactly the same as up
    except that because the loop for descends we will reach every word
    in the lexicographic order descending
 */

void print_words_down(node *n,char *str,int len){
    if (!n) return;
    len++;
    char new_str[len+1];
    strcpy(new_str,str);
    new_str[len-1]=n->letter;
    new_str[len]='\0';
    for (int i = NUM_LETTERS-1; i >= 0; i--){
        if (n->children[i]){
            print_words_down(n->children[i],new_str,len);
        }
    }
       if (n->count>0){
         printf("%s %ld\n",new_str,n->count);
    }

}



void print_root_down(node *n){
    if (!n) return;
    for (int i = NUM_LETTERS-1; i >= 0; i--){
        print_words_down(n->children[i],"",0);
        }
}



/*
First check if we got "r" and if so we will join the "down" function
otherwise we will join "up"
Next we will create a root for the tree
and then initialize the nodes in the tree according to the input using the "insert" function
Then we will print according to the shape selected up \ down.
And finally we will free the place of the nodes in memory
*/

int main(int argc, char** argv){
    boolean down=FALSE;
    if (argc>1){
        if (**(argv+1)=='r') down=TRUE;
    }
    node *root=newNode('R');
    boolean boo=TRUE;
    while (boo){
         boo= insert(root);
    }
      if (down){
        print_root_down(root);
    }else{
        print_root_up(root);
    }
  
  
    freeNode(root);

    printf("\n");
    return 0;
}