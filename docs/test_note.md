# Ghi chú kiểm thử — Nền tảng dữ liệu & I/O

**Phụ trách:** Thành viên 1  
**Phạm vi:** `types.h`, `arrays.h/c`, `fileio.h/c`, `gpa.c`, `data/*.txt`

---

## 1. Môi trường

| Thành phần | Chi tiết |
|---|---|
| Hệ điều hành | Windows 11 |
| Trình biên dịch | GCC 15.2.0 (MSYS2) |
| Cờ biên dịch | `-Wall -Wextra -std=c99` |

---

## 2. Kết quả tổng hợp

**68/68 test case PASS — không có lỗi.**

| Bộ test | Loại | Số case | Kết quả |
|---|---|---|---|
| `test_types.c` | Unit | 7 | ✅ 7/7 |
| `test_arrays.c` | Unit | 11 | ✅ 11/11 |
| `test_fileio_unit.c` | Unit | 6 | ✅ 6/6 |
| `test_gpa.c` | Unit | 3 | ✅ 3/3 |
| `test_fileio.c` | Tích hợp | 41 | ✅ 41/41 |

*Lưu ý khi chạy: một số dòng `[CANH BAO]` xuất hiện là bình thường — đó là test cố tình đưa vào dữ liệu sai để kiểm tra chương trình có xử lý ổn không, không phải lỗi thật.*

---

## 3. Chi tiết từng bộ test

### `test_types.c` — Struct layout (7 PASS)

Kiểm tra 4 struct trong `types.h` có kích thước trường và kiểu dữ liệu đúng không.

| Case | Ghi chú |
|---|---|
| `sizeof(s.mssv) == 12` | Đủ chứa mã SV 9 ký tự + null terminator |
| `sizeof(s.hoTen) == 60` | Đủ cho họ tên tiếng Việt không dấu |
| Gán/đọc các trường `mssv`, `maHP`, `soTinChi`, `hocKy`, `namHoc`, `diemTK` | Mỗi trường trên một struct khác nhau |

File này không include module nào khác, không cần file dữ liệu — chạy độc lập hoàn toàn.

---

### `test_arrays.c` — Mảng động (11 PASS)

Kiểm tra các hàm `sa_*` trong `arrays.c` qua vòng đời đầy đủ của một `StudentArray`.

| Case | Ghi chú |
|---|---|
| Khởi tạo | `size=0`, `capacity=init_cap` đúng ngay sau `sa_init` |
| Thêm phần tử | `size` tăng đúng sau mỗi lần `sa_add` |
| **Tự động resize** | Thêm phần tử thứ 3 khi `capacity=2` → resize nhân đôi, không crash, dữ liệu cũ không mất |
| Tìm đúng | `sa_find` trả index đúng với khóa có thật |
| Tìm không thấy | `sa_find` trả `-1` |
| `sa_get` với index âm và index == size | Trả `NULL`, không crash |
| `sa_remove` với index == size | Trả `0`, mảng không bị hỏng |
| Xóa và dịch trái | Sau `sa_remove(0)`, phần tử cũ ở index 1 dịch xuống đúng vị trí 0 |
| Giải phóng | Sau `sa_clear`: `data=NULL`, `size=0` — không double-free |

Kỹ thuật quan trọng trong `sa_resize`: dùng con trỏ tạm `tmp` khi gọi `realloc` để không mất con trỏ gốc nếu cấp phát thất bại. Sau `sa_clear` đặt `data = NULL` để tránh dangling pointer.

---

### `test_fileio_unit.c` — Đọc/ghi file (6 PASS)

Kiểm tra `loadStudents` và `saveStudents` bằng file tạm tự tạo trong test — **không đụng đến `data/`**.

| Case | Ghi chú |
|---|---|
| Đọc 1 dòng hợp lệ | Parse đúng cả 4 trường: MSSV, HoTen, Lop, Birthday |
| **Dòng thiếu trường bị bỏ qua** | Dòng có 2/4 trường → in cảnh báo, bỏ qua, đọc tiếp |
| **Trùng MSSV bị bỏ qua** | MSSV xuất hiện lần 2 → giữ bản ghi đầu tiên, bỏ bản sau |
| Save → Load lại | Ghi file rồi đọc lại: số lượng và nội dung khớp hoàn toàn |

