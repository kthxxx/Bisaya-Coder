#include <stdio.h>

void readNewAngle(double *newAngle);
const char *determineNewQuadrant(double newAngle);

int main() 
{
    double newAngle;
    readNewAngle(&newAngle);
    printf("%s", determineNewQuadrant(newAngle));
    return 0;
}

void readNewAngle(double *newAngle)
{
    printf("Enter a new angle: ");
    scanf("%lf", newAngle);
}

const char *determineNewQuadrant(double newAngle)
{
    if (newAngle == 0)
    {
        return "It is not a quadrant but lies on the positive X-axis";
    }
    else if (newAngle == 90)
    {
        return "It lies on the positive Y-axis";
    }
    else if (newAngle == 180)
    {
        return "It lies on the negative X-axis";
    }
    else if (newAngle == 270)
    {
        return "It lies on the negative Y-axis";
    }
    else if (newAngle > 0 && newAngle < 90)
    {
        return "Quadrant I";
    }
    else if (newAngle > 90 && newAngle < 180)
    {
        return "Quadrant II";
    }
    else if (newAngle > 180 && newAngle < 270)
    {
        return "Quadrant III";
    }
    else if (newAngle > 270 && newAngle < 360)
    {
        return "Quadrant IV";
    }
    else
    {
        return "Invalid angle"; // Invalid angle
    }
}
