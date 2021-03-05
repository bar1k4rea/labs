#include <stdio.h>
#include <string.h>
#include <malloc.h>


char* inputString(int *n);
char* skipSpace(char *old_str);
char* sortString(char *new_str);


int main() {
    int signal;
    char *old_str = NULL, *new_str = NULL;
    
    do {
        old_str = inputString(&signal);
        if (signal == -1) {
            printf("\n");
            return 0;
        }
        new_str = skipSpace(old_str);
        new_str = sortString(new_str);
        printf("FINAL STRING: %s\n", new_str);
        free(old_str);
        free(new_str);
    } while (signal > 0);
    return 0;
}


char* inputString(int *n) {
    char *str = (char*)malloc(1);
    char buffer[101];

    str = '\0';
    printf("\nEnter the string: ");
    *n = scanf("%100[^\n]%*c", buffer);
    str = (char*)realloc(str, strlen(buffer) + 1);
    strcat(str, buffer);
    return str;
}


char* skipSpace(char *old) {
    char *new = (char*)calloc(strlen(old) + 1, sizeof(char));
    int i = 0, j = 0;

    while (i < strlen(old)) {
        if ((old[i] != ' ') && (old[i] != '\t')) {
            new[j] = old[i];
            j++;
            if ((old[i + 1] == ' ') || (old[i + 1] == '\t')) {
                new[j] = ' ';
                j++;
            }
        }
        i++;
    }
    new[j] = '\0';
    new = (char*)realloc(new, strlen(new)*sizeof(char) + 1);
    return new;
}


char* sortString(char *str) {
    char tmp;
    int i, j, n, k = 0, l = 1;
    
    for (i = 0; i < strlen(str) + 1; i++) {
        if ((str[i] == ' ') || (str[i] == '\0')) {
            n = (i - k) / 2;
            for (j = k; j < n + k; j++, l++) {
                tmp = str[j];
                str[j] = str[i - l];
                str[i - l] = tmp;
            }
            k = i + 1;
            l = 1;
        }
    }
    return str;
}
