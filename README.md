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

> **⚠ Ràng buộc toàn vẹn tham chiếu (bắt buộc thực thi):**  
> Tuyệt đối **không cho phép xóa** một Sinh viên, Môn học hoặc Lớp học phần nếu thực thể đó đang được tham chiếu bởi ít nhất một bản ghi trong file `scores.txt`.  
> Trước khi thực hiện xóa, chương trình **phải kiểm tra** sự tồn tại của bản ghi liên quan trong `scores.txt`. Nếu có, hiển thị thông báo lỗi và hủy thao tác xóa.
| Quản lý điểm số | Nhập và cập nhật điểm cho sinh viên theo MSSV và mã lớp học phần/mã môn |
| Tính toán kết quả học tập | Tính điểm tổng kết, điểm trung bình học kỳ hoặc tích lũy theo hệ 10; có thể quy đổi hệ 4 nếu nhóm triển khai |
| Xếp loại học lực | Xếp loại học lực dựa trên điểm trung bình |
| Tìm kiếm | Tìm kiếm sinh viên theo MSSV, họ tên hoặc lớp |
| Sắp xếp | Sắp xếp danh sách sinh viên theo MSSV, họ tên hoặc điểm trung bình |
| Báo cáo | Hiển thị bảng điểm của một sinh viên và bảng điểm của một lớp học phần |

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

**Lựa chọn 1 — Mảng động định kiểu riêng / Typed Dynamic Array (khuyến nghị):**

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

**Lựa chọn 2 — Mảng tĩnh đủ lớn (đơn giản hơn, an toàn hơn cho nhóm mới):**

Khai báo riêng một mảng tĩnh cho mỗi loại dữ liệu. Không cần `malloc`.

```c
#define MAX_STUDENTS 500

typedef struct {
    Student items[MAX_STUDENTS];
    int     size;
} StudentArray;
```

Ưu điểm: không lo quản lý bộ nhớ, truy cập trực tiếp bằng chỉ số.  
Nhược điểm: phải viết lặp cho từng kiểu dữ liệu; không linh hoạt khi dữ liệu vượt giới hạn.

> **Khuyến nghị:** Nếu nhóm chưa quen với cấp phát bộ nhớ động, hãy dùng Lựa chọn 2 trước để có chương trình chạy được sớm. Có thể nâng cấp lên Lựa chọn 1 sau nếu còn thời gian.

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
- `DynamicArray`: mảng động tự cài đặt (hoặc mảng tĩnh theo Lựa chọn 2).

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
| `data/students.txt` | `MSSV\|HoTen\|Lop\|NgaySinh\|Email` | Lưu thông tin sinh viên |
| `data/subjects.txt` | `MaMon\|TenMon\|SoTinChi` | Lưu thông tin môn học |
| `data/course_classes.txt` | `MaLHP\|MaMon\|HocKy\|NamHoc` | Lưu thông tin lớp học phần |
| `data/scores.txt` | `MSSV\|MaLHP\|DiemQT\|DiemThi\|DiemTK\|DiemHe4` | Lưu điểm của sinh viên theo từng lớp học phần |

---

### 7.3. Ví dụ dữ liệu mẫu

#### `students.txt`

