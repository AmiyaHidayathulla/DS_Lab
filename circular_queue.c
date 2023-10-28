#include<stdio.h>
#include<stdlib.h>
void Enqueue();
void Dequeue();
void display();
int queue[100];
int front=-1;
int rear=-1;
int n,item;
void main()
{
int choice;
printf("Enter the size of the Circular Queue : ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
queue[i]='a';
}
while(1)
{
printf("Choose the operation you want to perform:\nSelect from 1-4 :\n1:Enqueue\n2:Dequeue\n3:display\n4:exit\nSelect option:");
scanf("%d",&choice);
switch(choice)
{
case 1 : Enqueue();
break;
case 2 : Dequeue();
break;

case 3 : display();
break;
case 4 : printf("Exited");
exit(0);
break;
default : printf("WRONG CHOICE!!!");
break;
}
}
}
void Enqueue()
{
printf("Enter the item to be inserted (Zero is not allowed) : ");
scanf("%d",&item);
if(front==(rear+1)%n)
{
printf("Circular queue Overflow!!!");
}
else
{
if(front==-1)
{
front=0;
rear=0;
}
else
{
rear=(rear+1)%n;
}
queue[rear]=item;


printf("%d is Inserted\n",item);
}
}
void Dequeue()
{
if(front==-1)
{
printf("Circular Queue Underflow!!!");
}
else
{
printf("%d is deleted\n",queue[front]);
queue[front]='\0';
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=(front+1)%n;
}

}
}
void display()
{
if(front==-1)
{
printf("Circular queue Underflow!!!");


}
else
{
int i;
printf("-------Circular Queue-------\n");
for(i=0;i<n;i++)
{
if(queue[i]!='\0')
printf("%d\t",queue[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
if(queue[i]!='\0')
{
if(i==front)
printf("front");
if(i==rear)
printf("rear");
if(i!=front||i!=rear)
printf("\t");
}
}
printf("\nfront=%d rear=%d ",front,rear);
printf("\n-----------------------------\n");
}
}

