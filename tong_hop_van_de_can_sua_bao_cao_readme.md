# Tổng hợp vấn đề cần sửa — Báo cáo PDF và README.md

**Dự án:** QLSV_MI3310 — Quản lý sinh viên bằng ngôn ngữ C  
**Phạm vi rà soát:** báo cáo PDF, README.md, Makefile, `docs/test_note.md`, dữ liệu mẫu trong `data/`, ảnh minh chứng trong `screenshots/`, cùng các nhận xét phản biện từ 2 LLM khác.  
**Mục tiêu:** liệt kê các điểm cần sửa thực tế trước khi nộp, ưu tiên lỗi dễ bị giảng viên phát hiện khi đọc báo cáo hoặc chạy thử repo.

---

## 1. Kết luận ngắn

Báo cáo có bố cục tốt và phần lớn nội dung kỹ thuật chính khớp với dự án: module hóa rõ, dùng file text, có mảng động tự cài, có tìm kiếm/sắp xếp cơ bản, có kiểm thử tự động `68/68 PASS`.

Các lỗi còn lại chủ yếu nằm ở:

1. **Hướng dẫn build thủ công bị sai.**
2. **Bảng test case và ảnh minh chứng bị lệch mã TC.**
3. **Dữ liệu mẫu trong một số phần của báo cáo/README.md còn là dữ liệu cũ.**
4. **README.md vẫn mang tính kế hoạch ban đầu, chưa hoàn toàn giống tài liệu nộp cuối.**
5. **Một số phần báo cáo bị dài/lặp do dán nhiều source code.**

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

### Lỗi 2 — Bảng test case không khớp với ảnh minh chứng

| Mục | Nội dung |
|---|---|
| **Vị trí** | Bảng 6.3 và Phụ lục D.2 / thư mục `screenshots/` |
| **Hiện trạng** | Một số ảnh/caption đang dùng số TC của phiên bản cũ, không khớp Bảng 6.3 hiện tại. |
| **Ví dụ** | `TC03.png` trong phản biện được mô tả là ảnh thêm môn học mới, nhưng Bảng 6.3 lại dùng TC03 cho cập nhật sinh viên. `TC15.png` hiển thị học lực/GPA, nhưng bảng lại có thể đang dùng TC15 cho nhập điểm trùng. |
| **Rủi ro** | Giảng viên đối chiếu bảng test case với phụ lục ảnh sẽ thấy ngay sự lệch. Phần kiểm thử mất độ tin cậy. |
| **Cách sửa nhanh** | Không nhất thiết chụp lại toàn bộ ảnh. Chỉ cần mở từng ảnh trong `screenshots/`, xác định nội dung thật, rồi sửa caption Phụ lục D.2 cho khớp Bảng 6.3. |
| **Cách sửa chắc chắn hơn** | Đánh số lại/chụp lại đủ ảnh theo đúng thứ tự TC01–TC28 hiện tại. |

**Checklist cần làm:**

- [ ] Mở từng ảnh `TC01.png` đến `TC21.png`.
- [ ] Ghi lại nội dung thật của từng ảnh.
- [ ] So với Bảng 6.3.
- [ ] Sửa caption trong phụ lục.
- [ ] Sửa tên file nếu cần, nhưng ưu tiên sửa caption trước vì nhanh hơn.
- [ ] Đảm bảo không còn ảnh nào có số TC lệch nội dung.

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

## 2.2. README.md

### Lỗi 6 — README.md dùng dữ liệu mẫu cũ

| Mục | Nội dung |
|---|---|
| **Vị trí** | README.md — mục ví dụ dữ liệu mẫu |
| **Hiện trạng** | README còn dùng dữ liệu kiểu `22000001`, `KTLT`, `KTLT_K67_1`. |
| **Vấn đề** | Không khớp dữ liệu thật trong `data/` và không khớp Phụ lục C của báo cáo. |
| **Rủi ro** | Người đọc repo tưởng dữ liệu mẫu hiện tại là bộ cũ. |
| **Cách sửa** | Thay toàn bộ ví dụ dữ liệu trong README bằng dữ liệu đúng đang có trong `data/`, hoặc rút gọn và ghi “xem trực tiếp thư mục `data/`”. |

**Cách sửa gọn:**

