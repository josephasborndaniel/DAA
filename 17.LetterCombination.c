#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *phoneMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char *digits, char *combination, char **result, int index, int *count) {
    if (index == strlen(digits)) {
        result[*count] = strdup(combination);
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    char *letters = phoneMap[digit];

    for (int i = 0; i < strlen(letters); i++) {
        combination[index] = letters[i];
        backtrack(digits, combination, result, index + 1, count);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int totalCombinations = 1;
    for (int i = 0; i < strlen(digits); i++) {
        totalCombinations *= strlen(phoneMap[digits[i] - '0']);
    }

    char **result = (char **)malloc(totalCombinations * sizeof(char *));
    char *combination = (char *)malloc(strlen(digits) + 1);
    combination[strlen(digits)] = '\0';

    *returnSize = 0;
    backtrack(digits, combination, result, 0, returnSize);

    free(combination);
    return result;
}

int main() {
    char digits[] = "23";
    int returnSize;
    char **result = letterCombinations(digits, &returnSize);

    printf("Letter Combinations of the Phone Number %s:\n", digits);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
