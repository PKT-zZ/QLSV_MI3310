# Quản lý sinh viên và điểm số | Student Management System

## 1. Giới thiệu dự án

Dự án **Quản lý sinh viên và điểm số (Student Management System)** là chương trình quản lý sinh viên và điểm số chạy trên giao diện console.

Dự án được thực hiện bởi nhóm 3 sinh viên ngành Toán – Khoa học máy tính trong khuôn khổ môn học Kỹ thuật lập trình.

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
- Tạo sản phẩm có thể demo và bảo vệ trước giảng viên.

---

## 3. Phạm vi chức năng

Dự án tập trung vào đúng yêu cầu của bài tập lớn: xây dựng chương trình console quản lý sinh viên và điểm số, có đọc/ghi dữ liệu bằng file text, tự cài đặt cấu trúc dữ liệu và thuật toán cơ bản.

### 3.1. Chức năng bắt buộc

| Nhóm chức năng | Mô tả |
|---|---|
| Quản lý sinh viên | Thêm, sửa, xóa, tìm kiếm sinh viên theo MSSV, họ tên hoặc lớp |
| Quản lý môn học | Thêm, sửa, xóa, tìm kiếm môn học theo mã môn hoặc tên môn |
| Quản lý lớp học phần | Tạo, sửa, xóa, tìm kiếm lớp học phần; mỗi lớp học phần gắn với một môn học |
| Quản lý điểm số | Nhập và cập nhật điểm cho sinh viên theo MSSV và mã lớp học phần/mã môn |
| Tính toán kết quả học tập | Tính điểm tổng kết, điểm trung bình học kỳ hoặc tích lũy theo hệ 10; có thể quy đổi hệ 4 nếu nhóm triển khai |
| Xếp loại học lực | Xếp loại học lực dựa trên điểm trung bình |
| Tìm kiếm | Tìm kiếm sinh viên theo MSSV, họ tên hoặc lớp |
| Sắp xếp | Sắp xếp danh sách sinh viên theo MSSV, họ tên hoặc điểm trung bình |
| Báo cáo | Hiển thị bảng điểm của một sinh viên và bảng điểm của một lớp học phần |

> **⚠ Ràng buộc toàn vẹn tham chiếu bắt buộc thực thi:**  
> Chương trình phải kiểm tra dữ liệu liên quan trước khi xóa Sinh viên, Môn học hoặc Lớp học phần.
>
> - Không cho phép xóa **Sinh viên** nếu còn bản ghi điểm có `MSSV` tương ứng trong `scores.txt`.
> - Không cho phép xóa **Lớp học phần** nếu còn bản ghi điểm có `MaLHP` tương ứng trong `scores.txt`.
> - Không cho phép xóa **Môn học** nếu còn lớp học phần nào trong `course_classes.txt` sử dụng `MaMon` tương ứng.
>
> Nếu dữ liệu đang được tham chiếu, chương trình phải hiển thị thông báo lỗi và hủy thao tác xóa.

### 3.2. Chức năng mở rộng nếu còn thời gian

Các chức năng sau **không bắt buộc**, chỉ thực hiện sau khi các chức năng cốt lõi đã hoàn thành ổn định:

| Chức năng mở rộng | Ghi chú |
|---|---|
| Tìm kiếm nhị phân (Binary Search) | Chỉ áp dụng khi danh sách đã được sắp xếp theo đúng khóa |
| Quick Sort | Không bắt buộc; chỉ dùng để nâng cao phần thuật toán |
| Bảng xếp hạng theo GPA | Có thể thêm nếu đã hoàn thành bảng điểm sinh viên và bảng điểm lớp học phần |
| Xuất báo cáo ra file riêng | Không bắt buộc, vì yêu cầu chính chỉ cần hiển thị báo cáo trên console |
| Các thống kê nâng cao | Thống kê phân phối điểm, tỉ lệ đạt/rớt theo lớp học phần, v.v. |

---

## 4. Công nghệ sử dụng

| Thành phần | Lựa chọn |
|---|---|
| Ngôn ngữ lập trình | C, khuyến nghị ANSI C / C99 |
| Giao diện | Console menu |
| Lưu trữ dữ liệu | File text định dạng CSV tự thiết kế, dùng dấu phân cách `\|` |
| Cấu trúc dữ liệu chính | Dynamic Array tự cài đặt |
| Build | Makefile |
| Quản lý mã nguồn | Git và GitHub |

---

## 5. Ràng buộc kỹ thuật

Dự án tuân thủ các ràng buộc sau:

- Không sử dụng các thư viện cấu trúc dữ liệu hoặc hàm thuật toán có sẵn ngoài các thư viện chuẩn (như `stdio.h`, `string.h`, `stdlib.h`).
- Không sử dụng JSON/XML parser.
- Không sử dụng cơ sở dữ liệu thật.
- Cấu trúc dữ liệu và thuật toán phải tự cài đặt từ đầu.
- Dữ liệu được đọc/ghi bằng file text.
- Chương trình chạy trên console với menu lặp cho đến khi người dùng chọn thoát.
- Mã sinh viên, mã môn học và mã lớp học phần là khóa chính, không được trùng lặp.

> **Lưu ý về thuật toán:**  
> Phiên bản cơ bản chỉ cần cài **Linear Search** và một thuật toán sắp xếp đơn giản như **Bubble Sort** hoặc **Selection Sort** là đủ để đáp ứng yêu cầu bài tập lớn.  
> **Binary Search** và **Quick Sort** là phần mở rộng — không bắt buộc, chỉ thực hiện nếu còn thời gian và các chức năng cốt lõi đã ổn định.

---

## 6. Cấu trúc dữ liệu và thuật toán

### 6.1. Cấu trúc dữ liệu chính

