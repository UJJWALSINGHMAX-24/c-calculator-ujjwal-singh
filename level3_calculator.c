#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double AllResult = 0.0;

double AddLaw(double a, double b)
{
    AllResult = a + b;
    return AllResult;
}

double SubtractLaw(double a, double b)
{
    AllResult = a - b;
    return AllResult;
}

double MultiplyLaw(double a, double b)
{
    AllResult = a * b;
    return AllResult;
}

double DivideLaw(double a, double b)
{
    if (b == 0)
    {
        printf("\n[!] Error : Zero se divide nahi kiya ja sakta!\n");
        return 0;
    }
    AllResult = a / b;
    return AllResult;
}

void ShowHistory(char **AllHistory, int AllCount)
{
    printf("\n-----------------------------\n");
    printf(" >>> AUTO-DYNAMIC HISTORY <<<\n");
    printf("-----------------------------\n");

    if (AllCount == 0)
    {
        printf("No History Available \n");
    }
    else
    {
        for (int a = 0; a < AllCount; a++)
        {
            printf("[ %d ] %s \n", a + 1, AllHistory[a]);
        }
    }
    printf("-----------------------------\n");
}

int main()
{
    char **AllHistory = NULL;
    int History_Count = 0;
    int History_Capacity = 0;
    int Calc_On_Off = 1;

    printf("\n-------------------------------\n");
    printf("     >>> SMART CALCULATOR <<<   \n\n");
    printf("Calculator On > Press ( 1 )\n");
    printf("All History > Press ( 2 )\n");
    printf("Cleared Memory > Press ( 3 )\n");
    printf("Calculator Off > Press ( 0 )\n\n");

    while (Calc_On_Off)
    {
        int MenuChoice;
        double Num1, Num2;
        char AllRecord[100];
        char UserOperator;

        printf("Choose Your Option > Press Enter : ");
        scanf("%d", &MenuChoice);

        if (MenuChoice == 1)
        {
            printf("\nCALCULATOR ON\n\n");

            printf("Enter Your First Number : ");
            scanf("%lf", &Num1);

            printf("Choose an Operator { + , - , * , / } : ");
            scanf(" %c", &UserOperator);

            printf("Enter Your Second Number : ");
            scanf("%lf", &Num2);

            if (UserOperator == '+')
            {
                AddLaw(Num1, Num2);
                snprintf(AllRecord, sizeof(AllRecord), "%.2lf + %.2lf = %.2lf", Num1, Num2, AllResult);
            }
            else if (UserOperator == '-')
            {
                SubtractLaw(Num1, Num2);
                snprintf(AllRecord, sizeof(AllRecord), "%.2lf - %.2lf = %.2lf", Num1, Num2, AllResult);
            }
            else if (UserOperator == '*')
            {
                MultiplyLaw(Num1, Num2);
                snprintf(AllRecord, sizeof(AllRecord), "%.2lf * %.2lf = %.2lf", Num1, Num2, AllResult);
            }
            else if (UserOperator == '/')
            {
                if (Num2 == 0)
                {
                    DivideLaw(Num1, Num2);
                    continue;
                }
                DivideLaw(Num1, Num2);
                snprintf(AllRecord, sizeof(AllRecord), "%.2lf / %.2lf = %.2lf", Num1, Num2, AllResult);
            }
            else
            {
                printf("Choose Invalid Operator ? \n");
                continue;
            }

            if (History_Count >= History_Capacity)
            {
                History_Capacity = (History_Capacity == 0) ? 2 : History_Capacity * 2;
                char **temp = realloc(AllHistory, History_Capacity * sizeof(char *));
                if (temp != NULL)
                {
                    AllHistory = temp;
                }
            }

            AllHistory[History_Count] = malloc(strlen(AllRecord) + 1);
            strcpy(AllHistory[History_Count], AllRecord);
            History_Count++;

            printf("Result Is : %.2lf %c %.2lf = %.2lf\n\n", Num1, UserOperator, Num2, AllResult);
        }
        else if (MenuChoice == 2)
        {
            ShowHistory(AllHistory, History_Count);
        }
        else if (MenuChoice == 3)
        {
            for (int i = 0; i < History_Count; i++)
            {
                free(AllHistory[i]);
            }
            free(AllHistory);
            AllHistory = NULL;
            History_Count = 0;
            History_Capacity = 0;

            printf("\nAll Memory Successfully Cleared.\n\n");
        }
        else if (MenuChoice == 0)
        {
            for (int i = 0; i < History_Count; i++)
            {
                free(AllHistory[i]);
            }
            free(AllHistory);

            printf("\nCalculator OFF \n\n");
            Calc_On_Off = 0;
        }
        else
        {
            printf("\nInvalid Choice! Please choose 1, 2, 3 or 0.\n\n");
        }
    }

    return 0;
}