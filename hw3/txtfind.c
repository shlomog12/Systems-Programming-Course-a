#include<stdio.h>
#include<string.h>


#define LINE 256
#define WORD 30

int getLine(char s[LINE]){
    int len;
    for (size_t i = 0; i < LINE; i++){
        char c;
        int end = scanf("%c", &c);
        if (c == '\n'){
            s[i] = '\0';
            return i;
        }
        else if (end == EOF){
            s[i] = ' ';
            s[i + 1] = '\0';
            return i + 1;
        }
        s[i] = c;
        len = i;
    }
    return len;
}

int getword(char line[LINE],char w[WORD],int j){
    for ( size_t i = 0; i < WORD+j; i++) {
        char c=line[i+j];
        if ( c==' ' || c=='\t' || c=='\n')   return i;
        else if(c=='\0')  return i-1;
        (w[i]) = c;
    }
    return WORD;
}

int substring( char * str1, char * str2){
int len1= strlen(str1);
int len2= strlen(str2);
if (len1<len2) return 0;

for (size_t i = 0; i < len1-len2+1; i++){
    for (size_t j = 0; j < len2; j++){
        if (str1[i+j]!=str2[j]) break;
        if (j==len2-1) return 1;
    }
}
return 0;
}

int similar (char *s, char *t, int n){
    int lens=strlen(s);
    int lent=strlen(t);
    if (lent<lens-n || lent>lens) return -1;
    int count_errors=0;
    for (size_t i = 0; i < lent+count_errors && count_errors<=n; i++){
        char si=*(s+i);
        char ti=*(t+i-count_errors);
        if (si!=ti) count_errors++;
    }
    if(lent+count_errors<lens) count_errors+=lens-count_errors-lent;
    if (count_errors==0) return 0;
    if (count_errors>n) return -1;
    return 1;
}

void print_similar_words(char str[]){
    char line[LINE];
    int len = getLine(line);
    int wordlen = 0;
    for (size_t i = 0; i < len; i += wordlen + 1){
        char current[WORD];
        wordlen = getword(line, current, i);
        current[wordlen] = '\0';
        int simi = similar(current, str, 1);
        if (simi != -1) puts(current);
    }
}

void print_lines(char *str){
    char line[LINE];
    int len = getLine(line);
    char line2[LINE];
    strcpy(line2,line);
    int wordlen = 0;
    for (size_t i = 0; i < len; i += wordlen + 1){
        char current[WORD];
        wordlen = getword(line, current, i);
        current[wordlen] = '\0';
        int sub=substring(current,str);
        if (sub == 1){
            puts(line2);
            return;
        }
    }
}


int main(){



char str2[WORD]={0};
char str[WORD];

scanf("%s",str2);
strcpy(str,str2);
char chuse[1];
scanf("%s",chuse);

if (chuse[0]=='a'){
    for (size_t i = 0; i < 250; i++)
    {
         print_lines(str);
    }
    
   
}else if (chuse[0]=='b'){
       for (size_t i = 0; i < 250; i++){
        print_similar_words(str);
        }
}else{
    printf("eror!");
}
    return 0;
}