File tạm (`unit_tmp_in.txt`, `unit_tmp_out.txt`) được tạo và xóa ngay trong test, không để lại gì trên disk.

---

### `test_gpa.c` — Tính GPA (3 PASS)

Kiểm tra `calculateStudentGPA` tính đúng công thức GPA = Σ(diemHe4 × soTinChi) / Σ(soTinChi). Toàn bộ data dựng thẳng trong code, không cần file.

| Case | Kết quả mong đợi | Kết quả thực tế |
|---|---|---|
| 1 môn (2 TC, He4 = 4.0) | 4.0 | ✅ PASS |
| 2 môn có trọng số: 2TC×4.0 + 3TC×2.0 | (8+6)/5 = **2.8** | ✅ PASS |
| Sinh viên không có điểm nào | 0.0 | ✅ PASS |

---

### `test_fileio.c` — Tích hợp với data thật (41 PASS)

Chạy toàn bộ pipeline `loadAllData` → `saveAllData` → `loadAllData` với 4 file trong `data/`. Mục đích chính là kiểm tra chương trình thật sự hoạt động đúng với dữ liệu thật, và đảm bảo không bị vỡ khi có thay đổi nhỏ.

| Nhóm | Nội dung test | Kết quả |
|---|---|---|
| **Nhóm 1 – Load cơ bản** | Đếm đúng số bản ghi (6 SV, 5 MH, 5 LHP, 22 điểm); kiểm tra giá trị cụ thể (tên, lớp, ngày sinh, số TC, học kỳ) | 14/14 |
| **Nhóm 2 – Điểm số** | DiemQT/CK trong [0,10]; `DiemTK = 0.5×QT + 0.5×CK`; DiemHe4 trong [0,4]; tìm khóa không có → -1 | 6/6 |
| **Nhóm 3 – Save → Reload** | Load → ghi đè file → xóa RAM → load lại: số lượng và nội dung khớp hoàn toàn | 6/6 |
| **Nhóm 4 – File không tồn tại** | Truyền đường dẫn file giả → mảng rỗng, không crash | 1/1 |
| **Nhóm 5 – Dữ liệu sai định dạng** | File tạm có: thiếu cột, MSSV rỗng, trùng MSSV → chỉ load đúng 1 dòng hợp lệ, bỏ qua 3 dòng lỗi | 2/2 |
| **Nhóm 6 – Khóa ngoại** | Mỗi bản ghi điểm có MSSV và MaLHP hợp lệ; mỗi LHP có MaHP hợp lệ — `loadAllData` tự xóa bản ghi tham chiếu sai | 2/2 |
| **Nhóm 7 – Edge case mảng** | `sa/suba/cca/sca_find` với khóa không tồn tại → -1; `sa_get/remove/update` với index âm và index==size → NULL/0 | 10/10 |

---

````md
## **4. Hướng dẫn build, chạy chương trình và chạy test**

### **4.1. Kiểm tra GCC**

