#include "ft_printf.h"

int main()
{
// Тест для спецификатора %c:
// без ошибок

char c = 'A';
/*
printf("Original printf: %c\n", c);
ft_printf("Custom ft_printf: %c\n", c);
char c2 = 'b';
printf("Original printf: %c\n", c2);
ft_printf("Custom ft_printf: %c\n", c2);
char space = ' ';
printf("Original printf: %c\n", space);
ft_printf("Custom ft_printf: %c\n", space);
char newline = '\n';
printf("Original printf: %c\n", newline);
ft_printf("Custom ft_printf: %c\n", newline);
char control_char = '\t'; // например, табуляция
printf("Original printf: %c\n", control_char);
ft_printf("Custom ft_printf: %c\n", control_char);
char ascii_char = 65; // код ASCII для символа 'A'
printf("Original printf: %c\n", ascii_char);
ft_printf("Custom ft_printf: %c\n", ascii_char);
char max_ascii_char = 127; // максимальный код ASCII для символа
printf("Original printf: %c\n", max_ascii_char);
ft_printf("Custom ft_printf: %c\n", max_ascii_char);
char min_ascii_char = 0; // минимальный код ASCII для символа
printf("Original printf: %c\n", min_ascii_char);
ft_printf("Custom ft_printf: %c\n", min_ascii_char);
*/
// с ошибками
/*
int num65 = 65;
printf("Original printf: %c\n", num65); // передача числа вместо символа
ft_printf("Custom ft_printf: %c\n", num65);
char *null_ptr = NULL;
//printf("Original printf: %c\n", null_ptr); // передача нулевого указателя
ft_printf("Custom ft_printf: %c\n", null_ptr);  // передача нулевого указателя - ведет себя не так!!!
double d = 3.14;
//printf("Original printf: %c\n", d); // передача вещественного числа
ft_printf("Custom ft_printf: %c\n", d); // передача вещественного числа - ведет себя не так!!!
//char uninitialized_char;
//printf("Original printf: %c\n", uninitialized_char); // передача неинициализированной переменной
//ft_printf("Custom ft_printf: %c\n", uninitialized_char);  // передача неинициализированной переменной
int invalid_ascii = 150; // значение, превышающее допустимый диапазон ASCII
printf("Original printf: %c\n", invalid_ascii);
ft_printf("Custom ft_printf: %c\n", invalid_ascii);
*/

//    Тест для спецификатора %s:
// без ошибок
/*
char *str = "Hello, world!";
printf("Original printf: %s\n", str);
ft_printf("Custom ft_printf: %s\n", str);
char *empty_str = "";
printf("Original printf: %s\n", empty_str);
ft_printf("Custom ft_printf: %s\n", empty_str);
char *str_with_spaces = "String with spaces";
printf("Original printf: %s\n", str_with_spaces);
ft_printf("Custom ft_printf: %s\n", str_with_spaces);
char *str_with_punctuation = "String with punctuation!?,.";
printf("Original printf: %s\n", str_with_punctuation);
ft_printf("Custom ft_printf: %s\n", str_with_punctuation);
char *str_with_control_chars = "String\nwith\tcontrol\bsymbols";
printf("Original printf: %s\n", str_with_control_chars);
ft_printf("Custom ft_printf: %s\n", str_with_control_chars);
char *unicode_str = "Строка с Unicode символами 😊";
printf("Original printf: %s\n", unicode_str);
ft_printf("Custom ft_printf: %s\n", unicode_str);
char *long_str = "This is a very long string that will test the performance of the printf function in both the original printf and the custom ft_printf. This string is longer than usual to check if the function can handle it efficiently.";
printf("Original printf: %s\n", long_str);
ft_printf("Custom ft_printf: %s\n", long_str);
char max_str[10000];
memset(max_str, 'A', sizeof(max_str) - 1);
max_str[sizeof(max_str) - 1] = '\0';
printf("Original printf: %s\n", max_str);
ft_printf("Custom ft_printf: %s\n", max_str);
*/
// с ошибками
/*
char *null_str = NULL;
printf("Original printf: %s\n", null_str); // передача нулевого указателя
ft_printf("Custom ft_printf: %s\n", null_str);
double d = 3.14;
//printf("Original printf: %s\n", d); // передача вещественного числа
ft_printf("Custom ft_printf!: %s\n", d); // передача вещественного числа - ведет себя не так!!!
//char *uninitialized_str;
//printf("Original printf: %s\n", uninitialized_str); // передача неинициализированного указателя
//ft_printf("Custom ft_printf: %s\n", uninitialized_str);
char non_null_terminated_str[10] = {'H', 'e', 'l', 'l', 'o'};
//printf("Original  printf:( %s\n\n)", non_null_terminated_str); // передача строки без нулевого символа
printf("---------");
ft_printf("Custom ft_printf:( %s\n\n)", non_null_terminated_str); // не понимаю поведение)))
ft_printf("---------");
char *out_of_bounds_str = "Hello, world!";
printf("Original printf: %s\n!", out_of_bounds_str + 100); // передача указателя, выходящего за пределы строки
ft_printf("Custom ft_printf: %s\n!", out_of_bounds_str + 100); // не понимаю поведение)))
*/

//    Тест для спецификатора %p:

void *ptr = &c;
printf("Original printf: %p\n", ptr);
ft_printf("Custom ft_printf: %p\n", ptr);
int num = 42;
printf("Original printf: %p\n", (void*)&num);
ft_printf("Custom ft_printf: %p\n", (void*)&num);
char *str = "Hello, world!";
printf("Original printf: %p\n", (void*)str);
ft_printf("Custom ft_printf: %p\n", (void*)str);

void (*fn_ptr)() = &test_function;
printf("Original printf: %p\n", (void*)fn_ptr);
ft_printf("Custom ft_printf: %p\n", (void*)fn_ptr);

void *null_ptr = NULL;
printf("Original printf: %p\n", null_ptr);
ft_printf("Custom ft_printf: %p\n", null_ptr);
double d = 3.14;
printf("Original printf: %p\n", (void*)&d);
ft_printf("Custom ft_printf: %p\n", (void*)&d);
unsigned int ui = 12345;
printf("Original printf: %p\n", (void*)&ui);
ft_printf("Custom ft_printf: %p\n", (void*)&ui);


//    Тест для спецификатора %d:

int num12345 = 12345;
printf("Original printf: %d\n", num12345);
ft_printf("Custom ft_printf: %d\n", num12345);

//    Тест для спецификатора %i:

int integer = -54321;
printf("Original printf: %i\n", integer);
ft_printf("Custom ft_printf: %i\n", integer);

//    Тест для спецификатора %u:

unsigned int unsigned_num = 54321;
printf("Original printf: %u\n", unsigned_num);
ft_printf("Custom ft_printf: %u\n", unsigned_num);

//    Тест для спецификатора %x:

int hex_num = 255;
printf("Original printf: %x\n", hex_num);
ft_printf("Custom ft_printf: %x\n", hex_num);

//    Тест для спецификатора %X:

int upper_hex_num = 255;
printf("Original printf: %X\n", upper_hex_num);
ft_printf("Custom ft_printf: %X\n", upper_hex_num);

//   Тест для спецификатора %%:

printf("Original printf: %%\n");
ft_printf("Custom ft_printf: %%\n");

    return 0;
}


void test_function() {
    write(1, "abra", 4);
}
