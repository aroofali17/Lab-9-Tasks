#include<stdio.h>
void print(void *p,char t);
int add(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int divi(int a,int b);
int calculate(int a,int b,int (*op)(int,int));
int main()
{
int a,b,ch,res;
int x=100;
float y=45.67;
char z='A';
int (*op[4])(int,int)={add,sub,mul,divi};
printf("Smart Calculator\n");
printf("\nGENERIC DATA PRINTER\n");
print(&x,'i');
print(&y,'f');
print(&z,'c');
printf("\nCALCULATOR\n");
printf("Enter first number: ");
scanf("%d",&a);
printf("Enter second number: ");
scanf("%d",&b);
printf("\n1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("Enter your choice: ");
scanf("%d",&ch);
if(ch<1||ch>4)
{
printf("\nInvalid choice\n");
return 0;
}
if(ch==4&&b==0)
{
printf("\nError! Division by zero is not allowed\n");
return 0;
}
res=calculate(a,b,op[ch-1]);
printf("\nResult: %d\n",res);
return 0;
}
void print(void *p,char t)
{
if(t=='i')
printf("Integer: %d\n",*(int*)p);
else if(t=='f')
printf("Float: %.2f\n",*(float*)p);
else if(t=='c')
printf("Character: %c\n",*(char*)p);
}
int add(int a,int b)
{
return a+b;
}
int sub(int a,int b)
{
return a-b;
}
int mul(int a,int b)
{
return a*b;
}
int divi(int a,int b)
{
return a/b;
}
int calculate(int a,int b,int (*op)(int,int))
{
return op(a,b);
}

