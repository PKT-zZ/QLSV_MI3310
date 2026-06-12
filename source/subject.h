#pragma once

#include "arrays.h"

int addSubjectRecord(
    SubjectArray* subjects,
    Subject s
);

int updateSubjectRecord(
    SubjectArray* subjects,
    Subject s
);

int deleteSubjectRecord(
    SubjectArray* subjects,
    const char* maHP
);

Subject* findSubjectRecord(
    SubjectArray* subjects,
    const char* maHP
);