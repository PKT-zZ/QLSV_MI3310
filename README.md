# Student Score Management System

## 1. Giới thiệu dự án

Dự án **Student Score Management System** là chương trình quản lý sinh viên và điểm số chạy trên giao diện console.

Dự án được thực hiện bởi nhóm 3 sinh viên ngành Toán – Khoa học máy tính trong khuôn khổ môn học Kỹ thuật lập trình / Cấu trúc dữ liệu và Giải thuật.

Chương trình tập trung vào việc tự cài đặt cấu trúc dữ liệu, thuật toán tìm kiếm, thuật toán sắp xếp và xử lý dữ liệu lưu trữ bằng file text.

---

## 2. Mục tiêu dự án

Xây dựng một chương trình console hoàn chỉnh bằng ngôn ngữ C, cho phép quản lý sinh viên, môn học, lớp học phần và điểm số.

Các mục tiêu chính:

- Quản lý thông tin sinh viên.
- Quản lý môn học.
- Quản lý lớp học phần.
- Quản lý điểm quá trình, điểm thi và điểm tổng kết.
- Tính GPA hệ 10, GPA hệ 4 và xếp loại học lực.
- Tự cài đặt cấu trúc dữ liệu và thuật toán, không sử dụng thư viện container hoặc hàm thuật toán có sẵn.

---

## 3. Phạm vi chức năng

| Nhóm chức năng | Mô tả |
|---|---|
| Quản lý sinh viên | Thêm, sửa, xóa, tìm kiếm sinh viên theo MSSV, họ tên, lớp |
| Quản lý môn học | Thêm, sửa, xóa, tìm kiếm môn học theo mã môn hoặc tên môn |
| Quản lý lớp học phần | Tạo, xóa lớp học phần, gắn sinh viên vào lớp |
| Quản lý điểm số | Nhập điểm quá trình, điểm thi, tính điểm tổng kết |
| Tính toán và báo cáo | Tính GPA hệ 10, GPA hệ 4, xếp loại học lực, in bảng điểm |
| Thuật toán | Tìm kiếm tuyến tính, tìm kiếm nhị phân, Bubble Sort, Selection Sort, Quick Sort |

---

## 4. Công nghệ sử dụng

| Thành phần | Lựa chọn |
|---|---|
| Ngôn ngữ lập trình | C, khuyến nghị ANSI C / C99 |
| Giao diện | Console menu |
| Lưu trữ dữ liệu | File text định dạng CSV tự thiết kế, dùng dấu phân cách `|` |
| Cấu trúc dữ liệu chính | Dynamic Array tự cài đặt |
| Build | Makefile |
| Quản lý mã nguồn | Git và GitHub |

---

## 5. Ràng buộc kỹ thuật

Dự án tuân thủ các ràng buộc sau:

- Không sử dụng STL, Collections hoặc container có sẵn.
- Không sử dụng hàm `sort()`, `search()` hoặc thư viện thuật toán có sẵn.
- Không sử dụng JSON/XML parser.
- Dữ liệu được đọc/ghi bằng file text.
- Chương trình chạy trên console với menu lặp cho đến khi người dùng chọn thoát.
- Mã sinh viên, mã môn học và mã lớp học phần là khóa chính, không được trùng lặp.

---

## 6. Cấu trúc dữ liệu và thuật toán

### 6.1. Cấu trúc dữ liệu chính

Dự án sử dụng **Dynamic Array tự cài đặt** làm cấu trúc dữ liệu lõi.

Các thao tác cần cài đặt:

| Hàm | Mô tả |
|---|---|
| `da_init` | Khởi tạo mảng động |
| `da_add` | Thêm phần tử |
| `da_get` | Lấy phần tử theo chỉ số |
| `da_remove` | Xóa phần tử |
| `da_update` | Cập nhật phần tử |
| `da_resize` | Mở rộng dung lượng mảng |
| `da_find` | Tìm kiếm phần tử |
| `da_clear` | Giải phóng bộ nhớ |

### 6.2. Các struct chính

Các thực thể chính trong chương trình:

- `Student`: thông tin sinh viên.
- `Subject`: thông tin môn học.
- `CourseClass`: thông tin lớp học phần.
- `ScoreRecord`: thông tin điểm số.
- `DynamicArray`: mảng động tự cài đặt.

