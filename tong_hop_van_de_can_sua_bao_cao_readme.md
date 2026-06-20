# Tổng hợp vấn đề cần sửa — Báo cáo PDF

**Dự án:** QLSV_MI3310 — Quản lý sinh viên bằng ngôn ngữ C  

---

## 1. Kết luận ngắn

Báo cáo có bố cục tốt và phần lớn nội dung kỹ thuật chính khớp với dự án: module hóa rõ, dùng file text, có mảng động tự cài, có tìm kiếm/sắp xếp cơ bản, có kiểm thử tự động `68/68 PASS`.

Các lỗi còn lại chủ yếu nằm ở:

1. **Hướng dẫn build thủ công bị sai.**
3. **Dữ liệu mẫu trong một số phần của báo cáo/README.md còn là dữ liệu cũ.**

---

# 2. Bắt buộc sửa trước khi nộp

## 2.1. Báo cáo PDF

### Lỗi 1 — Lệnh build thủ công bị thiếu file nguồn

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 6.1 — đoạn “Trong trường hợp không sử dụng Makefile...” |
| **Hiện trạng** | Báo cáo ghi lệnh: `gcc main.c arrays.c fileio.c sort.c ui.c -o ../qlsv` |
| **Vấn đề** | Lệnh thiếu các file quan trọng: `student.c`, `subject.c`, `courseclass.c`, `score.c`, `gpa.c`, `search.c`. Ngoài ra output nên thống nhất là `../qlsv.exe` như Makefile. |
| **Rủi ro** | Nếu giảng viên copy lệnh này để build thủ công, chương trình sẽ lỗi link kiểu `undefined reference`. |
| **Cách sửa** | Thay bằng lệnh đầy đủ dưới đây. |

```bash
gcc -Wall -Wextra -std=c99 arrays.c fileio.c student.c subject.c courseclass.c score.c gpa.c sort.c search.c ui.c main.c -o ../qlsv.exe
```

Có thể ghi thêm:

```bash
cd ..
./qlsv.exe
```

Trên PowerShell:

```powershell
cd ..
.\qlsv.exe
```

---

---

### Lỗi 3 — Dữ liệu mẫu trong Chương 6.3 không khớp dữ liệu thật

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 6.3 — phần ví dụ dữ liệu mẫu trong `students.txt`, `subjects.txt`, `course_classes.txt`, `scores.txt` |
| **Hiện trạng** | Một số đoạn dùng dữ liệu cũ kiểu `22000001`, `KTLT`, `KTLT_K67_1`. |
| **Dữ liệu thật hiện tại** | Repo và Phụ lục C dùng dữ liệu dạng `202400000`, `MI3310`, `169313`. |
| **Rủi ro** | Báo cáo tự mâu thuẫn: Chương 6.3 dùng dữ liệu cũ, còn Phụ lục C lại dùng dữ liệu thật. Người chấm mở `data/` sẽ thấy không khớp. |
| **Cách sửa** | Copy dữ liệu mẫu đúng từ Phụ lục C hoặc từ 4 file thật trong `data/` để thay toàn bộ ví dụ ở Chương 6.3. |

**Dữ liệu nên thống nhất theo dạng hiện tại:**

```txt
students.txt
MSSV|HoTen|Lop|Birthday
202400000|Nguyen Van Toan|K69-MI1-01|15/08/2006
...
```

```txt
subjects.txt
MaHP|TenHP|SoTinChi
MI3310|Ky Thuat Lap Trinh|2
MI3060|Cau Truc Du Lieu & Thuat Toan|3
...
```

```txt
course_classes.txt
MaLHP|MaHP|HocKy|NamHoc
169313|MI3310|1|2025
...
```

---

### Lỗi 4 — Thiếu test case riêng cho chức năng xếp loại học lực

| Mục | Nội dung |
|---|---|
| **Vị trí** | Bảng 6.3 — test chức năng qua giao diện |
| **Hiện trạng** | Báo cáo liệt kê yêu cầu “hỗ trợ xếp loại học lực”, code có hàm xếp loại và ảnh minh chứng có dòng học lực, nhưng bảng test case chưa có dòng kiểm thử riêng cho chức năng này. |
| **Rủi ro** | Khi bảo vệ, giảng viên có thể hỏi: “Chức năng xếp loại học lực được test ở đâu?” |
| **Cách sửa** | Thêm 1 test case mới hoặc sửa TC tính GPA để ghi rõ có kiểm tra học lực. |

**Đề xuất thêm test case:**

| TC | Chức năng | Dữ liệu kiểm thử | Kết quả mong đợi | Kết quả |
|---|---|---|---|---|
| TC29 | Xếp loại học lực | Sinh viên có GPA hệ 10 thuộc các mốc khác nhau | Chương trình hiển thị đúng học lực: Xuất sắc/Giỏi/Khá/Trung bình/Yếu | Đạt |

Nếu không muốn tăng số TC, có thể sửa TC “Tính GPA” thành:

> Tính GPA và xếp loại học lực của sinh viên.

---

