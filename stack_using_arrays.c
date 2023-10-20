#include<stdio.h>
#include<stdlib.h>
void push(int n);
void pop();
void display();
int stack[100];
int top=-1;
void main()
{
int n,choice,item;
printf("Enter the size of the stack : \n");
scanf("%d",&n);
while(1)
{
printf("\nChoose the operation you want to perform: 
\n1:push\n2:pop\n3:display\n4:exit\nChoose options(1-4): ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
push(n);
break;
case 2 :
pop();
break;
case 3 :
display();
break;
case 4 : exit(0);
break;
default : printf("WRONG CHOICE !!!");
}
}
}
void push(int n)
{
int item;
printf("Enter the element to be inserted:");
scanf("%d",&item);
if(top>=n-1)
printf("Stack overflow!!!");
else
{
stack[++top]=item;
printf("%d inserted ",item);
}
}
void pop()
{
if(top==-1)
printf("Stack underflow!!!");
else
{
printf("%d deleted ",stack[top]);
top--;
}
}
void display()
{
if(top==-1)
printf("Stack underflow!!!");
else
{
printf("--------------------");
for(int i=top;i>=0;i--)
{
printf("\n %d\n",stack[i]);
}
printf("--------------------");
}
}
