#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int solution(char* inputString) {
    int length = strlen(inputString);
    if (length == 1) return 0;
    int* map = (int*) malloc(26 * sizeof(int));
    int i;
    int letter;
    int count = 0;
    for (i = 0; i < 26; i++) {
        map[i] = 0;
    }
    for (i = 0; i<length; i++) {
        letter = (int)(inputString[i]) - 65;
        map[letter]++;
    }
    if (length % 2 == 0) {
        for (i = 0; i<26; i++) {
            if (map[i] % 2) return 1;
        }   
    } else {
        for (i = 0; i<26; i++) {
            if (map[i] % 2) count++;
        }
        if (count > 1) return 1;
    }
    return 0;
}

int main(void) {
    char input[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc";
    printf("Result: ");
    printf(solution(input) ? "false\n" : "true\n");
}