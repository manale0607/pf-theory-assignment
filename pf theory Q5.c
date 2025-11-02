#include <stdio.h>
void encode(char msg[]);
void decode(char msg[]);
void reverse(char msg[]);
int main() {
    char msg[200];
    int choice, i;
    while (1) {
        printf("\n--- TCS Secure Message Tool ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        if (choice == 3) {
            printf("\nGoodbye!\n");
            break;
        }
        printf("\nEnter message: ");
        i = 0;
        while (1) {
            msg[i] = getchar();
            if (msg[i] == '\n') {
                msg[i] = '\0';
                break;
            }
            i++;
        }
        if (choice == 1)
            encode(msg);
        else if (choice == 2)
            decode(msg);
        else
            printf("\nInvalid choice!\n");
    }
    return 0;
}
void reverse(char msg[]) {
    int len = 0, i;
    char temp;
    while (msg[len] != '\0')
        len++;
    for (i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }
}
void encode(char msg[]) {
    int i;
    reverse(msg);
    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ (1 << 1); 
        msg[i] = msg[i] ^ (1 << 4); 
    }
    printf("\nEncoded message: %s\n", msg);
}
void decode(char msg[]) {
    int i;

    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);
    }
    reverse(msg);
    printf("\nDecoded message: %s\n", msg);
}

