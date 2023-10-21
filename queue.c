#include<stdio.h>
#include<stdlib.h>
void enqueue(int n);
void dequeue();
void display();
int queue[100];
int rear=-1;
int front=-1;
void main()
{
int choice,item,n;
printf("Enter the size of the Queue : \n");
scanf("%d",&n);
while(1)
{
printf("\nChoose the operation you want to 
perform1:\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1 : enqueue(n);
break;
case 2 : dequeue();
break;
case 3 : display();
break;
case 4 :
printf("Exited");
exit(0);
break;
default : printf("WRONG CHOICE!!!");
break;
}
}
}
void enqueue(int n)
{
int item;
printf("Enter the item to be inserted : \n");
scanf("%d",&item);
if(rear==(n-1))
printf("Queue Overflow!!!");
else
{
if(rear==-1)
{
front=0;
rear=0;
}
else
{
rear++;
}
queue[rear]=item;
printf("%d is inserted",item);
}
}
void dequeue()
{
int item;
if(rear==-1)
printf("Queue underflow!!!\n");
else if(front==rear)
{
item=queue[front];
front=-1;
rear=-1;
printf("%d is Deleted ",item);
}
else
{
item=queue[front];
front++;
printf("%d is Deleted ",item);
}
}
void display()
{
if(rear==-1)
{
printf("Queue Underflow!!!\n");
}
else
{
printf("--------QUEUE--------\n");
for(int i=front;i<=rear;i++)
{
printf("%d ",queue[i]);
}
printf("\n----------------------\n");
}
}
