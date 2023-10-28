#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start;
void insert_begin();
void insert_end();
void insert_loc();
void delete_begin();
void delete_end();
void delete_loc();
void display();
void main()
{
int ch;
while(1)
{
printf("\nEnter the operation to be performed : \n");
printf("1.Insert at beginning\n2.Insert at the end\n3.Insert at a particular location\n4.delete from beginning\n5.delete from end\n6.delete from a particular location\n7.display\n8.exit\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1 : insert_begin();
break;

case 2 : insert_end();
break;
case 3 : insert_loc();
break;
case 4 : delete_begin();
break;
case 5 : delete_end();
break;
case 6 : delete_loc();
break;
case 7 : display();
break;
case 8 : printf("Exited!!!");
exit(0);
break;
default : printf("Wrong choice!!!");
break;
}
}
}
void insert_begin()
{
struct node *p;
int value;
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the value : ");
scanf("%d",&value);
p->data=value;
if(start==NULL)

{
p->next=NULL;
start=p;
}
else
{
p->next=start;
start=p;
}
printf("%d is Inserted",value);
}
void insert_end()
{
int value;
struct node *p,*temp;
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the value : ");
scanf("%d",&value);
p->data=value;
if(start==NULL)
{
p->next=NULL;
start=p;
}
else
{
temp=start;
while(temp->next!=NULL)
temp=temp->next;

temp->next=p;
p->next=NULL;
}
printf("%d is Inserted",value);
}
void insert_loc()
{
int value,loc,i;
struct node *p,*temp;
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the location : ");
scanf("%d",&loc);
temp=start;
if(loc>=1&&start==NULL)
{
insert_begin();
}
else
{
printf("Enter the value : ");
scanf("%d",&value);
p->data=value;
for(i=1;i<(loc-1);i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("Cannot insert at position!!!");
return;

}
}
p->next=temp->next;
temp->next=p;
printf("%d is Inserted",value);
}
}
void delete_begin()
{
struct node *p;
if(start==NULL)
{
printf("Nothing to delete!!!");
return;
}
else
{
p=start;
start=start->next;
printf("%d is Deleted",p->data);
free(p);
}
}
void delete_end()
{
struct node *p,*temp;
if(start==NULL)
{
printf("Nothing to delete!!!");

return;
}
else if(start->next==NULL)
{
p=start;
start=NULL;
printf("%d is Deleted",p->data);
free(p);
}
else
{
p=start;
temp=start->next;
while(temp->next!=NULL)
{
p=temp;
temp=temp->next;
}
p->next=NULL;
printf("%d is deleted",temp->data);
free(temp);
}
}
void delete_loc()
{
struct node *p,*temp;
int loc,i;
if(start==NULL)
{

printf("Nothing to delete!!!");
return;
}
printf("Enter the location : ");
scanf("%d",&loc);
temp=start;
p=start;
i=1;
while(i<loc-1&&temp!=NULL)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Search fails!!!");
}
else if(temp->next==NULL)
{
start=NULL;
printf("%d is Deleted",temp->data);
free(temp);
}
else if(loc==1)
{
delete_begin();
}
else
{
p=temp->next;

temp->next=p->next;
printf("%d is Deleted",p->data);
free(p);
}
}
void display()
{
struct node *p;
if(start==NULL)
{
printf("Linked List Empty");
return;
}
else
{
p=start;
while(p->next!=NULL)
{
printf("%d\t",p->data);
p=p->next;
}
printf("%d\t",p->data);
}
}






OUTPUT
