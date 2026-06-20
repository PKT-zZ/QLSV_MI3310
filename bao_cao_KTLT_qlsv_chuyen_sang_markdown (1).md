# Báo cáo KTLT QLSV
---


<!-- Trang 1 / 102 -->

## Trang 1

Mục lục

LỜI MỞ ĐẦU

1 GIỚI THIỆU ĐỀ TÀI

11 Giới thiệu chủng ........... ko
12 Mục tiêu đề tài .......... v2
1.3 Phân chia công viéc.. 2...

2 PHAN TÍCH YÊU CAU

2.1 Yêu cầu chung.......... 0000000 ee
2.2 Yêu cầu chứcnăng ... 2... cv.
2.3 Yêu cầu phi chức năng ........... .. Q c Q cv.
2.4 Rang buộc kỹ thuật và dữ liệu............. co

3 THIẾT KẾ CHƯƠNG TRÌNH

3.1 Cấu trúc thư mục dựán ............ 00000 2 ee
3.2 Các module chnh........... va
3.3. Luồng hoạt động của chương trình ......................
3.4 Thiết kế menu console.......... Ốc TQ Q2

4 THIẾT KE DU LIEU

41 Cfaestructchnh 2... . cv va
42 Quan hệ giữa các d@lidu... va
4.3 Các file lưu trữ dữ liệu .......... va
4.4 Cơ chế doc/ghifile ........ . ca

5 CẤU TRÚC DU LIỆU VÀ THUẬT TOÁN

5.1 Mang động tự cài đặt.......... ee
5.2 Tìm kiếm tuyến tính ........ TQ ee
5.3 Sắp xếp sinh viên ......... Q2
5.4 Công thức tính điểm va GPA .......... ee

20
20
22
23

27
27


<!-- Trang 2 / 102 -->

## Trang 2

Nhóm 16 MỤC LỤC

6 CÀI ĐẶT VÀ KIEM THU
6.1 Môi trường cài đặt........... Qua va
6.2_ Các chức năng đã cài đặt............ . Q2
6.3 Dữ liệu kiểm thử ......... cv.
6.4 Bảng test case... . ga và  g  kv va
7 KET QUA THUC HIEN
71 Hàm main.......... ee
7.2 Module quản lý sinh viên............... . ca
7.3 Module quản lý môn học............... va
7.4 Module quản lý lớp hoc phan .........................
7.5 Module quản lý đểm số .............. ốc
7.6 Module đọc/ghi ñle............. Qua
7.7 Module giao diện console.............. . . La
8 KẾT LUẬN
8.1 Kết quả đạt được... Quy.
8.2 Hạn chế ......... . Q 000000  Q Q g v  v v v x v v2
8.3 Hướng phát triển ......... ee
TÀI LIỆU THAM KHẢO
PHỤ LỤC
Phụ lục A. Code hàm main ................ cv.
Phụ lục B. Một số hàm xử lý chính .........................
Phụ lục C. File dữ liệu mẫu .................. Số c
Phu lục D. Một số kết quả kểm thử ........................

ii

35
35
37
39
42

46
46
48
53
57
62
67
71

75
75
77
78

80

82


<!-- Trang 3 / 102 -->

## Trang 3

LỜI MỞ ĐẦU

"Trong quá trình học tập môn Kỹ thuật lập trình, việc vận dụng kiến thức lý thuyết
vào xây dựng một chương trình hoàn chỉnh có ý nghĩa quan trọng đối với sinh viên. Thông
qua bài tập lớn, sinh viên không chỉ rèn luyện kỹ năng lập trình bằng ngôn ngữ C ma
còn có cơ hội củng cố kiến thức về tổ chức chương trình, xử lý dữ liệu, quản lý bộ nhớ,

xây dựng cấu trúc dữ liệu và cài đặt các thuật toán cơ bản.

Xuất phát từ yêu cầu đó, nhóm chúng em lựa chọn đề tài Quản lý sinh vién dựa
theo các kiến thức có sẵn và các kiến thức từ [1, 2, 3, 4, 5, 6, 7] đã được hướng dẫn ở
trên lớp. Đây là một chương trình quản lý chạy trên giao diện console, cho phép thực
hiện các chức năng như quản lý thông tin sinh viên, quản lý môn học, quản lý lớp học
phần, nhập và cập nhật điểm số, tính điểm tổng kết, quy đổi điểm, tìm kiếm, sắp xếp và
hiển thị các báo cáo cần thiết. Dữ liệu của chương trình được lưu trữ bằng các file text,

qua đó giúp nhóm hiểu rõ hơn về quá trình đọc, ghi, kiểm tra và xử lý dữ liệu trong thực tế.

Do kiến thức và kinh nghiệm lập trình của nhóm còn hạn chế, bài làm khó tránh khỏi
những thiếu sót trong quá trình thiết kế và triển khai. Nhóm chúng em rất mong nhận
được sự góp ý của thầy để có thể hoàn thiện chương trình tốt hơn, đồng thời rút ra thêm

kinh nghiệm cho các môn học và dự án sau này.

Nhóm chúng em xin chân thành cảm ơn thầy TS. Vũ Thành Nam đã hướng dẫn, định
hướng và hỗ trợ nhóm trong quá trình thực hiện bài tập lớn này.


<!-- Trang 4 / 102 -->

## Trang 4

Chương 1

GIỚI THIỆU ĐỀ TÀI

1.1 Giới thiệu chung

Trong thực tế, việc quản lý thông tin sinh viên và điểm số là một công việc quan trọng
trong các cơ sở đào tạo. Các thông tin như mã số sinh viên, họ tên, lớp, ngày sinh, môn
học, lớp học phần và kết quả học tập cần được lưu trữ, cập nhật và tra cứu một cách
chính xác. Nếu thực hiện thủ công, quá trình này dễ phát sinh sai sót, mất thời gian và

khó tổng hợp khi số lượng dữ liệu tăng lên.

Xuất phát từ nhu cầu đó, nhóm chúng em thực hiện đề tài Quan ly sinh tiên. Day là
một chương trình được xây dựng bằng ngôn ngữ lập trình C, chạy trên giao diện console,
cho phép người dùng thực hiện các chức năng cơ bản như quản lý sinh viên, quản lý môn
học, quản lý lớp học phần, nhập và cập nhật điểm số, tìm kiếm, sắp xếp và hiển thị bảng

điểm.

Dữ liệu của chương trình được lưu trữ bằng các file text, giúp chương trình có thể đọc
di liệu khi khởi động và ghi lại dữ liệu khi người dùng thoát. Bên cạnh đó, chương trình
sử dụng các cấu trúc dữ liệu và thuật toán do nhóm tự cài đặt, phù hợp với yêu cầu của
môn học Kỹ thuật lập trình. Thông qua đề tài này, nhóm có cơ hội vận dụng kiến thức
về lập trình C, xử lý file, mảng động, tìm kiếm, sắp xếp và kiểm thử chương trình vào

một bài toán quản lý cụ thể.

1.2 Mục tiêu đề tài

Đề tài Quản ly sinh vién tập trung xây dựng một chương trình hỗ trợ quản lý các
thông tin cơ bản trong quá trình học tập của sinh viên. Chương trình cho phép lưu trữ

và xử lý dữ liệu về sinh viên, môn học, lớp học phần và điểm số. Các thao tác chính bao


<!-- Trang 5 / 102 -->

## Trang 5

Nhóm 16 CHƯƠNG 1. GIỚI THIỆU ĐỀ TÀI

gồm thêm, sửa, xóa, tìm kiếm thông tin sinh viên; quản lý danh sách môn học, lớp học

phần; nhập và cập nhật điểm cho sinh viên theo từng lớp học phần.

Bên cạnh các chức năng quản lý dữ liệu, chương trình còn hỗ trợ tính toán kết quả
học tập như điểm tổng kết, điểm quy đổi hệ 4 và điểm trung bình học tập. Ngoài ra, hệ
thống có thể hiển thị bảng điểm của từng sinh viên, bảng điểm của lép học phần, đồng
thời hỗ trợ sắp xếp danh sách sinh viên theo các tiêu chí như mã số sinh viên hoặc họ

tên.

Chương trình được xây dựng bằng ngôn ngữ lập trình C và chạy trên giao diện console.
Dữ liệu được lưu trữ trong các file text, giúp người dùng có thể lưu lại thông tin sau mỗi
lần sử dụng. Trong quá trình thực hiện, nhóm tự cài đặt các cấu trúc dữ liệu và thuật
toán cơ bản như mảng động, tìm kiếm tuyến tính và sắp xếp, nhằm đáp ứng yêu cầu của

bài tập lớn môn Kỹ thuật lập trình.

1.3 Phân chia công việc

Trong quá trình thực hiện đề tài, nhóm phan chia công việc theo từng vai trò cụ thể
nhằm đảm bảo các phần của chương trình được triển khai rõ ràng và thuận tiện cho việc

tích hợp. Bảng dưới đây trình bày phân công công việc chính của từng thành viên.

Bảng 1.1: Phân công công việc nhóm

STT | Họ và tên MSSV | Công việc chính
1 Nguyễn Khánh Toàn 202418996 | Core Data, Dynamic Array, File I/O
2 Ngo Ngoc Thai 202418984 | Business Logic, thuật toán, xử lý điểm
3 Nguyễn Vũ Quang Anh | 202418836 | Console UI, validation, kiểm thử, báo cáo

Nhìn chung, cách phân công trên giúp nhóm tách rõ các phần chính của chương trình
gồm xử lý dữ liệu, xử lý nghiệp vụ và giao diện người dùng. Qua đó, các thành viên có
thể triển khai song song, đồng thời dễ dàng phối hợp trong quá trình kiểm thử và hoàn

thiện sản phẩm.


<!-- Trang 6 / 102 -->

## Trang 6

Chương 2

PHAN TÍCH YÊU CÂU

2.1 Yêu cầu chung

Bài tập lớn yêu cầu nhóm xây dựng một chương trình quản lý hoàn chỉnh, có khả
năng thực hiện các thao tác cơ bản thông qua menu điều khiển. Người dùng có thể lựa
chọn các chức năng từ menu để thao tác với dữ liệu và chương trình chỉ kết thúc khi người

dùng chọn thoát.

Chương trình được xây dựng bằng ngôn ngữ lập trình C, chạy trên giao diện console.
Dữ liệu đầu vào va đầu ra của chương trình phải được lưu trữ bằng file text. Người dùng
có thể nhập dữ liệu từ bàn phím, sau đó dữ liệu được xử lý trong chương trình và lưu lại

xuống các file tương ứng.

Một yêu cầu quan trọng của bai tập lớn là không sử dung các cấu trúc dữ liệu nâng
cao hoặc thư viện thuật toán có sẵn. Các cau trúc dữ liệu và thuật toán sử dung trong
chương trình cần được nhóm tự cài đặt, chẳng hạn như mảng động, thuật toán tìm kiếm
và thuật toán sắp xếp. Điều này giúp nhóm vận dụng kiến thức đã học về lập trình, thiết

kế chương trình, xử lý file, kiểm thử và tổ chức mã nguồn.

Đối với đề tài “Quản lý sinh viên”, chương trình cần đáp ứng các chức năng cơ bản
như quản lý sinh viên, quản lý môn học, quản lý lớp học phần, quản lý điểm số, tìm kiếm,
sắp xếp và hiển thị báo cáo bảng điểm. Ngoài ra, chương trình cần đảm bảo dữ liệu được
lưu trữ đúng định dạng, có kiểm tra tính hợp lệ của dữ liệu nhập vào và không bị lỗi khi

người dùng nhập sai.


<!-- Trang 7 / 102 -->

## Trang 7

Nhóm 16 CHƯƠNG 2. PHÂN TÍCH YÊU CẦU

2.2 Yêu cầu chức năng

Chương trình Quản ly sinh tiên cần cung cấp các chức năng cơ bản phục vụ việc quản
lý thông tin sinh viên, môn học, lớp học phần và kết quả học tập. Các chức năng được tổ

chức thông qua giao diện menu console, giúp người dùng dễ dàng lựa chọn và thao tác.

Bảng 2.1: Các yêu cầu chức năng chính của chương trình
STT | Nhóm chức năng Mô tả yêu cầu

1 Quản lý sinh viên Thêm, sửa, xóa, tìm kiếm và hiển thị danh
sách sinh viên. Thông tin sinh viên gồm
MSSV, họ tên, lớp và ngày sinh.

2 Quản lý môn học Thêm, sửa, xóa, tìm kiếm và hiển thị danh
sách môn học. Mỗi môn học gồm mã học
phần, tên học phần và số tín chỉ.

3 Quản lý lớp học phần | Thêm, sửa, xóa, tìm kiếm và hiển thị danh
sách lớp học phần. Mỗi lớp học phần gắn với
một mã học phần tương ứng.

4_ | Quan lý điểm số Nhập và cập nhật điểm quá trình, điểm cuối
kỳ cho sinh viên theo từng lớp học phần.
Chương trình tự động tính điểm tổng kết và
điểm hệ 4.

5 Tính kết quả học tập | Tính điểm trung bình học tập theo hệ 10, hệ
4 và hỗ trợ xếp loại học lực của sinh viên.

6 Tìm kiếm và sắp xếp | Tìm kiếm sinh viên theo MSSV, họ tên hoặc
lớp; tìm kiếm môn học, lớp học phần và điểm
số theo các khóa tương ứng; sắp xếp danh
sách sinh viên theo MSSV, họ tên hoặc GPA.
7 Báo cáo, bảng điểm Hiển thị bảng điểm của một sinh viên và bảng
điểm của một lớp học phần để phục vụ việc
theo dõi kết quả học tập.

Ngoài các chức năng trên, chương trình cần kiểm tra dữ liệu đầu vào nhằm hạn chế
lỗi khi người dùng nhập sai định dạng. Các thao tác thêm, sửa, xóa dữ liệu cũng cần đảm

bảo không làm mất tính nhất quán giữa sinh viên, môn học, lớp học phần và điểm số.

2.3 Yêu cầu phi chức năng

Bên cạnh các yêu cầu chức năng, chương trình Quan ly sinh tiên cần đáp ứng một
số yêu cầu phi chức năng nhằm đảm bảo chương trình hoạt động ổn định, dễ sử dụng
và thuận tiện cho việc mở rộng, kiểm thử. Các yêu cầu này không trực tiếp mô tả một
chức năng cụ thể, nhưng có vai trò quan trọng trong việc đánh giá chất lượng của chương
trình.


<!-- Trang 8 / 102 -->

## Trang 8

Nhóm 16 CHƯƠNG 2. PHÂN TÍCH YÊU CẦU

Bảng 2.2: Các yêu cầu phi chức năng của chương trình
STT | Yêu cầu Mo tả

1 Tính dễ sử dụng Chương trình cần có menu console rõ ràng,
các lựa chọn được đánh số cụ thể, thông báo
dễ hiểu để người dùng thao tác thuận tiện.

2 | Tính ổn định Chương trình cần hạn chế lỗi khi người dùng
nhập sai dữ liệu, không bị dừng đột ngột
trong quá trình sử dụng.

3 Tính chính xác Các thao tác thêm, sửa, xóa, tìm kiếm, sắp
xếp và tính toán điểm cần cho ra kết quả
đúng theo dữ liệu đầu vào và công thức đã
quy định.

4 Tính nhất quán Dữ liệu giữa sinh viên, môn học, lớp học phần
và điểm số cần được kiểm tra liên kết hợp lý,
tránh tình trạng dữ liệu bị trùng hoặc tham
chiếu sai.

5 | Tính dễ bảo trì Mã nguồn cần được tổ chức theo module, đặt
tên hàm và biến rõ ràng, có chú thích ở những
phần xử lý quan trọng để thuận tiện cho việc
sửa lỗi và phát triển tiếp.

6 Tính lưu trữ Dữ liệu của chương trình cần được lưu trữ
trong các file text đúng định dạng, có thé
đọc lại khi chương trình khởi động và ghi lại
khi người dùng thoát.

7 Tính kiểm thử Chương trình cần có các test case để kiểm
tra những chức năng chính như thêm dữ liệu,
nhập điểm, tìm kiếm, sắp xếp, doc/ghi file và
xử lý dữ liệu sai.

Nhìn chung, các yêu cầu phi chức năng trên giúp chương trình không chi dap ứng
đúng chức năng quản lý sinh viên mà còn đảm bảo tính ổn định, rõ ràng và dễ kiểm tra.
Dây cũng là những yếu tố phù hợp với định hướng của môn K¥ thuật lập trình, trong đó
nhấn mạnh việc xây dựng chương trình có cấu trúc tốt, dễ hiểu, có khả năng phòng ngừa

lỗi và thuận tiện cho quá trình kiểm thử.


<!-- Trang 9 / 102 -->

## Trang 9

Nhóm 16 CHƯƠNG 2. PHÂN TÍCH YÊU CẦU

2.4 Rang buộc kỹ thuật và dữ liệu

Trong quá trình xây dựng chương trình Quản ly sinh uiên, nhóm cần tuân thủ một
số ràng buộc về kỹ thuật lập trình và tổ chức dữ liệu. Các ràng buộc này nhằm đảm bảo
chương trình phù hợp với yêu cầu của bài tập lớn, đồng thời giúp dữ liệu được xử lý nhất

quán và an toàn hơn.

Bảng 2.3: Các ràng buộc kỹ thuật của chương trình

STT | Rang buộc Mô tả

1 Ngôn ngữ lập trình Chương trình được xây dựng bằng ngôn ngữ C,
chạy trên giao điện console.

2 Giao diện chương trình Người dùng thao tác thông qua menu lặp, chương
trình chỉ kết thúc khi người dùng chọn chức năng
thoát.

3 Lưu trữ dữ liệu Dữ liệu được lưu trữ bằng file text, không sử
dụng cơ sở dữ liệu như MySQL, SQL Server hoặc
SQLite.

4 Cấu trúc dữ liệu Nhóm tự cài đặt cấu trúc dữ liệu mảng động để
lưu danh sách sinh viên, môn học, lớp học phần và
điểm số.

5 Thuật toán Các thuật toán tìm kiếm và sắp xếp được tự cài

đặt, không sử dụng thư viện thuật toán có sẵn.

6 Thư viện sử dụng Chỉ sử dụng các thư viện chuẩn của C như
stdio.h, stdlib.h, string.h, ctype.h.


<!-- Trang 10 / 102 -->

## Trang 10

Nhóm 16

CHƯƠNG 2. PHÂN TÍCH YÊU CẦU

Bên cạnh các ràng buộc kỹ thuật, chương trình cũng cần đảm bảo các ràng buộc về

dữ liệu để tránh sai lệch trong quá trình quản lý.

Bảng 2.4: Các ràng buộc dữ liệu của chương trình

STT | Ràng buộc Mô tả

1 Khóa chính Mã sinh viên,
không được trùng lặp trong danh sách tương ứng.

mã học phần và mã lớp học phần

2 | Diém số Điểm quá trình và điểm cuối kỳ phải nằm trong
khoảng từ 0 đến 10.

DD/MM/YYYY.

3 Dinh dạng ngày sinh | Ngày sinh của sinh viên được nhập theo định dạng

4 Quan hệ dữ liệu Mỗi lớp học phần phải gắn với một mã học phần
đã tồn tại trong danh sách môn học.

5 Ban ghi diém Mỗi ban ghi điểm phải gắn với một sinh viên và
một lớp học phần đã tồn tại. Cặp mã sinh viên và
mã lớp học phần không được trùng lặp.

6 Ràng buộc khi xóa Không cho phép xóa sinh viên nếu sinh viên đó đã
có điểm; không cho phép xóa lớp học phần nếu đã
có bản ghi điểm; không cho phép xóa môn học nếu
đang có lớp học phần sử dụng.

được chứa ký

7 Ky tự phan cách Dữ liệu trong file text sử dung ký tự | để phan
tách các trường, vì vậy nội dung nhập vào không

tự này.

Những ràng buộc trên giúp chương trình hoạt động đúng theo phạm vi đề tài, đồng

thời đảm bảo dữ liệu giữa các thành phần như sinh viên, môn học, lớp học phần và điểm

số được quản lý một cách nhất quán.


<!-- Trang 11 / 102 -->

## Trang 11

Chương 3

THIET KE CHƯƠNG TRÌNH

3.1 Cấu trúc thư mục dự án

Du án Quan lý sinh vién được tổ chức thành nhiều thư mục và file riêng biệt nhằm
giúp quá trình quản lý mã nguồn, dữ liệu, tài liệu và báo cáo được rõ ràng hơn. Thay vì
đặt toàn bộ chương trình trong một file duy nhất, nhóm chia dự án thành các nhóm file
theo từng nhiệm vu cu thể như xử lý dữ liệu, doc/ghi file, tính điểm, tìm kiếm, sắp xếp,

giao diện console và kiểm thử.

Cách tổ chức này giúp chương trình có cấu trúc dễ theo dõi, đồng thời hỗ trợ quá trình
phát triển theo nhóm. Mỗi thành viên có thể phụ trách một phần riêng mà không ảnh
hưởng quá nhiều đến các phần còn lại. Bên cạnh đó, việc tách riêng thư mục mã nguồn,
dữ liệu, ảnh minh chứng và báo cáo cũng giúp quá trình kiểm thử, sửa lỗi và hoàn thiện

sản phẩm cuối cùng được thuận tiện hơn.

Trong dự án, thư mục source/ chứa toàn bộ mã nguồn chương trình, bao gồm các file
.c, .h và Makefile. Thư mục data/ chứa các file dữ liệu dang text dùng để lưu thông tin
sinh viên, môn học, lớp học phần và điểm số. Ngoài ra, các thư mục như screenshots/,

report/ và docs/ được sử dụng để lưu ảnh minh chứng, báo cáo va tài liệu phụ trợ.

Sơ đồ dưới đây trình bày tổng quan cấu trúc thư mục của dự án, qua đó thể hiện cách

nhóm tổ chức các thành phần chính trong quá trình xây dựng chương trình.


<!-- Trang 12 / 102 -->

## Trang 12

Nhóm 16

CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

QLSV_M1I3310-main/

source/

|-- main.c

|-- types.h

|-- arrays.h

|-- arrays.c

|-- student.h

|-- student.c

|-- subject.h

|-- subject.c

|-- courseclass.h
|-- courseclass.c
|-- score.h

|-- score.c

|-- gpa.h

|-- gpa.c
|-- search.h

|-- search.c

|-- sort.h

|-- sort.c

|-- fileio.h

|-- fileio.c

|-- ui.h

|-- ui.c

|-- Makefile

|-- test_arrays.c
|-- test_fileio.c
|-- test_fileio_unit.c
|-- test_gpa.c
|-- test_types.c

data/

|-- students. txt

|-- subjects.txt

|-- course_classes.txt

|-- scores.txt

screenshots/
report/
docs/
README. md

10

Mô ta nhanh:

source/: chứa mã nguồn

và các file kiểm thử.

data/: chứa dữ liệu lưu trữ

dang file text.

screenshots/: chita anh
minh chứng kết quả chạy
chương trình.

report/: chứa báo cáo
cuối kỳ.
docs/: chứa tài liệu phụ

trợ.

README.md: mô tả dự án

và hướng dẫn sử dụng.


<!-- Trang 13 / 102 -->

## Trang 13

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

"Trong đó, thư mục source/ là phần quan trọng nhất của dự án vì chứa toàn bộ mã
nguồn chương trình. Các file trong thư mục này được chia theo từng nhóm chức năng
như định nghĩa kiểu dữ liệu, cài đặt mảng động, xử lý sinh viên, môn học, lớp học phần,
điểm số, tinh GPA, tìm kiếm, sắp xếp, đọc/ghi file và giao diện console. Ngoài ra, thư
mục này còn có một số file kiểm thử dùng để kiểm tra riêng các module quan trọng.

Thư mục data/ chứa các file dữ liệu chính của chương trình. Dữ liệu được lưu dưới
dang file text, mỗi dòng là một bản ghi và các trường được phan tách bang ký tự |. Cách
lưu trữ này giúp chương trình có thể đọc dữ liệu khi khởi động và ghi lại dữ liệu khi người
dùng thoát chương trình.

Bảng 3.1: Mô tả cấu trúc thư mục dự án
Thư mục/File Mô tả
source/ Chứa toàn bộ mã nguồn của chương trình, bao
gồm các file cài đặt .c, file khai báo .h, file kiểm
thử test_*.c và Makefile để biên dịch chương

trình.

data/ Chita các file text dùng để lưu trữ dữ liệu sinh
viên, môn học, lớp học phần và điểm số.

screenshots/ Chứa ảnh chụp màn hình kết quả chạy chương
trình, dùng làm minh chứng trong phần kiểm thử.

report/ Chứa file báo cáo cuối kỳ của nhóm.

docs/ Chứa các tài liệu phụ trợ như ghi chú kiểm thử, kế
hoạch làm việc hoặc mô tả chức năng.

