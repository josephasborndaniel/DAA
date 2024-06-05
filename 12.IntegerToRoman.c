#include <stdio.h>

void roman(int num) {
    int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i;
    for (i = 0; i < 13; i++) {
        while (num >= decimal[i]) {
            printf("%s", roman[i]);
            num -= decimal[i];
        }
    }
}

int main() {
    int n = 354;
    printf("Roman numeral for %d is: ", n);
    roman(n);
    return 0;
}
