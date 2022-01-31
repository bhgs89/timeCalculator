#include <stdio.h>
#include <stdlib.h>

int resultHour = 0;
int resultMin = 0;

void addTime() {
    int addHour, addMin;
    int totalResultMins = 0;
    int totalAddMins = 0;
    
    printf("# Max hour is 99, Max minutes is 59\n");
    printf("# Enter the time(HH:MM) : ");
    scanf("%d:%d", &addHour, &addMin);
        
    if (addHour > 99) {
        printf("#\n");
        printf("# Warning - Maximum hour for adding is 99!!\n");
        printf("# Warning - Please re-enter the time\n");
        printf("#\n");
        addTime();
    } else if (addMin > 59) {
        printf("#\n");
        printf("# Warning - Maximum minutes for adding is 59!!\n");
        printf("# Warning - Please re-enter the time\n");
        printf("#\n");
        addTime();
    } else {
        totalAddMins += addMin;
        totalAddMins += (addHour * 60);
        
        totalResultMins += resultMin;
        totalResultMins += (resultHour * 60);
        
        totalResultMins += totalAddMins;
        
        resultHour = totalResultMins / 60;
        resultMin = totalResultMins % 60;
        
        printf("#\n");
    }
}

void subtractTime() {
    int subHour, subMin;
    int totalResultMins = 0;
    int totalSubMins = 0;
    
    printf("# Max hour is 99, Max minutes is 59\n");
    printf("# Enter the time(HH:MM) : ");
    scanf("%d:%d", &subHour, &subMin);
    
    if (subHour > 99) {
        printf("#\n");
        printf("# Warning - Maximum hour for substracting is 99!!\n");
        printf("# Warning - Please re-enter the time\n");
        printf("#\n");
        subtractTime();
    } else if (subMin > 59) {
        printf("#\n");
        printf("# Warning - Maximum minutes for substracting is 59!!\n");
        printf("# Warning - Please re-enter the time\n");
        printf("#\n");
        subtractTime();
    } else {
        totalSubMins += subMin;
        totalSubMins += (subHour * 60);
        
        totalResultMins += resultMin;
        totalResultMins += (resultHour * 60);
        
        totalResultMins -= totalSubMins;
        
        resultHour = totalResultMins / 60;
        resultMin = totalResultMins % 60;
        
        printf("#\n");
    }
}

void getFileResult() {
    
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
    printf("# 3. File Calculator\n")
    printf("# 0. Exit\n");
    printf("#------------------------------------\n");
    printf("# Enter: ");
    scanf("%d", &menu);

    if (menu < 0 || menu > 3) {
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
        } else if (menu == 2) {
            getFileResult();
            showMenu();
        } else if (menu == 0) {
            printf("#\n");
            printf("# Thanks for using time calculator!!\n");
            printf("#\n");
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("########## Time Calculator ##########\n");
    showMenu();
    printf("#####################################\n");
    return 0;
}