README .md Mô tả tổng quan dự án, mục tiêu, chức năng, phân
công công việc và hướng dẫn build/chay chương
trình.

Mô tả các nhóm file trong thư mục source/

Các file mã nguồn trong thư mục source/ được tổ chức theo từng nhóm chức năng

cụ thể:

e Nhóm file khởi động chương trình: gồm main.c. File này là điểm bắt đầu của
chương trình, thực hiện khởi tạo dữ liệu, gọi hàm đọc file, hiển thị menu chính, lưu
dữ liệu và giải phóng bộ nhớ khi kết thúc.

e Nhóm file định nghĩa dữ liệu: gồm types.h. File này định nghĩa các struct
chính như Student, Subject, CourseClass, ScoreRecord và các kiểu mảng động

tương ứng.

e Nhóm file cẫu trúc dữ liệu: gồm arrays.h và arrays.c. Nhóm file này cài đặt

mảng động cho sinh viên, môn học, lớp học phần và điểm số.

11


<!-- Trang 14 / 102 -->

## Trang 14

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

e Nhóm file xử lý nghiệp vụ: gồm student .h/.c, subject .h/.c, courseclass.h/.

score.h/.c và gpa.h/.c. Các file này phụ trách thao tác thêm, sửa, xóa, tìm kiếm
bản ghi, xử lý điểm số và tính GPA.

e Nhóm file thuật toán: gồm search.h/.c và sort.h/.c. Nhóm file này cài đặt

chức năng tìm kiếm sinh viên và sắp xếp danh sách sinh viên.

e Nhóm file doc/ghi dữ liệu: gồm fileio.h và fileio.c. Nhóm file này phụ trách

đọc dữ liệu từ các file trong thư mục data/ và ghi dữ liệu trở lại file text.

e Nhóm file giao diện: gồm ui.h và ui.c. Nhóm file này phụ trách hiển thị menu

console, nhận dif liệu từ bàn phím, kiểm tra dit liệu đầu vào và gọi các chức năng

xử lý tương ứng.

e Nhóm file kiểm thử: gồm test_arrays.c, test_fileio.c, test_fileio_unit.c,

test_gpa.c vatest_types.c. Các file này được dùng để kiểm tra riêng từng module
quan trọng, từ đó giúp nhóm phát hiện lỗi sớm và đảm bảo chương trình hoạt động
ổn định hơn.

e File Makefile: hỗ trợ biên dịch chương trình nhanh chóng bằng lệnh make, giúp

giảm thao tác nhập lệnh biên dịch thủ công.

Việc tổ chức thư mục như trên giúp dự án có cấu trúc rõ ràng, dễ quản lý và thuận

tiện cho quá trình phát triển, kiểm thử cũng như hoàn thiện sản phẩm cuối cùng.

3.2. Các module chính

Chương trình được thiết kế theo hướng module hóa, trong đó mỗi file hoặc nhóm file

2 iv ~ . ` tax 2 2 4 ` ae ~ x ~ ox £ A
đảm nhiệm một vai trò riêng. Cách to chức nay giúp mã nguôn rõ ràng hon, hạn chế việc

tập trung toàn bộ xử lý vào một file lớn, đồng thời thuận tiện cho quá trình kiểm thử,

sửa lỗi và mở rộng chương trình.

main.c

|-- types.h : Khai bao cac kieu du lieu chinh
|-- arrays.h/.c : Cai dat mang dong cho cac kieu du lieu
|-- student .h/.c : Xu ly nghiep vu sinh vien

|-- subject.h/.c : Xu ly nghiep vu mon hoc

|-- courseclass.h/.c : Xu ly nghiep vu lop hoc phan

|-- score.h/.c : Xu ly diem so va quy doi diem he 4
|-- gpa.h/.c : Tinh GPA cua sinh vien

|-- search.h/.c : Tim kiem sinh vien

|-- sort.h/.c : Sap xep danh sach sinh vien

|-- fileio.h/.c : Doc va ghi du lieu file text

12

c,


<!-- Trang 15 / 102 -->

## Trang 15

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

|-- ui.h/.c : Giao dien console va xu ly nhap lieu

|-- test_*.c : Cac file kiem thu module
Cu thể, các module chính trong chương trình gồm:

e Module main.c: là điểm bắt đầu của chương trình. File này thực hiện khởi tạo
các mang dit liệu, gọi hàm doc dit liệu từ file, hiển thị menu chính, lưu dit liệu khi

người dùng thoát và giải phóng bộ nhớ đã cấp phát.

e Module types.h: phụ trách định nghĩa các kiểu dữ liệu chính của chương trình.
File này khai báo các struct biểu diễn sinh viên, môn học, lớp học phần và điểm
số, gồm Student, Subject, CourseClass và ScoreRecord. Ngoài ra, types.h còn
định nghĩa các kiểu mảng động tương ứng như StudentArray, SubjectArray,
CourseClassArray và ScoreArray dé sử dung thống nhất trong toàn bộ chương
trình.

e Module arrays.h/.c: cài đặt cấu trúc dữ liệu mảng động cho từng nhóm dé liệu.
Mỗi mảng động gồm con trỏ data, biến size và biến capacity. Module này cung
cấp các thao tác cơ bản như khởi tạo, thêm phần tử, lấy phần tử, cập nhật, xóa,
tìm kiếm và giải phóng bộ nhớ. Khi mang day, chương trình tự động mở rộng vùng

nhớ bằng cách tăng capacity.

e Module student.h/.c: phụ trách xử lý nghiệp vụ liên quan đến sinh viên. Module
này cung cấp các hàm thêm, cập nhật, xóa và tìm kiếm sinh viên. Các thao tác
được thực hiện thông qua StudentArray, trong đó mã số sinh viên MSSV được sử

dung làm khóa chính để xác định từng sinh viên.

e Module subject.h/.c: phụ trách xử lý nghiệp vụ liên quan đến môn hoc. Module
này cung cấp các hàm thêm, cập nhật, xóa và tìm kiếm môn học. Mỗi môn học
được xác định thông qua mã học phần MaHP. Khi thêm môn học mới, chương trình

kiểm tra mã học phần để tránh trùng lặp dữ liệu.

e Module courseclass.h/. c: phụ trách xử lý nghiệp vụ liên quan đến lớp học phần.
Module này cung cấp các hàm thêm, cập nhật, xóa và tìm kiếm lớp học phần. Khi
thêm lớp học phần mới, chương trình kiểm tra mã lớp hoc phần MaLHP để tránh
trùng lặp, đồng thời kiểm tra mã học phần MaHP có tồn tại trong danh sách môn

học hay không.

e Module score.h/.c: phụ trách xử lý điểm số của sinh viên theo từng lớp học
phần. Module này cài đặt các hàm tính điểm tổng kết, quy đổi điểm hệ 4, thêm
bản ghi điểm và cập nhật điểm. Khi thêm điểm, chương trình kiểm tra sinh viên và
lớp học phần có tồn tại hay không, đồng thời kiểm tra cặp khóa (MSSV, MaLHP) để

tránh nhập trùng điểm cho cùng một sinh viên trong cùng một lớp học phần.

13


<!-- Trang 16 / 102 -->

## Trang 16

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

Module gpa.h/.c: phụ trách tính GPA của sinh viên. Module này sử dụng dữ liệu
từ ScoreArray, CourseClassArray và SubjectArray để liên kết điểm số với lớp
học phần và môn học. Từ đó, chương trình lấy số tín chỉ tương ứng và tính GPA

theo trọng số tín chỉ dựa trên điểm hệ 4.

e Module search.h/.c: phụ trách chức năng tìm kiếm sinh viên. Module này hỗ
trợ tìm kiếm sinh viên theo mã số sinh viên và tìm kiếm sinh viên theo họ tên. Tìm
kiếm theo mã số sinh viên sử dụng khóa chính MSSV, trong khi tìm kiếm theo họ

tên sử dụng từ khóa để kiểm tra sự xuất hiện trong chuỗi họ tên.

e Module sort.h/.c: chứa các hàm sắp xếp danh sách sinh viên. Chương trình hỗ
trợ sắp xếp sinh viên theo mã số sinh viên và theo họ tên. Các hàm sắp xếp được
tự cài đặt bằng thuật toán Bubble Sort, sử dụng strcmp để so sánh chuỗi và hoán

đổi vị trí hai sinh viên khi cần thiết.

e Module fileio.h/.c: phụ trách việc đọc và ghi dữ liệu từ các file text. Module
này cài đặt các hàm đọc/ghi riêng cho sinh viên, môn học, lớp học phần và điểm
số. Ngoài ra, hai hàm 1oadA11Data và saveA11Data được sử dụng để đọc hoặc ghi
toàn bộ dữ liệu của chương trình trong một lần. Trong quá trình đọc file, chương
trình có kiểm tra các lỗi như thiếu trường, trùng khóa, điểm ngoài khoảng hợp lệ

và khóa ngoại không tồn tại.

e Module ui.h/.c: phụ trách giao diện console và xử lý tương tác với người dùng.
Module này hiển thi menu, nhận dữ liệu từ bàn phím, kiểm tra dữ liệu đầu vào, gọi
các chức năng quản lý và hiển thị kết quả. Đây là module kết nối giữa người dùng

và các module xử lý dữ liệu bên trong chương trình.

e Các file kiểm thử test_*.c: được sử dụng để kiểm tra tính đúng đắn của một số
module quan trọng. Ví dụ, test_arrays.c kiểm thử mảng động, test_fileio.c
kiểm thử đọc/ghi dữ liệu và toàn vẹn khóa ngoại, test_gpa.c kiểm thử hàm tính

GPA, còn test_types.c kiểm thử các struct dữ liệu chính.

Nhìn chung, việc chia chương trình thành các module giúp quá trình phát triển được
rõ ràng hơn. Mỗi module tập trung vào một nhiệm vụ cụ thể, nhờ đó chương trình dễ
đọc, dễ kiểm thử và dễ bảo trì hơn. Cách tổ chức này cũng giúp nhóm thuận tiện hơn khi
phân công công việc, sửa lỗi và mở rộng chức năng trong quá trình hoàn thiện bài tập

lớn.

3.2.1 Liên hệ với kỹ thuật thiết kế chương trình

Cách tổ chức chương trình của nhóm thể hiện rõ tư tưởng module hóa trong thiết kế

chương trình. Thay vì viết toàn bộ chức năng trong một file duy nhất, chương trình được

14


<!-- Trang 17 / 102 -->

## Trang 17

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

chia thành nhiều module nhỏ, mỗi module phụ trách một nhóm nhiệm vụ cụ thể. Ví dụ,
arrays.c phụ trách cấu trúc dữ liệu mảng động, fileio.c phụ trách đọc/ghi dữ liệu,

score.c phụ trách xử lý điểm số, còn ui.c phụ trách giao diện console và nhập liệu.

Cách chia này giúp bài toán lớn được tách thành các bài toán nhỏ hơn. Đây là cách
tiếp cận phù hợp với nguyên tắc thiết kế chương trình theo hướng từ trên xuống: trước
hết xác định các nhiệm vụ chính của hệ thống, sau đó tỉnh chỉnh từng nhiệm vụ thành
các hàm và module cụ thể. Nhờ đó, chương trình dễ đọc hơn, dễ phân công công việc
trong nhóm hơn và thuận tiện hơn khi kiểm thử từng phần.

Ngoài ra, việc tách phần xử lý nghiệp vụ khỏi phần giao diện cũng giúp chương trình có
tinh bao trì cao hơn. Các module như student .c, subject.c, courseclass.c và score. c
chỉ xử lý dữ liệu, trong khi ui.c chịu trách nhiệm nhập xuất và kiểm tra đầu vào. Khi
cần thay đổi giao điện hoặc bổ sung cách nhập dữ liệu mới, nhóm có thể sửa ở tầng giao

điện mà ít ảnh hưởng đến các hàm xử lý nghiệp vụ bên trong.

3.3. Luồng hoạt động của chương trình

Chương trình được thiết kế theo luồng xử lý tuần tự, bắt đầu từ hàm main. Khi chương
trình khởi động, các mảng dữ liệu chính như danh sách sinh viên, môn học, lớp học phần
và điểm số được khởi tạo trong bộ nhớ. Sau đó, chương trình đọc dữ liệu từ các file text

trong thư mục data/ và nạp vào các mảng động tương ứng.

Sau khi dữ liệu đã được nạp, chương trình hiển thi menu chính để người dùng lựa
chọn chức năng cần thực hiện. Từ menu chính, người dùng có thể chuyển đến các nhóm
chức năng như quản lý sinh viên, quản lý môn học, quản lý lớp học phần, quản lý điểm
số hoặc xem báo cáo bảng điểm. Sau mỗi thao tác, dữ liệu được cập nhật trực tiếp trong

bộ nhớ và chương trình quay lại menu để tiếp tục nhận lựa chọn mới.

Các thay đổi trong quá trình chạy chương trình chưa được ghi ngay xuống file sau
từng thao tác. Dữ liệu chỉ được lưu lại khi người dùng chọn chức năng lưu và thoát. Khi
đó, chương trình ghi toàn bộ dữ liệu hiện tại xuống các file text, giải phóng bộ nhớ đã
cấp phát và kết thúc chương trình. Luồng hoạt động tổng quát của chương trình được mô

tả trong sơ đồ dưới đây.

15


<!-- Trang 18 / 102 -->

## Trang 18

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

——— Khởi tạo Đọc dữ liệu
Bắt đầu 2 ra
mang dữ liệu

từ file text

