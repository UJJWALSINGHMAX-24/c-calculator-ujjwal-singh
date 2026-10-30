// ==========================================
// Project: C Calculator - Level 1 (Single Run)
// Concepts Used: Switch-Case, if-else, printf/scanf, break, default
// Description: Simple basic calculator with 2 numbers.
// Note: Yeh ek baar run hota hai, dobara use karne ke liye code ko re-run karna padta hai.
// ==========================================

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int Num1, Num2;
    int Result;
    char Operator;
    bool IsValid = true;

    printf("----- BASIC CALCULATOR -----\n\n");

    printf("Enter Your First Number : ");
    scanf("%d", &Num1);

    printf("Chose Your Operator [ + , -, * , / ] : ");
    scanf(" %c", &Operator); // Note : %c ke pehle space dena zaroori hai taaki buffer clean rahe

    printf("Enter Your Second Number : ");
    scanf("%d", &Num2);

    switch (Operator)
    {
    case '+':
        Result = Num1 + Num2;
        break;

    case '-':
        Result = Num1 - Num2;
        break;

    case '*':
        Result = Num1 * Num2;
        break;

    case '/':
        if (Num2 != 0)
        {
            Result = Num1 / Num2;
        }
        else
        {
            printf("Error: Division by zero is not allowed!\n");
            IsValid = false;
        }
        break;

    default:
        printf("Error: Invalid operator! Please use +, -, *, or /.\n");
        IsValid = false;
        break;
    }

    if (IsValid)
    {
        printf("\nResult Is : %d %c %d = %d\n\n", Num1, Operator, Num2, Result);
    }

    return 0;
}