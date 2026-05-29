/* arrays.c - Cai dat Typed Dynamic Array cho 4 kieu du lieu: StudentArray, SubjectArray, CourseClassArray, ScoreArray
Quy uoc tra ve:
- init, add, remove, update: 1 = thanh cong, 0 = loi
- *_find: index >= 0 neu tim thay, -1 neu khong
- *_get: con tro hop le neu ok, NULL neu ngoai pham vi
- *_resize: static - chi su dung noi bo file */
#include <stdlib.h>
#include <string.h>
#include "arrays.h"

//P1:StudentArray. Khóa chính: mssv

//Tăng gấp đôi capacity khi mảng đầy
static int sa_resize(StudentArray* arr) {
    int new_cap = arr->capacity * 2;
    //Dùng con trỏ tạm tmp để bảo vệ arr->data nếu realloc thất bại
    Student* tmp = (Student*)realloc(arr->data, new_cap * sizeof(Student));
    if (tmp == NULL) return 0;
    
    arr->data = tmp;
    arr->capacity = new_cap;
    return 1;
}

//Khởi tạo mảng với init_cap ô nhớ. init_cap <= 0 dùng mặc định 4
int sa_init(StudentArray* arr, int init_cap) {
    if (init_cap <= 0) init_cap = 4;   
    arr->data = (Student*)malloc(init_cap * sizeof(Student));
    if (arr->data == NULL) return 0;
    
    arr->size = 0;
    arr->capacity = init_cap;
    return 1;
}

//Thêm một Student vào cuối mảng. Tự động resize nếu đầy
int sa_add(StudentArray* arr, Student s) {
    if (arr->size >= arr->capacity) {
        if (!sa_resize(arr)) return 0;
    }
    arr->data[arr->size] = s;
    arr->size++;
    return 1;
}

//Trả về con trỏ đến phần tử tại index, NULL nếu ngoài phạm vi
Student* sa_get(StudentArray* arr, int index) {
    if (index < 0 || index >= arr->size) return NULL;
    return &arr->data[index];
}

//Xóa phần tử tại index, dịch các phần tử sau lên một vị trí
int sa_remove(StudentArray* arr, int index) {
    if (index < 0 || index >= arr->size) return 0;    
    //Dịch từ index đến size-2
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

//Ghi đè phần tử tại index bằng nội dung mới
int sa_update(StudentArray* arr, int index, Student s) {
    if (index < 0 || index >= arr->size) return 0;
    arr->data[index] = s;
    return 1;
}

//Tìm kiếm theo MSSV (khóa chính). Dùng strcmp để so sánh nội dung chuỗi, không dùng
int sa_find(StudentArray* arr, const char* mssv) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].mssv, mssv) == 0) return i;
    }
    return -1;
}

//Giải phóng bộ nhớ heap. Gọi trước khi kết thúc chương trình
void sa_clear(StudentArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


//P2:SubjectArray. Khóa chính: maHP

static int suba_resize(SubjectArray* arr) {
    int new_cap = arr->capacity * 2;
    Subject* tmp = (Subject*)realloc(arr->data, new_cap * sizeof(Subject));
    if (tmp == NULL) return 0;
    arr->data = tmp;
    arr->capacity = new_cap;
    return 1;
}

int suba_init(SubjectArray* arr, int init_cap) {
    if (init_cap <= 0) init_cap = 4;
    arr->data = (Subject*)malloc(init_cap * sizeof(Subject));
    if (arr->data == NULL) return 0;
    arr->size = 0;
    arr->capacity = init_cap;
    return 1;
}

int suba_add(SubjectArray* arr, Subject s) {
    if (arr->size >= arr->capacity) {
        if (!suba_resize(arr)) return 0;
    }
    arr->data[arr->size] = s;
    arr->size++;
    return 1;
}

Subject* suba_get(SubjectArray* arr, int index) {
    if (index < 0 || index >= arr->size) return NULL;
    return &arr->data[index];
}

int suba_remove(SubjectArray* arr, int index) {
    if (index < 0 || index >= arr->size) return 0;
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

int suba_update(SubjectArray* arr, int index, Subject s) {
    if (index < 0 || index >= arr->size) return 0;
    arr->data[index] = s;
    return 1;
}

//Tìm kiếm theo maHP - khóa chính của Subject
int suba_find(SubjectArray* arr, const char* maHP) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].maHP, maHP) == 0) return i;
    }
    return -1;
}

