#include <stdio.h>
#include <cs50.h>
#include <math.h>

typedef struct
{
    int unit;
    int grade;
    int mult;
}
cgpa;

int main(void)
{
    int size = get_int("Input number of courses: ");
    if (size < 1)
    {
        printf("Must have a course unit and its grade\n");
        return 1;
    }

    cgpa score[size];
    int add_units = 0;
    int add_mult = 0;

    for (int i = 0; i < size; i++)
    {
        score[i].unit =  get_int("course %i unit: ", i + 1);
        score[i].grade = get_int("Course %i Grade: ", i + 1);
        printf("\n");

        score[i].mult = score[i].unit * score[i].grade;
        add_mult += score[i].mult;
        add_units += score[i].unit;
    }

    float gpa = (float) add_mult / add_units;
    gpa = round(gpa * 100) / 100;

    printf("CGPA = %.2f ", gpa);

    if (gpa >= 4.5 && gpa <= 5.0)
    {
        printf("(First Class)\n");
    }
    else if (gpa >= 3.5 && gpa < 4.5)
    {
        printf("(Second Class Upper)\n");
    }
    else if (gpa >= 2.5 && gpa < 3.5)
    {
        printf("(Second Class Lower)\n");
    }
    else if (gpa >= 1.5 && gpa < 2.5)
    {
        printf("(Third Class)\n");
    }
    else if (gpa >= 1.0 && gpa < 1.5)
    {
        printf("(Pass)\n");
    }
    else if (gpa < 1.0)
    {
        printf("(Fail! No Degree)\n");
    }
    else
    {
        printf("Error! Check unit and grade distribution.\n");
    }
    return 0;
}