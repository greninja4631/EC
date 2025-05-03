#include <stdio.h>
#include <string.h>

char message[100] = "Hello, world!";

void get_message() {
    printf("GET /message: %s\n", message);
}

void post_message(const char *new_msg) {
    strncpy(message, new_msg, sizeof(message) - 1);
    message[sizeof(message) - 1] = '\0';
    printf("POST /message: %s\n", message);
}

int main() {
    get_message();
    post_message("ぼっち・ざ・ホロリス！");
    get_message();
    return 0;
}