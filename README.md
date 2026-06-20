# Quản lý sinh viên và điểm số | Student Management System

## 1. Giới thiệu dự án

Dự án **Quản lý sinh viên và điểm số (Student Management System)** là chương trình quản lý sinh viên và điểm số chạy trên giao diện console.

Dự án được thực hiện bởi nhóm 3 sinh viên ngành Toán Tin, ĐHBKHN (HUST) trong khuôn khổ môn học Kỹ thuật lập trình.
Cụ thể về nhân sự: 
 - Nguyễn Khánh Toàn đảm nhận công việc của Thành viên 1 + lập ra bản kế hoạch trong file README này + theo dõi tiến độ của 2 thành viên còn lại
 - Ngô Ngọc Thái đảm nhận công việc của Thành viên 2
 - Nguyễn Vũ Quang Anh đảm nhận công việc của Thành viên 3

Chương trình tập trung vào việc tự cài đặt cấu trúc dữ liệu, thuật toán tìm kiếm, thuật toán sắp xếp và xử lý dữ liệu lưu trữ bằng file text.

---

## 2. Mục tiêu dự án

Xây dựng một chương trình console hoàn chỉnh bằng ngôn ngữ C, cho phép quản lý sinh viên, môn học, lớp học phần và điểm số.

Các mục tiêu chính:

- Quản lý thông tin sinh viên.
- Quản lý môn học.
- Quản lý lớp học phần.
- Quản lý điểm quá trình, điểm cuối kỳ và điểm tổng kết.
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
| Quản lý môn học | Thêm, sửa, xóa, tìm kiếm môn học theo mã học phần hoặc tên môn |
| Quản lý lớp học phần | Tạo, sửa, xóa, tìm kiếm lớp học phần; mỗi lớp học phần gắn với một môn học |
| Quản lý điểm số | Nhập và cập nhật điểm cho sinh viên theo MSSV và mã lớp học phần/mã học phần |
| Tính toán kết quả học tập | Tính điểm tổng kết, GPA hệ 10, GPA hệ 4 và xếp loại học lực |
| Xếp loại học lực | Xếp loại học lực dựa trên điểm trung bình |
| Tìm kiếm | Tìm kiếm sinh viên theo MSSV, họ tên hoặc lớp |
| Sắp xếp | Sắp xếp danh sách sinh viên theo MSSV, họ tên hoặc điểm trung bình |
| Báo cáo | Hiển thị bảng điểm của một sinh viên và bảng điểm của một lớp học phần |

> **⚠ Ràng buộc toàn vẹn tham chiếu bắt buộc thực thi:**  
> Chương trình phải kiểm tra dữ liệu liên quan trước khi xóa Sinh viên, Môn học hoặc Lớp học phần.
>
> - Không cho phép xóa **Sinh viên** nếu còn bản ghi điểm có `MSSV` tương ứng trong `scores.txt`.
> - Không cho phép xóa **Lớp học phần** nếu còn bản ghi điểm có `MaLHP` tương ứng trong `scores.txt`.
> - Không cho phép xóa **Môn học** nếu còn lớp học phần nào trong `course_classes.txt` sử dụng `MaHP` tương ứng.
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
- Mã sinh viên, mã học phần và mã lớp học phần là khóa chính, không được trùng lặp.

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
> Cách dùng `void*` và `elemSize` (con trỏ dạng `(char*)arr->data + i * arr->elemSize`) yêu cầu ép kiểu thủ công mỗi khi truy cập phần tử. Với nhóm chưa thành thạo con trỏ, đây là nguồn gốc thường gặp của lỗi nhầm kiểu, truy cập sai vùng nhớ và memory leak khó phát hiện.

---

Các thao tác cần cài đặt (áp dụng cho Typed Dynamic Array):

| Hàm (ví dụ cho `StudentArray`) | Mô tả |
|---|---|
| `sa_init` | Khởi tạo mảng động sinh viên với `init_cap`; nếu `init_cap <= 0` dùng mặc định 4 |
| `sa_add` | Thêm phần tử `Student`, trả về `1` nếu thành công, `0` nếu lỗi cấp phát |
| `sa_get` | Lấy con trỏ phần tử theo chỉ số |
| `sa_remove` | Xóa phần tử theo chỉ số, trả về `1` nếu thành công, `0` nếu index sai |
| `sa_update` | Cập nhật phần tử theo chỉ số, trả về `1` nếu thành công, `0` nếu index sai |
| `sa_resize` | Mở rộng dung lượng mảng; hiện cài `static` trong `arrays.c`, không gọi trực tiếp từ module khác |
| `sa_find` | Tìm kiếm theo khóa chính `mssv`; các mảng khác tìm theo khóa tương ứng |
| `sa_clear` | Giải phóng bộ nhớ |

