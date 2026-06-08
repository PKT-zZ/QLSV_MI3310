#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ui.h"

/* =========================================================
   HAM TIEN ICH NHAP DU LIEU VA VALIDATION
   ========================================================= */

static void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

static void removeNewline(char* s) {
    size_t len;
    if (s == NULL) return;

    len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

static int isEmptyString(const char* s) {
    if (s == NULL) return 1;

    while (*s != '\0') {
        if (!isspace((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}

void readLine(const char* message, char* buffer, int size) {
    while (1) {
        size_t len;

        printf("%s", message);

        if (fgets(buffer, size, stdin) == NULL) {
            printf("Loi nhap du lieu. Vui long nhap lai.\n");
            continue;
        }

        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] != '\n') {
            clearInputBuffer();
        }

        removeNewline(buffer);

        if (isEmptyString(buffer)) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        return;
    }
}

static int readLineOptional(const char* message, char* buffer, int size) {
    size_t len;

    printf("%s", message);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return 0;
    }

    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] != '\n') {
        clearInputBuffer();
    }

    removeNewline(buffer);
    return !isEmptyString(buffer);
}

int readInt(const char* message) {
    char buffer[100];
    char* end;
    long value;

    while (1) {
        printf("%s", message);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Loi nhap du lieu. Vui long nhap lai.\n");
            continue;
        }

        removeNewline(buffer);
        value = strtol(buffer, &end, 10);

        if (buffer[0] != '\0' && *end == '\0') {
            return (int)value;
        }

        printf("Nhap sai dinh dang. Vui long nhap so nguyen.\n");
    }
}

static int readIntRange(const char* message, int min, int max) {
    int value;

    while (1) {
        value = readInt(message);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Gia tri phai nam trong khoang [%d, %d].\n", min, max);
    }
}

float readFloat(const char* message) {
    char buffer[100];
    char* end;
    float value;

    while (1) {
        printf("%s", message);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Loi nhap du lieu. Vui long nhap lai.\n");
            continue;
        }

        removeNewline(buffer);
        value = strtof(buffer, &end);

        if (buffer[0] != '\0' && *end == '\0') {
            return value;
        }

        printf("Nhap sai dinh dang. Vui long nhap so thuc.\n");
    }
}

static float readFloatRange(const char* message, float min, float max) {
    float value;

    while (1) {
        value = readFloat(message);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Gia tri phai nam trong khoang [%.2f, %.2f].\n", min, max);
    }
}

int validateMSSV(const char* mssv) {
    int len;

    if (mssv == NULL) return 0;
    len = (int)strlen(mssv);

    if (len == 0 || len >= 12) return 0;

    for (int i = 0; i < len; i++) {
        if (!isdigit((unsigned char)mssv[i])) return 0;
    }

    return 1;
}

static int validateCode(const char* code, int maxLen) {
    int len;

    if (code == NULL) return 0;
    len = (int)strlen(code);

    return len > 0 && len < maxLen;
}

int validateScore(float score) {
    return score >= 0.0f && score <= 10.0f;
}

static int validateSemester(int hocKy) {
    return hocKy >= 1 && hocKy <= 3;
}

static int validateYear(int year) {
    return year >= 2000 && year <= 2100;
}

static int validateCredit(int credit) {
    return credit > 0 && credit <= 10;
}

static int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

static int daysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

int validateDate(const char* date) {
    int day, month, year;

    if (date == NULL) return 0;
    if (strlen(date) != 10) return 0;
    if (date[2] != '/' || date[5] != '/') return 0;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit((unsigned char)date[i])) return 0;
    }

    if (sscanf(date, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        return 0;
    }

    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > daysInMonth(month, year)) return 0;

    return 1;
}

static float calcDiemTK(float diemQT, float diemCK) {
    return 0.5f * diemQT + 0.5f * diemCK;
}

static float quyDoiHe4(float diemTK) {
    if (diemTK >= 8.5f) return 4.0f;
    if (diemTK >= 8.0f) return 3.5f;
    if (diemTK >= 7.0f) return 3.0f;
    if (diemTK >= 6.5f) return 2.5f;
    if (diemTK >= 5.5f) return 2.0f;
    if (diemTK >= 5.0f) return 1.5f;
    if (diemTK >= 4.0f) return 1.0f;
    return 0.0f;
}

