#include <stdarg.h>
#include <stdio.h>

void print_args_copy(int num_args, ...) {
    va_list args;
    va_start(args, num_args);

    va_list args_copy;
    va_copy(args_copy, args);

    for (int i = 0; i < num_args; i++) {
        int val = va_arg(args_copy, int);
        printf("%d: %d\n", i, val);
    }

    va_end(args_copy);
    va_end(args);
}

void simple_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // Обратите внимание, что char промотируется к int при передаче через `...`.
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }

    va_end(args);
}

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int main() {
    printf("%d\n", sum(4, 1, 2, 3, 4)); // Выведет 10

    simple_printf("dcf", 3, 'a', 3.14159);

    print_args_copy(3, 10, 20, 30);
    return 0;
}
