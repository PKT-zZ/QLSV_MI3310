# Tổng hợp vấn đề cần sửa và hướng rút gọn `ui.c` / `ui.h`

## Kết luận kiến trúc

Hiện tại `ui.c` đang ôm quá nhiều công việc: hiển thị menu, nhập dữ liệu, kiểm tra dữ liệu, xử lý CRUD, kiểm tra ràng buộc, tìm kiếm, sắp xếp, tính điểm, tính GPA và in báo cáo. Cách làm này khiến các module như `student.c`, `subject.c`, `courseclass.c`, `score.c`, `gpa.c`, `sort.c`, `search.c` không phát huy đúng vai trò theo kế hoạch trong README.

Hướng sửa nên chọn là: **rút gọn `ui.c` và `ui.h`, chuyển logic nghiệp vụ về đúng các module tương ứng**. Sau khi sửa, `ui.c` chỉ nên làm nhiệm vụ giao diện console: hiển thị menu, đọc input, gọi hàm từ module khác và in kết quả.

---

## 1. Rút gọn `ui.h`

### Vấn đề
`ui.h` đang khai báo quá nhiều hàm nội bộ như hàm nhập dữ liệu, hiển thị danh sách, kiểm tra MSSV, kiểm tra điểm, kiểm tra ngày sinh. Những hàm này chủ yếu chỉ được dùng bên trong `ui.c`, không cần công khai ra header.

### Hướng sửa
- Đổi `ui.h` sang dùng `#pragma once` để đồng bộ với các header khác.
- Chỉ giữ trong `ui.h` những hàm UI thật sự cần gọi từ file khác, quan trọng nhất là `showMainMenu`.
- Các hàm như `readLine`, `readInt`, `readFloat`, `displayStudents`, `validateDate`, `validateScore` nếu chỉ dùng trong `ui.c` thì để thành hàm `static` trong `ui.c`, không khai báo trong `ui.h`.
- Mục tiêu là làm `ui.h` gọn, đúng vai trò là header của giao diện, không phải nơi khai báo toàn bộ logic phụ.

---

## 2. Rút gọn `ui.c`

### Vấn đề
`ui.c` hiện vừa làm giao diện vừa xử lý nghiệp vụ. Ví dụ: thêm sinh viên, sửa sinh viên, xóa sinh viên, kiểm tra trùng MSSV, kiểm tra sinh viên đã có điểm chưa, tính điểm tổng kết, quy đổi điểm hệ 4, tìm kiếm, sắp xếp và báo cáo đều đang nằm nhiều trong `ui.c`.

### Hướng sửa
- Giữ lại trong `ui.c` các hàm menu và các hàm nhập/xuất màn hình.
- Không để `ui.c` tự xử lý trực tiếp các thao tác nghiệp vụ bằng cách gọi sâu vào `arrays.c` như `sa_find`, `sa_add`, `suba_find`, `cca_find`, `sca_find`.
- Thay vào đó, `ui.c` chỉ đọc thông tin người dùng nhập, rồi gọi các hàm cấp cao từ `student.c`, `subject.c`, `courseclass.c`, `score.c`, `gpa.c`, `sort.c`, `search.c`.
- Sau khi gọi module nghiệp vụ, `ui.c` chỉ cần in thông báo thành công/thất bại hoặc in bảng kết quả.

---

## 3. Chuyển logic sinh viên sang `student.c` / `student.h`

### Vấn đề
Các thao tác thêm, sửa, xóa sinh viên hiện vẫn đang bị xử lý nhiều trong `ui.c`. Điều này làm `ui.c` phụ thuộc quá nhiều vào cấu trúc mảng động và các quy tắc nghiệp vụ.

### Hướng sửa
- Đưa các hàm xử lý sinh viên vào `student.c/student.h`.
- Module `student.c` nên chịu trách nhiệm:
  - tìm sinh viên theo MSSV,
  - thêm sinh viên mới,
  - cập nhật thông tin sinh viên,
  - xóa sinh viên,
  - kiểm tra sinh viên đã có điểm hay chưa trước khi xóa,
  - kiểm tra MSSV hợp lệ nếu muốn tách validate khỏi UI.
