//Định nghĩa kiểu dữ liệu chính
#ifndef TYPES_H
#define TYPES_H

//Sinh viên
typedef struct{
    char mssv[12]; //PK. Ex: "202400000"
    char hoTen[60]; //"Salah"
    char lop[20]; //"K68-MI1-01"
    char birthday[12]; //DD/MM/YYYY.Ex: "09/05/2005"
} Student;

//Học phần
typedef struct{
    char maHP[10]; //MI3310
    char tenHP[80]; //Kỹ thuật lập trình
    int soTinChi; //2
} Subject;

//Lớp học phần
typedef struct {
    char maLHP[15]; //PK.Ex: "169312"
    char maHP[10]; //FK -> Subjects
    int hocKy; // "1", "2", "3"
    int namHoc; //2025
} CourseClass;

//Điểm số
typedef struct {
    char mssv[12]; //FK -> Students
    char maLHP[15]; //FK -> CourseClasses
    float diemQT; //0.0 - 10.0
    float diemCK; //0.0 - 10.0
    float diemTK; //0.5*QT + 0.5*CK
    float diemHe4; //quy đổi hệ 4
} ScoreRecord;

//Typed Dynamic Arrays
typedef struct { Student* data; int size; int capacity; } StudentArray;
typedef struct { Subject* data; int size; int capacity; } SubjectArray;
typedef struct { CourseClass* data; int size; int capacity; } CourseClassArray;
typedef struct { ScoreRecord* data; int size; int capacity; } ScoreArray;

#endif