```md
### Ví dụ dữ liệu mẫu

Dữ liệu mẫu hiện tại nằm trong thư mục `data/`, gồm:

- `students.txt`: 6 sinh viên.
- `subjects.txt`: 5 môn học.
- `course_classes.txt`: 5 lớp học phần.
- `scores.txt`: 22 bản ghi điểm.

Ví dụ:

    202400000|Nguyen Van Toan|K69-MI1-01|15/08/2006
    MI3310|Ky Thuat Lap Trinh|2
    169313|MI3310|1|2025
    202400000|169313|8.50|7.00|7.75|3.00
```

---

### Lỗi 7 — README.md bị dính dòng, định dạng Markdown khó đọc

| Mục | Nội dung |
|---|---|
| **Vị trí** | Toàn README.md |
| **Hiện trạng** | Một số heading và nội dung bị dính trên cùng một dòng, ví dụ tiêu đề chính và `## 1. Giới thiệu dự án` nằm liền nhau. |
| **Rủi ro** | GitHub vẫn có thể render một phần, nhưng file raw rất khó đọc và thiếu chuyên nghiệp. |
| **Cách sửa** | Chèn dòng trống trước/sau heading, bảng và code block. Mỗi heading nên đứng riêng một dòng. |

**Mẫu đúng:**

```md
# Quản lý sinh viên và điểm số | Student Management System

## 1. Giới thiệu dự án

Dự án **Quản lý sinh viên và điểm số** là chương trình quản lý sinh viên và điểm số chạy trên giao diện console.
```

---

### Lỗi 8 — README.md vẫn mang tính “kế hoạch ban đầu”, chưa giống tài liệu nộp cuối

| Mục | Nội dung |
|---|---|
| **Vị trí** | Các mục “Chức năng mở rộng nếu còn thời gian”, “khuyến nghị”, “nhóm có thể chọn...” |
| **Vấn đề** | README hiện vừa là kế hoạch, vừa là hướng dẫn sử dụng. Ở giai đoạn nộp cuối, nên chuyển README thành tài liệu mô tả sản phẩm đã hoàn thành. |
| **Rủi ro** | Người chấm có thể cảm thấy README chưa được cập nhật sau khi dự án hoàn tất. |
| **Cách sửa** | Giữ phần kế hoạch nếu cần, nhưng chuyển xuống cuối hoặc đổi thành “Phạm vi đã hoàn thành / Chưa thực hiện”. |

**Nên đổi:**

```md
### Chức năng mở rộng nếu còn thời gian
```

thành:

```md
### Chức năng chưa thực hiện / hướng phát triển
```

Và ghi rõ:

- Chưa dùng Binary Search.
- Chưa dùng Quick Sort.
- Chưa xuất báo cáo ra file riêng.
- Chưa có thống kê nâng cao.
- Chưa tự lưu sau mỗi thao tác.

---

# 3. Nên sửa nếu còn thời gian

## 3.1. Báo cáo PDF

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

### Vấn đề 6 — Bảng test case hơi khó đọc

| Mục | Nội dung |
|---|---|
| **Vị trí** | Bảng 6.3 |
| **Hiện trạng** | Một số dòng dài, dễ bị vỡ/tràn cột khi xuất PDF. |
| **Cách sửa** | Rút gọn câu trong ô; tăng chiều rộng cột mô tả/kết quả; bật lặp header bảng nếu bảng qua nhiều trang. |

---

### Vấn đề 7 — Cần phân biệt rõ test tự động và test giao diện thủ công

| Mục | Nội dung |
|---|---|
| **Vị trí** | Chương 6.4 và Phụ lục D |
| **Hiện trạng** | Báo cáo đã có kết quả 68/68 PASS, nhưng nên nhấn mạnh 68 test này là unit/integration test tự động, không phải toàn bộ TC01–TC28 qua UI. |
| **Cách sửa** | Thêm 1 đoạn giải thích ngắn trước hoặc sau Bảng 6.4. |

**Đề xuất câu thêm:**

> Các test case TC01–TC28 là kiểm thử chức năng qua giao diện console, được thực hiện thủ công và minh chứng bằng ảnh chụp. Bộ 68 test case tự động gồm unit test và integration test chạy bằng Makefile, dùng để kiểm tra các module nền tảng và đọc/ghi dữ liệu, không thay thế hoàn toàn kiểm thử giao diện.