Áp dụng tương tự với các prefix `suba_` (`SubjectArray`), `cca_` (`CourseClassArray`), `sca_` (`ScoreArray`).

### 6.2. Các struct chính

> Ghi chú cập nhật theo mã nguồn hiện tại: `Subject` dùng trường `maHP` thay cho `maMon`; `CourseClass` tham chiếu học phần bằng `maHP`; `Student` dùng trường `birthday`; `ScoreRecord` dùng `diemCK` cho điểm cuối kỳ. README cần giữ thống nhất với các tên này để tránh lỗi khi các thành viên khác gọi hàm hoặc đọc/ghi file.

Các thực thể chính trong chương trình:

- `Student`: thông tin sinh viên.
- `Subject`: thông tin môn học.
- `CourseClass`: thông tin lớp học phần.
- `ScoreRecord`: thông tin điểm số.
- `StudentArray`, `SubjectArray`, `CourseClassArray`, `ScoreArray`: các mảng tự cài đặt (Typed Dynamic Array).

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
| `data/students.txt` | `MSSV\|HoTen\|Lop\|Birthday` | Lưu thông tin sinh viên |
| `data/subjects.txt` | `MaHP\|TenHP\|SoTinChi` | Lưu thông tin môn học |
| `data/course_classes.txt` | `MaLHP\|MaHP\|HocKy\|NamHoc` | Lưu thông tin lớp học phần |
| `data/scores.txt` | `MSSV\|MaLHP\|DiemQT\|DiemCK\|DiemTK\|DiemHe4` | Lưu điểm của sinh viên theo từng lớp học phần |

---

### 7.3. Ví dụ dữ liệu mẫu

#### `students.txt`

```txt
MSSV|HoTen|Lop|Birthday
202400000|Nguyen Van Toan|K69-MI1-01|15/08/2006
202400001|Tran Quan Anh|K69-MI1-02|20/03/2006
202400002|Le Hoang Thai|K69-MI1-03|05/11/2005
```

#### `subjects.txt`

```txt
MaHP|TenHP|SoTinChi
MI3310|Ky Thuat Lap Trinh|2
MI3060|Cau Truc Du Lieu & Thuat Toan|3
MI3090|Co So Du Lieu|3
```

#### `course_classes.txt`

```txt
MaLHP|MaHP|HocKy|NamHoc
169313|MI3310|1|2025
169307|MI3060|2|2025
169320|MI3090|3|2025
```

#### `scores.txt`

```txt
MSSV|MaLHP|DiemQT|DiemCK|DiemTK|DiemHe4
202400000|169313|8.50|7.00|7.75|3.00
202400000|169307|8.00|9.00|8.50|4.00
202400000|169320|6.50|7.00|6.75|2.50
```

---

### 7.4. Ý nghĩa các trường dữ liệu

#### Sinh viên — `Student`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MSSV` | `char[12]` | Mã số sinh viên, khóa chính, không được trùng |
| `HoTen` | `char[60]` | Họ và tên sinh viên |
| `Lop` | `char[20]` | Lớp hành chính của sinh viên |
| `Birthday` | `char[12]` | Ngày sinh, định dạng `DD/MM/YYYY`; trong struct hiện tại đặt tên trường là `birthday` |

#### Môn học — `Subject`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MaHP` | `char[10]` | Mã học phần, khóa chính, không được trùng |
| `TenHP` | `char[80]` | Tên môn học |
| `SoTinChi` | `int` | Số tín chỉ của môn học |

#### Lớp học phần — `CourseClass`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MaLHP` | `char[15]` | Mã lớp học phần, khóa chính, không được trùng |
| `MaHP` | `char[10]` | Mã học phần tương ứng, tham chiếu đến `subjects.txt` |
| `HocKy` | `int` | Học kỳ, ví dụ `1`, `2`, `3` |
| `NamHoc` | `int` | Năm học |

#### Điểm số — `ScoreRecord`

