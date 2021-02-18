#include <stdio.h> 
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *alines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getlines(char *, int);

int main() {
    int nlines;
    char alines[MAXLINES * MAXLEN];

    if ((nlines = readlines(lineptr, MAXLINES, alines)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        printf("sorted:\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines, char *alines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    /* set pointer to next open position in the all lines array */
    p = alines + strlen(alines);
    while ((len = getlines(line, MAXLEN)) > 0) {
        /* check that adding another line won't go out of the array bounds */
        if (nlines >= maxlines || (strlen(alines) >= MAXLINES * MAXLEN)) { 
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            /* increment the pointer */
            p += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getlines(char *s, int lim){
    int c, i;
    
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