---

## 3.2. README.md

### Vấn đề 8 — README.md nên bổ sung trạng thái kiểm thử hiện tại

| Mục | Nội dung |
|---|---|
| **Vị trí** | README.md — nên đặt sau phần hướng dẫn chạy test |
| **Hiện trạng** | README đã có hướng dẫn chạy test, nhưng nên trình bày gọn kết quả cuối cùng để người chấm nhìn nhanh. |
| **Cách sửa** | Thêm bảng trạng thái test. |

**Đề xuất thêm:**

```md
## Kết quả kiểm thử hiện tại

| Bộ test | Loại | Số case | Kết quả |
|---|---|---:|---|
| `test_types.c` | Unit test | 7 | 7/7 PASS |
| `test_arrays.c` | Unit test | 11 | 11/11 PASS |
| `test_fileio_unit.c` | Unit test | 6 | 6/6 PASS |
| `test_gpa.c` | Unit test | 3 | 3/3 PASS |
| `test_fileio.c` | Integration test | 41 | 41/41 PASS |
| **Tổng** |  | **68** | **68/68 PASS** |
```

---

### Vấn đề 9 — README.md nên có cây thư mục hiện tại

| Mục | Nội dung |
|---|---|
| **Vị trí** | README.md — phần đầu hoặc sau giới thiệu |
| **Hiện trạng** | README dài nhưng chưa thật sự rõ cấu trúc nộp cuối. |
| **Cách sửa** | Thêm cây thư mục ngắn, đúng với repo hiện tại. |

**Mẫu:**

```txt
QLSV_MI3310/
├── data/
│   ├── students.txt
│   ├── subjects.txt
│   ├── course_classes.txt
│   └── scores.txt
├── docs/
│   └── test_note.md
├── screenshots/
├── source/
│   ├── main.c
│   ├── types.h
│   ├── arrays.c / arrays.h
│   ├── fileio.c / fileio.h
│   ├── student.c / student.h
│   ├── subject.c / subject.h
│   ├── courseclass.c / courseclass.h
│   ├── score.c / score.h
│   ├── gpa.c / gpa.h
│   ├── search.c / search.h
│   ├── sort.c / sort.h
│   ├── ui.c / ui.h
│   └── Makefile
└── README.md
```

---

### Vấn đề 10 — README.md nên rút gọn phần “khuyến nghị/có thể chọn”

| Mục | Nội dung |
|---|---|
| **Vị trí** | Các mục giải thích thiết kế ban đầu, ví dụ “nhóm có thể chọn một trong hai cách...” |
| **Hiện trạng** | Phù hợp khi README là kế hoạch triển khai, nhưng không phù hợp lắm với README nộp cuối. |
| **Cách sửa** | Đổi từ văn phong “kế hoạch” sang văn phong “sản phẩm đã hoàn thành”. |

**Ví dụ sửa:**

Thay:

> Nhóm có thể chọn một trong hai cách triển khai...

bằng:

> Dự án sử dụng mảng động định kiểu riêng cho từng loại dữ liệu, gồm `StudentArray`, `SubjectArray`, `CourseClassArray` và `ScoreArray`.

---

# 4. Có thể giữ nguyên

| Nội dung | Lý do |
|---|---|
| Dùng Linear Search và Bubble Sort | Phù hợp phạm vi môn Kỹ thuật lập trình; báo cáo đã nêu độ phức tạp và hạn chế. |
| Thư mục `screenshots/` trong repo | Có ích cho minh chứng kiểm thử, không cần bỏ. |
| Kết quả kiểm thử tự động 68/68 PASS | Khớp với `docs/test_note.md` và nên giữ. |
| Mô tả module chính | Về cơ bản khớp repo, chỉ cần sửa phần `search.h/.c` cho đủ hơn. |
| Dùng file text với dấu phân cách `|` | Phù hợp yêu cầu bài tập lớn, đơn giản và dễ kiểm tra. |
| Nhắc đến hạn chế như chưa có DB, chưa có GUI | Hợp lý, miễn là không viết thành lỗi nghiêm trọng. |
| Thư viện chuẩn như `<stddef.h>` | Không đáng sửa gấp; đây vẫn là thư viện chuẩn C. |
| Một số câu văn lặp “Nhìn chung...” | Không ảnh hưởng kỹ thuật; chỉ sửa nếu còn thời gian chỉnh văn phong. |

