#Makefile cho dự án QLSV_MI3310
#Chạy các lệnh make trong thư mục source/
#Ghi chú về môi trường:
# - Trên Linux/macOS hoặc Git Bash/MSYS2: chạy file bằng ./ten_file
# - Trên Windows CMD/PowerShell: có thể chạy trực tiếp ten_file.exe
# - Lệnh xóa file cũng khác nhau: Linux/macOS dùng rm -f, Windows dùng del

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

#File thực thi được đặt ở thư mục gốc của repo để chương trình có thể làm việc với thư mục data/
MAIN_EXE = ../qlsv.exe
TEST_EXE = ../test_fileio.exe

#Danh sách file nguồn của chương trình chính
SRC_MAIN = arrays.c fileio.c \
           student.c subject.c courseclass.c score.c \
           gpa.c sort.c search.c \
           ui.c main.c

#Danh sách file nguồn dùng cho kiểm thử File I/O, score.c được đưa vào vì fileio.c sử dụng hàm tính DiemTK và quy đổi điểm hệ 4
SRC_TEST = arrays.c fileio.c score.c test_fileio.c

#Một số lệnh chạy/xóa file khác nhau giữa Windows và Linux/macOS
ifeq ($(OS),Windows_NT)
	RUN_TEST = cd .. && test_fileio.exe
	CLEAN_CMD = del /Q ..\qlsv.exe ..\test_fileio.exe 2>nul
else
	RUN_TEST = cd .. && ./test_fileio.exe
	CLEAN_CMD = rm -f $(MAIN_EXE) $(TEST_EXE)
endif

#Build chương trình chính
all:
	$(CC) $(CFLAGS) $(SRC_MAIN) -o $(MAIN_EXE)
	@echo "Build thanh cong. Chay ../qlsv.exe de mo chuong trinh."

#Build và chạy bộ kiểm thử File I/O
test:
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(TEST_EXE)
	$(RUN_TEST)

#Xóa các file build cũ
clean:
	-$(CLEAN_CMD)
	@echo "Da don dep file build."

.PHONY: all test clean
