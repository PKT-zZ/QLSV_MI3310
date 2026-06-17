## 1. Kết luận

Dự án `QLSV_MI3310` **chưa nên nộp ngay** nếu chưa sửa các lỗi dưới đây. Phần lõi của dự án đã tương đối ổn, nhưng hiện còn một số điểm có thể làm bài bị trừ nặng khi giảng viên build/test hoặc demo trực tiếp.

Các việc bắt buộc cần làm:

1. Sửa lỗi `test_gpa.c` gọi sai hàm GPA.
2. Sửa `test_fileio.c` luôn trả về thành công dù test có lỗi.
3. Bổ sung chức năng **xóa điểm**.
4. Cập nhật `README.md` và `docs/test_note.md` cho đúng trạng thái code/test thật.
5. Dọn file nháp `sửa_code_13.6.md` khỏi bản nộp.
6. Chạy lại toàn bộ build/test và chỉ ghi kết quả PASS nếu đã chạy thật.

---

## 2. Sửa lỗi `test_gpa.c` gọi hàm GPA không tồn tại

### Mức độ

**Bắt buộc sửa.**

### Hiện trạng

Trong `source/gpa.h`, các hàm được khai báo là:

```c
float calculateStudentGPA4(...);
float calculateStudentGPA10(...);
const char* getAcademicRank(float gpa10);
```

Trong `source/gpa.c`, các hàm được triển khai cũng là:

```c
calculateStudentGPA4(...)
calculateStudentGPA10(...)
getAcademicRank(...)
```

Tuy nhiên, trong `source/test_gpa.c`, test lại gọi:

```c
calculateStudentGPA(...)
```

Hàm này hiện không tồn tại trong `gpa.c` và cũng không được khai báo trong `gpa.h`.

### Rủi ro

Target `make test_gpa` hoặc `make unit_test` có thể lỗi compile/link.

Đây là lỗi rất dễ bị phát hiện nếu giảng viên chạy:

```bash
make clean
make unit_test
```

### Cách sửa tối thiểu

Sửa trong `test_gpa.c`, đổi các lệnh gọi:

```c
calculateStudentGPA(...)
```

thành:

```c
calculateStudentGPA4(...)
```

Ví dụ:

```c
float gpa1 = calculateStudentGPA4("SV001", &scores, &clss, &subs);
float gpa2 = calculateStudentGPA4("SV001", &scores, &clss, &subs);
float gpa3 = calculateStudentGPA4("SV999", &scores, &clss, &subs);
```

### Phương án khác

Có thể thêm wrapper để tương thích với test cũ.

Trong `gpa.h`:

```c
float calculateStudentGPA(
    const char* mssv,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
);
```

Trong `gpa.c`:

```c
float calculateStudentGPA(
    const char* mssv,
    ScoreArray* scores,
    CourseClassArray* classes,
    SubjectArray* subjects
) {
    return calculateStudentGPA4(mssv, scores, classes, subjects);
}
```

### Khuyến nghị

Nên sửa `test_gpa.c` gọi thẳng `calculateStudentGPA4()` để tên hàm rõ nghĩa và thống nhất với `gpa.h`.

---

## 3. Sửa `test_fileio.c` luôn báo thành công giả

### Mức độ

**Bắt buộc sửa.**

### Hiện trạng

Trong `source/test_fileio.c`, chương trình có biến đếm số test lỗi, ví dụ:

```c
int fail = 0;
```

Nhưng cuối chương trình vẫn:

```c
return 0;
```

ngay cả khi `fail > 0`.

### Rủi ro

`make test` có thể báo thành công dù bên trong test đã ghi nhận lỗi.

Đây là lỗi nghiêm trọng vì kết quả test không còn đáng tin.

### Cách sửa tối thiểu

Đổi:

```c
return 0;
```

thành:

```c
return fail > 0 ? 1 : 0;
```

Sau khi sửa, nếu có test fail, chương trình test sẽ trả về exit code khác 0 và `make test` sẽ báo lỗi đúng.

---

## 4. Bổ sung chức năng xóa điểm

