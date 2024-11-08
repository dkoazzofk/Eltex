#include <stdio.h>
#include <stdarg.h>

#define MAX_CHARLENGHT 128
 
double sum(int count, ...){
    double result = 0;
    va_list factor;
    va_start(factor, count); 
    for(int i = 0; i < count; i++){
        double value = va_arg(factor, double);
        result += value;
    }
    va_end(factor);
    return result;
}

double subtraction(int count, ...) {
    va_list factor;
    va_start(factor, count);

    double resultMinus = va_arg(factor, double);
    
    for (int i = 1; i < count; i++) {
        double value = va_arg(factor, double);
        resultMinus -= value;
    }
    
    va_end(factor);
    return resultMinus;
}

double multiplication(int count, ...){
    double resultMultiplication = 1;
    va_list factor;
    va_start(factor, count);
    for(int i = 0; i < count; i++){
        double value = va_arg(factor, double);
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
    char name[MAX_CHARLENGHT];
    double (*function)(int n, ...);
}Operation;

double work(int choice) {
    int count;
    Operation operation[] = {
        {"Sum", sum},
        {"Subtraction", subtraction},
        {"Multiplication", multiplication},
        {"Division", division}
    };
    
    printf("Enter count of numbers: ");
    scanf("%d", &count);

    double numbers[count];
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
    }
    double result = operation[choice - 1].function(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    
    return result;
}

int main()
{
    int choice=0;
    while (choice!=5)
    {
        printf("------------------------------------------\n");
        printf("Choose operation:\n");
        printf("1.Sum\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n");
        scanf("%d", &choice);
        printf("------------------------------------------\n");
        getchar();
        if (choice >= 1 && choice <= 4) 
        {
            double result = work(choice);
            printf("%lf\n",result);
        }
        else if (choice != 5)
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}