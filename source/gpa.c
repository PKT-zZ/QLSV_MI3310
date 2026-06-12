#include <string.h>

#include "gpa.h"

float calculateStudentGPA(
    const char* mssv,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
)
{
    float tongDiem = 0.0f;
    int tongTinChi = 0;

    for(int i = 0; i < scores->size; i++)
    {
        ScoreRecord sc =
            scores->data[i];

        if(strcmp(sc.mssv, mssv) != 0)
            continue;

        int classIndex =
            cca_find(
                classes,
                sc.maLHP
            );

        if(classIndex == -1)
            continue;

        CourseClass cc =
            classes->data[classIndex];

        int subjectIndex =
            suba_find(
                subjects,
                cc.maHP
            );

        if(subjectIndex == -1)
            continue;

        Subject sub =
            subjects->data[subjectIndex];

        tongDiem +=
            sc.diemHe4 *
            sub.soTinChi;

        tongTinChi +=
            sub.soTinChi;
    }

    if(tongTinChi == 0)
        return 0.0f;

    return tongDiem /
           tongTinChi;
}