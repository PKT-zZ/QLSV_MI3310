#include "score.h"

float calculateDiemTK(float diemQT, float diemCK)
{
    return (diemQT + diemCK) / 2.0f;
}

float convertToHe4(float diemTK)
{
    if (diemTK >= 8.5f)
        return 4.0f;

    if (diemTK >= 8.0f)
        return 3.5f;

    if (diemTK >= 7.0f)
        return 3.0f;

    if (diemTK >= 6.5f)
        return 2.5f;

    if (diemTK >= 5.5f)
        return 2.0f;

    if (diemTK >= 5.0f)
        return 1.5f;

    if (diemTK >= 4.0f)
        return 1.0f;

    return 0.0f;
}

int addScoreRecord(
    ScoreArray* scores,
    StudentArray* students,
    CourseClassArray* classes,
    ScoreRecord sc
)
{
    if (sa_find(students, sc.mssv) == -1)
        return 0;

    if (cca_find(classes, sc.maLHP) == -1)
        return 0;

    if (sca_find(scores, sc.mssv, sc.maLHP) != -1)
        return 0;

    sc.diemTK =
        calculateDiemTK(
            sc.diemQT,
            sc.diemCK
        );

    sc.diemHe4 =
        convertToHe4(
            sc.diemTK
        );

    return sca_add(scores, sc);
}

int updateScoreRecord(
    ScoreArray* scores,
    const char* mssv,
    const char* maLHP,
    float diemQT,
    float diemCK
)
{
    int idx =
        sca_find(
            scores,
            mssv,
            maLHP
        );

    if(idx == -1)
        return 0;

    scores->data[idx].diemQT =
        diemQT;

    scores->data[idx].diemCK =
        diemCK;

    scores->data[idx].diemTK =
        calculateDiemTK(
            diemQT,
            diemCK
        );

    scores->data[idx].diemHe4 =
        convertToHe4(
            scores->data[idx].diemTK
        );

    return 1;
}