#include <stddef.h>
#include "student.h"

Student* findStudentRecord(
    StudentArray* students,
    const char* mssv
)
{
    int idx = sa_find(students, mssv);

    if(idx == -1)
        return NULL;

    return &students->data[idx];
}

int addStudentRecord(
    StudentArray* students,
    Student s
)
{
    if(sa_find(students, s.mssv) != -1)
        return 0;

    return sa_add(students, s);
}

int updateStudentRecord(
    StudentArray* students,
    Student s
)
{
    int idx =
        sa_find(
            students,
            s.mssv
        );

    if(idx == -1)
        return 0;

    return sa_update(
        students,
        idx,
        s
    );
}

int deleteStudentRecord(
    StudentArray* students,
    const char* mssv
)
{
    int idx =
        sa_find(
            students,
            mssv
        );

    if(idx == -1)
        return 0;

    return sa_remove(
        students,
        idx
    );
}