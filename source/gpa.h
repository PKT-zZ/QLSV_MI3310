#pragma once

#include "arrays.h"

float calculateStudentGPA4(
    const char* mssv,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
);

float calculateStudentGPA10(
    const char* mssv,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
);

const char* getAcademicRank(
    float gpa10
);