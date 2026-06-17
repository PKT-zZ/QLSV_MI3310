# QLSV_MI3310 — Tổng hợp lỗi đang có cần sửa trước khi chạy test/nộp

> Phạm vi bản này: chỉ tập trung vào lỗi làm code/test/Makefile không chạy đúng, tính năng README đã nêu nhưng code/test chưa khớp, và tài liệu README/test_note đang sai lệch.  
> Không xét các vấn đề phụ như phong cách code, comment dài, dấu hiệu AI, module chưa tối ưu, hay kiến trúc chưa sạch.

---

## Kết luận ngắn

Repo hiện **chưa nên coi là bản ổn để nộp/chạy mục 13** vì còn các lỗi trực tiếp ảnh hưởng đến build/test và tài liệu:

1. `test_gpa.c` đang gọi hàm `calculateStudentGPA()` nhưng `gpa.h/gpa.c` hiện không có hàm này.
2. `test_fileio.c` vẫn `return 0` dù có thể có test fail, làm `make test` báo pass giả.
3. `README.md` và `docs/test_note.md` đang ghi `68/68 PASS`, nhưng kết luận này không còn đáng tin khi `test_gpa.c` đang gọi sai API.
4. Hướng dẫn clone/build/chạy trong `README.md` đang sai hoặc lệch với Makefile thực tế.
5. `README.md` nhắc một số file/thư mục/tên hàm chưa khớp repo hiện tại.
6. Makefile có thể chạy được về mặt target, nhưng phần chạy file `.exe` trên Git Bash/MSYS2 có rủi ro do biến `DOTSLASH` đang phụ thuộc `$(OS)` theo kiểu chưa chắc đúng với shell đang dùng.

---

## 1. Lỗi build/test: `test_gpa.c` gọi hàm không tồn tại

### File liên quan

- `source/test_gpa.c`
- `source/gpa.h`
- `source/gpa.c`
- `source/Makefile`

### Hiện trạng

Trong `source/gpa.h`, API hiện có:

```c
float calculateStudentGPA4(...);
float calculateStudentGPA10(...);
const char* getAcademicRank(float gpa10);
```

Trong `source/gpa.c`, code cũng chỉ triển khai:

```c
calculateStudentGPA4(...)
calculateStudentGPA10(...)
getAcademicRank(...)
```

Nhưng trong `source/test_gpa.c`, test vẫn gọi:

```c
calculateStudentGPA(...)
```

ở 3 chỗ:

```c
float gpa1 = calculateStudentGPA("SV001", &scores, &clss, &subs);
float gpa2 = calculateStudentGPA("SV001", &scores, &clss, &subs);
float gpa3 = calculateStudentGPA("SV999", &scores, &clss, &subs);
```

### Ảnh hưởng

`make unit_test` sẽ bị lỗi ở target `test_gpa`, vì Makefile đang build:

```make
test_gpa:
	$(CC) $(CFLAGS) arrays.c gpa.c test_gpa.c -o ../test_gpa.exe
	cd .. && $(DOTSLASH)test_gpa.exe
```

Khi link, `test_gpa.c` cần hàm `calculateStudentGPA`, nhưng `gpa.c` không cung cấp hàm này.

### Kết luận lỗi

Đây là lỗi **bắt buộc sửa**. Nếu không sửa, kết quả `unit_test` không thể đúng.

### Sửa tối thiểu

Đổi trong `source/test_gpa.c`:

```c
calculateStudentGPA(...)
```

thành:

```c
calculateStudentGPA4(...)
```

Cụ thể:

```c
float gpa1 = calculateStudentGPA4("SV001", &scores, &clss, &subs);
float gpa2 = calculateStudentGPA4("SV001", &scores, &clss, &subs);
float gpa3 = calculateStudentGPA4("SV999", &scores, &clss, &subs);
```

Sửa luôn comment đầu file:

```c
//Test: hàm calculateStudentGPA()
```

thành:

```c
//Test: hàm calculateStudentGPA4()
```

---

## 2. Lỗi test: `test_fileio.c` có thể báo pass giả

### File liên quan

- `source/test_fileio.c`
- `source/Makefile`
- `docs/test_note.md`
- `README.md`

### Hiện trạng

Trong `test_fileio.c`, chương trình có biến đếm lỗi:

```c
int pass = 0, fail = 0;
```

