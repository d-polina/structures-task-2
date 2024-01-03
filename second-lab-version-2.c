// Дан текст. Группы символов, разделенные пробелами (одним или несколькими) и не содержащие пробелов внутри себя, 
// будем называть словами. Найти количество слов, начинающихся с буквы "t"

// 2 вариант. дана строка символов, нужно ее ввести используя функцию malloc. при вводе очередного символа, нужно захватить память под строку с помощью reaclloc. захватывать порцию по 1

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(void)
{

    int count = 0;
    int i = 0;
    char *str = (char*)malloc(sizeof(char));

    if (str != NULL) {
        printf("Введите текст: ");
        char s;
        while((s = getchar()) != '\n') {
            str[i] = s;
            i++;
            if (str != NULL) {
                str = (char*)realloc(str, (i+1)*sizeof(char));
            } else {
                printf("Ошибка");
                return 1;
            }
            
        }
        str[i] = '\0';

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
