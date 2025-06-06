#ifndef SERVICE_H
#define SERVICE_H

#include "addfunction.h"

// Định nghĩa struct Node, PNode, DanhSachDV
typedef struct Node {
    int   maDichVu;
    char  tenDichVu[MAX_SERVICE];
    double giaTien;
    struct Node *next;
} Node, *PNode, *DanhSachDV;

// Hàm quản lý dịch vụ
void initListDV(DanhSachDV *list);
int isEmptyDV(DanhSachDV list);
void themDV(DanhSachDV *list, int id, const char *name, double price);
PNode timKiemDV(DanhSachDV list, int k);
PNode timKiemDVTen(DanhSachDV list, const char *keyword);
void suaDV(PNode q, const char *name, double price);
void xoaDV(DanhSachDV *list, PNode p);
void hienThiDV(DanhSachDV list);

#endif
