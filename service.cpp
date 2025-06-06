#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initListDV(DanhSachDV *list) {
    *list = NULL;
}

int isEmptyDV(DanhSachDV list) {
    return list == NULL;
}

void themDV(DanhSachDV *list, int id, const char *name, double price)
{
    PNode q = (PNode)malloc(sizeof(Node));
    q->maDichVu = id;

    strncpy(q->tenDichVu, name, MAX_SERVICE);
    q->tenDichVu[MAX_SERVICE - 1] = '\0';

    q->giaTien = price;

    q->next = *list;
    *list   = q;
}

PNode timKiemDV(DanhSachDV list, int k)
{
    for (PNode p = list; p != NULL; p = p->next)
        if (p->maDichVu == k) return p;
    return NULL;
}

PNode timKiemDVTen(DanhSachDV list, const char *keyword)
{
    if (list == NULL || keyword == NULL) return NULL;
    char keyUp[MAX_SERVICE];
    strncpy(keyUp, keyword, MAX_SERVICE);
    keyUp[MAX_SERVICE-1] = '\0';
    UPCASE(keyUp);
    for (PNode p = list; p != NULL; p = p->next)
    {
        char nameUp[MAX_SERVICE];
        strncpy(nameUp, p->tenDichVu, MAX_SERVICE);
        nameUp[MAX_SERVICE-1] = '\0';
        UPCASE(nameUp);

        if (strstr(nameUp, keyUp) != NULL)
            return p;
    }
    return NULL;
}

void suaDV(PNode q, const char *name, double price)
{
    if (q == NULL) return;

    strncpy(q->tenDichVu, name, MAX_SERVICE);
    q->tenDichVu[MAX_SERVICE - 1] = '\0';
    q->giaTien = price;
}

void xoaDV(DanhSachDV *list, PNode p)
{
    if (isEmptyDV(*list) || p == NULL) return;

    if (p == *list)
        *list = (*list)->next;
    else {
        PNode prev = *list;
        while (prev && prev->next != p) prev = prev->next;
        if (!prev) return;
        prev->next = p->next;
    }
    free(p);
}

void hienThiDV(DanhSachDV list)
{
    printf("--------------------------------------------------\n");
    for (PNode p = list; p != NULL; p = p->next)
        printf("Ma: %-5d | Ten: %-25s | Gia: %.0lf VND\n",
               p->maDichVu, p->tenDichVu, p->giaTien);
    printf("--------------------------------------------------\n");
}
