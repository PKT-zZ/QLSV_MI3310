# I. Lỗi thuộc phần Thành viên 2

Nhóm file theo README:

```text
student.h/.c
subject.h/.c
courseclass.h/.c
score.h/.c
gpa.h/.c
sort.h/.c
search.h/.c
````

---

## 1. `search.h` thiếu prototype cho nhiều hàm đã có trong `search.c`

### File liên quan

```text
source/search.h
source/search.c
```

### Hiện trạng

`search.c` hiện có nhiều hàm:

```c
searchStudentByName(...)
searchStudentByMSSV(...)
searchStudentByClass(...)
searchSubjectByCode(...)
searchSubjectByName(...)
searchCourseClassByCode(...)
```

Nhưng `search.h` hiện chỉ khai báo:

```c
void searchStudentByName(StudentArray* students, const char* keyword);

Student* searchStudentByMSSV(StudentArray* students, const char* mssv);
```

### Vì sao là lỗi

Nếu module UI hoặc test muốn gọi các hàm còn lại như:

```c
searchStudentByClass(...)
searchSubjectByCode(...)
searchSubjectByName(...)
searchCourseClassByCode(...)
```

thì sẽ thiếu prototype trong header.

Ở C99 với `-Wall -Wextra -std=c99`, việc gọi hàm không khai báo trước có thể gây warning/lỗi tùy compiler và thiết lập.

### Mức độ

**Nên sửa trước khi nộp**, vì đây là lỗi thiếu đồng bộ giữa `.c` và `.h`.

### Cách sửa tối thiểu

Bổ sung vào `search.h`:

```c
void searchStudentByClass(StudentArray* students, const char* lop);

Subject* searchSubjectByCode(SubjectArray* subjects, const char* maHP);

void searchSubjectByName(SubjectArray* subjects, const char* keyword);

CourseClass* searchCourseClassByCode(CourseClassArray* classes, const char* maLHP);
```

---

## 2. Các hàm xóa ở `student.c`, `subject.c`, `courseclass.c` không tự kiểm tra ràng buộc liên quan

### File liên quan

```text
source/student.c
source/student.h
source/subject.c
source/subject.h
source/courseclass.c
source/courseclass.h
source/ui.c
README.md
```

### Hiện trạng

README yêu cầu:

* Không cho xóa sinh viên nếu còn điểm.
* Không cho xóa môn học nếu còn lớp học phần dùng mã học phần đó.
* Không cho xóa lớp học phần nếu còn điểm.

Trong `ui.c`, phần này đã được chặn ở giao diện:

```c
studentHasScore(...)
subjectIsUsed(...)
classHasScore(...)
```

Tuy nhiên, trong các module nghiệp vụ của Thành viên 2:

```c
deleteStudentRecord(StudentArray* students, const char* mssv)
deleteSubjectRecord(SubjectArray* subjects, const char* maHP)
deleteCourseClassRecord(CourseClassArray* classes, const char* maLHP)
```

các hàm này chỉ tìm index rồi xóa, không tự kiểm tra dữ liệu liên quan.

### Vì sao là lỗi

Nếu chỉ chạy qua UI thì chương trình vẫn chặn được xóa sai.

Nhưng nếu test trực tiếp module nghiệp vụ hoặc một file khác gọi thẳng:

```c
deleteStudentRecord(...)
deleteSubjectRecord(...)
deleteCourseClassRecord(...)
```

thì vẫn có thể xóa dữ liệu đang được tham chiếu.

Điều này lệch với README phần yêu cầu ràng buộc toàn vẹn tham chiếu.

### Mức độ

**Không làm chương trình chính lỗi nếu UI luôn được dùng.**
Nhưng **nên sửa nếu muốn module Thành viên 2 đúng trách nhiệm nghiệp vụ**.

### Cách sửa tối thiểu

Có 2 hướng.

#### Hướng 1 — Giữ như hiện tại, sửa README cho rõ

Ghi rõ trong README:

```text
Ràng buộc toàn vẹn tham chiếu được kiểm tra tại tầng UI trước khi gọi hàm xóa cơ bản trong module nghiệp vụ.
```

#### Hướng 2 — Sửa đúng nghiệp vụ hơn

Đổi prototype để hàm nghiệp vụ tự kiểm tra:

```c
int deleteStudentRecord(StudentArray* students, const char* mssv, ScoreArray* scores);