Cuối chương trình có phân nhánh in kết quả:

```c
if (fail == 0)
    printf("KET QUA: %d/%d PASS -- tat ca dung!\n", pass, pass + fail);
else
    printf("KET QUA: %d PASS, %d FAIL -- co loi!\n", pass, fail);
```

Nhưng ngay sau đó vẫn:

```c
return 0;
```

### Ảnh hưởng

Nếu có test fail, chương trình vẫn trả exit code `0`.

Điều này làm:

```bash
make test
```

vẫn có thể được Makefile xem là thành công dù bên trong test đã báo lỗi.

### Kết luận lỗi

Đây là lỗi **bắt buộc sửa** vì làm sai kết quả kiểm thử.

### Sửa tối thiểu

Đổi:

```c
return 0;
```

thành:

```c
return fail > 0 ? 1 : 0;
```

Sau khi sửa, nếu integration test có lỗi, `make test` sẽ trả lỗi đúng.

---

## 3. Lỗi tài liệu: README và test_note ghi `68/68 PASS` không còn đáng tin

### File liên quan

- `README.md`
- `docs/test_note.md`
- `source/test_gpa.c`
- `source/gpa.h`
- `source/gpa.c`
- `source/test_fileio.c`

### Hiện trạng

`README.md` đang ghi:

```text
Tổng kết: 68/68 PASS — không có lỗi.
```

`docs/test_note.md` cũng ghi:

```text
Kết quả tổng hợp 68/68 test case PASS — không có lỗi.
```

Trong đó có ghi:

```text
test_gpa.c: 3/3 PASS
test_fileio.c: 41/41 PASS
```

### Vấn đề

Hai kết luận trên đang lệch với trạng thái code hiện tại:

- `test_gpa.c` gọi `calculateStudentGPA()`, nhưng `gpa.h/gpa.c` không có hàm này.
- `test_fileio.c` luôn `return 0`, nên nếu fail cũng có thể bị báo pass ở mức Makefile.

### Ảnh hưởng

Giảng viên hoặc thành viên khác chạy lại test sẽ thấy tài liệu ghi pass nhưng code/test không khớp.

Đây là lỗi tài liệu nghiêm trọng vì mục tiêu hiện tại là chạy được Makefile và thực hiện kế hoạch kiểm thử.

### Kết luận lỗi

Phải sửa code test trước, chạy lại, rồi mới được ghi `68/68 PASS`.

### Sửa tối thiểu

Sau khi sửa `test_gpa.c` và `test_fileio.c`, chạy lại từ thư mục `source/`:

```bash
make clean
make all
make unit_test
make test
```

Chỉ khi các lệnh trên pass thật mới giữ dòng:

```text
68/68 PASS
```

Nếu chưa chạy lại, sửa README/test_note thành:

```text
Kết quả kiểm thử cần cập nhật lại sau khi chạy:
make clean
make all
make unit_test
make test
```

---

## 4. Lỗi README: hướng dẫn clone repository đang sai

### File liên quan

- `README.md`

### Hiện trạng

README đang ghi:

```bash
git clone https://github.com//.git
cd
```

### Ảnh hưởng

Người chấm hoặc thành viên khác làm theo README sẽ không clone được repo.

### Kết luận lỗi

Đây là lỗi tài liệu **bắt buộc sửa**.

### Sửa tối thiểu

Đổi thành:

```bash
git clone https://github.com/PKT-zZ/QLSV_MI3310.git
cd QLSV_MI3310
```

---

## 5. Lỗi README: hướng dẫn build/chạy lệch với Makefile

### File liên quan

- `README.md`
- `source/Makefile`

### Hiện trạng

Trong `source/Makefile`, file thực thi chính được đặt là:

```make
MAIN_EXE = ../qlsv.exe
```

Nhưng README phần build thủ công lại ghi:

```bash
gcc main.c arrays.c fileio.c student.c subject.c courseclass.c \
score.c gpa.c sort.c search.c ui.c -o ../qlsv
```

và hướng dẫn chạy:

```bash
./qlsv
```

trên Linux/macOS.

### Ảnh hưởng

Có 2 cách build tạo ra 2 tên file khác nhau:

- Makefile tạo `qlsv.exe`.
- README build thủ công tạo `qlsv`.

Điều này làm hướng dẫn chạy không thống nhất. Nếu người dùng build bằng Makefile nhưng chạy `./qlsv`, sẽ không thấy file.