Mở terminal trong VSCode (`Ctrl + ``) và gõ:

```bash
gcc --version
````

Nếu thấy số phiên bản in ra thì môi trường biên dịch đã sẵn sàng. Nếu báo `not found`, cần cài GCC/MinGW/MSYS2 trước.

---

### 4.2. Mở đúng terminal theo hệ điều hành

**Windows**

Nên dùng **Git Bash / MINGW64** trong VSCode.

Nếu dùng Git Bash mà lệnh `make` không chạy được, dùng:

```bash
mingw32-make
```

thay cho:

```bash
make
```

**Linux/macOS**

Có thể dùng terminal mặc định và lệnh `make`.

Nếu chưa có GCC/Make:

```bash
sudo apt install build-essential    # Ubuntu/Debian
sudo dnf install gcc make           # Fedora
xcode-select --install              # macOS
```

---

### 4.3. Build chương trình chính

Trỏ terminal vào thư mục `source/`:

```bash
cd QLSV_MI3310/source
```

Hoặc nếu đang ở thư mục gốc project:

```bash
cd source
```

Sau đó build chương trình:

```bash
mingw32-make clean
mingw32-make all
```

Trên Linux/macOS có thể dùng:

```bash
make clean
make all
```

Sau khi build thành công, file `qlsv.exe` sẽ được tạo ở thư mục gốc project:

```text
QLSV_MI3310/qlsv.exe
```

---

### 4.4. Chạy chương trình chính `qlsv.exe`

Sau khi build xong, cần quay lại **thư mục gốc project** rồi mới chạy chương trình:

```bash
cd ..
./qlsv.exe
```

Trên PowerShell:

```powershell
.\qlsv.exe
```

Lưu ý quan trọng:

* Chương trình cần chạy từ thư mục gốc `QLSV_MI3310/` để đọc đúng các file trong `data/`.
* Không nên chạy `../qlsv.exe` khi terminal vẫn đang ở `source/`, vì khi đó chương trình có thể không đọc đúng `data/students.txt`, `data/subjects.txt`, `data/course_classes.txt`, `data/scores.txt`.
* Nếu chương trình báo không mở được file `data/*.txt`, hãy thoát chương trình, quay về thư mục gốc project rồi chạy lại:

```bash
cd /d/Code/Environment/QLSV_MI3310
./qlsv.exe
```

---

### 4.5. Chạy test bằng Makefile

Các lệnh test chạy trong thư mục `source/`.

Nếu đang ở thư mục gốc project:

```bash
cd source
```

Chạy unit test:

```bash
mingw32-make unit_test
```

Chạy integration test:

```bash
mingw32-make test
```

Trên Linux/macOS có thể dùng:

```bash
make unit_test
make test
```

Ý nghĩa các lệnh:

| Lệnh                     | Tác dụng                                                                      |
| ------------------------ | ----------------------------------------------------------------------------- |
| `mingw32-make all`       | Build chương trình chính `../qlsv.exe`                                        |
| `mingw32-make unit_test` | Chạy 4 unit test: `test_types`, `test_arrays`, `test_fileio_unit`, `test_gpa` |
| `mingw32-make test`      | Chạy integration test `test_fileio` với dữ liệu thật trong `data/`            |
| `mingw32-make clean`     | Xóa các file `.exe` đã build                                                  |

Kết quả mong đợi:

```text
Unit test: 27/27 PASS
Integration test: 41/41 PASS
Tổng: 68/68 PASS
```

Một số dòng `[CANH BAO]` khi chạy test là bình thường, vì test cố tình đưa vào file không tồn tại hoặc dữ liệu sai định dạng để kiểm tra khả năng xử lý lỗi.

---

### 4.6. Chạy bằng lệnh GCC trực tiếp nếu Makefile không hoạt động

Nếu `make` hoặc `mingw32-make` không hoạt động, có thể chạy thủ công từ thư mục `source/`.

**Git Bash / Linux / macOS:**

```bash
gcc -Wall -Wextra -std=c99 test_types.c -o ../test_types.exe && cd .. && ./test_types.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c test_arrays.c -o ../test_arrays.exe && cd .. && ./test_arrays.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio_unit.c -o ../test_fileio_unit.exe && cd .. && ./test_fileio_unit.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c gpa.c test_gpa.c -o ../test_gpa.exe && cd .. && ./test_gpa.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio.c -o ../test_fileio.exe && cd .. && ./test_fileio.exe && cd source
```

**PowerShell/CMD:**

```powershell
gcc -Wall -Wextra -std=c99 test_types.c -o ../test_types.exe && cd .. && .\test_types.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c test_arrays.c -o ../test_arrays.exe && cd .. && .\test_arrays.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio_unit.c -o ../test_fileio_unit.exe && cd .. && .\test_fileio_unit.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c gpa.c test_gpa.c -o ../test_gpa.exe && cd .. && .\test_gpa.exe && cd source
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio.c -o ../test_fileio.exe && cd .. && .\test_fileio.exe && cd source
```

> `test_fileio` cần chạy từ thư mục gốc project vì test này dùng dữ liệu thật trong `data/`.

```
```
