// bill.c
#include "bill.h"
#include <stdio.h>
#include <stdlib.h>

QueueHD hangDoiHoaDon;

void initQueueHD(QueueHD *q) {
    q->front = q->rear = NULL;
}

int isQueueHDEmpty(QueueHD q) {
    return (q.front == NULL);
}

void enqueueHD(QueueHD *q, TNode newHD) {
    newHD->next = NULL;
    if (isQueueHDEmpty(*q)) {
        q->front = q->rear = newHD;
    } else {
        q->rear->next = newHD;
        q->rear = newHD;
    }
}

TNode dequeueHD(QueueHD *q) {
    if (isQueueHDEmpty(*q)) {
        return NULL;
    }
    TNode temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    temp->next = NULL;
    return temp;
}

TNode peekQueueHD(const QueueHD *q) {
    if (isQueueHDEmpty(*q)) {
        return NULL;
    }
    return q->front;
}

void hienThiHD(DanhSachBN list, TNode q) {
    if (isEmptyBN(list) || q == NULL)  {
        printf("Khong co hoa don nao !\n");
        return;
    }
    printf("--------------------------------------------------\n");
    printf("STT : %d\n",q->STT);
    printf("Ten benh nhan : %s\n",q->tenBenhNhan);
    printf("Tuoi benh nhan : %d\n",q->tuoiBenhNhan);
    printf("SDT : %s\n",q->SDT);
    printf("CCCD : %s\n",q->CCCD);
    printf("Tinh trang benh : %s\n",q->tinhTrangBenh);
    printf("Lich kham : %s\n",q->lichKham);
    printf("Dich vu : %s\n",q->dichVu->tenDichVu);
    if (q->BHYT) printf("BHYT : Co\n");
    else printf("BHYT : Khong\n");
    printf("--------------------------------------------------\n");
    printf("Gia dich vu : %lf VND\n", q->dichVu->giaTien);
    if (q->BHYT) printf("Chiet khau BHYT : 50%% \n");
    printf("--------------------------------------------------\n");
    printf("TONG : %lf VND \n", (q->dichVu->giaTien) / ( q->BHYT ? 2.0 : 1.0 ));
}