int deleteSubjectRecord(SubjectArray* subjects, const char* maHP, CourseClassArray* classes);

int deleteCourseClassRecord(CourseClassArray* classes, const char* maLHP, ScoreArray* scores);
```

Nhưng hướng này cần sửa cả `.h`, `.c` và nơi gọi hàm nếu có. Nếu mục tiêu là sửa tối thiểu, chọn Hướng 1.

---

## 3. `score.c` không kiểm tra điểm ngoài khoảng nếu gọi trực tiếp `addScoreRecord()` / `updateScoreRecord()`

### File liên quan

```text
source/score.c
source/score.h
source/ui.c
```

### Hiện trạng

Trong `ui.c`, khi nhập điểm, code dùng:

```c
readFloatRange("Nhap diem qua trinh (0-10): ", 0.0f, 10.0f);
readFloatRange("Nhap diem cuoi ky (0-10): ", 0.0f, 10.0f);
```

nên nếu người dùng nhập từ UI thì điểm được chặn trong khoảng `0–10`.

Nhưng trong `score.c`, các hàm:

```c
addScoreRecord(...)
updateScoreRecord(...)
```

không tự kiểm tra:

```c
diemQT < 0 || diemQT > 10
diemCK < 0 || diemCK > 10
```

### Vì sao là lỗi

Nếu test trực tiếp `score.c` hoặc module khác gọi thẳng `addScoreRecord()` / `updateScoreRecord()` với điểm sai, hàm vẫn có thể thêm/cập nhật điểm sai.

Điều này làm module nghiệp vụ phụ thuộc hoàn toàn vào UI để validate.

### Mức độ

**Nên sửa nếu có test module `score.c`.**
Nếu chỉ demo qua UI, lỗi này chưa bộc lộ.

### Cách sửa tối thiểu

Trong `score.c`, thêm kiểm tra ở đầu `addScoreRecord()` sau khi kiểm tra tồn tại sinh viên/lớp:

```c
if (sc.diemQT < 0.0f || sc.diemQT > 10.0f) return 0;
if (sc.diemCK < 0.0f || sc.diemCK > 10.0f) return 0;
```

Trong `updateScoreRecord()` thêm trước khi sửa dữ liệu:

```c
if (diemQT < 0.0f || diemQT > 10.0f) return 0;
if (diemCK < 0.0f || diemCK > 10.0f) return 0;
```

---

## 4. README nêu tên hàm nghiệp vụ không khớp tên hàm thật

### File liên quan

```text
README.md
source/score.h
source/gpa.h
source/student.h
source/subject.h
source/courseclass.h
```

### Hiện trạng

README phần Thành viên 2 nêu các hàm tối thiểu như:

```c
int addStudent(...)
int editStudent(...)
int deleteStudent(...)
int findStudentByMSSV(...)
int findStudentByName(...)

int addSubject(...)
int editSubject(...)
int deleteSubject(...)
int findSubjectByCode(...)

int addScore(...)
int updateScore(...)
float calcDiemTK(...)
float calcGPA10(...)
float calcGPA4(...)
float quyDoiHe4(...)
```

Nhưng code hiện tại dùng tên khác, ví dụ:

```c
addStudentRecord(...)
updateStudentRecord(...)
deleteStudentRecord(...)
findStudentRecord(...)

addSubjectRecord(...)
updateSubjectRecord(...)
deleteSubjectRecord(...)
findSubjectRecord(...)

calculateDiemTK(...)
convertToHe4(...)
calculateStudentGPA10(...)
calculateStudentGPA4(...)
getAcademicRank(...)
```

### Vì sao là lỗi

Không làm chương trình lỗi nếu code gọi đúng tên hiện tại.

Nhưng README đang mô tả sai API thật của project. Nếu thành viên khác hoặc giảng viên đối chiếu README với header, sẽ thấy lệch.

### Mức độ

**Bắt buộc sửa trong README trước khi nộp.**

### Cách sửa tối thiểu

Trong README, không nên ghi danh sách prototype cũ nữa. Có 2 lựa chọn:

#### Cách 1 — Đổi README sang tên hàm thật

Ví dụ:

```c
int addStudentRecord(StudentArray* students, Student s);
int updateStudentRecord(StudentArray* students, Student s);
int deleteStudentRecord(StudentArray* students, const char* mssv);
Student* findStudentRecord(StudentArray* students, const char* mssv);