static void pauseScreen(void) {
    printf("\nNhan Enter de tiep tuc...");
    getchar();
}

/* =========================================================
   HIEN THI DU LIEU
   ========================================================= */

void displayStudents(StudentArray* students) {
    printf("\n==================== DANH SACH SINH VIEN ====================\n");
    printf("%-12s | %-25s | %-12s | %-12s\n", "MSSV", "Ho ten", "Lop", "Birthday");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < students->size; i++) {
        Student* s = &students->data[i];
        printf("%-12s | %-25s | %-12s | %-12s\n",
               s->mssv, s->hoTen, s->lop, s->birthday);
    }

    printf("Tong so sinh vien: %d\n", students->size);
}

void displaySubjects(SubjectArray* subjects) {
    printf("\n==================== DANH SACH MON HOC ====================\n");
    printf("%-10s | %-35s | %-8s\n", "MaHP", "Ten hoc phan", "So TC");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < subjects->size; i++) {
        Subject* s = &subjects->data[i];
        printf("%-10s | %-35s | %-8d\n", s->maHP, s->tenHP, s->soTinChi);
    }

    printf("Tong so mon hoc: %d\n", subjects->size);
}

void displayCourseClasses(CourseClassArray* classes) {
    printf("\n==================== DANH SACH LOP HOC PHAN ====================\n");
    printf("%-15s | %-10s | %-8s | %-8s\n", "MaLHP", "MaHP", "Hoc ky", "Nam hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < classes->size; i++) {
        CourseClass* c = &classes->data[i];
        printf("%-15s | %-10s | %-8d | %-8d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
    }

    printf("Tong so lop hoc phan: %d\n", classes->size);
}

void displayScores(ScoreArray* scores) {
    printf("\n==================== DANH SACH DIEM ====================\n");
    printf("%-12s | %-15s | %-8s | %-8s | %-8s | %-8s\n",
           "MSSV", "MaLHP", "DiemQT", "DiemCK", "DiemTK", "He4");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        printf("%-12s | %-15s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
               sc->mssv, sc->maLHP, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
    }

    printf("Tong so ban ghi diem: %d\n", scores->size);
}

/* =========================================================
   QUAN LY SINH VIEN
   ========================================================= */

static int studentHasScore(ScoreArray* scores, const char* mssv) {
    for (int i = 0; i < scores->size; i++) {
        if (strcmp(scores->data[i].mssv, mssv) == 0) return 1;
    }
    return 0;
}

static void addStudentUI(StudentArray* students) {
    Student s;

    while (1) {
        readLine("Nhap MSSV: ", s.mssv, sizeof(s.mssv));

        if (!validateMSSV(s.mssv)) {
            printf("MSSV khong hop le. MSSV chi gom chu so va toi da 11 ky tu.\n");
            continue;
        }

        if (sa_find(students, s.mssv) != -1) {
            printf("MSSV da ton tai. Vui long nhap MSSV khac.\n");
            continue;
        }

        break;
    }

    readLine("Nhap ho ten: ", s.hoTen, sizeof(s.hoTen));
    readLine("Nhap lop: ", s.lop, sizeof(s.lop));

    while (1) {
        readLine("Nhap ngay sinh DD/MM/YYYY: ", s.birthday, sizeof(s.birthday));
        if (validateDate(s.birthday)) break;
        printf("Ngay sinh khong hop le. Vi du dung: 15/08/2006\n");
    }

    if (sa_add(students, s)) {
        printf("Them sinh vien thanh cong.\n");
    } else {
        printf("Them sinh vien that bai do loi bo nho.\n");
    }
}

static void editStudentUI(StudentArray* students) {
    char mssv[12];
    char buffer[100];
    int index;

    readLine("Nhap MSSV can sua: ", mssv, sizeof(mssv));
    index = sa_find(students, mssv);

    if (index == -1) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }

    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("Ho ten moi: ", buffer, sizeof(buffer))) {
        strncpy(students->data[index].hoTen, buffer, sizeof(students->data[index].hoTen) - 1);
        students->data[index].hoTen[sizeof(students->data[index].hoTen) - 1] = '\0';
    }

    if (readLineOptional("Lop moi: ", buffer, sizeof(buffer))) {
        strncpy(students->data[index].lop, buffer, sizeof(students->data[index].lop) - 1);
        students->data[index].lop[sizeof(students->data[index].lop) - 1] = '\0';
    }

    while (1) {
        if (!readLineOptional("Ngay sinh moi DD/MM/YYYY: ", buffer, sizeof(buffer))) {
            break;
        }

        if (validateDate(buffer)) {
            strncpy(students->data[index].birthday, buffer, sizeof(students->data[index].birthday) - 1);
            students->data[index].birthday[sizeof(students->data[index].birthday) - 1] = '\0';
            break;
        }

        printf("Ngay sinh khong hop le. Vui long nhap lai hoac Enter de bo qua.\n");
    }

    printf("Sua sinh vien thanh cong.\n");
}

