include <stdlib.h>
include <stdio.h>

int main(int argc, char *argv[]){
    int num1,num2,temp;
    scanf("%d",&num1);
    scanf("%d",&num2);
    while(num1 % num2 != 0){
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    printf("%d",num2);
    return 0;
}