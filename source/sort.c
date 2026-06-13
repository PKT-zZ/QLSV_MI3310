#include <string.h>
#include "sort.h"

void sortStudentByMSSV(StudentArray* students)
{
    for(int i = 0; i < students->size - 1; i++)
    {
        for(int j = 0; j < students->size - i - 1; j++)
        {
            if(strcmp(
                students->data[j].mssv,
                students->data[j + 1].mssv
            ) > 0)
            {
                Student temp =
                    students->data[j];

                students->data[j] =
                    students->data[j + 1];

                students->data[j + 1] =
                    temp;
            }
        }
    }
}

void sortStudentByName(StudentArray* students)
{
    for(int i = 0; i < students->size - 1; i++)
    {
        for(int j = 0; j < students->size - i - 1; j++)
        {
            if(strcmp(
                students->data[j].hoTen,
                students->data[j + 1].hoTen
            ) > 0)
            {
                Student temp =
                    students->data[j];

                students->data[j] =
                    students->data[j + 1];

                students->data[j + 1] =
                    temp;
            }
        }
    }
}