### Kết luận lỗi

Đây là lỗi tài liệu **bắt buộc sửa** vì ảnh hưởng trực tiếp đến chạy chương trình.

### Sửa tối thiểu

Thống nhất theo Makefile hiện tại:

```bash
cd source
make clean
make all
```

Sau đó chạy từ thư mục gốc:

```bash
./qlsv.exe
```

Trên PowerShell:

```powershell
.\qlsv.exe
```

Nếu muốn README vẫn có build thủ công, sửa output thủ công thành:

```bash
gcc main.c arrays.c fileio.c student.c subject.c courseclass.c \
score.c gpa.c sort.c search.c ui.c -o ../qlsv.exe
```

---

## 6. Rủi ro Makefile khi chạy test trên Git Bash/MSYS2

### File liên quan

- `source/Makefile`
- `docs/test_note.md`

### Hiện trạng

Makefile đang dùng:

```make
ifeq ($(OS),Windows_NT)
	DOTSLASH =
	CLEAN_CMD = del /Q ..\*.exe 2>nul
else
	DOTSLASH = ./
	CLEAN_CMD = rm -f ../*.exe
endif
```

Các target test chạy file `.exe` bằng:

```make
cd .. && $(DOTSLASH)test_gpa.exe
```

Nếu `OS=Windows_NT`, `DOTSLASH` rỗng, lệnh thành:

```bash
cd .. && test_gpa.exe
```

### Vấn đề

Trên Windows CMD/PowerShell, gọi `test_gpa.exe` kiểu này thường chạy được.

Nhưng trên Git Bash/MSYS2, current directory thường không nằm trong `PATH`, nên cần:

```bash
./test_gpa.exe
```

Trong khi `docs/test_note.md` lại hướng dẫn dùng Git Bash/MSYS2 để chạy test bằng Makefile.

### Ảnh hưởng

Người dùng làm đúng theo `docs/test_note.md` nhưng vẫn có thể gặp lỗi dạng:

```text
test_gpa.exe: command not found
```

hoặc tương tự khi chạy test.

### Kết luận lỗi

Đây là lỗi tương thích Makefile/tài liệu cần sửa để chạy kiểm thử ổn trên môi trường nhóm đang dùng.

### Sửa tối thiểu

Cách đơn giản nhất: dùng `./` cho lệnh chạy file `.exe` trong Makefile:

```make
DOTSLASH = ./
```

Hoặc bỏ nhánh `ifeq ($(OS),Windows_NT)` cho biến `DOTSLASH`.

Ví dụ:

```make
DOTSLASH = ./

ifeq ($(OS),Windows_NT)
	CLEAN_CMD = del /Q ..\*.exe 2>nul
else
	CLEAN_CMD = rm -f ../*.exe
endif
```

Nếu chủ yếu chạy bằng Git Bash/MSYS2, nên ưu tiên cách này.

---

## 7. README/test_note lệch tên hàm GPA

### File liên quan

- `docs/test_note.md`
- `source/test_gpa.c`
- `source/gpa.h`
- `source/gpa.c`

### Hiện trạng

`docs/test_note.md` ghi:

```text
test_gpa.c — Tính GPA
Kiểm tra calculateStudentGPA tính đúng công thức...
```

Nhưng code hiện tại không có API `calculateStudentGPA`.

API thật hiện tại là:

```c
calculateStudentGPA4(...)
calculateStudentGPA10(...)
```

### Ảnh hưởng

Tài liệu mô tả sai module đang test.

Nếu sau đó sửa `test_gpa.c` gọi `calculateStudentGPA4()`, nhưng không sửa `test_note.md`, tài liệu vẫn lệch.

### Kết luận lỗi

Phải sửa `docs/test_note.md` cho khớp tên hàm thật.

### Sửa tối thiểu

Đổi mô tả:

```text
Kiểm tra calculateStudentGPA tính đúng công thức...
```

thành:

```text
Kiểm tra calculateStudentGPA4 tính đúng công thức GPA hệ 4 theo trọng số tín chỉ.
```

Nếu muốn bổ sung kiểm thử GPA hệ 10, cần thêm test riêng cho `calculateStudentGPA10()`.

---

## 8. README đang nhắc file/thư mục chưa có hoặc chưa chắc tồn tại trong repo nộp

### File liên quan

- `README.md`
- repo root