static void deleteStudentUI(StudentArray* students, ScoreArray* scores) {
    char mssv[12];
    int index;

    readLine("Nhap MSSV can xoa: ", mssv, sizeof(mssv));
    index = sa_find(students, mssv);

    if (index == -1) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }

    if (studentHasScore(scores, mssv)) {
        printf("Khong the xoa sinh vien vi da co ban ghi diem.\n");
        return;
    }

    if (sa_remove(students, index)) {
        printf("Xoa sinh vien thanh cong.\n");
    } else {
        printf("Xoa sinh vien that bai.\n");
    }
}

static void searchStudentUI(StudentArray* students) {
    int choice;
    char key[100];
    int found = 0;

    printf("\n1. Tim theo MSSV\n");
    printf("2. Tim theo ho ten\n");
    printf("3. Tim theo lop\n");
    choice = readIntRange("Nhap lua chon: ", 1, 3);

    readLine("Nhap tu khoa: ", key, sizeof(key));

    printf("\n%-12s | %-25s | %-12s | %-12s\n", "MSSV", "Ho ten", "Lop", "Birthday");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < students->size; i++) {
        Student* s = &students->data[i];
        int match = 0;

        if (choice == 1 && strcmp(s->mssv, key) == 0) match = 1;
        if (choice == 2 && strstr(s->hoTen, key) != NULL) match = 1;
        if (choice == 3 && strcmp(s->lop, key) == 0) match = 1;

        if (match) {
            printf("%-12s | %-25s | %-12s | %-12s\n", s->mssv, s->hoTen, s->lop, s->birthday);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay ket qua phu hop.\n");
}

void showStudentMenu(StudentArray* students, ScoreArray* scores) {
    int choice;

    do {
        printf("\n========== QUAN LY SINH VIEN =========="
               "\n1. Hien thi danh sach sinh vien"
               "\n2. Them sinh vien"
               "\n3. Sua sinh vien"
               "\n4. Xoa sinh vien"
               "\n5. Tim sinh vien"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: displayStudents(students); break;
            case 2: addStudentUI(students); break;
            case 3: editStudentUI(students); break;
            case 4: deleteStudentUI(students, scores); break;
            case 5: searchStudentUI(students); break;
            case 0: break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

/* =========================================================
   QUAN LY MON HOC
   ========================================================= */

static int subjectIsUsed(CourseClassArray* classes, const char* maHP) {
    for (int i = 0; i < classes->size; i++) {
        if (strcmp(classes->data[i].maHP, maHP) == 0) return 1;
    }
    return 0;
}

static void addSubjectUI(SubjectArray* subjects) {
    Subject s;

    while (1) {
        readLine("Nhap MaHP: ", s.maHP, sizeof(s.maHP));

        if (!validateCode(s.maHP, 10)) {
            printf("MaHP khong hop le.\n");
            continue;
        }

        if (suba_find(subjects, s.maHP) != -1) {
            printf("MaHP da ton tai.\n");
            continue;
        }

        break;
    }

    readLine("Nhap ten hoc phan: ", s.tenHP, sizeof(s.tenHP));

    while (1) {
        s.soTinChi = readInt("Nhap so tin chi: ");
        if (validateCredit(s.soTinChi)) break;
        printf("So tin chi khong hop le.\n");
    }

    if (suba_add(subjects, s)) {
        printf("Them mon hoc thanh cong.\n");
    } else {
        printf("Them mon hoc that bai.\n");
    }
}

static void editSubjectUI(SubjectArray* subjects) {
    char maHP[10];
    char buffer[100];
    int index;

    readLine("Nhap MaHP can sua: ", maHP, sizeof(maHP));
    index = suba_find(subjects, maHP);

    if (index == -1) {
        printf("Khong tim thay mon hoc.\n");
        return;
    }

    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("Ten hoc phan moi: ", buffer, sizeof(buffer))) {
        strncpy(subjects->data[index].tenHP, buffer, sizeof(subjects->data[index].tenHP) - 1);
        subjects->data[index].tenHP[sizeof(subjects->data[index].tenHP) - 1] = '\0';
    }

    if (readLineOptional("So tin chi moi: ", buffer, sizeof(buffer))) {
        int credit = atoi(buffer);
        if (validateCredit(credit)) {
            subjects->data[index].soTinChi = credit;
        } else {
            printf("So tin chi khong hop le, giu nguyen gia tri cu.\n");
        }
    }

    printf("Sua mon hoc thanh cong.\n");
}

static void deleteSubjectUI(SubjectArray* subjects, CourseClassArray* classes) {
    char maHP[10];
    int index;

    readLine("Nhap MaHP can xoa: ", maHP, sizeof(maHP));
    index = suba_find(subjects, maHP);

    if (index == -1) {
        printf("Khong tim thay mon hoc.\n");
        return;
    }

    if (subjectIsUsed(classes, maHP)) {
        printf("Khong the xoa mon hoc vi dang co lop hoc phan su dung MaHP nay.\n");
        return;
    }

    if (suba_remove(subjects, index)) {
        printf("Xoa mon hoc thanh cong.\n");
    } else {
        printf("Xoa mon hoc that bai.\n");
    }
}

static void searchSubjectUI(SubjectArray* subjects) {
    int choice;
    char key[100];
    int found = 0;

    printf("\n1. Tim theo MaHP\n");
    printf("2. Tim theo ten hoc phan\n");
    choice = readIntRange("Nhap lua chon: ", 1, 2);

    readLine("Nhap tu khoa: ", key, sizeof(key));

    printf("\n%-10s | %-35s | %-8s\n", "MaHP", "Ten hoc phan", "So TC");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < subjects->size; i++) {
        Subject* s = &subjects->data[i];
        int match = 0;

        if (choice == 1 && strcmp(s->maHP, key) == 0) match = 1;
        if (choice == 2 && strstr(s->tenHP, key) != NULL) match = 1;

        if (match) {
            printf("%-10s | %-35s | %-8d\n", s->maHP, s->tenHP, s->soTinChi);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay ket qua phu hop.\n");
}

void showSubjectMenu(SubjectArray* subjects,
                     CourseClassArray* classes,
                     ScoreArray* scores) {
    int choice;
    (void)scores;

    do {
        printf("\n========== QUAN LY MON HOC =========="
               "\n1. Hien thi danh sach mon hoc"
               "\n2. Them mon hoc"
               "\n3. Sua mon hoc"
               "\n4. Xoa mon hoc"
               "\n5. Tim mon hoc"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: displaySubjects(subjects); break;
            case 2: addSubjectUI(subjects); break;
            case 3: editSubjectUI(subjects); break;
            case 4: deleteSubjectUI(subjects, classes); break;
            case 5: searchSubjectUI(subjects); break;
            case 0: break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

/* =========================================================
   QUAN LY LOP HOC PHAN
   ========================================================= */

static int classHasScore(ScoreArray* scores, const char* maLHP) {
    for (int i = 0; i < scores->size; i++) {
        if (strcmp(scores->data[i].maLHP, maLHP) == 0) return 1;
    }
    return 0;
}

static void addCourseClassUI(CourseClassArray* classes, SubjectArray* subjects) {
    CourseClass c;

    while (1) {
        readLine("Nhap MaLHP: ", c.maLHP, sizeof(c.maLHP));

        if (!validateCode(c.maLHP, 15)) {
            printf("MaLHP khong hop le.\n");
            continue;
        }

        if (cca_find(classes, c.maLHP) != -1) {
            printf("MaLHP da ton tai.\n");
            continue;
        }

        break;
    }

    while (1) {
        readLine("Nhap MaHP: ", c.maHP, sizeof(c.maHP));

        if (suba_find(subjects, c.maHP) != -1) break;
        printf("MaHP khong ton tai trong danh sach mon hoc.\n");
    }

    while (1) {
        c.hocKy = readInt("Nhap hoc ky (1-3): ");
        if (validateSemester(c.hocKy)) break;
        printf("Hoc ky khong hop le.\n");
    }

    while (1) {
        c.namHoc = readInt("Nhap nam hoc: ");
        if (validateYear(c.namHoc)) break;
        printf("Nam hoc khong hop le.\n");
    }

    if (cca_add(classes, c)) {
        printf("Them lop hoc phan thanh cong.\n");
    } else {
        printf("Them lop hoc phan that bai.\n");
    }
}

static void editCourseClassUI(CourseClassArray* classes, SubjectArray* subjects) {
    char maLHP[15];
    char buffer[100];
    int index;

    readLine("Nhap MaLHP can sua: ", maLHP, sizeof(maLHP));
    index = cca_find(classes, maLHP);

    if (index == -1) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("MaHP moi: ", buffer, sizeof(buffer))) {
        if (suba_find(subjects, buffer) != -1) {
            strncpy(classes->data[index].maHP, buffer, sizeof(classes->data[index].maHP) - 1);
            classes->data[index].maHP[sizeof(classes->data[index].maHP) - 1] = '\0';
        } else {
            printf("MaHP khong ton tai, giu nguyen gia tri cu.\n");
        }
    }

    if (readLineOptional("Hoc ky moi: ", buffer, sizeof(buffer))) {
        int hocKy = atoi(buffer);
        if (validateSemester(hocKy)) classes->data[index].hocKy = hocKy;
        else printf("Hoc ky khong hop le, giu nguyen gia tri cu.\n");
    }

    if (readLineOptional("Nam hoc moi: ", buffer, sizeof(buffer))) {
        int namHoc = atoi(buffer);
        if (validateYear(namHoc)) classes->data[index].namHoc = namHoc;
        else printf("Nam hoc khong hop le, giu nguyen gia tri cu.\n");
    }

    printf("Sua lop hoc phan thanh cong.\n");
}

static void deleteCourseClassUI(CourseClassArray* classes, ScoreArray* scores) {
    char maLHP[15];
    int index;

    readLine("Nhap MaLHP can xoa: ", maLHP, sizeof(maLHP));
    index = cca_find(classes, maLHP);

    if (index == -1) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    if (classHasScore(scores, maLHP)) {
        printf("Khong the xoa lop hoc phan vi da co ban ghi diem.\n");
        return;
    }

    if (cca_remove(classes, index)) {
        printf("Xoa lop hoc phan thanh cong.\n");
    } else {
        printf("Xoa lop hoc phan that bai.\n");
    }
}

static void searchCourseClassUI(CourseClassArray* classes) {
    int choice;
    char key[100];
    int found = 0;

    printf("\n1. Tim theo MaLHP\n");
    printf("2. Tim theo MaHP\n");
    choice = readIntRange("Nhap lua chon: ", 1, 2);

    readLine("Nhap tu khoa: ", key, sizeof(key));

    printf("\n%-15s | %-10s | %-8s | %-8s\n", "MaLHP", "MaHP", "Hoc ky", "Nam hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < classes->size; i++) {
        CourseClass* c = &classes->data[i];
        int match = 0;

        if (choice == 1 && strcmp(c->maLHP, key) == 0) match = 1;
        if (choice == 2 && strcmp(c->maHP, key) == 0) match = 1;

        if (match) {
            printf("%-15s | %-10s | %-8d | %-8d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay ket qua phu hop.\n");
}

void showCourseClassMenu(CourseClassArray* classes,
                         SubjectArray* subjects,
                         ScoreArray* scores) {
    int choice;

    do {
        printf("\n========== QUAN LY LOP HOC PHAN =========="
               "\n1. Hien thi danh sach lop hoc phan"
               "\n2. Them lop hoc phan"
               "\n3. Sua lop hoc phan"
               "\n4. Xoa lop hoc phan"
               "\n5. Tim lop hoc phan"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: displayCourseClasses(classes); break;
            case 2: addCourseClassUI(classes, subjects); break;
            case 3: editCourseClassUI(classes, subjects); break;
            case 4: deleteCourseClassUI(classes, scores); break;
            case 5: searchCourseClassUI(classes); break;
            case 0: break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

/* =========================================================
   QUAN LY DIEM SO
   ========================================================= */

static void addScoreUI(ScoreArray* scores, StudentArray* students, CourseClassArray* classes) {
    ScoreRecord sc;

    while (1) {
        readLine("Nhap MSSV: ", sc.mssv, sizeof(sc.mssv));
        if (sa_find(students, sc.mssv) != -1) break;
        printf("MSSV khong ton tai trong danh sach sinh vien.\n");
    }

    while (1) {
        readLine("Nhap MaLHP: ", sc.maLHP, sizeof(sc.maLHP));
        if (cca_find(classes, sc.maLHP) != -1) break;
        printf("MaLHP khong ton tai trong danh sach lop hoc phan.\n");
    }

    if (sca_find(scores, sc.mssv, sc.maLHP) != -1) {
        printf("Ban ghi diem da ton tai. Hay dung chuc nang cap nhat diem.\n");
        return;
    }

    sc.diemQT = readFloatRange("Nhap diem qua trinh (0-10): ", 0.0f, 10.0f);
    sc.diemCK = readFloatRange("Nhap diem cuoi ky (0-10): ", 0.0f, 10.0f);
    sc.diemTK = calcDiemTK(sc.diemQT, sc.diemCK);
    sc.diemHe4 = quyDoiHe4(sc.diemTK);

    if (sca_add(scores, sc)) {
        printf("Them diem thanh cong. DiemTK = %.2f, He4 = %.2f\n", sc.diemTK, sc.diemHe4);
    } else {
        printf("Them diem that bai.\n");
    }
}

static void updateScoreUI(ScoreArray* scores) {
    char mssv[12];
    char maLHP[15];
    int index;

    readLine("Nhap MSSV: ", mssv, sizeof(mssv));
    readLine("Nhap MaLHP: ", maLHP, sizeof(maLHP));

    index = sca_find(scores, mssv, maLHP);
    if (index == -1) {
        printf("Khong tim thay ban ghi diem.\n");
        return;
    }

    scores->data[index].diemQT = readFloatRange("Nhap diem qua trinh moi (0-10): ", 0.0f, 10.0f);
    scores->data[index].diemCK = readFloatRange("Nhap diem cuoi ky moi (0-10): ", 0.0f, 10.0f);
    scores->data[index].diemTK = calcDiemTK(scores->data[index].diemQT, scores->data[index].diemCK);
    scores->data[index].diemHe4 = quyDoiHe4(scores->data[index].diemTK);

    printf("Cap nhat diem thanh cong. DiemTK = %.2f, He4 = %.2f\n",
           scores->data[index].diemTK, scores->data[index].diemHe4);
}

static void searchScoreUI(ScoreArray* scores) {
    int choice;
    char key1[100];
    char key2[100];
    int found = 0;

    printf("\n1. Tim theo MSSV\n");
    printf("2. Tim theo MaLHP\n");
    printf("3. Tim theo cap MSSV + MaLHP\n");
    choice = readIntRange("Nhap lua chon: ", 1, 3);

    if (choice == 1) {
        readLine("Nhap MSSV: ", key1, sizeof(key1));
    } else if (choice == 2) {
        readLine("Nhap MaLHP: ", key1, sizeof(key1));
    } else {
        readLine("Nhap MSSV: ", key1, sizeof(key1));
        readLine("Nhap MaLHP: ", key2, sizeof(key2));
    }

    printf("\n%-12s | %-15s | %-8s | %-8s | %-8s | %-8s\n",
           "MSSV", "MaLHP", "DiemQT", "DiemCK", "DiemTK", "He4");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        int match = 0;

        if (choice == 1 && strcmp(sc->mssv, key1) == 0) match = 1;
        if (choice == 2 && strcmp(sc->maLHP, key1) == 0) match = 1;
        if (choice == 3 && strcmp(sc->mssv, key1) == 0 && strcmp(sc->maLHP, key2) == 0) match = 1;

        if (match) {
            printf("%-12s | %-15s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
                   sc->mssv, sc->maLHP, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay ket qua phu hop.\n");
}

void showScoreMenu(ScoreArray* scores,
                   StudentArray* students,
                   CourseClassArray* classes) {
    int choice;

    do {
        printf("\n========== QUAN LY DIEM =========="
               "\n1. Hien thi danh sach diem"
               "\n2. Nhap diem"
               "\n3. Cap nhat diem"
               "\n4. Tim diem"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: displayScores(scores); break;
            case 2: addScoreUI(scores, students, classes); break;
            case 3: updateScoreUI(scores); break;
            case 4: searchScoreUI(scores); break;
            case 0: break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

/* =========================================================
   BAO CAO CO BAN
   ========================================================= */

static void showStudentScoreCard(StudentArray* students, ScoreArray* scores) {
    char mssv[12];
    int studentIndex;
    int found = 0;

    readLine("Nhap MSSV can xem bang diem: ", mssv, sizeof(mssv));
    studentIndex = sa_find(students, mssv);

    if (studentIndex == -1) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }

    printf("\nBang diem sinh vien: %s - %s\n", students->data[studentIndex].mssv, students->data[studentIndex].hoTen);
    printf("%-15s | %-8s | %-8s | %-8s | %-8s\n", "MaLHP", "DiemQT", "DiemCK", "DiemTK", "He4");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        if (strcmp(sc->mssv, mssv) == 0) {
            printf("%-15s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
                   sc->maLHP, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
            found = 1;
        }
    }

    if (!found) printf("Sinh vien nay chua co diem.\n");
}

static void showClassScoreTable(CourseClassArray* classes, ScoreArray* scores) {
    char maLHP[15];
    int classIndex;
    int found = 0;

    readLine("Nhap MaLHP can xem bang diem: ", maLHP, sizeof(maLHP));
    classIndex = cca_find(classes, maLHP);

    if (classIndex == -1) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    printf("\nBang diem lop hoc phan: %s\n", maLHP);
    printf("%-12s | %-8s | %-8s | %-8s | %-8s\n", "MSSV", "DiemQT", "DiemCK", "DiemTK", "He4");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        if (strcmp(sc->maLHP, maLHP) == 0) {
            printf("%-12s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
                   sc->mssv, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
            found = 1;
        }
    }

    if (!found) printf("Lop hoc phan nay chua co diem.\n");
}

static void showReportMenu(StudentArray* students,
                           CourseClassArray* classes,
                           ScoreArray* scores) {
    int choice;

    do {
        printf("\n========== BAO CAO =========="
               "\n1. Bang diem cua mot sinh vien"
               "\n2. Bang diem cua mot lop hoc phan"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: showStudentScoreCard(students, scores); break;
            case 2: showClassScoreTable(classes, scores); break;
            case 0: break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

/* =========================================================
   MENU CHINH
   ========================================================= */

void showMainMenu(StudentArray* students,
                  SubjectArray* subjects,
                  CourseClassArray* classes,
                  ScoreArray* scores) {
    int choice;

    do {
        printf("\n========== STUDENT MANAGEMENT SYSTEM =========="
               "\n1. Quan ly sinh vien"
               "\n2. Quan ly mon hoc"
               "\n3. Quan ly lop hoc phan"
               "\n4. Quan ly diem so"
               "\n5. Bao cao / bang diem"
               "\n6. Hien thi tat ca du lieu"
               "\n0. Luu va thoat\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1:
                showStudentMenu(students, scores);
                break;

            case 2:
                showSubjectMenu(subjects, classes, scores);
                break;

            case 3:
                showCourseClassMenu(classes, subjects, scores);
                break;

            case 4:
                showScoreMenu(scores, students, classes);
                break;

            case 5:
                showReportMenu(students, classes, scores);
                break;

            case 6:
                displayStudents(students);
                displaySubjects(subjects);
                displayCourseClasses(classes);
                displayScores(scores);
                break;

            case 0:
                printf("Dang luu du lieu va thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }

        if (choice != 0) {
            pauseScreen();
        }
    } while (choice != 0);
}
