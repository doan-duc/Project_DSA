#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khởi tạo biến hàng đợi toàn cục
QueueBN hangDoi;

void initListBN(DanhSachBN *list) {
    *list = NULL;
}

int isEmptyBN(DanhSachBN list) {
    return (list == NULL);
}

void themBN(DanhSachBN *list,
            int   STT2,
            const char *tenBenhNhan2,
            int   tuoiBenhNhan2,
            const char *SDT2,
            const char *CCCD2,
            const char *tinhTrangBenh2,
            const char *lichKham2,
            int   BHYT2,
            struct Node *dichVu2)
{
    TNode q = (TNode)malloc(sizeof(NodeBN));

    q->STT          = STT2;
    strncpy(q->tenBenhNhan, tenBenhNhan2, MAX_NAME);
    q->tenBenhNhan[MAX_NAME-1] = '\0';
    q->tuoiBenhNhan = tuoiBenhNhan2;

    strncpy(q->SDT,  SDT2,  MAX_PHONE);
    q->SDT[MAX_PHONE-1] = '\0';

    strncpy(q->CCCD, CCCD2, MAX_CCCD);
    q->CCCD[MAX_CCCD-1] = '\0';

    strncpy(q->tinhTrangBenh, tinhTrangBenh2, MAX_NAME);
    q->tinhTrangBenh[MAX_NAME-1] = '\0';

    strncpy(q->lichKham, lichKham2, MAX_DATE);
    q->lichKham[MAX_DATE-1] = '\0';

    q->BHYT  = BHYT2;
    q->dichVu = dichVu2;
    q->next = *list;
    *list    = q;
    enqueueBN(&hangDoi, q);
}

TNode timKiemBNTen(DanhSachBN list, const char *name)
{
    char key[MAX_NAME];
    strncpy(key, name, MAX_NAME);
    key[MAX_NAME-1] = '\0';
    UPCASE(key);

    for (TNode p = list; p; p = p->next) {
        char tmp[MAX_NAME];
        strncpy(tmp, p->tenBenhNhan, MAX_NAME);
        tmp[MAX_NAME-1] = '\0';
        UPCASE(tmp);

        if (strcmp(tmp, key) == 0)
            return p;
    }
    return NULL;
}

TNode timKiemBNSDT(DanhSachBN list, const char *SDTtemp)
{
    for (TNode ptr = list; ptr != NULL; ptr = ptr->next)
        if (strcmp(ptr->SDT, SDTtemp) == 0)
            return ptr;
    return NULL;
}

void suaBN(DanhSachBN *list,
           TNode       q,
           int         STT2,
           const char *tenBenhNhan2,
           int         tuoiBenhNhan2,
           const char *SDT2,
           const char *CCCD2,
           const char *tinhTrangBenh2,
           const char *lichKham2,
           int         BHYT2,
           struct Node *dichVu2)
{
    if (isEmptyBN(*list) || q == NULL)  return;

    q->STT = STT2;

    strncpy(q->tenBenhNhan, tenBenhNhan2, MAX_NAME);
    q->tenBenhNhan[MAX_NAME - 1] = '\0';

    q->tuoiBenhNhan = tuoiBenhNhan2;

    strncpy(q->SDT, SDT2, MAX_PHONE);
    q->SDT[MAX_PHONE - 1] = '\0';

    strncpy(q->CCCD, CCCD2, MAX_CCCD);
    q->CCCD[MAX_CCCD - 1] = '\0';

    strncpy(q->tinhTrangBenh, tinhTrangBenh2, MAX_NAME);
    q->tinhTrangBenh[MAX_NAME - 1] = '\0';

    strncpy(q->lichKham, lichKham2, MAX_DATE);
    q->lichKham[MAX_DATE - 1] = '\0';

    q->BHYT   = BHYT2;
    q->dichVu = dichVu2;
}

void xoaBN(DanhSachBN *list, TNode p) {
    if (isEmptyBN(*list)) {
        return;
    }
    if (p == NULL) {
        return;
    }

    if (p == *list) {
        *list = (*list)->next;
        free(p);
        return;
    }
    TNode prev = *list;
    while (prev != NULL && prev->next != p) {
        prev = prev->next;
    }

    if (prev == NULL) {
        return;
    }
    prev->next = p->next;
    free(p);
}

void hienThiMotBN(DanhSachBN list, TNode q) {
    printf("--------------------------------------------------\n");
    if (isEmptyBN(list) || q == NULL)  {
        printf("Danh sach rong\n");
        return;
    }
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
}

void hienThiBN(DanhSachBN list) {
    for (TNode q = list; q != NULL; q = q->next) {
        printf("--------------------------------------------------\n");
        if (isEmptyBN(list) || q == NULL){
            printf("Danh sach rong\n");
            return;
        }
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
    }
}

// --------- Hàng đợi bệnh nhân ---------
void initQueue(QueueBN *q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(QueueBN q) {
    return (q.front == NULL);
}

void enqueueBN(QueueBN *q, TNode newBN) {
    newBN->next = NULL;
    if (isQueueEmpty(*q)) {
        q->front = q->rear = newBN;
    } else {
        q->rear->next = newBN;
        q->rear = newBN;
    }
}

TNode dequeueBN(QueueBN *q) {
    if (isQueueEmpty(*q)) {
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

TNode peekQueue(const QueueBN *q) {
    if (isQueueEmpty(*q)) {
        return NULL;
    }
    return q->front;
}
