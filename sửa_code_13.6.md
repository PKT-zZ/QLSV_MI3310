# Tong hop loi can sua va huong rut gon ui.c/ui.h

## Ket luan kien truc

Hien tai `ui.c` dang om qua nhieu viec: menu, nhap/xuat, validate, CRUD, kiem tra rang buoc, tim kiem, sap xep, tinh diem, GPA va bao cao. Huong sua nen chon la: `ui.c` chi giu vai tro giao dien console, con nghiep vu chuyen ve cac module dung theo ke hoach trong README.

## Muc tieu sau khi sua

- `ui.c`: chi hien thi menu, doc input, in ket qua, goi ham tu module khac.
- `ui.h`: chi khai bao cac ham UI that su can goi tu ngoai, chu yeu la `showMainMenu`.
- `student/subject/courseclass/score/gpa/sort/search`: chua logic nghiep vu, tim kiem, sap xep, tinh diem va tinh GPA.
- `arrays.c`: chi giu vai tro mang dong co ban.
- `fileio.c`: chi doc/ghi file va kiem tra loi file, khong nen lap lai cong thuc diem neu `score.c` da co.

---

## 1. Rut gon `ui.h`

### Loi hien tai
`ui.h` dang khai bao qua nhieu ham noi bo nhu `displayStudents`, `readLine`, `readInt`, `validateMSSV`, `validateScore`, `validateDate`. Nhung cac ham nay chu yeu chi phuc vu noi bo `ui.c`, khong nen dua het ra header.

### Huong sua
Rut gon `ui.h` chi con:
- `#pragma once`
- include cac kieu du lieu can thiet
- prototype `showMainMenu(...)`

Cac ham nhap lieu, validate, display neu chi dung trong `ui.c` thi de `static` trong `ui.c`, khong khai bao trong `ui.h`.

---

## 2. Rut gon `ui.c`

### Loi hien tai
`ui.c` dang tu lam CRUD va goi truc tiep `sa_find`, `sa_add`, `suba_find`, `cca_find`, `sca_find`, v.v. Nhu vay cac module `student.c`, `subject.c`, `courseclass.c`, `score.c`, `gpa.c`, `sort.c`, `search.c` bi giam vai tro hoac thanh dead code.

### Huong sua
`ui.c` chi nen:
- hien thi menu
- doc input tu ban phim
- goi ham nghiep vu tu module tuong ung
- in thong bao thanh cong/that bai
- in bang ket qua

Khong nen de `ui.c` tu xu ly quy tac xoa, tim kiem, tinh diem, GPA, sap xep.

---

## 3. Chuyen logic sinh vien sang `student.c/student.h`

### Loi hien tai
Cac ham trong UI nhu them/sua/xoa sinh vien dang tu kiem tra trung MSSV, sua struct, xoa array va kiem tra sinh vien co diem hay khong.

### Huong sua
Chuyen sang `student.c/student.h` cac ham:
- `findStudentRecord`
- `addStudentRecord`
- `updateStudentRecord`
- `deleteStudentRecord`
- `studentHasScore`
- `validateMSSV` neu muon tach khoi UI

Sau do trong `ui.c`, cac ham `addStudentUI`, `editStudentUI`, `deleteStudentUI` chi doc input va goi cac ham tren.

---

## 4. Chuyen logic mon hoc sang `subject.c/subject.h`

### Loi hien tai
`ui.c` dang tu them/sua/xoa mon hoc, tu kiem tra trung MaHP, tu kiem tra mon hoc co dang duoc lop hoc phan su dung hay khong.

### Huong sua
Chuyen sang `subject.c/subject.h` cac ham:
- `findSubjectRecord`
- `addSubjectRecord`
- `updateSubjectRecord`
- `deleteSubjectRecord`
- `subjectIsUsed`
- validate MaHP va so tin chi neu can

Trong `ui.c`, menu mon hoc chi doc input va goi ham tu `subject.c`.

---

## 5. Chuyen logic lop hoc phan sang `courseclass.c/courseclass.h`

### Loi hien tai
`ui.c` dang tu them/sua/xoa lop hoc phan, tu kiem tra MaLHP trung, MaHP co ton tai, hoc ky/nam hoc hop le, va lop co diem hay khong.

### Huong sua
Chuyen sang `courseclass.c/courseclass.h` cac ham:
- `findCourseClassRecord`
- `addCourseClassRecord`
- `updateCourseClassRecord`
- `deleteCourseClassRecord`
- `classHasScore`
- validate MaLHP, hoc ky, nam hoc

