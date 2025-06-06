#ifndef BILL_H
#define BILL_H

#include "patient.h"

typedef struct QueueHD {
    TNode front;
    TNode rear;
} QueueHD;

extern QueueHD hangDoiHoaDon;

// Khai báo hàm cho hóa đơn
void initQueueHD(QueueHD *q);
int isQueueHDEmpty(QueueHD q);
void enqueueHD(QueueHD *q, TNode newHD);
TNode dequeueHD(QueueHD *q);
TNode peekQueueHD(const QueueHD *q);
void hienThiHD(DanhSachBN list, TNode q);

#endif
