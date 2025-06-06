#include "menu.h"
#include "patient.h"
#include "service.h"
#include "bill.h"
#include "addfunction.h"

int main() {
    if (!DangNhap()) return 0;
    DanhSachBN list;
    DanhSachDV list2;
    initListBN(&list);
    initListDV(&list2);
    initQueue(&hangDoi);
    initQueueHD(&hangDoiHoaDon);
    MENU(&list, &list2);

    return 0;
}