# Ghi chú test
Phụ trách: Thành viên 1
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

---

## Trạng thái tổng quan

| Chỉ số | Kết quả |
|---|---|
| Tổng số test case | **68** |
| Passed | **68** |
| Failed | **0** |
| Tỉ lệ | **100 %** |

Toàn bộ hệ thống mảng động và I/O đã được kiểm thử và vận hành ổn định. Không phát hiện memory leak, crash, hay sai lệch dữ liệu trong bất kỳ kịch bản nào đã test.

---

## Chi tiết kiểm thử theo module

### 1. `test_types.c` — Kiểm tra định nghĩa struct (7 PASS)

Xác nhận `types.h` khai báo đúng layout bộ nhớ cho 4 kiểu dữ liệu lõi.

| Case đã cover | Ghi chú |
|---|---|
| `sizeof(s.mssv) == 12` | Đủ chứa mã SV 9 chữ số + null |
| `sizeof(s.hoTen) == 60` | Đủ cho tên đầy đủ tiếng Việt không dấu |
| Gán/đọc `mssv`, `maHP`, `soTinChi`, `hocKy`, `namHoc`, `diemTK` | Kiểm tra từng trường trên cả 4 struct |

File này không phụ thuộc bất kỳ module hay file dữ liệu nào — chạy độc lập hoàn toàn.

---

### 2. `test_arrays.c` — Kiểm tra mảng động `StudentArray` (11 PASS)

Xác nhận các hàm `sa_*` trong `arrays.c` xử lý đúng vòng đời của mảng, bao gồm các tình huống biên.

| Case đã cover | Ghi chú |
|---|---|
| Khởi tạo mảng rỗng | `size=0`, `capacity=init_cap` ngay sau `sa_init` |
| Thêm phần tử bình thường | `size` tăng đúng sau mỗi `sa_add` |
| **Tự động mở rộng (resize x2)** | Thêm phần tử thứ 3 khi capacity=2 → resize không crash, dữ liệu cũ nguyên vẹn |
| Tìm kiếm đúng | `sa_find` trả đúng index với khóa tồn tại |
| Tìm kiếm khóa không có | `sa_find` trả `-1` |
| OOB get: index âm và index == size | `sa_get` trả `NULL` |
| OOB remove: index == size | `sa_remove` trả `0`, mảng không bị hỏng |
| Xóa + dịch trái | Sau `sa_remove(0)`, phần tử index 1 dịch về index 0 đúng |
| Giải phóng bộ nhớ | Sau `sa_clear`: `data=NULL`, `size=0` |

> **Kỹ thuật resize:** Hàm `sa_resize` (và 3 hàm tương đương) dùng con trỏ tạm `tmp` khi gọi `realloc` — đảm bảo không mất con trỏ gốc nếu `realloc` thất bại. Sau `sa_clear`, con trỏ được đặt về `NULL` ngăn double-free.

---

### 3. `test_fileio_unit.c` — Kiểm tra đọc/ghi file (6 PASS, không dùng `data/`)

Xác nhận `loadStudents`/`saveStudents` hoạt động đúng với file tạm tự tạo, hoàn toàn tách biệt khỏi dữ liệu thật.

| Case đã cover | Ghi chú |
|---|---|
| Đọc 1 dòng hợp lệ | Parse đúng MSSV, HoTen, Lop, Birthday |
| **Dòng thiếu trường bị bỏ qua** | Dòng có 2/4 trường → `[CANH BAO]`, bỏ qua, không crash |
| **Trùng khóa chính bị bỏ qua** | MSSV xuất hiện lần 2 → `[CANH BAO]`, giữ bản ghi đầu tiên |
| Save → Load lại (round-trip) | Dữ liệu sau khi ghi file rồi đọc lại khớp 100% |
| Số lượng bản ghi sau lọc | Chỉ load đúng số dòng hợp lệ |

> Các file tạm (`unit_tmp_in.txt`, `unit_tmp_out.txt`) được tạo và xóa tự động trong cùng test case — không để lại artifact trên disk.

---

### 4. `test_gpa.c` — Kiểm tra tính GPA có trọng số (3 PASS)

Xác nhận `calculateStudentGPA` tính đúng công thức GPA = Σ(diemHe4 × soTinChi) / Σ(soTinChi).

| Case đã cover | Kết quả mong đợi | Kết quả thực tế |
|---|---|---|
| 1 môn (2TC, He4=4.0) | GPA = 4.0 | ✅ PASS |
| **2 môn có trọng số** (2TC×4.0 + 3TC×2.0) | GPA = (8+6)/5 = **2.8** | ✅ PASS |
| Sinh viên không có bản ghi điểm | GPA = 0.0 | ✅ PASS |

Toàn bộ data được dựng in-memory — không phụ thuộc file, không phụ thuộc `fileio.c`.

---

### 5. `test_fileio.c` — Kiểm thử tích hợp với data thật (41 PASS)

Kiểm tra end-to-end toàn bộ pipeline I/O với 4 file trong `data/`. Đây là bộ test hồi quy (regression test) đảm bảo dữ liệu và logic phối hợp đúng.

| Nhóm | Cases | PASS |
|---|---|---|
| **Nhóm 1 – Load cơ bản** | Đếm số bản ghi (6 SV, 5 MH, 5 LHP, 22 điểm); kiểm tra giá trị cụ thể (tên, lớp, ngày sinh, số TC, học kỳ) | 14/14 |
| **Nhóm 2 – Điểm số** | `DiemQT/CK ∈ [0,10]`; `DiemTK = 0.5×QT + 0.5×CK`; `DiemHe4 ∈ [0,4]`; tìm khóa không tồn tại → -1 | 6/6 |
| **Nhóm 3 – Save → Reload** | Load → Save → Clear RAM → Load lại: số lượng và nội dung khớp hoàn toàn | 6/6 |
| **Nhóm 4 – File không tồn tại** | `loadStudents` với file giả → mảng rỗng, không crash | 1/1 |
| **Nhóm 5 – Dữ liệu sai định dạng** | File tạm có: 1 dòng hợp lệ + thiếu trường + MSSV rỗng + trùng MSSV → chỉ load đúng 1 bản ghi | 2/2 |
| **Nhóm 6 – Toàn vẹn khóa ngoại** | Mỗi điểm có MSSV và MaLHP hợp lệ; mỗi LHP có MaHP hợp lệ (sau `loadAllData` đã cascade-delete bản ghi rác) | 2/2 |
| **Nhóm 7 – Arrays edge cases** | `sa/suba/cca/sca_find` với khóa không tồn tại → -1; `sa_get/remove/update` với index âm và index==size → NULL/0 | 10/10 |

> **Lưu ý khi đọc output:** Các dòng `[CANH BAO]` xuất hiện lúc chạy là **bình thường** — đó là test cố tình truyền dữ liệu sai để kiểm tra khả năng phục hồi của chương trình. Không phải lỗi.

---
