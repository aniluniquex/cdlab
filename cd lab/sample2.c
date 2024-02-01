#include <stdio.h>

int main() {
    char arr[20] = "code /* this is a comment";

    int i;
    int commentStartIndex = -1;  

    for (i = 0; i < 18; i++) {  
        if (arr[i] == '/' && arr[i + 1] == '/') {
            commentStartIndex = i;
            // printf("Single-line comment found starting from index %d: %s\n", commentStartIndex, &arr[i]);
            printf("Single-line comment found starting from index %d\n", commentStartIndex);
            break;  
        } 
        else if (arr[i] == '/' && arr[i + 1] == '*') {
            commentStartIndex = i;
            // printf("Multi-line comment found starting from index %d: %s\n", commentStartIndex, &arr[i]);
            printf("multi-line comment found starting from index %d\n", commentStartIndex);
            break;  
        }
    }

    if (commentStartIndex == -1) {
        printf("no comment found in the array.\n");
    }

    return 0;
}
