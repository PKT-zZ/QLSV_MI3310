//Kiểm thử module arrays và fileio
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "fileio.h"

static int g_pass = 0, g_fail = 0;

static float f_abs(float x) { return (x < 0.0f) ? -x : x; }

#define CHECK(cond, msg) \
    do { \
        if (cond) { printf("  [PASS] %s\n", msg); g_pass++; } \
        else      { printf("  [FAIL] %s\n", msg); g_fail++; } \
    } while (0)


//Nhóm 1: Load dữ liệu cơ bản (TC01-TC04)
static void test_load_basic(void) {
    printf("\n[NHOM 1] Load du lieu co ban\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);

    loadAllData(&stu, &sub, &cls, &sc);

    //TC01: số lượng bản ghi khớp với dữ liệu mẫu
    CHECK(stu.size == 6, "TC01a: students.size == 6");
    CHECK(sub.size == 5, "TC01b: subjects.size == 5");
    CHECK(cls.size == 5, "TC01c: classes.size == 5");
    CHECK(sc.size == 22, "TC01d: scores.size == 22");

    //TC02: nội dung bản ghi sinh viên đầu tiên
    int i = sa_find(&stu, "202400000");
    CHECK(i >= 0, "TC02a: tim thay MSSV 202400000");
    if (i >= 0) {
        CHECK(strcmp(stu.data[i].hoTen, "Nguyen Van Toan") == 0,
            "TC02b: hoTen cua 202400000 la 'Nguyen Van Toan'");
        CHECK(strcmp(stu.data[i].lop, "K69-MI1-01") == 0,
            "TC02c: lop cua 202400000 la 'K69-MI1-01'");
        CHECK(strcmp(stu.data[i].birthday, "15/08/2006") == 0,
            "TC02d: birthday cua 202400000 la '15/08/2006'");
    }

    //TC03: HP load đúng
    int j = suba_find(&sub, "MI3310");
    CHECK(j >= 0, "TC03a: tim thay MaHP MI3310");
    if (j >= 0)
        CHECK(sub.data[j].soTinChi == 2, "TC03b: MI3310 soTinChi == 2");

    //TC04: LHP load đúng
    int k = cca_find(&cls, "169313");
    CHECK(k >= 0, "TC04a: tim thay MaLHP 169313");
    if (k >= 0) {
        CHECK(strcmp(cls.data[k].maHP, "MI3310") == 0, "TC04b: 169313 -> MI3310");
        CHECK(cls.data[k].hocKy == 1, "TC04c: 169313 hocKy == 1");
        CHECK(cls.data[k].namHoc == 2025, "TC04d: 169313 namHoc == 2025");
    }

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 2: Điểm số (TC05-TC06)
static void test_scores(void) {
    printf("\n[NHOM 2] Diem so\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //TC05: kiểm tra giá trị bản ghi điểm cụ thể
    int i = sca_find(&sc, "202400000", "169313");
    CHECK(i >= 0, "TC05a: tim thay score (202400000, 169313)");
    if (i >= 0) {
        float qt = sc.data[i].diemQT;
        float ck = sc.data[i].diemCK;
        float tk = sc.data[i].diemTK;
        CHECK(qt >= 0.0f && qt <= 10.0f, "TC05b: DiemQT trong [0, 10]");
        CHECK(ck >= 0.0f && ck <= 10.0f, "TC05c: DiemCK trong [0, 10]");
        CHECK(f_abs(tk - (0.5f*qt + 0.5f*ck)) < 0.01f, "TC05d: DiemTK == 0.5*QT + 0.5*CK");
        CHECK(sc.data[i].diemHe4 >= 0.0f && sc.data[i].diemHe4 <= 4.0f,
            "TC05e: DiemHe4 trong [0, 4]");
    }

    //TC06: khóa không tồn tại phải trả -1
    CHECK(sca_find(&sc, "000000000", "000000") == -1, "TC06: sca_find khoa khong ton tai -> -1");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 3: Save rồi Reload (TC07)
static void test_save_reload(void) {
    printf("\n[NHOM 3] Save -> Reload\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    int n_stu = stu.size, n_sub = sub.size, n_cls = cls.size, n_sc = sc.size;

    saveAllData(&stu, &sub, &cls, &sc);
    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);

    //Load lại lần hai
    sa_init(&stu, 4); suba_init(&sub, 4); cca_init(&cls, 4); sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    CHECK(stu.size == n_stu, "TC07a: students count khop sau save/reload");
    CHECK(sub.size == n_sub, "TC07b: subjects count khop sau save/reload");
    CHECK(cls.size == n_cls, "TC07c: classes count khop sau save/reload");
    CHECK(sc.size == n_sc,   "TC07d: scores count khop sau save/reload");

    int i = sa_find(&stu, "202400010");
    CHECK(i >= 0, "TC07e: sau reload van tim thay MSSV 202400010");
    if (i >= 0)
        CHECK(strcmp(stu.data[i].hoTen, "Tran Van Nam") == 0,
            "TC07f: sau reload hoTen cua 202400010 van chinh xac");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 4: File không tồn tại (TC08)
static void test_missing_file(void) {
    printf("\n[NHOM 4] File khong ton tai\n");
    printf("  (dong [CANH BAO] sau la binh thuong)\n");

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/FILE_KHONG_TON_TAI.txt");
    CHECK(stu.size == 0, "TC08: load file khong ton tai -> mang rong, khong crash");
    sa_clear(&stu);
}


//Nhóm 5: Dữ liệu sai định dạng (TC09)
static void test_bad_format(void) {
    printf("\n[NHOM 5] Du lieu sai dinh dang\n");
    printf("  (cac dong [CANH BAO] sau la binh thuong)\n");

    //Tạo file tạm: 1 dòng hợp lệ + 3 dòng lỗi
    FILE *f = fopen("data/tmp_test.txt", "w");
    if (f == NULL) {
        printf("  [SKIP] khong tao duoc file tam, bo qua nhom nay\n");
        return;
    }
    fprintf(f, "MSSV|HoTen|Lop|Birthday\n");
    fprintf(f, "999001|Nguyen Test|K99|01/01/2000\n"); //hợp lệ
    fprintf(f, "THIEU|Chi co hai truong\n");            //thiếu trường
    fprintf(f, "|Ho Ten|K99|01/01/2000\n");             //MSSV rỗng
    fprintf(f, "999001|Trung Khoa|K99|01/01/2000\n");  //trùng MSSV
    fclose(f);

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/tmp_test.txt");

    CHECK(stu.size == 1, "TC09a: chi load 1 ban ghi hop le, bo qua 3 dong loi");
    if (stu.size >= 1)
        CHECK(strcmp(stu.data[0].mssv, "999001") == 0, "TC09b: ban ghi hop le load dung MSSV");

    sa_clear(&stu);
    remove("data/tmp_test.txt");
}


//Nhóm 6: Toàn vẹn tham chiếu FK (TC10)
static void test_fk_integrity(void) {
    printf("\n[NHOM 6] Toan ven tham chieu FK\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //TC10a: mỗi score phải có MSSV và MaLHP hợp lệ
    int ok_sc = 1;
    for (int i = 0; i < sc.size; i++) {
        if (sa_find(&stu, sc.data[i].mssv) < 0) { ok_sc = 0; break; }
        if (cca_find(&cls, sc.data[i].maLHP) < 0) { ok_sc = 0; break; }
    }
    CHECK(ok_sc, "TC10a: moi score co MSSV va MaLHP hop le");

    //TC10b: mỗi CourseClass phải có MaHP hợp lệ
    int ok_cls = 1;
    for (int i = 0; i < cls.size; i++) {
        if (suba_find(&sub, cls.data[i].maHP) < 0) { ok_cls = 0; break; }
    }
    CHECK(ok_cls, "TC10b: moi CourseClass co MaHP hop le trong subjects");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 7: Arrays edge cases (TC11)
static void test_arrays_edge_cases(void) {
    printf("\n[NHOM 7] Arrays edge cases\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //Tìm khóa không tồn tại phải trả -1
    CHECK(sa_find(&stu, "KHONGTONTAI") == -1, "TC11a: sa_find khoa khong ton tai -> -1");
    CHECK(suba_find(&sub, "KHONGTONTAI") == -1, "TC11b: suba_find khoa khong ton tai -> -1");
    CHECK(cca_find(&cls, "KHONGTONTAI") == -1, "TC11c: cca_find khoa không ton tai -> -1");
    CHECK(sca_find(&sc, "AAA", "BBB") == -1, "TC11d: sca_find khoa khong ton tai -> -1");

    //sa_get index ngoài phạm vi phải trả NULL
    CHECK(sa_get(&stu, -1) == NULL, "TC11e: sa_get(-1) -> NULL");
    CHECK(sa_get(&stu, stu.size) == NULL, "TC11f: sa_get(size) -> NULL");

    //sa_remove và sa_update với index sai phải trả 0
    CHECK(sa_remove(&stu, -1) == 0, "TC11g: sa_remove(-1) -> 0");
    CHECK(sa_remove(&stu, stu.size) == 0, "TC11h: sa_remove(size) -> 0");
    CHECK(sa_update(&stu, -1, stu.data[0]) == 0, "TC11i: sa_update(-1) -> 0");
    CHECK(sa_update(&stu, stu.size, stu.data[0]) == 0, "TC11j: sa_update(size) -> 0");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


int main(void) {
    printf("  KIEM THU TV1: arrays + fileio\n");

    test_load_basic();
    test_scores();
    test_save_reload();
    test_missing_file();
    test_bad_format();
    test_fk_integrity();
    test_arrays_edge_cases();

    if (g_fail == 0)
        printf("  KET QUA: %d PASS -- TAT CA DUNG!\n", g_pass);
    else
        printf("  KET QUA: %d PASS, %d FAIL -- CO LOI!\n", g_pass, g_fail);

    return (g_fail > 0) ? 1 : 0;
}