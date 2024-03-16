#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[20], c;
    int state = 0, i = 0;

    printf("\nEnter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  // Remove the newline character from the input

    while (s[i] != '\0') {
        switch (state) {
            case 0:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else
                    state = 4;
                break;
            case 1:
                c = s[i++];
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else
                    state = 4;
                break;
            case 2:
                c = s[i++];
                if (c == 'b')
                    state = 3;
                else
                    state = 4;
                break;
            case 3:
                c = s[i++];
                if (c != '\0')
                    state = 4;
                break;
            case 4:
                printf("\n%s is not recognized.", s);
                exit(0);
        }
    }

    if (state == 1)
        printf("\n%s is accepted under rule a\n", s);
    else if (state == 3)
        printf("\n%s is accepted under rule abb\n", s);
    else
        printf("\n%s is not accepted\n", s);

    return 0;
}
