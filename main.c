#include<stdio.h>
void main()
{

 int a,b,c;
 char ch;
 scanf("%d",&a);
 scanf("%d",&b);
 fflush(stdin);
 printf("Enter choice : ");
 scanf("%c",&ch);


switch(ch){
case '+':
    return c= a+b;
    break;
case '-':
    return c= a-b;
    break;
case '*':
    return c= a*b;
    break;
case '/':
    return c= a/b;
    break;
default:
    break;
}
}