float calculateDiemTK(float diemQT, float diemCK);
float convertToHe4(float diemTK);
float calculateStudentGPA10(const char* mssv, ScoreArray* scores, CourseClassArray* classes, SubjectArray* subjects);
float calculateStudentGPA4(const char* mssv, ScoreArray* scores, CourseClassArray* classes, SubjectArray* subjects);
const char* getAcademicRank(float gpa10);
```

#### Cách 2 — Bỏ prototype cụ thể

Đổi thành mô tả chức năng:

```text
Module nghiệp vụ cung cấp các hàm thêm/sửa/xóa/tìm cho sinh viên, môn học, lớp học phần; các hàm tính điểm tổng kết, quy đổi hệ 4, tính GPA hệ 10/hệ 4 và xếp loại học lực.
```

Cách 2 an toàn hơn nếu tên hàm còn có thể thay đổi.

---

## 5. `search.c` có nhiều hàm nhưng UI hiện không dùng module `search.c`

### File liên quan

```text
source/search.c
source/search.h
source/ui.c
```

### Hiện trạng

`search.c` có các hàm tìm kiếm riêng.

Tuy nhiên, trong `ui.c`, các chức năng tìm kiếm sinh viên/môn học/lớp học phần/điểm đang tự duyệt mảng và dùng `strcmp`, `strstr` trực tiếp trong UI.

### Vì sao là vấn đề

Không làm chương trình lỗi.

Nhưng README nói Thành viên 2 cài tìm kiếm tuyến tính và Thành viên 3 tích hợp giao diện với module Thành viên 2. Nếu UI không gọi `search.c`, thì module `search.c` chưa thật sự được tích hợp vào chương trình chính.

### Mức độ

**Không bắt buộc nếu chỉ cần demo chạy được.**
**Nên sửa nếu muốn đúng phân công module.**

### Cách sửa tối thiểu

Có 2 hướng:

#### Hướng 1 — Giữ nguyên code, sửa README

Ghi rõ:

```text
Tìm kiếm tuyến tính được triển khai trực tiếp trong UI cho từng menu; `search.c` giữ vai trò module tìm kiếm bổ sung.
```

#### Hướng 2 — Tích hợp lại

Cho `ui.c` gọi các hàm trong `search.c`, nhưng hướng này sửa rộng hơn.

---

# II. Lỗi thuộc phần Thành viên 3

Nhóm file theo README:

```text
main.c
ui.h
ui.c
README.md
screenshots/
report/
```

---

## 6. `ui.h` không khớp với danh sách prototype README nêu

### File liên quan

```text
source/ui.h
source/ui.c
README.md
```

### Hiện trạng

README nêu các hàm giao diện/validation tối thiểu cần có:

```c
void showMainMenu();
void showStudentMenu();
void showSubjectMenu();
void showCourseClassMenu();
void showScoreMenu();
void displayTable();
void displayScoreCard();

int validateMSSV(const char* mssv);
int validateScore(float score);
int validateDate(const char* date);
int readInt(const char* message);
float readFloat(const char* message);
```

Nhưng `ui.h` hiện chỉ public:

```c
void showMainMenu(StudentArray* students,
                  SubjectArray* subjects,
                  CourseClassArray* classes,
                  ScoreArray* scores);
```

Các hàm còn lại trong `ui.c` đa số là `static`, không khai báo trong `ui.h`.

### Vì sao là lỗi

Không làm chương trình chính lỗi, vì `main.c` chỉ cần gọi `showMainMenu(...)`.

Nhưng README đang mô tả sai public API của `ui.h`. Nếu giảng viên hoặc test khác dựa theo README để gọi `showStudentMenu()` / `validateMSSV()` từ ngoài file `ui.c`, sẽ không gọi được.

### Mức độ

**Bắt buộc sửa README**, không nhất thiết sửa code.

### Cách sửa tối thiểu

Trong README, đổi từ:

```text
Các hàm giao diện và validation tối thiểu cần có
```

thành:

```text
Các chức năng giao diện cần có
```

và không liệt kê prototype cụ thể.

Ví dụ sửa thành:

```md
Các chức năng giao diện cần có:

- Menu chính.
- Menu quản lý sinh viên.
- Menu quản lý môn học.
- Menu quản lý lớp học phần.
- Menu quản lý điểm.
- Menu báo cáo.
- Kiểm tra dữ liệu nhập: MSSV, ngày sinh, điểm, học kỳ, năm học, số tín chỉ.
```

---

## 7. Bảng điểm sinh viên chưa in đủ thông tin môn học/lớp học phần như README mô tả

### File liên quan

```text
source/ui.c
README.md
```

### Hiện trạng

README mục báo cáo yêu cầu:

```text
Bảng điểm của một sinh viên
```

và mục test TC20 nêu bảng điểm sinh viên cần hiển thị đầy đủ các môn/lớp học phần, điểm và GPA.

Trong `ui.c`, `showStudentScoreCard()` hiện đã in được:

```text
MaLHP | DiemQT | DiemCK | DiemTK | He4
GPA he 10
GPA he 4
Hoc luc
```

### Vấn đề

Bảng điểm sinh viên đã có GPA và học lực, nhưng phần từng dòng điểm chỉ có `MaLHP`, chưa in:

```text
MaHP
TenHP
SoTinChi
```

Nếu README nói “đầy đủ các môn/lớp học phần”, chỉ in `MaLHP` là hơi thiếu thông tin.

### Mức độ

**Nên sửa để demo TC20 chắc hơn.**

### Cách sửa tối thiểu

Trong `showStudentScoreCard()`, khi duyệt từng `ScoreRecord`, tra thêm:

```c
int classIndex = cca_find(classes, sc->maLHP);
int subjectIndex = -1;

if (classIndex != -1) {
    subjectIndex = suba_find(subjects, classes->data[classIndex].maHP);
}
```

Rồi in thêm ít nhất:

```text
MaLHP | MaHP | SoTC | DiemQT | DiemCK | DiemTK | He4
```

Tốt hơn:

```text
MaLHP | MaHP | TenHP | SoTC | DiemQT | DiemCK | DiemTK | He4
```

---

## 8. Bảng điểm lớp học phần chưa in họ tên sinh viên

### File liên quan

```text
source/ui.c
README.md
```

### Hiện trạng

README yêu cầu:

```text
Bảng điểm của một lớp học phần
```

Trong `ui.c`, `showClassScoreTable()` hiện in:

```text
MSSV | DiemQT | DiemCK | DiemTK | He4
```

### Vấn đề

Bảng điểm lớp học phần có MSSV và điểm, nhưng chưa có họ tên sinh viên. Khi demo, giảng viên có thể hỏi “danh sách sinh viên” mà chỉ có MSSV thì chưa trực quan.

### Mức độ

**Nên sửa trước demo nếu còn thời gian.**

### Cách sửa tối thiểu

Đổi chữ ký hàm từ:

```c
static void showClassScoreTable(CourseClassArray* classes, ScoreArray* scores)
```

thành:

```c
static void showClassScoreTable(CourseClassArray* classes, ScoreArray* scores, StudentArray* students)
```

Trong vòng lặp, tra sinh viên:

```c
int studentIndex = sa_find(students, sc->mssv);
const char* hoTen = "";

