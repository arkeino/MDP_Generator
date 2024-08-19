#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 22

char generate_random_char(const char *charset) {
    return charset[rand() % strlen(charset)];
}

void shuffle_password(char *password, int length) {
    for (int i = 0; i < length; i++) {
        int random_index = rand() % length;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }
}

void generate_password(char *password) {
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    password[0] = generate_random_char(uppercase);
    password[1] = generate_random_char(digits);
    password[2] = generate_random_char(digits);
    password[3] = generate_random_char(digits);
    password[4] = generate_random_char(special_chars);

    for (int i = 5; i < PASSWORD_LENGTH; i++) {
        int rand_choice = rand() % 4;
        switch (rand_choice) {
            case 0: password[i] = generate_random_char(lowercase); break;
            case 1: password[i] = generate_random_char(uppercase); break;
            case 2: password[i] = generate_random_char(digits); break;
            case 3: password[i] = generate_random_char(special_chars); break;
        }
    }

    shuffle_password(password, PASSWORD_LENGTH);

    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH + 1];
    generate_password(password);

    printf("Mot de passe généré : %s\n", password);

    return 0;
}