Trong `ui.c`, menu lop hoc phan chi nhap du lieu va goi ham tu `courseclass.c`.

---

## 6. Chuyen logic diem sang `score.c/score.h`

### Loi hien tai
`ui.c` dang tu tinh `DiemTK`, tu quy doi `DiemHe4`, tu kiem tra MSSV/MaLHP ton tai va tu them/cap nhat/xoa diem. Trong khi `score.c` da co/nen co cac ham tinh diem rieng.

### Huong sua
Chuyen sang `score.c/score.h` cac ham:
- `calculateDiemTK`
- `convertToHe4`
- `addScoreRecord`
- `updateScoreRecord`
- `deleteScoreRecord`
- `validateScore`
- kiem tra MSSV ton tai
- kiem tra MaLHP ton tai
- kiem tra trung khoa kep `(MSSV, MaLHP)`

Trong `ui.c`, khi them/cap nhat diem chi doc `DiemQT`, `DiemCK`, roi goi ham tu `score.c`.

---

## 7. Bo trung lap cong thuc diem

### Loi hien tai
Dang co nguy co lap logic: `ui.c` co `calcDiemTK`/`quyDoiHe4`, con `score.c` co `calculateDiemTK`/`convertToHe4`.

### Huong sua
Chi giu mot ban trong `score.c/score.h`. Xoa hoac ngung dung ban trong `ui.c`. Moi noi can tinh diem, gom ca `ui.c` va `fileio.c`, deu goi `calculateDiemTK` va `convertToHe4`.

---

## 8. Bo sung GPA he 10 va GPA he 4 trong `gpa.c/gpa.h`

### Loi hien tai
README yeu cau tinh GPA he 10, co the quy doi he 4 va xep loai hoc luc, nhung phan nay chua du ro neu chua co ham dung chung.

### Huong sua
Trong `gpa.c/gpa.h`, bo sung:
- `calculateStudentGPA10`
- `calculateStudentGPA4`

Cong thuc:
- `GPA10 = tong(DiemTK * SoTinChi) / tong(SoTinChi)`
- `GPA4 = tong(DiemHe4 * SoTinChi) / tong(SoTinChi)`

Ham GPA phai duyet `scores`, tim `CourseClass` theo `MaLHP`, sau do tim `Subject` theo `MaHP` de lay `SoTinChi`.

---

## 9. Bo sung xep loai hoc luc trong `gpa.c/gpa.h`

### Loi hien tai
Chua co/hoac chua tich hop xep loai hoc luc theo diem trung binh.

### Huong sua
Viet ham `classifyAcademicByGPA10(float gpa10)` trong `gpa.c/gpa.h`.

Moc de xuat:
- `>= 9.0`: Xuat sac
- `>= 8.0`: Gioi
- `>= 7.0`: Kha
- `>= 5.0`: Trung binh
- `< 5.0`: Yeu

---

## 10. Sua bang diem sinh vien trong `ui.c`

### Loi hien tai
`showStudentScoreCard` moi in tung mon, chua tong ket GPA10, GPA4 va hoc luc.

### Huong sua
Giu ham in bang diem trong `ui.c`, nhung sau khi in danh sach diem thi goi:
- `calculateStudentGPA10`
- `calculateStudentGPA4`
- `classifyAcademicByGPA10`

Sau do in them 3 dong tong ket:
- GPA he 10
- GPA he 4
- Hoc luc

---

## 11. Chuyen tim kiem sang `search.c/search.h`

### Loi hien tai
`ui.c` dang tu lap qua danh sach de tim sinh vien, mon hoc, lop hoc phan. Nhung README yeu cau tu cai Linear Search, nen nen co module tim kiem ro rang.

### Huong sua
Chuyen sang `search.c/search.h` cac ham:
- tim sinh vien theo MSSV
- tim sinh vien theo ho ten
- tim sinh vien theo lop
- tim mon hoc theo MaHP
- tim mon hoc theo ten
- tim lop hoc phan theo MaLHP
- tim diem theo MSSV/MaLHP neu can

`ui.c` chi nhan tu khoa, goi ham search va in ket qua.

---

## 12. Bo sung sap xep vao `sort.c/sort.h`

### Loi hien tai
README yeu cau sap xep danh sach sinh vien theo MSSV, ho ten hoac diem trung binh. Neu menu sinh vien chua co chuc nang nay thi chua dat du README.

### Huong sua
Trong `sort.c/sort.h`, can co:
- `sortStudentByMSSV`
- `sortStudentByName`
- `sortStudentByGPA10`

