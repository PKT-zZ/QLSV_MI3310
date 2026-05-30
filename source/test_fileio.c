/* test_fileio.c - Kiem tra module fileio.h / fileio.c
   Chay tu thu muc goc project:
   gcc source/arrays.c source/fileio.c source/test_fileio.c -Isource -o test_fileio
   .\test_fileio.exe
*/
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "fileio.h"

static int g_pass = 0, g_fail = 0;

/* Tinh gia tri tuyet doi cua float, tranh can include math.h */
static float my_abs(float x) { return x < 0 ? -x : x; }

#define CHECK(dieu_kien, mo_ta)                             \
    do {                                                     \
        if (dieu_kien) {                                     \
            printf("  [PASS] %s\n", mo_ta);                 \
            g_pass++;                                        \
        } else {                                             \
            printf("  [FAIL] %s\n", mo_ta);                 \
            g_fail++;                                        \
        }                                                    \
    } while(0)

/* -------------------------------------------------- */
void test_load_basic(void) {
    printf("\n[NHOM 1] Load du lieu co ban\n");

    StudentArray     stu; sa_init(&stu, 4);
    SubjectArray     sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray       sc;  sca_init(&sc, 4);

    loadAllData(&stu, &sub, &cls, &sc);

    /* Dem so ban ghi */
    CHECK(stu.size == 6,  "students.size == 6");
    CHECK(sub.size == 5,  "subjects.size == 5");
    CHECK(cls.size == 5,  "classes.size  == 5");
    CHECK(sc.size  == 22, "scores.size   == 22");

    /* Kiem tra noi dung sinh vien dau tien */
    int i = sa_find(&stu, "202400000");
    CHECK(i >= 0, "Tim thay MSSV 202400000");
    if (i >= 0) {
        CHECK(strcmp(stu.data[i].hoTen, "Nguyen Van Toan") == 0,
              "hoTen cua 202400000 la 'Nguyen Van Toan'");
        CHECK(strcmp(stu.data[i].lop, "K69-MI1-01") == 0,
              "lop cua 202400000 la 'K69-MI1-01'");
        CHECK(strcmp(stu.data[i].birthday, "15/08/2006") == 0,
              "birthday cua 202400000 la '15/08/2006'");
    }

    /* Kiem tra mon hoc */
    int j = suba_find(&sub, "MI3310");
    CHECK(j >= 0, "Tim thay MaHP MI3310");
    if (j >= 0)
        CHECK(sub.data[j].soTinChi == 2, "MI3310 soTinChi == 2");

    /* Kiem tra lop hoc phan */
    int k = cca_find(&cls, "169313");
    CHECK(k >= 0, "Tim thay MaLHP 169313");
    if (k >= 0) {
        CHECK(strcmp(cls.data[k].maHP, "MI3310") == 0,
              "169313 tham chieu dung den MI3310");
        CHECK(cls.data[k].hocKy  == 1,    "169313 hocKy == 1");
        CHECK(cls.data[k].namHoc == 2025, "169313 namHoc == 2025");
    }

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}

/* -------------------------------------------------- */
void test_scores(void) {
    printf("\n[NHOM 2] Diem so\n");

    StudentArray     stu; sa_init(&stu, 4);
    SubjectArray     sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray       sc;  sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    /* Kiem tra ban ghi diem cu the */
    int i = sca_find(&sc, "202400000", "169313");
    CHECK(i >= 0, "Tim thay score (202400000, 169313)");
    if (i >= 0) {
        float qt = sc.data[i].diemQT;
        float ck = sc.data[i].diemCK;
        float tk = sc.data[i].diemTK;
        float h4 = sc.data[i].diemHe4;

        CHECK(qt >= 0.0f && qt <= 10.0f, "DiemQT nam trong [0, 10]");
        CHECK(ck >= 0.0f && ck <= 10.0f, "DiemCK nam trong [0, 10]");
        CHECK(my_abs(tk - (0.5f*qt + 0.5f*ck)) < 0.01f,
              "DiemTK == 0.5*DiemQT + 0.5*DiemCK");
        CHECK(h4 >= 0.0f && h4 <= 4.0f, "DiemHe4 nam trong [0, 4]");
    }

    /* Khoa khong ton tai phai tra ve -1 */
    CHECK(sca_find(&sc, "000000000", "000000") == -1,
          "sca_find khoa khong ton tai -> -1");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}

/* -------------------------------------------------- */
void test_save_reload(void) {
    printf("\n[NHOM 3] Save -> Reload\n");

    StudentArray     stu; sa_init(&stu, 4);
    SubjectArray     sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray       sc;  sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    int n_stu = stu.size, n_sub = sub.size;
    int n_cls = cls.size, n_sc  = sc.size;

    /* Luu xuong file */
    saveAllData(&stu, &sub, &cls, &sc);
    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);

    /* Load lai */
    sa_init(&stu, 4); suba_init(&sub, 4);
    cca_init(&cls, 4); sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    CHECK(stu.size == n_stu, "students: so luong khop sau save/reload");
    CHECK(sub.size == n_sub, "subjects: so luong khop sau save/reload");
    CHECK(cls.size == n_cls, "classes:  so luong khop sau save/reload");
    CHECK(sc.size  == n_sc,  "scores:   so luong khop sau save/reload");

    int i = sa_find(&stu, "202400010");
    CHECK(i >= 0, "Sau reload: van tim thay MSSV 202400010");
    if (i >= 0)
        CHECK(strcmp(stu.data[i].hoTen, "Tran Van Nam") == 0,
              "Sau reload: hoTen cua 202400010 chinh xac");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}

