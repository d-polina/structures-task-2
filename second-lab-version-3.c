// Дан текст. Группы символов, разделенные пробелами (одним или несколькими) и не содержащие пробелов внутри себя, 
// будем называть словами. Найти количество слов, начинающихся с буквы "t"

// 3 вариант.строку в файл. считываем из файла открываем первую или вторую задачу и результат помещаем в файл

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(void)
{

    int count = 0;
    int i = 0;
    char *str = (char*)malloc(sizeof(char));
    char s;

    FILE *fp = fopen("text.txt", "r"); 
    
    if (fp != NULL) {
        while ((s = fgetc(fp)) != EOF) {
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
        printf("Ошибка c файлом");
        fclose(fp); 
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
    fclose(fp); 
    return 0;
}