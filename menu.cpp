#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MENU(DanhSachBN *list, DanhSachDV *list2) {
    int k;
    system("cls");
    printf("==== CHUONG TRINH QUAN LY PHONG KHAM ====\n");
    printf("1. Quan ly benh nhan\n");
    printf("2. Quan ly dich vu\n");
    printf("3. Xuat hoa don\n");
    printf("4. Thoat chuong trinh \n");
    printf("==================================================\n");
    printf("Vui long chon thao tac : ");
    scanf("%d",&k);
    switch(k) {
    case 1:
        quanLyBN(list, list2);
        break;
    case 2:
        quanLyDichVu(list, list2);
        break;
    case 3:
        xuatHoaDon(list, list2);
        break;
    case 4:
        system("cls");
        printf("XIN CHAO VA HEN GAP LAI  !\n");
        sleep_fake(2);
        exit(0);
        break;
    default:
        eraseLines(2);
        printf("Vui long nhap lai !\n");
        sleep_fake(2);
        MENU(list, list2);
        break;
    }
}

void quanLyBN(DanhSachBN *list, DanhSachDV *list2) {
    int k;
    system("cls");
    printf("=============== QUAN LY BENH NHAN ===============\n");
    printf("1. Tao benh nhan moi\n");
    printf("2. Xoa benh nhan\n");
    printf("3. Kham benh nhan\n");
    printf("4. Sua thong tin benh nhan\n");
    printf("5. Tim kiem benh nhan\n");
    printf("6. Thong ke benh nhan\n");
    printf("7. Quay lai\n");
    printf("==================================================\n");
    printf("Vui long chon thao tac : ");
    scanf("%d",&k);
    switch(k) {
    case 1:
        taoBN(list, list2);
        break;
    case 2:
        xoaBNMenu(list, list2);
        break;
    case 3:
        khamBN(list, list2);
        break;
    case 4:
        suaThongTinBN(list, list2);
        break;
    case 5:
        timKiemBN(list, list2);
        break;
    case 6:
        thongKeBN(list, list2);
        break;
    case 7:
        system("cls");
        MENU(list, list2);
        break;
    default:
        system("cls");
        printf("Vui long nhap lai !\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        break;
    }
}

// Tạo bệnh nhân mới
void taoBN(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= TAO BENH NHAN =================\n");
    if (isEmptyDV(*list2)) {
        printf("Danh sach dich vu rong, khong the tao benh nhan ! \n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    static int autoSTT = 1;
    int  STT2 = autoSTT++;
    char tenBenhNhan2[MAX_NAME];
    int  tuoiBenhNhan2;
    char SDT2[MAX_PHONE];
    char CCCD2[MAX_CCCD];
    char tinhTrangBenh2[MAX_NAME];
    int  BHYT2;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    printf("Ten benh nhan la : ");
    fgets(tenBenhNhan2, sizeof(tenBenhNhan2), stdin);
    tenBenhNhan2[strcspn(tenBenhNhan2, "\n")] = '\0';

    printf("Nhap tuoi benh nhan: ");
    scanf("%d", &tuoiBenhNhan2); getchar();

    printf("Nhap so dien thoai: ");
    fgets(SDT2, sizeof(SDT2), stdin);
    SDT2[strcspn(SDT2, "\n")] = '\0';

    printf("Nhap CCCD: ");
    fgets(CCCD2, sizeof(CCCD2), stdin);
    CCCD2[strcspn(CCCD2, "\n")] = '\0';

    printf("Trang thai cua benh nhan: ");
    fgets(tinhTrangBenh2, sizeof(tinhTrangBenh2), stdin);
    tinhTrangBenh2[strcspn(tinhTrangBenh2, "\n")] = '\0';

    printf("Co bao hiem y te ko (1 co 0 khong): ");
    scanf("%d", &BHYT2); getchar();

    // Chọn dịch vụ
    printf("================== CHON DICH VU ==================\n");
    hienThiDV(*list2);
    printf("==================================================\n");
    int k;
    printf("Vui long nhap ma dich vu : ");
    scanf("%d",&k); getchar();
    PNode dv = timKiemDV(*list2, k);
    while (dv == NULL) {
        printf("Nhap sai ma, vui long nhap lai: ");
        scanf("%d", &k); getchar();
        dv = timKiemDV(*list2, k);
    }

    themBN(list, STT2, tenBenhNhan2, tuoiBenhNhan2, SDT2, CCCD2, tinhTrangBenh2, layThoiGian(), BHYT2, dv);
    system("cls");
    printf("\n>>> Them benh nhan thanh cong!\n");
    sleep_fake(2);
    system("cls");
    MENU(list, list2);
}

// Xóa bệnh nhân
void xoaBNMenu(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= XOA BENH NHAN =================\n");
    if (isEmptyBN(*list)) {
        printf("Danh sach rong!\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    char sdt[MAX_PHONE];
    printf("Nhap SDT benh nhan can xoa: ");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    fgets(sdt, sizeof(sdt), stdin);
    sdt[strcspn(sdt, "\n")] = '\0';

    TNode p = timKiemBNSDT(*list, sdt);
    if (!p) {
        printf("Khong tim thay benh nhan co SDT nay!\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    hienThiMotBN(*list, p);
    printf("Ban co chac muon xoa benh nhan nay? (y/n): ");
    char confirm[8];
    fgets(confirm, sizeof(confirm), stdin);
    if (confirm[0] == 'y' || confirm[0] == 'Y') {
        xoaBN(list, p);
        printf("\n>>> Da xoa benh nhan thanh cong!\n");
    } else {
        printf("\n>>> Da huy thao tac xoa!\n");
    }
    sleep_fake(2);
    MENU(list, list2);
}

void khamBN(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= KHAM BENH NHAN =================\n");
    printf("--------------- BENH NHAN DEN LUOT ---------------\n");
    hienThiMotBN(*list, peekQueue(&hangDoi));
    printf("--------------------------------------------------\n");
    int k;
    printf("Kham benh nhan khong ? ([0] la khong, [1] la co) : ");
    scanf("%d",&k); getchar();
    switch(k) {
        case 0:
            quanLyBN(list, list2);
            break;
        case 1:
            enqueueHD(&hangDoiHoaDon, dequeueBN(&hangDoi));
            system("cls");
            printf("\n>>> Da kham benh nhan, xin moi benh nhan tiep theo!\n");
            sleep_fake(2);
            quanLyBN(list, list2);
            break;
        default:
            system("cls");
            printf("Vui long nhap lai !\n");
            sleep_fake(2);
            khamBN(list, list2);
            break;
    }
}

void suaThongTinBN(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= SUA BENH NHAN =================\n");
    if (isEmptyBN(*list)) {
        printf("Danh sach rong!\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    char sdtKey[MAX_PHONE];
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    printf("Nhap SDT benh nhan can sua: ");
    fgets(sdtKey, sizeof(sdtKey), stdin);
    sdtKey[strcspn(sdtKey, "\n")] = '\0';
    TNode p = timKiemBNSDT(*list, sdtKey);
    if (!p) {
        printf("Khong tim thay benh nhan !\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    printf("=== SUA THONG TIN === (bo qua = giu nguyen)\n");
    char buf[128];
    char newTen[MAX_NAME];      strncpy(newTen, p->tenBenhNhan, MAX_NAME);
    int  newTuoi    = p->tuoiBenhNhan;
    char newSDT[MAX_PHONE];     strncpy(newSDT, p->SDT, MAX_PHONE);
    char newCCCD[MAX_CCCD];     strncpy(newCCCD, p->CCCD, MAX_CCCD);
    char newTinhTrang[MAX_NAME];strncpy(newTinhTrang, p->tinhTrangBenh, MAX_NAME);
    int  newBHYT    = p->BHYT;
    Node *newDV     = p->dichVu;

    printf("Ten [%s]: ", p->tenBenhNhan);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') { buf[strcspn(buf, "\n")] = '\0'; strncpy(newTen, buf, MAX_NAME); }
    printf("Tuoi [%d]: ", p->tuoiBenhNhan);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n')   newTuoi = atoi(buf);
    printf("SDT [%s]: ", p->SDT);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') { buf[strcspn(buf, "\n")] = '\0'; strncpy(newSDT, buf, MAX_PHONE); newSDT[MAX_PHONE-1] = '\0';}
    printf("CCCD [%s]: ", p->CCCD);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') { buf[strcspn(buf, "\n")] = '\0'; strncpy(newCCCD, buf, MAX_CCCD); }
    printf("Tinh trang [%s]: ", p->tinhTrangBenh);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') { buf[strcspn(buf, "\n")] = '\0'; strncpy(newTinhTrang, buf, MAX_NAME); }
    printf("BHYT (1/0) [%d]: ", p->BHYT);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n')   newBHYT = atoi(buf);
    printf("Muon doi dich vu? (y/n): ");
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] == 'y' || buf[0] == 'Y') {
        printf("================== CHON DICH VU MOI ==================\n");
        hienThiDV(*list2);
        printf("======================================================\n");
        int k;
        printf("Nhap ma dich vu: ");
        scanf("%d", &k); getchar();
        Node *tmp = timKiemDV(*list2, k);
        if (tmp) newDV = tmp;
    }
    suaBN(list, p, p->STT, newTen, newTuoi, newSDT, newCCCD, newTinhTrang, p->lichKham, newBHYT, newDV);
    system("cls");
    printf(">>> Da cap nhat.\n");
    sleep_fake(2);
    quanLyBN(list, list2);
}


void timKiemBN(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= TIM KIEM BENH NHAN =================\n");
    if (isEmptyBN(*list)) {
        printf("Danh sach rong!\n");
        sleep_fake(2);
        quanLyBN(list, list2);
        return;
    }
    int k, t;
    printf("Tim theo ten [0], tim theo so dien thoai [1] : ");
    scanf("%d", &k); getchar();
    printf("\n");
    switch(k) {
        case 0: {
            char name[MAX_NAME];
            printf("Nhap ten benh nhan can tim kiem: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("===========================================\n ");
            printf("Danh sach benh nhan can tim: \n");
            hienThiMotBN(*list, timKiemBNTen(*list, name));
            printf("===========================================\n ");
            printf("Go bat ky nut nao de quay lai : ");
            scanf("%d", &t); getchar();
            sleep_fake(1);
            quanLyBN(list, list2);
            break;
        }
        case 1: {
            char sdt[MAX_PHONE];
            printf("Nhap SDT benh nhan can tim kiem: ");
            fgets(sdt, sizeof(sdt), stdin);
            sdt[strcspn(sdt, "\n")] = '\0';
            printf("===========================================\n ");
            printf("Danh sach benh nhan can tim: \n");
            hienThiMotBN(*list, timKiemBNSDT(*list, sdt));
            printf("===========================================\n ");
            printf("Go bat ky nut nao de quay lai : ");
            scanf("%d", &t); getchar();
            sleep_fake(1);
            quanLyBN(list, list2);
            break;
        }
        default:
            system("cls");
            printf("Vui long nhap lai !\n");
            sleep_fake(2);
            timKiemBN(list, list2);
            break;
    }
}

void thongKeBN(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    int k;
    printf("================= THONG KE BENH NHAN =================\n");
    hienThiBN(*list);
    printf("======================================================\n");
    printf("Go bat ky nut nao de quay lai : ");
    scanf("%d", &k); getchar();
    sleep_fake(1);
    quanLyBN(list, list2);
}


void quanLyDichVu(DanhSachBN *list, DanhSachDV *list2) {
    int k;
    system("cls");
    printf("================ QUAN LY DICH VU =================\n");
    printf("1. Tao dich vu moi\n");
    printf("2. Xoa dich vu\n");
    printf("3. Sua dich vu\n");
    printf("4. Tim kiem dich vu\n");
    printf("5. Danh sach dich vu\n");
    printf("6. Quay lai\n");
    printf("==================================================\n");
    printf("Vui long chon thao tac : ");
    scanf("%d",&k);
    switch(k) {
    case 1:
        taoDV(list, list2);
        break;
    case 2:
        xoaDVMenu(list, list2);
        break;
    case 3:
        suaDVMenu(list, list2);
        break;
    case 4:
        timKiemDVMenu(list, list2);
        break;
    case 5:
        danhSachDVMenu(list, list2);
        break;
    case 6:
        system("cls");
        MENU(list, list2);
        break;
    default:
        system("cls");
        printf("Vui long nhap lai !\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        break;
    }
}

void taoDV(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= TAO DICH VU =================\n");
    static int autoSTT = 1;
    int  STT2 = autoSTT++;
    char tenDichVu2[MAX_NAME];
    double  giaDichVu2;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    printf("Ten dich vu la : ");
    fgets(tenDichVu2, sizeof(tenDichVu2), stdin);
    tenDichVu2[strcspn(tenDichVu2, "\n")] = '\0';

    printf("Nhap gia dich vu : ");
    scanf("%lf", &giaDichVu2); getchar();

    themDV(list2, STT2, tenDichVu2, giaDichVu2);
    system("cls");
    printf("\n>>> Them dich vu thanh cong!\n");
    sleep_fake(2);
    system("cls");
    MENU(list, list2);
}

void xoaDVMenu(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= XOA DICH VU =================\n");
    if (isEmptyDV(*list2)) {
        printf("Danh sach dich vu rong!\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        return;
    }
    hienThiDV(*list2);
    int ma;
    printf("Nhap ma dich vu can xoa: ");
    scanf("%d", &ma); getchar();

    PNode p = timKiemDV(*list2, ma);
    if (!p) {
        printf("Khong tim thay dich vu co ma nay!\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        return;
    }

    for (TNode q = *list; q != NULL; q = q->next) {
        if (q->dichVu && q->dichVu->maDichVu == ma) {
            printf("Khong the xoa! Co benh nhan dang su dung dich vu nay.\n");
            sleep_fake(2);
            quanLyDichVu(list, list2);
            return;
        }
    }
    printf("Ban co chac muon xoa dich vu nay? (y/n): ");
    char confirm[8];
    fgets(confirm, sizeof(confirm), stdin);
    if (confirm[0] == 'y' || confirm[0] == 'Y') {
        xoaDV(list2, p);
        system("cls");
        printf("\n>>> Da xoa dich vu!\n");
    } else {
        printf("\n>>> Da huy thao tac xoa.\n");
    }
    sleep_fake(2);
    quanLyDichVu(list, list2);
}

void suaDVMenu(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= SUA DICH VU =================\n");
    if (isEmptyDV(*list2)) {
        printf("Danh sach dich vu rong!\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        return;
    }
    hienThiDV(*list2);
    int ma;
    printf("Nhap ma dich vu can sua: ");
    scanf("%d", &ma); getchar();

    PNode p = timKiemDV(*list2, ma);
    if (!p) {
        printf("Khong tim thay dich vu co ma nay!\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        return;
    }
    printf("=== SUA THONG TIN === (bo qua = giu nguyen)\n");
    char buf[128];

    char   newTen[MAX_NAME];  strncpy(newTen, p->tenDichVu, MAX_NAME);
    double newGia            = p->giaTien;

    printf("Ten dich vu [%s]: ", p->tenDichVu);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') {
        buf[strcspn(buf, "\n")] = '\0';
        strncpy(newTen, buf, MAX_NAME);
    }

    printf("Gia tien [%.0lf]: ", p->giaTien);
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n')
        newGia = atof(buf);
    suaDV(p, newTen, newGia);
    system("cls");
    printf(">>> Da cap nhat dich vu!\n");
    sleep_fake(2);
    quanLyDichVu(list, list2);
}

void timKiemDVMenu(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= TIM KIEM DICH VU =================\n");
    if (isEmptyDV(*list2)) {
        printf("Danh sach dich vu rong!\n");
        sleep_fake(2);
        quanLyDichVu(list, list2);
        return;
    }
    int k;
    printf("Tim theo ma [1] hay theo ten [2]: ");
    scanf("%d", &k); getchar();
    if (k == 1) {
        int ma;
        printf("Nhap ma dich vu: ");
        scanf("%d", &ma); getchar();
        PNode p = timKiemDV(*list2, ma);
        if (p) {
            printf("Ket qua tim kiem:\n");
            printf("Ma: %-5d | Ten: %-25s | Gia: %.0lf VND\n", p->maDichVu, p->tenDichVu, p->giaTien);
        } else {
            printf("Khong tim thay dich vu co ma nay!\n");
        }
    } else if (k == 2) {
        char ten[MAX_NAME];
        printf("Nhap ten dich vu: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = '\0';
        PNode p = timKiemDVTen(*list2, ten);
        if (p) {
            printf("Ket qua tim kiem:\n");
            printf("Ma: %-5d | Ten: %-25s | Gia: %.0lf VND\n", p->maDichVu, p->tenDichVu, p->giaTien);
        } else {
            printf("Khong tim thay dich vu co ma nay!\n");
        }
    } else {
        printf("Lua chon khong hop le!\n");
    }
    printf("\nNhan phim bat ky de quay lai...");
    getchar();
    quanLyDichVu(list, list2);
}

void danhSachDVMenu(DanhSachBN *list, DanhSachDV *list2) {
    system("cls");
    printf("================= DANH SACH DICH VU =================\n");
    if (isEmptyDV(*list2)) {
        printf("Danh sach dich vu rong!\n");
    } else {
        hienThiDV(*list2);
    }
    int k;
    printf("\nNhan phim bat ky de quay lai...");
    scanf("%d", &k); getchar();
    quanLyDichVu(list, list2);
}

// ------ Xuất hóa đơn ---------
void xuatHoaDon(DanhSachBN *list, DanhSachDV *list2) {
    int k;
    system("cls");
    printf("======= HOA DON HIEN TAI =======\n");
    hienThiHD(*list, peekQueueHD(&hangDoiHoaDon));
    printf("================================\n");
    printf("Ban co muon xuat hoa don tren ? ([0] la khong, [1] la co) \n");
    scanf("%d",&k); getchar();
    switch(k) {
        case 0:
            sleep_fake(1);
            MENU(list, list2);
            break;
        case 1:
            dequeueHD(&hangDoiHoaDon);
            printf("\n>>> Xuat hoa don thanh cong!\n");
            sleep_fake(2);
            MENU(list, list2);
            break;
        default:
            system("cls");
            printf("Vui long nhap lai !\n");
            sleep_fake(2);
            xuatHoaDon(list, list2);
            break;
    }
}