Chi can Bubble Sort hoac Selection Sort. Khong can Quick Sort vi do la phan mo rong.

---

## 13. Them menu sap xep sinh vien trong `ui.c`

### Loi hien tai
Neu `showStudentMenu` chua co muc sap xep thi ham sort co ton tai cung khong dung duoc trong chuong trinh.

### Huong sua
Trong `showStudentMenu`, them muc:
- sap xep theo MSSV
- sap xep theo ho ten
- sap xep theo diem trung binh/GPA10

Khi nguoi dung chon, `ui.c` goi ham tu `sort.c`, sau do in lai danh sach sinh vien.

---

## 14. Sua `fileio.c` de dung lai cong thuc diem trong `score.c`

### Loi hien tai
Khi doc `scores.txt`, chuong trinh co the tin vao `DiemTK` va `DiemHe4` trong file. Neu file co diem tong ket sai cong thuc, du lieu van co the bi load sai.

### Huong sua
Trong `fileio.c`, sau khi doc `DiemQT` va `DiemCK`, nen tinh lai:
- `DiemTK = calculateDiemTK(DiemQT, DiemCK)`
- `DiemHe4 = convertToHe4(DiemTK)`

Co the canh bao neu gia tri trong file khong khop, nhung du lieu luu vao struct nen theo cong thuc tu `score.c`.

---

## 15. Sua `test_fileio.c`

### Loi hien tai
`test_fileio.c` goi `feq()` nhung chua dinh nghia, co the gay loi link `undefined reference to feq`.

### Huong sua
Them ham `feq(float a, float b)` de so sanh so thuc voi epsilon, tan dung `f_abs` neu da co. Sau do chay lai `make test`.

---

## 16. Cap nhat `docs/test_note.md`

### Loi hien tai
Tai lieu test co the ghi so PASS/FAIL cu, khong con gia tri neu test truoc do chua build duoc.

### Huong sua
Sau khi sua test, chay lai:
- `make clean`
- `make all`
- `make test`

Ghi lai dung so PASS/FAIL that vao `docs/test_note.md`.

---

## 17. Sua `Makefile`

### Loi hien tai
`make clean` dung `del /Q`, chi hop Windows CMD va khong phu hop neu README noi co the chay tren Linux/macOS.

### Huong sua
Doi `clean` sang cach cross-platform hon, hoac tach theo OS:
- Windows dung `del /Q`
- Linux/macOS/Git Bash dung `rm -f`

---

## 18. Sua `main.c`

### Loi hien tai
`main.c` goi cac ham init mang dong nhung chua kiem tra gia tri tra ve. Neu malloc that bai, chuong trinh co the tiep tuc voi mang chua khoi tao dung.

### Huong sua
Kiem tra lan luot:
- `sa_init`
- `suba_init`
- `cca_init`
- `sca_init`

Neu ham nao tra ve `0`, in thong bao loi, giai phong cac mang da khoi tao truoc do va thoat chuong trinh.

---

## 19. Tao thu muc `report/` va `screenshots/`

### Loi hien tai
README co nhac san pham ban giao lien quan bao cao va anh chup man hinh, nhung Git khong luu thu muc rong.

### Huong sua
Tao:
- `report/README.md`
- `screenshots/README.md`

De giu thu muc trong repo va giai thich muc dich tung thu muc.

---

## Thu tu uu tien nen lam

1. Rut gon `ui.h`, chi de API UI that su can cong khai.
2. Tao/chuan hoa API trong `student/subject/courseclass/score/gpa/sort/search`.
3. Sua `ui.c` de goi cac module thay vi tu xu ly logic.
4. Bo sung GPA10, GPA4, xep loai hoc luc.
5. Bo sung sort theo MSSV, ho ten, GPA10 va gan vao menu sinh vien.
6. Sua bang diem sinh vien de hien GPA va hoc luc.
7. Gop cong thuc diem ve `score.c`, de `ui.c` va `fileio.c` dung chung.
8. Sua `test_fileio.c`, chay lai test va cap nhat `docs/test_note.md`.
9. Sua Makefile, main.c va tao thu muc placeholder.

## Ket qua mong muon sau khi sua

- `ui.c` ngan hon, chi con giao dien va dieu phoi.
- `ui.h` gon, khong phoi bay cac ham noi bo.
- Cac module nghiep vu co vai tro that, khong con la file trang tri.
- Code khop hon voi README.
- Chuc nang bat buoc ve GPA, xep loai, tim kiem, sap xep va bao cao duoc goi that tu menu.
- Test build duoc va tai lieu test phan anh ket qua that.
