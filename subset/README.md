Vấn đề: Cho dãy A, N phần tử nguyên. Hãy in ra tất cả các tập con các khác rỗng của A mà có tổng bằng một số S cho trước.
Giải quyết: Duyệt bằng cách chia đôi tập hợp, độ phức tạp tính toán O(2^(N/2)).
Dữ liệu cho phép: 
	N <= 55
	A[i], S <= 2^63 - 1
Hướng dẫn sử dụng:
	- Compile file main.cpp và checker.cpp ra file thực thi (*.exe, *.bin, ...).
	- Luôn giữ cho các file sau đây ở cùng một thư mục (directory):
		+ main.*
		+ checker.*
		+ in.txt
		+ out.txt
		+ log.txt
	  * là phần mở rộng của file thực thi, tùy vào hệ điều hành có thể sẽ khác nhau (exe, bin, ..)
	- Cấu trúc file:
		+ in.txt: 
		Day so				Tong {S}
		{A[1]}
		{A[2]}
		{A[..]}
		{A[N]}
		+ out.txt:
		#x-y: d[1], d[2], d[..], d[y]
		.....
		//footer.
		trong đó: x là số thứ tự tập con tìm thấy.
			       y là số phần tử của tập con d[].
		+ log.txt
		#x: {Ok/Wrong}
		tệp này cho biết tập con số hiệu x có tổng đúng bằng S cho trước không.
	- Cách thực thi:
		+ Chuẩn bị dữ liệu cho file in.txt.
		+ Chạy file thực thi main.*. Chức năng: Tạo các tập con theo yêu cầu và xuất ra file out.txt.
		+ Chạy file thực thi checker.*. Chức năng: Kiểm tra bước đầu kết quả trong file out.txt có chính xác hay không.
		+ Kiểm tra file out.txt và log.txt
Ghi chú:
	- Các môi trường biên dịch C++ thông dụng
		minGW <http://www.mingw.org/>
		gnu <http://www.gnu.org/>
	- Platform thông dụng:
		CodeBlocks <http://www.codeblocks.org/>