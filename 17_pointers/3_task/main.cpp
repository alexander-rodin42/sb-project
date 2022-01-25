#include <iostream>

bool substr (const char *a, const char *b) {
    for (int i = 0; *(a + i) != '\0'; i++) {
        for (int j = 0; *(b + j) != '\0'; j++) {
            if ( *(a + i + j) == '\0' || *(a + i + j) != *(b + j)) {
                break;
            } else {
                if ( *(b + j + 1) == '\0') {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c);
    return 0;
}
