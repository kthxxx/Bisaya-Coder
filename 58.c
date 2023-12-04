#include <stdio.h>

// Constants for parking rates
#define CAR_RATE_FIRST_3_HR 0.00
#define CAR_RATE_AFTER_3_HR 1.50
#define TRUCK_RATE_FIRST_2_HR 1.00
#define TRUCK_RATE_AFTER_2_HR 2.30
#define BUS_RATE_FIRST_HR 2.00
#define BUS_RATE_AFTER_FIRST_HR 3.70

// Function declarations
void inputDetails(char *vType, int *eHr, int *eMin, int *xHr, int *xMin);
void calculateDuration(int eHr, int eMin, int xHr, int xMin, int *pHr, int *pMin);
int roundUpToHour(int pHr, int pMin);
double calculateNewRatesCharge(char vType, int pHr, int roundedPHr);
void displayChargeDetails(char vType, int eHr, int eMin, int xHr, int xMin, int pHr, int pMin, int roundedPHr, double totalCharge);

int main() {
    // Variables to store input and calculation results
    char vehicleType;
    int entryHour, entryMinute, exitHour, exitMinute, parkingMinutes, parkingHours, roundedParkingHours;
    double totalCharge;

    // Input vehicle details
    inputDetails(&vehicleType, &entryHour, &entryMinute, &exitHour, &exitMinute);

    // Calculate parking duration
    calculateDuration(entryHour, entryMinute, exitHour, exitMinute, &parkingHours, &parkingMinutes);

    // Round parking duration to the nearest hour
    roundedParkingHours = roundUpToHour(parkingHours, parkingMinutes);

    // Calculate parking charge with new rates
    totalCharge = calculateNewRatesCharge(vehicleType, parkingHours, roundedParkingHours);

    // Display parking charge details
    displayChargeDetails(vehicleType, entryHour, entryMinute, exitHour, exitMinute, parkingHours, parkingMinutes, roundedParkingHours, totalCharge);

    return 0;
}

// Function to input vehicle details
void inputDetails(char *vType, int *eHr, int *eMin, int *xHr, int *xMin) {
    printf("Type of vehicle? (C for car, B for bus, T for truck): ");
    scanf(" %c", vType);

    // Validate input
    if (*vType != 'C' && *vType != 'B' && *vType != 'T') {
        printf("Invalid vehicle type. Exiting.\n");
        exit(1);
    }

    printf("Hour vehicle entered lot (0 - 24): ");
    scanf("%d", eHr);

    // Add more input validation as needed

    printf("Minute vehicle entered lot (0 - 60): ");
    scanf("%d", eMin);
    printf("Hour vehicle left lot (0 - 24): ");
    scanf("%d", xHr);
    printf("Minute vehicle left lot (0 - 60): ");
    scanf("%d", xMin);
}

// Function to compute parking duration
void calculateDuration(int eHr, int eMin, int xHr, int xMin, int *pHr, int *pMin) {
    if (xHr < eHr || (xHr == eHr && xMin <= eMin)) {
        // Vehicle stayed overnight; set parking duration to 0
        *pHr = 0;
        *pMin = 0;
    } else {
        if (xMin < eMin) {
            xMin += 60;
            xHr--;
        }

        *pHr = xHr - eHr;
        *pMin = xMin - eMin;
    }
}

// Function to round parking duration to the nearest hour
int roundUpToHour(int pHr, int pMin) {
    return (pMin > 0) ? pHr + 1 : pHr;
}

// Function to calculate parking charge based on vehicle type and rounded duration with new rates
double calculateNewRatesCharge(char vType, int pHr, int roundedPHr) {
    switch (vType) {
        case 'C':
            return (roundedPHr <= 3) ? roundedPHr * CAR_RATE_FIRST_3_HR : (roundedPHr - 3) * CAR_RATE_AFTER_3_HR + 3 * CAR_RATE_FIRST_3_HR;

        case 'B':
            return (roundedPHr <= 1) ? roundedPHr * BUS_RATE_FIRST_HR : (roundedPHr - 1) * BUS_RATE_AFTER_FIRST_HR + BUS_RATE_FIRST_HR;

        case 'T':
            return (roundedPHr <= 2) ? roundedPHr * TRUCK_RATE_FIRST_2_HR : (roundedPHr - 2) * TRUCK_RATE_AFTER_2_HR + 2 * TRUCK_RATE_FIRST_2_HR;

        default:
            return 0;
    }
}

// Function to display parking charge details
void displayChargeDetails(char vType, int eHr, int eMin, int xHr, int xMin, int pHr, int pMin, int roundedPHr, double totalCharge) {
    printf("PARKING LOT CHARGE\n");
    printf("Type of vehicle: ");

    switch (vType) {
        case 'C':
            printf("Car\n");
            break;
        case 'B':
            printf("Bus\n");
            break;
        case 'T':
            printf("Truck\n");
            break;
        default:
            printf("Unknown\n");
    }

    printf("\t\tPARKING LOT CHARGE\t\t");
    printf("\n");
    printf("The type of vehicle: %c\n", vType);
    printf("TIME-IN\t\t\t %2d : %02d\n", eHr, eMin);
    printf("TIME-OUT\t\t %2d : %02d\n", xHr, xMin);
    printf("\t\t\t--------\n");
    printf("PARKING TIME\t\t%2d : %02d\n", pHr, pMin);
    printf("ROUNDED TOTAL\t\t %6d\n", roundedPHr);
    printf("\t\t\t--------\n");
    printf("TOTAL CHARGE\t\t $%6.2f\n", totalCharge);
}
