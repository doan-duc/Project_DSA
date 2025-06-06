// menu.h
#ifndef MENU_H
#define MENU_H

#include "patient.h"
#include "service.h"
#include "bill.h"
#include "addfunction.h"

// Menu tổng
void MENU(DanhSachBN *list, DanhSachDV *list2);

// Menu quản lý bệnh nhân
void quanLyBN(DanhSachBN *list, DanhSachDV *list2);

// Menu quản lý dịch vụ
void quanLyDichVu(DanhSachBN *list, DanhSachDV *list2);

// Xuất hóa đơn
void xuatHoaDon(DanhSachBN *list, DanhSachDV *list2);

// Các chức năng phụ cho bệnh nhân
void taoBN(DanhSachBN *list, DanhSachDV *list2);
void xoaBNMenu(DanhSachBN *list, DanhSachDV *list2);
void khamBN(DanhSachBN *list, DanhSachDV *list2);
void suaThongTinBN(DanhSachBN *list, DanhSachDV *list2);
void timKiemBN(DanhSachBN *list, DanhSachDV *list2);
void thongKeBN(DanhSachBN *list, DanhSachDV *list2);

// Các chức năng phụ cho dịch vụ
void taoDV(DanhSachBN *list, DanhSachDV *list2);
void xoaDVMenu(DanhSachBN *list, DanhSachDV *list2);
void suaDVMenu(DanhSachBN *list, DanhSachDV *list2);
void timKiemDVMenu(DanhSachBN *list, DanhSachDV *list2);
void danhSachDVMenu(DanhSachBN *list, DanhSachDV *list2);

#endif