```txt
MSSV|HoTen|Lop|NgaySinh|Email
22000001|Nguyen Van An|K67-MT|15/08/2003|an.nva@sv.edu.vn
22000002|Tran Thi Bich|K67-MT|20/03/2003|bich.tt@sv.edu.vn
22000003|Le Hoang Cuong|K67-MT|05/11/2002|cuong.lh@sv.edu.vn
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
| `Email` | `char[60]` | Email sinh viên |

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

> **⚠ Bắt buộc tự viết hàm `splitString` — Tuyệt đối không dùng `strtok`:**  
> Hàm `strtok()` của thư viện C **tự động bỏ qua các trường rỗng liên tiếp**, ví dụ chuỗi `22000001|KTLT_K67_1||7.0||` sẽ bị `strtok` nhảy qua các `||` mà không trả về chuỗi rỗng, làm lệch toàn bộ vị trí cột và phá vỡ cấu trúc dữ liệu.  
> Nhóm **phải tự viết hàm `splitString`** duyệt chuỗi bằng con trỏ, tách theo ký tự `|`, và **giữ nguyên các trường rỗng** dưới dạng chuỗi rỗng `""`. Ví dụ prototype:
> ```c
> /* Trả về số trường đã tách được; fields[] chứa con trỏ đến từng trường.
>    Các trường rỗng (||) được giữ lại dưới dạng chuỗi rỗng "". */
> int splitString(char* line, char delimiter, char* fields[], int maxFields);
> ```
| Dữ liệu số sai định dạng | Bỏ qua dòng lỗi hoặc gán giá trị mặc định nếu phù hợp |
| Điểm ngoài khoảng `0–10` | Không nạp bản ghi điểm đó |
| Trùng khóa chính | Giữ bản ghi đầu tiên, bỏ qua bản ghi trùng và hiển thị cảnh báo |

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

## 9. Lộ trình triển khai 5 tuần

### Tuần 1: Chốt thiết kế và xây dựng cấu trúc lõi

Mục tiêu:

- Chốt yêu cầu kỹ thuật.
- Tạo cấu trúc thư mục.
- Viết `types.h`.
- Bắt đầu cài đặt mảng dữ liệu (DynamicArray hoặc mảng tĩnh).
- Phác thảo menu console.

Sản phẩm cuối tuần:

- `types.h`
- `dynarray.h` (hoặc khai báo mảng tĩnh)
- Cấu trúc thư mục ban đầu
- Tài liệu thiết kế nội bộ

---

### Tuần 2: Hoàn thiện cấu trúc dữ liệu, File I/O và CRUD danh mục

Mục tiêu:

- Hoàn thiện `dynarray.c` (hoặc mảng tĩnh).
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
- Cài GPA hệ 10 và xếp loại (GPA hệ 4 nếu còn thời gian).
- Cài Linear Search và một thuật toán sắp xếp (Bubble Sort hoặc Selection Sort).
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

## 10. Sản phẩm cần đạt của từng thành viên

Phần này mô tả chi tiết các sản phẩm mà từng thành viên cần hoàn thành trong quá trình triển khai dự án.  
Mỗi sản phẩm cần được commit lên GitHub thông qua branch riêng và Pull Request trước khi merge vào `main`.

---

### 10.1. Thành viên 1 — Core Data & File I/O

#### Vai trò chính

Thành viên 1 phụ trách phần nền tảng dữ liệu của chương trình, bao gồm:

- Định nghĩa các kiểu dữ liệu chính.
- Tự cài đặt cấu trúc dữ liệu `DynamicArray` (hoặc mảng tĩnh theo Lựa chọn 2).
- Xây dựng module đọc/ghi dữ liệu từ file text.
- Chuẩn bị dữ liệu mẫu ban đầu.
- Hỗ trợ các thành viên khác khi tích hợp dữ liệu.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu | Thời hạn dự kiến |
|---|---|---|---|---|
| 1 | Định nghĩa kiểu dữ liệu chính | `source/types.h` | Khai báo các struct `Student`, `Subject`, `CourseClass`, `ScoreRecord` | Tuần 1 |
| 2 | Header cho mảng dữ liệu | `source/dynarray.h` | Khai báo struct và prototype các hàm thao tác mảng | Tuần 1 |
| 3 | Cài đặt mảng dữ liệu | `source/dynarray.c` | Cài các hàm `da_init`, `da_add`, `da_get`, `da_remove`, `da_update`, `da_resize`, `da_find`, `da_clear` | Tuần 1–2 |
| 4 | Module đọc/ghi file | `source/fileio.h`, `source/fileio.c` | Cài các hàm load/save dữ liệu cho sinh viên, môn học, lớp học phần và điểm số | Tuần 2 |
| 5 | Hàm tách dòng dữ liệu | `splitString` trong `fileio.c` | Tự viết hàm tách chuỗi bằng con trỏ theo ký tự `\|`, **tuyệt đối không dùng `strtok`** (xem lý do tại Mục 7.7). Hàm phải giữ nguyên trường rỗng (`\|\|`), kiểm tra đủ số trường và xử lý dòng sai định dạng | Tuần 2 |
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
- Các hàm trong `dynarray.h` có prototype rõ ràng để thành viên khác sử dụng.
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
int deleteSubject(SubjectArray* subjects, const char* maMon, ScoreArray* scores);
int findSubjectByCode(SubjectArray* subjects, const char* maMon);
```

