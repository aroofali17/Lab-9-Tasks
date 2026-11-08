#include<stdio.h>
void wrongSwap(int a,int b);
void swap(int *a,int *b);
void analyze(int *p,int n,int *t,int *h,int *l);
int main()
{
int a,b,x,y,i,t,h,l;
int arr[7];
printf("Hospital Ward Repair Utility\n");
printf("\nEnter Ward A occupancy: ");
scanf("%d",&a);
printf("Enter Ward B occupancy: ");
scanf("%d",&b);
printf("\nBefore swapping:\n");
printf("Ward A: %d | Address: %p\n",a,(void*)&a);
printf("Ward B: %d | Address: %p\n",b,(void*)&b);
swap(&a,&b);
printf("\nAfter swapping:\n");
printf("Ward A: %d | Address: %p\n",a,(void*)&a);
printf("Ward B: %d | Address: %p\n",b,(void*)&b);
printf("\nNORMAL FUNCTION ATTEMPT\n");
printf("Enter value of x: ");
scanf("%d",&x);
printf("Enter value of y: ");
scanf("%d",&y);
printf("\nBefore function call:\n");
printf("x = %d | Address: %p\n",x,(void*)&x);
printf("y = %d | Address: %p\n",y,(void*)&y);
wrongSwap(x,y);
printf("\nAfter function call:\n");
printf("x = %d | Address: %p\n",x,(void*)&x);
printf("y = %d | Address: %p\n",y,(void*)&y);
printf("\nWEEKLY WARD OCCUPANCY\n");
for(i=0;i<7;i++)
{
printf("Enter occupancy for day %d: ",i+1);
scanf("%d",&arr[i]);
}
analyze(arr,7,&t,&h,&l);
printf("\nWeekly Total: %d\n",t);
printf("Highest Occupancy: %d\n",h);
printf("Lowest Occupancy: %d\n",l);
return 0;
}
void wrongSwap(int a,int b)
{
int temp;
printf("\nInside normal function:\n");
printf("a = %d | Address: %p\n",a,(void*)&a);
printf("b = %d | Address: %p\n",b,(void*)&b);
temp=a;
a=b;
b=temp;
printf("After swapping inside function:\n");
printf("a = %d\n",a);
printf("b = %d\n",b);
}
void swap(int *a,int *b)
{
int temp;
printf("\nInside pointer function:\n");
printf("Address of a: %p\n",(void*)a);
printf("Address of b: %p\n",(void*)b);
temp=*a;
*a=*b;
*b=temp;
}
void analyze(int *p,int n,int *t,int *h,int *l)
{
int i;
*t=0;
*h=*p;
*l=*p;
printf("\nInside analysis function:\n");
printf("Array address: %p\n",(void*)p);
printf("Total address: %p\n",(void*)t);
for(i=0;i<n;i++)
{
*t=*t+*(p+i);
if(*(p+i)>*h)
*h=*(p+i);
if(*(p+i)<*l)
*l=*(p+i);
}
}

