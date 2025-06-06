#ifndef PATIENT_H
#define PATIENT_H

#include "service.h"
#include "addfunction.h"

// Định nghĩa struct NodeBN, TNode, DanhSachBN
typedef struct NodeBN {
    int   STT;
    char  tenBenhNhan[MAX_NAME];
    int   tuoiBenhNhan;
    char  SDT[MAX_PHONE];
    char  CCCD[MAX_CCCD];
    char  tinhTrangBenh[MAX_NAME];
    char  lichKham[MAX_DATE];
    int   BHYT;
    struct Node *dichVu;
    struct NodeBN *next;
} NodeBN, *TNode, *DanhSachBN;

// Hàng đợi bệnh nhân
typedef struct QueueBN {
    TNode front;
    TNode rear;
} QueueBN;

// Biến hàng đợi bệnh nhân dùng toàn cục
extern QueueBN hangDoi;

// Khai báo hàm cho quản lý bệnh nhân
void initListBN(DanhSachBN *list);
int isEmptyBN(DanhSachBN list);
void themBN(DanhSachBN *list, int STT2, const char *tenBenhNhan2, int tuoiBenhNhan2,
            const char *SDT2, const char *CCCD2, const char *tinhTrangBenh2,
            const char *lichKham2, int BHYT2, struct Node *dichVu2);
TNode timKiemBNTen(DanhSachBN list, const char *name);
TNode timKiemBNSDT(DanhSachBN list, const char *SDTtemp);
void suaBN(DanhSachBN *list, TNode q, int STT2, const char *tenBenhNhan2, int tuoiBenhNhan2,
           const char *SDT2, const char *CCCD2, const char *tinhTrangBenh2,
           const char *lichKham2, int BHYT2, struct Node *dichVu2);
void xoaBN(DanhSachBN *list, TNode p);
void hienThiMotBN(DanhSachBN list, TNode q);
void hienThiBN(DanhSachBN list);

// Hàng đợi bệnh nhân
void initQueue(QueueBN *q);
int isQueueEmpty(QueueBN q);
void enqueueBN(QueueBN *q, TNode newBN);
TNode dequeueBN(QueueBN *q);
TNode peekQueue(const QueueBN *q);

#endif