```c
int   addScore(ScoreArray* scores, ScoreRecord newScore);
int   updateScore(ScoreArray* scores, const char* mssv, const char* maLHP, ScoreRecord updated);
float calcDiemTK(float diemQT, float diemThi);
float calcGPA10(ScoreArray* scores, SubjectArray* subjects, const char* mssv);
float calcGPA4(ScoreArray* scores, SubjectArray* subjects, const char* mssv);
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

### 10.3. Thành viên 3 — Console UI, Validation & Documentation

#### Vai trò chính

Thành viên 3 phụ trách phần giao diện console, kiểm tra dữ liệu đầu vào, báo cáo kết quả và tài liệu dự án.

Các nhiệm vụ chính:

- Xây dựng menu chính và các submenu.
- Tích hợp giao diện với các module của Thành viên 1 và Thành viên 2.
- Kiểm tra dữ liệu đầu vào.
- In bảng điểm, bảng danh sách, báo cáo thống kê.
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
| 6 | Module validation | `source/validation.h`, `source/validation.c` | Kiểm tra MSSV, điểm, ngày sinh, số nguyên, số thực, dữ liệu rỗng | Tuần 3 |
| 7 | Module báo cáo | `source/report.h`, `source/report.c` | In bảng điểm sinh viên, bảng điểm lớp học phần, danh sách xếp hạng | Tuần 4 |
| 8 | Bảng test case | `docs/test-plan.md` hoặc `report/` | Viết danh sách test case từ TC01 đến TC14 | Tuần 4 |
| 9 | Ảnh kiểm thử | `screenshots/` | Chụp ảnh kết quả chạy chương trình cho các test case chính | Tuần 4–5 |
| 10 | Báo cáo Word | `report/BaoCao_QLSV_NhomXX.docx` | Viết báo cáo cuối kỳ theo đúng thể thức | Tuần 5 |
| 11 | README cuối cùng | `README.md` | Cập nhật mô tả dự án, hướng dẫn build/chạy, phân công và tiến độ | Tuần 5 |
| 12 | Đóng gói nộp bài | File `.zip` cuối cùng | Kiểm tra đủ source, data, screenshots, report, README | Tuần 5 |

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
| Thành viên 1 | Core Data, DynamicArray, File I/O, dữ liệu mẫu | `types.h`, `dynarray.h/.c`, `fileio.h/.c`, `data/*.txt` | Cao |
| Thành viên 2 | CRUD, xử lý điểm, GPA, tìm kiếm tuyến tính, sắp xếp | `student.h/.c`, `subject.h/.c`, `courseclass.h/.c`, `score.h/.c`, `gpa.h/.c`, `sort.h/.c`, `search.h/.c` | Cao |
| Thành viên 3 | Console UI, validation, report, test, documentation | `main.c`, `ui.h/.c`, `validation.h/.c`, `report.h/.c`, `screenshots/`, `report/`, `README.md` | Cao |

---

## 12. Quy định nghiệm thu sản phẩm của từng thành viên

Một phần việc chỉ được xem là hoàn thành khi thỏa mãn đủ các điều kiện sau:

```text
[ ] Có file mã nguồn hoặc tài liệu tương ứng trong đúng thư mục.
[ ] Code biên dịch được cùng toàn bộ chương trình.
[ ] Không làm hỏng chức năng của thành viên khác.
[ ] Có commit rõ ràng trên GitHub.
[ ] Có Pull Request được review trước khi merge vào main.
[ ] Có mô tả ngắn trong Pull Request về nội dung đã làm.
[ ] Với chức năng quan trọng, có ảnh hoặc test case minh chứng.
```

---

## 13. Quy tắc đặt tên branch theo từng thành viên

Để dễ quản lý, mỗi thành viên nên đặt branch theo nhóm việc mình phụ trách.

### Thành viên 1

```text
feature/types-definition
feature/dynamic-array
feature/file-io
feature/sample-data
```

### Thành viên 2

```text
feature/student-crud
feature/subject-crud
feature/courseclass-management
feature/score-management
feature/gpa-calculation
feature/search-sort
```

### Thành viên 3

```text
feature/console-ui
feature/input-validation
feature/report-output
docs/test-plan
docs/final-report
docs/update-readme
```

---

## 14. Gợi ý Issue tương ứng với từng sản phẩm

Nhóm nên tạo các Issue trên GitHub tương ứng với từng sản phẩm cần bàn giao.

| Issue | Người phụ trách | Nội dung |
|---|---|---|
| `#1` | TV1 | Tạo `types.h` và định nghĩa các struct chính |
| `#2` | TV1 | Cài đặt `DynamicArray` |
| `#3` | TV1 | Cài đặt module File I/O |
| `#4` | TV1 | Chuẩn bị dữ liệu mẫu trong thư mục `data/` |
| `#5` | TV2 | Cài CRUD sinh viên |
| `#6` | TV2 | Cài CRUD môn học |
| `#7` | TV2 | Cài quản lý lớp học phần |
| `#8` | TV2 | Cài quản lý điểm số |
| `#9` | TV2 | Cài tính GPA và xếp loại |
| `#10` | TV2 | Cài Linear Search và Bubble/Selection Sort |
| `#11` | TV3 | Xây dựng menu console |
| `#12` | TV3 | Cài validation dữ liệu đầu vào |
| `#13` | TV3 | Cài chức năng in bảng điểm và báo cáo |
| `#14` | TV3 | Viết test plan và chụp ảnh kiểm thử |
| `#15` | TV3 | Hoàn thiện báo cáo Word và README |

> **Nếu còn thời gian (không bắt buộc):**
> - `#16` TV2: Cài Binary Search
> - `#17` TV2: Cài Quick Sort

---

## 15. Kế hoạch kiểm thử

Một số test case chính:

| Mã test | Chức năng | Kết quả mong đợi |
|---|---|---|
| TC01 | Thêm sinh viên hợp lệ | Sinh viên được thêm thành công |
| TC02 | Thêm sinh viên trùng MSSV | Hiển thị lỗi, không thêm dữ liệu |
| TC03 | Nhập điểm ngoài khoảng 0–10 | Hiển thị lỗi |
| TC04 | Tìm sinh viên tồn tại | Hiển thị đúng thông tin sinh viên |
| TC05 | Tìm sinh viên không tồn tại | Hiển thị thông báo không tìm thấy |
| TC06 | Sắp xếp sinh viên theo MSSV | Danh sách tăng dần theo MSSV |
| TC07 | Sắp xếp theo GPA giảm dần | Sinh viên GPA cao nhất lên đầu |
| TC08 | Tính GPA hệ 10 | Kết quả tính đúng theo tín chỉ |
| TC09 | Quy đổi GPA hệ 4 | Đúng theo bảng quy đổi |
| TC10 | Hiển thị bảng điểm sinh viên | Bảng điểm đầy đủ, đúng định dạng |
| TC11 | Hiển thị bảng điểm lớp học phần | Đủ danh sách sinh viên, điểm và xếp loại |
| TC12 | Đọc file rỗng | Chương trình không bị crash |
| TC13 | Đọc file sai định dạng | Bỏ qua dòng lỗi, dữ liệu hợp lệ vẫn load |
| TC14 | Lưu dữ liệu và mở lại | Dữ liệu vẫn còn sau khi khởi động lại |

---

## 16. Hướng dẫn build và chạy chương trình

### 16.1. Yêu cầu môi trường

Cần cài đặt:

- GCC hoặc trình biên dịch C tương đương.
- Make, nếu sử dụng Makefile.
- Git, nếu muốn clone repo từ GitHub.

### 16.2. Clone repository

```bash
git clone https://github.com/<ten-nhom>/<ten-repo>.git
cd <ten-repo>
```

### 16.3. Build chương trình

Nếu dùng Makefile:

```bash
cd source
make all
```

Nếu chưa có Makefile, có thể biên dịch thủ công (chạy từ thư mục `source/`):

```bash
gcc main.c dynarray.c fileio.c student.c subject.c courseclass.c \
    score.c gpa.c sort.c search.c ui.c validation.c report.c -o ../qlsv
```

> **Lưu ý:** Lệnh trên được chạy từ bên trong thư mục `source/`, do đó `-o ../qlsv` sẽ đặt file thực thi ra **thư mục gốc** của project — nhất quán với lệnh chạy `./qlsv` ở Mục 16.4.

### 16.4. Chạy chương trình

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

## 17. Quy trình làm việc Git/GitHub của nhóm

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

## 18. Tài liệu liên quan

- Báo cáo cuối kỳ: `report/BaoCao_QLSV_NhomXX.docx`
- Ảnh kiểm thử: `screenshots/`
- Dữ liệu mẫu: `data/`