| Trường | Kiểu dữ liệu dự kiến | Ý nghĩa |
|---|---|---|
| `MSSV` | `char[12]` | Mã sinh viên, tham chiếu đến `students.txt` |
| `MaLHP` | `char[15]` | Mã lớp học phần, tham chiếu đến `course_classes.txt` |
| `DiemQT` | `float` | Điểm quá trình, từ `0.0` đến `10.0` |
| `DiemCK` | `float` | Điểm cuối kỳ, từ `0.0` đến `10.0` |
| `DiemTK` | `float` | Điểm tổng kết, tính theo công thức `0.5 * DiemQT + 0.5 * DiemCK` |
| `DiemHe4` | `float` | Điểm quy đổi sang hệ 4 |

> **Ghi chú thiết kế — Phi chuẩn hóa có chủ đích (Denormalization):**  
> Việc lưu sẵn `DiemTK` và `DiemHe4` trực tiếp vào file `scores.txt` là **thiết kế phi chuẩn hóa có chủ đích**. Về lý thuyết, hai trường này có thể tính lại bất cứ lúc nào từ `DiemQT` và `DiemCK`. Tuy nhiên, lưu sẵn giúp giảm thiểu việc tính toán lại mỗi lần load file và đơn giản hóa phần đọc/ghi dữ liệu trong phạm vi dự án này. Khi cập nhật `DiemQT` hoặc `DiemCK`, chương trình **phải tính lại và cập nhật đồng thời** `DiemTK` và `DiemHe4`.

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
    MaHP  (FK) ──────────────────────────────┐
      |                                        |
      | MaLHP là khóa ngoại (FK) trong         | MaHP tham chiếu đến
      | scores.txt                             v
      v                                 subjects.txt
scores.txt                                  MaHP  (PK)
    MSSV + MaLHP
```

Quy ước quan trọng:

- `MSSV` là khóa chính của sinh viên.
- `MaHP` là khóa chính của môn học.
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
> Có thể dùng `strtok()` để tách dòng theo ký tự `|`. Sau khi tách, cần kiểm tra đủ số trường và đảm bảo các trường bắt buộc như `MSSV`, `MaHP`, `MaLHP` không bị bỏ trống trước khi lưu vào struct.

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
QLSV_MI3310/
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
│   ├── test_types.c
│   ├── test_arrays.c
│   ├── test_fileio_unit.c
│   ├── test_gpa.c
│   ├── test_fileio.c
│   └── Makefile
│
├── data/
│   ├── students.txt
│   ├── subjects.txt
│   ├── course_classes.txt
│   └── scores.txt
│
├── docs/
│   └── test_note.md
│
├── screenshots/
│   ├── TCxx_mo_ta_ngan_01.png
│   ├── TCxx_mo_ta_ngan_02.png
│   └── ...
│
├── README.md
└── .gitignore
```

> `screenshots/` dùng để lưu ảnh minh chứng kiểm thử. Nhóm chọn khoảng **10–15 test case tiêu biểu** trong Mục 12 để chụp ảnh, không bắt buộc phải chụp đủ toàn bộ TC01–TC28.
>
> Nếu Git không nhận thư mục `screenshots/` khi chưa có ảnh, có thể tạo tạm file `screenshots/.gitkeep`, sau đó thay bằng ảnh kiểm thử khi hoàn thiện.

## 9. Sản phẩm cần đạt của từng thành viên

Phần này mô tả chi tiết các sản phẩm mà từng thành viên cần hoàn thành trong quá trình triển khai dự án.  

---

### 9.1. Thành viên 1 — Core Data & File I/O

#### Vai trò chính

Thành viên 1 phụ trách phần nền tảng dữ liệu của chương trình, bao gồm:

