#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200

int main() {
    setlocale(LC_ALL, "");
    char text[MAX_LENGTH];
    char word[MAX_LENGTH];
    char* ptr;
    int count = 0;

    printf("Введите строку: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Введите слово для поиска: ");
    scanf("%s", word);

    ptr = text;
    while ((ptr = strstr(ptr, word)) != NULL) {
        int start_pos = ptr - text;
        int end_pos = start_pos + strlen(word);

        int is_word_start = (start_pos == 0 || !isalnum(text[start_pos - 1]));
        int is_word_end = (text[end_pos] == '\0' || !isalnum(text[end_pos]));

        if (is_word_start && is_word_end) {
            count++;
        }

        ptr += strlen(word); 
    }

    printf("\nРезультаты:\n");
    printf("Текст: \"%s\"\n", text);
    printf("Слово \"%s\" встречается %d раз(а)\n", word, count);

    return 0;
}