Dự án sử dụng **Dynamic Array tự cài đặt** làm cấu trúc dữ liệu lõi. Nhóm có thể chọn một trong hai cách triển khai tùy theo sở thích và khả năng:

**Chọn Mảng động định kiểu riêng / Typed Dynamic Array:**

Khai báo một struct mảng động **riêng biệt cho từng kiểu dữ liệu**. Cách tiếp cận này an toàn kiểu dữ liệu, không cần ép kiểu `void*`, giảm thiểu nguy cơ nhầm kiểu và rò rỉ bộ nhớ.

```c
typedef struct {
    Student* data;   // Con trỏ đến vùng bộ nhớ cấp phát động
    int      size;   // Số phần tử hiện tại
    int      capacity;  // Dung lượng tối đa hiện tại
} StudentArray;

typedef struct {
    Subject* data;
    int      size;
    int      capacity;
} SubjectArray;

typedef struct {
    CourseClass* data;
    int          size;
    int          capacity;
} CourseClassArray;

typedef struct {
    ScoreRecord* data;
    int          size;
    int          capacity;
} ScoreArray;
```

Ưu điểm: an toàn kiểu dữ liệu, truy cập trực tiếp không cần cast, dễ debug.  
Nhược điểm: phải viết lặp bộ hàm thao tác cho từng struct (nhưng logic mỗi hàm đều giống nhau và ngắn gọn).

> **⚠ Lý do không khuyến nghị dùng mảng `void*` tổng quát:**  
> Cách dùng `void*` và `elemSize` (con trỏ dạng `(char*)arr->data + i * arr->elemSize`) yêu cầu ép kiểu thủ công mỗi khi truy cập phần tử. Với nhóm chưa thành thạo con trỏ, đây là nguồn gốc thường gặp của lỗi nhầm kiểu, truy cập sai vùng nhớ và memory leak khó phát hiện. **Hãy dùng Lựa chọn 1 hoặc Lựa chọn 2 thay thế.**

---

Các thao tác cần cài đặt (áp dụng cho Lựa chọn 1 — Typed Dynamic Array):

| Hàm (ví dụ cho `StudentArray`) | Mô tả |
|---|---|
| `sa_init` | Khởi tạo mảng động sinh viên |
| `sa_add` | Thêm phần tử `Student` |
| `sa_get` | Lấy con trỏ phần tử theo chỉ số |
| `sa_remove` | Xóa phần tử theo chỉ số |
| `sa_update` | Cập nhật phần tử theo chỉ số |
| `sa_resize` | Mở rộng dung lượng mảng |
| `sa_find` | Tìm kiếm phần tử |
| `sa_clear` | Giải phóng bộ nhớ |

Áp dụng tương tự với các prefix `suba_` (`SubjectArray`), `cca_` (`CourseClassArray`), `sca_` (`ScoreArray`).

### 6.2. Các struct chính

Các thực thể chính trong chương trình:

- `Student`: thông tin sinh viên.
- `Subject`: thông tin môn học.
- `CourseClass`: thông tin lớp học phần.
- `ScoreRecord`: thông tin điểm số.
- `StudentArray`, `SubjectArray`, `CourseClassArray`, `ScoreArray`: các mảng tự cài đặt (Typed Dynamic Array hoặc mảng tĩnh theo Lựa chọn 2).

### 6.3. Thuật toán cần tự cài

**Bắt buộc:**

- Linear Search — tìm kiếm tuyến tính, dùng cho mọi trường hợp.
- Bubble Sort hoặc Selection Sort — sắp xếp theo MSSV, họ tên hoặc điểm trung bình.

**Mở rộng (không bắt buộc, chỉ làm nếu còn thời gian):**

- Binary Search — chỉ áp dụng sau khi mảng đã được sắp xếp; **lưu ý quan trọng:** Binary Search chỉ cho kết quả đúng nếu mảng đã được sắp xếp **chính xác theo trường dữ liệu đang được dùng làm khóa tìm kiếm** (ví dụ: nếu tìm theo MSSV thì mảng phải đang được sắp xếp theo MSSV, không phải theo tên hay điểm). Dùng sai trường sắp xếp sẽ trả về kết quả sai hoặc không tìm thấy dù dữ liệu tồn tại.
- Quick Sort — thuật toán sắp xếp nhanh hơn, dùng để minh họa trong báo cáo.

---

## 7. Định dạng file lưu trữ

Dữ liệu của chương trình được lưu bằng **file text thuần**, sử dụng định dạng CSV tự thiết kế với ký tự phân cách là dấu gạch đứng `|`.

Nhóm chọn dấu `|` thay vì dấu phẩy `,` để hạn chế lỗi khi dữ liệu văn bản như họ tên, địa chỉ hoặc ghi chú có thể chứa dấu phẩy. Cách lưu này đơn giản hơn JSON/XML vì không cần dùng thư viện parser có sẵn, phù hợp với yêu cầu tự xử lý dữ liệu bằng C.

---

### 7.1. Quy ước chung

- Mỗi file dữ liệu có một dòng tiêu đề ở dòng đầu tiên.
- Mỗi dòng sau dòng tiêu đề tương ứng với một bản ghi.
- Các trường trong một dòng được phân tách bằng ký tự `|`.
- Không đặt ký tự `|` trong nội dung của một trường dữ liệu.
- Không để dòng trống giữa các bản ghi.
- Dữ liệu số thực dùng dấu chấm `.` làm dấu thập phân, ví dụ `8.5`, `7.25`.
- Dữ liệu ngày sinh dùng định dạng `DD/MM/YYYY`.
- Khi chương trình khởi động, dữ liệu được load từ các file trong thư mục `data/`.
- Khi người dùng chọn thoát chương trình, toàn bộ dữ liệu hiện tại được ghi lại xuống file.

