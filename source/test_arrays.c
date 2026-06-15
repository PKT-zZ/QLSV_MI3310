//Test: các hàm sa_* trong arrays.c 
#include <stdio.h>
#include <string.h>
#include "arrays.h"

int pass_arr = 0, fail_arr = 0;
void check_arr(int cond, const char* msg) {
    if (cond) { printf("  [PASS] %s\n", msg); pass_arr++; }
    else { printf("  [FAIL] %s\n", msg); fail_arr++; }
}

int main() {
    printf("[UNIT TEST] arrays.c\n");

    StudentArray arr;
    sa_init(&arr, 2);
    check_arr(arr.size == 0 && arr.capacity == 2, "Khoi tao mang rong chuan xac");

    Student s1; strcpy(s1.mssv, "SV001");
    Student s2; strcpy(s2.mssv, "SV002");
    Student s3; strcpy(s3.mssv, "SV003");

    sa_add(&arr, s1);
    sa_add(&arr, s2);
    check_arr(arr.size == 2, "Them 2 sinh vien, size == 2");

    sa_add(&arr, s3); //vượt capacity ban đầu -> phải tự resize
    check_arr(arr.size == 3 && arr.capacity >= 3, "Them vuot capacity -> tu resize, khong crash");

    int idx = sa_find(&arr, "SV002");
    check_arr(idx == 1, "Tim thay SV002 o index 1");
    check_arr(sa_find(&arr, "KHONGCO") == -1, "Tim khoa khong ton tai -> -1");

    //Edge case: index ngoài phạm vi
    check_arr(sa_get(&arr, -1) == NULL, "sa_get(-1) -> NULL");
    check_arr(sa_get(&arr, arr.size) == NULL, "sa_get(size) -> NULL");
    check_arr(sa_remove(&arr, arr.size) == 0, "sa_remove(size) -> 0");

    sa_remove(&arr, 0);
    check_arr(arr.size == 2, "Xoa 1 sinh vien, size giam xuong 2");
    check_arr(strcmp(arr.data[0].mssv, "SV002") == 0, "Don mang sang trai dung");

    sa_clear(&arr);
    check_arr(arr.data == NULL && arr.size == 0, "Giai phong bo nho thanh cong");

    printf("KET QUA: %d PASS, %d FAIL\n\n", pass_arr, fail_arr);
    return fail_arr > 0 ? 1 : 0;
}
