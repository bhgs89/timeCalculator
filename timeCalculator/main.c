#include <stdio.h>
#include <stdlib.h>

int resultHour = 0;
int resultMin = 0;

void addTime() {
    int addHour, addMin;
    
    printf("# Max hour is 99, Max minutes is 60\n");
    printf("# Enter the time(HH:MM) : ");
    scanf("%d:%d", &addHour, &addMin);
        
    resultHour += addHour;
    resultMin += addMin;
    
    if (resultMin / 60 > 0) {
        resultHour += resultMin / 60;
        resultMin %= 60;
    }
    printf("#\n");
}

void subtractTime() {
    int subHour, subMin;
    int totalResultMins = 0;
    int totalSubMins = 0;
    
    printf("# Max hour is 99, Max minutes is 60\n");
    printf("# Enter the time(HH:MM) : ");
    scanf("%d:%d", &subHour, &subMin);
    
    totalSubMins += subMin;
    totalSubMins += (subHour * 60);
    
    totalResultMins += resultMin;
    totalResultMins += (resultHour * 60);
    
    totalResultMins -= totalSubMins;
    
    if (totalResultMins < 0) {
        resultHour = totalResultMins / 60;
        resultMin = totalResultMins % 60;
    } else {
        resultHour = totalResultMins / 60;
        resultMin = totalResultMins % 60;
    }
    
    printf("#\n");
}

void showMenu() {
    int menu;
    
    printf("# Current Time: ");
    
    if (resultHour >= 0 && resultHour < 10) {
        printf("0%d:", resultHour);
    } else if (resultHour < 0 && resultHour > -10) {
        printf("-0%d:", abs(resultHour));
    } else {
        printf("%d:", resultHour);
    }
    
    if (resultMin >= 0 && resultMin < 10) {
        printf("0%d\n", resultMin);
    } else if (resultMin < 0 && resultMin > -10) {
        printf("0%d:", abs(resultMin));
    } else if (resultMin < 0 && resultMin < -10) {
        printf("%d\n", abs(resultMin));
    } else {
        printf("%d\n", resultMin);
    }
    
    printf("# 1. Add time\n");
    printf("# 2. Subtract time\n");
    printf("# 0. Exit\n");
    printf("#------------------------------------\n");
    printf("# Enter: ");
    scanf("%d", &menu);

    if (menu < 0 || menu > 2) {
        printf("#\n");
        printf("# Warning - Invalid option\n");
        printf("# Warning - Please re-enter the option\n");
        printf("#\n");
        showMenu();
    } else {
        if (menu == 1) {
            addTime();
            showMenu();
        } else if (menu == 2) {
            subtractTime();
            showMenu();
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("########## Time Calculator ##########\n");
    showMenu();
    printf("#####################################\n");
    return 0;
}
