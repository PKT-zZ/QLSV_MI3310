/* Module đọc/ghi file text, phân cách = '|'
Quy ước:
- File không tồn tại: in cảnh báo, mảng giữ nguyên (rỗng), không crash
- File rỗng: mảng rỗng, không có gì được load
- Dòng thiếu trường: bỏ qua dòng đó, in cảnh báo, đọc tiếp
- Trường bắt buộc rỗng: bỏ qua dòng đó, in cảnh báo
- Trùng khóa chính: giữ bản ghi đầu tiên, bỏ qua bản trùng
- Điểm ngoài [0,10]: bỏ qua toàn bộ bản ghi điểm đó
- FK không tồn tại: được phát hiện và xử lý trong loadAllData */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"
#include "score.h"

//Kích thước tối đa cho 1 dòng trong file
#define MAX_LINE 512

//HÀM TIỆN ÍCH NỘI BỘ

static void trim_newline(char* s) {
    int len = (int)strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
        s[--len] = '\0';
}

//Tách dòng phân cách bằng '|' thành mảng con trỏ tokens[]
static int split_pipe(char* line, char* tokens[], int max_fields) {
    int count = 0;
    char* p = line;
    while (count < max_fields) {
        tokens[count++] = p;
        char* sep = strchr(p, '|');
        if (sep == NULL) break;
        *sep = '\0';
        p = sep + 1;
    }
    return count;
}

//Copy chuỗi, tự động thêm '\0' vào cuối
static void safe_copy(char* dest, const char* src, int dest_size) {
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

//Kiểm tra điểm thang 10 hợp lệ
static int valid_score(float v) {
    return v >= 0.0f && v <= 10.0f;
}

//Kiểm tra điểm hệ 4 hợp lệ
static int valid_he4(float v) {
    return v >= 0.0f && v <= 4.0f;
}


//SINH VIÊN

//Đọc file students.txt vào mảng students. Kiểm tra: đủ 4 trường, MSSV không rỗng, không trùng PK
void loadStudents(StudentArray* students, const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("[CANH BAO] Khong mo duoc file '%s'. Bat dau voi danh sach sinh vien rong.\n", path);
        return;
    }

    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, f) == NULL) { fclose(f); return; }

    int lineNum = 1;
    while (fgets(line, MAX_LINE, f) != NULL) {
        lineNum++;
        trim_newline(line);
        if (line[0] == '\0') continue;

        char buf[MAX_LINE];
        safe_copy(buf, line, MAX_LINE);

        char* tok[4];
        int n = split_pipe(buf, tok, 4);

        if (n < 4) {
            printf("[CANH BAO] %s (dong %d): thieu truong (%d/4). Bo qua.\n", path, lineNum, n);
            continue;
        }
        if (tok[0][0] == '\0') {
            printf("[CANH BAO] %s (dong %d): MSSV trong. Bo qua.\n", path, lineNum);
            continue;
        }
        if (sa_find(students, tok[0]) != -1) {
            printf("[CANH BAO] %s (dong %d): MSSV '%s' bi trung. Bo qua.\n", path, lineNum, tok[0]);
            continue;
        }

        Student s;
        safe_copy(s.mssv,     tok[0], sizeof(s.mssv));
        safe_copy(s.hoTen,    tok[1], sizeof(s.hoTen));
        safe_copy(s.lop,      tok[2], sizeof(s.lop));
        safe_copy(s.birthday, tok[3], sizeof(s.birthday));

        if (!sa_add(students, s)) {
            printf("[LOI] Het bo nho khi them sinh vien (dong %d). Dung doc.\n", lineNum);
            break;
        }
    }
    fclose(f);
}

