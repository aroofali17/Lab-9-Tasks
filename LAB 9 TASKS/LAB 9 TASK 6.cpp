#include <stdio.h>
double add(int x,int y){
    return x+y;
}
double sub(int x,int y){
    return x-y;
}
double multiply(int x,int y){
    return x*y;
}
double div(int x,int y){
    return (double)x/y;
}
double calculate(int x,int y,double (*operation)(int,int)){
    return operation(x,y);
}
int main(){
    int a=25;
    float b=5.55;
    char c='X';
    void *ptr;
    ptr=&a;
    printf("Integer Value: %d\n",*(int*)ptr);
    ptr=&b;
    printf("Decimal Value: %.2f\n",*(float*)ptr);
    ptr=&c;
    printf("Character Value: %c\n",*(char*)ptr);
    int x,y;
    printf("\nEnter number 1: ");
    scanf("%d",&x);
    printf("Enter number 2: ");
    scanf("%d",&y);
    double (*operations[4])(int,int)={add,sub,multiply,div};
    printf("\n0. Addition");
    printf("\n1. Subtraction");
    printf("\n2. Multiplication");
    printf("\n3. Division");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    if(choice<0 || choice>3){
        printf("Invalid choice!");
    }
    else if(choice==3 && y==0){
        printf("Error: Division by zero is not allowed.");
    }
    else{
        printf("Result: %.2f",calculate(x,y,operations[choice]));
    }
    return 0;
}
