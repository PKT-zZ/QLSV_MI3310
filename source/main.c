#include <stdio.h>
#include "fileio.h"
#include "ui.h"
int main(void) {
    StudentArray students;
    SubjectArray subjects;
    CourseClassArray classes;
    ScoreArray scores;

    sa_init(&students, 4);
    suba_init(&subjects, 4);
    cca_init(&classes, 4);
    sca_init(&scores, 4);

    loadAllData(&students, &subjects, &classes, &scores);

    printf("Load data thanh cong!\n");
    printf("So sinh vien: %d\n", students.size);
    printf("So mon hoc: %d\n", subjects.size);
    printf("So lop hoc phan: %d\n", classes.size);
    printf("So ban ghi diem: %d\n", scores.size);

    saveAllData(&students, &subjects, &classes, &scores);

    sa_clear(&students);
    suba_clear(&subjects);
    cca_clear(&classes);
    sca_clear(&scores);

    return 0;
}