//Ghi toàn bộ mảng students xuống file. Format: dòng tiêu đề + mỗi bản ghi trên 1 dòng
void saveStudents(StudentArray* students, const char* path) {
    FILE* f = fopen(path, "w");
    if (f == NULL) {
        printf("[LOI] Khong the ghi file '%s'.\n", path);
        return;
    }
    fprintf(f, "MSSV|HoTen|Lop|Birthday\n");
    for (int i = 0; i < students->size; i++) {
        Student* s = &students->data[i];
        fprintf(f, "%s|%s|%s|%s\n", s->mssv, s->hoTen, s->lop, s->birthday);
    }
    fclose(f);
}


//MÔN HỌC

//Đọc file subjects.txt vào mảng subjects. Kiểm tra: đủ 3 trường, MaHP không rỗng, SoTinChi > 0, không trùng khóa
void loadSubjects(SubjectArray* subjects, const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("[CANH BAO] Khong mo duoc file '%s'. Bat dau voi danh sach mon hoc rong.\n", path);
        return;
    }

    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, f) == NULL) { fclose(f); return; }

    int lineNum = 1;
    while (fgets(line, MAX_LINE, f) != NULL) {
        lineNum++;
        trim_newline(line);
        if (line[0] == '\0') continue;

        char buf[MAX_LINE];
        safe_copy(buf, line, MAX_LINE);

        char* tok[3];
        int n = split_pipe(buf, tok, 3);

        if (n < 3) {
            printf("[CANH BAO] %s (dong %d): thieu truong (%d/3). Bo qua.\n", path, lineNum, n);
            continue;
        }
        if (tok[0][0] == '\0') {
            printf("[CANH BAO] %s (dong %d): MaHP trong. Bo qua.\n", path, lineNum);
            continue;
        }

        int soTC = atoi(tok[2]);
        if (soTC <= 0) {
            printf("[CANH BAO] %s (dong %d): SoTinChi khong hop le ('%s'). Bo qua.\n", path, lineNum, tok[2]);
            continue;
        }
        if (suba_find(subjects, tok[0]) != -1) {
            printf("[CANH BAO] %s (dong %d): MaHP '%s' bi trung. Bo qua.\n", path, lineNum, tok[0]);
            continue;
        }

        Subject s;
        safe_copy(s.maHP,  tok[0], sizeof(s.maHP));
        safe_copy(s.tenHP, tok[1], sizeof(s.tenHP));
        s.soTinChi = soTC;

        if (!suba_add(subjects, s)) {
            printf("[LOI] Het bo nho khi them mon hoc (dong %d). Dung doc.\n", lineNum);
            break;
        }
    }
    fclose(f);
}

void saveSubjects(SubjectArray* subjects, const char* path) {
    FILE* f = fopen(path, "w");
    if (f == NULL) {
        printf("[LOI] Khong the ghi file '%s'.\n", path);
        return;
    }
    fprintf(f, "MaHP|TenHP|SoTinChi\n");
    for (int i = 0; i < subjects->size; i++) {
        Subject* s = &subjects->data[i];
        fprintf(f, "%s|%s|%d\n", s->maHP, s->tenHP, s->soTinChi);
    }
    fclose(f);
}


//LỚP HP

