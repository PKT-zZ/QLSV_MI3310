#pragma once

#include "arrays.h"

float calculateDiemTK(float diemQT, float diemCK);

float convertToHe4(float diemTK);

int addScoreRecord(
    ScoreArray* scores,
    StudentArray* students,
    CourseClassArray* classes,
    ScoreRecord sc
);

int updateScoreRecord(
    ScoreArray* scores,
    const char* mssv,
    const char* maLHP,
    float diemQT,
    float diemCK
);