- Định nghĩa các kiểu dữ liệu chính.
- Tự cài đặt cấu trúc dữ liệu Typed Dynamic Array (hoặc mảng tĩnh theo Lựa chọn 2).
- Xây dựng module đọc/ghi dữ liệu từ file text.
- Chuẩn bị dữ liệu mẫu ban đầu.
- Hỗ trợ các thành viên khác khi tích hợp dữ liệu.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu |
|---|---|---|---|
| 1 | Định nghĩa kiểu dữ liệu chính | `source/types.h` | Khai báo các struct `Student`, `Subject`, `CourseClass`, `ScoreRecord` |
| 2 | Header cho mảng dữ liệu | `source/arrays.h` | Khai báo struct và prototype các hàm thao tác mảng |
| 3 | Cài đặt mảng dữ liệu | `source/arrays.c` | Cài các hàm `sa_init`, `sa_add`, `sa_get`, `sa_remove`, `sa_update`, `sa_resize`, `sa_find`, `sa_clear` (và tương tự cho các kiểu khác) |
| 4 | Module đọc/ghi file | `source/fileio.h`, `source/fileio.c` | Cài các hàm load/save dữ liệu cho sinh viên, môn học, lớp học phần và điểm số |
| 5 | Hàm tách dòng dữ liệu | `fileio.c` | Dùng `strtok()` để tách dòng theo ký tự `\|`; đảm bảo các trường bắt buộc không để trống, kiểm tra đủ số trường và xử lý dòng sai định dạng |
| 6 | Dữ liệu mẫu | `data/students.txt`, `data/subjects.txt`, `data/course_classes.txt`, `data/scores.txt` | Chuẩn bị dữ liệu mẫu đủ lớn để test các chức năng chính |
| 7 | Kiểm thử File I/O | Có thể ghi trong `docs/test_note.md` hoặc ảnh trong `screenshots/` | Kiểm tra đọc file rỗng, file sai định dạng, lưu dữ liệu và mở lại chương trình |
| 8 | Review code nền tảng | Toàn bộ file do TV1 phụ trách | Xóa code thừa, kiểm tra cấp phát/giải phóng bộ nhớ, bổ sung comment cần thiết |

#### Các hàm tối thiểu cần có

```c
int      sa_init(StudentArray* arr, int init_cap);
int      sa_add(StudentArray* arr, Student s);
Student* sa_get(StudentArray* arr, int index);
int      sa_remove(StudentArray* arr, int index);
int      sa_update(StudentArray* arr, int index, Student s);
int      sa_find(StudentArray* arr, const char* mssv);
void     sa_clear(StudentArray* arr);

// Áp dụng tương tự:
// suba_* cho SubjectArray, tìm theo maHP
// cca_*  cho CourseClassArray, tìm theo maLHP
// sca_*  cho ScoreArray, tìm theo khóa kép (mssv, maLHP)
```

> Ghi chú: các hàm `*_resize` đang được cài là `static` trong `arrays.c`, chỉ dùng nội bộ module nên không khai báo trong `arrays.h`. Các hàm `init`, `add`, `remove`, `update` trả về `1` nếu thành công và `0` nếu lỗi.

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

### 9.2. Thành viên 2 — Business Logic & Algorithms

#### Vai trò chính

Thành viên 2 phụ trách phần xử lý nghiệp vụ và thuật toán của chương trình, bao gồm:

- Quản lý sinh viên.
- Quản lý môn học.
- Quản lý lớp học phần.
- Quản lý điểm số.
- Tính điểm tổng kết, GPA hệ 10, GPA hệ 4.
- Cài đặt thuật toán tìm kiếm và sắp xếp.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu |
|---|---|---|---|
| 1 | CRUD sinh viên | `source/student.h`, `source/student.c` | Thêm, sửa, xóa, tìm sinh viên theo MSSV, họ tên, lớp |
| 2 | CRUD môn học | `source/subject.h`, `source/subject.c` | Thêm, sửa, xóa, tìm môn học theo mã học phần hoặc tên môn |
| 3 | Quản lý lớp học phần | `source/courseclass.h`, `source/courseclass.c` | Tạo/xóa lớp học phần, quản lý danh sách lớp học phần |
| 4 | Quản lý điểm số | `source/score.h`, `source/score.c` | Nhập điểm quá trình, điểm cuối kỳ, cập nhật điểm, tìm điểm theo MSSV hoặc mã lớp học phần |
| 5 | Tính điểm và GPA | `source/gpa.h`, `source/gpa.c` | Tính `diemTK`, GPA hệ 10, xếp loại học lực; GPA hệ 4 nếu còn thời gian |
| 6 | Tìm kiếm tuyến tính *(bắt buộc)* | `source/search.h`, `source/search.c` | Cài `linearSearch` dùng cho tìm kiếm dữ liệu chưa sắp xếp |
| 7 | Thuật toán sắp xếp *(bắt buộc)* | `source/sort.h`, `source/sort.c` | Cài `bubbleSort` hoặc `selectionSort` để sắp xếp theo MSSV, họ tên, điểm trung bình |
| 8 | Tìm kiếm nhị phân *(mở rộng)* | `source/search.c` | Cài `binarySearch` nếu còn thời gian; chỉ dùng sau khi mảng đã sắp xếp |
| 9 | Quick Sort *(mở rộng)* | `source/sort.c` | Cài `quickSort` nếu còn thời gian, dùng minh họa trong báo cáo |
| 10 | Hỗ trợ báo cáo kỹ thuật | `report/` hoặc `docs/` | Viết phần giải thích thuật toán, độ phức tạp và công thức tính điểm |
| 11 | Sửa lỗi logic cuối kỳ | Các file nghiệp vụ | Sửa lỗi còn sót sau kiểm thử tích hợp |