### Mức độ

**Bắt buộc sửa nếu yêu cầu bài có đủ CRUD cho điểm.**

### Hiện trạng

Menu quản lý điểm hiện có các chức năng như:

- Hiển thị điểm.
- Nhập điểm.
- Cập nhật điểm.
- Tìm điểm.

Nhưng chưa có chức năng **xóa điểm**.

Trong khi đó, với quản lý điểm, yêu cầu thông thường là phải có đủ:

- Thêm điểm.
- Sửa điểm.
- Xóa điểm.
- Tìm/hiển thị điểm.

### Rủi ro

Khi demo, giảng viên có thể hỏi:

> “Phần quản lý điểm có đủ thêm, sửa, xóa không?”

Nếu không có xóa điểm, chức năng CRUD điểm bị thiếu.

### Cách sửa tối thiểu

#### 4.1. Thêm prototype vào `score.h`

```c
int deleteScoreRecord(
    ScoreArray* scores,
    const char* mssv,
    const char* maLHP
);
```

#### 4.2. Thêm hàm vào `score.c`

```c
int deleteScoreRecord(
    ScoreArray* scores,
    const char* mssv,
    const char* maLHP
) {
    int idx = sca_find(scores, mssv, maLHP);

    if (idx == -1) {
        return 0;
    }

    return sca_remove(scores, idx);
}
```

#### 4.3. Thêm hàm UI trong `ui.c`

```c
static void deleteScoreUI(ScoreArray* scores) {
    char mssv[12];
    char maLHP[15];

    readLine("Nhap MSSV can xoa diem: ", mssv, sizeof(mssv));
    readLine("Nhap MaLHP can xoa diem: ", maLHP, sizeof(maLHP));

    if (deleteScoreRecord(scores, mssv, maLHP)) {
        printf("Xoa diem thanh cong.\n");
    } else {
        printf("Khong tim thay ban ghi diem can xoa.\n");
    }
}
```

Lưu ý: tên hàm `readLine()` cần khớp với hàm đọc input thật đang dùng trong `ui.c`.

#### 4.4. Sửa menu quản lý điểm

Ví dụ:

```c
printf("\n========== QUAN LY DIEM =========="
       "\n1. Hien thi danh sach diem"
       "\n2. Nhap diem"
       "\n3. Cap nhat diem"
       "\n4. Xoa diem"
       "\n5. Tim diem"
       "\n0. Quay lai\n");
```

Trong `switch`:

```c
case 4:
    deleteScoreUI(scores);
    break;

case 5:
    searchScoreUI(scores);
    break;
```

---

## 5. Cập nhật `README.md`

### Mức độ

**Bắt buộc sửa trước khi nộp.**

### Các lỗi cần sửa

#### 5.1. Không ghi kết quả test PASS nếu chưa chạy lại

Nếu `README.md` đang ghi dạng:

```text
68/68 PASS
```

thì không nên giữ nguyên nếu chưa sửa code và chạy lại thật sự.

Đặc biệt, khi `test_gpa.c` còn gọi sai hàm GPA, kết luận test PASS là không đáng tin.

#### 5.2. Sửa URL clone

Nếu README còn placeholder:

```bash
git clone https://github.com/<ten-nhom>/<ten-repo>.git
cd <ten-repo>
```

cần đổi thành:

```bash
git clone https://github.com/PKT-zZ/QLSV_MI3310.git
cd QLSV_MI3310
```

#### 5.3. Sửa hướng dẫn build/chạy cho khớp Makefile

Nếu Makefile tạo file:

```text
qlsv.exe
```

thì README nên hướng dẫn rõ:

```bash
cd source
make clean
make all
```

Chạy từ thư mục gốc project:

```bash
./qlsv.exe
```

Hoặc trên Windows PowerShell:

```powershell
.\qlsv.exe
```

#### 5.4. Ghi rõ công thức điểm tổng kết

README nên ghi rõ:

```text
DiemTK = (DiemQT + DiemCK) / 2
```

và quy đổi hệ 4 theo các ngưỡng trong `score.c`.

