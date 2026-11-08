#include<stdio.h>
void hall1(int (*p)[4],int r);
void hall2(int *p[],int n[]);
int vacant1(int (*p)[4],int r);
int vacant2(int *p[],int n[]);
void booking(int *p[],int n[]);
int main()
{
int a[3][4]={{1,0,1,0},{0,1,0,1},{1,0,0,1}};
int r1[3]={1,0,1};
int r2[5]={0,1,0,1,0};
int r3[7]={1,0,0,1,0,1,0};
int *p[3]={r1,r2,r3};
int n[3]={3,5,7};
printf("Cinema Seating Manager\n");
printf("\nHALL 1\n");
hall1(a,3);
printf("Vacant Seats: %d\n",vacant1(a,3));
printf("\nHALL 2\n");
hall2(p,n);
printf("Vacant Seats: %d\n",vacant2(p,n));
booking(p,n);
printf("\nUPDATED HALL 2\n");
hall2(p,n);
printf("Vacant Seats: %d\n",vacant2(p,n));
return 0;
}
void hall1(int (*p)[4],int r)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<4;j++)
{
if(*(*(p+i)+j)==1)
printf("B ");
else
printf("V ");
}
printf("\n");
}
}
int vacant1(int (*p)[4],int r)
{
int i,j,c=0;
for(i=0;i<r;i++)
{
for(j=0;j<4;j++)
{
if(*(*(p+i)+j)==0)
c++;
}
}
return c;
}
void hall2(int *p[],int n[])
{
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<n[i];j++)
{
if(*(*(p+i)+j)==1)
printf("B ");
else
printf("V ");
}
printf("\n");
}
}
int vacant2(int *p[],int n[])
{
int i,j,c=0;
for(i=0;i<3;i++)
{
for(j=0;j<n[i];j++)
{
if(*(*(p+i)+j)==0)
c++;
}
}
return c;
}
void booking(int *p[],int n[])
{
int r,s;
printf("\nBOOK A SEAT\n");
printf("Enter row number (1-3): ");
scanf("%d",&r);
if(r<1||r>3)
{
printf("Invalid row number\n");
return;
}
printf("Enter seat number (1-%d): ",n[r-1]);
scanf("%d",&s);
if(s<1||s>n[r-1])
{
printf("Invalid seat number\n");
return;
}
if(*(*(p+r-1)+s-1)==1)
{
printf("This seat is already booked\n");
return;
}
*(*(p+r-1)+s-1)=1;
printf("Seat booked successfully\n");
}

