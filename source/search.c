#include <stdio.h>
#include <string.h>

#include "search.h"

void searchStudentByName(
    StudentArray* students,
    const char* keyword
)
{
    int found = 0;

    for(int i = 0; i < students->size; i++)
    {
        if(strstr(
            students->data[i].hoTen,
            keyword
        ) != NULL)
        {
            printf(
                "%s | %s | %s | %s\n",
                students->data[i].mssv,
                students->data[i].hoTen,
                students->data[i].lop,
                students->data[i].birthday
            );

            found = 1;
        }
    }

    if(!found)
    {
        printf("Khong tim thay sinh vien.\n");
    }
}

Student* searchStudentByMSSV(
    StudentArray* students,
    const char* mssv
)
{
    int idx =
        sa_find(students, mssv);

    if(idx == -1)
        return NULL;

    return &students->data[idx];
}