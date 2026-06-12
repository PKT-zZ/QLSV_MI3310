#pragma once

#include "arrays.h"

int addStudentRecord(
    StudentArray* students,
    Student s
);

int updateStudentRecord(
    StudentArray* students,
    Student s
);

int deleteStudentRecord(
    StudentArray* students,
    const char* mssv
);

Student* findStudentRecord(
    StudentArray* students,
    const char* mssv
);