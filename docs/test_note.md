# Ghi chú kiểm thử — Nền tảng dữ liệu & I/O

**Phụ trách:** Thành viên 1
**Phạm vi kiểm thử:**

* Kiểm thử các thành phần nền tảng: `types.h`, `arrays.h/c`, `fileio.h/c`, `gpa.c`.
* Kiểm thử dữ liệu mẫu trong `data/*.txt`.
* Ghi nhận kết quả chạy các test tự động: unit test và integration test.
* Ghi chú cách build/chạy chương trình chính `qlsv.exe` và cách chạy test bằng Makefile.

**Không bao gồm:** kiểm thử thủ công toàn bộ chức năng giao diện theo các test case TC01–TC28 trong README. Các test case đó được kiểm tra riêng khi demo/chụp ảnh minh chứng.

---

## 4. **Hướng dẫn build, chạy chương trình và chạy test**

### 4.1. **Kiểm tra GCC**

Mở terminal trong VSCode (`Ctrl + ``) và gõ:

```bash
gcc --version
```

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