### Hiện trạng

README phần tài liệu liên quan ghi:

```text
Báo cáo cuối kỳ: report/BaoCao_QLSV_NhomXX.docx
Ảnh kiểm thử: screenshots/
```

Trong phần kế hoạch còn nhắc:

```text
docs/test-plan.md hoặc report/
screenshots/
report/BaoCao_QLSV_NhomXX.docx
```

### Vấn đề

Nếu repo nộp không có các thư mục/file này, README đang mô tả không đúng trạng thái repo.

### Ảnh hưởng

Không làm code lỗi, nhưng làm hồ sơ nộp thiếu nhất quán. Giảng viên mở README rồi tìm `report/`, `screenshots/`, `docs/test-plan.md` có thể không thấy.

### Kết luận lỗi

Cần sửa trước khi nộp nếu README được dùng làm tài liệu chính.

### Sửa tối thiểu

Một trong hai cách:

#### Cách 1 — tạo đủ file/thư mục

Tạo:

```text
report/
screenshots/
docs/test-plan.md
```

nếu thật sự cần nộp.

#### Cách 2 — sửa README cho đúng thực tế

Ví dụ:

```text
Tài liệu kiểm thử hiện có: docs/test_note.md
Ảnh kiểm thử và báo cáo Word sẽ được bổ sung ở bản nộp cuối nếu giảng viên yêu cầu.
```

Nếu không định nộp `docs/test-plan.md`, nên bỏ dòng nhắc file này.

---

## 9. README mô tả một số prototype/hàm UI không khớp code hiện tại

### File liên quan

- `README.md`
- `source/ui.h`
- `source/ui.c`

### Hiện trạng

README phần Thành viên 3 ghi các hàm tối thiểu cần có:

```c
void showMainMenu();
void showStudentMenu();
void showSubjectMenu();
void showCourseClassMenu();
void showScoreMenu();
void displayTable();
void displayScoreCard();
```

và các hàm validation/đọc input:

```c
int validateMSSV(const char* mssv);
int validateScore(float score);
int validateDate(const char* date);
int isStudentKeyDuplicate(StudentArray* arr, const char* key);
int isSubjectKeyDuplicate(SubjectArray* arr, const char* key);
int isClassKeyDuplicate(CourseClassArray* arr, const char* key);
int readInt(const char* message);
float readFloat(const char* message);
```

Nhưng `source/ui.h` hiện chỉ public:

```c
void showMainMenu(StudentArray* students, SubjectArray* subjects, CourseClassArray* classes, ScoreArray* scores);
```

Các hàm còn lại phần lớn là `static` trong `ui.c`, hoặc tên thật khác README.

### Ảnh hưởng

Không nhất thiết làm chương trình lỗi, nhưng làm README sai lệch nếu giảng viên đối chiếu prototype với code.

### Kết luận lỗi

Cần sửa README để không yêu cầu các prototype không public, hoặc đổi code/header nếu nhóm thật sự muốn public các hàm này.

### Sửa tối thiểu

Trong README, đổi từ “các hàm tối thiểu cần có” sang “các chức năng giao diện cần có”, ví dụ:

```text
Các chức năng giao diện cần có:
- Menu chính.
- Menu quản lý sinh viên.
- Menu quản lý môn học.
- Menu quản lý lớp học phần.
- Menu quản lý điểm.
- Báo cáo/bảng điểm.
- Kiểm tra dữ liệu nhập.
```

Không nên liệt kê prototype nếu code không public các prototype đó trong `ui.h`.

---

## 10. README mục 13 có TC20 “đầy đủ các môn/lớp học phần, điểm và GPA”, nhưng bảng điểm sinh viên hiện chỉ in MaLHP, chưa in tên môn/mã học phần

### File liên quan

- `README.md`
- `source/ui.c`

### Hiện trạng

README TC20 ghi:

```text
Hiển thị bảng điểm sinh viên
Kết quả mong đợi: Hiển thị đầy đủ các môn/lớp học phần, điểm và GPA
```

Trong `ui.c`, `showStudentScoreCard()` hiện in:

```text
MaLHP | DiemQT | DiemCK | DiemTK | He4
```

và cuối bảng có:

```text
GPA he 10
GPA he 4
Hoc luc
```

### Vấn đề

Chức năng đã có GPA/học lực, nhưng phần “đầy đủ các môn/lớp học phần” trong README chưa thật sự đầy đủ nếu chỉ in `MaLHP`.

