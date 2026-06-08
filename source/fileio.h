/* Khai báo module đọc/ghi dữ liệu từ file text
- load*: nếu file không tồn tại thì bỏ qua, mảng giữ nguyên (không crash)
- save*: ghi đè toàn bộ file, bao gồm dòng tiêu đề
- loadAllData/saveAllData: gọi đủ 4 cặp hàm theo thứ tự */
#pragma once

#include "arrays.h"

#define STUDENT_FILE "data/students.txt"
#define SUBJECT_FILE "data/subjects.txt"
#define COURSE_CLASS_FILE "data/course_classes.txt"
#define SCORE_FILE "data/scores.txt"

//Sinh viên
void loadStudents(StudentArray* students, const char* path);
void saveStudents(StudentArray* students, const char* path);

//Môn học
void loadSubjects(SubjectArray* subjects, const char* path);
void saveSubjects(SubjectArray* subjects, const char* path);

//Lớp hphan
void loadCourseClasses(CourseClassArray* classes, const char* path);
void saveCourseClasses(CourseClassArray* classes, const char* path);

//Điểm số
void loadScores(ScoreArray* scores, const char* path);
void saveScores(ScoreArray* scores, const char* path);

//Load/save toàn bộ dữ liệu 1 lần, loadAllData còn kiểm tra toàn vẹn tham chiếu sau khi load xong 4 bảng
void loadAllData(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores);
void saveAllData(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores);