- Trong `ui.c`, các hàm như thêm/sửa/xóa sinh viên chỉ còn đọc dữ liệu từ bàn phím rồi gọi hàm tương ứng trong `student.c`.

---

## 4. Chuyển logic học phần sang `subject.c` / `subject.h`

### Vấn đề
`ui.c` đang tự xử lý thêm, sửa, xóa học phần và tự kiểm tra học phần có đang được lớp học phần sử dụng hay không.

### Hướng sửa
- Đưa các thao tác liên quan học phần vào `subject.c/subject.h`.
- Module `subject.c` nên xử lý:
  - tìm học phần theo mã,
  - thêm học phần,
  - cập nhật học phần,
  - xóa học phần,
  - kiểm tra học phần có đang được lớp học phần tham chiếu không,
  - kiểm tra số tín chỉ hợp lệ nếu cần.
- `ui.c` chỉ đọc mã học phần, tên học phần, số tín chỉ rồi gọi hàm từ `subject.c`.

---

## 5. Chuyển logic lớp học phần sang `courseclass.c` / `courseclass.h`

### Vấn đề
`ui.c` đang tự xử lý thêm, sửa, xóa lớp học phần, tự kiểm tra mã lớp học phần trùng, mã học phần có tồn tại không, lớp có điểm hay chưa.

### Hướng sửa
- Đưa logic lớp học phần vào `courseclass.c/courseclass.h`.
- Module này nên xử lý:
  - tìm lớp học phần theo mã lớp học phần,
  - thêm lớp học phần,
  - cập nhật lớp học phần,
  - xóa lớp học phần,
  - kiểm tra mã học phần có tồn tại không,
  - kiểm tra lớp học phần có đang được bảng điểm sử dụng không,
  - kiểm tra học kỳ, năm học nếu cần.
- `ui.c` chỉ nhập thông tin lớp học phần và gọi hàm từ module này.

---

## 6. Chuyển logic điểm sang `score.c` / `score.h`

### Vấn đề
`ui.c` đang tự tính `DiemTK`, tự quy đổi `DiemHe4`, tự kiểm tra MSSV tồn tại, mã lớp học phần tồn tại, trùng khóa điểm và tự thêm/cập nhật/xóa điểm.

### Hướng sửa
- Đưa toàn bộ logic điểm vào `score.c/score.h`.
- Module `score.c` nên xử lý:
  - tính điểm tổng kết `DiemTK`,
  - quy đổi điểm hệ 4,
  - thêm điểm,
  - cập nhật điểm,
  - xóa điểm,
  - kiểm tra điểm nằm trong khoảng hợp lệ,
  - kiểm tra sinh viên tồn tại,
  - kiểm tra lớp học phần tồn tại,
  - kiểm tra trùng khóa kép `(MSSV, MaLHP)`.
- Trong `ui.c`, khi thêm hoặc sửa điểm, chỉ cần nhập `DiemQT`, `DiemCK`, sau đó gọi hàm từ `score.c`. Việc tự tính `DiemTK` và `DiemHe4` nên để `score.c` xử lý.

---

## 7. Gộp công thức tính điểm về một nơi

### Vấn đề
Đang có nguy cơ trùng lặp công thức: `ui.c` có thể có `calcDiemTK` / `quyDoiHe4`, trong khi `score.c` cũng có `calculateDiemTK` / `convertToHe4`. Nếu sau này sửa công thức ở một nơi mà quên nơi còn lại thì dữ liệu sẽ không nhất quán.

### Hướng sửa
- Chỉ giữ một bản công thức trong `score.c/score.h`.
- Các file khác như `ui.c`, `fileio.c`, `test_fileio.c` nếu cần tính điểm thì gọi lại hàm trong `score.c`.
- Xóa hoặc ngừng dùng các hàm tính điểm trùng lặp trong `ui.c`.

