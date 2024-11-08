#include <stdio.h>
#include <stdarg.h>
 
int sum(int count, ...){
    int result = 0;
    va_list factor;
    va_start(factor, count); 
    for(int i = 0; i < count; i++){
        int value = va_arg(factor, int);
        result += value;
    }
    va_end(factor);
    return result;
}

int subtraction(int count, ...) {
    va_list factor;
    va_start(factor, count);

    int resultMinus = va_arg(factor, int);
    
    for (int i = 1; i < count; i++) {
        int value = va_arg(factor, int);
        resultMinus -= value;
    }
    
    va_end(factor);
    return resultMinus;
}

int multiplication(int count, ...){
    int resultMultiplication = 1;
    va_list factor;
    va_start(factor, count);
    for(int i = 0; i < count; i++){
        int value = va_arg(factor, int);
        resultMultiplication *= value;
    }
    va_end(factor);
    return resultMultiplication;
}

double division(int count, ...){
    va_list factor;
    va_start(factor, count);

    double resultDivision = va_arg(factor, double);

    for(int i = 0; i < count - 1; i++){
        double value = va_arg(factor, double);
        resultDivision /= value;
    }

    va_end(factor);
    return resultDivision;
}

typedef struct Operation{
    char name;
    double (*function)(int n, ...);
}Operation;

double work(int expression){
    int count;
    Operation operation[] =
    {
        {"Sum", sum},
        {"Subtraction",subtraction},
        {"Multiplication",multiplication},
        {"Division",division}
    };
    printf("Enter count of numbers: ");
    scanf("%d", &count);
}
 
int main(){   
    int expression, count;
    while (1){
    printf("\n1 - Sum\n2 - Subtaraction\n3 - Multiplication\n4 - Division\nChoose a function: ");
    scanf("%d", &expression);
    if(expression == 1){
        printf("How many numbers you want to sum: ");
        scanf("%d", &count);
        int massive[count];
        if(count == 2){
            printf("Put that numbers: \n");
            for(int i = 0; i < 2; i++){
                printf("Put %d number: ", i + 1);
                scanf("%d", &massive[i]);
            }
            printf("Result: %d", sum(2,massive[0],massive[1]));
        }
            if(count == 3){
                printf("Put that numbers: \n");
                for(int i = 0; i < 3; i++){
                    printf("Put %d number: ", i + 1);
                    scanf("%d", &massive[i]);
                }
                printf("Result: %d", sum(3,massive[0],massive[1],massive[2]));
        }
    }
    if(expression == 2){
        printf("How many numbers you want to subtraction: ");
        scanf("%d", &count);
        int massive[count];
        if(count == 2){
            printf("Put that numbers: \n");
            for(int i = 0; i < 2; i++){
                printf("Put %d number: ", i + 1);
                scanf("%d", &massive[i]);
            }
            printf("Result: %d\n", subtraction(2,massive[0],massive[1]));
        }
            if(count == 3){
                printf("Put that numbers: \n");
                for(int i = 0; i < 3; i++){
                    printf("Put %d number: ", i + 1);
                    scanf("%d", &massive[i]);
                }
                printf("Result: %d\n", subtraction(3,massive[0],massive[1],massive[2]));
        }
    }
    if(expression == 3){
        printf("How many numbers you want to subtraction: ");
        scanf("%d", &count);
        int massive[count];
        if(count == 2){
            printf("Put that numbers: \n");
            for(int i = 0; i < 2; i++){
                printf("Put %d number: ", i + 1);
                scanf("%d", &massive[i]);
            }
            printf("Result: %d\n", multiplication(2,massive[0],massive[1]));
        }
        if(count == 3){
            printf("Put that numbers: \n");
            for(int i = 0; i < 2; i++){
                printf("Put %d number: ", i + 1);
                scanf("%d", &massive[i]);
            }
            printf("Result: %d\n", multiplication(3,massive[0],massive[1],massive[2]));
        }
    }
    if(expression == 4){
        printf("How many numbers you want to division: ");
        scanf("%d", &count);
        double massive[count];
        if(count == 2){
            printf("Put that numbers: \n");
            for(int i = 0; i < 2; i++){
                printf("Put %d number: ", i + 1);
                scanf("%lf", &massive[i]);
            }
            printf("Result: %lf\n", division(2,massive[0],massive[1]));
        }
    }
    }
}