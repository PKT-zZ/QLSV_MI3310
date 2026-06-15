//Test: struct Student, Subject, CourseClass, ScoreRecord trong types.h, chỉ kiểm tra kích thước trường và việc gán/đọc giá trị có biên dịch và hoạt động đúng
#include <stdio.h>
#include <string.h>
#include "types.h"

int pass = 0, fail = 0;
void check(int cond, const char* msg) {
    if (cond) { printf("  [PASS] %s\n", msg); pass++; }
    else { printf("  [FAIL] %s\n", msg); fail++; }
}

int main() {
    printf("[UNIT TEST] types.h\n");

    Student s;
    check(sizeof(s.mssv) == 12, "Kich thuoc truong mssv la 12 bytes");
    check(sizeof(s.hoTen) == 60, "Kich thuoc truong hoTen la 60 bytes");
    strcpy(s.mssv, "202400000");
    check(strcmp(s.mssv, "202400000") == 0, "Gan/doc truong mssv dung");

    Subject sub;
    sub.soTinChi = 3;
    strcpy(sub.maHP, "MI3310");
    check(sub.soTinChi == 3, "Truong soTinChi gan/doc dung");
    check(strcmp(sub.maHP, "MI3310") == 0, "Truong maHP gan/doc dung");

    CourseClass cc;
    strcpy(cc.maLHP, "169313");
    cc.hocKy = 1; cc.namHoc = 2025;
    check(cc.hocKy == 1 && cc.namHoc == 2025, "Truong hocKy/namHoc cua CourseClass dung");

    ScoreRecord sc;
    sc.diemQT = 8.5f; sc.diemCK = 7.0f;
    sc.diemTK = 0.5f * sc.diemQT + 0.5f * sc.diemCK;
    check(sc.diemTK > 0, "Truong diemTK ton tai va tinh duoc gia tri");

    printf("KET QUA: %d PASS, %d FAIL\n\n", pass, fail);
    return fail > 0 ? 1 : 0;
}
