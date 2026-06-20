#include "score.h"
#include "gpa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ui.h"
#include "sort.h"
#include "student.h"
#include "subject.h"
#include "courseclass.h"
#include "search.h"

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
static int hasPipeChar(const char* s) {
    if (s == NULL) return 0;
    return strchr(s, '|') != NULL;
}
static void readLine(const char* message, char* buffer, int size) {
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
if (hasPipeChar(buffer)) {
    printf("Du lieu khong duoc chua ky tu '|'. Vui long nhap lai.\n");
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

    if (hasPipeChar(buffer)) {
        printf("Du lieu khong duoc chua ky tu '|'. Bo qua gia tri vua nhap.\n");
        buffer[0] = '\0';
        return 0;
    }

    return !isEmptyString(buffer);
}

static int readInt(const char* message) {
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
static int parseIntStrict(const char* s, int* out) {
    char* end;
    long value;

    if (s == NULL || isEmptyString(s)) return 0;

    value = strtol(s, &end, 10);

    if (*end != '\0') return 0;

    *out = (int)value;
    return 1;
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

static float readFloat(const char* message) {
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

static int validateMSSV(const char* mssv) {
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

static int validateDate(const char* date) {
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


static void pauseScreen(void) {
    printf("\nNhan Enter de tiep tuc...");
    getchar();
}

/* =========================================================
   HIEN THI DU LIEU
   ========================================================= */

static void displayStudents(StudentArray* students) {
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

static void displaySubjects(SubjectArray* subjects) {
    printf("\n==================== DANH SACH MON HOC ====================\n");
    printf("%-10s | %-35s | %-8s\n", "MaHP", "Ten hoc phan", "So TC");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < subjects->size; i++) {
        Subject* s = &subjects->data[i];
        printf("%-10s | %-35s | %-8d\n", s->maHP, s->tenHP, s->soTinChi);
    }

    printf("Tong so mon hoc: %d\n", subjects->size);
}

static void displayCourseClasses(CourseClassArray* classes) {
    printf("\n==================== DANH SACH LOP HOC PHAN ====================\n");
    printf("%-15s | %-10s | %-8s | %-8s\n", "MaLHP", "MaHP", "Hoc ky", "Nam hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < classes->size; i++) {
        CourseClass* c = &classes->data[i];
        printf("%-15s | %-10s | %-8d | %-8d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
    }

    printf("Tong so lop hoc phan: %d\n", classes->size);
}

static void displayScores(ScoreArray* scores) {
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

        if (findStudentRecord(students, s.mssv) != NULL) {
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

    if (addStudentRecord(students, s)) {
        printf("Them sinh vien thanh cong.\n");
    } else {
        printf("Them sinh vien that bai do loi bo nho.\n");
    }
}

static void editStudentUI(StudentArray* students) {
    char mssv[12];
    char buffer[100];
    Student* found;
    Student s;

    readLine("Nhap MSSV can sua: ", mssv, sizeof(mssv));
    found = findStudentRecord(students, mssv);

    if (found == NULL) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }

    s = *found;
    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("Ho ten moi: ", buffer, sizeof(buffer))) {
        strncpy(s.hoTen, buffer, sizeof(s.hoTen) - 1);
        s.hoTen[sizeof(s.hoTen) - 1] = '\0';
    }

    if (readLineOptional("Lop moi: ", buffer, sizeof(buffer))) {
        strncpy(s.lop, buffer, sizeof(s.lop) - 1);
        s.lop[sizeof(s.lop) - 1] = '\0';
    }

    while (1) {
        if (!readLineOptional("Ngay sinh moi DD/MM/YYYY: ", buffer, sizeof(buffer))) {
            break;
        }

        if (validateDate(buffer)) {
            strncpy(s.birthday, buffer, sizeof(s.birthday) - 1);
            s.birthday[sizeof(s.birthday) - 1] = '\0';
            break;
        }

        printf("Ngay sinh khong hop le. Vui long nhap lai hoac Enter de bo qua.\n");
    }

    updateStudentRecord(students, s);
    printf("Sua sinh vien thanh cong.\n");
}

static void deleteStudentUI(StudentArray* students, ScoreArray* scores) {
    char mssv[12];

    readLine("Nhap MSSV can xoa: ", mssv, sizeof(mssv));

    if (findStudentRecord(students, mssv) == NULL) {
        printf("Khong tim thay sinh vien.\n");
        return;
    }

    if (studentHasScore(scores, mssv)) {
        printf("Khong the xoa sinh vien vi da co ban ghi diem.\n");
        return;
    }

    if (deleteStudentRecord(students, mssv)) {
        printf("Xoa sinh vien thanh cong.\n");
    } else {
        printf("Xoa sinh vien that bai.\n");
    }
}

static void searchStudentUI(StudentArray* students) {
    int choice;
    char key[100];

    printf("\n1. Tim theo MSSV\n");
    printf("2. Tim theo ho ten\n");
    printf("3. Tim theo lop\n");
    choice = readIntRange("Nhap lua chon: ", 1, 3);

    readLine("Nhap tu khoa: ", key, sizeof(key));

    if (choice == 1) {
        Student* s = searchStudentByMSSV(students, key);

        printf("\n%-12s | %-25s | %-12s | %-12s\n", "MSSV", "Ho ten", "Lop", "Birthday");
        printf("-----------------------------------------------------------------------\n");

        if (s != NULL) {
            printf("%-12s | %-25s | %-12s | %-12s\n", s->mssv, s->hoTen, s->lop, s->birthday);
        } else {
            printf("Khong tim thay ket qua phu hop.\n");
        }
    } else if (choice == 2) {
        searchStudentByName(students, key);
    } else {
        searchStudentByClass(students, key);
    }
}
static void sortStudentUI(
    StudentArray* students,
    SubjectArray* subjects,
    CourseClassArray* classes,
    ScoreArray* scores
)
{
    int choice;

    printf("\n========== SAP XEP SINH VIEN ==========\n");
    printf("1. Sap xep theo MSSV\n");
    printf("2. Sap xep theo ho ten\n");
    printf("3. Sap xep theo GPA\n");
    printf("0. Quay lai\n");

    choice = readIntRange(
        "Nhap lua chon: ",
        0,
        3
    );

    switch (choice)
    {
        case 1:
            sortStudentByMSSV(
                students
            );

            printf(
                "Da sap xep danh sach sinh vien theo MSSV.\n"
            );

            displayStudents(
                students
            );
            break;

        case 2:
            sortStudentByName(
                students
            );

            printf(
                "Da sap xep danh sach sinh vien theo ho ten.\n"
            );

            displayStudents(
                students
            );
            break;

        case 3:
            sortStudentByGPA(
                students,
                scores,
                classes,
                subjects
            );

            printf(
                "Da sap xep danh sach sinh vien theo GPA.\n"
            );

            displayStudents(
                students
            );
            break;

        case 0:
            break;

        default:
            printf(
                "Lua chon khong hop le.\n"
            );
    }
}
static void showStudentMenu(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores) {
    int choice;

    do {
        printf("\n========== QUAN LY SINH VIEN =========="
       "\n1. Hien thi danh sach sinh vien"
       "\n2. Them sinh vien"
       "\n3. Sua sinh vien"
       "\n4. Xoa sinh vien"
       "\n5. Tim sinh vien"
       "\n6. Sap xep danh sach sinh vien"
       "\n0. Quay lai\n");
        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1: displayStudents(students); break;
            case 2: addStudentUI(students); break;
            case 3: editStudentUI(students); break;
            case 4: deleteStudentUI(students, scores); break;
            case 5: searchStudentUI(students); break;
            case 6: sortStudentUI(students, subjects, classes, scores); break;
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

        if (findSubjectRecord(subjects, s.maHP) != NULL) {
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

    if (addSubjectRecord(subjects, s)) {
        printf("Them mon hoc thanh cong.\n");
    } else {
        printf("Them mon hoc that bai.\n");
    }
}

static void editSubjectUI(SubjectArray* subjects) {
    char maHP[10];
    char buffer[100];
    Subject* found;
    Subject s;

    readLine("Nhap MaHP can sua: ", maHP, sizeof(maHP));
    found = findSubjectRecord(subjects, maHP);

    if (found == NULL) {
        printf("Khong tim thay mon hoc.\n");
        return;
    }

    s = *found;
    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("Ten hoc phan moi: ", buffer, sizeof(buffer))) {
        strncpy(s.tenHP, buffer, sizeof(s.tenHP) - 1);
        s.tenHP[sizeof(s.tenHP) - 1] = '\0';
    }

    if (readLineOptional("So tin chi moi: ", buffer, sizeof(buffer))) {
    int credit;

    if (parseIntStrict(buffer, &credit) && validateCredit(credit)) {
        s.soTinChi = credit;
    } else {
        printf("So tin chi khong hop le, giu nguyen gia tri cu.\n");
    }
}

    updateSubjectRecord(subjects, s);
    printf("Sua mon hoc thanh cong.\n");
}

static void deleteSubjectUI(SubjectArray* subjects, CourseClassArray* classes) {
    char maHP[10];

    readLine("Nhap MaHP can xoa: ", maHP, sizeof(maHP));

    if (findSubjectRecord(subjects, maHP) == NULL) {
        printf("Khong tim thay mon hoc.\n");
        return;
    }

    if (subjectIsUsed(classes, maHP)) {
        printf("Khong the xoa mon hoc vi dang co lop hoc phan su dung MaHP nay.\n");
        return;
    }

    if (deleteSubjectRecord(subjects, maHP)) {
        printf("Xoa mon hoc thanh cong.\n");
    } else {
        printf("Xoa mon hoc that bai.\n");
    }
}

static void searchSubjectUI(SubjectArray* subjects) {
    int choice;
    char key[100];

    printf("\n1. Tim theo MaHP\n");
    printf("2. Tim theo ten hoc phan\n");
    choice = readIntRange("Nhap lua chon: ", 1, 2);

    readLine("Nhap tu khoa: ", key, sizeof(key));

    if (choice == 1) {
        Subject* s = searchSubjectByCode(subjects, key);

        printf("\n%-10s | %-35s | %-8s\n", "MaHP", "Ten hoc phan", "So TC");
        printf("--------------------------------------------------------------\n");

        if (s != NULL) {
            printf("%-10s | %-35s | %-8d\n", s->maHP, s->tenHP, s->soTinChi);
        } else {
            printf("Khong tim thay ket qua phu hop.\n");
        }
    } else {
        searchSubjectByName(subjects, key);
    }
}

static void showSubjectMenu(SubjectArray* subjects,
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

        if (findCourseClassRecord(classes, c.maLHP) != NULL) {
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

    if (addCourseClassRecord(classes, subjects, c)) {
        printf("Them lop hoc phan thanh cong.\n");
    } else {
        printf("Them lop hoc phan that bai.\n");
    }
}

static void editCourseClassUI(CourseClassArray* classes, SubjectArray* subjects) {
    char maLHP[15];
    char buffer[100];
    CourseClass* found;
    CourseClass c;

    readLine("Nhap MaLHP can sua: ", maLHP, sizeof(maLHP));
    found = findCourseClassRecord(classes, maLHP);

    if (found == NULL) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    c = *found;
    printf("Nhap thong tin moi. Bo trong de giu nguyen.\n");

    if (readLineOptional("MaHP moi: ", buffer, sizeof(buffer))) {
        if (suba_find(subjects, buffer) != -1) {
            strncpy(c.maHP, buffer, sizeof(c.maHP) - 1);
            c.maHP[sizeof(c.maHP) - 1] = '\0';
        } else {
            printf("MaHP khong ton tai, giu nguyen gia tri cu.\n");
        }
    }

   if (readLineOptional("Hoc ky moi: ", buffer, sizeof(buffer))) {
    int hocKy;

    if (parseIntStrict(buffer, &hocKy) && validateSemester(hocKy)) {
        c.hocKy = hocKy;
    } else {
        printf("Hoc ky khong hop le, giu nguyen gia tri cu.\n");
    }
}

   if (readLineOptional("Nam hoc moi: ", buffer, sizeof(buffer))) {
    int namHoc;

    if (parseIntStrict(buffer, &namHoc) && validateYear(namHoc)) {
        c.namHoc = namHoc;
    } else {
        printf("Nam hoc khong hop le, giu nguyen gia tri cu.\n");
    }
}

    updateCourseClassRecord(classes, c);
    printf("Sua lop hoc phan thanh cong.\n");
}

static void deleteCourseClassUI(CourseClassArray* classes, ScoreArray* scores) {
    char maLHP[15];

    readLine("Nhap MaLHP can xoa: ", maLHP, sizeof(maLHP));

    if (findCourseClassRecord(classes, maLHP) == NULL) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    if (classHasScore(scores, maLHP)) {
        printf("Khong the xoa lop hoc phan vi da co ban ghi diem.\n");
        return;
    }

    if (deleteCourseClassRecord(classes, maLHP)) {
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

    if (choice == 1) {
        CourseClass* c = searchCourseClassByCode(classes, key);

        printf("\n%-15s | %-10s | %-8s | %-8s\n", "MaLHP", "MaHP", "Hoc ky", "Nam hoc");
        printf("-----------------------------------------------------------\n");

        if (c != NULL) {
            printf("%-15s | %-10s | %-8d | %-8d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
        } else {
            printf("Khong tim thay ket qua phu hop.\n");
        }
        return;
    }

    printf("\n%-15s | %-10s | %-8s | %-8s\n", "MaLHP", "MaHP", "Hoc ky", "Nam hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < classes->size; i++) {
        CourseClass* c = &classes->data[i];

        if (strcmp(c->maHP, key) == 0) {
            printf("%-15s | %-10s | %-8d | %-8d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay ket qua phu hop.\n");
}

static void showCourseClassMenu(CourseClassArray* classes,
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

    if (addScoreRecord(scores, students, classes, sc)) {
        int idx = sca_find(scores, sc.mssv, sc.maLHP);
        ScoreRecord* added = sca_get(scores, idx);
        printf("Them diem thanh cong. DiemTK = %.2f, He4 = %.2f\n", added->diemTK, added->diemHe4);
    } else {
        printf("Them diem that bai.\n");
    }
}

static void updateScoreUI(ScoreArray* scores) {
    char mssv[12];
    char maLHP[15];
    float diemQT, diemCK;
    int index;

    readLine("Nhap MSSV: ", mssv, sizeof(mssv));
    readLine("Nhap MaLHP: ", maLHP, sizeof(maLHP));

    if (sca_find(scores, mssv, maLHP) == -1) {
        printf("Khong tim thay ban ghi diem.\n");
        return;
    }

    diemQT = readFloatRange("Nhap diem qua trinh moi (0-10): ", 0.0f, 10.0f);
    diemCK = readFloatRange("Nhap diem cuoi ky moi (0-10): ", 0.0f, 10.0f);

    updateScoreRecord(scores, mssv, maLHP, diemQT, diemCK);

    index = sca_find(scores, mssv, maLHP);
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

static void showScoreMenu(ScoreArray* scores,
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

static void showStudentScoreCard(
    StudentArray* students,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
)
{
    char mssv[12];
    int studentIndex;
    int found = 0;

    readLine(
        "Nhap MSSV can xem bang diem: ",
        mssv,
        sizeof(mssv)
    );

    studentIndex =
        sa_find(
            students,
            mssv
        );

    if (studentIndex == -1)
    {
        printf(
            "Khong tim thay sinh vien.\n"
        );
        return;
    }

    Student* s =
        sa_get(
            students,
            studentIndex
        );

    if (s == NULL)
    {
        printf(
            "Loi: index sinh vien khong hop le.\n"
        );
        return;
    }

    printf(
        "\nBang diem sinh vien: %s - %s\n",
        s->mssv,
        s->hoTen
    );

    printf(
        "%-15s | %-8s | %-8s | %-8s | %-8s\n",
        "MaLHP",
        "DiemQT",
        "DiemCK",
        "DiemTK",
        "He4"
    );

    printf(
        "------------------------------------------------------------\n"
    );

    for (int i = 0; i < scores->size; i++)
    {
        ScoreRecord* sc =
            &scores->data[i];

        if (
            strcmp(
                sc->mssv,
                mssv
            ) == 0
        )
        {
            printf(
                "%-15s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
                sc->maLHP,
                sc->diemQT,
                sc->diemCK,
                sc->diemTK,
                sc->diemHe4
            );

            found = 1;
        }
    }

    if (!found)
    {
        printf(
            "Sinh vien nay chua co diem.\n"
        );
        return;
    }

    float gpa10 =
        calculateStudentGPA10(
            mssv,
            scores,
            classes,
            subjects
        );

    float gpa4 =
        calculateStudentGPA4(
            mssv,
            scores,
            classes,
            subjects
        );

    printf("\n");

    printf(
        "GPA he 10 : %.2f\n",
        gpa10
    );

    printf(
        "GPA he 4  : %.2f\n",
        gpa4
    );

    printf(
        "Hoc luc   : %s\n",
        getAcademicRank(gpa10)
    );
}

static void showClassScoreTable(CourseClassArray* classes,
                                ScoreArray* scores,
                                StudentArray* students) {
    char maLHP[15];
    int classIndex;
    int found = 0;

    readLine("Nhap MaLHP can xem bang diem: ", maLHP, sizeof(maLHP));
    classIndex = cca_find(classes, maLHP);

    if (classIndex == -1) {
        printf("Khong tim thay lop hoc phan.\n");
        return;
    }

    printf("%-12s | %-25s | %-8s | %-8s | %-8s | %-8s\n",
       "MSSV", "HoTen", "DiemQT", "DiemCK", "DiemTK", "He4");
printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        if (strcmp(sc->maLHP, maLHP) == 0) {
            int studentIndex = sa_find(students, sc->mssv);
const char* hoTen = "Khong ro";

if (studentIndex != -1) {
    hoTen = students->data[studentIndex].hoTen;
}

printf("%-12s | %-25s | %-8.2f | %-8.2f | %-8.2f | %-8.2f\n",
       sc->mssv, hoTen, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
            found = 1;
        }
    }

    if (!found) printf("Lop hoc phan nay chua co diem.\n");
}

static void showReportMenu(
    StudentArray* students,
    SubjectArray* subjects,
    CourseClassArray* classes,
    ScoreArray* scores
) {
    int choice;

    do {
        printf("\n========== BAO CAO =========="
               "\n1. Bang diem cua mot sinh vien"
               "\n2. Bang diem cua mot lop hoc phan"
               "\n0. Quay lai\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1:showStudentScoreCard(students, scores, classes, subjects); break;
            case 2: showClassScoreTable(classes, scores, students); break;
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
                showStudentMenu(students, subjects, classes, scores); break;

            case 2:
                showSubjectMenu(subjects, classes, scores);
                break;

            case 3:
                showCourseClassMenu(classes, subjects, scores);
                break;

            case 4:
                showScoreMenu(scores, students, classes);
                break;

            case 5:showReportMenu(students, subjects, classes, scores); break;

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
