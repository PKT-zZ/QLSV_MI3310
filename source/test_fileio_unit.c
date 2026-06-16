//Test: loadStudents/saveStudents trong fileio.c
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "fileio.h"

int pass_io = 0, fail_io = 0;
void check_io(int cond, const char* msg) {
    if (cond) { printf("  [PASS] %s\n", msg); pass_io++; }
    else { printf("  [FAIL] %s\n", msg); fail_io++; }
}

int main() {
    printf("[UNIT TEST] fileio.c (doc/ghi doc lap, khong dung data/)\n");

    const char* tmp_in  = "unit_tmp_in.txt";
    const char* tmp_out = "unit_tmp_out.txt";

    //Test 1: đọc 1 dòng hợp lệ
    FILE* f = fopen(tmp_in, "w");
    if (f == NULL) {
        printf("  [SKIP] khong tao duoc file tam\n");
    } else {
        fprintf(f, "MSSV|HoTen|Lop|Birthday\n");
        fprintf(f, "2020007|Test|K68|01/01/2000\n");
        fclose(f);

        StudentArray arr;
        sa_init(&arr, 4);
        loadStudents(&arr, tmp_in);
        check_io(arr.size == 1, "Doc duoc 1 dong hop le tu file tam");
        if (arr.size > 0) {
            check_io(strcmp(arr.data[0].mssv, "2020007") == 0, "Lay dung MSSV");
            check_io(strcmp(arr.data[0].hoTen, "Test") == 0, "Lay dung HoTen");
        }
        sa_clear(&arr);
        remove(tmp_in);
    }

    //Test 2: dòng lỗi (thiếu trường, trùng MSSV) bị bỏ qua
    f = fopen(tmp_in, "w");
    if (f == NULL) {
        printf("  [SKIP] khong tao duoc file tam\n");
    } else {
        fprintf(f, "MSSV|HoTen|Lop|Birthday\n");
        fprintf(f, "6767|Sinh Vien A|K68|01/01/2000\n"); //hop le
        fprintf(f, "THIEU|Chi co 2 truong\n"); //thieu truong -> bo qua
        fprintf(f, "6767|A Nhan Ban|K68|01/01/2000\n"); //trung MSSV -> bo qua

        fclose(f);

        StudentArray arr;
        sa_init(&arr, 4);
        loadStudents(&arr, tmp_in);
        check_io(arr.size == 1, "Dong thieu truong va dong trung MSSV bi bo qua");
        sa_clear(&arr);
        remove(tmp_in);
    }

    //Test 3: save rồi load lại
    {
        StudentArray arr;
        sa_init(&arr, 4);
        Student s1; strcpy(s1.mssv, "111"); strcpy(s1.hoTen, "Nguyen A");
        strcpy(s1.lop, "K68"); strcpy(s1.birthday, "01/01/2000");
        Student s2; strcpy(s2.mssv, "222"); strcpy(s2.hoTen, "Tran B");
        strcpy(s2.lop, "K68"); strcpy(s2.birthday, "02/02/2000");
        sa_add(&arr, s1);
        sa_add(&arr, s2);

        saveStudents(&arr, tmp_out);
        sa_clear(&arr);

        StudentArray arr2;
        sa_init(&arr2, 4);
        loadStudents(&arr2, tmp_out);
        check_io(arr2.size == 2, "Save roi load lai -> dung 2 ban ghi");
        if (arr2.size == 2) {
            check_io(strcmp(arr2.data[1].hoTen, "Tran B") == 0, "Du lieu round-trip dung");
        }
        sa_clear(&arr2);
        remove(tmp_out);
    }

    printf("KET QUA: %d PASS, %d FAIL\n\n", pass_io, fail_io);
    return fail_io > 0 ? 1 : 0;
}
