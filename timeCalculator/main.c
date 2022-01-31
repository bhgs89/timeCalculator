#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE *fp = NULL;
    char fpath[256] = "/Users/hangwonsokbaek/Desktop/c_programs/timeCalculator/timeCalculator/";
    char fname[256];
    char line[100][256];
    int index = 0;
    
    printf("#\n");
    printf("# Enter file: ");
    scanf("%s", fname);
    strcat(fpath, fname);
    
    if ((fp = fopen(fpath, "r")) == NULL) {
        fprintf(stderr, "# Can't open file %s\n", fname);
        exit(1);
    }

    
    while (fgets(line[index], 256, fp) != NULL) {
        char tempHour[10];
        char tempMin[10];
        int convert = 0;
        int tempHourIdx = 0;
        int tempMinIdx = 0;
        
        for (int i = 0; i < 256; i++) {
            if (line[index][i] == ':') {
                convert = 1;
                continue;
            } else if (line[index][i] < 48 || line[index][i] > 57) {
                break;
            }
            
            if (convert == 0) {
                tempHour[tempHourIdx++] = line[index][i];
            } else {
                tempMin[tempMinIdx++] = line[index][i];
            }
        }
        index++;
//        printf("%s:", tempHour);
//        printf("%s", tempMin);
//        printf("\n");
////        int hour = line[index]
    }

    fclose(fp);
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
    printf("# 3. File Calculator\n");
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
        } else if (menu == 3) {
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