void suba_clear(SubjectArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


//P3:CourseClassArray. Khóa chính: maLHP

static int cca_resize(CourseClassArray* arr) {
    int new_cap = arr->capacity * 2;
    CourseClass* tmp = (CourseClass*)realloc(arr->data, new_cap * sizeof(CourseClass));
    if (tmp == NULL) return 0;
    arr->data = tmp;
    arr->capacity = new_cap;
    return 1;
}

int cca_init(CourseClassArray* arr, int init_cap) {
    if (init_cap <= 0) init_cap = 4;
    arr->data = (CourseClass*)malloc(init_cap * sizeof(CourseClass));
    if (arr->data == NULL) return 0;
    arr->size = 0;
    arr->capacity = init_cap;
    return 1;
}

int cca_add(CourseClassArray* arr, CourseClass c) {
    if (arr->size >= arr->capacity) {
        if (!cca_resize(arr)) return 0;
    }
    arr->data[arr->size] = c;
    arr->size++;
    return 1;
}

CourseClass* cca_get(CourseClassArray* arr, int index) {
    if (index < 0 || index >= arr->size) return NULL;
    return &arr->data[index];
}

int cca_remove(CourseClassArray* arr, int index) {
    if (index < 0 || index >= arr->size) return 0;
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

int cca_update(CourseClassArray* arr, int index, CourseClass c) {
    if (index < 0 || index >= arr->size) return 0;
    arr->data[index] = c;
    return 1;
}

//Tìm kiếm theo maLHP - khóa chính của CourseClass
int cca_find(CourseClassArray* arr, const char* maLHP) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].maLHP, maLHP) == 0) return i;
    }
    return -1;
}

void cca_clear(CourseClassArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


//P4:ScoreArray. Khóa kép: (mssv + maLHP)

static int sca_resize(ScoreArray* arr) {
    int new_cap = arr->capacity * 2;
    ScoreRecord* tmp = (ScoreRecord*)realloc(arr->data, new_cap * sizeof(ScoreRecord));
    if (tmp == NULL) return 0;
    arr->data = tmp;
    arr->capacity = new_cap;
    return 1;
}

int sca_init(ScoreArray* arr, int init_cap) {
    if (init_cap <= 0) init_cap = 4;
    arr->data = (ScoreRecord*)malloc(init_cap * sizeof(ScoreRecord));
    if (arr->data == NULL) return 0;
    arr->size = 0;
    arr->capacity = init_cap;
    return 1;
}

int sca_add(ScoreArray* arr, ScoreRecord sc) {
    if (arr->size >= arr->capacity) {
        if (!sca_resize(arr)) return 0;
    }
    arr->data[arr->size] = sc;
    arr->size++;
    return 1;
}

ScoreRecord* sca_get(ScoreArray* arr, int index) {
    if (index < 0 || index >= arr->size) return NULL;
    return &arr->data[index];
}

int sca_remove(ScoreArray* arr, int index) {
    if (index < 0 || index >= arr->size) return 0;
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

int sca_update(ScoreArray* arr, int index, ScoreRecord sc) {
    if (index < 0 || index >= arr->size) return 0;
    arr->data[index] = sc;
    return 1;
}

//Tìm kiếm theo khóa kép (mssv + maLHP). Cả hai điều kiện phải thỏa mãn để xác định bản ghi
int sca_find(ScoreArray* arr, const char* mssv, const char* maLHP) {
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].mssv, mssv) == 0 && strcmp(arr->data[i].maLHP, maLHP) == 0) return i;
    }
    return -1;
}

void sca_clear(ScoreArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}