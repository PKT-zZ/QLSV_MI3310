#ifndef UI_H
#define UI_H

#include "fileio.h"

void showMainMenu(StudentArray* students,
                  SubjectArray* subjects,
                  CourseClassArray* classes,
                  ScoreArray* scores);

void showStudentMenu(StudentArray* students, ScoreArray* scores);
void showSubjectMenu(SubjectArray* subjects,
                     CourseClassArray* classes,
                     ScoreArray* scores);
void showCourseClassMenu(CourseClassArray* classes,
                         SubjectArray* subjects,
                         ScoreArray* scores);
void showScoreMenu(ScoreArray* scores,
                   StudentArray* students,
                   CourseClassArray* classes);

void displayStudents(StudentArray* students);
void displaySubjects(SubjectArray* subjects);
void displayCourseClasses(CourseClassArray* classes);
void displayScores(ScoreArray* scores);

int validateMSSV(const char* mssv);
int validateScore(float score);
int validateDate(const char* date);

void readLine(const char* message, char* buffer, int size);
int readInt(const char* message);
float readFloat(const char* message);

#endif