---

## 8. Bổ sung GPA hệ 10 và GPA hệ 4 trong `gpa.c` / `gpa.h`

### Vấn đề
README yêu cầu tính GPA và xếp loại, nhưng phần GPA cần được tách rõ thành module riêng thay vì để trong `ui.c` hoặc chỉ tính rời rạc trong báo cáo.

### Hướng sửa
- Viết hàm tính GPA hệ 10 trong `gpa.c/gpa.h`.
- Công thức GPA hệ 10:
  - `GPA10 = tổng(DiemTK * SoTinChi) / tổng(SoTinChi)`.
- Viết hàm tính GPA hệ 4:
  - `GPA4 = tổng(DiemHe4 * SoTinChi) / tổng(SoTinChi)`.
- Khi tính GPA, hàm phải đi qua dữ liệu theo chuỗi:
  - từ `scores` lấy `MaLHP`,
  - từ `course_classes` tìm lớp học phần tương ứng,
  - từ lớp học phần lấy `MaHP`,
  - từ `subjects` tìm học phần để lấy `SoTinChi`.
- Nếu sinh viên chưa có điểm hoặc không có tín chỉ hợp lệ thì trả về 0 hoặc xử lý theo quy ước thống nhất.

---

## 9. Bổ sung xếp loại học lực trong `gpa.c` / `gpa.h`

### Vấn đề
Bảng điểm hoặc báo cáo chưa có phần xếp loại học lực, trong khi README có nhắc đến xếp loại.

### Hướng sửa
- Viết hàm xếp loại học lực trong `gpa.c/gpa.h`, nhận đầu vào là GPA hệ 10.
- Có thể dùng các mốc:
  - từ 9.0 trở lên: Xuất sắc,
  - từ 8.0 đến dưới 9.0: Giỏi,
  - từ 7.0 đến dưới 8.0: Khá,
  - từ 5.0 đến dưới 7.0: Trung bình,
  - dưới 5.0: Yếu.
- `ui.c` không tự xếp loại, chỉ gọi hàm từ `gpa.c` rồi in kết quả.

---

## 10. Bổ sung GPA và học lực vào bảng điểm sinh viên trong `ui.c`

### Vấn đề
Hàm in bảng điểm sinh viên hiện mới in danh sách điểm từng môn, chưa có phần tổng kết GPA hệ 10, GPA hệ 4 và học lực.

### Hướng sửa
- Giữ hàm in bảng điểm ở `ui.c` vì đây là phần hiển thị.
- Sau khi in xong các dòng điểm từng môn, `ui.c` gọi các hàm từ `gpa.c` để lấy:
  - GPA hệ 10,
  - GPA hệ 4,
  - học lực.
- In thêm một phần tổng kết cuối bảng điểm, ví dụ:
  - GPA hệ 10,
  - GPA hệ 4,
  - xếp loại học lực.
- Không tự tính GPA trực tiếp trong `ui.c`.

---

## 11. Chuyển tìm kiếm sang `search.c` / `search.h`

### Vấn đề
README yêu cầu tự cài tìm kiếm tuyến tính, nhưng nếu toàn bộ tìm kiếm nằm rải rác trong `ui.c` thì module `search.c` không có vai trò rõ ràng.

### Hướng sửa
- Đưa các hàm tìm kiếm vào `search.c/search.h`.
- Tối thiểu nên có:
  - tìm sinh viên theo MSSV,
  - tìm sinh viên theo họ tên,
  - tìm sinh viên theo lớp,
  - tìm học phần theo mã học phần,
  - tìm học phần theo tên học phần,
  - tìm lớp học phần theo mã lớp học phần,
  - tìm điểm theo MSSV hoặc theo mã lớp học phần nếu cần.
- Các hàm tìm kiếm nên dùng Linear Search để đúng yêu cầu cơ bản.
- `ui.c` chỉ nhận từ khóa từ người dùng, gọi hàm tìm kiếm rồi in kết quả.

---

