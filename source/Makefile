#Makefile cho QLSV_MI3310
#Mở terminal ở thư mục/source rồi mới gõ lệnh

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

#Build và chạy luôn test_fileio.c
#Đẩy file exe ra ngoài thư mục gốc để code đọc được folder data/
test:
	$(CC) $(CFLAGS) arrays.c fileio.c test_fileio.c -o ../test_fileio.exe
	cd .. && test_fileio.exe

#Build chương trình chính
all:
	$(CC) $(CFLAGS) \
		arrays.c fileio.c \
		student.c subject.c courseclass.c score.c \
		gpa.c sort.c search.c \
		ui.c main.c \
		-o ../qlsv.exe
	@echo "Build thanh cong! Hay go ..\qlsv.exe de chay"

#Xóa mấy file exe cũ để build lại từ đầu
#Nếu file chưa có thì terminal không báo lỗi
clean:
	del /Q ..\qlsv.exe ..\test_fileio.exe 2>nul
	@echo "Da don dep file build rac."

.PHONY: test all clean