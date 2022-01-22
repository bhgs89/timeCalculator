#include <stdio.h>

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

void showMenu() {
    int menu;
    
    printf("# Current Time: ");
    printf("");
    if (resultHour < 10) {
        printf("0%d:", resultHour);
    } else {
        printf("%d:", resultHour);
    }
    
    if (resultMin < 10) {
        printf("0%d\n", resultMin);
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
//            subtractTime();
//            showMenu();
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("########## Time Calculator ##########\n");
    showMenu();
    printf("#####################################\n");
    return 0;
}
