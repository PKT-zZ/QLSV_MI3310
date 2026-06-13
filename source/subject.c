#include <stddef.h>
#include "subject.h"

Subject* findSubjectRecord(
    SubjectArray* subjects,
    const char* maHP
)
{
    int idx =
        suba_find(
            subjects,
            maHP
        );

    if(idx == -1)
        return NULL;

    return &subjects->data[idx];
}

int addSubjectRecord(
    SubjectArray* subjects,
    Subject s
)
{
    if(suba_find(subjects, s.maHP) != -1)
        return 0;

    return suba_add(
        subjects,
        s
    );
}

int updateSubjectRecord(
    SubjectArray* subjects,
    Subject s
)
{
    int idx =
        suba_find(
            subjects,
            s.maHP
        );

    if(idx == -1)
        return 0;

    return suba_update(
        subjects,
        idx,
        s
    );
}

int deleteSubjectRecord(
    SubjectArray* subjects,
    const char* maHP
)
{
    int idx =
        suba_find(
            subjects,
            maHP
        );

    if(idx == -1)
        return 0;

    return suba_remove(
        subjects,
        idx
    );
}