if (studentIndex != -1) {
    hoTen = students->data[studentIndex].hoTen;
}
```

In bảng dạng:

```text
MSSV | HoTen | DiemQT | DiemCK | DiemTK | He4
```

Và sửa nơi gọi trong `showReportMenu()`:

```c
showClassScoreTable(classes, scores, students);
```

---

## 9. README nhắc “danh sách xếp hạng” nhưng UI chưa có chức năng bảng xếp hạng riêng

### File liên quan

```text
README.md
source/ui.c
source/sort.c
source/sort.h
```

### Hiện trạng

README phần Thành viên 3 ghi:

```text
Validation và in báo cáo: ... in bảng điểm sinh viên, bảng điểm lớp học phần, danh sách xếp hạng
```

Trong `ui.c`, hiện có chức năng sắp xếp sinh viên theo GPA trong menu sinh viên:

```text
Sap xep danh sach sinh vien theo GPA
```

Nhưng chưa có báo cáo riêng kiểu:

```text
Bang xep hang GPA
```

in kèm GPA hệ 10/GPA hệ 4 của từng sinh viên.

### Vì sao là vấn đề

Nếu hiểu “danh sách xếp hạng” là chức năng báo cáo riêng, hiện code chưa có.

Nếu chỉ cần sắp xếp danh sách sinh viên theo GPA thì có thể coi là đã đáp ứng ở mức cơ bản, nhưng kết quả hiện chỉ in danh sách sinh viên, không in GPA bên cạnh nên khó chứng minh thứ hạng.

### Mức độ

**Không bắt buộc nếu README sửa lại cho rõ.**
**Nên sửa nếu nhóm muốn giữ yêu cầu “danh sách xếp hạng”.**

### Cách sửa tối thiểu

Hoặc sửa README thành:

```text
Có chức năng sắp xếp sinh viên theo GPA.
```

Hoặc thêm báo cáo:

```text
MSSV | HoTen | Lop | GPA10 | GPA4 | HocLuc
```

---

## 10. Menu điểm không có xóa điểm

### File liên quan

```text
source/ui.c
source/score.c
source/score.h
README.md
```

### Hiện trạng

Menu điểm hiện có:

```text
1. Hien thi danh sach diem
2. Nhap diem
3. Cap nhat diem
4. Tim diem
0. Quay lai
```

Không có xóa điểm.

### Đánh giá theo README hiện tại

README phần quản lý điểm chủ yếu nói:

```text
Nhập và cập nhật điểm
```

Mục test cũng không thấy yêu cầu xóa điểm rõ ràng.

### Kết luận

Không coi đây là lỗi bắt buộc nếu chỉ bám README hiện tại.

Tuy nhiên, nếu báo cáo hoặc giảng viên yêu cầu CRUD đầy đủ cho điểm, thì cần bổ sung.

### Cách sửa nếu muốn đủ CRUD

Thêm vào `score.h`:

```c
int deleteScoreRecord(ScoreArray* scores, const char* mssv, const char* maLHP);
```

Thêm vào `score.c`:

```c
int deleteScoreRecord(ScoreArray* scores, const char* mssv, const char* maLHP)
{
    int idx = sca_find(scores, mssv, maLHP);
    if (idx == -1) return 0;
    return sca_remove(scores, idx);
}
```

Thêm `deleteScoreUI()` trong `ui.c` và thêm mục “Xoa diem” vào menu điểm.

---

## 11. README phần tài liệu/sản phẩm nộp nhắc `screenshots/`, `report/`, `docs/test-plan.md` nhưng repo có thể chưa có

### File liên quan

```text
README.md
screenshots/
report/
docs/test-plan.md
docs/test_note.md
```

### Hiện trạng

README Thành viên 3 yêu cầu:

```text
docs/test-plan.md hoặc report/
screenshots/
report/BaoCao_QLSV_NhomXX.docx
```

Nhưng nếu repo hiện chưa có các thư mục/file này, README đang mô tả sản phẩm chưa tồn tại.

### Mức độ

**Bắt buộc sửa trước khi nộp nếu README là tài liệu chính.**

### Cách sửa tối thiểu

Nếu chưa có ảnh/báo cáo, sửa README thành:

```text
Tài liệu kiểm thử hiện có: docs/test_note.md.
Ảnh kiểm thử và báo cáo Word sẽ được bổ sung ở bản nộp cuối nếu giảng viên yêu cầu.
```

Nếu cần nộp thật, tạo đủ:

```text
screenshots/
report/
report/BaoCao_QLSV_NhomXX.docx
```

---

## 12. README hướng dẫn build/chạy đang lệch với Makefile

### File liên quan

```text
README.md
source/Makefile
```

### Hiện trạng

Makefile tạo file:

```text
../qlsv.exe
```

Nhưng README phần build thủ công lại tạo:

```text
../qlsv
```

và hướng dẫn Linux/macOS chạy:

```bash
./qlsv
```

### Vì sao là lỗi

Nếu người dùng build bằng Makefile thì file sinh ra là:

```text
qlsv.exe
```

nhưng README lại hướng dẫn chạy:

```text
./qlsv
```

Dễ gây lỗi “không tìm thấy file”.

### Mức độ

**Bắt buộc sửa trước khi nộp.**

### Cách sửa tối thiểu

README nên thống nhất theo Makefile:

```bash
cd source
make clean
make all
```

Từ thư mục gốc project, chạy:

```bash
./qlsv.exe
```

Trên PowerShell:

```powershell
.\qlsv.exe
```

Nếu vẫn muốn giữ build thủ công, sửa `-o` thành:

```bash
-o ../qlsv.exe
```

---

## 13. README clone URL đang sai

### File liên quan

```text
README.md
```

### Hiện trạng

README hiện có dạng:

```bash
git clone https://github.com//.git
cd
```

### Mức độ

**Bắt buộc sửa.**

### Cách sửa

```bash
git clone https://github.com/PKT-zZ/QLSV_MI3310.git
cd QLSV_MI3310
```

---

# III. Kết luận theo mức độ ưu tiên

## Bắt buộc sửa trước khi nộp

```md
- [ ] Sửa README clone URL: `https://github.com/PKT-zZ/QLSV_MI3310.git`.
- [ ] Sửa README build/chạy cho khớp Makefile: dùng `qlsv.exe`.
- [ ] Sửa README phần prototype Thành viên 2 cho khớp tên hàm thật hoặc bỏ prototype cụ thể.
- [ ] Sửa README phần prototype Thành viên 3 vì `ui.h` chỉ public `showMainMenu(...)`, còn các hàm khác là `static` trong `ui.c`.
- [ ] Sửa README nếu còn nhắc `screenshots/`, `report/`, `docs/test-plan.md` nhưng repo chưa có.
- [ ] Sửa `search.h` để khai báo đủ các hàm đã có trong `search.c`.
```

## Nên sửa để demo chắc hơn

```md
- [ ] Bổ sung kiểm tra điểm ngoài khoảng trong `score.c`, không chỉ kiểm tra ở `ui.c`.
- [ ] Làm rõ hoặc sửa các hàm xóa ở `student.c`, `subject.c`, `courseclass.c`: ràng buộc liên quan đang nằm ở UI, không nằm trong module nghiệp vụ.
- [ ] Bảng điểm sinh viên nên in thêm `MaHP`, tên học phần hoặc số tín chỉ.
- [ ] Bảng điểm lớp học phần nên in thêm họ tên sinh viên.
- [ ] Nếu giữ yêu cầu “danh sách xếp hạng” trong README, nên thêm báo cáo GPA ranking hoặc sửa README thành “sắp xếp sinh viên theo GPA”.
```

## Không bắt buộc nếu chỉ bám README hiện tại

```md
- [ ] Chưa cần thêm xóa điểm nếu README/mục test không yêu cầu rõ CRUD đầy đủ cho điểm.
- [ ] Chưa cần refactor UI gọi toàn bộ `search.c` nếu chương trình hiện vẫn tìm kiếm đúng từ menu.
```

# IV. Chốt ngắn

Phần Thành viên 2 và 3 hiện không thấy lỗi logic lớn làm hỏng toàn bộ chương trình qua UI, nhưng có nhiều lỗi lệch giữa README và code thật.

Các lỗi đáng sửa nhất là:

1. README sai clone/build/chạy.
2. README nêu prototype không khớp header thật.
3. `search.h` thiếu prototype cho các hàm có trong `search.c`.
4. `score.c` chưa tự validate điểm nếu gọi trực tiếp.
5. Các hàm xóa nghiệp vụ không tự kiểm tra ràng buộc liên quan, dù UI đã chặn.
6. Báo cáo bảng điểm còn thiếu thông tin để khớp mô tả “đầy đủ” trong README.

```
```