---

# 5. Thứ tự ưu tiên sửa

## Ưu tiên 1 — sửa ngay

1. Sửa lệnh GCC thủ công trong Chương 6.1.
2. Đồng bộ caption ảnh Phụ lục D.2 với Bảng 6.3.
3. Sửa dữ liệu mẫu cũ trong Chương 6.3.
4. Thêm test case hoặc mô tả rõ kiểm thử xếp loại học lực.
5. Sửa dữ liệu mẫu cũ trong README.md.
6. Sửa định dạng Markdown bị dính dòng trong README.md.

## Ưu tiên 2 — nên làm trước khi xuất PDF cuối

7. Thêm hoặc ghi rõ `report/` trong repo/gói nộp.
8. Sửa mô tả `search.h/.c`.
9. Bổ sung `sortStudentByGPA` ở Phụ lục B hoặc ghi chú rõ.
10. Thống nhất công thức `DiemTK`.
11. Sửa listing đường dẫn file bị giãn khoảng trắng.
12. Thêm câu phân biệt test UI thủ công và 68 test tự động.

## Ưu tiên 3 — làm nếu còn thời gian

13. Rút gọn Chương 7 và Phụ lục code.
14. Căn lại Bảng 6.3 cho dễ đọc.
15. Rút gọn README.md theo hướng tài liệu nộp cuối.
16. Thêm cây thư mục hiện tại vào README.md.
17. Thêm bảng kết quả kiểm thử hiện tại vào README.md.

---

# 6. Gợi ý nội dung sửa nhanh cho README.md

Có thể dùng cấu trúc README gọn hơn như sau:

````md
# Quản lý sinh viên và điểm số

## 1. Giới thiệu

Chương trình quản lý sinh viên viết bằng C, chạy trên giao diện console, lưu dữ liệu bằng file text trong thư mục `data/`.

## 2. Chức năng chính

- Quản lý sinh viên.
- Quản lý môn học.
- Quản lý lớp học phần.
- Quản lý điểm số.
- Tính điểm tổng kết, GPA hệ 10, GPA hệ 4 và xếp loại học lực.
- Tìm kiếm và sắp xếp sinh viên.
- Hiển thị bảng điểm sinh viên và bảng điểm lớp học phần.

## 3. Cấu trúc thư mục

```txt
QLSV_MI3310/
├── data/
├── docs/
├── screenshots/
├── source/
└── README.md
```

## 4. Build và chạy

```bash
cd source
make clean
make all
cd ..
./qlsv.exe
```

Trên Windows PowerShell:

```powershell
cd source
mingw32-make clean
mingw32-make all
cd ..
.\qlsv.exe
```

Lưu ý: cần chạy `qlsv.exe` từ thư mục gốc project để đọc đúng `data/`.

## 5. Chạy test

```bash
cd source
make unit_test
make test
```

Kết quả hiện tại:

| Loại test | Số case | Kết quả |
|---|---:|---|
| Unit test | 27 | 27/27 PASS |
| Integration test | 41 | 41/41 PASS |
| Tổng | 68 | 68/68 PASS |

## 6. Dữ liệu mẫu

Dữ liệu nằm trong `data/`:

- `students.txt`
- `subjects.txt`
- `course_classes.txt`
- `scores.txt`

## 7. Hạn chế

- Chưa có cơ sở dữ liệu thật.
- Chưa có giao diện đồ họa.
- Chưa hỗ trợ tìm kiếm không dấu.
- Chưa tự lưu sau mỗi thao tác.
- Test giao diện console chủ yếu thực hiện thủ công qua ảnh minh chứng.
````

---

# 7. Ghi chú cuối

Không nên sửa quá nhiều theo hướng “làm lại báo cáo”. Trọng tâm là đồng bộ tài liệu với repo hiện tại. Nếu thời gian ít, chỉ cần xử lý nhóm lỗi bắt buộc là báo cáo đã giảm đáng kể rủi ro bị trừ điểm khi giảng viên đọc và chạy thử.
