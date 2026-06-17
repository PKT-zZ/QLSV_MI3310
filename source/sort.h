#pragma once

#include "arrays.h"

void sortStudentByMSSV(
    StudentArray* students
);

void sortStudentByName(
    StudentArray* students
);

void sortStudentByGPA(
    StudentArray* students,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
);