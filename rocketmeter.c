#include <stdio.h>

typedef struct {
    double time;
    double pressure;
    double velocity;
    double altitude;
} RocketMeter;

void displayValues(RocketMeter rm);
double averageAltitude(RocketMeter rm1, RocketMeter rm2);
double calculateAcceleration(RocketMeter rm1, RocketMeter rm2);
double calculateDistance(RocketMeter rm1, RocketMeter rm2);
RocketMeter inputRocketMeter(double time);

int main() {
    printf("Enter data for the initial timestamp (t=0):\n");
    RocketMeter rm1 = inputRocketMeter(0.0);

    printf("\nEnter data for the second timestamp (t=5):\n");
    RocketMeter rm2 = inputRocketMeter(5.0);

    printf("\nEnter data for the third timestamp (t=10):\n");
    RocketMeter rm3 = inputRocketMeter(10.0);

    printf("\nDisplaying values for each timestamp:\n");
    displayValues(rm1);
    displayValues(rm2);
    displayValues(rm3);

    printf("Average Altitude between t=%.2f and t=%.2f: %.2f m\n", rm1.time, rm3.time, averageAltitude(rm1, rm3));
    printf("Acceleration between t=%.2f and t=%.2f: %.2f m/s^2\n", rm1.time, rm2.time, calculateAcceleration(rm1, rm2));
    printf("Distance traveled between t=%.2f and t=%.2f: %.2f m\n", rm1.time, rm2.time, calculateDistance(rm1, rm2));

    return 0;
}

void displayValues(RocketMeter rm) {
    printf("Timestamp: %.2f seconds\n", rm.time);
    printf("Pressure: %.2f Pa\n", rm.pressure);
    printf("Velocity: %.2f m/s\n", rm.velocity);
    printf("Altitude: %.2f m\n", rm.altitude);
    printf("------------------------\n");
}

double averageAltitude(RocketMeter rm1, RocketMeter rm2) {
    return (rm1.altitude + rm2.altitude) / 2.0;
}

double calculateAcceleration(RocketMeter rm1, RocketMeter rm2) {
    return (rm2.velocity - rm1.velocity) / (rm2.time - rm1.time);
}

double calculateDistance(RocketMeter rm1, RocketMeter rm2) {
    double avgVelocity = (rm1.velocity + rm2.velocity) / 2.0;
    return avgVelocity * (rm2.time - rm1.time);
}

RocketMeter inputRocketMeter(double time) {
    RocketMeter rm;
    rm.time = time;
    printf("Enter pressure (Pa) at time %.2f: ", rm.time);
    scanf("%lf", &rm.pressure);
    printf("Enter velocity (m/s) at time %.2f: ", rm.time);
    scanf("%lf", &rm.velocity);
    printf("Enter altitude (m) at time %.2f: ", rm.time);
    scanf("%lf", &rm.altitude);
    return rm;
}