---

### 7.2. Danh sách file dữ liệu

| File | Header | Ý nghĩa |
|---|---|---|
| `data/students.txt` | `MSSV\|HoTen\|Lop\|NgaySinh` | Lưu thông tin sinh viên |
| `data/subjects.txt` | `MaMon\|TenMon\|SoTinChi` | Lưu thông tin môn học |
| `data/course_classes.txt` | `MaLHP\|MaMon\|HocKy\|NamHoc` | Lưu thông tin lớp học phần |
| `data/scores.txt` | `MSSV\|MaLHP\|DiemQT\|DiemThi\|DiemTK\|DiemHe4` | Lưu điểm của sinh viên theo từng lớp học phần |

---

### 7.3. Ví dụ dữ liệu mẫu

#### `students.txt`

```txt
MSSV|HoTen|Lop|NgaySinh
22000001|Nguyen Van An|K67-MT|15/08/2003
22000002|Tran Thi Bich|K67-MT|20/03/2003
22000003|Le Hoang Cuong|K67-MT|05/11/2002
```

#### `subjects.txt`

```txt
MaMon|TenMon|SoTinChi
KTLT|Ky Thuat Lap Trinh|3
CTDL|Cau Truc Du Lieu|3
CSDL|Co So Du Lieu|3
```

#### `course_classes.txt`

```txt
MaLHP|MaMon|HocKy|NamHoc
KTLT_K67_1|KTLT|1|2024
CTDL_K67_2|CTDL|2|2024
CSDL_K67_2|CSDL|2|2024
```

#### `scores.txt`

```txt
MSSV|MaLHP|DiemQT|DiemThi|DiemTK|DiemHe4
22000001|KTLT_K67_1|8.5|7.0|7.60|3.0
22000002|KTLT_K67_1|9.0|8.5|8.70|4.0
22000003|CTDL_K67_2|7.0|7.5|7.30|3.0
```

---

### 7.4. Ý nghĩa các trường dữ liệu

#### Sinh viên — `Student`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MSSV` | `char[12]` | Mã số sinh viên, khóa chính, không được trùng |
| `HoTen` | `char[60]` | Họ và tên sinh viên |
| `Lop` | `char[20]` | Lớp hành chính của sinh viên |
| `NgaySinh` | `char[12]` | Ngày sinh, định dạng `DD/MM/YYYY` |

#### Môn học — `Subject`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MaMon` | `char[10]` | Mã môn học, khóa chính, không được trùng |
| `TenMon` | `char[80]` | Tên môn học |
| `SoTinChi` | `int` | Số tín chỉ của môn học |

#### Lớp học phần — `CourseClass`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MaLHP` | `char[15]` | Mã lớp học phần, khóa chính, không được trùng |
| `MaMon` | `char[10]` | Mã môn học tương ứng, tham chiếu đến `subjects.txt` |
| `HocKy` | `char[10]` | Học kỳ, ví dụ `1`, `2`, `He` |
| `NamHoc` | `int` | Năm học |

#### Điểm số — `ScoreRecord`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MSSV` | `char[12]` | Mã sinh viên, tham chiếu đến `students.txt` |
| `MaLHP` | `char[15]` | Mã lớp học phần, tham chiếu đến `course_classes.txt` |
| `DiemQT` | `float` | Điểm quá trình, từ `0.0` đến `10.0` |
| `DiemThi` | `float` | Điểm thi, từ `0.0` đến `10.0` |
| `DiemTK` | `float` | Điểm tổng kết, tính theo công thức `0.4 * DiemQT + 0.6 * DiemThi` |
| `DiemHe4` | `float` | Điểm quy đổi sang hệ 4 |

> **Ghi chú thiết kế — Phi chuẩn hóa có chủ đích (Denormalization):**  
> Việc lưu sẵn `DiemTK` và `DiemHe4` trực tiếp vào file `scores.txt` là **thiết kế phi chuẩn hóa có chủ đích**. Về lý thuyết, hai trường này có thể tính lại bất cứ lúc nào từ `DiemQT` và `DiemThi`. Tuy nhiên, lưu sẵn giúp giảm thiểu việc tính toán lại mỗi lần load file và đơn giản hóa phần đọc/ghi dữ liệu trong phạm vi dự án này. Khi cập nhật `DiemQT` hoặc `DiemThi`, chương trình **phải tính lại và cập nhật đồng thời** `DiemTK` và `DiemHe4`.

---

### 7.5. Quan hệ giữa các file dữ liệu

Các file dữ liệu có quan hệ logic với nhau như sau:

```text
students.txt
    MSSV  (PK)
      |
      | MSSV là khóa ngoại (FK) trong scores.txt
      v
scores.txt
    MSSV + MaLHP  (khóa duy nhất)

course_classes.txt
    MaLHP  (PK)
    MaMon  (FK) ──────────────────────────────┐
      |                                        |
      | MaLHP là khóa ngoại (FK) trong         | MaMon tham chiếu đến
      | scores.txt                             v
      v                                 subjects.txt
scores.txt                                  MaMon  (PK)
    MSSV + MaLHP
```

Quy ước quan trọng:

- `MSSV` là khóa chính của sinh viên.
- `MaMon` là khóa chính của môn học.
- `MaLHP` là khóa chính của lớp học phần.
- Cặp `(MSSV, MaLHP)` là khóa duy nhất trong file `scores.txt`.
- Một sinh viên được xem là tham gia một lớp học phần nếu tồn tại bản ghi tương ứng trong `scores.txt`.
- Không cần tạo thêm file `enrollments.txt` trong phiên bản hiện tại để giữ thiết kế đơn giản.

