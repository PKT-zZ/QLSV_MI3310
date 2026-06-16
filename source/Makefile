#Chạy các lệnh make trong thư mục source/
#Trên Linux/macOS cần ./ trước tên file khi chạy, Windows thì không

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

#File thực thi đặt ở thư mục gốc để chương trình đọc được thư mục data/
MAIN_EXE = ../qlsv.exe
TEST_EXE = ../test_fileio.exe

#Danh sách file nguồn của chương trình chính
SRC_MAIN = arrays.c fileio.c \
           student.c subject.c courseclass.c score.c \
           gpa.c sort.c search.c \
           ui.c main.c

#Danh sách file nguồn cho integration test đọc/ghi dữ liệu
SRC_TEST = arrays.c fileio.c score.c test_fileio.c

ifeq ($(OS),Windows_NT)
	DOTSLASH =
	CLEAN_CMD = del /Q ..\*.exe 2>nul
else
	DOTSLASH = ./
	CLEAN_CMD = rm -f ../*.exe
endif

#Build chương trình chính
all:
	$(CC) $(CFLAGS) $(SRC_MAIN) -o $(MAIN_EXE)
	@echo "Build thành công. Chạy ../qlsv.exe để mở chương trình."

#Integration test: đọc/ghi dữ liệu với file trong data/
test:
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(TEST_EXE)
	cd .. && $(DOTSLASH)test_fileio.exe

#Unit test: từng module riêng lẻ, không đụng đến data/
test_types:
	$(CC) $(CFLAGS) test_types.c -o ../test_types.exe
	cd .. && $(DOTSLASH)test_types.exe

test_arrays:
	$(CC) $(CFLAGS) arrays.c test_arrays.c -o ../test_arrays.exe
	cd .. && $(DOTSLASH)test_arrays.exe

test_fileio_unit:
	$(CC) $(CFLAGS) arrays.c fileio.c score.c test_fileio_unit.c -o ../test_fileio_unit.exe
	cd .. && $(DOTSLASH)test_fileio_unit.exe

test_gpa:
	$(CC) $(CFLAGS) arrays.c gpa.c test_gpa.c -o ../test_gpa.exe
	cd .. && $(DOTSLASH)test_gpa.exe

unit_test: test_types test_arrays test_fileio_unit test_gpa

#Xóa file build cũ
clean:
	-$(CLEAN_CMD)
	@echo "Đã dọn dẹp."

.PHONY: all test test_types test_arrays test_fileio_unit test_gpa unit_test clean
