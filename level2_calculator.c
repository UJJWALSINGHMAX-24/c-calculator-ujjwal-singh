#include <stdio.h>
#include <stdbool.h>

double AddRule(double a, double b)
{
    return a + b;
}

double SubtractRule(double a, double b)
{
    return a - b;
}

double MultiplyRule(double a, double b)
{
    return a * b;
}

double DivideRule(double a, double b)
{
    return a / b;
}

int main()
{
    bool RunCalculator = true;
    char Option;
    double Num1, Num2;
    double Result = 0;

    while (RunCalculator)
    {
        printf("\n--- CALCULATOR ---\n\n");
        printf("Run Calculator > ( 1 - On )\n");
        printf("Quit Calculator > ( 0 - Off )\n");
        printf("\nYour Option : ");
        scanf(" %c", &Option);

        switch (Option)
        {
        case '0':
            RunCalculator = false;
            printf("\n- Calculator Quit -\n\n");
            break;
        case '1':
            printf("\nCalculator On\n\n");
            break;
        default:
            printf("Invalid Option! Please enter 0 or 1.\n");
            continue;
        }

        if (!RunCalculator)
        {
            break;
        }

        printf("Enter Your First Number : ");
        scanf("%lf", &Num1);

        printf("Choose an Operator { + , - , * , / } : ");
        scanf(" %c", &Option);

        printf("Enter Your Second Number : ");
        scanf("%lf", &Num2);

        if (Option == '+')
        {
            Result = AddRule(Num1, Num2);
        }
        else if (Option == '-')
        {
            Result = SubtractRule(Num1, Num2);
        }
        else if (Option == '*')
        {
            Result = MultiplyRule(Num1, Num2);
        }
        else if (Option == '/')
        {
            if (Num2 == 0)
            {
                printf("\nError : Zero Divide Nhi Kiya Ja Sakta.\n");
                continue;
            }
            Result = DivideRule(Num1, Num2);
        }
        else
        {
            printf("Invalid Operator !\n");
            continue;
        }

        printf("\nResult Is : %.2lf %c %.2lf = %.2lf\n", Num1, Option, Num2, Result);
    }

    return 0;
}