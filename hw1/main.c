#include"myMath.h"
#include<stdio.h>

int main(){
double x;
char ch;
printf("Please inset a real number: \n");
while(scanf("%lf",&x)!=1){  
    scanf("%c",&ch);
}

float a=add(Exponent(x),Power(x,3));
a=sub(a,2);
printf("The value of f(𝑥) = 𝑒^𝑥 + 𝑥^3 − 2 at the point %0.4lf is: %0.4lf\n",x,a);

float b_a=mul(x,3);              
float b_b=mul(Power(x,2),2);     
float b=add(b_a,b_b);


 printf("The value of f(𝑥) = 3𝑥 + 2𝑥^2 at the point %0.4lf is: %0.4lf\n" ,x, b);



float c_a = mul(Power(x,3),4);
c_a = div(c_a,5);
float c_b = mul(x,2);
float c=sub(c_a,c_b); 


 printf("The value of f(𝑥) = (4x^3)/5 -2x  at the point %0.4lf is: %0.4lf\n",x,c);



return 0;
}
