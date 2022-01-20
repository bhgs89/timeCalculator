#include <stdio.h>

char resultTime[8] = "00:00";

int showMenu() {
    int menu;
    
    printf("# Current Time: %s\n", resultTime);
    printf("# 1. Add time\n");
    printf("# 2. Subtract time\n");
    printf("# 3. Get result\n");
    printf("# 0. Exit\n");
    printf("#------------------------------------\n");
    printf("# Enter: ");
    scanf("%d", &menu);

    if (menu < 0 || menu > 3) {
        while (menu < 0 || menu > 3) {
            printf("#\n");
            printf("# Warning - Invalid option\n");
            printf("# Re-enter: ");
            scanf("%d", &menu);
        }
    }
    
    if (menu == 0) {
        return 0;
    } else if (menu == 1) {
//        addTime();
    } else if (menu == 2) {
//        subtractTime();
    } else if (menu == 3) {
//        getResult();
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    printf("########## Time Calculator ##########\n");
    showMenu();
    printf("#####################################\n");
    return 0;
}
