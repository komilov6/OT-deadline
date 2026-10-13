#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Satrni so'zlarga ajratish funksiyasi
char **splitString(const char *str, int *wordCount) {
    char **words = NULL;
    char *temp = strdup(str); // Satrni nusxalash
    char *token = strtok(temp, " ");
    int count = 0;

    while (token != NULL) {
        words = realloc(words, (count + 1) * sizeof(char *));
        if (words == NULL) {
            printf("Xotira ajratishda xatolik!\n");
            free(temp);
            return NULL;
        }
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }

    free(temp);
    *wordCount = count;
    return words;
}

// Ajratilgan xotirani bo'shatish funksiyasi
void freeWords(char **words, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    char str[256];
    char **words;
    int wordCount;

    // Satrni kiritish
    printf("Satrni kiriting: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Oxiridagi '\n' belgini olib tashlash

    // Satrni so'zlarga ajratish
    words = splitString(str, &wordCount);
    if (words == NULL) {
        return 1;
    }

    // So'zlarni chop etish
    printf("So'zlar:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    // Ajratilgan xotirani bo'shatish
    freeWords(words, wordCount);

    return 0;
}