//Đọc file course_classes.txt vào mảng classes. Kiểm tra: đủ 4 trường, MaLHP không rỗng, HocKy trong 1/2/3, NamHoc >= 2000, không trùng khóa
void loadCourseClasses(CourseClassArray* classes, const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("[CANH BAO] Khong mo duoc file '%s'. Bat dau voi danh sach lop hoc phan rong.\n", path);
        return;
    }

    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, f) == NULL) { fclose(f); return; }

    int lineNum = 1;
    while (fgets(line, MAX_LINE, f) != NULL) {
        lineNum++;
        trim_newline(line);
        if (line[0] == '\0') continue;

        char buf[MAX_LINE];
        safe_copy(buf, line, MAX_LINE);

        char* tok[4];
        int n = split_pipe(buf, tok, 4);

        if (n < 4) {
            printf("[CANH BAO] %s (dong %d): thieu truong (%d/4). Bo qua.\n", path, lineNum, n);
            continue;
        }
        if (tok[0][0] == '\0') {
            printf("[CANH BAO] %s (dong %d): MaLHP trong. Bo qua.\n", path, lineNum);
            continue;
        }

        int hocKy  = atoi(tok[2]);
        int namHoc = atoi(tok[3]);

        if (hocKy < 1 || hocKy > 3) {
            printf("[CANH BAO] %s (dong %d): HocKy '%s' khong hop le (can 1-3). Bo qua.\n", path, lineNum, tok[2]);
            continue;
        }
        if (namHoc < 2000) {
            printf("[CANH BAO] %s (dong %d): NamHoc '%s' khong hop le. Bo qua.\n", path, lineNum, tok[3]);
            continue;
        }
        if (cca_find(classes, tok[0]) != -1) {
            printf("[CANH BAO] %s (dong %d): MaLHP '%s' bi trung. Bo qua.\n", path, lineNum, tok[0]);
            continue;
        }

        CourseClass c;
        safe_copy(c.maLHP, tok[0], sizeof(c.maLHP));
        safe_copy(c.maHP,  tok[1], sizeof(c.maHP));
        c.hocKy  = hocKy;
        c.namHoc = namHoc;

        if (!cca_add(classes, c)) {
            printf("[LOI] Het bo nho khi them lop hoc phan (dong %d). Dung doc.\n", lineNum);
            break;
        }
    }
    fclose(f);
}

void saveCourseClasses(CourseClassArray* classes, const char* path) {
    FILE* f = fopen(path, "w");
    if (f == NULL) {
        printf("[LOI] Khong the ghi file '%s'.\n", path);
        return;
    }
    fprintf(f, "MaLHP|MaHP|HocKy|NamHoc\n");
    for (int i = 0; i < classes->size; i++) {
        CourseClass* c = &classes->data[i];
        fprintf(f, "%s|%s|%d|%d\n", c->maLHP, c->maHP, c->hocKy, c->namHoc);
    }
    fclose(f);
}


//ĐIỂM SỐ

//Đọc file scores.txt vào mảng scores. Kiểm tra: đủ 6 trường, MSSV/MaLHP không rỗng, DiemQT/CK/TK trong [0,10], DiemHe4 trong [0,4], không trùng khóa kép
void loadScores(ScoreArray* scores, const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("[CANH BAO] Khong mo duoc file '%s'. Bat dau voi danh sach diem rong.\n", path);
        return;
    }

    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, f) == NULL) { fclose(f); return; }

    int lineNum = 1;
    while (fgets(line, MAX_LINE, f) != NULL) {
        lineNum++;
        trim_newline(line);
        if (line[0] == '\0') continue;

        char buf[MAX_LINE];
        safe_copy(buf, line, MAX_LINE);

        char* tok[6];
        int n = split_pipe(buf, tok, 6);

        if (n < 6) {
            printf("[CANH BAO] %s (dong %d): thieu truong (%d/6). Bo qua.\n", path, lineNum, n);
            continue;
        }
        if (tok[0][0] == '\0' || tok[1][0] == '\0') {
            printf("[CANH BAO] %s (dong %d): MSSV hoac MaLHP trong. Bo qua.\n", path, lineNum);
            continue;
        }

        float diemQT  = (float)atof(tok[2]);
        float diemCK  = (float)atof(tok[3]);
        float diemTKFile  = (float)atof(tok[4]);
        float diemHe4File = (float)atof(tok[5]);

        if (!valid_score(diemQT) || !valid_score(diemCK) || !valid_score(diemTKFile)) {
            printf("[CANH BAO] %s (dong %d): Diem QT/CK/TK ngoai khoang [0,10]. Bo qua.\n", path, lineNum);
            continue;
        }
        if (!valid_he4(diemHe4File)) {
            printf("[CANH BAO] %s (dong %d): DiemHe4 ngoai khoang [0,4]. Bo qua.\n", path, lineNum);
            continue;
        }
        if (sca_find(scores, tok[0], tok[1]) != -1) {
            printf("[CANH BAO] %s (dong %d): Ban ghi ('%s','%s') bi trung. Bo qua.\n", path, lineNum, tok[0], tok[1]);
            continue;
        }

        ScoreRecord sc;
        safe_copy(sc.mssv,  tok[0], sizeof(sc.mssv));
        safe_copy(sc.maLHP, tok[1], sizeof(sc.maLHP));
        sc.diemQT = diemQT;
        sc.diemCK = diemCK;
        //DiemTK và DiemHe4 được tính lại cho chắc
        sc.diemTK = calculateDiemTK(sc.diemQT, sc.diemCK);
        sc.diemHe4 = convertToHe4(sc.diemTK);
        if (!sca_add(scores, sc)) {
            printf("[LOI] Het bo nho khi them ban ghi diem (dong %d). Dung doc.\n", lineNum);
            break;
        }
    }
    fclose(f);
}