---

### 7.6. Cơ chế load và save dữ liệu

Khi chương trình khởi động:

1. Gọi hàm `loadAllData()`.
2. Đọc lần lượt các file:
   - `data/students.txt`
   - `data/subjects.txt`
   - `data/course_classes.txt`
   - `data/scores.txt`
3. Bỏ qua dòng header đầu tiên.
4. Tách từng dòng dữ liệu bằng ký tự `|`.
5. Kiểm tra số lượng trường dữ liệu.
6. Chuyển dữ liệu sang các struct tương ứng.
7. Thêm bản ghi vào mảng dữ liệu.

Khi người dùng chọn thoát chương trình:

1. Gọi hàm `saveAllData()`.
2. Ghi lại toàn bộ dữ liệu hiện tại xuống file.
3. Ghi dòng header trước.
4. Ghi từng bản ghi theo đúng định dạng đã quy định.

---

### 7.7. Xử lý lỗi khi đọc file

Module File I/O cần xử lý các trường hợp sau:

| Tình huống | Cách xử lý đề xuất |
|---|---|
| File không tồn tại | Tạo mảng rỗng, hiển thị cảnh báo, không làm chương trình crash |
| File rỗng | Tạo mảng rỗng |
| Dòng thiếu trường | Bỏ qua dòng lỗi, hiển thị cảnh báo |
| Dữ liệu số sai định dạng | Bỏ qua dòng lỗi hoặc gán giá trị mặc định nếu phù hợp |
| Điểm ngoài khoảng `0–10` | Không nạp bản ghi điểm đó |
| Trùng khóa chính | Giữ bản ghi đầu tiên, bỏ qua bản ghi trùng và hiển thị cảnh báo |
| Mã tham chiếu không tồn tại | Bỏ qua bản ghi và hiển thị cảnh báo |
| Trường bắt buộc bị bỏ trống | Bỏ qua dòng lỗi, không lưu vào mảng dữ liệu |

> **Ghi chú tách dòng dữ liệu:**  
> Có thể dùng `strtok()` để tách dòng theo ký tự `|`. Sau khi tách, cần kiểm tra đủ số trường và đảm bảo các trường bắt buộc như `MSSV`, `MaMon`, `MaLHP` không bị bỏ trống trước khi lưu vào struct.

---

### 7.8. Ghi chú triển khai

Các đường dẫn file nên được khai báo tập trung trong một file header hoặc trong `fileio.c`, ví dụ:

```c
#define STUDENT_FILE      "data/students.txt"
#define SUBJECT_FILE      "data/subjects.txt"
#define COURSE_CLASS_FILE "data/course_classes.txt"
#define SCORE_FILE        "data/scores.txt"
```

Nhóm cần thống nhất rằng chương trình sẽ được chạy từ thư mục gốc của project. Khi đó các đường dẫn dạng `data/students.txt` sẽ hoạt động ổn định.

---

## 8. Cấu trúc thư mục dự án

