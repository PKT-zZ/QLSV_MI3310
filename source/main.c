#include <stdio.h>
#include "fileio.h"
#include "ui.h"

int main(void)
{
    StudentArray students;
    SubjectArray subjects;
    CourseClassArray classes;
    ScoreArray scores;

    sa_init(&students, 4);
    suba_init(&subjects, 4);
    cca_init(&classes, 4);
    sca_init(&scores, 4);

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