## 12. Bổ sung sắp xếp vào `sort.c` / `sort.h`

### Vấn đề
README yêu cầu sắp xếp danh sách sinh viên theo MSSV, họ tên hoặc điểm trung bình. Nếu chỉ có file `sort.c` nhưng menu không gọi, hoặc thiếu sắp xếp theo điểm trung bình thì chưa đủ.

### Hướng sửa
- Trong `sort.c/sort.h`, cần có các hàm:
  - sắp xếp sinh viên theo MSSV,
  - sắp xếp sinh viên theo họ tên,
  - sắp xếp sinh viên theo điểm trung bình/GPA hệ 10.
- Chỉ cần dùng Bubble Sort, Selection Sort hoặc Insertion Sort. Không cần Quick Sort vì đây là phần mở rộng, không bắt buộc.
- Hàm sắp xếp theo điểm trung bình nên gọi `gpa.c` để lấy GPA hệ 10 của từng sinh viên, không tự tính lại trong `sort.c`.

---

## 13. Thêm chức năng sắp xếp vào menu sinh viên trong `ui.c`

### Vấn đề
Nếu `showStudentMenu` chưa có mục sắp xếp, người dùng không thể sử dụng chức năng này dù `sort.c` đã có hàm.

### Hướng sửa
- Trong menu sinh viên, thêm một mục “Sắp xếp danh sách sinh viên”.
- Khi chọn mục này, cho người dùng chọn tiếp:
  - sắp xếp theo MSSV,
  - sắp xếp theo họ tên,
  - sắp xếp theo điểm trung bình/GPA hệ 10.
- Sau khi gọi hàm sắp xếp từ `sort.c`, `ui.c` in lại danh sách sinh viên.
- Phần này giúp chức năng sắp xếp thật sự được tích hợp vào chương trình, thay vì chỉ tồn tại trong source code.

---

## 14. Sửa `fileio.c` để dùng lại công thức điểm trong `score.c`

### Vấn đề
Khi đọc `scores.txt`, chương trình có thể đang tin vào `DiemTK` và `DiemHe4` có sẵn trong file. Nếu dữ liệu file sai công thức, chương trình vẫn có thể load dữ liệu không nhất quán.

### Hướng sửa
- Khi đọc file điểm, vẫn có thể đọc các cột `DiemTK` và `DiemHe4` để kiểm tra định dạng nếu muốn.
- Tuy nhiên, giá trị lưu vào struct nên được tính lại từ `DiemQT` và `DiemCK` bằng hàm trong `score.c`.
- Nếu giá trị trong file không khớp với công thức, có thể in cảnh báo, nhưng dữ liệu chính trong chương trình nên theo kết quả tự tính.
- Cách này giúp dữ liệu điểm luôn nhất quán giữa nhập tay, đọc file và ghi file.

---

## 15. Sửa `test_fileio.c`

### Vấn đề
`test_fileio.c` đang gọi `feq()` để so sánh số thực nhưng hàm này chưa được định nghĩa, có thể gây lỗi khi build hoặc link test.

### Hướng sửa
- Bổ sung hàm `feq(float a, float b)` trong `test_fileio.c`.
- Hàm này so sánh hai số thực với một sai số nhỏ, ví dụ epsilon = 0.001.
- Có thể tận dụng hàm `f_abs` nếu trong file đã có.
- Sau khi thêm hàm này, chạy lại `make test` để kiểm tra kết quả thật.

---

## 16. Cập nhật `docs/test_note.md`

### Vấn đề
Tài liệu test có thể đang ghi kết quả PASS/FAIL cũ. Nếu trước đó test chưa build được thì con số trong tài liệu không còn đáng tin.

### Hướng sửa
- Sau khi sửa `test_fileio.c`, chạy lại:
  - `make clean`,
  - `make all`,
  - `make test`.
- Ghi lại đúng số lượng PASS/FAIL thực tế vào `docs/test_note.md`.
- Nếu có cảnh báo trong lúc test do cố tình kiểm tra file lỗi thì ghi chú rõ để người đọc không hiểu nhầm.

