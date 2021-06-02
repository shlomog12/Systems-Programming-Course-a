
#define lengs 50
#include<stdio.h>


void printarr(int arr[],int len){              
for (size_t i = 0; i < len-1; i++){
  printf("%d,",arr[i]);
}
 printf("%d",arr[len-1]);
}


void shift_element(int* arr, int i){    
for (size_t j = i; j > 0; j--){
    *(arr+j)=*(arr+j-1);
}
}



void insertion_sort(int*arr , int len){
    for (size_t i = 1; i < len; i++){                          
        int current=*(arr+i);           
        for (size_t j = 0; j <i; j++){                       
            int *p=arr+j;                       
            if (*p>=current){
               shift_element(p,i-j); 
               *(arr+j)=current;
               break;
            }
        } 
    }
    

}


int main(){

int arr[lengs];
for (size_t i = 0; i < lengs; i++){
    scanf("%d",arr+i);
}
insertion_sort(arr,lengs);

printarr(arr,lengs);

    return 0;
}