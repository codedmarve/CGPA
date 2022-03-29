#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = get_int("Input number of courses: ");
    if (size < 1)
    {
        printf("Must have a course unit and its grade\n");
        return 1;
    }

    int unit[size];
    int grade[size];
    int mult[size];
    int add_units = 0;
    int add_mult = 0;

    for (int i = 0; i < size; i++)
    {
        unit[i] =  get_int("course %i unit: ", i + 1);
        grade[i] = get_int("course %i grade: ", i + 1);
        printf("\n");

        mult[i] = unit[i] * grade[i];
        add_mult += mult[i];
        add_units += unit[i];
    }

    printf("CGPA = %.2f\n", (float) add_mult / add_units);
    return 0;
}