```text
NHOM_XX_QLSV/
├── source/
│   ├── main.c
│   ├── types.h
│   ├── arrays.h
│   ├── arrays.c
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

## 9. Lộ trình triển khai 5 tuần

### Tuần 1: Chốt thiết kế và xây dựng cấu trúc lõi

Mục tiêu:

- Chốt yêu cầu kỹ thuật.
- Tạo cấu trúc thư mục.
- Viết `types.h`.
- Bắt đầu cài đặt mảng dữ liệu (Typed Array hoặc mảng tĩnh).
- Phác thảo menu console.

Sản phẩm cuối tuần:

- `types.h`
- `arrays.h` (hoặc khai báo mảng tĩnh)
- Cấu trúc thư mục ban đầu
- Tài liệu thiết kế nội bộ

---

### Tuần 2: Hoàn thiện cấu trúc dữ liệu, File I/O và CRUD danh mục

Mục tiêu:

- Hoàn thiện `arrays.c` (hoặc mảng tĩnh).
- Viết module đọc/ghi file.
- Cài CRUD cho sinh viên, môn học và lớp học phần.
- Có menu cơ bản chạy được.

Sản phẩm cuối tuần:

- `arrays.c`
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
- Cài Linear Search và một thuật toán sắp xếp (Bubble Sort hoặc Selection Sort).
- Tích hợp validation.

Sản phẩm cuối tuần:

- `score.c`
- `gpa.c`
- `sort.c`
- `search.c`
- Menu nhập điểm hoạt động (validation tích hợp trong `ui.c`)

---

### Tuần 4: Hoàn thiện giao diện, báo cáo bảng điểm và kiểm thử tích hợp

Mục tiêu:

- Hoàn thiện toàn bộ menu.
- Cài chức năng in bảng điểm.
- Kiểm thử end-to-end.
- Chụp ảnh minh chứng các test case chính.

Sản phẩm cuối tuần:

- Chương trình chạy hoàn chỉnh
- Chức năng in bảng điểm (tích hợp trong `ui.c`)
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

## 10. Sản phẩm cần đạt của từng thành viên

Phần này mô tả chi tiết các sản phẩm mà từng thành viên cần hoàn thành trong quá trình triển khai dự án.  
Mỗi sản phẩm cần được commit lên GitHub thông qua branch riêng và Pull Request trước khi merge vào `main`.

---

### 10.1. Thành viên 1 — Core Data & File I/O

#### Vai trò chính

Thành viên 1 phụ trách phần nền tảng dữ liệu của chương trình, bao gồm:

- Định nghĩa các kiểu dữ liệu chính.
- Tự cài đặt cấu trúc dữ liệu Typed Dynamic Array (hoặc mảng tĩnh theo Lựa chọn 2).
- Xây dựng module đọc/ghi dữ liệu từ file text.
- Chuẩn bị dữ liệu mẫu ban đầu.
- Hỗ trợ các thành viên khác khi tích hợp dữ liệu.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu | Thời hạn dự kiến |
|---|---|---|---|---|
| 1 | Định nghĩa kiểu dữ liệu chính | `source/types.h` | Khai báo các struct `Student`, `Subject`, `CourseClass`, `ScoreRecord` | Tuần 1 |
| 2 | Header cho mảng dữ liệu | `source/arrays.h` | Khai báo struct và prototype các hàm thao tác mảng | Tuần 1 |
| 3 | Cài đặt mảng dữ liệu | `source/arrays.c` | Cài các hàm `sa_init`, `sa_add`, `sa_get`, `sa_remove`, `sa_update`, `sa_resize`, `sa_find`, `sa_clear` (và tương tự cho các kiểu khác) | Tuần 1–2 |
| 4 | Module đọc/ghi file | `source/fileio.h`, `source/fileio.c` | Cài các hàm load/save dữ liệu cho sinh viên, môn học, lớp học phần và điểm số | Tuần 2 |
| 5 | Hàm tách dòng dữ liệu | `fileio.c` | Dùng `strtok()` để tách dòng theo ký tự `\|`; đảm bảo các trường bắt buộc không để trống, kiểm tra đủ số trường và xử lý dòng sai định dạng | Tuần 2 |
| 6 | Dữ liệu mẫu | `data/students.txt`, `data/subjects.txt`, `data/course_classes.txt`, `data/scores.txt` | Chuẩn bị dữ liệu mẫu đủ lớn để test các chức năng chính | Tuần 2 |
| 7 | Kiểm thử File I/O | Có thể ghi trong `docs/test-note.md` hoặc ảnh trong `screenshots/` | Kiểm tra đọc file rỗng, file sai định dạng, lưu dữ liệu và mở lại chương trình | Tuần 4 |
| 8 | Review code nền tảng | Toàn bộ file do TV1 phụ trách | Xóa code thừa, kiểm tra cấp phát/giải phóng bộ nhớ, bổ sung comment cần thiết | Tuần 5 |

#### Các hàm tối thiểu cần có

```c
void sa_init(StudentArray* arr);
void sa_add(StudentArray* arr, Student elem);
Student* sa_get(StudentArray* arr, int index);
void sa_remove(StudentArray* arr, int index);
void sa_update(StudentArray* arr, int index, Student elem);
void sa_resize(StudentArray* arr);
int  sa_find(StudentArray* arr, const char* key);
void sa_clear(StudentArray* arr);
// Áp dụng tương tự: suba_* (SubjectArray), cca_* (CourseClassArray), sca_* (ScoreArray)
```

Các hàm File I/O tối thiểu:

```c
void loadStudents(StudentArray* students, const char* path);
void saveStudents(StudentArray* students, const char* path);

void loadSubjects(SubjectArray* subjects, const char* path);
void saveSubjects(SubjectArray* subjects, const char* path);

void loadCourseClasses(CourseClassArray* classes, const char* path);
void saveCourseClasses(CourseClassArray* classes, const char* path);

void loadScores(ScoreArray* scores, const char* path);
void saveScores(ScoreArray* scores, const char* path);
```

#### Tiêu chí hoàn thành

- Chương trình đọc được dữ liệu từ thư mục `data/`.
- Chương trình không bị crash khi file rỗng.
- Chương trình bỏ qua được dòng sai định dạng.
- Dữ liệu sau khi thêm/sửa/xóa có thể lưu lại vào file.
- Các hàm trong `arrays.h` có prototype rõ ràng để thành viên khác sử dụng.
- Không để rò rỉ bộ nhớ nghiêm trọng ở các thao tác cơ bản.

---

### 10.2. Thành viên 2 — Business Logic & Algorithms

#### Vai trò chính

Thành viên 2 phụ trách phần xử lý nghiệp vụ và thuật toán của chương trình, bao gồm:

- Quản lý sinh viên.
- Quản lý môn học.
- Quản lý lớp học phần.
- Quản lý điểm số.
- Tính điểm tổng kết, GPA hệ 10, GPA hệ 4.
- Cài đặt thuật toán tìm kiếm và sắp xếp.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu | Thời hạn dự kiến |
|---|---|---|---|---|
| 1 | CRUD sinh viên | `source/student.h`, `source/student.c` | Thêm, sửa, xóa, tìm sinh viên theo MSSV, họ tên, lớp | Tuần 2–3 |
| 2 | CRUD môn học | `source/subject.h`, `source/subject.c` | Thêm, sửa, xóa, tìm môn học theo mã môn hoặc tên môn | Tuần 2–3 |
| 3 | Quản lý lớp học phần | `source/courseclass.h`, `source/courseclass.c` | Tạo/xóa lớp học phần, quản lý danh sách lớp học phần | Tuần 2–3 |
| 4 | Quản lý điểm số | `source/score.h`, `source/score.c` | Nhập điểm quá trình, điểm thi, cập nhật điểm, tìm điểm theo MSSV hoặc mã lớp học phần | Tuần 3 |
| 5 | Tính điểm và GPA | `source/gpa.h`, `source/gpa.c` | Tính `diemTK`, GPA hệ 10, xếp loại học lực; GPA hệ 4 nếu còn thời gian | Tuần 3 |
| 6 | Tìm kiếm tuyến tính *(bắt buộc)* | `source/search.h`, `source/search.c` | Cài `linearSearch` dùng cho tìm kiếm dữ liệu chưa sắp xếp | Tuần 3 |
| 7 | Thuật toán sắp xếp *(bắt buộc)* | `source/sort.h`, `source/sort.c` | Cài `bubbleSort` hoặc `selectionSort` để sắp xếp theo MSSV, họ tên, điểm trung bình | Tuần 3 |
| 8 | Tìm kiếm nhị phân *(mở rộng)* | `source/search.c` | Cài `binarySearch` nếu còn thời gian; chỉ dùng sau khi mảng đã sắp xếp | Tuần 4 |
| 9 | Quick Sort *(mở rộng)* | `source/sort.c` | Cài `quickSort` nếu còn thời gian, dùng minh họa trong báo cáo | Tuần 4 |
| 10 | Hỗ trợ báo cáo kỹ thuật | `report/` hoặc `docs/` | Viết phần giải thích thuật toán, độ phức tạp và công thức tính điểm | Tuần 5 |
| 11 | Sửa lỗi logic cuối kỳ | Các file nghiệp vụ | Sửa lỗi còn sót sau kiểm thử tích hợp | Tuần 4–5 |

#### Các chức năng nghiệp vụ tối thiểu cần có

```c
int addStudent(StudentArray* students, Student newStudent);
int editStudent(StudentArray* students, const char* mssv, Student updatedStudent);
int deleteStudent(StudentArray* students, const char* mssv, ScoreArray* scores);
int findStudentByMSSV(StudentArray* students, const char* mssv);
int findStudentByName(StudentArray* students, const char* name);
```

```c
int addSubject(SubjectArray* subjects, Subject newSubject);
int editSubject(SubjectArray* subjects, const char* maMon, Subject updatedSubject);
int deleteSubject(SubjectArray* subjects, const char* maMon,
                  CourseClassArray* classes, ScoreArray* scores);
