#include<stdio.h>
float bill(float p,int q);
float discount(float total);
float finalBill(float total,float dis);
void receipt(float p1,int q1,float p2,int q2,float t1,float t2,float total,float dis,float fb);
int main()
{
float p1,p2,t1,t2,total,dis,fb;
int q1,q2;
printf("Campus Canteen Billing System\n");
printf("\nEnter price of item 1: ");
scanf("%f",&p1);
printf("Enter quantity of item 1: ");
scanf("%d",&q1);
printf("\nEnter price of item 2: ");
scanf("%f",&p2);
printf("Enter quantity of item 2: ");
scanf("%d",&q2);
if(p1<0||p2<0||q1<0||q2<0)
{
printf("\nInvalid input! Negative values are not allowed\n");
return 1;
}
t1=bill(p1,q1);
t2=bill(p2,q2);
total=t1+t2;
dis=discount(total);
fb=finalBill(total,dis);
receipt(p1,q1,p2,q2,t1,t2,total,dis,fb);
if(p1>p2)
printf("\nItem 1 has a higher price\n");
else if(p2>p1)
printf("\nItem 2 has a higher price\n");
else
printf("\nBoth items have equal prices\n");
return 0;
}
float bill(float p,int q)
{
return p*q;
}
float discount(float total)
{
if(total>1000)
return total*0.10;
return 0;
}
float finalBill(float total,float dis)
{
return total-dis;
}
void receipt(float p1,int q1,float p2,int q2,float t1,float t2,float total,float dis,float fb)
{
printf("\nCUSTOMER RECEIPT\n");
printf("\nItem 1");
printf("\nPrice: Rs %.2f",p1);
printf("\nQuantity: %d",q1);
printf("\nSubtotal: Rs %.2f\n",t1);
printf("\nItem 2");
printf("\nPrice: Rs %.2f",p2);
printf("\nQuantity: %d",q2);
printf("\nSubtotal: Rs %.2f\n",t2);
printf("\nTotal: Rs %.2f",total);
printf("\nDiscount: Rs %.2f",dis);
printf("\nFinal Bill: Rs %.2f",fb);
printf("\nThank you for visiting!\n");
}

