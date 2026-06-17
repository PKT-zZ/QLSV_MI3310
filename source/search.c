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

void searchStudentByClass(
    StudentArray* students,
    const char* lop
)
{
    int found = 0;

    for(int i = 0; i < students->size; i++)
    {
        if(strcmp(
            students->data[i].lop,
            lop
        ) == 0)
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
        printf("Khong tim thay lop.\n");
    }
}

Subject* searchSubjectByCode(
    SubjectArray* subjects,
    const char* maHP
)
{
    int idx =
        suba_find(
            subjects,
            maHP
        );

    if(idx == -1)
        return NULL;

    return &subjects->data[idx];
}

void searchSubjectByName(
    SubjectArray* subjects,
    const char* keyword
)
{
    int found = 0;

    for(int i = 0; i < subjects->size; i++)
    {
        if(strstr(
            subjects->data[i].tenHP,
            keyword
        ) != NULL)
        {
            printf(
                "%s | %s | %d\n",
                subjects->data[i].maHP,
                subjects->data[i].tenHP,
                subjects->data[i].soTinChi
            );

            found = 1;
        }
    }

    if(!found)
    {
        printf("Khong tim thay hoc phan.\n");
    }
}

CourseClass* searchCourseClassByCode(
    CourseClassArray* classes,
    const char* maLHP
)
{
    int idx =
        cca_find(
            classes,
            maLHP
        );

    if(idx == -1)
        return NULL;

    return &classes->data[idx];
}