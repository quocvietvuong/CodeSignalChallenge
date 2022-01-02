#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Write a function that reverses characters in (possibly nested) parentheses in the input string.
// Input strings will always be well-formed with matching ()s.

// For inputString = "(bar)", the output should be solution(inputString) = "rab";
// For inputString = "foo(bar)baz", the output should be solution(inputString) = "foorabbaz";
// For inputString = "foo(bar)baz(blim)", the output should be solution(inputString) = "foorabbazmilb";
// For inputString = "foo(bar(baz))blim", the output should be solution(inputString) = "foobazrabblim".
// (Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim".)

void reverse(char* inputString) {
    int i = 0;
    char temp;
    int strLength = strlen(inputString);
    while (i < strLength/2) 
    {
        temp = inputString[i];
        inputString[i] = inputString[strLength - 1 - i];
        inputString[strLength - 1 - i] = temp;
        i++;
    }
}

char* reverseInParentheses(char* inputString) {
    int i, j, k, l;
    int strLength = strlen(inputString);
    char* innerString = NULL;
    j = 0;
    while (inputString[j] != ')' && j < strLength) j++;
    if (j == strLength) return inputString;
    i = j - 1;
    while (inputString[i] != '(' && i >= 0) i--;
    if (i == -1) 
    {
        return inputString;
    }
    else 
    {
        innerString = (char*) malloc ((j-i) * sizeof(char));
        for (k = 0; k < j-i-1; k++) 
        {
            innerString[k] = inputString[i+1+k];
        }
        innerString[k] = '\0';   
        reverse(innerString);
        l = 0;
        for (k = i; k < j-1; k++) 
        {
            inputString[k] = innerString[l++];
        }
        l = j+1;
        while (l < strLength) 
        {
            inputString[k] = inputString[l];
            k++;
            l++;
        }
        inputString[k] = '\0';
        return reverseInParentheses(inputString);
    }
    
}

int main() {
    char newString1[] = "(bar)";
    char newString2[] = "foo(bar)baz";
    char newString3[] = "foo(bar)baz(blim)";
    char newString4[] = "foo(bar(baz))blim";
    printf("inputString = ""(bar)"", reverseInParentheses(inputString) = %s\n", reverseInParentheses(newString1));
    printf("inputString = ""foo(bar)baz"", reverseInParentheses(inputString) = %s\n", reverseInParentheses(newString2));
    printf("inputString = ""foo(bar)baz(blim)"", reverseInParentheses(inputString) = %s\n", reverseInParentheses(newString3));
    printf("inputString = ""foo(bar(baz))blim"", reverseInParentheses(inputString) = %s\n", reverseInParentheses(newString4));
}