#### Các module/hàm nghiệp vụ chính hiện có

README không liệt kê prototype giả định nữa, mà mô tả theo đúng các module đang có trong mã nguồn:

| Module | Chức năng chính |
|---|---|
| `student.h/.c` | Thêm, sửa, xóa, tìm sinh viên theo MSSV |
| `subject.h/.c` | Thêm, sửa, xóa, tìm học phần theo mã học phần |
| `courseclass.h/.c` | Thêm, sửa, xóa, tìm lớp học phần theo mã lớp học phần |
| `score.h/.c` | Nhập điểm, cập nhật điểm, tính điểm tổng kết và quy đổi điểm hệ 4 |
| `gpa.h/.c` | Tính GPA hệ 10, GPA hệ 4 theo trọng số tín chỉ và xếp loại học lực |
| `search.h/.c` | Tìm kiếm tuyến tính theo MSSV, họ tên, lớp, mã học phần, tên học phần, mã lớp học phần |
| `sort.h/.c` | Sắp xếp sinh viên theo MSSV, họ tên và GPA |

Các tên hàm cụ thể được khai báo trong từng file `.h` tương ứng. Cách viết này tránh tình trạng README liệt kê prototype không khớp với mã nguồn thực tế.

#### Công thức cần cài đặt đúng

