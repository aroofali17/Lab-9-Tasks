#include<stdio.h>
int total(float *p,int n);
int highest(float *p,int n);
void display(float *p,int n);
void adjustment(float *p,int n,float th);
int main()
{
float a[7],th;
float *p,*m=NULL;
int i;
printf("Smart Meter Memory Inspector\n");
p=a;
for(i=0;i<7;i++)
{
printf("Enter units for day %d: ",i+1);
scanf("%f",p+i);
}
printf("\nEnter peak tariff threshold: ");
scanf("%f",&th);
printf("\nMEMORY DETAILS\n");
display(p,7);
printf("\nAddress difference between consecutive readings:\n");
for(i=0;i<6;i++)
{
printf("Day %d to Day %d: %d bytes\n",i+1,i+2,(int)((char*)(p+i+1)-(char*)(p+i)));
}
printf("\nEach reading is stored in a separate memory location\n");
printf("The address difference is %lu bytes because a float occupies %lu bytes\n",(unsigned long)sizeof(float),(unsigned long)sizeof(float));
printf("\nWeekly Total: %.2f\n",total(p,7));
printf("Highest Consumption: Day %d\n",highest(p,7));
adjustment(p,7,th);
printf("\nAFTER PEAK ADJUSTMENT\n");
display(p,7);
printf("\nUpdated Weekly Total: %.2f\n",total(p,7));
printf("\nLINKED METER\n");
if(m==NULL)
printf("Linked meter is not assigned\n");
else
printf("Linked meter reading: %.2f\n",*m);
m=p+2;
if(m==NULL)
printf("Linked meter is not assigned\n");
else
printf("Linked meter reading: %.2f\n",*m);
return 0;
}
void display(float *p,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("Day %d: %.2f | Address: %p\n",i+1,*(p+i),(void*)(p+i));
}
}
int total(float *p,int n)
{
int i;
float s=0;
for(i=0;i<n;i++)
s=s+*(p+i);
return s;
}
int highest(float *p,int n)
{
int i,d=1;
float h=*p;
for(i=1;i<n;i++)
{
if(*(p+i)>h)
{
h=*(p+i);
d=i+1;
}
}
return d;
}
void adjustment(float *p,int n,float th)
{
int i;
for(i=0;i<n;i++)
{
if(*(p+i)>th)
*(p+i)=*(p+i)*2;
}
}

