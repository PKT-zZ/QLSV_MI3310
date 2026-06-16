//Test: hàm calculateStudentGPA()
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "gpa.h"

int pass_gpa = 0, fail_gpa = 0;
void check_gpa(int cond, const char* msg) {
    if (cond) { printf("  [PASS] %s\n", msg); pass_gpa++; }
    else { printf("  [FAIL] %s\n", msg); fail_gpa++; }
}

static int feq(float a, float b) {
    float d = a - b;
    return (d < 0 ? -d : d) < 0.01f;
}

int main() {
    printf("[UNIT TEST] gpa.c\n");

    SubjectArray subs; suba_init(&subs, 4);
    CourseClassArray clss; cca_init(&clss, 4);
    ScoreArray scores; sca_init(&scores, 4);

    //Môn 1: 2 tín, diemHe4 = 4.0
    Subject sub1; strcpy(sub1.maHP, "MH01"); strcpy(sub1.tenHP, "Mon 1"); sub1.soTinChi = 2;
    suba_add(&subs, sub1);
    CourseClass cc1; strcpy(cc1.maLHP, "LHP01"); strcpy(cc1.maHP, "MH01"); cc1.hocKy = 1; cc1.namHoc = 2025;
    cca_add(&clss, cc1);
    ScoreRecord sc1;
    strcpy(sc1.mssv, "SV001"); strcpy(sc1.maLHP, "LHP01");
    sc1.diemQT = 10; sc1.diemCK = 10; sc1.diemTK = 10; sc1.diemHe4 = 4.0f;
    sca_add(&scores, sc1);

    //Test 1: 1 môn -> GPA = diemHe4 của môn đó
    float gpa1 = calculateStudentGPA("SV001", &scores, &clss, &subs);
    check_gpa(feq(gpa1, 4.0f), "GPA voi 1 mon = diemHe4 cua mon do (4.0)");

    //Môn 2: 3 tín, diemHe4 = 2.0
    Subject sub2; strcpy(sub2.maHP, "MH02"); strcpy(sub2.tenHP, "Mon 2"); sub2.soTinChi = 3;
    suba_add(&subs, sub2);
    CourseClass cc2; strcpy(cc2.maLHP, "LHP02"); strcpy(cc2.maHP, "MH02"); cc2.hocKy = 1; cc2.namHoc = 2025;
    cca_add(&clss, cc2);
    ScoreRecord sc2;
    strcpy(sc2.mssv, "SV001"); strcpy(sc2.maLHP, "LHP02");
    sc2.diemQT = 5; sc2.diemCK = 5; sc2.diemTK = 5; sc2.diemHe4 = 2.0f;
    sca_add(&scores, sc2);

    //Test 2: 2 môn -> GPA tính theo công thức đã biết
    float gpa2 = calculateStudentGPA("SV001", &scores, &clss, &subs);
    check_gpa(feq(gpa2, 2.8f), "GPA voi 2 mon co trong so dung (2.8)");

    //Test 3: sinh viên ko có điểm -> GPA = 0
    float gpa3 = calculateStudentGPA("SV999", &scores, &clss, &subs);
    check_gpa(feq(gpa3, 0.0f), "Sinh vien khong co diem -> GPA = 0");

    sca_clear(&scores); cca_clear(&clss); suba_clear(&subs);

    printf("KET QUA: %d PASS, %d FAIL\n\n", pass_gpa, fail_gpa);
    return fail_gpa > 0 ? 1 : 0;
}
