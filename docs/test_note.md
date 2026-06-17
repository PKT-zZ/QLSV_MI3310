# Ghi chú test

---

## 1. Môi trường chạy code

| Thành phần | Chi tiết |
|---|---|
| **Hệ điều hành** | Windows 11 |
| **Trình biên dịch** | GCC 15.2.0 (MSYS2) |
| **Cờ biên dịch** | `-Wall -Wextra -std=c99` |
| **File chạy test** | `source/test_fileio.c` (integration), `source/test_types.c`, `source/test_arrays.c`, `source/test_fileio_unit.c`, `source/test_gpa.c` (unit) |
| **Dữ liệu test** | Các file `.txt` trong thư mục `data/` |

---

## 2. Hướng dẫn chạy test

**Lưu ý:** Tất cả lệnh `make` đều chạy từ bên trong thư mục `source/`. File `.exe` được đặt ở thư mục gốc để chương trình đọc được đúng đường dẫn `data/`.

### Các target có sẵn trong Makefile

| Lệnh | Tác dụng |
|---|---|
| `make all` | Build chương trình chính → `../qlsv.exe` |
| `make test` | Build và chạy integration test (`test_fileio.c`) dùng dữ liệu thật trong `data/` |
| `make test_types` | Unit test cho `types.h` |
| `make test_arrays` | Unit test cho `arrays.c` |
| `make test_fileio_unit` | Unit test cho `fileio.c`, dùng file tạm, không đụng `data/` |
| `make test_gpa` | Unit test cho `gpa.c` |
| `make unit_test` | Chạy cả 4 unit test trên liên tiếp |
| `make clean` | Xóa toàn bộ file `.exe` đã build |

### Cách chạy

```bash
# Trỏ vào thư mục source trước
cd source

# Build chương trình chính
make all

# Chạy integration test
make test

# Chạy toàn bộ unit test
make unit_test

# Chạy từng unit test riêng lẻ nếu cần
make test_arrays
```

> **Trên Windows với MSYS2:** thay `make` bằng `mingw32-make` nếu lệnh `make` không nhận, ví dụ: `mingw32-make test`.

### Nếu không dùng Makefile (gõ thủ công)

```bash
# Build chương trình chính (chạy từ thư mục source/)
gcc -Wall -Wextra -std=c99 arrays.c fileio.c student.c subject.c courseclass.c score.c gpa.c sort.c search.c ui.c main.c -o ../qlsv.exe

# Chạy integration test (score.c bắt buộc phải có vì fileio.c dùng hàm tính điểm từ đó)
gcc -Wall -Wextra -std=c99 arrays.c fileio.c score.c test_fileio.c -o ../test_fileio.exe
cd .. && ./test_fileio.exe        # Linux/macOS
cd .. && test_fileio.exe          # Windows
```

---

## 3. Tổng hợp kết quả test

**Kết quả chung: 41 PASS / 0 FAIL**

> *Ghi chú: Lúc chạy test sẽ hiện ra vài dòng `[CANH BAO]`. Đây là test tính năng tự động bắt lỗi khi file `.txt` bị sai định dạng, chương trình vẫn chạy bình thường không bị sập.*

### Bảng chi tiết các trường hợp đã test:

| Nhóm chức năng | Các trường hợp đã kiểm tra (Pass 100%) |
|---|---|
| **1. Load dữ liệu** | • Đọc đủ số lượng bản ghi của 4 file txt.<br>• Data lấy ra mảng (MSSV, Tên, Học kỳ...) khớp chính xác với file. |
| **2. Điểm số** | • Tính toán điểm `DiemTK == 0.5*DiemQT + 0.5*DiemCK` chuẩn xác.<br>• Bắt lỗi điểm ngoài khoảng [0, 10]. |
| **3. Save / Reload** | • Đọc data lên $\rightarrow$ Ghi đè xuống file $\rightarrow$ Xóa ram $\rightarrow$ Đọc lại: Không bị mất hay lệch dòng nào. |
| **4. Lỗi file missing** | • Xóa thử file `students.txt` $\rightarrow$ Code tự tạo mảng rỗng, báo lỗi nhẹ rồi chạy tiếp, không bị crash. |
| **5. Dữ liệu rác** | • Cố tình tạo file txt bị: thiếu cột, rỗng MSSV, trùng MSSV $\rightarrow$ Code tự động skip các dòng lỗi, nạp các dòng đúng.<br>• Tự động dọn dẹp file tạm `tmp_test.txt` sau khi test xong. |
| **6. Khóa ngoại (FK)** | • Quét thấy điểm của MSSV không tồn tại $\rightarrow$ Tự động dọn dẹp điểm rác.<br>• Lớp học phần trỏ đến Mã HP không tồn tại $\rightarrow$ Xóa lớp đó. |
| **7. Tràn mảng (OOB)**| • Gọi hàm tìm kiếm/xóa với index âm hoặc khóa không có thật $\rightarrow$ Bị chặn lại an toàn, trả về `-1` hoặc `NULL`. |

---

### Unit test từng module

> *Các file unit test được bổ sung sau integration test. Chạy bằng `make unit_test` từ thư mục `source/`.*

| File test | Module kiểm tra | Kết quả |
|---|---|---|
| `test_types.c` | Struct và kích thước trường trong `types.h` | ✅ PASS |
| `test_arrays.c` | Thêm/xóa/tìm/resize mảng động, edge case index âm/ngoài phạm vi | ✅ PASS |
| `test_fileio_unit.c` | Đọc/ghi file bằng file tạm, không dùng `data/` — kiểm tra dòng lỗi bị bỏ qua, round-trip save→load | ✅ PASS |
| `test_gpa.c` | Công thức GPA có trọng số tín chỉ, trường hợp không có điểm → GPA = 0 | ✅ PASS |
---

## 4. Lưu ý quan trọng cho TV2 & TV3 khi tích hợp

Khi viết các hàm UI hoặc Logic (Thêm/Sửa/Xóa), nhớ tuân thủ quy tắc sau để bảo vệ tính toàn vẹn dữ liệu nhé:
1. **Trước khi xóa Sinh Viên hoặc Môn học:** phải gọi hàm check xem có bản ghi điểm (`ScoreRecord`) hay Lớp học phần (`CourseClass`) nào đang dính tới nó không. Nếu có thì chặn lại không cho xóa (báo lỗi ra màn hình).
2. Khi dùng các hàm có đuôi `_get` (ví dụ `sa_get`), nhớ check `NULL` trước khi trỏ lấy data.