### Lỗi 5 — Cây thư mục có `report/` nhưng repo hiện chưa có thư mục này

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 3.1 — cây thư mục và Bảng 3.1 |
| **Hiện trạng** | Báo cáo liệt kê `report/`, nhưng repo root hiện có `data/`, `docs/`, `screenshots/`, `source/`, `.gitignore`, `README.md`; chưa thấy `report/`. |
| **Rủi ro** | Nếu giảng viên kiểm tra repo, cây thư mục trong báo cáo không khớp hoàn toàn. |
| **Cách sửa 1** | Tạo thư mục `report/`, đặt báo cáo PDF/LaTeX/Markdown vào đó rồi commit. |
| **Cách sửa 2** | Nếu báo cáo được nộp riêng ngoài repo, sửa mô tả thành: “`report/`: thư mục báo cáo trong gói nộp cuối, có thể được nộp tách khỏi repo.” |
| **Khuyến nghị** | Cách 1 sạch hơn nếu nhóm nộp qua GitHub/ZIP. |

---

# 3. Nên sửa nếu còn thời gian

### Vấn đề 1 — Chương 6.2, Chương 7 và Phụ lục A/B bị lặp nhiều

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 6.2, Chương 7, Phụ lục A, Phụ lục B |
| **Hiện trạng** | Nhiều đoạn trong Chương 7 dán source code dài; Phụ lục A/B lại lặp lại các đoạn code đó. |
| **Rủi ro** | Báo cáo dài và loãng. Người đọc có thể bỏ qua phần phân tích vì bị ngập code. |
| **Cách sửa** | Trong Chương 7 chỉ giữ đoạn code tiêu biểu hoặc pseudocode. Code đầy đủ đưa xuống Phụ lục, hoặc chỉ ghi “xem repo”. |

**Gợi ý xử lý:**

- Chương 7: giữ mô tả kết quả, luồng xử lý, ảnh minh chứng.
- Phụ lục: chỉ giữ 5–7 hàm quan trọng nhất.
- Không nên dán lại toàn bộ `main.c`, `fileio.c`, `ui.c`.

---

### Vấn đề 2 — Mô tả module `search.h/.c` chưa đủ so với code hiện tại

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 3.2 — mô tả module `search.h/.c` |
| **Hiện trạng** | Báo cáo chủ yếu mô tả tìm kiếm sinh viên theo MSSV và họ tên. |
| **Code hiện tại** | Module tìm kiếm còn có tìm sinh viên theo lớp, tìm môn học theo mã/tên, tìm lớp học phần theo mã. |
| **Cách sửa** | Viết lại đoạn mô tả cho đầy đủ. |

**Đề xuất đoạn thay thế:**

> Module `search.h/.c` phụ trách các chức năng tìm kiếm tuyến tính trên các danh sách dữ liệu. Module này hỗ trợ tìm sinh viên theo MSSV, họ tên hoặc lớp; tìm môn học theo mã học phần hoặc tên học phần; và tìm lớp học phần theo mã lớp học phần. Các hàm tìm kiếm đều duyệt tuần tự trên mảng động tương ứng, phù hợp với quy mô dữ liệu của bài tập lớn.

---

### Vấn đề 3 — Phụ lục B.4 thiếu `sortStudentByGPA`

| Mục | Nội dung |
|---|---|
| **Vị trí** | Phụ lục B.4 — Hàm tìm kiếm và sắp xếp |
| **Hiện trạng** | Thân bài nói có sắp xếp theo MSSV, họ tên và GPA, nhưng phụ lục chỉ đưa `sortStudentByMSSV` và `sortStudentByName`. |
| **Rủi ro** | Không nghiêm trọng, nhưng thiếu nhất quán. |
| **Cách sửa** | Thêm code hoặc mô tả ngắn cho `sortStudentByGPA`. |

Nếu không muốn dán thêm code, có thể thêm một câu:

> Hàm `sortStudentByGPA` được cài đặt tương tự Bubble Sort, nhưng so sánh GPA hệ 10 đã tính từ dữ liệu điểm và sắp xếp theo thứ tự giảm dần.

---

### Vấn đề 4 — Công thức điểm tổng kết trình bày chưa thống nhất

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 5.4, Chương 7.5, Phụ lục B |
| **Hiện trạng** | Có nơi ghi `DiemTK = 0.5 × DiemQT + 0.5 × DiemCK`; có nơi ghi `(DiemQT + DiemCK) / 2.0`. |
| **Đánh giá** | Hai công thức tương đương, không sai. Tuy nhiên nên thống nhất một cách viết. |
| **Cách sửa** | Dùng thống nhất công thức khớp code: `DiemTK = (DiemQT + DiemCK) / 2.0`. |

---

### Vấn đề 5 — Listing đường dẫn file bị giãn khoảng trắng

| Mục | Nội dung |
|---|---|
| **Vị trí** | Listing về các macro đường dẫn file, ví dụ `data / students . txt` |
| **Hiện trạng** | PDF có chỗ hiển thị đường dẫn bị tách khoảng trắng do định dạng LaTeX/PDF. |
| **Rủi ro** | Người đọc có thể hiểu nhầm đường dẫn thật có khoảng trắng. |
| **Cách sửa** | Đưa đường dẫn vào code block monospace và kiểm tra lại bản PDF. |

**Mẫu đúng:**

```c
#define STUDENT_FILE "data/students.txt"
#define SUBJECT_FILE "data/subjects.txt"
#define COURSE_CLASS_FILE "data/course_classes.txt"
#define SCORE_FILE "data/scores.txt"
```

---
