#include <stdio.h>
#include <math.h>

void PrintBill(float units, float costPerUnit[5], float extraCharge, char firstName[100], char lastName[100]) {
    float totalCost = 0.0, sum = 0.0;
    int unitRanges[8] = {1, 50, 51, 100, 101, 200, 201, 300};

    // Calculate total cost based on unit ranges and cost per unit
    for (int i = 0; i < 5; ++i) {
        int lowerBound = unitRanges[2 * i];
        int upperBound = unitRanges[2 * i + 1];

        if (units <= upperBound) {
            float usedUnits = fminf(units, upperBound) - lowerBound + 1;
            sum += usedUnits * costPerUnit[i];
            break;
        } else {
            sum += (upperBound - lowerBound + 1) * costPerUnit[i];
            units -= (upperBound - lowerBound + 1);
        }
    }

    totalCost = sum + (sum * extraCharge);

    printf("\n\n******************Hi %s %s*********************\n\n", firstName, lastName);
    printf("******Your Electricity Bill*********\n\n");

    printf("  Unit Range  %15s\n", "Cost");
    for (int i = 0; i < 5; ++i) {
        printf("%9d - %4d", unitRanges[2 * i], unitRanges[2 * i + 1]);
        if (i != 0 && i != 4) {
            printf("%15.2f\n", costPerUnit[i]);
        } else {
            printf("%16.2f\n", costPerUnit[i]);
        }
    }

    printf("\nSum                       = %.2f\n", sum);
    printf("Collecting Extra Charge of %.2f on total amount of %.2f\n", extraCharge, sum);
    printf("\nTotal Amount Costed        = %.2f\n", totalCost);
}

int main() {
    int choice;
    float units, extraCharge;
    char firstName[100], lastName[100];
    int unitRanges[8] = {1, 50, 51, 100, 101, 200, 201, 300};

    printf("Enter\n1. To Calculate electricity of your own custom values\n2. To use Predefined values\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            float costPerUnit[5];

            printf("Enter First Name\n");
            scanf("%s", firstName);

            printf("Enter Last Name\n");
            scanf("%s", lastName);

            for (int i = 0; i < 5; ++i) {
                printf("Enter Cost/Unit for %d - %d units\n", unitRanges[2 * i], unitRanges[2 * i + 1]);
                scanf("%f", &costPerUnit[i]);
            }

            printf("Enter Extra Charge\n");
            scanf("%f", &extraCharge);

            printf("Enter Total Number of Units used/consumed\n");
            scanf("%f", &units);

            PrintBill(units, costPerUnit, extraCharge, firstName, lastName);
            break;
        }
        case 2: {
            float costPerUnit[5] = {1.2, 3, 3.3, 4.1, 5.2};
            extraCharge = 3.5;

            printf("Enter First Name\n");
            scanf("%s", firstName);

            printf("Enter Last Name\n");
            scanf("%s", lastName);

            printf("Enter Total Number of Units used/consumed\n");
            scanf("%f", &units);

            PrintBill(units, costPerUnit, extraCharge, firstName, lastName);
            break;
        }
        default:
            printf("Enter Valid Choice\n");
    }

    return 0;
}
