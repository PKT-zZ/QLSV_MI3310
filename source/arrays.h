#pragma once
#include "types.h"

//StudentArray
int sa_init(StudentArray* arr, int init_cap);
int sa_add(StudentArray* arr, Student s);
Student* sa_get(StudentArray* arr, int idx);
int sa_remove(StudentArray* arr, int idx);
int sa_update(StudentArray* arr, int idx, Student s);
int sa_find(StudentArray* arr, const char* mssv);
void sa_clear(StudentArray* arr);

//SubjectArray 
int suba_init(SubjectArray* arr, int init_cap);
int suba_add(SubjectArray* arr, Subject s);
Subject* suba_get(SubjectArray* arr, int idx);
int suba_remove(SubjectArray* arr, int idx);
int suba_update(SubjectArray* arr, int idx, Subject s);
int suba_find(SubjectArray* arr, const char* maHP);
void suba_clear(SubjectArray* arr);

//CourseClassArray
int cca_init(CourseClassArray* arr, int init_cap);
int cca_add(CourseClassArray* arr, CourseClass c);
CourseClass* cca_get(CourseClassArray* arr, int idx);
int cca_remove(CourseClassArray* arr, int idx);
int cca_update(CourseClassArray* arr, int idx, CourseClass c);
int cca_find(CourseClassArray* arr, const char* maLHP);
void cca_clear(CourseClassArray* arr);

//ScoreArray
int sca_init(ScoreArray* arr, int init_cap);
int sca_add(ScoreArray* arr, ScoreRecord sc);
ScoreRecord* sca_get(ScoreArray* arr, int idx);
int sca_remove(ScoreArray* arr, int idx);
int sca_update(ScoreArray* arr, int idx, ScoreRecord sc);
//ScoreRecord dùng khóa kép (mssv, maLHP)
int sca_find(ScoreArray* arr, const char* mssv, const char* maLHP);
void sca_clear(ScoreArray* arr);
