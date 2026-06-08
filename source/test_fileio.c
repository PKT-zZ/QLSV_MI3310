//Kiểm thử module arrays và fileio
//Chạy từ thư mục gốc project
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "fileio.h"

int pass = 0, fail = 0;

//In kết quả test và đếm pass/fail
void check(int cond, const char* msg) {
    if (cond) { printf("  [PASS] %s\n", msg); pass++; }
    else { printf("  [FAIL] %s\n", msg); fail++; }
}

static float f_abs(float x) { return (x < 0.0f) ? -x : x; }


//Nhóm 1: Load dữ liệu cơ bản (số lượng + nội dung)
static void test_load_basic(void) {
    printf("\n[NHOM 1] Load du lieu co ban\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //Kiểm tra số lượng bản ghi
    check(stu.size == 6, "Load duoc 6 sinh vien");
    check(sub.size == 5, "Load duoc 5 mon hoc");
    check(cls.size == 5, "Load duoc 5 lop hoc phan");
    check(sc.size == 22, "Load duoc 22 ban ghi diem");

    //Kiểm tra nội dung sinh viên đầu tiên
    int i = sa_find(&stu, "202400000");
    check(i >= 0, "Tim thay MSSV 202400000");
    if (i >= 0) {
        check(strcmp(stu.data[i].hoTen, "Nguyen Van Toan") == 0, "hoTen cua 202400000 dung");
        check(strcmp(stu.data[i].lop, "K69-MI1-01") == 0, "lop cua 202400000 dung");
        check(strcmp(stu.data[i].birthday, "15/08/2006") == 0, "birthday cua 202400000 dung");
    }

    //Kiểm tra môn học
    int j = suba_find(&sub, "MI3310");
    check(j >= 0, "tim thay MaHP MI3310");
    if (j >= 0)
        check(sub.data[j].soTinChi == 2, "MI3310 co 2 tin chi");

    //Kiểm tra lớp học phần
    int k = cca_find(&cls, "169313");
    check(k >= 0, "tim thay MaLHP 169313");
    if (k >= 0) {
        check(strcmp(cls.data[k].maHP, "MI3310") == 0, "169313 thuoc mon MI3310");
        check(cls.data[k].hocKy == 1, "169313 la hoc ky 1");
        check(cls.data[k].namHoc == 2025, "169313 nam hoc 2025");
    }

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 2: Điểm số
static void test_scores(void) {
    printf("\n[NHOM 2] Diem so\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //Kiểm tra giá trị bản ghi điểm cụ thể
    int i = sca_find(&sc, "202400000", "169313");
    check(i >= 0, "tim thay diem cua (202400000, 169313)");
    if (i >= 0) {
        float qt = sc.data[i].diemQT;
        float ck = sc.data[i].diemCK;
        float tk = sc.data[i].diemTK;
        check(qt >= 0.0f && qt <= 10.0f, "DiemQT trong khoang [0, 10]");
        check(ck >= 0.0f && ck <= 10.0f, "DiemCK trong khoang [0, 10]");
        check(feq(tk, 0.5f*qt + 0.5f*ck), "DiemTK = 0.5*QT + 0.5*CK");
        check(sc.data[i].diemHe4 >= 0.0f && sc.data[i].diemHe4 <= 4.0f, "DiemHe4 trong khoang [0, 4]");
    }

    //Tìm bản ghi không tồn tại phải ra -1
    check(sca_find(&sc, "000000000", "000000") == -1, "tim khoa khong ton tai -> -1");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 3: Save rồi reload, kiểm tra dữ liệu không bị mất
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

    //Load lại lần 2
    sa_init(&stu, 4); suba_init(&sub, 4); cca_init(&cls, 4); sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    check(stu.size == n_stu, "So sinh vien khop sau save/reload");
    check(sub.size == n_sub, "So mon hoc khop sau save/reload");
    check(cls.size == n_cls, "So lop hoc phan khop sau save/reload");
    check(sc.size == n_sc, "So ban ghi diem khop sau save/reload");

    int i = sa_find(&stu, "202400010");
    check(i >= 0, "Sau reload van tim thay MSSV 202400010");
    if (i >= 0)
        check(strcmp(stu.data[i].hoTen, "Tran Van Nam") == 0, "hoTen cua 202400010 van dung sau reload");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 4: File không tồn tại phải chạy bình thường, không crash
static void test_missing_file(void) {
    printf("\n[NHOM 4] File khong ton tai\n");
    printf("  (dong [CANH BAO] sau la binh thuong)\n");

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/FILE_KHONG_TON_TAI.txt");
    check(stu.size == 0, "Load file khong ton tai -> mang rong, khong crash");
    sa_clear(&stu);
}


//Nhóm 5: Dữ liệu sai định dạng trong file phải bị bỏ qua
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
    fprintf(f, "THIEU|Chi co 2 truong\n"); //thiếu trường
    fprintf(f, "|Ho Ten|K99|01/01/2000\n"); //MSSV rỗng
    fprintf(f, "999001|Trung Khoa|K99|01/01/2000\n"); //trùng MSSV
    fclose(f);

    StudentArray stu; sa_init(&stu, 4);
    loadStudents(&stu, "data/tmp_test.txt");

    check(stu.size == 1, "chi load 1 ban ghi hop le, bo qua 3 dong loi");
    if (stu.size >= 1)
        check(strcmp(stu.data[0].mssv, "999001") == 0, "ban ghi hop le load dung MSSV");

    sa_clear(&stu);
    remove("data/tmp_test.txt");
}


//Nhóm 6: Toàn vẹn khóa ngoại sau loadAllData
static void test_fk_integrity(void) {
    printf("\n[NHOM 6] Toan ven khoa ngoai\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //Mỗi bản ghi điểm phải có MSSV và MaLHP hợp lệ
    int ok_sc = 1;
    for (int i = 0; i < sc.size; i++) {
        if (sa_find(&stu, sc.data[i].mssv) < 0) { ok_sc = 0; break; }
        if (cca_find(&cls, sc.data[i].maLHP) < 0) { ok_sc = 0; break; }
    }
    check(ok_sc, "Moi ban ghi diem co MSSV va MaLHP hop le");

    //Mỗi lớp học phần phải có MaHP hợp lệ
    int ok_cls = 1;
    for (int i = 0; i < cls.size; i++) {
        if (suba_find(&sub, cls.data[i].maHP) < 0) { ok_cls = 0; break; }
    }
    check(ok_cls, "moi lop hoc phan co MaHP hop le trong subjects");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


//Nhóm 7: Các trường hợp biên của mảng
static void test_arrays_edge_cases(void) {
    printf("\n[NHOM 7] Arrays edge cases\n");

    StudentArray stu; sa_init(&stu, 4);
    SubjectArray sub; suba_init(&sub, 4);
    CourseClassArray cls; cca_init(&cls, 4);
    ScoreArray sc; sca_init(&sc, 4);
    loadAllData(&stu, &sub, &cls, &sc);

    //Tìm khóa không tồn tại phải ra -1
    check(sa_find(&stu, "KHONGTONTAI") == -1, "sa_find khoa khong ton tai -> -1");
    check(suba_find(&sub, "KHONGTONTAI") == -1, "suba_find khoa khong ton tai -> -1");
    check(cca_find(&cls, "KHONGTONTAI") == -1, "cca_find khoa khong ton tai -> -1");
    check(sca_find(&sc, "AAA", "BBB") == -1, "sca_find khoa khong ton tai -> -1");

    //Index ngoài phạm vi phải trả NULL hoặc 0
    check(sa_get(&stu, -1) == NULL, "sa_get(-1) -> NULL");
    check(sa_get(&stu, stu.size) == NULL, "sa_get(size) -> NULL");
    check(sa_remove(&stu, -1) == 0, "sa_remove(-1) -> 0");
    check(sa_remove(&stu, stu.size) == 0, "sa_remove(size) -> 0");
    check(sa_update(&stu, -1, stu.data[0]) == 0, "sa_update(-1) -> 0");
    check(sa_update(&stu, stu.size, stu.data[0]) == 0, "sa_update(size) -> 0");

    sa_clear(&stu); suba_clear(&sub); cca_clear(&cls); sca_clear(&sc);
}


int main() {
    printf("KIEM THU TV1: arrays + fileio\n");
    test_load_basic();
    test_scores();
    test_save_reload();
    test_missing_file();
    test_bad_format();
    test_fk_integrity();
    test_arrays_edge_cases();

    printf("\n");
    if (fail == 0)
        printf("KET QUA: %d/%d PASS -- tat ca dung!\n", pass, pass + fail);
    else
        printf("KET QUA: %d PASS, %d FAIL -- co loi!\n", pass, fail);

    return 0;
}