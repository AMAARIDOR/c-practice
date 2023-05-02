#include <stdio.h>
#define MAXLINE 1000

int linegetter(char line[], int maxline);
void copier(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while ((len = linegetter(line, MAXLINE)) > 0)

    return 0;
}

int linegetter(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}