int findSubjectByCode(SubjectArray* subjects, const char* maMon);
```

```c
int   addScore(ScoreArray* scores, ScoreRecord newScore);
int   updateScore(ScoreArray* scores, const char* mssv, const char* maLHP, ScoreRecord updated);
float calcDiemTK(float diemQT, float diemThi);
float calcGPA10(ScoreArray* scores, CourseClassArray* classes,
                SubjectArray* subjects, const char* mssv);
float calcGPA4(ScoreArray* scores, CourseClassArray* classes,
               SubjectArray* subjects, const char* mssv);
float quyDoiHe4(float diemTK);
```

#### Công thức cần cài đặt đúng

```text
DiemTK = 0.4 * DiemQT + 0.6 * DiemThi
```

```text
GPA10 = Σ(DiemTK × SoTinChi) / Σ(SoTinChi)
```

```text
GPA4 = Σ(DiemHe4 × SoTinChi) / Σ(SoTinChi)
```

#### Tiêu chí hoàn thành

- Có đủ CRUD cho sinh viên, môn học và lớp học phần.
- **Không cho phép xóa** Sinh viên, Môn học hoặc Lớp học phần nếu đã tồn tại bản ghi liên quan trong `scores.txt` (xem ràng buộc toàn vẹn tham chiếu tại Mục 3.1).
- Không cho phép thêm dữ liệu bị trùng khóa chính.
- Tính đúng điểm tổng kết theo công thức.
- Tính đúng GPA hệ 10.
- Có ít nhất một thuật toán sắp xếp cơ bản (Bubble Sort hoặc Selection Sort).
- Có tìm kiếm tuyến tính.
- Các hàm nghiệp vụ có thể được gọi từ module giao diện của Thành viên 3.
- Code có comment ở những đoạn thuật toán quan trọng.

---

### 10.3. Thành viên 3 — Console UI & Documentation

#### Vai trò chính

Thành viên 3 phụ trách phần giao diện console, kiểm tra dữ liệu đầu vào, báo cáo kết quả và tài liệu dự án.

Các nhiệm vụ chính:

- Xây dựng menu chính và các submenu.
- Tích hợp giao diện với các module của Thành viên 1 và Thành viên 2.
- Kiểm tra dữ liệu đầu vào (validation tích hợp trong `ui.c`).
- In bảng điểm, bảng danh sách, báo cáo thống kê (tích hợp trong `ui.c`).
- Thiết kế test case và chụp ảnh kiểm thử.
- Viết báo cáo Word và hoàn thiện tài liệu nộp bài.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu | Thời hạn dự kiến |
|---|---|---|---|---|
| 1 | Menu chính | `source/ui.h`, `source/ui.c`, `source/main.c` | Xây dựng menu console vòng lặp cho đến khi người dùng chọn thoát | Tuần 2 |
| 2 | Submenu quản lý sinh viên | `source/ui.c` | Giao diện gọi các chức năng thêm, sửa, xóa, tìm kiếm sinh viên | Tuần 2–3 |
| 3 | Submenu quản lý môn học | `source/ui.c` | Giao diện gọi các chức năng quản lý môn học | Tuần 2–3 |
| 4 | Submenu quản lý lớp học phần | `source/ui.c` | Giao diện gọi các chức năng quản lý lớp học phần | Tuần 3 |
| 5 | Submenu quản lý điểm | `source/ui.c` | Giao diện nhập điểm, cập nhật điểm, xem điểm | Tuần 3 |
| 6 | Validation và in báo cáo | `source/ui.c` | Kiểm tra MSSV, điểm, ngày sinh, số nguyên, số thực; in bảng điểm sinh viên, bảng điểm lớp học phần, danh sách xếp hạng (gộp trong `ui.c`) | Tuần 3–4 |
| 7 | Bảng test case | `docs/test-plan.md` hoặc `report/` | Viết danh sách test case từ TC01 đến TC14 | Tuần 4 |
| 8 | Ảnh kiểm thử | `screenshots/` | Chụp ảnh kết quả chạy chương trình cho các test case chính | Tuần 4–5 |
| 9 | Báo cáo Word | `report/BaoCao_QLSV_NhomXX.docx` | Viết báo cáo cuối kỳ theo đúng thể thức | Tuần 5 |
| 10 | README cuối cùng | `README.md` | Cập nhật mô tả dự án, hướng dẫn build/chạy, phân công và tiến độ | Tuần 5 |
| 11 | Đóng gói nộp bài | File `.zip` cuối cùng | Kiểm tra đủ source, data, screenshots, report, README | Tuần 5 |

#### Các hàm giao diện và validation tối thiểu cần có

```c
void showMainMenu();
void showStudentMenu();
void showSubjectMenu();
void showCourseClassMenu();
void showScoreMenu();
void displayTable();
void displayScoreCard();
```

```c
/* Các hàm validation và đọc dữ liệu đầu vào — khai báo trong ui.h, cài trong ui.c */
int   validateMSSV(const char* mssv);
int   validateScore(float score);
int   validateDate(const char* date);
int   isStudentKeyDuplicate(StudentArray* arr, const char* key);
int   isSubjectKeyDuplicate(SubjectArray* arr, const char* key);
int   isClassKeyDuplicate(CourseClassArray* arr, const char* key);
int   readInt(const char* message);
float readFloat(const char* message);
```

#### Các báo cáo cần in được

```text
Bảng danh sách sinh viên
Bảng danh sách môn học
Bảng điểm của một sinh viên
Bảng điểm của một lớp học phần
```

#### Tiêu chí hoàn thành

- Menu dễ dùng, có hướng dẫn rõ ràng cho người nhập.
- Người dùng nhập sai thì chương trình báo lỗi và cho nhập lại.
- Không để chương trình crash khi nhập dữ liệu sai kiểu.
- Các bảng hiển thị rõ ràng trên console.
- Có đủ ảnh kiểm thử cho các chức năng chính.
- Báo cáo Word đầy đủ nội dung kỹ thuật, ảnh minh chứng và kết luận.
- README được cập nhật đúng với trạng thái cuối cùng của dự án.

---

## 11. Bảng tổng hợp sản phẩm bàn giao theo thành viên

| Thành viên | Nhóm sản phẩm chính | File/Thư mục cần có | Mức độ ưu tiên |
|---|---|---|---|
| Thành viên 1 | Core Data, Typed Arrays, File I/O, dữ liệu mẫu | `types.h`, `arrays.h/.c`, `fileio.h/.c`, `data/*.txt` | Cao |
| Thành viên 2 | CRUD, xử lý điểm, GPA, tìm kiếm tuyến tính, sắp xếp | `student.h/.c`, `subject.h/.c`, `courseclass.h/.c`, `score.h/.c`, `gpa.h/.c`, `sort.h/.c`, `search.h/.c` | Cao |
| Thành viên 3 | Console UI, validation, report, test, documentation | `main.c`, `ui.h/.c`, `screenshots/`, `report/`, `README.md` | Cao |

---

## 12. Quy trình làm việc và nghiệm thu

Một phần việc chỉ được xem là hoàn thành khi thỏa mãn đủ các điều kiện sau:

```text
[ ] Có file mã nguồn hoặc tài liệu tương ứng trong đúng thư mục.
[ ] Code biên dịch được cùng toàn bộ chương trình.
[ ] Không làm hỏng chức năng của thành viên khác.
[ ] Với chức năng quan trọng, có ảnh hoặc test case minh chứng.
```

Mỗi thành viên đặt tên branch theo nhóm việc mình phụ trách, ví dụ: `feature/student-crud`, `feature/gpa-calculation`, `feature/console-ui`, `docs/final-report`. Sau khi hoàn thành, tạo Pull Request vào `main` để thành viên khác review trước khi merge.

---

## 13. Kế hoạch kiểm thử

Một số test case tham khảo (khi làm chọn tầm 10-15 tc đủ các tính năng mà bài yêu cầu):

| Mã test | Chức năng | Dữ liệu / Tình huống kiểm thử | Kết quả mong đợi |
|---|---|---|---|
| TC01 | Thêm sinh viên hợp lệ | Nhập sinh viên mới với MSSV chưa tồn tại | Sinh viên được thêm thành công |
| TC02 | Thêm sinh viên trùng MSSV | Nhập MSSV đã tồn tại trong `students.txt` | Hiển thị lỗi, không thêm dữ liệu |
| TC03 | Thêm môn học hợp lệ | Nhập môn học mới với `MaMon` chưa tồn tại | Môn học được thêm thành công |
| TC04 | Thêm môn học trùng mã | Nhập `MaMon` đã tồn tại trong `subjects.txt` | Hiển thị lỗi, không thêm dữ liệu |
| TC05 | Thêm lớp học phần hợp lệ | Nhập `MaLHP` mới và `MaMon` đã tồn tại | Lớp học phần được thêm thành công |
| TC06 | Thêm lớp học phần với mã môn không tồn tại | Nhập `MaMon` không có trong `subjects.txt` | Hiển thị lỗi, không thêm lớp học phần |
| TC07 | Nhập điểm hợp lệ | Nhập `MSSV`, `MaLHP`, `DiemQT`, `DiemThi` hợp lệ | Bản ghi điểm được thêm thành công |
| TC08 | Nhập điểm ngoài khoảng `0–10` | Nhập `DiemQT = -1` hoặc `DiemThi = 11` | Hiển thị lỗi, không lưu điểm |
| TC09 | Nhập điểm cho sinh viên không tồn tại | Nhập `MSSV` không có trong `students.txt` | Hiển thị lỗi, không lưu điểm |
| TC10 | Nhập điểm cho lớp học phần không tồn tại | Nhập `MaLHP` không có trong `course_classes.txt` | Hiển thị lỗi, không lưu điểm |
| TC11 | Nhập điểm trùng cặp `(MSSV, MaLHP)` | Nhập điểm cho sinh viên đã có điểm trong lớp học phần đó | Hiển thị lỗi hoặc chuyển sang chức năng cập nhật điểm |
| TC12 | Cập nhật điểm | Cập nhật `DiemQT` hoặc `DiemThi` của một bản ghi đã tồn tại | Điểm được cập nhật thành công, điểm tổng kết được tính lại |
| TC13 | Tính điểm tổng kết | `DiemQT = 8.5`, `DiemThi = 7.0` | `DiemTK = 0.4 * 8.5 + 0.6 * 7.0 = 7.60` |
| TC14 | Tính GPA hệ 10 | Sinh viên có nhiều môn với điểm tổng kết và số tín chỉ khác nhau | GPA hệ 10 được tính đúng theo công thức tín chỉ |
| TC15 | Xếp loại học lực | GPA hệ 10 thuộc các khoảng Xuất sắc, Giỏi, Khá, Trung bình, Yếu | Hiển thị đúng xếp loại |
| TC16 | Tìm sinh viên tồn tại | Tìm theo MSSV hoặc họ tên có trong dữ liệu | Hiển thị đúng thông tin sinh viên |
| TC17 | Tìm sinh viên không tồn tại | Tìm MSSV không có trong dữ liệu | Hiển thị thông báo không tìm thấy |
| TC18 | Sắp xếp sinh viên theo MSSV | Danh sách sinh viên chưa được sắp xếp | Danh sách hiển thị tăng dần theo MSSV |
| TC19 | Sắp xếp sinh viên theo họ tên | Danh sách sinh viên chưa được sắp xếp theo tên | Danh sách hiển thị đúng thứ tự theo họ tên |
| TC20 | Hiển thị bảng điểm sinh viên | Nhập MSSV của sinh viên có điểm | Hiển thị đầy đủ các môn/lớp học phần, điểm và GPA |
| TC21 | Hiển thị bảng điểm lớp học phần | Nhập `MaLHP` có nhiều sinh viên đã nhập điểm | Hiển thị danh sách sinh viên và điểm trong lớp học phần |
| TC22 | Không cho xóa sinh viên đã có điểm | Xóa sinh viên có `MSSV` đang xuất hiện trong `scores.txt` | Hiển thị lỗi, không xóa sinh viên |
| TC23 | Không cho xóa lớp học phần đã có điểm | Xóa lớp học phần có `MaLHP` đang xuất hiện trong `scores.txt` | Hiển thị lỗi, không xóa lớp học phần |
| TC24 | Không cho xóa môn học đang có lớp học phần | Xóa môn học có `MaMon` đang được dùng trong `course_classes.txt` | Hiển thị lỗi, không xóa môn học |
| TC25 | Đọc file rỗng | Một trong các file dữ liệu rỗng | Chương trình không crash, tạo danh sách rỗng |
| TC26 | Đọc file sai định dạng | Một dòng thiếu trường hoặc sai kiểu dữ liệu | Bỏ qua dòng lỗi, dữ liệu hợp lệ vẫn được load |
| TC27 | Lưu dữ liệu và mở lại chương trình | Thêm/sửa dữ liệu, thoát chương trình, chạy lại | Dữ liệu vẫn còn sau khi khởi động lại |
| TC28 | Quy đổi GPA hệ 4 | Điểm tổng kết thuộc các mốc quy đổi hệ 4 | Điểm hệ 4 được quy đổi đúng |

---

## 14. Hướng dẫn build và chạy chương trình

### 14.1. Yêu cầu môi trường

Cần cài đặt:

- GCC hoặc trình biên dịch C tương đương.
- Make, nếu sử dụng Makefile.
- Git, nếu muốn clone repo từ GitHub.

### 14.2. Clone repository

```bash
git clone https://github.com/<ten-nhom>/<ten-repo>.git
cd <ten-repo>
```

### 14.3. Build chương trình

Nếu dùng Makefile:

```bash
cd source
make all
```

Nếu chưa có Makefile, có thể biên dịch thủ công (chạy từ thư mục `source/`):

```bash
gcc main.c arrays.c fileio.c student.c subject.c courseclass.c \
    score.c gpa.c sort.c search.c ui.c -o ../qlsv
```

> **Lưu ý:** Lệnh trên được chạy từ bên trong thư mục `source/`, do đó `-o ../qlsv` sẽ đặt file thực thi ra **thư mục gốc** của project — nhất quán với lệnh chạy `./qlsv` ở Mục 14.4.

### 14.4. Chạy chương trình

Trên Linux/macOS:

```bash
./qlsv
```

Trên Windows:

```bash
qlsv.exe
```

> **Lưu ý:** Chạy chương trình từ thư mục gốc của project để các đường dẫn `data/*.txt` hoạt động đúng.

---

## 15. Quy trình làm việc Git/GitHub của nhóm

Nhóm thống nhất không làm trực tiếp trên branch `main`. Quy trình gồm 3 bước:

**1. Tạo branch và code:**

```bash
git checkout main && git pull origin main
git checkout -b feature/ten-tinh-nang
# ... code, test ...
```

**2. Commit và push:**

```bash
git add .
git commit -m "Mô tả ngắn nội dung thay đổi"
git push origin feature/ten-tinh-nang
```

**3. Tạo Pull Request trên GitHub vào `main`, thành viên khác review rồi mới merge.**

---

## 16. Tài liệu liên quan

- Báo cáo cuối kỳ: `report/BaoCao_QLSV_NhomXX.docx`
- Ảnh kiểm thử: `screenshots/`
- Dữ liệu mẫu: `data/`
