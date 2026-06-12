#pragma once

#include "arrays.h"

int addCourseClassRecord(
    CourseClassArray* classes,
    SubjectArray* subjects,
    CourseClass c
);

int updateCourseClassRecord(
    CourseClassArray* classes,
    CourseClass c
);

int deleteCourseClassRecord(
    CourseClassArray* classes,
    const char* maLHP
);

CourseClass* findCourseClassRecord(
    CourseClassArray* classes,
    const char* maLHP
);