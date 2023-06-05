#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>

/* Threshold temperature values */
#define T1_THRESHOLD 80.0
#define T2_THRESHOLD 70.0
#define T3_THRESHOLD 75.0

/* Motor activation status */
bool m1_motor_active = false;
bool m2_motor_active = false;
bool m3_motor_active = false;

/* Function to generate a pseudorandom temperature value */
void generate_temperature(double* T1, double* T2, double* T3)
{
    *T1 += (double)rand() / RAND_MAX;
    *T2 += (double)rand() / RAND_MAX;
    *T3 += (double)rand() / RAND_MAX;
}

/* Function to activate motors and display messages */
void activate_motor(const char* motor_name, double*T1, double* T2, double* T3)
{
    if (strcmp(motor_name, "M1") == 0)
    {
        if (!m1_motor_active)
        {
            m1_motor_active = true;
            printf("M1 motor activated.\n");
            *T1 -= 5;
        }
    }
    else if (strcmp(motor_name, "M2") == 0)
    {
        if (!m2_motor_active)
        {
            m2_motor_active = true;
            printf("M2 motor activated.\n");
            *T2 -= 5;
        }
    }
    else if (strcmp(motor_name, "M3") == 0)
    {
        if (!m3_motor_active)
        {
            m3_motor_active = true;
            printf("M3 motor activated.\n");
            *T3 -= 5;
        }
    }
}

/* Function to deactivate motors and display messages */
void deactivate_motor(const char* motor_name)
{
    if (strcmp(motor_name, "M1") == 0)
    {
        if (m1_motor_active)
        {
            m1_motor_active = false;
            printf("M1 motor deactivated.\n");
        }
    }
    else if (strcmp(motor_name, "M2") == 0)
    {
        if (m2_motor_active)
        {
            m2_motor_active = false;
            printf("M2 motor deactivated.\n");
        }
    }
    else if (strcmp(motor_name, "M3") == 0)
    {
        if (m3_motor_active)
        {
            m3_motor_active = false;
            printf("M3 motor deactivated.\n");
        }
    }
}

/* Function to check temperature thresholds and activate/deactivate motors */
void check_temperature_thresholds(double* T1, double* T2, double* T3)
{
    generate_temperature(T1, T2, T3);

    printf("T1: %.2f°C, T2: %.2f°C, T3: %.2f°C\n", *T1, *T2, *T3);

    if (*T1 > T1_THRESHOLD)
    {
        activate_motor("M1", T1, T2, T3);
    }
    else
    {
        deactivate_motor("M1");
    }

    if (*T2 > T2_THRESHOLD)
    {
        activate_motor("M2", T1, T2, T3);
    }
    else
    {
        deactivate_motor("M2");
    }

    if (*T3 > T3_THRESHOLD)
    {
        activate_motor("M3", T1, T2, T3);
    }
    else
    {
        deactivate_motor("M3");
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed

    double T1 = 70.0; // Initialize initial temperatures
    double T2 = 65.0;
    double T3 = 72.0;

    while (true)
    {
        check_temperature_thresholds(&T1, &T2, &T3);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for 1 second before checking again
    }

    return 0;
}


