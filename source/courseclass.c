#include <stddef.h>
#include "courseclass.h"

CourseClass* findCourseClassRecord(
    CourseClassArray* classes,
    const char* maLHP
)
{
    int idx =
        cca_find(
            classes,
            maLHP
        );

    if(idx == -1)
        return NULL;

    return &classes->data[idx];
}

int addCourseClassRecord(
    CourseClassArray* classes,
    SubjectArray* subjects,
    CourseClass c
)
{
    if(cca_find(classes, c.maLHP) != -1)
        return 0;

    if(suba_find(subjects, c.maHP) == -1)
        return 0;

    return cca_add(
        classes,
        c
    );
}

int updateCourseClassRecord(
    CourseClassArray* classes,
    CourseClass c
)
{
    int idx =
        cca_find(
            classes,
            c.maLHP
        );

    if(idx == -1)
        return 0;

    return cca_update(
        classes,
        idx,
        c
    );
}

int deleteCourseClassRecord(
    CourseClassArray* classes,
    const char* maLHP
)
{
    int idx =
        cca_find(
            classes,
            maLHP
        );

    if(idx == -1)
        return 0;

    return cca_remove(
        classes,
        idx
    );
}