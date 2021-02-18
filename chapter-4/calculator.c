#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100        /* max size of operand or operator */
#define NUMBER '0'       /* signal that a number was found */
#define PRINT '1'        /* signal to print the top of the stack */
#define SIN '2'          /* signal that the sin operator was found */
#define EXP '3'          /* signal that the exponential function operator was found */
#define POW '4'          /* signal that the power function operator was found */
#define CLEAR '5'        /* signal to clear stack */
#define SWAP '6'         /* signal to swap the top 2 elements on the stack */
#define DUPLICATE '7'    /* signal to duplicate the top element of the stack */
#define MAXVAL 100       /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;              /* next free stack position */
double val[MAXVAL];      /* value stack */
char buf[BUFSIZE];       /* buffer for ungetch */
int bufp = 0;            /* next free position in buf */

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    double op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            }
            else {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            push(fmod(pop(), op2));
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            op1 = pop();
            if (op1 == 0 && op2 <= 0) {
                printf("error: domain error\n");
            }
            if (op1 < 0 && !isdigit(op2)) {
                printf("error: domain error");
            }
            else {
                push(pow(op1, op2));
            }
            break;
        case PRINT:
            op2 = pop();
            printf("The top of the stack is: %.8g\n", op2);
            push(op2);
            break;
        case CLEAR:
            sp = 0;
            printf("stack cleared\n");
            break;
        case SWAP:
            op2 = pop();
            op1 = pop();
            printf("swapping %.8g\t%.8g\n", op2, op1);
            push(op2);
            push(op1);
            break;
        case DUPLICATE:
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c; 
    
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        if (isalpha(c)) {      /* handle strings */
            i = 0;
            while (isalpha(s[++i] = c = getch())) {
                ;
            }
            s[i] = '\0';
            if (strcmp(s, "sin") == 0) {
                return SIN;        /* SIN */
            }
            if (strcmp(s, "exp")== 0) {
                return EXP;        /* EXP */
            }
            if (strcmp(s, "pow")== 0) {
                return POW;        /* POW */
            }
            if (strcmp(s, "print")== 0) {
                return PRINT;      /* PRINT */
            }
            if (strcmp(s, "clear")== 0) {
                return CLEAR;      /* CLEAR */
            }
            if (strcmp(s, "swap")== 0) {
                return SWAP;       /* SWAP */
            }
            if (strcmp(s, "dupe")== 0) {
                return DUPLICATE;  /* DUPLICATE */
            }
        }
        return c;              /* not a number */
    }
    i = 0;
    if (c == '-') {            /* handle negative numbers */
        s[++i] = c = getch();
    }
    if (isdigit(c)) {          /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    if (c == '.') {            /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

/* get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push a character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
