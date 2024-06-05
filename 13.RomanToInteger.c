#include <stdio.h>

int romanToInt(char *s) {
    int i,num = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                num -= 1;
            } else {
                num += 1;
            }
        } else if (s[i] == 'V') {
            num += 5;
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                num -= 10;
            } else {
                num += 10;
            }
        } else if (s[i] == 'L') {
            num += 50;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                num -= 100;
            } else {
                num += 100;
            }
        } else if (s[i] == 'D') {
            num += 500;
        } else if (s[i] == 'M') {
            num += 1000;
        }
    }
    return num;
}

int main() {
    char romanNumeral[] = "XXVII";
    int result = romanToInt(romanNumeral);
    printf("The integer value of %s is: %d\n", romanNumeral, result);
    return 0;
}