```text
DiemTK = 0.5 * DiemQT + 0.5 * DiemCK
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

### 9.3. Thành viên 3 — Console UI & Documentation

#### Vai trò chính

Thành viên 3 phụ trách phần giao diện console, kiểm tra dữ liệu đầu vào, báo cáo kết quả và tài liệu dự án.

Các nhiệm vụ chính:

- Xây dựng menu chính và các submenu.
- Tích hợp giao diện với các module của Thành viên 1 và Thành viên 2.
- Kiểm tra dữ liệu đầu vào (validation tích hợp trong `ui.c`).
- In bảng điểm, bảng danh sách, báo cáo thống kê (tích hợp trong `ui.c`).
- Thiết kế test case và chụp ảnh kiểm thử cho khoảng 10–15 test case tiêu biểu.
- Viết báo cáo Word và hoàn thiện tài liệu nộp bài.

#### Sản phẩm cần hoàn thành

| STT | Sản phẩm | File/Thư mục liên quan | Mô tả yêu cầu |
|---|---|---|---|
| 1 | Menu chính | `source/ui.h`, `source/ui.c`, `source/main.c` | Xây dựng menu console vòng lặp cho đến khi người dùng chọn thoát |
| 2 | Submenu quản lý sinh viên | `source/ui.c` | Giao diện gọi các chức năng thêm, sửa, xóa, tìm kiếm sinh viên |
| 3 | Submenu quản lý môn học | `source/ui.c` | Giao diện gọi các chức năng quản lý môn học |
| 4 | Submenu quản lý lớp học phần | `source/ui.c` | Giao diện gọi các chức năng quản lý lớp học phần |
| 5 | Submenu quản lý điểm | `source/ui.c` | Giao diện nhập điểm, cập nhật điểm, xem điểm |
| 6 | Validation và in báo cáo | `source/ui.c` | Kiểm tra MSSV, điểm, ngày sinh, số nguyên, số thực; in bảng điểm sinh viên, bảng điểm lớp học phần, danh sách xếp hạng (gộp trong `ui.c`) |
| 7 | Bảng test case | `docs/test_note.md` hoặc `README.md` | Viết danh sách test case từ TC01 đến TC28 |
| 8 | Ảnh kiểm thử | `screenshots/` | Chụp ảnh kết quả chạy chương trình cho khoảng 10–15 test case tiêu biểu trong Mục 12 |
| 9 | Báo cáo Word | `report/BaoCao_QLSV_NhomXX.pdf` | Viết báo cáo cuối kỳ|
| 10 | README cuối cùng | `README.md` | Cập nhật mô tả dự án, hướng dẫn build/chạy, phân công và tiến độ |
| 11 | Đóng gói nộp bài | File `.zip` cuối cùng | Kiểm tra đủ source, data, screenshots, report, README |

#### Các chức năng giao diện và validation cần có

Các hàm giao diện chi tiết được cài đặt chủ yếu trong `ui.c`; `ui.h` chỉ cần public những hàm cần gọi từ module khác, đặc biệt là hàm menu chính.

Các chức năng giao diện cần có:

- Menu chính.
- Submenu quản lý sinh viên.
- Submenu quản lý học phần.
- Submenu quản lý lớp học phần.
- Submenu quản lý điểm.
- Menu báo cáo/bảng điểm.
- Đọc và kiểm tra dữ liệu đầu vào: chuỗi rỗng, ký tự phân cách `|`, số nguyên, số thực, điểm trong khoảng `0–10`, ngày sinh, học kỳ, năm học và số tín chỉ.
- Chặn thao tác xóa dữ liệu đang được tham chiếu theo các ràng buộc đã nêu ở Mục 3.1.

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
- Có khoảng 10–15 ảnh kiểm thử cho các chức năng chính, lưu trong `screenshots/`.
- Báo cáo Word đầy đủ nội dung kỹ thuật, ảnh minh chứng và kết luận.
- README được cập nhật đúng với trạng thái cuối cùng của dự án.

---

## 10. Bảng tổng hợp sản phẩm bàn giao theo thành viên

| Thành viên | Nhóm sản phẩm chính | File/Thư mục cần có | Mức độ ưu tiên |
|---|---|---|---|
| Thành viên 1 | Core Data, Typed Arrays, File I/O, dữ liệu mẫu, kiểm thử nền tảng | `types.h`, `arrays.h/.c`, `fileio.h/.c`, `data/*.txt`, `source/test_types.c`, `source/test_arrays.c`, `source/test_fileio_unit.c`, `source/test_gpa.c`, `source/test_fileio.c`, `docs/test_note.md` | Cao |
| Thành viên 2 | CRUD, xử lý điểm, GPA, tìm kiếm tuyến tính, sắp xếp | `student.h/.c`, `subject.h/.c`, `courseclass.h/.c`, `score.h/.c`, `gpa.h/.c`, `sort.h/.c`, `search.h/.c` | Cao |
| Thành viên 3 | Console UI, validation, test, documentation | `main.c`, `ui.h/.c`, `README.md`, `docs/test_note.md`, `screenshots/`; `report/` nếu nộp kèm | Cao |

---

## 11. Quy trình làm việc và nghiệm thu

Một phần việc chỉ được xem là hoàn thành khi thỏa mãn đủ các điều kiện sau:

```text
[ ] Có file mã nguồn hoặc tài liệu tương ứng trong đúng thư mục.
[ ] Code biên dịch được cùng toàn bộ chương trình.
[ ] Không làm hỏng chức năng của thành viên khác.
[ ] Với chức năng quan trọng, có ảnh hoặc test case minh chứng.
```

---

## 12. Kế hoạch kiểm thử

Bảng dưới đây liệt kê 15 test case tiêu biểu được chọn để minh chứng trong báo cáo. Các test case này tập trung vào các chức năng chính của chương trình như thêm dữ liệu, kiểm tra trùng khóa, kiểm tra khóa ngoại, nhập/cập nhật điểm, xếp loại học lực, tìm kiếm và hiển thị bảng điểm.

| Mã test | Chức năng                                  | Dữ liệu / Tình huống kiểm thử                                   | Kết quả mong đợi                                                           |
| ------- | ------------------------------------------ | --------------------------------------------------------------- | -------------------------------------------------------------------------- |
| TC01    | Thêm sinh viên hợp lệ                      | Nhập sinh viên mới với MSSV chưa tồn tại                        | Sinh viên được thêm thành công                                             |
| TC02    | Thêm sinh viên trùng MSSV                  | Nhập MSSV đã tồn tại trong `students.txt`                       | Hiển thị lỗi, không thêm dữ liệu                                           |
| TC03    | Thêm môn học hợp lệ                        | Nhập môn học mới với `MaHP` chưa tồn tại                        | Môn học được thêm thành công                                               |
| TC04    | Thêm môn học trùng mã                      | Nhập `MaHP` đã tồn tại trong `subjects.txt`                     | Hiển thị lỗi, không thêm dữ liệu                                           |
| TC05    | Thêm lớp học phần hợp lệ                   | Nhập `MaLHP` mới và `MaHP` đã tồn tại                           | Lớp học phần được thêm thành công                                          |
| TC06    | Thêm lớp học phần với `MaHP` không tồn tại | Nhập `MaHP` không có trong `subjects.txt`                       | Hiển thị lỗi, không thêm lớp học phần                                      |
| TC07    | Nhập điểm hợp lệ                           | Nhập `MSSV`, `MaLHP`, `DiemQT`, `DiemCK` hợp lệ                 | Bản ghi điểm được thêm thành công, `DiemTK` và `DiemHe4` được tính tự động |
| TC08    | Nhập điểm ngoài khoảng `0–10`              | Nhập `DiemQT = -1` hoặc `DiemCK = 11`                           | Hiển thị lỗi, không lưu điểm không hợp lệ                                  |
| TC09    | Nhập điểm cho sinh viên không tồn tại      | Nhập `MSSV` không có trong `students.txt`                       | Hiển thị lỗi, không lưu điểm                                               |
| TC11    | Nhập điểm trùng cặp `(MSSV, MaLHP)`        | Nhập điểm cho sinh viên đã có điểm trong lớp học phần đó        | Hiển thị lỗi, không tạo bản ghi trùng                                      |
| TC12    | Cập nhật điểm                              | Cập nhật `DiemQT` hoặc `DiemCK` của một bản ghi đã tồn tại      | Điểm được cập nhật thành công, `DiemTK` và `DiemHe4` được tính lại         |
| TC15    | Xếp loại học lực                           | GPA hệ 10 thuộc các khoảng Xuất sắc, Giỏi, Khá, Trung bình, Yếu | Hiển thị đúng xếp loại học lực                                             |
| TC16    | Tìm sinh viên tồn tại                      | Tìm theo MSSV hoặc họ tên có trong dữ liệu                      | Hiển thị đúng thông tin sinh viên                                          |
| TC17    | Tìm sinh viên không tồn tại                | Tìm MSSV hoặc từ khóa không có trong dữ liệu                    | Hiển thị thông báo không tìm thấy                                          |
| TC21    | Hiển thị bảng điểm lớp học phần            | Nhập `MaLHP` có nhiều sinh viên đã nhập điểm                    | Hiển thị danh sách sinh viên và điểm trong lớp học phần                    |

### 12.1. Ảnh minh chứng kiểm thử

Nhóm không cần chụp ảnh toàn bộ 28 test case. Khi nộp bài, chỉ cần chọn khoảng **10–15 test case tiêu biểu** để minh chứng chương trình đã chạy được các chức năng chính.

Các nhóm test nên có ảnh minh chứng:

- Thêm dữ liệu hợp lệ và chặn dữ liệu trùng khóa.
- Nhập/cập nhật điểm, chặn điểm ngoài khoảng `0–10`.
- Tính điểm tổng kết, GPA hệ 10, GPA hệ 4 và xếp loại học lực.
- Tìm kiếm và sắp xếp sinh viên.
- Hiển thị bảng điểm sinh viên và bảng điểm lớp học phần.
- Chặn xóa dữ liệu đang được tham chiếu.
- Kiểm thử load/save dữ liệu nếu cần minh chứng thêm.

Ảnh kiểm thử đặt trong thư mục `screenshots/`, đặt tên ngắn gọn theo mã test case, ví dụ:

```text
screenshots/
├── TC01_them_sinh_vien_hop_le.png
├── TC02_trung_mssv.png
├── TC07_nhap_diem_hop_le.png
├── TC08_diem_ngoai_khoang.png
├── TC14_gpa_he_10.png
├── TC15_xep_loai_hoc_luc.png
├── TC16_tim_sinh_vien.png
├── TC18_sap_xep_mssv.png
├── TC20_bang_diem_sinh_vien.png
├── TC21_bang_diem_lop_hoc_phan.png
├── TC22_chan_xoa_sinh_vien_co_diem.png
└── TC27_luu_va_doc_lai_du_lieu.png
```

---

## 13. Kết quả kiểm thử module nền tảng (TV1)

TV1 đã hoàn thành bộ kiểm thử tự động gồm 5 file, bao phủ toàn bộ phạm vi code do TV1 phụ trách (`types.h`, `arrays.c`, `fileio.c`, `gpa.c`). Chi tiết từng test case xem tại [`docs/test_note.md`](docs/test_note.md).

**Tổng kết theo kết quả kiểm thử đã ghi nhận: 68/68 PASS.**

| File test | Loại | Module kiểm tra | Số case | Kết quả |
|---|---|---|---|---|
| `source/test_types.c` | Unit | Struct layout trong `types.h` | 7 | ✅ 7/7 |
| `source/test_arrays.c` | Unit | Mảng động — init, add, resize, find, remove, clear, edge case | 11 | ✅ 11/11 |
| `source/test_fileio_unit.c` | Unit | Đọc/ghi file bằng file tạm, không đụng `data/` | 6 | ✅ 6/6 |
| `source/test_gpa.c` | Unit | Công thức GPA có trọng số tín chỉ, sinh viên không có điểm | 3 | ✅ 3/3 |
| `source/test_fileio.c` | Tích hợp | Toàn bộ pipeline `loadAllData` → `saveAllData` với `data/` thật | 41 | ✅ 41/41 |

> Khi chạy test sẽ có một vài dòng `[CANH BAO]` xuất hiện — đây là kết quả của các test case cố tình đưa vào dữ liệu sai định dạng để kiểm tra chương trình xử lý được không, không phải lỗi thật.

### Chạy test

Trỏ terminal vào thư mục `source/` trước, sau đó:

```bash
make unit_test   # Chạy 4 unit test, không đụng đến data/
make test        # Chạy integration test với dữ liệu thật trong data/
```

Chạy từng bộ riêng lẻ nếu cần:

```bash
make test_types
make test_arrays
make test_fileio_unit
make test_gpa
```

> **Windows với MSYS2:** thay `make` bằng `mingw32-make` nếu lệnh `make` không nhận.

Nếu không dùng Makefile, chạy thủ công từ thư mục `source/` (Linux/macOS):

```bash
gcc -Wall -Wextra -std=c99 test_types.c -o ../test_types && cd .. && ./test_types && cd source
gcc -Wall -Wextra -std=c99 arrays.c test_arrays.c -o ../test_arrays && cd .. && ./test_arrays && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio_unit.c -o ../test_fileio_unit && cd .. && ./test_fileio_unit && cd source
gcc -Wall -Wextra -std=c99 arrays.c gpa.c test_gpa.c -o ../test_gpa && cd .. && ./test_gpa && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio.c -o ../test_fileio && cd .. && ./test_fileio && cd source
```

---

## 14. Hướng dẫn build và chạy chương trình

### 14.1. Yêu cầu môi trường

Cần cài đặt:

- GCC hoặc trình biên dịch C tương đương.
- Make, nếu sử dụng Makefile.
- Git, nếu muốn clone repo từ GitHub.

### 14.2. Clone repository

```bash
git clone https://github.com/PKT-zZ/QLSV_MI3310.git
cd QLSV_MI3310
```

### 14.3. Build chương trình

Dự án sử dụng `Makefile` đặt trong thư mục `source/`. Để biên dịch chương trình chính, chạy các lệnh sau từ thư mục gốc của dự án:

```bash
cd source
make clean
make all
```

Sau khi build thành công, file thực thi `qlsv.exe` sẽ được tạo ở thư mục gốc của dự án.

Chi tiết về môi trường build, các target trong Makefile và kết quả kiểm thử được trình bày trong file [`docs/test_note.md`](docs/test_note.md).

### 14.4. Chạy chương trình

Sau khi build thành công, quay lại thư mục gốc của dự án và chạy chương trình:

```bash
cd ..
./qlsv.exe
```

Trên Windows PowerShell, có thể chạy bằng lệnh:

```powershell
.\qlsv.exe
```

Chương trình sẽ hiển thị menu chính để thực hiện các chức năng quản lý sinh viên, học phần, lớp học phần, điểm số, tìm kiếm, sắp xếp và báo cáo.

Các bước chạy kiểm thử tự động bằng Makefile như `make unit_test`, `make test` và kết quả kiểm thử chi tiết được ghi trong file [`docs/test_note.md`](docs/test_note.md).

## 15. Tài liệu liên quan

- Ghi chú kiểm thử: [`docs/test_note.md`](docs/test_note.md)
- Dữ liệu mẫu: `data/`
- Ảnh kiểm thử: `screenshots/` — lưu 15 ảnh minh chứng cho các test case tiêu biểu