Người dùng nhìn bảng điểm chưa biết lớp học phần đó thuộc môn nào, tên môn là gì, số tín chỉ bao nhiêu.

### Ảnh hưởng

Không làm code crash, nhưng khi demo TC20 có thể bị hỏi vì sao “đầy đủ các môn/lớp học phần” mà chỉ thấy `MaLHP`.

### Kết luận lỗi

Đây là lỗi khớp yêu cầu/tài liệu ở mức nên sửa trước khi demo mục 13.

### Sửa tối thiểu

Trong `showStudentScoreCard()`, khi duyệt từng `ScoreRecord`, tra thêm:

1. `CourseClass` theo `maLHP`.
2. `Subject` theo `maHP`.

Sau đó in thêm ít nhất:

```text
MaLHP | MaHP | SoTC | DiemQT | DiemCK | DiemTK | He4
```

Nếu muốn tốt hơn:

```text
MaLHP | MaHP | TenHP | SoTC | DiemQT | DiemCK | DiemTK | He4
```

---

## 11. README mục 13 có TC21 “danh sách sinh viên và điểm”, nhưng bảng điểm lớp hiện chỉ in MSSV, chưa in họ tên

### File liên quan

- `README.md`
- `source/ui.c`

### Hiện trạng

README TC21 ghi:

```text
Hiển thị bảng điểm lớp học phần
Kết quả mong đợi: Hiển thị danh sách sinh viên và điểm trong lớp học phần
```

Trong `ui.c`, `showClassScoreTable()` hiện in:

```text
MSSV | DiemQT | DiemCK | DiemTK | He4
```

### Vấn đề

Code có hiển thị mã sinh viên và điểm, nhưng nếu hiểu “danh sách sinh viên” là thông tin sinh viên đầy đủ hơn, bảng đang thiếu `HoTen`.

### Ảnh hưởng

Không làm chương trình sai nghiêm trọng, nhưng khi demo có thể bị hỏi vì sao bảng điểm lớp không có tên sinh viên.

### Kết luận lỗi

Nên sửa để TC21 thuyết phục hơn.

### Sửa tối thiểu

Đổi `showClassScoreTable()` để nhận thêm `StudentArray* students`, rồi khi in mỗi điểm thì tra `MSSV` sang họ tên.

In dạng:

```text
MSSV | HoTen | DiemQT | DiemCK | DiemTK | He4
```

Nếu không muốn sửa code, cần sửa TC21 trong README thành:

```text
Hiển thị danh sách MSSV và điểm trong lớp học phần
```

---

## 12. README mục 13 và docs/test_note chưa tách rõ test tự động với test thủ công

### File liên quan

- `README.md`
- `docs/test_note.md`

### Hiện trạng

README có mục 13 “Kế hoạch kiểm thử” gồm các TC01–TC28, phần lớn là test thủ công qua menu.

`docs/test_note.md` lại ghi kết quả `68/68 PASS` cho các test tự động:

- `test_types.c`
- `test_arrays.c`
- `test_fileio_unit.c`
- `test_gpa.c`
- `test_fileio.c`

Nhưng chưa nói rõ:

- TC01–TC28 trong README đã chạy thủ công chưa.
- TC nào được test tự động.
- TC nào cần demo bằng tay.
- Kết quả manual test ra sao.

### Ảnh hưởng

Nhóm có thể bị nhầm rằng `68/68 PASS` nghĩa là toàn bộ mục 13 đã pass, trong khi thực tế `68/68` chỉ là các test code/unit/integration.

### Kết luận lỗi

Cần sửa tài liệu để không đánh đồng unit/integration test với manual test theo mục 13.

### Sửa tối thiểu

Trong `docs/test_note.md`, thêm phân tách:

```md
## A. Automated test bằng Makefile

- test_types.c
- test_arrays.c
- test_fileio_unit.c
- test_gpa.c
- test_fileio.c

Lệnh chạy:
make clean
make all
make unit_test
make test

## B. Manual test theo README mục 13

- TC01–TC06: quản lý sinh viên/môn/lớp.
- TC07–TC13: nhập, cập nhật, kiểm tra điểm.
- TC14–TC15: GPA hệ 10, xếp loại.
- TC16–TC19: tìm kiếm, sắp xếp.
- TC20–TC21: bảng điểm.
- TC22–TC24: chặn xóa dữ liệu đang được tham chiếu.
- TC25–TC28: File I/O, save-load, quy đổi hệ 4.

Kết quả manual test: chỉ ghi PASS sau khi đã thao tác thật trên chương trình.
```