Xử lý chức năng Người dùng Hiển thị
tương ứng chọn chức năng menu chính
pent
a YÔU Thoá
oat ` Thoát

Cập nhật dữ liệu Ghi dữ liệu

trong bộ nhớ xuống file text

Giải phóng
bộ nhớ

Kết thúc

Cụ thể, khi người dùng chọn một chức năng trong menu, chương trình sẽ chuyển đến
submenu tương ứng. Tại mỗi submenu, người dùng có thể thực hiện các thao tác như
thêm, sửa, xóa, tìm kiếm, sắp xếp hoặc hiển thị dữ liệu. Ví dụ, trong nhóm chức năng
quản lý sinh viên, người dùng có thể thêm sinh viên mới, cập nhật thông tin sinh viên,

tìm kiếm sinh viên theo mã số hoặc họ tên và sắp xếp danh sách sinh viên.

Trong quá trình xử lý, dữ liệu được thao tác trực tiếp trên các mảng động trong bộ
nhớ. Điều này giúp các thao tác thêm, sửa, xóa và tìm kiếm được thực hiện nhanh chóng
trong phiên làm việc hiện tại. Khi người dùng chọn thoát, chương trình mới ghi dữ liệu
từ bộ nhó xuống các file text để đảm bảo dữ liệu được lưu lại cho lần chạy sau.

16


<!-- Trang 19 / 102 -->

## Trang 19

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

Cách tổ chức luồng hoạt động như trên giúp chương trình đơn giản, dễ kiểm soát và
phù hợp với quy mô của bài tập lớn. Đồng thời, việc tách riêng các bước khởi tạo dữ liệu,
doc file, xử lý menu, lưu file và giải phóng bộ nhớ cũng giúp chương trình rõ rang hon

trong quá trình kiểm thử va bảo tri.

3.4 Thiết kế menu console

Chương trình sử dung giao diện console với hệ thống menu phân cấp. Người dùng thao
tác bằng cách nhập số tương ứng với chức năng cần thực hiện. Menu chính được lặp lại
trong suốt quá trình chạy chương trình và chỉ kết thúc khi người dùng chọn chức năng

lưu và thoát.

Việc thiết kế menu theo dạng phân cấp giúp chương trình đơn giản, dễ sử dụng và
phù hợp với phạm vi của bài tập lớn. Các chức năng được chia thành từng nhóm rõ ràng
như quản lý sinh viên, quản lý môn học, quản lý lớp học phần, quản lý điểm số và báo
cáo kết quả học tập. Cách chia này giúp người dùng dễ tìm chức năng cần sử dụng, đồng

thời giúp mã nguồn được tổ chức theo từng nhóm xử lý riêng.

Bên cạnh đó, thiết kế menu console cũng phù hợp với cách tổ chức module của chương
trình. Khi người dùng chọn một chức năng trên menu, module giao diện sẽ tiếp nhận lựa
chọn, kiểm tra dữ liệu nhập vào nếu cần, sau đó gọi đến các module xử lý tương ứng như

sinh viên, môn học, lớp học phần, điểm số, tìm kiếm, sắp xếp hoặc đọc/ghi file.

STUDENT MANAGEMENT SYSTEM
Quan sinh vien
Quan mon hoc
Quan lop hoc phan

Quan diem so
Bao cao / bang diem
Hien thi tat ca du lieu

0. Luu va thoat
Nhap lua chon: |

Hình 3.1: Giao diện menu chính của chương trình

17


<!-- Trang 20 / 102 -->

## Trang 20

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

MENU CHINH
-- 1. Quan ly sinh vien
|-- Hien thi danh sach sinh vien
|-- Them sinh vien
|-- Sua thong tin sinh vien
|-- Xoa sinh vien
|-- Tim kiem sinh vien

|-- Sap xep danh sach sinh vien

-- 2. Quan ly mon hoc
|-- Hien thi danh sach mon hoc
|-- Them mon hoc
|-- Sua thong tin mon hoc
|-- Xoa mon hoc

|-- Tim kiem mon hoc
-- 3. Quan ly lop hoc phan

|-- Them lop hoc phan

|-- Sua thong tin lop hoc phan
|-- Xoa lop hoc phan

|-- Tim kiem lop hoc phan

-- 4. Quan ly diem so
|-- Hien thi danh sach diem
|-- Nhap diem sinh vien
|-- Cap nhat diem sinh vien

|-- Tim kiem diem

|

|

|

|

|

|

|

|

|

|

|

|

|

|

|

|

| |-- Hien thi danh sach lop hoc phan
|

|

|

|

|

|

|

|

|

|

|

|-- 5. Bao cao / bang diem

| |-- Bang diem cua mot sinh vien
| |-- Bang diem cua mot lop hoc phan
|

|-- Tinh GPA cua sinh vien

|
|-- 6. Hien thi tat ca du lieu
|-- 0. Luu va thoat

18


<!-- Trang 21 / 102 -->

## Trang 21

Nhóm 16 CHƯƠNG 3. THIẾT KẾ CHƯƠNG TRÌNH

Ở menu chính, người dùng có thể chọn từng nhóm chức năng tương ứng. Khi chọn
một nhóm chức năng, chương trình sẽ chuyển sang menu con của nhóm đó. Sau khi thực
hiện xong thao tác, chương trình quay lại menu trước đó để người dùng tiếp tục sử dụng
hoặc chọn thoát. Cách tổ chức này tạo thành một vòng lặp xử lý rõ ràng, giúp chương

trình dễ kiểm soát trong quá trình chạy.

Trong quá trình nhập dữ liệu, chương trình thực hiện kiểm tra dữ liệu đầu vào để hạn
chế lỗi. Ví dụ, mã sinh viên, mã học phần và mã lớp học phần không được để trống; điểm
số phải nằm trong khoảng hợp lệ; ngày sinh cần đúng định dạng; học kỳ và năm học phải
hợp lý. Ngoài ra, dữ liệu nhập vào không được chứa ký tự phân cách | để tránh làm sai
định dạng khi ghi dữ liệu xuống file text.

Đối với các thao tác có liên quan đến nhiều nhóm dit liệu, chương trình cũng kiểm
tra sự tồn tại của dữ liệu liên kết. Ví dụ, khi thêm lớp học phần, mã học phần phải tồn
tại trong danh sách môn học; khi nhập điểm, mã số sinh viên và mã lớp học phần phải
hợp lệ; khi thêm bản ghi điểm, cặp (MSSV, MaLHP) không được trùng lặp. Điều này giúp
chương trình hạn chế dữ liệu sai và dam bảo tính nhất quán giữa các file lưu trữ.

Nhìn chung, thiết kế menu console của chương trình được xây dựng theo hướng đơn
giản, rõ ràng và dé thao tác. Các nhóm chức năng được phân chia hợp lý, phù hợp với yêu
cầu của đề tài Quản lý sinh vién. Đồng thời, cách thiết kế này cũng giúp quá trình kiểm

thử thuận tiện hơn vì có thể kiểm tra riêng từng nhóm chức năng trong chương trình.

19


<!-- Trang 22 / 102 -->

## Trang 22

Chương 4

THIẾT KẾ DỮ LIỆU

4.1 Các struct chính

Trong chương trình Quản lý sinh viên, dữ liệu được tổ chức thông qua các struct
trong ngôn ngữ C. Mỗi struct biểu diễn một nhóm thông tin cụ thể như sinh viên, môn
học, lớp học phần hoặc điểm số. Việc sử dụng struct giúp dữ liệu có cấu trúc rõ ràng
hơn, thuận tiện cho quá trình lưu trữ, xử lý và truyền dữ liệu giữa các module trong
chương trình.

Các struct chính của chương trình được khai báo trong file types.h. Day là file
nền tảng, được các module khác sử dụng để đảm bảo toàn bộ chương trình dùng thống
nhất một kiểu dữ liệu. Bốn struct chính được sử dụng trong chương trình gồm Student,

Subject, CourseClass và ScoreRecord.

Struct Student

typedef struct {
char mssv [12];
char hoTen[60];
char lop[20];
char birthday [12];
} Student;

Listing 4.1: Ham tim sinh vién theo MSSV

Student dùng để lưu trữ thông tin cơ bản của một sinh viên. Trong đó, mssv là mã số
sinh viên và được xem là khóa chính để phân biệt các sinh viên với nhau. Các trường còn

lại gồm hoTen, lop và birthday, tương ứng với họ tên, lớp và ngày sinh của sinh viên.

Struct Subject

20


<!-- Trang 23 / 102 -->

## Trang 23

x

°

Nhóm 16 CHƯƠNG 4. THIẾT KE DU LIEU

typedef struct {
char maHP[10];
char tenHP[80];
int soTinChi;

} Subject;

Listing 4.2: Cấu trúc dữ liệu Subject

Subject dùng để lưu thông tin của một môn học. Mỗi môn học gồm mã học phần,
tên học phần và số tín chỉ. Trường maHP được dùng làm khóa chính để quản lý và tìm
kiếm môn học. Trường soTinChi có vai trò quan trọng trong quá trình tính GPA vì điểm

trung bình được tính theo trọng số tín chỉ.

Struct CourseClass

typedef struct {
char maLHP [15];
char maHP [10];
int hocKy;
int namHoc;

} CourseClass;

Listing 4.3: Cấu trúc dữ liệu CourseClass

CourseClass biểu diễn thông tin của một lớp học phần. Mỗi lớp học phần có mã lớp
học phần riêng maLHP, đồng thời liên kết với một môn học thông qua trường maHP. Ngoài
ra, struct này còn lưu thông tin về học kỳ và năm học của lớp học phần. Nhờ đó, chương

trình có thể quản lý cùng một môn học được mở ở nhiều lớp học phần khác nhau.

Struct ScoreRecord

typedef struct {
char mssv [12];
char maLHP[15];
float diemQT;
float diemCK;
float diemTK;
float diemHe4;

} ScoreRecord;

Listing 4.4: Cau trúc dit liệu ScoreRecord

21


<!-- Trang 24 / 102 -->

## Trang 24

Nhóm 16 CHƯƠNG 4. THIẾT KẾ DŨ LIỆU

ScoreRecord dùng để lưu điểm của một sinh viên trong một lớp học phần. Mỗi bản
ghi điểm gồm mã sinh viên, mã lớp học phần, điểm quá trình, điểm cuối kỳ, điểm tổng
kết và điểm quy đổi hệ 4. Cặp mssv và maLHP được sử dụng để xác định duy nhất một
bản ghi điểm, tránh trường hợp một sinh viên có nhiều bản ghi điểm trùng nhau trong

cùng một lớp học phần.

Các struct mảng động

Bên cạnh các struct biểu diễn dữ liệu nghiệp vụ, chương trình còn định nghĩa các struct
mang động như StudentArray, SubjectArray, CourseClassArray và ScoreArray. Mỗi

mảng động gồm ba thành phần chính:
e data: con trỏ trỏ đến vùng nhớ lưu các phần tử.
e size: số lượng phần tử hiện có trong mảng.
e capacity: sức chứa hiện tai của mảng.

Các struct mảng động này là cơ sở để chương trình tự cài đặt các thao tác thêm, sửa,
xóa, tìm kiếm và giải phóng bộ nhớ cho từng nhóm dữ liệu. Nhờ đó, chương trình không
cần dùng mang tĩnh có kích thước cố định mà vẫn có thể quản lý dữ liệu linh hoạt trong
quá trình chạy.

Nhìn chung, các struct trên là nền tảng dữ liệu chính của chương trình. Chúng giúp
biểu diễn rõ các đối tượng cần quản lý, đồng thời tạo cơ sở để xây dựng mảng động, chức

năng đọc ghi file, tìm kiếm, sắp xếp, xử lý điểm số và hiển thị dữ liệu.

4.2 Quan hệ giữa các dữ liệu

Trong chương trình Quán lý sinh vién, các dt liệu không tồn tại độc lập mà có mối
quan hệ với nhau thông qua các khóa định danh. Cụ thể, sinh viên được xác định bằng
mã số sinh viên, môn học được xác định bằng mã học phần, lớp học phần được xác định

bằng mã lớp học phần và bản ghi điểm liên kết sinh viên với lớp học phần tương ứng.

Student MSSV ScoreRecord MaLHP CourseClass MaHP Subject
MSSV MSSV, MaLHP MaLHP, MaHP MaHP

Quan hệ giữa các dit liệu có thể mô tả như sau:

e Sinh viên và điểm số: mỗi sinh viên có thể có nhiều bản ghi điểm khác nhau.
Trường MSSV trong ScoreRecord dùng để liên kết bản ghi điểm với sinh viên tương

ứng.

22


<!-- Trang 25 / 102 -->

## Trang 25

Nhóm 16 CHƯƠNG 4. THIẾT KE DU LIEU

e Môn học và lớp học phần: mỗi môn học có thể được mở thành nhiều lớp học
phần. Trường MaHP trong CourseClass dùng để xác định lớp học phần đó thuộc

môn học nào.

e Lớp học phần và điểm số: mỗi lớp học phần có thể có nhiều sinh viên tham gia
và có nhiều bản ghi điểm. Trường MaLHP trong ScoreRecord dùng để liên kết điểm

số với lớp học phần tương ứng.

e Bản ghi điểm: một bản ghi điểm được xác định duy nhất bởi cặp MSSV và MaLHP.
Diéu này đảm bảo một sinh viên chỉ có một bản ghi điểm trong cùng một lớp học

phần.

Như vậy, ScoreRecord đóng vai trò là dữ liệu trung gian liên kết giữa sinh viên và lớp
học phần. Thông qua lớp học phần, chương trình có thể xác định được môn học tương
ứng và số tín chỉ cần dùng khi tính điểm trung bình. Cách thiết kế này giúp dữ liệu được
tổ chức rõ ràng, hạn chế trùng lặp và thuận tiện cho các thao tác như nhập điểm, tìm

kiếm bảng điểm, tính GPA và kiểm tra ràng buộc khi xóa dữ liệu.

Để đảm bảo tính nhất quán dữ liệu, chương trình cần kiểm tra các ràng buộc trước
khi thao tác. Cụ thể, không cho phép nhập điểm cho sinh viên hoặc lớp học phần không
tồn tại; không cho phép xóa sinh viên đã có điểm; không cho phép xóa lớp học phần đã
có bản ghi điểm; và không cho phép xóa môn học nếu vẫn còn lớp học phần đang sử dụng

môn học đó.

4.3 Các file lưu trữ dữ liệu

Dữ liệu của chương trình được lưu trữ trong các file text thuộc thư mục data/. Thay
vì sử dụng cơ sở dữ liệu, nhóm lựa chọn cách lưu dữ liệu bằng file văn ban để phù hợp

với yêu cầu của bài tập lớn và thuận tiện cho việc đọc, ghi dữ liệu bằng ngôn ngữ C.

Các file dữ liệu sử dụng định dạng đơn giản, trong đó mỗi dòng biểu diễn một bản
ghi. Các trường dữ liệu trong cùng một dòng được phân tách bằng ký tự |. Dòng đầu

tiên của mỗi file là dong tiêu đề, dùng để mô tả tên các trường dữ liệu.

data/
|-- students.txt : Luu thong tin sinh vien
|-- subjects.txt : Luu thong tin mon hoc

|-- course_classes.txt : Luu thong tin lop hoc phan

|-- scores.txt : Luu thong tin diem so

23


<!-- Trang 26 / 102 -->

## Trang 26

Nhóm 16 CHƯƠNG 4. THIẾT KẾ DŨ LIỆU

File students.txt
File students.txt dùng để lưu thông tin sinh viên. Mỗi sinh viên gồm mã số sinh

viên, họ tên, lớp và ngày sinh.

MSSV | HoTen | Lop |Birthday
202400000|Nguyen Van Toan |K69-MTI1-01 | 15/08/2006
202400001|Tran Quan Anh|K69-MI1-02] 20/03/2006

Trong đó, MSSV là khóa chính dùng để phân biệt các sinh viên. Trường này không được
để trống và không được trùng lặp.

File subjects.txt
File subjects.txt dùng để lưu thông tin môn học. Mỗi môn hoc gồm mã hoc phan,

tên học phần và số tín chỉ.

MaHP | TenHP | SoTinChi
MI3310|Ky Thuat Lap Trinh|2
MI3060|Cau Truc Du Lieu & Thuat Toan|3

"Trường MaHP là khóa chính của môn học. Mỗi môn học có một mã hoc phần riêng và

có thể được sử dụng để tạo các lớp học phần tương ứng.

File course_classes.txt
File course_classes.txt dùng để lưu thông tin lớp hoc phần. Mỗi lớp hoc phần gồm

mã lớp học phần, mã học phần, học kỳ và năm học.

MaLHP | MaHP | HocKy | NamHoc
169313 |MT3310 | 1 |2025
169307 |MT3060 | 2 |2025

"Trường MaLHP là khóa chính của lớp học phần. Trường MaHP dùng để liên kết lớp học
phần với môn học tương ứng trong file subjects. txt.

File scores.txt

File scores.txt dùng để lưu điểm của sinh viên theo từng lớp học phần. Mỗi bản ghi
điểm gồm mã sinh viên, mã lớp học phần, điểm quá trình, điểm cuối kỳ, điểm tổng kết

và điểm hệ 4.

24


<!-- Trang 27 / 102 -->

## Trang 27

Nhóm 16 CHƯƠNG 4. THIẾT KE DU LIEU

MSSV | MaLHP | Di emQT | DiemCK | DiemTK | DiemHe4
202400000 | 169313|8.0|7.5|7.7B5|3.0
202400001 | 169307 |7.0|8.0|7.50|3.0

"Trong file này, cặp MSSV và MaLHP được dùng để xác định duy nhất một bản ghi điểm.

Điều này đảm bảo một sinh viên chỉ có một bản ghi điểm trong cùng một lớp học phần.

Nhìn chung, cách tổ chức dit liệu bằng các file text giúp chương trình đơn giản, dé
kiểm tra và phù hợp với phạm vi của bài tập lớn. Khi chương trình khởi động, dữ liệu
được đọc từ các file trên vào bộ nhớ. Khi người dùng chọn thoát, dữ liệu hiện tại sẽ được

ghi lại xuống file để sử dụng cho các lần chạy tiếp theo.

4.4 Cơ chế doc/ghi file

Trong chương trình Quan ly sinh uiên, dữ liệu được lưu trữ bằng các file text trong
thư mục data/. Khi chương trình khởi động, dữ liệu được đọc từ file vào các mảng động
trong bộ nhớ. Trong quá trình sử dụng, người dùng thao tác trực tiếp với dữ liệu trong
bộ nhớ. Khi người dùng chọn thoát chương trình, toàn bộ dit liệu hiện tại sẽ được ghi lại
xuống các file text tương ứng.

Cơ chế đọc/ghi file của chương trình được chia thành hai luồng chính: luồng đọc file

và luồng ghi file.

Luéng doc file

Luông ghi file
Mở file dữ liệu s6

Mở file ở chế độ ghi

Ghi dòng tiêu đề

(Duyet từng phần tử trong mảng}

Đọc từng dòng dữ liệu
Tach trường bằng ký tự |

(Kiến tra và chuyển đổi dữ liệu)

Ả Ghi bản ghi xuống file

(Them bản ghi vào mảng đông}

Đóng file

Ỏ luồng đọc file, chương trình mở lần lượt các file dữ liệu như students .txt, subjects. txt,

(Dinh dang dit liéu theo file text

course_classes.txt va scores.txt. Sau khi bỏ qua dong tiêu đề, chương trình đọc từng
dòng, tách các trường bằng ký tự |, kiểm tra dữ liệu và đưa bản ghi hợp lệ vào mảng

động tương ứng.

25


<!-- Trang 28 / 102 -->

## Trang 28

Nhóm 16 CHƯƠNG 4. THIẾT KẾ DŨ LIỆU

Ỏ luồng ghi file, khi người dùng chọn thoát chương trình, dữ liệu trong các mảng động
sẽ được ghi lại xuống file. Chương trình ghi dòng tiêu đề trước, sau đó duyệt từng phần
tử trong mảng và ghi dữ liệu theo đúng định dạng đã quy định.

Cách tổ chức này giúp chương trình có thể lưu trữ dit liệu giữa các lần chạy mà không
cần sử dụng cơ sở dữ liệu. Đồng thời, việc đọc dữ liệu vào bộ nhớ rồi xử lý trên mang
động cũng giúp chương trình đơn giản, dễ kiểm soát và phù hợp với phạm vi của bài tập

lớn.

26


<!-- Trang 29 / 102 -->

## Trang 29

Chương 5

CẤU TRÚC DỮ LIỆU VÀ THUẬT
TOÁN

Trong học phần Kỹ thuật lập trình, khi giải quyết một bài toán thực tế, người lập
trình cần xác định rõ các dữ liệu liên quan và các thao tác cần thiết trên dữ liệu đó. Với
đề tài này, dữ liệu chính gồm sinh viên, môn học, lớp học phần và điểm số. Tương ứng
với các dit liệu đó, chương trình cần có các thao tác như thêm, sửa, xóa, tìm kiếm, sắp

xếp, đọc/ghi file và tính toán kết quả học tập.

Do đó, chương này trình bày các cấu trúc dữ liệu và thuật toán được nhóm sử dụng
trong chương trình. Các nội dung chính gồm mảng động tự cài đặt, tìm kiếm tuyến tính,
sắp xếp sinh viên và các công thức tính điểm, GPA. Đây đều là các nội dung gắn trực

tiếp với yêu cầu của bài tập lớn và kiến thức lý thuyết của học phần.

5.1 Mang động tự cài đặt

"Trong chương trình Quan ly sinh uiên, nhóm sử dung cau trúc dữ liệu mang động tự
cài đặt để lưu trữ các danh sách dữ liệu như sinh viên, môn học, lớp học phần và điểm
số. Việc sử dụng mảng động giúp chương trình có thể thay đổi kích thước lưu trữ trong
quá trình chạy, thay vì bị giới hạn bởi một kích thước cố định như mảng tĩnh.

Mỗi mảng động trong chương trình gồm ba thành phần chính:

e data: con trỏ trỏ đến vùng nhớ chứa các phần tử.

e size: số lượng phần tử hiện có trong mảng.

e capacity: sức chứa tối đa hiện tại của mảng.

Ví dụ, mảng động dùng để lưu danh sách sinh viên được khai báo như sau:

27


<!-- Trang 30 / 102 -->

## Trang 30

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

typedef struct {
Student* data;
int size;
int capacity;
} StudentArray;

Tương tự, chương trình cũng xây dựng các mang động khác như SubjectArray, CourseClassArray
và ScoreArray để lưu trữ môn học, lớp học phần và điểm số. Cách thiết kế này giúp mỗi

loại dit liệu có một mảng riêng, dé sử dụng và tránh nhầm lẫn kiểu dit liệu trong quá

trình xử lý.

Cơ chế hoạt động của mảng động được mô tả qua sơ đồ luồng sau:

Khởi tạo mang động

[cáp phát vùng nhớ ban đần|

Thêm phần tử mới

- aco Có Mở rộng vùng nhớ
size == capacity?
tăng capacity

Khong

Luu phần tử vào mảng
Tăng size

Hoàn tất thao tác

ị

Khi thêm một phần tử mới, chương trình kiểm tra xem size đã bằng capacity hay
chưa. Nếu mảng đã đầy, chương trình sẽ cấp phát lại vùng nhớ với dung lượng lớn hon,
thường là gấp đôi dung lượng cũ. Sau đó, phần tử mới được thêm vào cuối mảng và giá
trị size được tăng lên một đơn vị.

Các thao tác chính trên mảng động gồm:
e init: khởi tạo mang động và cấp phát vùng nhớ ban đầu.
e add: thêm phần tử mới vào mảng.

28


<!-- Trang 31 / 102 -->

## Trang 31

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

get: lấy phần tử theo chỉ số.

update: cập nhật thông tin phần tử.

e remove: xóa phần tử khỏi mang.

find: tìm kiếm phần tử theo khóa.
e clear: giải phóng vùng nhớ khi không còn sử dụng.

Ví dụ, với danh sách sinh viên, chương trình sử dụng các hàm như sa_init, sa_add,
sa_get, sa_remove, sa_update, sa_find và sa_clear. Các danh sách khác cũng được
xây dựng tương tự với các tiền tố khác nhau như suba_ cho môn học, cca_ cho lớp học

phần và sca_ cho điểm số.

Việc tự cài đặt mảng động giúp nhóm hiểu rõ hơn về cách quản lý bộ nhớ trong ngôn
ngữ C, đặc biệt là quá trình cấp phát, mở rộng và giải phóng vùng nhớ. Đồng thời, cau

trúc dữ liệu nay cũng đáp ứng yêu cầu của bài tập lớn là không sử dụng các thư viện cau

trúc dữ liệu có sẵn, mà phải tự xây dựng cấu trúc dữ liệu và thuật toán cần thiết.

5.2 Tìm kiếm tuyến tính

Trong chương trình Quản ly sinh tiên, thuật toán tìm kiếm tuyến tính được sử dụng
để tìm kiếm dữ liệu trong các danh sách như sinh viên, môn học, lớp học phần và điểm
số. Đây là thuật toán tìm kiếm cơ ban, phù hợp với dữ liệu được lưu trong mang động va

không yêu cầu danh sách phải được sắp xếp trước.

Ý tưởng của tìm kiếm tuyến tính là duyệt lần lượt từng phần tử trong danh sách, so
sánh khóa của phần tử hiện tại với khóa cần tìm. Nếu tìm thấy phần tử có khóa trùng
khớp, thuật toán trả về vị trí của phần tử đó trong mảng. Nếu duyệt hết danh sách mà

không tìm thấy, thuật toán trả về giá trị báo hiệu không tồn tại, thường là -1.
"Trong chương trình, thuật toán tìm kiếm tuyến tính được áp dụng cho nhiều loại dữ

liệu khác nhau. Ví dụ, tìm sinh viên theo MSSV, tìm môn hoc theo MaHP, tìm lớp hoc phần
theo MaLHP, hoặc tìm bản ghi điểm theo cặp MSSV và MaLHP.

29


<!-- Trang 32 / 102 -->

## Trang 32

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

Mã giả thuật toán
LinearSearch(A, n, key)
for i =0 ton - 1 do
if A[i].key == key then
return i

return -1
Trong do:
e A: danh sách dữ liệu cần tìm kiếm.
e n: số lượng phần tử trong danh sách.
e key: khóa cần tìm.
e Giá trị trả về là vị trí phần tử nếu tìm thấy, hoặc -1 nếu không tìm thấy.

Ví dụ, hàm tìm kiếm sinh viên theo mã số sinh viên có thể được mô tả như sau:

int sa_find(StudentArray* arr, const char* mssv) {
for (int i= 0; i < arr->size; i++) {
if (strcmp(arr->data[i].mssv, mssv) == 0) {

return i;

}
return -1;

}

Tương tự, các hàm tìm kiếm khác như suba_find, cca_find và sca_find cũng được xây
dựng theo cùng nguyên tắc. Diểm khác nhau chủ yếu nằm ở trường dữ liệu được dùng

làm khóa tìm kiếm.

Độ phức tạp thời gian của thuật toán tìm kiếm tuyến tính là O(n) trong trường hợp
xâu nhất, khi phần tử cần tìm nằm ở cuối danh sách hoặc không tồn tại trong danh sách.
Độ phức tạp bộ nhớ là O(1) vì thuật toán chỉ sử dụng một số biến phụ và không cần cấp

phát thêm vùng nhớ đáng kể.

Mặc dù tìm kiếm tuyến tính không phải là thuật toán tối ưu nhất với dữ liệu lớn,
nhưng thuật toán này đơn giản, dé cài đặt và phù hợp với phạm vi của bài tập lớn. Ngoài
ra, vì danh sách dữ liệu trong chương trình không phải lúc nào cũng được sắp xếp, tìm
kiếm tuyến tính là lựa chọn phù hợp để đảm bảo chương trình có thể tìm kiếm chính xác

trong mọi trường hợp.

30


<!-- Trang 33 / 102 -->

## Trang 33

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

5.3 Sắp xếp sinh viên

Trong chương trình Quản lý sinh vién, chức năng sắp xếp được sử dung để sắp xếp
danh sách sinh viên theo một tiêu chí nhất định, giúp việc tra cứu và hiển thị dữ liệu
trở nên thuận tiện hơn. Chương trình hỗ trợ sắp xếp sinh viên theo mã số sinh viên hoặc
theo họ tên.

Chương trình hỗ trợ sắp xếp danh sách sinh viên theo ba tiêu chí: MSSV, họ tên và
GPA. Việc sắp xếp theo MSSV và họ tên được thực hiện bằng cách so sánh chuỗi thông
qua hàm stremp. Đối với sắp xếp theo GPA, chương trình tính GPA hệ 10 của từng sinh

viên, sau đó sắp xếp theo thứ tự giảm dần để sinh viên có GPA cao hơn đứng trước.

Thuật toán được sử dụng là Bubble Sort. Day là thuật toán đơn giản, dễ cài đặt va
phù hợp với quy mô dữ liệu nhỏ của bài tập lớn. Mặc dù Bubble Sort chưa tối ưu với dữ
liệu lớn do độ phức tạp trung bình và xấu là O(n), thuật toán này giúp thể hiện rõ quá
trình so sánh và hoán đổi phần tử, phù hợp với mục tiêu rèn luyện kỹ thuật lập trình cơ

bản.

Mã giả thuật toán
BubbleSort (A, n)
for i = 0 to n - 2 do
for ] =0 ton- 1 - 2 do
if A[j] > A[j + 1] then
swap(A[j], A[] + 1])
Trong chương trình, khi sắp xếp theo mã số sinh viên, khóa so sánh là trường mssv. Hai

sinh viên liền kề sẽ được so sánh theo mã số sinh viên, nếu sinh viên đứng trước có mã

lớn hơn sinh viên đứng sau thì chương trình thực hiện đổi chỗ.

if  (strcmp(students->data[j].mssv,
students->data[j + 1].mssv) > 0) {
swap(students->data[j], students->data[j + 1]);

31


<!-- Trang 34 / 102 -->

## Trang 34

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

Tương tự, khi sắp xếp theo họ tên, chương trình sử dụng trường hoTen làm khóa so
sánh. Việc so sánh chuỗi được thực hiện bằng hàm strcmp. Nếu tên của sinh viên đứng
trước lớn hơn tên của sinh viên đứng sau theo thứ tự từ điển, hai phần tử sẽ được hoán

đổi vị trí.

if (strcmp(students->data[j].hoTen,
students->data[j + 1].hoTen) > 0) {
swap(students->data[j], students->data[j + 1]);

Các thao tác sắp xếp được cài đặt trong module sort .h/.c. Module này cung cấp các
hàm như sortStudentByMSSV va sortStudentByName. Khi người dùng chọn chức năng
sắp xếp trong menu quản lý sinh viên, chương trình sẽ gọi hàm tương ứng và hiển thị lại

danh sách sinh viên sau khi sắp xếp.

D6 phức tạp thời gian của Bubble Sort là O(n?) trong trường hợp trung bình và xấu
nhất, với là số lượng sinh viên trong danh sách. Độ phức tạp bộ nhớ là O(1) vì thuật

toán chỉ sử dụng một biến tạm để hoán đổi hai phần tử.

Mặc dù Bubble Sort không phải là thuật toán tối ưu cho dữ liệu lớn, nhưng thuật
toán này có ưu điểm là đơn giản, dễ hiểu và dễ cài đặt. Với phạm vi của bài tập lớn và
số lượng dữ liệu không quá lớn, Bubble Sort đáp ứng tốt yêu cầu tự cài đặt thuật toán
sắp xếp và phù hợp để minh họa kỹ thuật xử lý dữ liệu trong chương trình.

5.4 Công thức tính điểm và GPA

Trong chương trình Quản lý sinh tiên, điểm số của sinh viên được quản lý theo từng
lớp học phần. Mỗi bản ghi điểm gồm điểm quá trình, điểm cuối kỳ, điểm tổng kết và điểm
quy đổi hệ 4. Các công thức tính điểm được xây dựng nhằm hỗ trợ việc đánh giá kết quả

học tập của sinh viên một cách rõ ràng và thống nhất.

32


<!-- Trang 35 / 102 -->

## Trang 35

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

Tính điểm tổng kết

Điểm tổng kết của một lớp học phần được tính dựa trên điểm quá trình và điểm cuối

kỳ. Trong chương trình, hai thành phần điểm này được lấy với trọng số bằng nhau:

DiemT K = 0.5 x DiemQT + 0.5 x DiemCkK

Trong đó:

e DiemQT: điểm quá trình của sinh viên.
e DiemCk: điểm cuối kỳ của sinh viên.

e DiemTK: điểm tổng kết của lớp học phần.

Ví dụ, nếu sinh viên có điểm quá trình là 8.0 và điểm cuối kỳ là 7.5, điểm tổng kết

được tính như sau:

DiemTK = 0.5 x 8.0 +0.5 x 7.5 = 7.75

Quy đổi điểm hệ 4

Sau khi tính được điểm tổng kết, chương trình thực hiện quy đổi điểm từ thang điểm
10 sang thang điểm 4. Việc quy đổi này giúp chương trình có thể tính GPA hệ 4 cho từng
sinh viên.

Công thức quy đổi được mô tả như sau:

4.0, DiemTK > 8.5

3.5, 8.0 < DiemTK < 8.5
3.0, 7.0< DiemTK < 8.0
2.5, 6.5 < DiemTK < 7.0
2.0, 5.5 < DiemTK <6.5
1.5, 5.0< DiemTK < 5.5
1.0, 40< DiemTK < 5.0
0.0, DiemTK < 4.0

DiemHe4 =

Việc quy đổi điểm hệ 4 được thực hiện tự động sau khi chương trình nhập hoặc cập

nhật điểm quá trình và điểm cuối kỳ.

33


<!-- Trang 36 / 102 -->

## Trang 36

Nhóm 16 CHƯƠNG 5. CẤU TRÚC DỮ LIỆU VÀ THUẬT TOÁN

Tính GPA hệ 10

GPA hệ 10 của một sinh viên được tính dựa trên điểm tổng kết của các lớp học phần
mà sinh viên đó đã có điểm. Vì mỗi môn học có số tín chỉ khác nhau, chương trình cần
tính trung bình có trọng số theo số tín chỉ.

Công thức tính GPA hệ 10:

S3") DiemTK, x SoTinChi;

GPAjo = SL SoTinChi;

Trong đó:
e DiemTK,: điểm tổng kết của học phần thứ i.
e SơTinChi;: số tín chỉ của học phần thứ i.

⁄ x te gee ek
e n: số học phan sinh viên đã có điểm.

Tính GPA hệ 4

Tương tự GPA hệ 10, GPA hệ 4 được tính dựa trên điểm hệ 4 của từng học phần và
số tín chỉ tương ứng:

¡ DiemHe4; x SoTinChi;

»ã
GPA,= =
4 yx", SoTinChi;

Trong chương trình, để tinh GPA, cần liên kết dữ liệu giữa ban ghi điểm, lớp hoc phần
và môn học. Cu thể, từ ScoreRecord lấy được MaLHP, từ CourseClass xác định MaHP,

sau đó từ Subject lấy số tín chỉ của môn học tương ứng.

Nhìn chung, các công thức trên giúp chương trình không chỉ lưu trữ điểm số mà còn
có khả năng xử lý và tổng hợp kết quả học tập của sinh viên. Đây là một phần quan
trọng trong đề tài, thể hiện việc vận dụng kiến thức lập trình, cấu trúc dữ liệu và xử lý

đữ liệu có liên kết.

34


<!-- Trang 37 / 102 -->

## Trang 37

Chương 6

CÀI ĐẶT VÀ KIEM THU

6.1 Môi trường cài dat

Chương trình Quản ly sinh vién được xây dựng bằng ngôn ngữ lập trình C và chạy
trên giao diện console. Trong quá trình phát triển, nhóm sử dụng trình biên dịch GCC
để biên dịch mã nguồn, kết hợp với Makefile nhằm hỗ trợ quá trình build chương trình

nhanh chóng và thuận tiện hơn.

Môi trường cài đặt và chạy chương trình được sử dụng như sau:

e Hệ điều hành: Windows 11.

Ngôn ngữ lập trình: C.

e Trình biên dich: GCC hoặc trình biên dịch tương đương.

Công cu build: Makefile.

e Trình soạn thảo mã nguồn: Visual Studio Code.

Quản lý mã nguồn: Git và GitHub.

Lưu trữ dữ liệu: File text trong thư mục data/.

35


<!-- Trang 38 / 102 -->

## Trang 38

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

8 Q œ= [ñ @ % €

Hình 6.1: Ảnh minh họa cài đặt

cd source
make clean
make all
cd

./qlsv.exe

Listing 6.1: Các lệnh build và chạy chương trình

cd source

make clean

s|make all

cd

.\q1sv.exe

Listing 6.2: Chạy chương trình trên Windows
Khi sử dung Makefile, chương trình có thé được biên dịch bằng lệnh:

cd source

make all

Trong trường hợp không sử dung Makefile, có thể biên dịch thủ công bằng GCC bằng

cách liên kết các file mã nguồn cần thiết:
gcc main.c arrays.c fileio.c sort.c ui.c -o ../qlsv

36


<!-- Trang 39 / 102 -->

## Trang 39

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

Sau khi biên dịch, chương trình cần được chạy từ thư mục gốc của dự án để các đường
dẫn đến file dữ liệu trong thư mục data/ hoạt động chính xác. Trên Windows, chương

trình có thể được chạy bằng file thực thi qlsv.exe.

Việc sử dụng môi trường cài đặt trên giúp nhóm dễ dàng phát triển, kiểm thử và đóng
gói chương trình. Đồng thời, các công cụ như GCC, Makefile và Git cũng hỗ trợ quá trình
quản lý mã nguồn, phát hiện lỗi biên dịch và kiểm tra chương trình trong quá trình thực

hiện bài tập lón.

6.2 Cac chức năng đã cai đặt

Dựa trên yêu cầu của đề tài, chương trình Quản ly sinh tiên đã cài đặt các nhóm chức
năng chính phục vụ việc quản lý dữ liệu sinh viên, môn học, lớp học phần, điểm số và
báo cáo bảng điểm. Các chức năng được tổ chức thông qua hệ thống menu console, cho
phép người dùng lựa chọn thao tác cần thực hiện.

Chức năng quản lý sinh viên

Nhóm chức năng quản lý sinh viên cho phép người dùng thao tác với danh sách sinh

viên trong chương trình. Các chức năng đã cài đặt gồm:
e Hiển thị danh sách sinh viên.
e Thêm sinh viên mới.
e Sửa thông tin sinh viên.
e Xóa sinh viên.
e Tìm kiếm sinh viên theo mã số sinh viên, họ tên hoặc lớp.
e Sắp xếp danh sách sinh viên theo mã số sinh viên hoặc họ tên.

Khi thêm sinh viên, chương trình kiểm tra mã số sinh viên để tránh trùng lặp. Khi
xóa sinh viên, chương trình kiểm tra xem sinh viên đó đã có bản ghi điểm hay chưa. Nếu
sinh viên đã có điểm, chương trình không cho phép xóa nhằm đảm bảo tính nhất quán
di liệu.

Chức năng quản lý môn học

Chương trình hỗ trợ quản lý danh sách môn học với các thao tác cơ bản như:
e Hiển thị danh sách môn học.

37


<!-- Trang 40 / 102 -->

## Trang 40

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

e Thêm môn học mới.

Sửa thông tin môn học.

Xóa môn học.

e Tìm kiếm môn học theo mã học phần hoặc tên học phần.

Mỗi môn học được quản lý thông qua mã học phần, tên học phần và số tín chỉ. Khi
xóa môn học, chương trình kiểm tra xem môn học đó có đang được sử dụng bởi lớp học
phần nào hay không. Nếu vẫn còn lớp học phần sử dụng mã học phần đó, thao tác xóa

sẽ bị hủy.

Chức năng quản lý lớp học phần
Đối với lớp học phần, chương trình đã cài đặt các chức năng:
e Hiển thị danh sách lớp học phần.

e Thêm lớp học phần mới.

Sửa thông tin lớp học phần.

Xóa lớp học phần.
e Tìm kiếm lớp học phần theo mã lớp học phần hoặc mã học phần.

Mỗi lớp học phần được liên kết với một môn học thông qua mã học phần. Khi thêm
hoặc sửa lớp học phần, chương trình kiểm tra mã học phần có tồn tại trong danh sách
môn học hay không. Khi xóa lớp học phần, chương trình kiểm tra xem lớp đó đã có bản

ghi điểm hay chưa để tránh làm mất liên kết dữ liệu.

Chức năng quản lý điểm số

Nhóm chức năng quản lý điểm số cho phép nhập và cập nhật kết quả học tập của sinh

viên theo từng lớp học phần. Các chức năng đã cài đặt gồm:
e Hiển thị danh sách điểm.
e Nhập điểm cho sinh viên.
e Cập nhật điểm đã có.

e Tìm kiếm điểm theo mã số sinh viên, mã lớp học phần hoặc cặp mã số sinh viên và
mã lớp học phần.

Khi nhập điểm, chương trình kiểm tra sinh viên và lớp hoc phần có tồn tai hay không.

Ngoài ra, điểm quá trình và điểm cuối kỳ phải nằm trong khoảng từ 0 đến 10. Sau khi

nhập hoặc cập nhật điểm, chương trình tự động tính điểm tổng kết và điểm quy đổi hệ 4.

38


<!-- Trang 41 / 102 -->

## Trang 41

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

Chức năng báo cáo và hiến thị bảng điểm
Chương trình cũng hỗ trợ một số chức năng báo cáo cơ bản, bao gồm:
e Hiển thị bảng điểm của một sinh viên.
e Hiển thị bảng điểm của một lớp học phần.

e Hiển thị toàn bộ dữ liệu hiện có trong chương trình.

Các chức năng báo cáo giúp người dùng dễ dàng theo dõi kết quả học tập của sinh

viên và tình hình điểm số trong từng lớp học phần.

Chức năng đọc, ghi file và kiểm tra dữ liệu

Bên cạnh các chức năng quản lý chính, chương trình còn cài đặt cơ chế đọc và ghi
dữ liệu bằng file text. Khi chương trình khởi động, dữ liệu được đọc từ các file trong thu
mục data/. Khi người dùng chọn lưu và thoát, dữ liệu hiện tại trong bộ nhớ sẽ được ghi
lại xuống file.

Ngoài ra, chương trình có các hàm kiểm tra dữ liệu đầu vào như kiểm tra mã sinh
viên, ngày sinh, điểm số, số tín chỉ, học kỳ và năm học. Việc kiểm tra dữ liệu giúp hạn
chế lỗi nhập liệu và tăng tính ổn định cho chương trình.

Nhìn chung, các chức năng đã cài đặt đáp ứng được yêu cầu chính của đề tài Quan
ly sinh vién. Chương trình cho phép quản lý dữ liệu cơ bản, xử lý điểm số, tìm kiếm, sắp

xếp, hiển thị báo cáo và lưu trữ dữ liệu bằng file text.

6.3 Dữ liệu kiểm thử

Dữ liệu kiểm thử được xây dựng nhằm kiểm tra khả năng hoạt động của chương trình
trong các chức năng chính như đọc dữ liệu, hiển thị danh sách, thêm /sửa/xóa thông tin,
nhập điểm, tính điểm tổng kết, tính GPA và kiểm tra toàn vẹn dữ liệu. Toàn bộ dữ liệu
được lưu trong thư mục data/ dưới dang file text, trong đó mỗi dòng biểu diễn một bản
ghi và các trường dữ liệu được phan tách bằng ký tự |.

Chương trình sử dụng bốn file dữ liệu chính: students.txt, subjects. txt,
course_classes.txt và scores.txt. Các file này tương ứng với bốn nhóm dữ liệu quan

trọng trong hệ thống là sinh viên, môn học, lớp học phần và điểm số.

cd source
make unit_test

make test

Listing 6.3: Các lệnh chạy kiểm thử

39


<!-- Trang 42 / 102 -->

## Trang 42

Nhóm 16

CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

Bảng 6.1: Các file dữ liệu kiểm thử

File dữ liệu

Nội dung lưu trữ

Vai trò trong kiểm thử

students. txt

Thông tin sinh viên gồm
MSSV, họ tên, lớp và ngày
sinh

Kiểm tra chức năng quản
lý sinh viên, tìm kiếm sinh
viên và liên kết với bảng
điểm

subjects.txt

Thông tin môn hoc gồm mã
học phần, tên học phần và
số tín chỉ

Kiểm tra chức năng quản lý
môn học và phục vụ tính
GPA theo tín chỉ

course_classes. txt

Thông tin lớp học phần gồm
mã lớp học phần, mã học
phần, học kỳ và năm học

Kiểm tra quan hệ giữa lớp
học phần và môn học

scores.txt

Điểm của sinh viên theo lớp
học phần, gồm điểm quá
trình, điểm cuối kỳ, điểm
tổng kết và điểm hệ 4

Kiểm tra chức năng nhập
điểm, cập nhật điểm, tính
điểm tổng kết, tính GPA và
in bảng điểm

Trong bộ dữ liệu kiểm thử chính, chương trình sử dụng dữ liệu mẫu gồm 6 sinh viên,
5 môn học, 5 lớp học phần và 22 bản ghi điểm. Quy mô dữ liệu này đủ để kiểm tra các
chức năng cơ bản của chương trình, đồng thời vẫn đảm bảo dễ quan sát kết quả khi chạy

trên giao diện console.

Bảng 6.2: Quy mô dữ liệu kiểm thử chính

Nhóm dữ liệu

Số lượng bản ghi

Mục đích kiểm thử

Sinh viên

6

Kiểm tra hiển thị danh sách,
tìm kiếm, sắp xếp và liên kết
với điểm số

Môn học

on

Kiểm tra quản lý môn học
và số tín chỉ khi tính GPA

Lớp học phần

ot

Kiểm tra quan hệ giữa môn
học và lớp học phần

Bản ghi điểm

2

Kiểm tra nhập điểm, cập
nhật điểm, tính điểm tổng
kết, quy đổi hệ 4 và tính
GPA

Một số dòng dữ liệu mẫu trong file students.txt có dạng như sau:

MSSV | HoTen | Lop |Birthday

22000001|Nguyen Van An|K67-MT | 15/08/2003
22000002|Tran Thi Bich|K67-MT |20/03/2003
22000003|Le Hoang Cuong |K67-MT |05/11/2002

40


<!-- Trang 43 / 102 -->

## Trang 43

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

Một số dòng dữ liệu mẫu trong file subjects. txt:

MaNP | TenHP |SoTinChi
KTLT|Ky Thuat Lap Trinh|3
CTDL|Cau Truc Du Lieul3
CSDL|Co So Du Lieul3

Một số dòng dữ liệu mẫu trong file course_classes.txt:

MaLHP | MaHP | HocKy | NamHoc
KTLT_K67_1 |KTLT | 1|2024
CTDL_K67_2|CTDL|2| 2024
CSDL _K67 _2 | CSDL |2|2024

Một số dòng dữ liệu mẫu trong file scores.txt:

MSSV | MaLHP | DiemQT |DiemCK | DiemTK | DiemHe4
22000001 |KTLT_K67_1|8.5|7.0|7.75|3.0
22000002|KTLT_K67_1|9.0|8.5|8.75|4.0
22000003|CTDL_K67_217.017.517.2513.0

Ngoài dữ liệu hợp lệ, nhóm cũng chuẩn bị một số tình huống dữ liệu lỗi để kiểm tra
khả năng xử lý ngoại lệ của chương trình. Các tình huống này bao gồm file không tồn
tai, file rong, dòng thiếu trường, khóa chính bị trùng, điểm nằm ngoài khoảng từ 0 đến
10 và dữ liệu tham chiếu không tồn tại. Khi gặp các dòng dữ liệu không hợp lệ, chương
trình sẽ bỏ qua dòng lỗi, hiển thị cảnh báo và tiếp tục nạp các dữ liệu hợp lệ còn lại.

Các nhóm dit liệu kiểm thử được sử dụng gồm:

e Dữ liệu hợp lệ: dùng để kiểm tra các chức năng chính như hiển thị danh sách,

tìm kiếm, sắp xếp, nhập điểm và in bảng điểm.

e Dữ liệu trùng khóa: dùng để kiểm tra việc không cho phép thêm sinh viên, môn

học, lớp học phần hoặc bản ghi điểm bị trùng khóa.

e Dữ liệu sai định dạng: dùng để kiểm tra khả năng bỏ qua dòng thiếu trường
hoặc trường bắt buộc bị rỗng.

e Dữ liệu điểm không hợp lệ: dùng để kiểm tra việc từ chối điểm nhỏ hơn 0 hoặc
lớn hơn 10.

e Dữ liệu sai tham chiếu: dùng để kiểm tra các trường hợp mã sinh viên, mã học

phần hoặc mã lớp học phần không tồn tại.

41


<!-- Trang 44 / 102 -->

## Trang 44

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THU

e Dữ liệu biên: dùng để kiểm tra thao tác với mảng rỗng, chỉ số không hợp lệ và
file không tồn tại.

Nhờ có dữ liệu kiểm thử đa dạng, chương trình có thể được kiểm tra ở cả hai mức:
kiểm thử trực tiếp qua giao diện console và kiểm thử tự động bằng các file test riêng.
Điều này giúp đánh giá tốt hơn độ ổn định của các module nền tảng như mảng động,
doc/ghi file, tính điểm và tính GPA.

6.4 Bảng test case

Để đánh giá độ đúng đắn và độ ổn định của chương trình, nhóm xây dựng các test
case bao phủ các chức năng chính như quản lý sinh viên, quản lý môn học, quản lý lớp
học phần, quản lý điểm số, tìm kiếm, sắp xếp, tính GPA, doc/ghi file và kiểm tra dữ liệu
không hợp lệ. Các test case được thực hiện thông qua giao diện console kết hợp với các

file kiểm thử riêng cho module nền tang.

Quá trình kiểm thử của nhóm được xây dựng theo hướng kiểm tra từng module quan
trọng trước, sau đó kiểm tra tích hợp toàn bộ quy trình đọc/ghi dữ liệu. Cách làm này
phù hợp với nguyên tắc viết từng phần, kiểm tra từng phần và phát hiện lỗi sớm trong

quá trình lập trình.

Các unit test như test_types. c, test_arrays.c, test_fileio_unit.c và test_gpa.c
được dùng để kiểm tra riêng từng thành phần nhỏ. Sau đó, test_fileio.c được dùng để
kiểm tra tích hợp với dữ liệu thật trong thư mục data/. Nhờ đó, nhóm có thể kiểm tra cả

tính đúng đắn của cấu trúc dữ liệu, xử lý file, công thức tính GPA và toàn vẹn khóa ngoại.

Bên cạnh kiểm thử dữ liệu hợp lệ, nhóm cũng chủ động đưa vào các trường hợp sai
như file không tồn tại, dòng thiếu trường, mã sinh viên rỗng, dữ liệu trùng khóa và khóa
ngoại không hợp lệ. Đây là cách áp dụng tư tưởng lập trình phòng ngừa, giúp chương
trình không bị dừng đột ngột khi gặp dữ liệu lỗi mà có thể bỏ qua bản ghi sai và tiếp tục
xử lý các dữ liệu hợp lệ còn lại.

Bảng 6.3: Bảng test case chức năng của chương trình

Mã Chức năng Dữ liệu / tình huống | Kết quả mong đợi Kết

TC kiểm thử quả

TC01 | Thêm sinh Nhập sinh viên mới với | Sinh viên được thêm Đạt
viên hợp lệ MSSV chưa tồn tại vào danh sách

42


<!-- Trang 45 / 102 -->

## Trang 45

Nhóm 16 CHƯƠNG 6. CÀI DAT VÀ KIEM THỦ
Mã Chức năng Dữ liệu / tình huống | Kết quả mong đợi Kết
TC kiểm thử quả
TC02_ | Thêm sinh viên | Nhập MSSV đã tồn tại | Chương trình hiển thi Đạt

trùng MSSV trong danh sách sinh lỗi và không thêm dữ
viên liệu
TC03 | Cập nhật sinh | Nhập MSSV tồn tại, Thông tin sinh viên Đạt
viên sau đó sửa họ tên, lớp | được cập nhật chính xác
hoặc ngày sinh
TC04 |Xóa sinh viên |Xóa sinh viên không Sinh viên được xóa khỏi | Đạt
chưa có điểm |xuất hiện trong file danh sách
điểm
TC05 |Xóa sinh viên |Xóa sinh viên có MSSV | Chương trình thông báo | Đạt
đã có điểm đang tồn tại trong lỗi và không cho xóa
scores.txt
TC06 | Thêm môn hoc | Nhập môn học mới với | Mén học được thêm Đạt
hợp lệ mã học phần chưa tồn |thành công
tại
TC07 | Thêm môn học | Nhập mã học phần đã | Chương trình báo lỗi và | Dat
trùng mã tồn tại không thêm môn học
TC08 |Xóa môn học |Xóa môn học có mã học | Chương trình không cho | Đạt
đang được sử |phần đang được lớp học | xóa để đảm bảo toàn
dụng phần tham chiếu vẹn dit liệu
TC09 | Thêm lớp học |Nhập mã lớp học phần | Lớp học phần được Đạt
phần hợp lệ mới và mã học phần đã | thêm thành công
tồn tại
TC10 | Thêm lớp học | Nhập mã học phần Chương trình báo lỗi và | Đạt
phần sai mã không tồn tại trong không thêm lớp học
học phần danh sách môn học phần
TC11 |Xóa lớp học Xóa lớp học phần có mã | Chương trình không cho | Đạt
phần đã có đang tồn tại trong xóa lớp học phần
điểm scores.txt
TC12 | Nhập điểm hợp | Nhập MSSV, mã lớp Bản ghi điểm được Đạt
lệ học phần, điểm quá thêm; điểm tổng kết và
trình và điểm cuối kỳ | điểm hệ 4 được tính tự
hợp lệ động
TC13 |Nhập điểm Nhập điểm quá trình Chương trình báo lỗi và | Đạt
ngoài khoảng |hoặc điểm cuối kỳ nhỏ | yêu cầu nhập lại
hơn 0 hoặc lớn hơn 10

43


<!-- Trang 46 / 102 -->

## Trang 46

Nhóm 16 CHƯƠNG 6. CÀI ĐẶT VÀ KIEM THỦ
Mã Chức năng Dữ liệu / tình huống | Kết quả mong đợi Kết
TC kiểm thử quả
TC14 | Nhập điểm cho |Nhập MSSV không có | Chương trình báo lỗi va | Dat

sinh viên trong danh sách sinh không lưu điểm
không tồn tại |viên
TC15 | Nhập điểm Nhập điểm cho cùng Chương trình không tạo | Đạt
trùng một cặp MSSV và mã bản ghi trùng
lớp học phần đã tồn tại
TC16 | Cập nhật điểm | Cập nhật điểm quá Điểm được cập nhật, Đạt
trình hoặc điểm cuối kỳ | điểm tổng kết và điểm
của bản ghi đã tồn tại |hệ 4 được tính lại
TCI7 | Tính điểm Điểm quá trình là 8.5, | Điểm tổng kết bằng Đạt
tổng kết điểm cuối kỳ là 7.0 7.75 theo công thức
trung bình có trọng số
TC18 | Tính GPA Sinh viên có nhiều bản |GPA được tính theo Đạt
ghi điểm thuộc các môn | công thức trung bình có
có số tín chỉ khác nhau | trọng số tín chỉ
TC19 |Tìm kiếm sinh | Tìm sinh viên theo Chương trình hiển thị Đạt
viên MSSV hoặc họ tên đã |đúng thông tin sinh viên
tồn tại
TC20 | Tìm kiếm sinh |Nhập MSSV không có | Chương trình thông báo | Đạt
viên không tồn |trong danh sách không tìm thấy
tại
TC21 |Sắp xếp sinh |Danh sách sinh viên Danh sách được hiển thị | Dat
viên theo chưa được sắp xếp theo thứ tự tăng dần
MSSV của MSSV
TC22 |Sắp xếp sinh Danh sách sinh viên Danh sách được hiển thị | Đạt
viên theo họ chưa được sắp xếp theo | theo thứ tự họ tên
tên tên
TC23 |Hiển thị bảng |Nhập MSSV của sinh Chương trình hiển thị Đạt
điểm sinh viên |viên đã có điểm các lớp học phần, điểm
thành phần, điểm tổng
kết, điểm hệ 4 và GPA
TC24 |Hiển thị bảng |Nhập mã lớp học phần | Chương trình hiển thị Đạt
điểm lớp học |có nhiều sinh viên đã danh sách sinh viên và
phần nhập điểm điểm trong lớp học
phần đó

44


<!-- Trang 47 / 102 -->

## Trang 47

Nhóm 16 CHƯƠNG 6. CÀI DAT VÀ KIEM THỦ
Mã Chức năng Dữ liệu / tình huống | Kết quả mong đợi Kết
TC kiểm thử quả
TC25 | Đọc file không | Truyền đường dẫn file | Chương trình không bị | Dat

tồn tại dữ liệu không tồn tại crash và tạo danh sách
rỗng
TC26 | Đọc file sai File có dòng thiếu Chương trình bỏ qua Đạt
định dạng trường, khóa rỗng hoặc | dòng lỗi và tiếp tục nạp
dữ liệu không hợp lệ dữ liệu hợp lệ
TC27 | Lưu dữ liệu và | Thêm hoặc sửa dữ liệu, | Dữ liệu đã thay đổi vẫn | Đạt
nạp lại thoát chương trình, sau | được lưu và nạp lại
đó chạy lại chính xác
TC28 | Quy đổi điểm | Điểm tổng kết thuộc các | Chương trình quy đổi Đạt
hệ 4 mốc quy đổi khác nhau | đúng điểm hệ 4 theo
khoảng điểm đã cài đặt

Ngoài các test case chức năng, nhóm còn thực hiện kiểm thử tự động cho các module
nền tảng. Các file kiểm thử gồm test_types.c, test_arrays.c, test_fileio_unit.c,
test_gpa.c và test_fileio.c. Kết quả tổng hợp cho thấy toàn bộ 68 test case của các

module nền tảng đều đạt yêu cầu.

Bảng 6.4: Kết quả kiểm thử tự động các module nền tảng

File kiểm thử Loại kiểm thử | Số test case Kết quả
test_types.c Unit test 7 7/7 PASS
test_arrays.c Unit test 11 11/11 PASS
test_fileio_unit.c | Unit test 6 6/6 PASS
test_gpa.c Unit test 3 3/3 PASS
test_fileio.c Integration test | 41 41/41 PASS
Tổng cộng 68 68/68 PASS

Một số test case có xuất hiện cảnh báo trong quá trình chạy, ví dụ khi đọc file sai định
dạng hoặc gặp dữ liệu không hợp lệ. Các cảnh báo này là tình huống được tạo có chủ đích
để kiểm tra khả năng xử lý lỗi của chương trình, không phải lỗi thực tế. Kết quả kiểm
thử cho thấy chương trình xử lý tốt các trường hợp dữ liệu hợp lệ, dữ liệu trùng khóa, dữ

liệu sai định dạng, dữ liệu sai tham chiếu và các thao tác cơ bản trên mang động.

45


<!-- Trang 48 / 102 -->

## Trang 48

Chương 7

KẾT QUẢ THỰC HIỆN

7.1 Ham main

Hàm main là điểm bắt đầu của chương trình va đóng vai trò điều phối toàn bộ quá
trình hoạt động của hệ thống. Trong chương trình Quan ly sinh uiên, hàm main không
trực tiếp xử lý các nghiệp vu chi tiết như thêm sinh viên, nhập điểm hay tính GPA, mà
thực hiện nhiệm vụ khởi tạo dữ liệu, gọi các module cần thiết và quản lý vòng đời của
chương trình.

Trước hết, hàm main khai báo bốn mảng động tương ứng với bốn nhóm dữ liệu chính
của hệ thống, bao gồm danh sách sinh viên, danh sách môn học, danh sách lớp học phần
và danh sách điểm số. Các mang này lần lượt có kiểu StudentArray, SubjectArray,
CourseClassArray và ScoreArray

Sau khi khai báo, chương trình tiến hành khởi tao từng mảng động bằng các ham
sa_init, suba_init, cca_init và sca_init. Mỗi hàm khởi tạo đều được kiểm tra kết
quả trả về. Nếu quá trình cấp phát bộ nhớ thất bại, chương trình sẽ hiển thị thông báo
lỗi, giải phóng các vùng nhớ đã được cấp phát trước đó và kết thúc chương trình. Cách
xử lý này giúp hạn chế rò rỉ bộ nhớ và tăng tính an toàn cho chương trình.

Tiếp theo, hàm main gọi loadAllData để nạp dữ liệu từ các file text trong thư mục
data/. Sau khi dữ liệu đã được nạp vào bộ nhớ, chương trình gọi hàm showMainMenu để
hiển thị menu chính và cho phép người dùng thực hiện các chức năng như quản lý sinh
viên, quản lý môn học, quản lý lớp học phần, quản lý điểm số và xem báo cáo.

Khi người dùng chọn thoát chương trình, hàm saveAllData được gọi để ghi lại toàn
bộ dữ liệu hiện tại xuống các file lưu trữ. Cuối cùng, chương trình gọi các hàm sa_clear,
suba_clear, cca_clear và sca_clear để giải phóng bộ nhớ đã cấp phát động trước khi
kết thúc.

#include <stdio.h>
#include “fileio.h"

#include "ui.h"

46


<!-- Trang 49 / 102 -->

## Trang 49

10

11

12

13

14

16

17

18

19

20

21

22

23

24

26

27

28

29

33

34

35

36

37

38

40

41

42

43

45

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

int main(void)

{
StudentArray students;
SubjectArray subjects;
CourseClassArray classes;

ScoreArray scores;

if (†sa init(&students, 4)) {
printf("Loi khoi tao mang sinh vien.\n");

return 1;

if (!suba_init (&subjects, 4)) {
printf("Loi khoi tao mang mon hoc.\n");
sa_clear(&students);

return 1;

if ('cca_init(&classes, 4)) {
printf("Loi khoi tao mang lop hoc phan.\n");
sa_clear(&students) ;
suba_clear (&subjects) ;

return 1;

if (!sca_init(&scores, 4)) {
printf("Loi khoi tao mang diem.\n");
sa_clear (&students) ;
suba_clear (&subjects) ;
cca_clear (kclasseS) ;

return 1;

loadAllData(
&students,
&subjects,
&classes,

&scores

»;

showMainMenu (

47


<!-- Trang 50 / 102 -->

## Trang 50

46

aT

48

49

56

57

58

59

60

61

62

63

64

65

Nhom 16 CHUONG 7. KET QUA THUC HIEN

&students,
&subjects,
&classes,

&scores

);

saveAllData(
&students,
&subjects,
&classes,
&scores

3

sa_clear (&students) ;
suba_clear (&subjects) ;
cca_clear (kclasses) ;

sca_clear (kscores);

return 0;

Listing 7.1: Cai đặt ham main của chương trình

Có thể thấy, hàm main được thiết kế theo hướng ngắn gọn và rõ ràng. Các thao tác
xử lý chi tiết được tách sang các module riêng như fileio.c, ui.c và arrays.c. Cách
tổ chức này giúp chương trình dễ đọc, dễ kiểm thử và thuận tiện hơn khi cần mở rộng

hoặc bao trì.

7.2_ Module quản lý sinh viên

Module quản lý sinh viên là một trong những module chức năng quan trọng của
chương trình. Module này cho phép lưu trữ, hiển thị, thêm, sửa, xóa, tìm kiếm và sắp xếp
thông tin sinh viên. Trong chương trình, thông tin sinh viên được biểu diễn bởi struct

Student, được khai báo trong file types.h.

typedef struct{
char mssv[12];
char hoTen[60];
char lop[20];
char birthday [12];
} Student;

Listing 7.2: Struct Student luu thong tin sinh vién

48


<!-- Trang 51 / 102 -->

## Trang 51

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

Mỗi sinh viên gồm bốn thông tin chính: mã số sinh viên, ho tên, lớp hành chính va
ngày sinh. Trong đó, trường mssv đóng vai trò là khóa chính để phân biệt các sinh viên
với nhau. Các thao tác tìm kiếm, cập nhật hoặc xóa sinh viên đều dựa trên mã số sinh
viên này.

Danh sách sinh viên được lưu trữ bằng cấu trúc StudentArray. Dây là mảng động tự
cài đặt, gồm ba thành phần chính: con trỏ data trỏ đến vùng nhớ lưu các phần tử, biến
size lưu số lượng sinh viên hiện tại và biến capacity lưu sức chứa tối đa hiện tại của

mảng. Khi số lượng phần tử vượt quá sức chứa, mảng sẽ tự động mở rộng vùng nhớ.

typedef struct {
Student* data;
int size;
int capacity;
} StudentArray;

Listing 7.3: Cau trúc mang động Student Array

Các hàm nghiệp vu co bản của module sinh viên được cài dat trong file student .c va
khai báo trong file student .h. Các ham nay không trực tiếp nhập dữ liệu từ ban phim
mà chỉ xử lý dữ liệu đã được truyền vào. Cách tách này giúp module sinh viên độc lập

hơn với giao diện và dễ kiểm thử hơn.

Bảng 7.1: Các hàm chính trong module quản lý sinh viên

Hàm Chức năng

findStudentRecord Tim sinh vién theo MSSV. Néu tim thay,
hàm trả về con trỏ đến sinh viên tương ứng;
nếu không tìm thấy, hàm trả về NULL.

addStudentRecord Thêm sinh viên mới vào danh sách. Trước
khi thêm, hàm kiểm tra MSSV đã tồn tại
hay chưa để tránh trùng khóa chính.

updateStudentRecord Cập nhật thong tin sinh viên dựa trên MSSV.
Nếu MSSV không tồn tại, hàm trả về thất
bại.

deleteStudentRecord Xóa sinh viên khỏi danh sách dựa trên

MSSV. Nếu không tìm thấy sinh viên, hàm
không thực hiện thao tác xóa.

49


<!-- Trang 52 / 102 -->

## Trang 52

17

18

19

20

21

22

23

24

26

27

28

29

30

Nhóm 16

CHƯƠNG 7. KET QUA THUC HIỆN

Doan mã sau thể hiện các hàm xử lý nghiệp vụ chính của module quản lý sinh viên:

Student* findStudentRecord (

int

int

StudentArray* students,

const char* mssv

int idx = sa_find(students,

if(idx == -1)
return NULL;

return &students->data[idx];

addStudentRecord (
StudentArray* students,

Student s

if (sa_find(students, s.mssv)

return 0;

return sa_add(students, s);

updateStudentRecord(
StudentArray* students,

Student s

int idx =
sa_find(
students,
S.mssv

3;

if(idx == -1)

return 0;

return sa_update(

students,

mssv);

50


<!-- Trang 53 / 102 -->

## Trang 53

41

43

44

45

46

48

49

51

52

53

54

55

56

57

58

59

60

61

62

63

64

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

idx,

int deleteStudentRecord(
StudentArray* students,

const char* mssv

)
{
int idx =
sa_find(
students,
mssv
3
if(idx == -1)
return 0;
return sa_remove(
students,
idx
3ÿ
}

Listing 7.4: Các hàm nghiệp vụ chính trong module sinh viên

Trong đoạn mã trên, hàm sa_find được sử dụng để tìm vị trí của sinh viên trong
mảng theo MSSV. Nếu không tìm thấy, hàm trả về -1. Khi thêm sinh viên, chương trình
kiểm tra trước xem MSSV đã tồn tại hay chưa. Nếu MSSV bị trùng, sinh viên sẽ không
được thêm vào danh sách. Khi cập nhật hoặc xóa sinh viên, chương trình cũng tìm sinh
viên theo MSSV trước, sau đó mới gọi các hàm thao tác mảng tương ứng như sa_update

hoặc sa_remove.

Ỏ tầng giao diện, các chức năng quản lý sinh viên được tích hợp trong menu QUAN
LY SINH VIEN. Menu này cho phép người dùng thực hiện các thao tác như hiển thị danh
sách sinh viên, thêm sinh viên, sửa thông tin sinh viên, xóa sinh viên, tìm kiếm sinh viên

và sắp xếp danh sách sinh viên.


<!-- Trang 54 / 102 -->

## Trang 54

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

Bang 7.2: Cac chitc nang sinh vién trong tang giao dién
Chức nang Mô tả
Hiển thị danh sách sinh viên | In toàn bộ danh sách sinh viên gồm MSSV,
họ tên, lớp và ngày sinh.

Thêm sinh viên Nhập thông tin sinh viên mới, kiểm tra
MSSV hợp lệ, kiểm tra trùng MSSV và kiểm
tra định dạng ngày sinh.

Sửa sinh viên Tìm sinh viên theo MSSV và cho phép cập
nhật họ tên, lớp hoặc ngày sinh. Nếu người
dùng bỏ trống một trường thì giữ nguyên dữ
liệu cũ.

Xóa sinh viên Xóa sinh viên theo MSSV. Trước khi xóa,
giao diện kiểm tra sinh viên đó đã có bản ghi
điểm hay chưa. Nếu đã có điểm thì không

cho xóa.
Tìm kiếm sinh viên Hỗ trợ tìm kiếm theo MSSV, họ tên hoặc lớp.
Sắp xếp sinh viên Hỗ trợ sắp xếp danh sách sinh viên theo

MSSV, họ tên hoặc GPA.

Trong quá trình nhập dữ liệu, chương trình có các bước kiểm tra nhằm hạn chế lỗi.
MSSV phải là chuỗi chữ số và không vượt quá kích thước trường đã khai báo. Các trường
văn bản không được để trống và không được chứa ký tự |, vì day là ký tự dùng để phân
tách các trường khi lưu dữ liệu vào file text. Ngày sinh được kiểm tra theo định dạng
DD/MM/YYYY và có xét đến số ngày hợp lệ của từng tháng.

Riêng thao tác xóa sinh viên, ràng buộc toàn ven di liệu được kiểm tra tại tang giao
diện. Trước khi xóa, chương trình duyệt qua danh sách điểm để kiểm tra sinh viên đó đã
có bản ghi điểm hay chưa. Nếu sinh viên đã có điểm, chương trình sẽ thông báo lỗi và
hủy thao tác xóa. Điều này giúp tránh trường hợp dữ liệu điểm bị mồ côi sau khi sinh

viên bị xóa.

Ngoài các thao tác CRUD cơ bản, module sinh viên còn hỗ trợ sắp xếp danh sách sinh
viên. Chương trình có thể sắp xếp sinh viên theo MSSV, theo họ tên hoặc theo GPA.
Việc sắp xếp theo MSSV và họ tên sử dụng so sánh chuỗi, còn sắp xếp theo GPA dựa

trên điểm trung bình của từng sinh viên.

Nhìn chung, module quản lý sinh viên đã dap ứng được các chức năng cần thiết của
hệ thống. Việc tách riêng xử lý dữ liệu sinh viên, thao tác mảng động và giao diện nhập
xuất giúp chương trình có cấu trúc rõ ràng, dễ bảo trì và thuận tiện cho việc mở rộng sau

này.

52


<!-- Trang 55 / 102 -->

## Trang 55

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

7.3 Module quan lý môn hoc

Module quản lý môn hoc là module dùng để lưu trữ và xử lý thong tin các học phần
trong chương trình. Mỗi môn học được biểu diễn bằng struct Subject, bao gồm mã học
phần, tên học phần và số tín chỉ. Trong đó, maHP đóng vai trò là khóa chính để phân biệt

các môn học với nhau.

typedef struct{
char maHP[10];
char tenHP[80];
int soTinChi;

} Subject;

Listing 7.5: Struct Subject lưu thông tin môn hoc

Danh sách môn hoc được lưu bằng cấu trúc SubjectArray. Day là mang động định
kiểu riêng dành cho dit liệu môn học, gồm con trỏ data, số phan tử hiện tại size và sức
chứa hiện tại capacity. Việc sử dụng mảng động giúp chương trình có thể thêm môn học

mới trong quá trình chạy mà không cần giới hạn cố định số lượng môn học ngay từ đầu.

typedef struct {
Subject* data;
int size;
int capacity;

} SubjectArray;

Listing 7.6: Cấu trúc mảng động Subject Array

Các thao tác nghiệp vụ chính của module môn học được cài đặt trong file subject.c
và khai báo trong file subject.h. Module này cung cấp các hàm thêm, sửa, xóa và tìm

kiếm môn học theo mã học phần.


<!-- Trang 56 / 102 -->

## Trang 56

10

11

12

13

16

17

18

20

21

22

23

24

Nhóm 16

CHƯƠNG 7. KET QUA THUC HIỆN

Bang 7.3: Các hàm chính trong module quản lý môn hoc

Hàm

Chức năng

findSubjectRecord

Tim môn học theo mã hoc phan MaHP. Nếu
tìm thấy, hàm trả về con trỏ đến môn học
tương ứng: nếu không tìm thấy, hàm trả về
NULL.

addSubjectRecord

Thém môn hoc mới vào danh sách. Trước khi
thêm, hàm kiểm tra mã học phần đã tồn tại
hay chưa để tránh trùng khóa chính.

updateSubjectRecord

Cập nhật thông tin môn hoc dựa trên mã học
phần. Nếu mã học phần không tồn tại, hàm
trả về thất bại.

deleteSubjectRecord

Xóa môn học khỏi danh sách dựa trên mã
học phần. Nếu không tìm thấy môn học, hàm
không thực hiện thao tác xóa.

Đoạn mã sau thể hiện các hàm xử lý nghiệp vụ chính của module quản lý môn học:

Subject* findSubjectRecord(
SubjectArray* subjects,

const char* maHP

)
{
int idx =
suba_find(
subjects,
maHP
3;
if(idx == -1)
return NULL;
return &subjects->data[idx];
}
int addSubjectRecord(
SubjectArray* subjects,
Subject s
)
{

if(suba_find(subjects, s.maHP)

return 0;

54

'= -1)


<!-- Trang 57 / 102 -->

## Trang 57

26

27

28

29

37

38

39

40

41

42

44

45

46

A7

48

49

50

51

52

53

54

56

57

58

59

60

61

62

63

64

65

66

Nhóm 16

CHUONG 7. KET QUA THUC HIỆN

int

int

return suba_add(
subjects,

s

3ÿ

updateSubjectRecord(
SubjectArray* subjects,
Subject s

int idx =
suba_find(
subjects,
s.maHP
3

if (idx

-1)

return 0;

return suba_update (
subjects,
idx,
s

3

deleteSubjectRecord(
SubjectArray* subjects,

const char* maHP

int idx =
suba_find (
subjects,
maHP
3
if(idx == -1)

return 0;


<!-- Trang 58 / 102 -->

## Trang 58

67

68

69

70

71

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

return suba_remove(
subjects,
idx

3

Listing 7.7: Các hàm nghiệp vụ chính trong module môn học

Trong các hàm trên, suba_find được sử dụng để tìm vị trí môn học trong mảng theo
mã học phần. Nếu mã học phần không tồn tại, hàm trả về -1. Khi thêm môn học mới,
chương trình kiểm tra trước xem mã học phần đã tồn tại hay chưa. Điều này giúp tránh
việc có hai môn học cùng mã trong hệ thống.

Ỏ tang giao diện, module môn học được tích hợp trong menu QUAN LY MON HOC. Người
dùng có thể hiển thị danh sách môn học, thêm môn học, sửa thông tin môn học, xóa môn

học và tìm kiếm môn học.

Bảng 7.4: Các chức năng môn học trong tầng giao diện
Chức năng Mô tả

Hiển thị danh sách môn học | In toàn bộ danh sách môn học gồm mã học
phần, tên học phần và số tín chỉ.

Thêm môn học Nhập thông tin môn học mới, kiểm tra mã
học phần hợp lệ, kiểm tra trùng mã hoc phần
và kiểm tra số tín chỉ hợp lệ.

Sửa môn học Tim môn hoc theo mã học phan và cho phép
cập nhật tên học phần hoặc số tín chỉ. Nếu
người dùng bỏ trống thì giữ nguyên dữ liệu
cũ.

Xóa môn học Xóa môn học theo mã học phần. Trước khi
xóa, chương trình kiểm tra môn học có đang
được lớp học phần sử dụng hay không.

Tìm kiếm môn học Hỗ trợ tìm kiếm môn học theo mã học phần
hoặc theo từ khóa trong tên học phần.

Khi thêm hoặc sửa môn học, chương trình kiểm tra các dữ liệu đầu vào để hạn chế
lỗi. Mã học phần không được để trống và không được vượt quá kích thước trường đã khai
báo. Tên học phần cũng không được để trống và không được chứa ký tự |, vì đây là ký tự
được dùng làm dấu phan tách khi lưu dữ liệu xuống file text. Số tín chỉ phải là số nguyên

dương và nằm trong khoảng hợp lệ.

Đối với thao tác xóa môn học, chương trình cần đảm bảo toàn vẹn dữ liệu. Một môn
học có thể được sử dụng bởi nhiều lớp học phần thông qua trường maHP trong struct

CourseClass. Vì vậy, trước khi xóa môn học, tang giao diện sẽ kiểm tra xem có lớp học

56


<!-- Trang 59 / 102 -->

## Trang 59

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

phan nào dang sử dung mã hoc phần đó hay không. Nếu môn hoc đang được tham chiếu,
chương trình sẽ thông báo lỗi và không cho phép xóa. Cách xử lý này giúp tránh trường
hợp lớp học phần bị mất thông tin môn học tương ứng.

Nhìn chung, module quản lý môn học đã đáp ứng được các chức năng cơ bản cần thiết
của hệ thống. Việc tách riêng phan xử lý nghiệp vụ trong subject.c và phần nhập xuất
trong ui.c giúp chương trình rõ ràng hơn, dễ kiểm thử hơn và thuận tiện cho việc mở

rộng trong các phiên bản sau.
Đ

7.4 Module quản lý lớp hoc phan

Module quan lý lớp học phan dùng để quan lý các lớp hoc phần được mở trong từng
học kỳ, từng năm học. Trong chương trình, lớp học phần được biểu diễn bằng struct
CourseClass. Mỗi lớp học phần có mã lớp học phần, mã học phần tương ứng, học kỳ và

năm học.

typedef struct {
char maLHP [15];
char maHP [10];
int hocKy;
int namHoc;

} CourseClass;

Listing 7.8: Struct CourseClass lưu thông tin lớp hoc phan

Trong đó, trường maLHP là khóa chính dùng dé phân biệt các lớp học phần với nhau.
Trường maHP là mã học phần tương ứng, có vai trò liên kết lớp học phần với môn học
trong danh sách SubjectArray. Nhờ mối liên kết này, chương trình có thể xác định lớp

học phần thuộc môn hoc nào và sử dụng số tín chỉ của môn học khi tính GPA cho sinh viên.

Danh sách lớp học phần được lưu trữ bằng cấu trúc CourseClassArray. Dây là mảng
động định kiểu riêng dành cho dữ liệu lớp học phần. Cấu trúc này gồm con trỏ data, số

phần tử hiện tại size và sức chứa hiện tại capacity.

typedef struct {
CourseClass* data;
int size;
int capacity;

} CourseClassArray ;

Listing 7.9: Cấu trúc mang động CourseClassArray


<!-- Trang 60 / 102 -->

## Trang 60

10

11

12

14

15

16

18

19

Nhóm 16

CHƯƠNG 7. KET QUA THUC HIỆN

Các thao tác nghiệp vụ chính của module lớp hoc phan được cài đặt trong file

courseclass.c và khai báo trong file courseclass.h. Module này cung cấp các hàm

thêm, cập nhật, xóa và tìm kiếm lớp học phần theo mã lớp học phần.

Bảng 7.5: Các hàm chính trong module quản lý lớp học phần

Hàm

Chức năng

findCourseClassRecord

Tìm lớp học phần theo ma lớp học phần
MaLHP. Nếu tìm thấy, hàm trả về con trỏ đến
lớp học phần tương ứng; nếu không tìm thấy,
hàm trả về NULL.

addCourseClassRecord

Thém lớp hoc phần mới vào danh sách. Hàm
kiểm tra trùng mã lớp học phần và kiểm tra
mã học phần có tồn tại trong danh sách môn
học hay không.

updateCourseClassRecord

Cap nhật thông tin lớp hoc phần dựa trên mã
lóp học phần. Nếu mã lớp học phần không
tồn tại, hàm trả về thất bại.

deleteCourseClassRecord

Xóa lớp học phần khỏi danh sách dựa trên
mã lớp học phần. Nếu không tìm thay lớp học
phần, hàm không thực hiện thao tác xóa.

Đoạn mã sau thể hiện các hàm xử lý nghiệp vụ chính của module quản lý lớp học

phần:

CourseClass* findCourseClassRecord(

CourseClassArray* classes,

const char* maLHP

)
{
int idx =
cca_find(
classes,
maLHP
3ÿ
if(idx == -1)
return NULL;
return &classes->data[idx];
}
int addCourseClassRecord (

CourseClassArray* classes,

58


<!-- Trang 61 / 102 -->

## Trang 61

20

21

22

23

24

26

27

28

29

31

32

33

34

35

36

37

40

41

42

44

45

46

47

48

49

50

51

52

53

54

55

56

Nhóm 16

int

int

SubjectArray* subjects,

CourseClass c

if (cca_find(classes, c.maLHP) != -1)

return 0;

if(suba_find(subjects, c.maHP) == -1)

return 0;

return cca_add(
classes,

Cc

updateCourseClassRecord(
CourseClassArray* classes,

CourseClass c

int idx =

cca_find(

classes,
c.maLHP
5
if(idx == -1)
return 0;

return cca_update(
classes,
idx,

c

deleteCourseClassRecord (
CourseClassArray* classes,

const char* maLHP

CHUONG 7. KET QUA THUC HIỆN


<!-- Trang 62 / 102 -->

## Trang 62

61

62

63

64

65

66

67

68

68

70

71

72

73

74

T5

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

{
int idx =
cca_find(
classes,
maLHP
3;
if(idx == -1)
return 0;
return cca_remove(
classes,
idx
3
}

Listing 7.10: Các hàm nghiệp vụ chính trong module lớp học phần

Trong các hàm trên, cca_find được sử dung để tìm lớp hoc phần theo mã MaLHP. Khi
thêm lớp học phần mới, chương trình kiểm tra hai điều kiện quan trọng: mã lớp học phần
không được trùng và mã học phần phải tồn tại trong danh sách môn học. Điều này giúp

đảm bảo mỗi lớp học phần đều gắn với một môn học hợp lệ.

Ỏ tầng giao diện, module lớp học phần được tích hợp trong menu QUAN LY LOP HOC
PHAN. Người dùng có thể hiển thị danh sách lớp học phần, thêm lớp học phần, sửa thông
tin lớp học phần, xóa lớp học phần và tìm kiếm lớp học phần.

60


<!-- Trang 63 / 102 -->

## Trang 63

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

Bang 7.6: Các chức năng lớp học phần trong tang giao diện

Chức năng Mô tả

Hiển thị danh sách lớp học | In toàn bộ danh sách lớp học phần gồm mã

phần lớp học phần, mã học phần, học kỳ và năm
học.

Thêm lớp học phần Nhập lớp học phần mới, kiểm tra mã lớp học

phan không trùng, mã học phần tồn tại, học
kỳ hợp lệ và năm học hợp lệ.

Sửa lớp học phần Tìm lớp học phần theo mã lớp học phần và
cho phép cập nhật mã học phần, học kỳ hoặc
năm học. Nếu người dùng bỏ trống thì giữ
nguyên dữ liệu cũ.

Xóa lớp học phần Xóa lớp học phần theo mã lớp học phần.
Trước khi xóa, chương trình kiểm tra lớp học
phần đó đã có bản ghi điểm hay chưa.

Tìm kiếm lớp học phần Hỗ trợ tìm kiếm lớp học phần theo mã lớp
học phần hoặc theo mã học phần.

Khi thêm lớp học phần, chương trình yêu cầu người dùng nhập MaLHP, MaHP, học kỳ
và năm học. Mã lớp học phần không được để trống và không được trùng với lớp học phần
đã tồn tại. Mã học phần phải tồn tại trong danh sách môn học, nhằm đảm bảo lớp học
phần luôn liên kết với một môn học hợp lệ. Học kỳ được kiểm tra trong khoảng từ 1 đến

3, còn năm học được kiểm tra trong khoảng hợp lệ.

Khi sửa lớp học phần, chương trình cho phép người dùng cập nhật từng trường thông
tin. Néu mã học phần mới không tồn tại trong danh sách môn học, chương trình sẽ giữ
nguyên mã học phần cũ và thông báo lỗi. Tương tự, nếu học kỳ hoặc năm học mới không

hợp lệ, chương trình cũng giữ nguyên giá trị cũ để tránh làm sai dữ liệu.

Đối với thao tác xóa lớp học phần, chương trình cần đảm bảo toàn vẹn dữ liệu với
bảng điểm. Vì mỗi bản ghi điểm trong ScoreRecord có chứa trường maLHP, nếu xóa một
lớp học phần đã có điểm thì các bản ghi điểm tương ứng sẽ bị mất tham chiếu. Do đó,
tầng giao diện kiểm tra trước xem lớp học phần có đang xuất hiện trong danh sách điểm

hay không. Nếu lớp học phần đã có điểm, chương trình sẽ không cho phép xóa.

Nhìn chung, module quản lý lớp học phần giữ vai trò trung gian giữa môn học và điểm
số. Module này giúp chương trình tổ chức dữ liệu theo từng học kỳ, từng năm học, đồng
thời đảm bảo mỗi bản ghi điểm đều gắn với một lớp học phần hợp lệ. Việc tách riêng
module lớp học phần giúp chương trình có cấu trúc rõ ràng, dễ kiểm thử và thuận tiện

hơn khi mở rộng các chức năng quản lý đào tạo sau này.

61


<!-- Trang 64 / 102 -->

## Trang 64

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

7.5 Module quan lý điểm số

Module quản lý điểm số dùng dé lưu trữ va xử lý điểm của sinh viên theo từng lớp
học phần. Đây là module liên kết trực tiếp giữa sinh viên và lớp học phần, vì mỗi bản
ghi điểm đều chứa mã số sinh viên mssv và mã lớp hoc phần maLHP. Trong chương trình,

thông tin điểm số được biểu diễn bằng struct ScoreRecord.

typedef struct {
char mssv[12];
char maLHP[15];
float diemQT;
float diemCK;
float diemTK;
float diemHe4;

} ScoreRecord;

Listing 7.11: Struct ScoreRecord lưu thông tin điểm số

Trong đó, mssv là mã số sinh viên, tham chiếu đến danh sách sinh viên; maLHP là mã
lớp học phần, tham chiếu đến danh sách lớp học phần. Hai trường này kết hợp với nhau
tạo thành khóa định danh cho một bản ghi điểm. Các trường diemQT, diemCK, diemTK
lần lượt là điểm quá trình, điểm cuối kỳ và điểm tổng kết. Trường diemHe4 lưu điểm quy
đổi sang hệ 4.

Danh sách điểm được lưu trữ bằng cấu trúc ScoreArray. Day là mảng động định kiểu
riêng dành cho dữ liệu điểm số, gồm con trỏ data, số phần tử hiện tại size và sức chứa

hiện tại capacity.

typedef struct {
ScoreRecord* data;
int size;
int capacity;

} ScoreArray ;

Listing 7.12: Cau trúc mang động ScoreArray

Module điểm số có nhiệm vu chính là thêm điểm, cập nhật điểm, tinh điểm tổng kết
và quy đổi điểm sang hệ 4. Các hàm nghiệp vụ chính được cài đặt trong file score.c và

khai báo trong file score.h.

62


<!-- Trang 65 / 102 -->

## Trang 65

11

12

13

15

16

18

19

20

Nhóm 16 CHUONG 7. KET QUA THUC HIEN
Bang 7.7: Các hàm chính trong module quản lý điểm số

Hàm Chức năng

calculateDiemTK Tính điểm tổng kết từ điểm quá trình và
điểm cuối kỳ theo công thức trung bình cộng.

convertToHe4 Quy đổi điểm tổng kết hệ 10 sang điểm hệ 4
theo các mốc điểm đã quy định.

addScoreRecord Thêm bản ghi điểm mới. Hàm kiểm tra sinh
viên tồn tại, lớp học phần tồn tại và không
bị trùng cặp MSSV + MaLHP.

updateScoreRecord Cập nhật điểm quá trình và điểm cuối kỳ của
một bản ghi điểm đã có, sau đó tính lại điểm
tổng kết và điểm hệ 4.

Điểm tổng kết được tính dựa trên điểm quá trình và điểm cuối kỳ. Trong chương trình,

công thức được sử dụng là:

DiemTK = (DiemQT + DiemCK) / 2.0

Sau khi tính được điểm tổng kết, chương trình tiếp tục quy đổi sang điểm hệ 4. Việc

quy đổi được thực hiện bằng hàm convertToHe4. Các mốc quy đổi được xét từ cao xuống

thấp để đảm bảo điểm được phân loại đúng.

float calculateDiemTK(
float diemQT,
float diemCK

return (diemQT + diemCK) / 2.0f;

float convertToHe4 (
float diemTK

if(diemTK >= 8.5f)

return 4.0f;

if(diemTK >= 8.0f)

return 3.5f;

if(diemTK >= 7.0f)

return 3.0f;

63


<!-- Trang 66 / 102 -->

## Trang 66

Nhóm 16

CHƯƠNG 7. KET QUA THUC HIỆN

21
22
23
24
25
26
27
28

29

38

34

35] }

if(diemTK >= 6.5f)

return 2.5f;

if(diemTK >= 5.5f)

return 2.0f;

if(diemTK >= 5.0f)

return 1.5f;

if(diemTK >= 4.0f)

return 1.0f;

return 0.0f;

Listing 7.13: Ham tính điểm tổng kết và quy đổi điểm hệ 4

Khi thêm một bản ghi điểm mới, chương trình cần đảm bảo dữ liệu có tính liên kết.

Cu thé, sinh viên phải tồn tại trong danh sách sinh viên và lớp học phần phải tồn tại

trong danh sách lớp học phần. Ngoài ra, một sinh viên chỉ được có một bản ghi điểm cho

cùng một lớp học phần, vì vậy chương trình kiểm tra trùng cặp theo cặp mssv và maLHP
trước khi thêm.

10

11

12

14

15

16

18

19

iJint addScoreRecord(

ScoreArray* scores,
StudentArray* students,
CourseClassArray* classes,

ScoreRecord sc

if (sa_find(students, sc.mssv) == -1)

return 0;

if (cca_find(classes, sc.maLHP) == -1)

return 0;

if (sca_find(scores, sc.mssv, sc.maLHP)

return 0;

sc.diemTK =
calculateDiemTK (

sc.diemQT,

64


<!-- Trang 67 / 102 -->

## Trang 67

20

21

22

23

24

25

26

27

28

29

31

32

17

18

19

20

21

22

Nhóm 16

CHUONG 7. KET QUA THUC HIỆN

sc.diemCK

3ÿ

sc.diemHe4 =
convertToHe4(
sc.diemTK

3ÿ

return sca_add(
scores,

sc

Listing 7.14: Hàm thêm ban ghi điểm

Đối với thao tác cập nhật điểm, chương trình tìm bản ghi điểm theo cặp mssv và

maLHP. Nếu tìm thấy, chương trình cập nhật lại điểm quá trình, điểm cuối kỳ, sau đó tự

động tính lại điểm tổng kết và điểm hệ 4. Nhờ đó, dữ liệu điểm luôn nhất quán sau mỗi

lần chỉnh sửa.

int updateScoreRecord(
ScoreArray* scores,
const char* mssv,
const char* maLHP,
float diemQT,
float diemCK

int idx =

sca_find(

scores,
mssv,
maLHP
3
if(idx == -1)

return 0;

scores->data[idx].diemQT

scores->data[idx]. diemCK

scores->data[idx]. diemTK

diemQT;
diemCK;

65


<!-- Trang 68 / 102 -->

## Trang 68

23

24

25

26

27

28

29

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

calculateDiemTK(
diemQT,
diemCK

);

scores->data[idx].diemHe4 =
convertToHe4 (
scores->data[idx]. diemTK

3;

return 1;

Listing 7.15: Ham cập nhật điểm

Ở tầng giao diện, module điểm số được tích hợp trong menu QUAN LY DIEM. Người
dùng có thể hiển thị danh sách điểm, nhập điểm, cập nhật điểm và tìm kiếm điểm.

Bảng 7.8: Các chức năng điểm số trong tầng giao diện
Chức năng Mô tả
Hiển thị danh sách điểm In toàn bộ danh sách điểm gồm MSSV, mã
lóp học phần, điểm quá trình, điểm cuối kỳ,
điểm tổng kết và điểm hệ 4.

Nhập điểm Nhập điểm cho một sinh viên trong một lớp
học phần. Chương trình kiểm tra sinh viên
tồn tại, lớp học phần tồn tại và bản ghi điểm
chưa bị trùng.

Cập nhật điểm Tìm bản ghi điểm theo cặp MSSV và mã lớp
học phần, sau đó cập nhật điểm quá trình và
điểm cuối kỳ.

Tìm điểm Hỗ trợ tìm điểm theo MSSV, theo mã lớp
học phần hoặc theo cặp MSSV và mã lớp
học phần.

Trong quá trình nhập điểm và cập nhật điểm, tầng giao diện kiểm tra điểm quá trình
và điểm cuối kỳ phải nằm trong khoảng từ 0 đến 10. Sau khi người dùng nhập điểm hợp
lệ, chương trình tự động tính điểm tổng kết và điểm hệ 4. Việc tự động tính toán này

giúp hạn chế sai sót do người dùng nhập thủ công điểm tổng kết hoặc điểm quy đổi.

Module điểm số cũng có vai trò quan trọng trong các chức năng báo cáo. Khi xem
bảng điểm của một sinh viên, chương trình duyệt qua danh sách điểm để tìm các bản ghi
có cùng MSSV, sau đó in ra điểm của từng lớp hoc phan. Đồng thời, dữ liệu điểm được

sử dung để tinh GPA hệ 10, GPA hệ 4 và hoc lực của sinh viên. Khi xem bảng điểm của

66


<!-- Trang 69 / 102 -->

## Trang 69

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

một lớp học phần, chương trình loc các bản ghi điểm theo maLHP và hiển thi danh sách
sinh viên trong lớp học phần đó.

Nhìn chung, module quản lý điểm số là module liên kết giữa sinh viên, lớp học phần
và kết quả học tập. Module này không chỉ lưu trữ điểm mà còn đảm nhiệm việc tính điểm
tổng kết, quy đổi điểm hệ 4 và cung cấp dữ liệu cho các báo cáo học tập. Việc kiểm tra
khóa ngoại và tự động tính toán giúp dữ liệu điểm số trong chương trình nhất quán, hạn

chế lỗi nhập liệu và thuận tiện cho việc mở rộng các chức năng thống kê sau này.

7.6 Module doc/ghi file

Module doc/ghi file có nhiệm vụ lưu trữ dữ liệu của chương trình xuống bộ nhớ ngoài
và nạp lại dữ liệu khi chương trình khởi động. Đây là module quan trọng vì toàn bộ dữ
liệu sinh viên, môn học, lớp học phần và điểm số cần được giữ lại sau khi chương trình

kết thúc. Module này được cài đặt trong file fileio.c và khai báo trong file fileio.h.

Trong chương trình, dữ liệu được lưu dưới dạng file văn bản. Mỗi loại dữ liệu được
lưu trong một file riêng, các trường trong một dòng được phân tách bằng ký tự |. Cách
lưu này đơn giản, dễ đọc, dễ chỉnh sửa thủ công và phù hợp với phạm vi của bài tập lớn.

Bảng 7.9: Các file dữ liệu sử dụng trong chương trình
File dữ liệu Nội dung lưu trữ

data/students.txt Luu danh sách sinh viên, gồm MSSV, họ tên,
lớp và ngày sinh.

data/subjects.txt Lưu danh sách môn học, gồm mã học phan,
tên học phần và số tín chỉ.

data/course_classes.txt | Lưu danh sách lớp học phần, gồm mã lớp học
phần, mã học phần, học kỳ và năm học.

data/scores.txt Lưu danh sách điểm, gồm MSSV, mã lớp hoc
phần, điểm quá trình, điểm cuối kỳ, điểm
tổng kết và điểm hệ 4.

Các đường dẫn file được định nghĩa trong fileio.h bằng các hằng tiền xử lý. Nhờ
đó, khi cần thay đổi vị trí lưu file, chương trình chỉ cần sửa ở một nơi thay vì sửa rải rác

trong nhiều module.

67


<!-- Trang 70 / 102 -->

## Trang 70

1

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

#define STUDENT_FILE "data/students.txt"

#define SUBJECT_FILE "data/subjects.txt"

#define COURSE_CLASS_FILE "data/course_classes.txt"
#define SCORE_FILE "data/scores.txt"

Listing 7.16: Các file dữ liệu được định nghĩa trong fileio.h

Cấu trúc mỗi file dữ liệu được thiết kế tương ứng với các struct chính của chương
trình. Mỗi dòng trong file là một bản ghi. Dòng đầu tiên là tiêu đề, các dòng tiếp theo là
dit liệu thực tế.

Bang 7.10: Dinh dang các file dữ liệu

File Dinh dạng một dòng dữ liệu

students. txt MSSV | HoTen | Lop |Birthday

subjects.txt MaHP | TenHP | SoTinChi

course_classes.txt MaLHP | MaHP | HocKy | NamHoc

scores.txt MSSV | MaLHP | DiemQT | DiemCK | DiemTK | DiemHe4

Ví dụ, một số dòng dữ liệu có thé được lưu như sau:

202400000| Nguyen Van Toan|K69-MI1-01115/08/2006
MI3310|Ky thuat lap trinh|2
169313|MTI3310|12025
202400000|169313|8.00|9.00|8.50|4.00

Listing 7.17: Ví dụ định dạng dữ liệu trong file text

Module đọc/ghi file cung cấp các hàm đọc và ghi riêng cho từng loại di liệu. Các hàm
đọc có nhiệm vu mở file, đọc từng dòng, tách các trường dữ liệu, kiểm tra tính hợp lệ
và thêm bản ghi hợp lệ vào mảng động tương ứng. Các hàm ghi có nhiệm vụ duyệt qua

mảng động và ghi từng bản ghi xuống file theo đúng định dạng.

68


<!-- Trang 71 / 102 -->

## Trang 71

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

Bảng 7.11: Các hàm doc/ghi dữ liệu chính
Hàm Chức năng
loadStudents Đọc danh sách sinh viên từ file
students.txt vào StudentArray.

saveStudents Ghi danh sách sinh viên từ StudentArray
xuống file students. txt.

loadSubjects Doc danh sách môn học từ file subjects. txt
vào SubjectArray.

saveSubjects Ghi danh sách môn hoc từ SubjectArray
xuống file subjects. txt.

loadCourseClasses Doc danh sách lớp học phần
từ file course_classes. txt vào
CourseClassArray.

saveCourseClasses Ghi danh sách lớp học phần
từ CourseClassArray xuống file
course_classes.txt.

loadScores Đọc danh sách điểm từ file scores. txt vào
ScoreArray.

saveScores Ghi danh sách điểm từ ScoreArray xuống

file scores. txt.

1oadA11Data Đọc toàn bộ dữ liệu của chương trình theo
đúng thứ tự.

saveAllData Ghi toàn bộ dữ liệu của chương trình xuống
các file tương ứng.

Khi đọc dữ liệu, chương trình không nạp dữ liệu một cách máy móc mà có kiểm tra
các lỗi thường gặp. Ví dụ, với file sinh viên, chương trình bỏ qua các dòng thiếu trường,
dong có MSSV rỗng hoặc dòng bi trùng MSSV. Với file môn học, chương trình kiểm tra
mã học phần không rỗng, số tín chỉ phải lớn hơn 0 và không bị trùng mã học phần. Với
file lớp học phần, chương trình kiểm tra học kỳ hợp lệ và năm học hợp lệ. Với file điểm
số, chương trình kiểm tra MSSV và mã lớp học phần không rỗng, các điểm nằm trong
khoảng hợp lệ và không bị trùng cặp khóa MSSV + MaLHP.

Một điểm quan trọng của module doc/ghi file là khi đọc dữ liệu điểm, chương trình
không hoàn toàn tin tưởng giá trị DiemTK và DiemHe4 có sẵn trong file. Thay vào đó,
chương trình tính lại điểm tổng kết và điểm hệ 4 dựa trên điểm quá trình và điểm cuối
kỳ. Diều này giúp dữ liệu điểm nhất quán hơn, tránh trường hợp file bị sửa thủ công làm
sai điểm tổng kết hoặc điểm quy đổi.

Quy trình đọc toàn bộ dữ liệu được thực hiện bởi hàm 1oadA11Data. Hàm này đọc dit
liệu theo thứ tự: sinh viên, môn học, lớp học phần và điểm số. Sau khi đọc xong, chương

trình tiếp tục kiểm tra toàn vẹn khóa ngoại. Cụ thể, mỗi lớp học phần phải tham chiếu

69


<!-- Trang 72 / 102 -->

## Trang 72

10

11

12

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

đến một mã hoc phan có tồn tại trong danh sách môn học. Mỗi bản ghi điểm phải tham
chiều đến một sinh viên có thật và một lớp học phần có thật. Những bản ghi tham chiếu

sai sẽ bị loại bỏ để tránh dữ liệu mồ côi.

loadAllData(students, subjects, classes, scores):
loadStudents (students, STUDENT_FILE)
1oadSubjects(subjects, SUBJECT_FILE)
loadCourseClasses(classes, COURSE_CLASS_FILE)
loadScores(scores, SCORE_FILE)

Kiem tra moi lop hoc phan co MaHP ton tai trong subjects

Neu MaHP khong ton tai thi loai bo lop hoc phan do

Kiem tra moi ban ghi diem co MSSV ton tai trong students
Kiem tra moi ban ghi diem co MaLHP ton tai trong classes

Neu tham chieu khong hop le thi loai bo ban ghi diem do

Listing 7.18: Ý tưởng xử lý của ham loadAllData

Ngược lại, khi chương trình kết thúc, hàm saveAllData được gọi để ghi toàn bộ dữ
liệu hiện có trong bộ nhớ xuống các file tương ứng. Nhờ đó, những thay đổi trong quá
trình chạy chương trình như thêm sinh viên, sửa môn học, thêm lớp học phần hoặc nhập

điểm sẽ được lưu lại.

saveAllData(students, subjects, classes, scores):
saveStudents(students, STUDENT_FILE)
saveSubjects(subjects, SUBJECT_FILE)
saveCourseClasses(classes, COURSE_CLASS_FILE)
saveScores(scores, SCORE_FILE)

Listing 7.19: Ý tưởng xử lý của ham saveAllData

Module đọc/ghi file cũng được kiểm thử bằng cả unit test và integration test. Trong
unit test, chương trình tạo file tạm để kiểm tra riêng hàm 1oadStudents và saveStudents,
gồm các trường hợp đọc dòng hợp lệ, bỏ qua dòng thiếu trường, bỏ qua MSSV trùng và
kiểm tra quá trình save rồi load lại. Trong integration test, chương trình kiểm tra toàn
bộ quy trình 1oadA11Data và saveAllData với dữ liệu thật trong thư mục data/. Kết

quả kiểm thử cho thấy các test case liên quan đến đọc/ghi file đều chạy đúng.

Nhìn chung, module đọc/ghi file giúp chương trình có khả năng lưu trữ dữ liệu lâu
đài thay vì chỉ xử lý tạm thời trong bộ nhớ RAM. Việ

chia dữ liệu thành bốn file riêng
giúp cấu trúc lưu trữ rõ ràng, dễ kiểm tra và dễ bảo trì. Đồng thời, các bước kiểm tra dit
liệu khi đọc file giúp chương trình ổn định hơn, hạn chế lỗi do file thiếu trường, dữ liệu

sai định dạng, trùng khóa hoặc tham chiếu không hợp lệ.

70


<!-- Trang 73 / 102 -->

## Trang 73

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

7.7 Module giao diện console

Module giao diện console là module chịu trách nhiệm tương tác trực tiếp với người
dùng. Module này hiển thị các menu chức năng, nhận dit liệu nhập từ ban phím, kiểm tra
tính hợp lệ của dữ liệu và gọi các hàm xử lý tương ứng của những module khác. Trong
chương trình, phan giao diện được cài đặt trong file ui.c và được khai báo public thông
qua file ui.h.

File ui.h chỉ công khai một hàm duy nhất là showMainMenu. Các hàm còn lại trong
ui.c được khai báo static, tức là chỉ được sử dụng nội bộ trong module giao diện. Cách
thiết kế này giúp che giấu chỉ tiết cài đặt bên trong module, đồng thời làm cho các module

khác chỉ cần gọi menu chính mà không cần biết toàn bộ cấu trúc menu con.

void showMainMenu(StudentArray* students,
SubjectArray* subjects,
CourseClassArray* classes,

ScoreArray* scores);

Listing 7.20: Ham giao diện chính được khai báo trong ui.h

Ham showMainMenu nhận vào bốn mang động chính của chương trình, bao gồm danh
sách sinh viên, danh sách môn học, danh sách lớp học phần và danh sách điểm. Từ menu
chính, người dùng có thể truy cập đến các nhóm chức năng khác nhau như quản lý sinh
viên, quản lý môn học, quản lý lớp học phần, quản lý điểm số, báo cáo bảng điểm và hiển
thị toàn bộ dữ liệu.

Bảng 7.12: Các chức năng chính trong menu console

Chức năng Mô tả

Quản lý sinh viên Hiển thị, thêm, sửa, xóa, tìm kiếm và sắp xếp
danh sách sinh viên.

Quản lý môn học Hiển thị, thêm, sửa, xóa và tìm kiếm môn
học.

Quản lý lớp học phần Hiển thị, thêm, sửa, xóa và tìm kiếm lớp học
phần.

Quản lý điểm số Hiển thị danh sách điểm, nhập điểm, cập

nhật điểm và tìm kiếm điểm.

Báo cáo / bảng điểm Xem bảng điểm của một sinh viên hoặc bảng
điểm của một lớp học phần.

Hiển thị toàn bộ dữ liệu In ra toàn bộ dữ liệu hiện có trong chương
trình, gồm sinh viên, môn học, lớp học phần
và điểm số.

Lưu và thoát Thoát khỏi menu chính. Sau đó chương trình
chính sẽ lưu di liệu xuống file.

71


<!-- Trang 74 / 102 -->

## Trang 74

10

11

12

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

Cấu trúc menu chính được tổ chức bằng vòng lặp do while. Sau mỗi lựa chọn, chương
trình thực hiện chức năng tương ứng rồi quay lại menu chính, trừ khi người dùng chọn
thoát. Cách tổ chức này giúp chương trình hoạt động liên tục và thuận tiện cho người

dùng khi thao tác với nhiều chức năng khác nhau.

showMainMenu(students, subjects, classes, scores):
repeat
In menu chỉnh

Nhap lua chon cua nguoi dung

Neu chon 1: mo menu quan ly sinh vien
Neu chon 2: mo menu quan ly mon hoc

Neu chon 3: mo menu quan ly lop hoc phan
Neu chon 4: mo menu quan ly diem so

Neu chon 5: mo menu bao cao

Neu chon 6: hien thi tat ca du lieu

Neu chon 0: thoat menu

Neu chua thoat thi tam dung man hinh

until choice == 0

Listing 7.21: Ý tưởng xử lý của menu chính

Một phần quan trọng của module giao diện là xử lý nhập dữ liệu và kiểm tra dữ
liệu đầu vào. Chương trình sử dung các hàm tiện ích như readLine, readLineOptional,
readInt, readIntRange, readFloat và readFloatRange để nhập dữ liệu an toàn hơn.
Các hàm này giúp hạn chế lỗi do nhập sai kiểu dữ liệu, nhập thiếu thông tin hoặc nhập

giá trị ngoài khoảng cho phép.

72


<!-- Trang 75 / 102 -->

## Trang 75

Nhóm 16 CHUONG 7. KET QUA THUC HIỆN

Bang 7.13: Một số hàm tiện ích nhập dữ liệu trong ui.c
Hàm Chức năng

readLine Nhập chuỗi bắt buộc, không cho phép bỏ
trống và không cho phép chứa ký tự |.

readLineOptional Nhập chuỗi tùy chon, dùng trong các chức
năng sửa thông tin. Nếu người dùng bỏ trống
thì giữ nguyên dữ liệu cũ.

readInt Nhập số nguyên và kiểm tra đúng định dang
SỐ nguyên.

readIntRange Nhập số nguyên trong một khoảng cho trước,
ví dụ lựa chọn menu hoặc học kỳ.

readFloat Nhập số thực và kiểm tra đúng định dạng số
thực.

readFloatRange Nhập số thực trong một khoảng cho trước,

dùng để nhập điểm từ 0 đến 10.

Ngoài kiểm tra kiểu dữ liệu, module giao diện còn có các hàm kiểm tra nghiệp vụ như
validateMSSV, validateCode, validateSemester, validateYear, validateCredit và
validateDate. Trong đó, validateDate kiểm tra ngày sinh theo định dạng DD/MM/YYYY,
đồng thời xét số ngày hợp lệ của từng tháng và năm nhuận. Điều này giúp hạn chế việc

người dùng nhập các ngày không tồn tại như 31/02/2006.

Bảng 7.14: Các kiểm tra dữ liệu đầu vào trong module giao điện

Dữ liệu Điều kiện kiểm tra

Chuỗi nhập vào Không được để trống và không được chứa ký
tự |.

MSSV Chỉ gồm chữ số và có độ dài nhỏ hơn kích

thước trường mssv.

Mã học phần, mã lớp học | Không được rỗng và không vượt quá kích

phần thước trường đã khai báo.

Ngày sinh Đúng định dạng DD/MM/YYYY, ngày thang
năm phải hợp lệ.

Học kỳ Nằm trong khoảng từ 1 đến 3.

Năm học Nằm trong khoảng từ 2000 đến 2100.

Số tín chỉ Là số nguyên dương và không vượt quá giới

hạn cho phép.

Diém số Điểm quá trình và điểm cuối kỳ phải nằm
trong khoảng từ 0 đến 10.

Trong phần quản lý sinh viên, giao diện cung cấp menu cho phép hiển thị danh sách

sinh viên, thêm sinh viên, sửa sinh viên, xóa sinh viên, tìm sinh viên và sắp xếp danh sách

73


<!-- Trang 76 / 102 -->

## Trang 76

Nhóm 16 CHƯƠNG 7. KET QUA THUC HIỆN

sinh viên. Khi thêm sinh viên, chương trình kiểm tra MSSV hợp lệ, không trùng MSSV và
ngày sinh đúng định dạng. Khi sửa sinh viên, người dùng có thể bỏ trống một trường để
giữ nguyên giá trị cũ. Khi xóa sinh viên, chương trình kiểm tra sinh viên đó đã có bản ghi

điểm hay chưa; nếu đã có điểm thi khong cho phép xóa nhằm tránh dữ liệu điểm bị mồ côi.

Trong phần quản lý môn học, giao diện cho phép hiển thị, thêm, sửa, xóa và tìm kiếm
môn học. Khi thêm hoặc sửa môn học, chương trình kiểm tra mã học phần, tên học phần
và số tín chỉ. Khi xóa môn học, chương trình kiểm tra xem môn học đó có đang được lớp
học phần nào sử dụng hay không. Nếu đang được tham chiếu, thao tác xóa sẽ bị chặn để

đảm bảo toàn vẹn dữ liệu.

Trong phần quản lý lớp học phần, giao diện cho phép người dùng thao tác với các lớp
học phần theo mã lớp học phần. Khi thêm lớp học phần, mã học phần phải tồn tại trong
danh sách môn học. Khi xóa lớp học phần, chương trình kiểm tra lớp học phần đó đã

có bản ghi điểm hay chưa. Nếu đã có điểm, chương trình không cho phép xóa lớp học phần.

Trong phần quản lý điểm số, giao diện cho phép hiển thị danh sách điểm, nhập điểm,
cập nhật điểm và tìm kiếm điểm. Khi nhập điểm, chương trình kiểm tra sinh viên tồn tại,
lớp học phần tồn tại và cặp MSSV + MaLHP chưa bị trùng. Diểm quá trình và điểm cuối
kỳ được nhập trong khoảng từ 0 đến 10. Sau khi nhập hoặc cập nhật điểm, chương trình
tự động tính điểm tổng kết và điểm hệ 4.

Module giao diện cũng cung cấp phần báo cáo gồm hai chức năng chính: xem bảng
điểm của một sinh viên và xem bảng điểm của một lớp học phần. Với bảng điểm sinh
viên, chương trình hiển thị các bản ghi điểm theo MSSV, đồng thời tính GPA hệ 10, GPA
hệ 4 và học lực. Với bảng điểm lớp học phần, chương trình hiển thị danh sách sinh viên
trong lớp học phần kèm MSSV, họ tên và các cột điểm tương ứng.

Nhìn chung, module giao diện console đóng vai trò điều phối toàn bộ chương trình.
Module này không chỉ giúp người dùng thao tác thuận tiện với hệ thống mà còn thực
hiện nhiều bước kiểm tra dữ liệu đầu vào trước khi gọi các hàm xử lý ở tầng nghiệp vụ.
Việc đặt các hàm hỗ trợ và menu con ở dạng static giúp module giao diện có tính đóng

gói tốt hơn, đồng thời làm cho cấu trúc chương trình rõ ràng và dễ bảo trì.

74


<!-- Trang 77 / 102 -->

## Trang 77

Chương 8

KẾT LUẬN

8.1 Kết quả đạt được

Sau quá trình phân tích, thiết kế, cài đặt và kiểm thử, nhóm đã xây dựng được chương
trình Quán lú sinh tiên chạy trên giao diện console bằng ngôn ngữ lập trình C. Chương
trình đáp ứng được các yêu cầu chính của đề tài, bao gồm quản lý sinh viên, môn học,
lớp học phần, điểm số, tìm kiếm, sắp xếp, tính GPA và lưu trữ dữ liệu bằng file text.

"Trước hết, nhóm đã thiết kế được hệ thống dữ liệu tương đối rõ rang thông qua các
struct chính như Student, Subject, CourseClass và ScoreRecord. Các kiểu dữ liệu
này giúp biểu diễn các đối tượng cần quản lý trong chương trình một cách trực tiếp và
dễ hiểu. Bên cạnh đó, nhóm cũng tự cài đặt cấu trúc dữ liệu mảng động cho từng nhóm
dữ liệu, bao gồm StudentArray, SubjectArray, CourseClassArray và ScoreArray. Nhờ
đó, chương trình có thể thêm, sửa, xóa, tìm kiếm và quản lý dữ liệu linh hoạt hon so với

việc sử dụng mảng tĩnh.

Về chức năng quản lý, chương trình đã cài đặt được các thao tác cơ bản đối với sinh
viên, môn học và lớp học phần như thêm mới, cập nhật, xóa, tìm kiếm và hiển thị danh
sách. Các thao tác này được tổ chức thành từng module riêng, giúp mã nguồn rõ ràng và
dé bảo trì hơn. Khi thêm dữ liệu mới, chương trình có kiểm tra khóa chính để hạn chế

tình trạng trùng lặp, ví dụ như trùng mã số sinh viên, mã học phần hoặc mã lớp học phần.

Đối với phần điểm số, chương trình đã cài đặt chức năng nhập và cập nhật điểm cho
sinh viên theo từng lớp học phần. Sau khi người dùng nhập điểm quá trình và điểm cuối
kỳ, chương trình tự động tính điểm tổng kết và quy đổi sang điểm hệ 4. Ngoài ra, chương
trình cũng hỗ trợ tính GPA của sinh viên dựa trên điểm hệ 4 và số tín chỉ của các học

phần tương ứng.

75


<!-- Trang 78 / 102 -->

## Trang 78

Nhóm 16 CHƯƠNG 8. KẾT LUẬN

Chương trình cũng đã cài đặt được các thuật toán cơ bản theo yêu cầu của bài tập
lớn. Cụ thể, nhóm sử dụng tìm kiếm tuyến tính để tìm kiếm dữ liệu theo khóa và tự cài
đặt thuật toán Bubble Sort để sắp xếp danh sách sinh viên theo mã số sinh viên hoặc họ
tên. Các thuật toán này tuy đơn giản nhưng phù hợp với phạm vi đề tài và giúp nhóm

vận dụng được kiến thức về cấu trúc dữ liệu và giải thuật trong ngôn ngữ C.

Về lưu trữ dữ liệu, nhóm đã xây dựng cơ chế đọc và ghi dữ liệu thông qua các file
text trong thư mục data/. Khi chương trình khởi động, dữ liệu được nạp từ các file như
students.txt, subjects.txt, course_classes.txt và scores.txt. Khi người dùng

chọn lưu và thoát, dữ liệu trong bộ nhớ được ghi lại xuống file. Cơ chế này giúp dữ liệu

được lưu trữ lâu dài và có thể sử dụng lại ở các lần chạy sau.

Thiết kế Cài đặt Xử lý
cấu trúc dữ liệu chức năng quản lý điểm và GPA

Đọc/ghi Kiểm thử |
file text module

Bên cạnh việc cài đặt chức năng, nhóm cũng đã xây dựng một số file kiểm thử cho các

module quan trọng như mảng động, doc/ghi file, tính GPA và định nghĩa kiểu dữ liệu.
Các file kiểm thử này giúp kiểm tra các trường hợp cơ bản, trường hợp biên, đữ liệu sai
định dạng, file không tồn tại và toàn vẹn khóa ngoại. Nhờ đó, nhóm có thể phát hiện và

sửa lỗi trong quá trình hoàn thiện chương trình.

Thông qua đề tài, nhóm đã vận dụng được nhiều nội dung lý thuyết của học phần Kỹ
thuật lập trình vào một chương trình cụ thể. Chương trình sử dụng cấu trúc dữ liệu tự
cài đặt để lưu trữ dữ liệu, áp dụng thuật toán tìm kiếm tuyến tính và Bubble Sort để xử
lý danh sách, tổ chức mã nguồn theo hướng module hóa và có các bước kiểm tra dữ liệu

đầu vào nhằm phòng ngừa lỗi.

Ngoài ra, nhóm đã xây dựng các bộ kiểm thử để kiểm tra từng phần của chương trình
cũng như kiểm tra tích hợp quá trình đọc/ghi dữ liệu. Kết quả kiểm thử cho thấy các
module nền tảng hoạt động đúng với dữ liệu hợp lệ và xử lý được nhiều trường hợp dữ
liệu sai định dạng. Đây là cơ sở quan trọng để đánh giá chương trình không chỉ chạy được

mà còn có tính ổn định và dễ bảo trì.

Nhìn chung, chương trình đã đạt được mục tiêu ban đầu của đề tài. Sản phẩm cuối
cùng có cấu trúc rõ ràng, dữ liệu được tổ chức hợp lý, các chức năng chính hoạt động

được và có khả năng lưu trữ dữ liệu bằng file text. Thông qua quá trình thực hiện, nhóm

76


<!-- Trang 79 / 102 -->

## Trang 79

Nhóm 16 CHƯƠNG 8. KẾT LUẬN

đã vận dụng được nhiều kiến thức quan trọng của học phần như thiết kế chương trình
theo module, sử dung struct, quản lý bộ nhớ động, doc/ghi file, tìm kiếm, sắp xếp, kiểm

tra dữ liệu đầu vào và kiểm thử chương trình.

8.2 Hạn chế

Mặc dù chương trình Quan ly sinh vién đã đáp ứng được các yêu cầu cơ bản của đề
tài, trong quá trình thực hiện vẫn còn tồn tại một số hạn chế nhất định. Các hạn chế này
chủ yếu xuất phát từ phạm vi của bài tập lớn, thời gian thực hiện và việc chương trình

được xây dựng ở mức console đơn giản.

"Trước hết, giao diện của chương trình mới dừng lại ở dang console. Người dùng thao
tác bằng cách nhập số và nhập dữ liệu từ bàn phím, chưa có giao diện đồ họa trực quan.
Vì vậy, trải nghiệm sử dụng chưa thật sự thuận tiện nếu so sánh với các phần mềm quản
lý hoàn chỉnh. Việc hiển thị dữ liệu trên console cũng còn đơn giản, đặc biệt khi danh

sách sinh viên, môn học hoặc điểm số có nhiều bản ghi.

Thứ hai, dữ liệu của chương trình được lưu trữ bằng file text. Cách lưu trữ này dé
hiểu, dễ kiểm tra và phù hợp với yêu cầu của bài tập lớn, tuy nhiên vẫn còn một số hạn
chế. Khi dữ liệu tăng lên nhiều, việc đọc ghi toàn bộ file có thể chưa tối ưu. Ngoài ra, file
text cũng chưa có cơ chế bảo mật, phân quyền hoặc kiểm soát truy cập như khi sử dụng
cơ sở dữ liệu thực tế.

Thit ba, các thuật toán tìm kiếm và sắp xếp trong chương trình còn ở mức cơ bản.
Chương trình sử dụng tìm kiếm tuyến tính và thuật toán Bubble Sort để xử lý dữ liệu.
Các thuật toán này dễ cài đặt và phù hợp với quy mô nhỏ, nhưng chưa thật sự hiệu quả
khi số lượng bản ghi lớn. Ví dụ, Bubble Sort có độ phức tạp thời gian O(n?) nên tốc độ

xử lý sẽ giảm khi danh sách sinh viên tăng lên nhiều.

Thứ tư, chức năng tính điểm và GPA mới được cài đặt ở mức cơ bản. Chương trình
đã hỗ trợ tính điểm tổng kết, quy đổi điểm hệ 4 và tính GPA theo trọng số tín chỉ. Tuy
nhiên, chương trình chưa xử lý đầy đủ các trường hợp phức tạp trong thực tế như học

lại, cải thiện điểm, hủy học phần, điểm chữ hoặc các quy định học vụ chi tiết khác.

'Thứ năm, việc kiểm tra dữ liệu đầu vào tuy đã được thực hiện ở nhiều vị trí nhưng van
còn có thể cải thiện thêm. Chương trình đã kiểm tra các lỗi cơ bản như mã rỗng, trùng
khóa, điểm ngoài khoảng hợp lệ hoặc dữ liệu sai định dạng trong file. Tuy nhiên, một số
kiểm tra nâng cao như chuẩn hóa họ tên, kiểm tra ngày sinh theo lịch thực tế, tìm kiếm

không phân biệt chữ hoa chữ thường hoặc xử lý dữ liệu tiếng Việt có dấu vẫn còn hạn ché.

77


<!-- Trang 80 / 102 -->

## Trang 80

Nhóm 16 CHƯƠNG 8. KẾT LUẬN

Ngoài ra, chương trình hiện chủ yếu lưu di liệu khi người dùng chọn chức năng lưu và
thoát. Do đó, nếu chương trình bị đóng đột ngột trước khi lưu, các thay đổi trong phiên
làm việc hiện tại có thể chưa được ghi xuống file. Đây là hạn chế cần được xem xét nếu

muốn phát triển chương trình theo hướng ổn định hơn.

Cuối cùng, mặc dù nhóm đã xây dựng một số file kiểm thử cho các module quan
trọng, phạm vi kiểm thử vẫn chưa bao phủ toàn bộ mọi tình huống có thể xảy ra. Các
test case hiện tại chủ yếu tập trung vào các chức năng chính, dữ liệu hợp lệ, một số dữ
liệu sai định dạng và trường hợp biên cơ bản. Trong thực tế, chương trình cần được kiểm
thử thêm với dữ liệu lớn hơn và nhiều tình huống nhập liệu phức tạp hơn.

Nhìn chung, các hạn chế trên không ảnh hưởng quá lớn đến mục tiêu chính của bài
tập lớn, nhưng là cơ sở để nhóm xác định hướng cải tiến trong tương lai. Nếu có thêm
thời gian, chương trình có thể được mở rộng về giao diện, thuật toán, cơ chế lưu trữ dit

liệu và phạm vi kiểm thử để trở nên hoàn thiện hơn.

8.3 Hướng phát triển

Từ những kết quả đã đạt được và các hạn chế còn tồn tại, chương trình Quản lý sinh
tiên có thể được tiếp tục phát triển theo nhiều hướng khác nhau để trở nên hoàn thiện
hơn. Các hướng phát triển này tập trung vào việc cải thiện giao diện, tối ưu thuật toán,

nâng cao khả năng lưu trữ dữ liệu, mở rộng chức năng va tăng độ ồn định của chương trình.

Trong tương lai, chương trình có thể được phát triển theo một số hướng. Về thuật
toán, nhóm có thể thay Bubble Sort bằng các thuật toán hiệu quả hơn như Quick Sort
hoặc Merge Sort, đồng thời nghiên cứu áp dụng tìm kiếm nhị phân trong những trường
hợp dit liệu đã được sắp xếp phù hợp. Về lưu trữ, chương trình có thể chuyển từ file text

sang cơ sở dữ liệu để tăng khả năng quản lý và truy vấn di liệu.

Về giao diện, chương trình có thể được mở rộng từ console sang giao diện đồ họa hoặc
giao diện web để thân thiện hơn với người dùng. Ngoài ra, có thể bổ sung các chức năng
thống kê kết quả học tập, xuất bảng điểm, lọc sinh viên theo học lực và phân quyền người
dùng. Những hướng phát triển này giúp chương trình gần hơn với một hệ thống quản lý

sinh viên thực tế.

78


<!-- Trang 81 / 102 -->

## Trang 81

Nhóm 16 CHƯƠNG 8. KẾT LUẬN

Giai đoạn 1
Hoàn thiện phiên bản console

| Giai đoạn 2

'Tối ưu thuật toán và kiểm thử

Giai đoạn 3

MG rộng xử lý điểm và báo cáo

Giai đoạn 4
Nang cấp lưu trữ dữ liệu

| Giai đoạn 5

Phát triển giao diện đồ họa

Hình 7.3. Lộ trinh phát triển chương trành trong tương lai

"Trước hết, chương trình có thể được phát triển từ giao diện console sang giao diện đồ
họa. Giao diện đồ họa sẽ giúp người dùng thao tác trực quan hơn thông qua các nút bam,
bảng dữ liệu, ô nhập liệu và thông báo lỗi rõ ràng. Diều này đặc biệt hữu ích khi chương

trình có nhiều dữ liệu sinh viên, môn học, lớp học phần và điểm số cần hiển thị cùng lúc.

Thứ hai, cơ chế lưu trữ dữ liệu có thể được cải tiến. Hiện tại, chương trình sử dụng
file text để lưu dữ liệu, phù hợp với phạm vi bài tập lớn. Trong tương lai, có thể thay
thế hoặc bổ sung cơ sở dữ liệu như SQLite, MySQL hoặc PostgreSQL để quản lý dữ liệu
tốt hơn. Việc sử dụng cơ sở dữ liệu sẽ giúp chương trình hỗ trợ truy vấn nhanh, đảm bảo

toàn vẹn dữ liệu tốt hơn và thuận tiện hơn khi dữ liệu có quy mô lớn.

Thứ ba, các thuật toán tìm kiếm và sắp xếp có thể được tối ưu. Hiện tại, chương trình
sử dụng tìm kiếm tuyến tính và Bubble Sort. Trong các phiên bản tiếp theo, có thể bổ
sung tìm kiếm nhị phân đối với dữ liệu đã được sắp xếp, hoặc sử dụng các thuật toán sắp
xếp hiệu quả hơn như Quick Sort, Merge Sort. Điều này giúp cải thiện tốc độ xử lý khi

số lượng sinh viên hoặc bản ghi điểm tăng lên.

Thứ tư, chức năng xử lý điểm va GPA có thể được mở rộng để sát với thực tế hơn.
Chương trình có thể bổ sung cách xử lý điểm chữ, học lại, học cải thiện, hủy học phần
hoặc phân loại học lực chi tiết hơn. Ngoài GPA hệ 4, chương trình cũng có thể bổ sung

tính điểm trung bình hệ 10 theo học kỳ, theo năm học hoặc theo toàn khóa.

79


<!-- Trang 82 / 102 -->

## Trang 82

Nhóm 16 CHƯƠNG 8. KẾT LUẬN

Thứ năm, chương trình có thể mở rộng thêm các chức năng báo cáo. Ví dụ, hệ thống
có thể thống kê danh sách sinh viên theo lớp, xếp hang sinh viên theo GPA, lọc sinh viên
theo học lực, xuất bảng điểm ra file hoặc tạo báo cáo tổng hợp theo từng lớp học phần.
Những chức năng này sẽ giúp chương trình không chỉ quản lý dữ liệu mà còn hỗ trợ phân

tích kết quả học tập.

Thứ sáu, việc kiểm tra dữ liệu đầu vào có thể tiếp tục được hoàn thiện. Chương trình
có thể bổ sung kiểm tra ngày sinh theo lịch thực tế, chuẩn hóa họ tên, tìm kiếm không
phân biệt chữ hoa chữ thường, xử lý tốt hơn dữ liệu tiếng Việt có dau và cảnh báo chi
tiết hơn khi người dùng nhập sai. Điều này giúp chương trình thân thiện hơn và hạn chế

lỗi dữ liệu trong quá trình sử dụng.

Ngoài ra, nhóm có thể mở rộng phạm vi kiểm thứ chương trình. Bên cạnh các file
kiểm thử hiện có, chương trình nên được kiểm thử thêm với dữ liệu lớn, dữ liệu sai phức
tạp và nhiều tình huống thao tác liên tiếp. Việc kiểm thử đầy đủ hơn sẽ giúp phát hiện

lỗi tiềm ẩn và tăng độ tin cậy của chương trình.

Nhìn chung, các hướng phát triển trên giúp chương trình có thể tiến gần hơn đến một
hệ thống quản lý sinh viên hoàn chỉnh. Mặc dù phiên bản hiện tại đã đáp ứng được yêu
cầu chính của bài tập lớn, việc tiếp tục cải tiến về giao diện, lưu trữ, thuật toán, kiểm

thử và chức năng nghiệp vụ sẽ giúp chương trình có tính ứng dụng cao hơn trong thực tế.

80


<!-- Trang 83 / 102 -->

## Trang 83

Tài liệu tham khảo

(1)

V. T. Nam, Bai giảng Kỹ thuật lập trình - Chương 1: Tổng quan [Slide PowerPoint],
Hà Nội: Dai Học Bách Khoa Hà Nội, 2022.

V. T. Nam, Bài giảng Kỹ thuật lập trình - Chương 2: Cấu trúc dữ liệu và giải thuật
[Slide PowerPoint], Hà Nội: Dai Học Bách Khoa Hà Nội, 2022.

V. T. Nam, Bài giảng Kỹ thuật lập trình - Chương 3: Kỹ thuật thiết kế chương trình
[Slide PowerPoint], Hà Nội: Dai Hoc Bách Khoa Hà Nội, 2022.

V. T. Nam, Bài giảng Kỹ thuật lập trình - Chương 4: Defensive Programming Lập
trình phòng ngừa [Slide PowerPoint], Hà Nội: Dại Học Bách Khoa Hà Nội, 2022.

V.T. Nam, Bài giảng Kỹ thuật lập trình - Chương 5: Gỡ lỗi và kiểm thử [Slide
PowerPoint], Ha Nội: Dai Học Bách Khoa Hà Nội, 2022.

V. T. Nam, Bài giảng Kỹ thuật lập trình - Chương 6: Tối ưu mã [Slide PowerPoint],
Hà Nội: Đại Học Bách Khoa Hà Nội, 2022.

V. T. Nam, Bài giảng Kỹ thuật lập trình - Chương 7: Lập trình bất đồng bộ
Asynchronous programming [Slide PowerPoint], Hà Nội: Dai Học Bách Khoa Hà Nội,
2022.

81


<!-- Trang 84 / 102 -->

## Trang 84

10

11

12

13

14

15

18

19

20

21

22

23

24

25

26

27

PHỤ LỤC

Phụ lục A. Code hàm main

Phu lục này trình bay code ham main của chương trình. Day là hàm điều khiển luồng

hoạt động chính, bao gồm khởi tạo dữ liệu, đọc dữ liệu từ file, gọi giao diện menu, lưu dữ

liệu và giải phóng bộ nhớ khi kết thúc chương trình.

#include <stdio.h>
#include "fileio.h"

#include "ui.h"

int main(void)

{
StudentArray students;
SubjectArray subjects;
CourseClassArray classes;

ScoreArray scores;

if ('sa_init(&students, 4)) {
printf("Loi khoi tao mang sinh vien.\n");

return 1;

if (!suba_init (&subjects, 4)) {
printf("Loi khoi tao mang mon hoc.\n");
sa_clear(&students);

return 1;

if (!†cca init(&classes, 4)) {
printf("Loi khoi tao mang lop hoc phan.\n");
sa_clear(&students);
suba_clear (&subjects) ;

return 1;

82


<!-- Trang 85 / 102 -->

## Trang 85

39

40

41

42

43

44

46

A7

48

49

56

57

58

59

60

61

62

63

64

Nhom 16 TAI LIEU THAM KHAO

if (!sca_init(&scores, 4)) {
printf("Loi khoi tao mang diem.\n");
sa_clear (students);
suba_clear (&subjects) ;
cca_clear (&classes);

return 1;

loadAllData(
&students,
&subjects,
&classes,
&scores

3

showMainMenu (
&students,
&subjects,
&classes,
&scores

3

saveAllData(
&students,
&subjects,
&classes,
&scores

3

sa_clear (&students) ;
suba_clear (&subjects) ;
cca_clear (&classes) ;

sca_clear (kscores) ;

return 0;

Listing 8.1: Code ham main của chương trình

83


<!-- Trang 86 / 102 -->

## Trang 86

10

11

10

Nhóm 16 TÀI LIỆU THAM KHẢO

Phụ lục B. Một số hàm xử lý chính

B.1. Hàm thao tác với mảng động

Phần này trình bày một số hàm tiêu biểu dùng để thao tác với mảng động StudentArray.

B.1.1. Hàm sa_init

Hàm sa_init dùng để khởi tạo mảng động sinh viên. Hàm cấp phát vùng nhớ ban

đầu cho mảng, đặt size = 0 và thiết lập capacity bằng sức chứa ban đầu.

int sa_init(StudentArray* arr, int init cap) {

if (init_cap <= 0) init_cap = 4;

arr->data = (Student*)malloc(init_cap * sizeof (Student));
a == NULL) return 0;

if (arr->dat

arr->size = 0;

arr->capacity = init_cap;

return 1;

Listing 8.2: Ham khởi tao mang động StudentArray

B.1.2. Ham sa_add

Hàm sa_add dùng để thêm một sinh viên vào cuối mảng. Nếu mảng đã đầy, hàm gọi

sa_resize để mở rộng vùng nhớ trước khi thêm phần tử mới.

int sa_add(StudentArray* arr, Student s) {
if (arr->size >= arr->capacity) {

if (!'sa_resize(arr)) return 0;

arr->data[arr->size] = s;

arr->size++;

return 1;

Listing 8.3: Ham thêm sinh viên vào mang động

84


<!-- Trang 87 / 102 -->

## Trang 87

Nhóm 16 TÀI LIỆU THAM KHẢO

B.1.3. Hàm sa_find

Ham sa_find dùng để tim sinh viên theo MSSV. Hàm duyệt lần lượt các phần tử
trong mảng và so sánh MSSV bằng strcmp. Nếu tìm thấy, hàm trả về vị trí của sinh viên;

nếu không, trả về -1.

int sa_find(StudentArray* arr, const char* mssv) {
for (int i = 0; i < arr->size; i++) {
if (strcmp(arr->data[i].mssv, mssv) == 0) {

return i;

return -1;

Listing 8.4: Ham tim sinh vién theo MSSV

B.1.4. Ham sa_remove

Ham sa_remove dùng để xóa sinh viên tại vi tri index. Sau khi xóa, các phan tử phía

sau được dịch sang trái để mảng không bị rỗng ở giữa.

int sa_remove(StudentArray* arr, int index) {

if (index < 0 || index >= arr->size) return 0;

for (int i = index; i < arr->size - 1; i++) {
arr->data[i] = arr->data[i + 1];

}

arr->size--;

return 1;

Listing 8.5: Ham xóa sinh viên khỏi mang dong

85


<!-- Trang 88 / 102 -->

## Trang 88

Nhóm 16 TÀI LIỆU THAM KHẢO

B.2. Hàm đọc và ghi dữ liệu

Phần này trình bày hai hàm tổng hợp dùng để đọc và ghi toàn bộ dữ liệu của chương
trình. Hai hàm nay được cài đặt trong file fileio.c.
B.2.1. Ham 1oadA11Data

Hàm loadAllData dùng để đọc toàn bộ dữ liệu từ các file text vào bộ nhớ. Hàm lần

lượt gọi các ham đọc dit liệu sinh viên, môn học, lớp học phần và điểm số.

void loadAllData(StudentArray* students,
SubjectArray* subjects,
CourseClassArray* classes,
ScoreArray* scores) {
loadStudents(students, STUDENT_FILE);
loadSubjects(subjects, SUBJECT_FILE);
loadCourseClasses(classes, COURSE_CLASS_FILE) ;
loadScores(scores, SCORE_FILE);

Listing 8.6: Ham đọc toàn bộ dit liệu từ file

Trong hàm trên, mỗi loại dữ liệu được doc từ một file riêng. Dữ liệu sinh viên được
nạp vào StudentArray, dữ liệu môn học được nạp vào SubjectArray, dữ liệu lớp học

phần được nạp vào CourseClassArray và dữ liệu điểm số được nạp vào ScoreArray.

B.2.2. Hàm saveAllData

Hàm saveAllData dùng để ghi toàn bộ dữ liệu hiện có trong bộ nhớ xuống các file
text tương ứng. Hàm này được gọi khi chương trình kết thúc để lưu lại dữ liệu sau quá

trình sử dụng.

void saveAllData(StudentArray* students,
SubjectArray* subjects,
CourseClassArray* classes,
ScoreArray* scores) {
saveStudents(students , STUDENT_FILE);
saveSubjects(subjects, SUBJECT_FILE) ;
saveCourseClasses(classes, COURSE_CLASS_FILE) ;
saveScores(scores, SCORE_FILE);

Listing 8.7: Ham ghi toàn bộ dữ liệu xuống file

86


<!-- Trang 89 / 102 -->

## Trang 89

10

11

13

14

15

16

18

Nhóm 16 TÀI LIỆU THAM KHẢO

Hàm saveAllData giúp quá trình lưu di liệu được thực hiện tập trung. Thay vì gọi
từng hàm ghi dữ liệu ở nhiều vị trí khác nhau, chương trình chỉ cần gọi một hàm duy

nhất để lưu toàn bộ danh sách sinh viên, môn học, lớp học phần và điểm số.
B.3. Hàm xử lý điểm va GPA
Phần này trình bày một số hàm tiêu biểu dùng để tính điểm tổng kết, quy đổi điểm

hệ 4 và tính GPA của sinh viên.

B.3.1. Hàm ca1culateDiemTK

Hàm calculateDiemTK dùng để tính điểm tổng kết từ điểm quá trình và điểm cuối
kỳ.

float calculateDiemTK(float diemQT, float diemCK)
{
return (diemQT + diemCK) / 2.0f;

Listing 8.8: Ham tinh diém tong két

B.3.2. Ham convertToHe4

Ham convertToHe4 dùng để quy đổi điểm tổng kết hệ 10 sang điểm hệ 4 theo các

mốc điểm đã quy định.

float convertToHe4(float diemTK)
{
if (diemTK >= 8.5f)

return 4.0f;

if (diemTK >= 8.0f)

return 3.5f;

if (diemTK >= 7.0f)

return 3.0f;

if (diemTK >= 6.5f)

return 2.5f;

if (diemTK >= 5.5f)

return 2.0f;

if (diemTK >= 5.0f)

87


<!-- Trang 90 / 102 -->

## Trang 90

19

20

21

22

23

24

10

11

12

13

14

15

18

19

20

21

22

23

24

25

26

27

Nhóm 16 TÀI LIỆU THAM KHẢO

return 1.5f;

if (diemTK >= 4.0f)

return 1.0f;

return 0.0f;

Listing 8.9: Ham quy đổi điểm hệ 10 sang hệ 4

B.3.3. Hàm calculateStudentGPA4

Hàm calculateStudentGPA4 dùng để tính GPA hệ 4 của một sinh viên. Hàm duyệt
qua các bản ghi điểm của sinh viên, tìm lớp học phần và môn học tương ứng để lấy số

tín chỉ, sau đó tính GPA theo trọng số tín chỉ.

float calculateStudentGPA4 (
const char* mssv,
ScoreArray* scores,
CourseClassArray* classes,

SubjectArray* subjects

)
{
float tongDiem = 0.0f;
int tongTinChi = 0;
for(int i = 0; i < scores->size; i++)
{
ScoreRecord sc = scores->data[i];
if(strcmp(sc.mssv, mssv) != 0)

continue;

int classIndex =
cca_find(
classes,
sc.maLHP
);3

if(classIndex == -1)

continue;

CourseClass cc =

88


<!-- Trang 91 / 102 -->

## Trang 91

39

40

41

42

43

44

46

A7

48

49

52

53

54

Nhóm 16

TÀI LIỆU THAM KHẢO

classes->data[classIndex] ;

int subjectIndex =
suba_find(
subjects,
cc.maHP

3

if (subjectIndex == -1)

continue;

Subject sub =
subjects ->data[subjectIndex];

tongDiem +=
sc.diemHe4 *
sub.soTinChi;
tongTinChi +=
sub.soTinChi;
if(tongTinChi == 0)

return 0.0f;

return tongDiem / tongTinChi;

Listing 8.10: Ham tinh GPA hệ 4 của sinh viên

B.3.4. Ham calculateStudentGPA10

Ham calculateStudentGPA10 có cách xử lý tương tự hàm tinh GPA hệ 4, nhưng sử

dụng điểm tổng kết diemTK để tính GPA theo hệ 10.

float calculateStudentGPA10(
const char* mssv,
ScoreArray* scores,
CourseClassArray* classes,

SubjectArray* subjects

float tongDiem = 0.0f;

89


<!-- Trang 92 / 102 -->

## Trang 92

18

19

20

21

22

23

24

25

26

27

28

29

30

37

38

3g

40

41

42

43

44

45

46

A7

48

49

Nhom 16

TAI LIEU THAM KHAO

int

tongTinChi 0;

for(int i = 0; i < scores->size; i++)

{

ScoreRecord sc = scores->data[i];

if(strcmp(sc.mssv, mssv) != 0)

continue;

int classIndex =
cca_find(
classes,
sc.maLHP
3

if(classIndex == -1)

continue;

CourseClass cc =

classes ->data[classIndex];

int subjectIndex =
suba_find(
subjects,
cc.maHP

3

if(subjectIndex == -1)

continue;

Subject sub =
subjects->data[subjectIndex];

tongDiem +=
sc.diemTK *

sub.soTinChi;

tongTinChi +=

sub.soTinChi;

90


<!-- Trang 93 / 102 -->

## Trang 93

Nhóm 16 TÀI LIỆU THAM KHẢO

50 if(tongTinChi == 0)

51 return 0.0f;

52

53 return tongDiem / tongTinChi;
oa) }

Listing 8.11: Ham tinh GPA hệ 10 của sinh viên

B.4. Hàm tìm kiếm và sắp xếp

Phần này trình bày một số hàm tiêu biểu dùng để tìm kiếm và sắp xếp sinh viên.

B.4.1. Ham searchStudentByMSSV

Ham searchStudentByMSSV dùng để tim sinh viên theo MSSV. Nếu tìm thấy, ham

trả về con trỏ đến sinh viên; nếu không tìm thấy, hàm trả về NULL.

iStudent* searchStudentByMSSV (

2 StudentArray* students,

3 const char* mssv

4|)

sị {

6 int idx =

7 sa_find(students, mssv);
8

9 if(idx == -1)

10 return NULL;

11

12 return &students->data[idx];
13 }

Listing 8.12: Hàm tìm sinh viên theo MSSV

B.4.2. Hàm sortStudentByMSSV

Hàm sortStudentByMSSV dùng để sắp xếp sinh viên tăng dần theo MSSV bằng thuật
toán Bubble Sort.

ilvoid sortStudentByMSSV(StudentArray* students)

2 {

3 for(int i = 0; i < students->size - 1; itt)

4 {

5 for(int j = 0; j < students->size - i - 1; jtt)
6 {

91


<!-- Trang 94 / 102 -->

## Trang 94

10

12

13

14

15

16

18

19

20

21

23

10

11

13

14

15

16

18

Nhóm 16 TÀI LIỆU THAM KHẢO

if (strcmp (
students ->data[j].mssv,
students->data[j + 1].mssv
) > 0)
{
Student temp =
students->data[j];

students->data[j] =
students->data[j + 1];

students->data[j + 1] =
temp;

Listing 8.13: Hàm sắp xếp sinh viên theo MSSV

B.4.3. Ham sortStudentByName

Ham sortStudentByName dùng để sắp xếp sinh viên tăng dần theo họ tên. Ham so

sánh trường hoTen của hai sinh viên liền kề và hoán đổi nếu sai thứ tự.

void sortStudentByName (StudentArray* students)

{
for(int i = 0; i < students->size - 1; i++)
{
for(int j = 0; j < students->size - i - 1; j++)
{

if (strcmp (
students ->data[j].hoTen,
students->data[j + 1].hoTen
) > 0)
{
Student temp =
students->datal[j];

students->data[j] =
students->data[j + 1];

stuđents->data[j + 1] =

92


<!-- Trang 95 / 102 -->

## Trang 95

19

20

21

22

Nhóm 16

TÀI LIỆU THAM KHẢO

temp;

Listing 8.14: Hàm sắp xếp sinh viên theo họ tên

Phụ lục C. File dữ liệu mẫu

Phụ lục này trình bày một số file dữ liệu mẫu được sử dụng trong chương trình. Các

file dữ liệu được lưu dưới dang text, mỗi dòng là một bản ghi và các trường được phân

tách bằng ký tự |.

C.1. File students.txt

MSSV|HoTen|Lop|Birthday

202400000|Nguyen Van Toan|K69-MI1-01] 15/08/2006
202400001|Tran Quan Anh|K69-MI1-02] 20/03/2006
202400002|Le Hoang Thai |K69-MI1-03 |05/11/2005
202400003|Vu Thi Hoa |K69-MT1-04 | 22/09/2002
202400004|Nguyen Thi Mai |K69-MT1-01 |10/05/2004
202400010|Tran Van Nam|K69-MT1-02 | 18/02/2004

C.2. File subjects.txt

MaHP | TenHP |SoTinChi

MI3310|Ky Thuat Lap Trinh|2

MI3060|Cau Truc Du Lieu & Thuat Toan|3
MI3090|Co So Du Lieul3

MI2020|Kien truc may tinh|2
MI3040|Toan Roi Rac|3

C.3. File course_classes.txt

MaLHP | MaHP | HocKy | NamHoc
169313|M1I3310|1|2025
169307 |MI3060 | 2 |2025
169320 |MT3090 | 3|2025
169400 |M12020 | 1|2025
169401 |MT3040 | 2 |2025

93


<!-- Trang 96 / 102 -->

## Trang 96

Nhóm 16

TÀI LIỆU THAM KHẢO

C.4. File scores.

MSSV | MaLHP | DiemQT|DiemCK | DiemTK | DiemHe4

202400000 | 169313 | 8.
202400000 | 169307 |8.
202400000 | 169320 | 6.
202400000 | 169400 | 9.
202400000 | 169401 |7.
202400001 | 169307 |9.
202400001 |169313| 7.
202400001 | 169320 | 8.
202400001 | 169400 | 6.
202400002 | 169320 | 7.
202400002| 169313 | 9.
202400002| 169307 | 5.
202400002 | 169401 |8.
202400008 | 169313 | 6.
202400008 169307 |7.
202400008 | 169320 | 8.
202400004] 169313 | 5.
202400004 | 169400 | 9.
202400004] 169401 |7.
202400010 | 169307 | 4.
202400010 | 169313 | 6.
202400010 | 169320 |8.

txt

5017.0017.7513.00
0019.0018.5014.00
507.006. 75|2.50
00 |8. 00 |8. 504. 00
5018.0017.7513.00
0018.5018.7514.00
0018.0017.5013.00
0017.0017.5013.00
0016.5016.25|2.00
0017.5017.2513.00
0019.5019.2514.00
5016.0015.7512.00
5019.0018.7514.00
0015.5015.7512.00
0016.5016.7512.50
008. 508. 25 |3. 50
0014.5014.7511.00
50110.0019.7514.0
0017.5017.2513.00
0013.5013.75]0.00
5017.0016.7512.50
0017.0017.5013.00

0

94


<!-- Trang 97 / 102 -->

## Trang 97

Nhóm 16 TÀI LIỆU THAM KHẢO

Phụ lục D. Một số kết quả kiểm thử

D.1. Phân loại kiểm thử

Bảng 8.1: Phân loại kiểm thử áp dụng trong chương trình

Loại kiểm thử Áp dụng trong đề tài

Internal Testing Nhóm thiết kế các bộ dữ liệu để kiểm
tra chương trình, gồm dữ liệu hợp lệ,
dit liệu trùng khóa, điểm ngoài khoảng,
file thiếu trường và dữ liệu sai quan hệ
khóa ngoại.

External Testing Nhóm xây dung các file kiểm thử
như test_types.c, test_arrays.c,
test_fileio_unit.c, test_gpa.c và
test_fi1eio.c để chương trình có thể
tự kiểm tra một số module quan trọng.
Black-box Testing Các test case thao tác qua giao diện
console được thực hiện dựa trên yêu
cầu chức năng. Người kiểm thử nhập
dữ liệu, quan sát kết quả đầu ra và so
sánh với kết quả mong đợi mà không
cần xét chi tiết mã nguồn.

White-box Testing Cac file kiém tht tu dong goi truc tiép
đến các ham bên trong chương trình
như hàm thao tác mảng động, hàm
đọc/ghi file, hàm tính điểm và hàm tính
GPA. Cách kiểm thử này dựa trên hiểu
biết về cầu trúc và logic bên trong mã
nguồn.

Test tĩnh Nhóm kiểm tra tài liệu, mã nguồn, cấu
trúc thư mục, khai báo hàm, định dạng
file dữ liệu và các ràng buộc dữ liệu mà
không cần thực thi chương trình.

Test động Nhóm chạy trực tiếp chương trình
q1sv.exe để kiểm thử giao diện, đồng
thời chạy các file kiểm thử tự động để
kiểm tra kết quả khi chương trình thực
thi.

95


<!-- Trang 98 / 102 -->

## Trang 98

Nhóm 16 TÀI LIỆU THAM KHẢO

D.2. Một số hình ảnh kiểm thử

STUDENT MANAGEMENT SYSTEM
. Quan sinh vien
. Quan mon hoc
. Quan lop hoc phan
. Quan diem so
. Bao cao / bang diem
. Hien thi tat ca du Lieu
. Luu va thoat
hap tua cho 1

QUAN LY SINH VIEN
. Hien thi danh sach sinh vien
. Them sinh vien
. Sua sinh vien
. Xoa sinh vien
. Tim sinh vien
. Sap xep danh sach sinh vien
. Quay Lai
tua chon: 2
MSSV: 202499999
ho ten: Nguyen Test UI
Lop: MI1-01-K69
ngay sinh DD/MM/YYYY: 22/082006
sinh khong hop le. Vi du dung: 15/08/2006
ngay sinh DD/MM/YYYY: 22/08/2006
sinh vien thanh cong.

Hình 8.1: TC01 — Thêm sinh viên hợp lệ

== QUAN LY SINH VIEN =
Hien thi danh sach sinh vien
Them sinh vien
Sua sinh vien
Xoa sinh vien
Tim sinh vien

Sap xep danh sach sinh vien

. Quay Lai

Nhap tua chon: 2

Nhap MSSV: 202499999

MSSV da ton tai. Vui Long nhap MSSV khac.
Nhap MSSV: |

@©@œŒœ%ỚƠẽĐPU)2E Il

Hình 8.2: TC02 — Thêm sinh viên trùng MSSV

96


<!-- Trang 99 / 102 -->

## Trang 99

Nhóm 16 TÀI LIỆU THAM KHẢO

== QUAN LY MON HOC ==

. Hien thi danh sach mon hoc
. Them mon hoc
Sua mon hoc
. Xoa mon hoc
. Tim mon hoc

. Quay Lai
Nhap lua chon: 2
Nhap MaHP: TESTO1
Nhap ten hoc phan: Mon Test UI
Nhap so tin chi: 3
Them mon hoc thanh cong.

Hình 8.3: TC03 — Thêm môn học hợp lệ

QUAN LY MON HOC
. Hien thi danh sach mon hoc
. Them mon hoc
. Sua mon hoc
. Xoa mon hoc
. Tim mon hoc
9. Quay Lai
Nhap tua chon: 2
Nhap MaHP: TESTO1
MaHP da ton tai.
Nhap MaHP:

Hình 8.4: TC04 — Thêm môn học trùng mã

QUAN LY LOP HOC PHAN ==
. Hien thi danh sach lop hoc phan
. Them lop hoc phan
. Sua Lop hoc phan
. Xoa Lop hoc phan
. Tim lop hoc phan
. Quay Lai

Nhap tua chon: 2

Nhap MaLHP: TESTLHP1

Nhap MaHP: TESTO1

Nhap hoc ky (1-3): 1

Nhap nam hoc: 2026

Them Lop hoc phan thanh cong.

Hình 8.5: TC05 — Thêm lớp học phần hợp lệ

97


<!-- Trang 100 / 102 -->

## Trang 100

Nhóm 16

TÀI LIỆU THAM KHẢO

= QUAN LY LOP HOC PHAN ==
. Hien thi danh sach lop hoc phan
. Them Lop hoc phan
. Sua Lop hoc phan
. Xoa Lop hoc phan

. Tim Lop hoc phan
. Quay Lai
Nhap Lua chon: 2
Nhap MaLHP: TESTLHP1
MaLHP da ton tai.
Nhap MaLHP:

Hình 8.6: TC06 — Thêm lớp hoc phần với MaHP khong tồn tại

QUAN LY DIEM

. Hien thi danh sach diem

. Nhap diem

. Cap nhat diem

. Tim diem

. Quay Lai
Nhap tua chon: 2
Nhap MSSV: 202499999
Nhap MaLHP: TESTLHP61
Nhap diem qua trinh (0-
Nhap diem cuoi ky (0-10): 10
Them diem thanh cong. DiemTK = 10.00, He4 = 4.00

Hình 8.7: TC07 — Nhập điểm hợp lệ

QUAN LY DIEM ==
Hien thi danh sach diem
Nhap diem
Cap nhat diem
. Tim diem
. Quay Lai

Nhap lua ch 2

Nhap MSSV: 21199998

Nhap MaLHP: TESTLHPO1

Nhap diem qua trinh (0-10): 11

Gia tri phai nam trong khoang [0.00, 10.00].
Nhap diem qua trinh (0-10): -1

Gia tri phai nam trong khoang [0.00, 10.00].
Nhap diem qua trinh (0-10):

Hình 8.8: TC08 — Nhập điểm ngoài khoảng

98


<!-- Trang 101 / 102 -->

## Trang 101

Nhóm 16 TÀI LIỆU THAM KHẢO

QUAN LY DIEM =
Hien thi danh sach diem
Nhap diem
Cap nhat diem
Tim diem

. Quay Lai
Nhap tua chon: 2
Nhap MSSV: 202188888
MSSV khong ton tai trong danh sach sinh vien.
Nhap MSSV:

Hình 8.9: TC09 — Nhập điểm cho sinh viên không tồn tại

QUAN LY DIEM =
Hien thi danh sach diem
. Nhap diem
. Cap nhat diem
. Tim diem
. Quay Lai
Nhap lua choi 2
Nhap MSSV: 99999
Nhap MaLH TESTLHPO1
Ban ghi diem da ton tai. Hay dung chuc nang cap nhat diem.

Hinh 8.10: TC11 — Nhap diém tring

QUAN LY DIEM
Hien thi danh sach diem

. Nhap diem

. Cap nhat diem

. Tim diem

. Quay Lai
Nhap tua chon: 3
Nhap MSSV: 202499999
Nhap MaLHP: TESTLHPO1
Nhap diem qua trinh moi (0-10): 9
Nhap diem cuoi ky moi (0-10): 7
Cap nhat diem thanh cong. DiemTK = 8.00, He4 = 3.50

Hinh 8.11: TC12 — Cap nhat diém

= = BAO CAO

1. Bang diem cua mot sinh vien

2. Bang diem cua mot lop hoc phan

9. Quay lai

Nhap tua chon: 1

Nhap MSSV can xem bang diem: 2499999

Bang diem sinh vien: 202499999 - Nguyen Test UI

MaLHP | DiemQT | DiemCH | DiemTK

TESTLHPO1 | 9.06 | 7.00 | 8.00

GPA he 10 : 8.00
GPA he 4: 3.59
Hoc Luc : Gioi

Hình 8.12: TC15 — Xếp loại học lực

99


<!-- Trang 102 / 102 -->

## Trang 102

Nhóm 16

TÀI LIỆU THAM KHẢO

QUAN LY SINH VIEN
1. Hien thi danh sach sinh vien
2. Them sinh vien
3. Sua sinh vien
4. Xoa sinh vien
5
6
L)
N

. Tim sinh vien

. Sap xep danh sach sinh vien
. Quay Lai

Nhap lua chon: 5

1. Tim theo MSSV
2. Tim theo ho ten
3. Tim theo Lop
Nhap tua chon:
Nhap tu khoa:

MSSV

202400000 | Nguyen Van Toan | H69-HT1-61

| Birthday

| 15/08/2006

Hình 8.13: TC16 — Tim sinh viên tồn tại

QUAN LY SINH VIEN
. Hien thi danh sach sinh vien
. Them sinh vien
. Sua sinh vien
oa sinh vien
. Tim sinh vien
Sap xep danh sach sinh vien
. Quay Lai
Nhap lua chon: 5

Tim theo MSSV
. Tim theo ho ten
. Tim theo lop
Nhap lua chon: 1
Nhap tu khoa: 9999999

MSSV | Ho ten

Khong tim thay ket qua phu hop.

| Birthday

Hình 8.14: TC17 — Tim sinh viên không tồn tại

BAO CAO
1. Bang diem cua mot sinh vi:
2. Bang diem cua mot Lop hoc
9. Quay tai
Nhap lua chon: 2
p MaLHP can xem bang diem
HoTen Diemgr

Nguyen Van To:
Tran Quan Anh
Le Hoang Thai
Vu Thi Hoa

Nguyen Thi Mai

102490010

1. Bang diem cua mot
2. Bang diem cua mot lop hoc phan
9. Quay lai

Nhap lua chon:

DiemTk

Hình 8.15: TC21 — Hiển thi bảng điểm lớp hoc phần

100
