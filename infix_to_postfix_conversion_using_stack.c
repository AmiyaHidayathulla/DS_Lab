#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int stack[100];
int top=-1;
void push(char x);
char pop();
int priority(char x);
void main()
{
char c;
char exp[100];
printf("Enter the infix expression : \n");
scanf("%s",exp);
char *e;
e=exp;
printf("Postfix expression of the given expression is:\n");
while(*e!='\0')
{
if(isalnum(*e))
{
printf("%c",*e);
}
else if(*e=='(')
{
push(*e);
}



else if(*e==')')
{
while((c=pop())!='(')
{
printf("%c",c);
}
}
else
{
while(priority(stack[top])>=priority(*e))
{
if(*e=='^')
break;
printf("%c",pop());
}
push(*e);
}
e++;
}
while(top != -1)
{
printf("%c ",pop());
}
}
void push(char x)
{
stack[++top]=x;
}
char pop()



{
if(top==-1)
return -1;
else
{
return stack[top--];
}
}
int priority(char x)
{
if(x=='(')
return 0;
else if(x=='+'||x=='-')
return 1;
else if(x=='*'||x=='/')
return 2;
else if(x=='^')
return 3;
else
return 0;
}