### 6.3. Thuật toán cần tự cài

- Linear Search.
- Binary Search.
- Bubble Sort.
- Selection Sort.
- Quick Sort, nếu còn thời gian.

---

## 7. Định dạng file lưu trữ

Dữ liệu được lưu bằng file text, sử dụng dấu `|` làm ký tự phân cách.

| File | Nội dung |
|---|---|
| `students.txt` | Thông tin sinh viên |
| `subjects.txt` | Thông tin môn học |
| `course_classes.txt` | Thông tin lớp học phần |
| `scores.txt` | Thông tin điểm số |

Ví dụ file `students.txt`:

```txt
MSSV|HoTen|Lop|NgaySinh|Email
22000001|Nguyen Van An|K67-MT|15/08/2003|an.nva@sv.edu.vn
22000002|Tran Thi Bich|K67-MT|20/03/2003|bich.tt@sv.edu.vn
```

---

## 8. Cấu trúc thư mục dự án

```text
NHOM_XX_QLSV/
├── source/
│   ├── main.c
│   ├── types.h
│   ├── dynarray.h
│   ├── dynarray.c
│   ├── fileio.h
│   ├── fileio.c
│   ├── student.h
│   ├── student.c
│   ├── subject.h
│   ├── subject.c
│   ├── courseclass.h
│   ├── courseclass.c
│   ├── score.h
│   ├── score.c
│   ├── gpa.h
│   ├── gpa.c
│   ├── sort.h
│   ├── sort.c
│   ├── search.h
│   ├── search.c
│   ├── ui.h
│   ├── ui.c
│   ├── validation.h
│   ├── validation.c
│   ├── report.h
│   ├── report.c
│   └── Makefile
│
├── data/
│   ├── students.txt
│   ├── subjects.txt
│   ├── course_classes.txt
│   └── scores.txt
│
├── screenshots/
├── report/
├── docs/
└── README.md
```

---

## 9. Phân công công việc

| Thành viên | Vai trò chính | Nhiệm vụ |
|---|---|---|
| Thành viên 1 | Core Data & File I/O | Thiết kế struct, cài DynamicArray, xử lý đọc/ghi file |
| Thành viên 2 | Business Logic & Algorithms | CRUD, xử lý điểm, GPA, tìm kiếm, sắp xếp |
| Thành viên 3 | Console UI, Validation & Documentation | Menu console, kiểm tra đầu vào, test, ảnh minh chứng, báo cáo |

---

## 10. Lộ trình triển khai 5 tuần

### Tuần 1: Chốt thiết kế và xây dựng cấu trúc lõi

Mục tiêu:

- Chốt yêu cầu kỹ thuật.
- Tạo cấu trúc thư mục.
- Viết `types.h`.
- Bắt đầu cài đặt `DynamicArray`.
- Phác thảo menu console.

Sản phẩm cuối tuần:

- `types.h`
- `dynarray.h`
- Cấu trúc thư mục ban đầu
- Tài liệu thiết kế nội bộ

---

### Tuần 2: Hoàn thiện DynamicArray, File I/O và CRUD danh mục

Mục tiêu:

- Hoàn thiện `dynarray.c`.
- Viết module đọc/ghi file.
- Cài CRUD cho sinh viên, môn học và lớp học phần.
- Có menu cơ bản chạy được.

Sản phẩm cuối tuần:

- `dynarray.c`
- `fileio.c`
- `student.c`
- `subject.c`
- `courseclass.c`
- Menu cơ bản

---

### Tuần 3: Nhập điểm, tính GPA, tìm kiếm và sắp xếp

Mục tiêu:

- Cài module điểm số.
- Cài công thức tính điểm tổng kết.
- Cài GPA hệ 10, GPA hệ 4 và xếp loại.
- Cài thuật toán tìm kiếm và sắp xếp.
- Tích hợp validation.

Sản phẩm cuối tuần:

- `score.c`
- `gpa.c`
- `sort.c`
- `search.c`
- `validation.c`
- Menu nhập điểm hoạt động

---

### Tuần 4: Hoàn thiện giao diện, báo cáo bảng điểm và kiểm thử tích hợp

Mục tiêu:

- Hoàn thiện toàn bộ menu.
- Cài chức năng in bảng điểm.
- Kiểm thử end-to-end.
- Chụp ảnh minh chứng các test case chính.

Sản phẩm cuối tuần:

- Chương trình chạy hoàn chỉnh
- `report.c`
- Ít nhất 80% test case pass
- Ảnh kiểm thử trong thư mục `screenshots/`

---

### Tuần 5: Tinh chỉnh, kiểm thử cuối và đóng gói nộp bài

Mục tiêu:

- Review toàn bộ code.
- Xóa code thừa.
- Bổ sung comment.
- Hoàn thiện báo cáo Word.
- Đóng gói sản phẩm cuối.

Sản phẩm cuối tuần:

- Mã nguồn sạch
- Báo cáo hoàn chỉnh
- File dữ liệu mẫu
- Ảnh kiểm thử
- README hoàn thiện
- File ZIP nộp bài

---

## 11. Kế hoạch kiểm thử

Một số test case chính:

| Mã test | Chức năng | Kết quả mong đợi |
|---|---|---|
| TC01 | Thêm sinh viên hợp lệ | Sinh viên được thêm thành công |
| TC02 | Thêm sinh viên trùng MSSV | Hiển thị lỗi, không thêm dữ liệu |
| TC03 | Nhập điểm ngoài khoảng 0–10 | Hiển thị lỗi |
| TC04 | Tìm sinh viên tồn tại | Hiển thị đúng thông tin sinh viên |
| TC05 | Tìm sinh viên không tồn tại | Hiển thị thông báo không tìm thấy |
| TC06 | Sắp xếp sinh viên theo MSSV | Danh sách tăng dần theo MSSV |
| TC08 | Tính GPA hệ 10 | Kết quả tính đúng theo tín chỉ |
| TC10 | Hiển thị bảng điểm sinh viên | Bảng điểm đầy đủ, đúng định dạng |
| TC12 | Đọc file rỗng | Chương trình không bị crash |
| TC14 | Lưu dữ liệu và mở lại | Dữ liệu vẫn còn sau khi khởi động lại |

---

## 12. Hướng dẫn build và chạy chương trình

### 12.1. Yêu cầu môi trường

Cần cài đặt:

- GCC hoặc trình biên dịch C tương đương.
- Make, nếu sử dụng Makefile.
- Git, nếu muốn clone repo từ GitHub.

### 12.2. Clone repository

```bash
git clone https://github.com/<ten-nhom>/<ten-repo>.git
cd <ten-repo>
```

### 12.3. Build chương trình

Nếu dùng Makefile:

```bash
cd source
make all
```

Nếu chưa có Makefile, có thể biên dịch thủ công:

```bash
gcc main.c dynarray.c fileio.c student.c subject.c courseclass.c score.c gpa.c sort.c search.c ui.c validation.c report.c -o qlsv
```

### 12.4. Chạy chương trình

Trên Linux/macOS:

```bash
./qlsv
```

Trên Windows:

```bash
qlsv.exe
```

---

## 13. Quy trình làm việc Git/GitHub của nhóm

Nhóm thống nhất không làm trực tiếp trên branch `main`.

Quy trình chuẩn:

1. Mỗi task được tạo thành một Issue.
2. Mỗi thành viên nhận Issue được giao.
3. Thành viên tạo branch riêng từ `main`.
4. Code và commit trên branch riêng.
5. Push branch lên GitHub.
6. Tạo Pull Request vào `main`.
7. Thành viên khác review code.
8. Chỉ merge vào `main` khi code đã ổn.

Ví dụ:

```bash
git checkout main
git pull origin main
git checkout -b feature/add-student
```

Sau khi code xong:

```bash
git add .
git commit -m "Add student creation feature"
git push origin feature/add-student
```

Sau đó tạo Pull Request trên GitHub:

```text
base: main
compare: feature/add-student
```

---

## 14. Tài liệu liên quan

- Kế hoạch chi tiết dự án: `docs/KeHoachDuAn_QLSV_5Tuan.docx`
- Báo cáo cuối kỳ: `report/BaoCao_QLSV_NhomXX.docx`
- Ảnh kiểm thử: `screenshots/`
- Dữ liệu mẫu: `data/`
