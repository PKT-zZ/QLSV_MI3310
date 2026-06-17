#pragma once

#include "arrays.h"

void searchStudentByName(
    StudentArray* students,
    const char* keyword
);

Student* searchStudentByMSSV(
    StudentArray* students,
    const char* mssv
);

void searchStudentByClass(
    StudentArray* students,
    const char* lop
);

Subject* searchSubjectByCode(
    SubjectArray* subjects,
    const char* maHP
);

void searchSubjectByName(
    SubjectArray* subjects,
    const char* keyword
);

CourseClass* searchCourseClassByCode(
    CourseClassArray* classes,
    const char* maLHP
);