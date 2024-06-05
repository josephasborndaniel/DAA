#include <stdio.h>
#include <string.h>

char* longestP(char str[], int size) {
    int i, j;
    if (size == 0)
        return "";

    int len = strlen(str[0]);
    for (i = 0; i < len; i++) {
        for (j = 1; j < size; j++) {
            if (str[j][i] != str[0][i] || str[j][i] == '\0') {
                str[0][i] = '\0';
                break;
            }
        }
    }

    return str[0];
}

int main() {
    char str[10][10]; 
    int i, size;
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        scanf("%s", str[i]);
    }

    char* result = longestP(str, size);
    printf("Longest Common Prefix: %s\n", result);

    return 0;
}
