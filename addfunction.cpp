#include "addfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32 // Kiểm tra có chạy trên window ko
#include <windows.h>
#endif

char* layThoiGian() {
    static char date[16]; // rộng rãi hơn
    time_t now = time(nullptr);
#ifdef _WIN32
    struct tm t; localtime_s(&t, &now);
    strftime(date, sizeof(date), "%d/%m/%Y", &t);
#else
    struct tm t; localtime_r(&now, &t);
    strftime(date, sizeof(date), "%d/%m/%Y", &t);
#endif
    return date;
}
snprintf(date, sizeof(date), "%02d/%02d/%04d", tm_mday, tm_mon+1, tm_year+1900);


void sleep_fake(int n) {
    for (int i = 1; i <= n; i++) {
        for(long long j = 1; j <= 2000000000; j++) {
            // DELAY TIME
        }
    }
}

void eraseLines(int count) {// xóa count dòng
    if (count > 0) {
        printf("\x1b[2k");// xóa dòng hiện tại
        for (int i = 1; i < count; i++) {
            printf("\x1b[1A"); // Di chuyển con trỏ lên một dòng
            printf("\x1b[2K"); // Xóa nội dung trên dòng
        }
        printf("\r");
    }
}

int convert(char *s){ // biến chuỗi số thành số nguyên
    int result = 0;
    for (size_t i = 0, n = strlen(s); i < n; ++i){
        result = result*10+((int)s[i]-48);
    }
    return result;
}

void UPCASE(char *s) // biến thành chuỗi in hoa
{
    for (size_t i = 0; s[i] != '\0'; ++i)
        s[i] = (char)toupper((unsigned char)s[i]);
}

// Hàm đăng nhập dùng chung
int DangNhap() {
    char USER[MAX_USER];
    char PASSWORD[MAX_PASSWORD];

    printf("============== DANG NHAP ==============\n");
    printf("Ten dang nhap : ");
    fgets(USER, sizeof(USER), stdin);
    USER[strcspn(USER, "\n")] = '\0';

    printf("Mat khau : ");
    fgets(PASSWORD, sizeof(PASSWORD), stdin);
    PASSWORD[strcspn(PASSWORD, "\n")] = '\0';
    printf("=======================================\n");

    if (strcmp(USER, "admin") == 0 && strcmp(PASSWORD, "admin") == 0) {
        printf("DANG NHAP THANH CONG !\n");
        sleep_fake(2);
        return 1;
    } else {
        printf("TEN DANG NHAP HOAC MAT KHAU SAI !\n");
        sleep_fake(2);
        return 0;
    }
}