Nếu đề bài yêu cầu trọng số khác, ví dụ 30% quá trình và 70% cuối kỳ, cần sửa cả code và README.

#### 5.5. Bỏ hoặc tạo các thư mục được README nhắc tới

Nếu README có nhắc các thư mục như:

```text
report/
screenshots/
```

nhưng repo không có, cần chọn một trong hai:

- Tạo thư mục/file tương ứng nếu thực sự cần nộp.
- Hoặc xóa khỏi README để tránh tài liệu nói không đúng repo.

---

## 6. Cập nhật `docs/test_note.md`

### Mức độ

**Bắt buộc sửa trước khi nộp.**

### Hiện trạng cần tránh

Không nên để `docs/test_note.md` chỉ mô tả test cũ, ví dụ chỉ nói về `test_fileio.c` và ghi kết quả cũ như:

```text
41 PASS / 0 FAIL
```

trong khi repo đã có thêm các test:

- `test_types.c`
- `test_arrays.c`
- `test_fileio_unit.c`
- `test_gpa.c`

Ngoài ra, cần sửa các lỗi format đường dẫn nếu có, ví dụ:

```text
source\a rrays.c
source\f ileio.c
source\t est_fileio.c
```

### Nội dung nên cập nhật

`docs/test_note.md` nên phân biệt rõ:

#### Unit test

- `test_types.c`
- `test_arrays.c`
- `test_fileio_unit.c`
- `test_gpa.c`

Lệnh chạy:

```bash
make unit_test
```

#### Integration test

- `test_fileio.c`

Lệnh chạy:

```bash
make test
```

#### Lệnh kiểm tra tổng thể

```bash
make clean
make all
make unit_test
make test
```

### Mẫu nội dung thay thế tối thiểu

```md
# Ghi chú kiểm thử

## 1. Môi trường kiểm thử

- Hệ điều hành: Windows 11
- Compiler: GCC / MinGW hoặc MSYS2
- Cờ biên dịch: `-Wall -Wextra -std=c99`
- Thư mục chạy lệnh: `source/`

## 2. Unit test

Các file unit test:

- `test_types.c`
- `test_arrays.c`
- `test_fileio_unit.c`
- `test_gpa.c`

Chạy:

```bash
make unit_test
```

## 3. Integration test

File integration test:

- `test_fileio.c`

Chạy:

```bash
make test
```

## 4. Kết quả chạy gần nhất

Sau khi sửa code, chạy lại:

```bash
make clean
make all
make unit_test
make test
```

Kết quả:

- `make all`: ...
- `make unit_test`: ...
- `make test`: ...

Chỉ ghi PASS nếu đã chạy thật và không có lỗi.
```

---

## 7. Dọn file nháp `sửa_code_13.6.md`

### Mức độ

**Bắt buộc dọn trước khi nộp chính thức.**

### Hiện trạng

Repo có file:

```text
sửa_code_13.6.md
```

Đây là tên file giống ghi chú nháp trong quá trình sửa code.

### Rủi ro

- Trông không giống file cần nộp chính thức.
- Tên file có dấu, dễ gây lỗi hoặc bất tiện khi thao tác terminal.
- Nội dung có thể làm giảng viên thấy đây là bản nháp/chưa hoàn thiện.
- Có thể làm tăng nghi ngờ về việc dùng AI/agent nếu nội dung giống checklist sửa code.

### Cách xử lý khuyến nghị

Xóa khỏi bản nộp:

```bash
git rm "sửa_code_13.6.md"
git commit -m "Remove temporary code review note"
```

Nếu muốn giữ lại, chuyển vào `docs/` và đổi tên không dấu:

```text
docs/refactor_note.md
```

Tuy nhiên, nếu không bắt buộc phải nộp file này, nên xóa.

---

## 8. Chạy lại toàn bộ build/test

### Mức độ

**Bắt buộc.**

Sau khi sửa các lỗi trên, chạy từ thư mục `source/`:

```bash
make clean
make all
make unit_test
make test
```

Nếu đã thêm target `full_test`, có thể chạy thêm:

