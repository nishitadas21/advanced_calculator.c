#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Entry point of the program
int main() {
    double num1, num2, result;
    char op, choice;
    FILE *fp;

    do {
        // Display menu
        printf("\n==== ADVANCED CALCULATOR ====\n");
        printf("Select an operation from the list below:\n");
        printf(" +  → Addition\n");
        printf(" -  → Subtraction\n");
        printf(" *  → Multiplication\n");
        printf(" /  → Division\n");
        printf(" %%  → Modulus (only for integers)\n");
        printf(" ^  → Power (x^y)\n");
        printf(" r  → Square Root\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &op);  // Notice the space before %c to consume newline

        // Handle square root separately
        if (op == 'r') {
            printf("Enter number: ");
            scanf("%lf", &num1);

            if (num1 < 0) {
                printf("Error: Cannot calculate square root of a negative number.\n");
                continue;
            }

            result = sqrt(num1);
            printf("Result: √%.2lf = %.2lf\n", num1, result);

            // Log the result to a file
            fp = fopen("history.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "√%.2lf = %.2lf\n", num1, result);
                fclose(fp);
            }

        } else {
            // For other operations
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);

            switch(op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Division by zero is not allowed.\n");
                        continue;
                    }
                    result = num1 / num2;
                    break;
                case '%':
                    if ((int)num2 == 0) {
                        printf("Error: Modulus by zero is not allowed.\n");
                        continue;
                    }
                    result = (int)num1 % (int)num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
                default:
                    printf("Error: Invalid operator '%c'\n", op);
                    continue;
            }

            printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);

            // Log the operation to history file
            fp = fopen("history.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
                fclose(fp);
            }
        }

        // Ask user whether they want to continue
        printf("\nWould you like to perform another operation? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nThank you for using the calculator.\n");
    printf("You can check 'history.txt' for your saved calculations.\n");

    return 0;
}
