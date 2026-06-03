# Ghi chú test

---

## 1. Môi trường chạy code

| Thành phần | Chi tiết |
|---|---|
| **Hệ điều hành** | Windows 11 |
| **Trình biên dịch** | GCC 15.2.0 (MSYS2) |
| **Cờ biên dịch** | `-Wall -Wextra -std=c99` |
| **File chạy test** | `source/test_fileio.c` |
| **Dữ liệu test** | Các file `.txt` trong thư mục `data/` |

---

## 2. Hướng dẫn chạy test

**Lưu ý:** Phải chạy lệnh từ thư mục gốc của project thì code mới đọc được đúng đường dẫn `data/...`

### Cách 1: Dùng Makefile
```bash
# Trỏ vào source và chạy make
cd source
mingw32-make test 
```

### Cách 2: Gõ lệnh thủ công (Từ thư mục gốc project)
```bash
# Trên Windows
gcc source\arrays.c source\fileio.c source\test_fileio.c -Isource -o test_fileio.exe
.\test_fileio.exe
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

## 4. Lưu ý quan trọng cho TV2 & TV3 khi tích hợp

Khi viết các hàm UI hoặc Logic (Thêm/Sửa/Xóa), nhớ tuân thủ quy tắc sau để bảo vệ tính toàn vẹn dữ liệu nhé:
1. **Trước khi xóa Sinh Viên hoặc Môn học:** phải gọi hàm check xem có bản ghi điểm (`ScoreRecord`) hay Lớp học phần (`CourseClass`) nào đang dính tới nó không. Nếu có thì chặn lại không cho xóa (báo lỗi ra màn hình).
2. Khi dùng các hàm có đuôi `_get` (ví dụ `sa_get`), nhớ check `NULL` trước khi trỏ lấy data.
