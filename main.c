#include "stdio.h"

int isChar(char c) {
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

int isDigit(const char c) {
    return (c >= '0' && c <= '9');
}

int is_valid(char email[30]) {
    if (!isChar(email[0])) {

        return 0;
    }
    int At = -1, Dot = -1;
    int AtCounter = 0, DotCounter = 0;
    for (int i = 0;
         i < 30; i++) {
        if (email[i] == '@') {
            At = i;
            AtCounter++;
        } else if (email[i] == '.') {
            Dot = i;
            DotCounter += AtCounter ? 1 : 0;
        }
    }
    if (At == -1 || Dot == -1)
        return 0;
    if (At > Dot)
        return 0;
    return !(Dot >= (30 - 1) || (DotCounter > 1) || (AtCounter > 1));
}

// Driver Code
int main() {
    char email[30];
    printf("Enter email:");
    scanf(" %s", &email);
    int ans = is_valid(email);
    if (ans) {
        printf("%s is valid", email);
    } else {
        printf("%s isn't valid", email);
    }
    return 0;
}