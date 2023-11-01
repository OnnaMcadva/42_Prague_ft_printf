#include "ft_printf.h"

int main()
{
// Тест для спецификатора %c:
// без ошибок

//char c = 'A';
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
// без ошибок
/*
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
*/

// с ошибками
/*
void *null_ptr = NULL;
printf("Original printf: %p\n", null_ptr); // передача нулевого указателя
ft_printf("Custom ft_printf: %p\n", null_ptr);
//char *uninitialized_ptr;
//printf("Original printf: %p\n", uninitialized_ptr); // передача неинициализированного указателя
//ft_printf("Custom ft_printf: %p\n", uninitialized_ptr); // передача неинициализированного указателя
char buffer[10];
char *out_of_bounds_ptr = &buffer[20];
printf("Original printf: %p\n", out_of_bounds_ptr); // передача указателя, выходящего за пределы памяти
ft_printf("Custom ft_printf: %p\n", out_of_bounds_ptr);
void (*fn_ptr)() = &test_function;
printf("Original printf: %p\n", fn_ptr); // передача указателя на функцию
ft_printf("Custom ft_printf: %p\n", fn_ptr);
*/

//    Тест для спецификатора  %i и %d:
// без ошибок
/*
int num12345 = 12345;
printf("Original printf: %d\n", num12345);
ft_printf("Custom ft_printf: %d\n", num12345);
int positive_num = 42;
printf("Original printf: %d\n", positive_num);
ft_printf("Custom ft_printf: %d\n", positive_num);
int negative_num = -123;
printf("Original printf: %d\n", negative_num);
ft_printf("Custom ft_printf: %d\n", negative_num);
int zero_num = 0;
printf("Original printf: %d\n", zero_num);
ft_printf("Custom ft_printf: %d\n", zero_num);
int max_int = INT_MAX;
printf("Original printf: %d\n", max_int);
ft_printf("Custom ft_printf: %d\n", max_int);
int min_int = INT_MIN;
printf("Original printf: %d\n", min_int);
ft_printf("Custom ft_printf: %d\n", min_int);
int custom_num = 9876;
printf("Original printf: %d\n", custom_num);
ft_printf("Custom ft_printf: %d\n", custom_num);
int integer = -54321;
printf("Original printf: %i\n", integer);
ft_printf("Custom ft_printf: %i\n", integer);
*/
// тесты с 8 и 16
/*
int hex_num1 = 0xABC;
printf("Original printf: %d\n", hex_num1);
ft_printf("Custom ft_printf: %d\n", hex_num1);
int octal_num = 0123;
printf("Original printf: %d\n", octal_num);
ft_printf("Custom ft_printf: %d\n", octal_num);
int hex_num_int = 0xABC;
printf("Original printf: %d\n", hex_num_int);
ft_printf("Custom ft_printf: %d\n", hex_num_int);
int octal_num_int = 0123;
printf("Original printf: %d\n", octal_num_int);
ft_printf("Custom ft_printf: %d\n", octal_num_int);
*/

// с ошибками
/*
double invalid_num = 123.456;
//printf("Original printf: %d\n", invalid_num); // передача дробного числа
ft_printf("Custom ft_printf: %d\n", invalid_num); // ведет себя неверно
char *invalid_str = "hello";
//printf("Original printf: %d\n", invalid_str); // передача строки
ft_printf("Custom ft_printf: %d\n", invalid_str); // ведет себя неверно
void *invalid_ptr = &test_function;
//printf("Original printf: %d\n", invalid_ptr); // передача указателя
ft_printf("Custom ft_printf: %d\n", invalid_ptr); // ведет себя неверно
//printf("orig print: %d\n", -2147483648);
ft_printf("orig print: %d\n", -2147483648); // ведет себя неверно
*/

//    Тест для спецификатора %u:
/*
// без ошибок
unsigned int unsigned_num = 54321;
printf("Original printf: %u\n", unsigned_num);
ft_printf("Custom ft_printf: %u\n", unsigned_num);
unsigned int positive_num1 = 12345;
printf("Original printf: %u\n", positive_num1);
ft_printf("Custom ft_printf: %u\n", positive_num1);
unsigned int zero = 0;
printf("Original printf: %u\n", zero);
ft_printf("Custom ft_printf: %u\n", zero);
unsigned int max_value = UINT_MAX;
printf("Original printf: %u\n", max_value);
ft_printf("Custom ft_printf: %u\n", max_value);
*/
// с ошибками
/*
int negative_num = -123;
printf("Original printf: %u\n", negative_num); // передача отрицательного числа
ft_printf("Custom ft_printf: %u\n", negative_num);
char invalid_char = 'A';
printf("Original printf: %u\n", invalid_char); // передача символа
ft_printf("Custom ft_printf: %u\n", invalid_char);
double decimal_num = 123.456;
printf("Original printf: %u\n", (unsigned int)decimal_num); // передача дробного числа
ft_printf("Custom ft_printf: %u\n", (unsigned int)decimal_num);
*/

//    Тест для спецификатора %x и %X:
/*
// без ошибок
int hex_num = 255;
printf("Original printf: %x\n", hex_num);
ft_printf("Custom ft_printf: %x\n", hex_num);
int upper_hex_num = 255;
printf("Original printf: %X\n", upper_hex_num);
ft_printf("Custom ft_printf: %X\n", upper_hex_num);
unsigned int positive_num = 4567;
printf("Original printf: %x\n", positive_num);
ft_printf("Custom ft_printf: %x\n", positive_num);
printf("Original printf: %X\n", positive_num);
ft_printf("Custom ft_printf: %X\n", positive_num);
unsigned int zero = 0;
printf("Original printf: %x\n", zero);
ft_printf("Custom ft_printf: %x\n", zero);
printf("Original printf: %X\n", zero);
ft_printf("Custom ft_printf: %X\n", zero);
unsigned int max_value = UINT_MAX;
printf("Original printf: %x\n", max_value);
ft_printf("Custom ft_printf: %x\n", max_value);
printf("Original printf: %X\n", max_value);
ft_printf("Custom ft_printf: %X\n", max_value);
*/
// с ошибками
/*
int negative_num = -123;
printf("Original printf: %x\n", negative_num); // передача отрицательного числа
ft_printf("Custom ft_printf: %x\n", negative_num);
printf("Original printf: %X\n", negative_num); // передача отрицательного числа
ft_printf("Custom ft_printf: %X\n", negative_num);
char invalid_char = 'A';
printf("Original printf: %x\n", invalid_char); // передача символа
ft_printf("Custom ft_printf: %x\n", invalid_char);
printf("Original printf: %X\n", invalid_char); // передача символа
ft_printf("Custom ft_printf: %X\n", invalid_char);
double decimal_num = 123.456;
printf("Original printf: %x\n", (unsigned int)decimal_num); // передача дробного числа
ft_printf("Custom ft_printf: %x\n", (unsigned int)decimal_num);
printf("Original printf: %X\n", (unsigned int)decimal_num); // передача дробного числа
ft_printf("Custom ft_printf: %X\n", (unsigned int)decimal_num);
*/

//   Тест для спецификатора %%:

printf("Original printf: %%\n");
ft_printf("Custom ft_printf: %%\n");
printf("Original printf: Hello, %% world!\n");
ft_printf("Custom ft_printf: Hello, %% world!\n");
int num = 123;
printf("Original printf: The number is %d%%\n", num);
ft_printf("Custom ft_printf: The number is %d%%\n", num);

char invalid_char = 'A';
printf("Original printf: %%%c\n", invalid_char); // передача символа
ft_printf("Custom ft_printf: %%%c\n", invalid_char);


    return 0;
}

void test_function() {
    write(1, "abra", 4);
}
