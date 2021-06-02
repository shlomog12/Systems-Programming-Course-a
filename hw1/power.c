#include<stdio.h>


#define EXP 2.718281828


double Power(double x , int y){
    int argo= (y<0)? -y :y;
    double ans=1;
    for ( int i = 0; i < argo; i++){
        ans*=x;
    }
    if (argo==-y){
        ans=1/ans;
    }
    return ans;  
}


double Exponent(int x) {
return Power(EXP,x);
}