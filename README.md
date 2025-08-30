# Project\_DSA

Ứng dụng C++ minh hoạ **Cấu trúc dữ liệu & Giải thuật** (DSA) thông qua một chương trình quản lý đơn giản theo mô-đun (patient, service, bill, v.v.), chạy trên **console** với menu thao tác.

---

## 🎯 Mục tiêu

* Tổ chức mã nguồn theo **mô-đun rõ ràng**, giúp rèn luyện thiết kế phần mềm.
* Vận dụng **cấu trúc dữ liệu** (vector/list/map, …) và **giải thuật** (tìm kiếm, sắp xếp) trong bài toán quản lý.
* Tạo nền tảng để mở rộng: lưu trữ dữ liệu, kiểm thử, báo cáo hiệu năng.

## ✨ Tính năng chính

* **Quản lý bệnh nhân (Patient)**: thêm / sửa / xoá / tìm kiếm / sắp xếp.
* **Quản lý dịch vụ (Service)**: thêm / sửa / xoá / niêm yết giá.
* **Hoá đơn (Bill)**: lập hoá đơn theo bệnh nhân & dịch vụ, tính tổng tiền.
* **Tra cứu**: theo mã / tên, lọc theo điều kiện cơ bản.
* **Giao diện menu console**: thao tác tuần tự, dễ thử nghiệm.
* *(Tuỳ chọn nếu đã triển khai)* **Lưu/đọc dữ liệu** từ file.

## 🧱 Kiến trúc & mô-đun

* `patient.{h,cpp}`: Định nghĩa **Patient** (ví dụ: id, name, age, gender, phone, address, …) & thao tác liên quan.
* `service.{h,cpp}`: Định nghĩa **Service** (code, name, price, …) & CRUD.
* `bill.{h,cpp}`: Định nghĩa **Bill** (id, patientId, danh sách dịch vụ, tổng tiền, …).
* `addfunction.{h,cpp}`: Hàm tiện ích chung (validate input, format chuỗi/số, xử lý ngoại lệ, I/O phụ trợ, …).
* `menu.{h,cpp}`: Hiển thị menu & điều hướng lệnh tới các mô-đun.
* `main.cpp`: Điểm vào chương trình, vòng lặp chạy menu.

## 🛠️ Yêu cầu hệ thống

* **Compiler**: C++17 trở lên (GCC/Clang/MSVC)
* **CMake** *(tuỳ chọn)*: 3.16+
* **Hệ điều hành**: Windows / Linux / macOS

## 🚀 Build & chạy nhanh

### Cách 1: Dùng g++/clang++ (đơn giản)

**Windows (MinGW):**

```bash
g++ -std=c++17 -O2 -Wall src/*.cpp -o Project_DSA
Project_DSA.exe
```

**Linux/macOS:**

```bash
g++ -std=c++17 -O2 -Wall src/*.cpp -o Project_DSA
./Project_DSA
```

## 🕹️ Hướng dẫn sử dụng (ví dụ)

Khi chạy chương trình, bạn sẽ thấy menu dạng:

```
===== MENU =====
1. Quản lý bệnh nhân
2. Quản lý dịch vụ
3. Lập hoá đơn
4. Tra cứu
0. Thoát
Chọn: _
```

Bên trong mỗi mục có các thao tác: **Thêm / Sửa / Xoá / Liệt kê / Tìm / Sắp xếp**. Hãy nhập số tương ứng theo hướng dẫn trên màn hình.
