#include <stdio.h>
#include "fileio.h"
#include "ui.h"

int main(void)
{
    StudentArray students;
    SubjectArray subjects;
    CourseClassArray classes;
    ScoreArray scores;

    if (!sa_init(&students, 4)) {
        printf("Loi khoi tao mang sinh vien.\n");
        return 1;
    }

    if (!suba_init(&subjects, 4)) {
        printf("Loi khoi tao mang mon hoc.\n");
        sa_clear(&students);
        return 1;
    }

    if (!cca_init(&classes, 4)) {
        printf("Loi khoi tao mang lop hoc phan.\n");
        sa_clear(&students);
        suba_clear(&subjects);
        return 1;
    }

    if (!sca_init(&scores, 4)) {
        printf("Loi khoi tao mang diem.\n");
        sa_clear(&students);
        suba_clear(&subjects);
        cca_clear(&classes);
        return 1;
    }

    loadAllData(
        &students,
        &subjects,
        &classes,
        &scores
    );

    showMainMenu(
        &students,
        &subjects,
        &classes,
        &scores
    );

    saveAllData(
        &students,
        &subjects,
        &classes,
        &scores
    );

    sa_clear(&students);
    suba_clear(&subjects);
    cca_clear(&classes);
    sca_clear(&scores);

    return 0;
}
