#include<stdio.h>
int total(int a[],int n);
float average(int t,int n);
int highest(int a[],int n);
int lowest(int a[],int n);
int passCount(int a[],int n,int pass);
int topCount(int a[],int n);
void bonus(int a[],int n,int b);
void report(int a[],int n,int pass);
int main()
{
int a[10],n=10,pass,b,i,t;
printf("Examination Cell Marks Analyzer\n");
for(i=0;i<n;i++)
{
printf("Enter marks of student %d: ",i+1);
scanf("%d",&a[i]);
while(a[i]<0||a[i]>100)
{
printf("Invalid marks! Enter marks between 0 and 100: ");
scanf("%d",&a[i]);
}
}
printf("\nEnter passing marks: ");
scanf("%d",&pass);
printf("\nORIGINAL RESULT\n");
report(a,n,pass);
printf("\nEnter bonus marks: ");
scanf("%d",&b);
bonus(a,n,b);
printf("\nRESULT AFTER BONUS\n");
report(a,n,pass);
return 0;
}
int total(int a[],int n)
{
int s=0,i;
for(i=0;i<n;i++)
s=s+a[i];
return s;
}
float average(int t,int n)
{
return (float)t/n;
}
int highest(int a[],int n)
{
int h=a[0],i;
for(i=1;i<n;i++)
{
if(a[i]>h)
h=a[i];
}
return h;
}
int lowest(int a[],int n)
{
int l=a[0],i;
for(i=1;i<n;i++)
{
if(a[i]<l)
l=a[i];
}
return l;
}
int passCount(int a[],int n,int pass)
{
int c=0,i;
for(i=0;i<n;i++)
{
if(a[i]>=pass)
c++;
}
return c;
}
int topCount(int a[],int n)
{
int h=highest(a,n);
int c=0,i;
for(i=0;i<n;i++)
{
if(a[i]==h)
c++;
}
return c;
}
void bonus(int a[],int n,int b)
{
int i;
for(i=0;i<n;i++)
{
a[i]=a[i]+b;
if(a[i]>100)
a[i]=100;
}
}
void report(int a[],int n,int pass)
{
int t;
t=total(a,n);
printf("\nClass Total: %d",t);
printf("\nClass Average: %.2f",average(t,n));
printf("\nHighest Marks: %d",highest(a,n));
printf("\nLowest Marks: %d",lowest(a,n));
printf("\nStudents Passed: %d",passCount(a,n,pass));
printf("\nStudents Sharing Top Marks: %d\n",topCount(a,n));
}

