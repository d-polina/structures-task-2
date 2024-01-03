// Дан текст. Группы символов, разделенные пробелами (одним или несколькими) и не содержащие пробелов внутри себя, 
// будем называть словами. Найти количество слов, начинающихся с буквы "t"

// 1 вариант. дана строка символов, ввести ее используя функцию calloc, память захватывать не больше 5 символов, если памяти не хватает, то использовать функцию realloc
// если символов не хватает, то захватывать порцию по 3

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(void)
{

    int n = 5;
    int count = 0;
    int i = 0;
    char s;
    char *str = (char*)calloc(n, sizeof(char));

    if (str != NULL) {
        printf("Введите текст: ");

        while((s = getchar()) != '\n') {
            str[i] = s;
            i++;
            if (strlen(str) > 5) {
                if (str != NULL) {
                    str = (char*)realloc(str, 3 * sizeof(char));
                } else {
                    printf("Ошибка");
                    return 1;
                }
            }
        }

        printf("Введено: %s\n", str);
    } else {
        printf("Ошибка");
        return 1;
    }

    i = 0;
    while (i < strlen(str) - 1) {
        if (str[i] == 't' && (i == 0 || str[i-1] == ' ')) {
        count++;
        }
        i++;
    }
    printf("Количество слов, начинающихся на 't': %d \n", count);

    free(str);
    return 0;
}
