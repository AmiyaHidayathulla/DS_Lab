#include<stdio.h>
#include<stdlib.h>
struct Node
{
int coeff;
int pow;
struct Node* next;
};
void readpoly( struct Node** poly)
{
int coeff,exp,cont;
struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
*poly = temp;
printf("\nEnter the number of terms: ");
int no;
scanf("%d",&no);
int i=0;
while(i<no)
{
printf("Enter the coefficient: ");
scanf("%d",&coeff);
printf("Enter the exponent: ");
scanf("%d",&exp);
temp->coeff= coeff;
temp->pow= exp;
temp->next= NULL;
if(i==no-1)
break;

temp->next=(struct Node*)malloc(sizeof(struct Node));
temp=temp->next;
temp->next=NULL;
i++;
}
}
void displaypoly(struct Node*poly)
{
while (poly!=NULL)
{
if(poly->coeff!=0)
{
if(poly->pow!=0)
printf(" %d(x^%d)",poly->coeff,poly->pow);
else
printf(" %d",poly->coeff);
}
poly=poly->next;
if(poly!=NULL)
{
if(poly->coeff>0)
printf(" +");
}
}
}
void addpoly(struct Node** result, struct Node*first,struct Node*second )
{
struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
temp->next=NULL;

*result=temp;
while(first)
{
temp->next=(struct Node*)malloc(sizeof(struct Node));
temp->coeff=first->coeff;
temp->pow = first->pow;
first = first->next;
temp=temp->next;
}
temp=*result;
while(second)
{
temp=*result;
while(temp)
{
if(temp->pow == second->pow)
{
temp->coeff += second->coeff;
break;
}
temp=temp->next;
}
if(temp==NULL)
{
temp=(struct Node*)malloc(sizeof(struct Node));
temp->pow = second->pow;
temp->coeff = second->coeff;
}
second=second->next;

}
}
void orderpoly(struct Node*ptr)
{
struct Node*i,*j;
ptr=ptr->next;
i=ptr;
j=ptr;
int tempc, tempe;
while(i->next!=NULL)
{
j=ptr;
while(j->next!=NULL)
{
if(j->pow<j->next->pow)
{
tempc=j->coeff;
tempe=j->pow;
j->coeff=j->next->coeff;
j->pow=j->next->pow;
j->next->coeff=tempc;
j->next->pow=tempe;
}
j=j->next;
}
i=i->next;
}
}
int main()

{
struct Node*first= NULL;
struct Node*second= NULL;
struct Node*result= NULL;
printf("\n Polynomial 1");
readpoly(&first);
printf("\nPolynomial 2");
readpoly(&second);
addpoly(&result,first,second);
orderpoly(first);
printf("\nFirst Polynomial expression:");
displaypoly(first);
orderpoly(second);
printf("\nSecond Polynomial expression:");
displaypoly(second);
orderpoly(result);
printf("\nResultant Polynomial expression:");
displaypoly(result);
printf("\n");
return 0;
}