/* -------------------------------------------------- */
void test_missing_file(void) {
    printf("\n[NHOM 4] File khong ton tai\n");
    printf("  (Chuong trinh se in [CANH BAO] - do la binh thuong)\n");

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/khong_ton_tai.txt");

    CHECK(stu.size == 0,
          "Load file khong ton tai -> mang rong, khong crash");

    sa_clear(&stu);
}

/* -------------------------------------------------- */
void test_bad_format(void) {
    printf("\n[NHOM 5] Du lieu sai dinh dang\n");
    printf("  (Chuong trinh se in [CANH BAO] cho dong loi - binh thuong)\n");

    /* Tao file tam voi 1 dong hop le + 3 dong loi */
    FILE* f = fopen("data/tmp_test.txt", "w");
    if (f == NULL) {
        printf("  [SKIP] Khong tao duoc file tam, bo qua nhom nay\n");
        return;
    }
    fprintf(f, "MSSV|HoTen|Lop|Birthday\n");
    fprintf(f, "999001|Nguyen Test|K99|01/01/2000\n"); /* Hop le */
    fprintf(f, "THIEU_TRUONG|Chi co hai truong\n");    /* Thieu truong */
    fprintf(f, "|Ho Ten|K99|01/01/2000\n");             /* MSSV rong */
    fprintf(f, "999001|Trung Khoa|K99|01/01/2000\n");  /* Trung MSSV */
    fclose(f);

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/tmp_test.txt");

    CHECK(stu.size == 1,
          "Chi load 1 ban ghi hop le, bo qua 3 dong loi");
    if (stu.size >= 1)
        CHECK(strcmp(stu.data[0].mssv, "999001") == 0,
              "Ban ghi hop le duoc load dung");

    sa_clear(&stu);
    remove("data/tmp_test.txt"); /* Xoa file tam */
}

/* -------------------------------------------------- */
void test_fk_integrity(void) {
    printf("\n[NHOM 6] Toan ven tham chieu (FK)\n");

    StudentArray     stu; sa_init(&stu, 4);
    SubjectArray     sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray       sc;  sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    /* Moi score phai co MSSV va MaLHP hop le */
    int ok_sc = 1;
    for (int i = 0; i < sc.size; i++) {
        if (sa_find(&stu,  sc.data[i].mssv)  < 0) { ok_sc = 0; break; }
        if (cca_find(&cls, sc.data[i].maLHP) < 0) { ok_sc = 0; break; }
    }
    CHECK(ok_sc, "Moi score co MSSV va MaLHP hop le");

    /* Moi CourseClass phai co MaHP hop le */
    int ok_cls = 1;
    for (int i = 0; i < cls.size; i++) {
        if (suba_find(&sub, cls.data[i].maHP) < 0) { ok_cls = 0; break; }
    }
    CHECK(ok_cls, "Moi CourseClass co MaHP hop le trong subjects");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}

/* -------------------------------------------------- */
void test_arrays_edge_cases(void) {
    printf("\n[NHOM 7] Bien bien arrays (edge cases)\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    /* Tim khoa khong ton tai */
    CHECK(sa_find(&stu,   "KHONGTONTAI")       == -1, "sa_find  khoa khong ton tai -> -1");
    CHECK(suba_find(&sub, "KHONGTONTAI")        == -1, "suba_find khoa khong ton tai -> -1");
    CHECK(cca_find(&cls,  "KHONGTONTAI")        == -1, "cca_find  khoa khong ton tai -> -1");
    CHECK(sca_find(&sc,   "AAA", "BBB")         == -1, "sca_find  khoa khong ton tai -> -1");

    /* Index ngoai pham vi */
    CHECK(sa_get(&stu, -1)        == NULL, "sa_get(-1) -> NULL");
    CHECK(sa_get(&stu, stu.size)  == NULL, "sa_get(size) -> NULL (out of bound)");

    /* Thao tac loi phai tra ve 0 */
    CHECK(sa_remove(&stu, -1)     == 0, "sa_remove(-1) -> 0");
    CHECK(sa_remove(&stu, stu.size) == 0, "sa_remove(size) -> 0");

    Student dummy = stu.data[0];
    CHECK(sa_update(&stu, -1, dummy)       == 0, "sa_update(-1) -> 0");
    CHECK(sa_update(&stu, stu.size, dummy) == 0, "sa_update(size) -> 0");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}

/* -------------------------------------------------- */
int main(void) {
    printf("==========================================\n");
    printf("  KIEM TRA fileio.h / fileio.c\n");
    printf("==========================================\n");

    test_load_basic();
    test_scores();
    test_save_reload();
    test_missing_file();
    test_bad_format();
    test_fk_integrity();
    test_arrays_edge_cases();

    printf("\n==========================================\n");
    if (g_fail == 0)
        printf("  KET QUA: %d PASS -- TAT CA DUNG!\n", g_pass);
    else
        printf("  KET QUA: %d PASS, %d FAIL -- CO LOI!\n", g_pass, g_fail);
    printf("==========================================\n");

    return (g_fail > 0) ? 1 : 0;
}