```bash
make full_test
```

### Kết quả cần đạt

- `make clean`: không lỗi.
- `make all`: build được `qlsv.exe`.
- `make unit_test`: tất cả unit test pass.
- `make test`: integration test pass.
- Chạy chương trình chính được.
- Menu chính vào được các nhóm chức năng.
- Thử thao tác thêm/sửa/xóa/tìm ít nhất một bản ghi cho từng nhóm chức năng chính.

---

## 9. Những điểm không bắt buộc sửa ngay

Các điểm dưới đây nên sửa nếu còn thời gian, nhưng không xếp vào nhóm bắt buộc nếu chương trình đã build/test/demo ổn:

1. `ui.c` đang ôm quá nhiều trách nhiệm.
2. `search.c` có thể chưa được tích hợp triệt để.
3. File I/O dùng `atoi/atof`, nên parse số chưa thật chặt.
4. Comment/README có thể hơi nhiều ký hiệu trình bày.
5. Một số module nghiệp vụ có nhưng UI vẫn gọi trực tiếp array.
6. Test chưa bao phủ hết `score.c`, `sort.c`, `student.c`, `subject.c`, `courseclass.c`.

---

## 10. Checklist bắt buộc cuối cùng

```md
- [ ] Sửa `test_gpa.c`: đổi `calculateStudentGPA()` thành `calculateStudentGPA4()` hoặc thêm wrapper tương thích.
- [ ] Sửa `test_fileio.c`: đổi `return 0;` thành `return fail > 0 ? 1 : 0;`.
- [ ] Thêm `deleteScoreRecord()` vào `score.h` và `score.c`.
- [ ] Thêm `deleteScoreUI()` vào `ui.c`.
- [ ] Thêm lựa chọn “Xoa diem” vào menu quản lý điểm.
- [ ] Sửa `README.md`: URL clone thật, hướng dẫn chạy đúng `qlsv.exe`, công thức điểm, kết quả test thật.
- [ ] Sửa `docs/test_note.md`: phân biệt unit test/integration test, cập nhật test mới, sửa lỗi format đường dẫn.
- [ ] Xóa hoặc di chuyển/đổi tên file `sửa_code_13.6.md`.
- [ ] Chạy lại `make clean`.
- [ ] Chạy lại `make all`.
- [ ] Chạy lại `make unit_test`.
- [ ] Chạy lại `make test`.
- [ ] Chạy thử chương trình chính và demo các chức năng chính.
- [ ] Chỉ commit/push bản cuối sau khi toàn bộ bước trên ổn.
```

---

## 11. Thứ tự sửa đề xuất

Nên sửa theo thứ tự sau để tránh rối:

### Bước 1 — Sửa test/build

1. Sửa `test_gpa.c`.
2. Sửa `test_fileio.c`.
3. Chạy:

```bash
make clean
make unit_test
make test
```

### Bước 2 — Sửa chức năng thiếu

4. Thêm xóa điểm trong `score.h/.c`.
5. Thêm xóa điểm trong `ui.c`.
6. Chạy:

```bash
make all
```

và test thủ công chức năng xóa điểm.

### Bước 3 — Sửa tài liệu

7. Cập nhật `README.md`.
8. Cập nhật `docs/test_note.md`.
9. Xóa hoặc dọn `sửa_code_13.6.md`.

### Bước 4 — Kiểm tra lần cuối

10. Chạy:

```bash
make clean
make all
make unit_test
make test
```

11. Chạy chương trình chính và demo thử.

---

## 12. Kết luận cuối

Sau khi sửa các mục bắt buộc trên, dự án sẽ đạt trạng thái an toàn hơn nhiều để nộp và bảo vệ.

Ưu tiên cao nhất là:

1. Sửa lỗi `test_gpa.c`.
2. Sửa `test_fileio.c`.
3. Bổ sung xóa điểm.
4. Cập nhật tài liệu theo kết quả thật.
5. Dọn file nháp khỏi repo.

Không nên nộp khi README ghi test pass nhưng target test thực tế vẫn có khả năng fail.