---

## 13. Không xếp “xóa điểm” vào lỗi bắt buộc theo README hiện tại

### File liên quan

- `README.md`
- `source/ui.c`
- `source/score.c/h`

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

### Đánh giá

Nếu xét CRUD đầy đủ thì thiếu xóa điểm. Tuy nhiên, theo README hiện tại:

- Quản lý điểm số được mô tả là nhập và cập nhật điểm.
- Mục 13 không có test case xóa điểm.
- TC07–TC12 chỉ yêu cầu nhập/cập nhật/tính lại điểm.

### Kết luận

Không coi “xóa điểm” là lỗi bắt buộc trong phạm vi sửa hiện tại.

Chỉ cần thêm nếu:

- Đề bài chính thức yêu cầu quản lý điểm có đủ thêm/sửa/xóa.
- README được sửa thành có “xóa điểm”.
- Nhóm muốn demo CRUD điểm đầy đủ hơn.

---

## 14. Checklist lỗi cần sửa theo đúng ưu tiên

```md
- [ ] Sửa `source/test_gpa.c`: đổi `calculateStudentGPA()` thành `calculateStudentGPA4()`.
- [ ] Sửa comment trong `test_gpa.c` cho khớp API thật.
- [ ] Sửa `source/test_fileio.c`: đổi `return 0;` thành `return fail > 0 ? 1 : 0;`.
- [ ] Chạy lại `make unit_test`; nếu còn lỗi thì chưa được cập nhật README/test_note.
- [ ] Chạy lại `make test`; kiểm tra integration test trả exit code đúng.
- [ ] Sửa README phần clone: `https://github.com/PKT-zZ/QLSV_MI3310.git`.
- [ ] Sửa README phần build/chạy: thống nhất dùng `qlsv.exe` nếu Makefile tạo `qlsv.exe`.
- [ ] Sửa README/test_note: bỏ hoặc tạm treo kết luận `68/68 PASS` cho đến khi chạy lại thật.
- [ ] Sửa `docs/test_note.md`: đổi mô tả `calculateStudentGPA` thành `calculateStudentGPA4`.
- [ ] Sửa `docs/test_note.md`: tách rõ automated test và manual test theo README mục 13.
- [ ] Sửa README nếu còn nhắc `report/`, `screenshots/`, `docs/test-plan.md` nhưng repo chưa có các file/thư mục này.
- [ ] Sửa README phần prototype UI/validation để khớp code hiện tại, hoặc bỏ danh sách prototype cụ thể.
- [ ] Kiểm tra/sửa Makefile để chạy `.exe` ổn trên Git Bash/MSYS2 nếu nhóm dùng môi trường này.
- [ ] Cải thiện bảng điểm sinh viên: nên in thêm `MaHP`/tên môn/số tín chỉ để khớp TC20.
- [ ] Cải thiện bảng điểm lớp học phần: nên in thêm họ tên sinh viên để khớp TC21.
```

---

## 15. Lệnh kiểm tra cuối sau khi sửa

Chạy từ thư mục `source/`:

```bash
make clean
make all
make unit_test
make test
```

Sau đó chạy chương trình chính từ thư mục gốc:

```bash
./qlsv.exe
```

Trên PowerShell:

```powershell
.\qlsv.exe
```

Nếu dùng Git Bash/MSYS2 và Makefile vẫn lỗi khi gọi `.exe`, sửa lại biến `DOTSLASH` như đã nêu ở mục 6.

---

## 16. Chốt lỗi bắt buộc nhất

Nếu chỉ còn ít thời gian, sửa theo thứ tự này:

1. `test_gpa.c` gọi sai hàm.
2. `test_fileio.c` trả exit code sai.
3. README clone/build/chạy sai.
4. README/test_note ghi pass sai.
5. test_note mô tả sai tên hàm GPA.
6. Makefile chạy `.exe` chưa ổn trên Git Bash/MSYS2 nếu đó là môi trường nhóm dùng.

Các lỗi bảng điểm TC20/TC21 nên sửa tiếp theo để demo mục 13 thuyết phục hơn.