//Ghi toàn bộ mảng scores xuống file (ghi đè). Điểm số được ghi với 2 chữ số thập phân để dễ đọc
void saveScores(ScoreArray* scores, const char* path) {
    FILE* f = fopen(path, "w");
    if (f == NULL) {
        printf("[LOI] Khong the ghi file '%s'.\n", path);
        return;
    }
    fprintf(f, "MSSV|MaLHP|DiemQT|DiemCK|DiemTK|DiemHe4\n");
    for (int i = 0; i < scores->size; i++) {
        ScoreRecord* sc = &scores->data[i];
        fprintf(f, "%s|%s|%.2f|%.2f|%.2f|%.2f\n", sc->mssv, sc->maLHP, sc->diemQT, sc->diemCK, sc->diemTK, sc->diemHe4);
    }
    fclose(f);
}


//LOAD/SAVE TOÀN BỘ

/*Load 4 bảng theo đúng thứ tự: students, subjects, course_classes, scores
  Sau khi load scores, kiểm tra toàn vẹn FK: xóa bản ghi điểm có MSSV/MaLHP không tồn tại*/
void loadAllData(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores) {
    loadStudents(students, STUDENT_FILE);
    loadSubjects(subjects, SUBJECT_FILE);
    loadCourseClasses(classes, COURSE_CLASS_FILE);
    loadScores(scores, SCORE_FILE);

    //Kiểm tra FK của course_classes: MaHP phải có trong subjects
    for (int i = classes->size - 1; i >= 0; i--) {
        CourseClass* c = &classes->data[i];
        if (suba_find(subjects, c->maHP) == -1) {
            printf("[CANH BAO] LHP '%s' co MaHP '%s' khong co trong subjects. Xoa ban ghi nay.\n", c->maLHP, c->maHP);
            cca_remove(classes, i);
        }
    }

    //Kiểm tra toàn vẹn tham chiếu trong scores. Duyệt ngược để tránh lỗi index khi xóa phần tử giữa chừng
    for (int i = scores->size - 1; i >= 0; i--) {
        ScoreRecord* sc = &scores->data[i];
        if (sa_find(students, sc->mssv) == -1) {
            printf("[CANH BAO] Diem cua MSSV '%s' khong co trong students. Xoa ban ghi nay.\n", sc->mssv);
            sca_remove(scores, i);
            continue;
        }
        if (cca_find(classes, sc->maLHP) == -1) {
            printf("[CANH BAO] Diem cua MaLHP '%s' khong co trong course_classes. Xoa ban ghi nay.\n", sc->maLHP);
            sca_remove(scores, i);
        }
    }
}

//Save 4 bảng theo thứ tự
void saveAllData(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores) {
    saveStudents(students,     STUDENT_FILE);
    saveSubjects(subjects,     SUBJECT_FILE);
    saveCourseClasses(classes, COURSE_CLASS_FILE);
    saveScores(scores,         SCORE_FILE);
}