---

## 17. Sửa `Makefile`

### Vấn đề
`make clean` dùng lệnh `del /Q`, chỉ phù hợp Windows CMD. Nếu README nói chương trình có thể chạy trên Linux/macOS hoặc môi trường Git Bash thì lệnh này không phù hợp.

### Hướng sửa
- Sửa target `clean` để dùng được trên nhiều môi trường hơn.
- Có thể tách theo hệ điều hành:
  - Windows dùng `del /Q`,
  - Linux/macOS/Git Bash dùng `rm -f`.
- Hoặc nếu nhóm chỉ chạy bằng Git Bash/MinGW thì có thể dùng `rm -f`, nhưng cần ghi rõ trong README.

---

## 18. Sửa `main.c`

### Vấn đề
`main.c` gọi các hàm khởi tạo mảng động nhưng chưa kiểm tra giá trị trả về. Nếu cấp phát bộ nhớ thất bại, chương trình vẫn có thể chạy tiếp với dữ liệu chưa khởi tạo đúng.

### Hướng sửa
- Kiểm tra kết quả trả về của:
  - `sa_init`,
  - `suba_init`,
  - `cca_init`,
  - `sca_init`.
- Nếu hàm nào thất bại, in thông báo lỗi, giải phóng các mảng đã khởi tạo trước đó rồi thoát chương trình.
- Việc này giúp chương trình an toàn hơn và xử lý lỗi bộ nhớ rõ ràng hơn.

---

## 19. Tạo thư mục `report/` và `screenshots/`

### Vấn đề
README có thể nhắc đến báo cáo và ảnh chụp màn hình demo, nhưng Git không lưu thư mục rỗng. Nếu repo không có hai thư mục này, phần bàn giao nhìn sẽ thiếu.

### Hướng sửa
- Tạo thư mục `report/` và thêm file `README.md` hoặc `.gitkeep`.
- Tạo thư mục `screenshots/` và thêm file `README.md` hoặc `.gitkeep`.
- Trong file placeholder, ghi ngắn gọn thư mục dùng để lưu báo cáo và ảnh chụp demo.
- Nếu nhóm không nộp hai phần này thì cần chỉnh README cho khớp, tránh README nói có nhưng repo không có.

---

## Thứ tự ưu tiên nên sửa

1. Rút gọn `ui.h`, chỉ để lại API giao diện cần công khai.
2. Chuẩn hóa API trong các module `student`, `subject`, `courseclass`, `score`, `gpa`, `sort`, `search`.
3. Sửa `ui.c` để gọi các module thay vì tự xử lý logic nghiệp vụ.
4. Gộp công thức tính điểm về `score.c`.
5. Bổ sung GPA hệ 10, GPA hệ 4 và xếp loại học lực trong `gpa.c`.
6. Bổ sung hiển thị GPA và học lực trong bảng điểm sinh viên.
7. Bổ sung sắp xếp theo MSSV, họ tên, GPA hệ 10 và gắn vào menu sinh viên.
8. Chuyển logic tìm kiếm sang `search.c`.
9. Sửa `fileio.c` để tự tính lại điểm tổng kết và điểm hệ 4 khi load điểm.
10. Sửa `test_fileio.c`, chạy lại test và cập nhật `docs/test_note.md`.
11. Sửa `Makefile`, `main.c`, tạo `report/` và `screenshots/`.

## Kết quả mong muốn sau khi sửa

- `ui.c` ngắn hơn, chỉ còn vai trò giao diện và điều phối.
- `ui.h` gọn, không khai báo các hàm nội bộ không cần thiết.
- Các module nghiệp vụ có vai trò thật, không còn là file tồn tại hình thức.
- Code khớp hơn với cấu trúc và yêu cầu trong README.
- Chức năng bắt buộc về GPA, xếp loại, tìm kiếm, sắp xếp và báo cáo được gọi thật từ menu.
- Test build được và tài liệu test phản ánh kết quả thật.
