#include "s21_string.h"

int s21_sprintf(char *buf, const char *format, ...) {

    // Specs: %c d i f s u
    // Flags: - + space
    // Width: (number)
    // Precision: .(number)
    // Length: h, l.

    va_list p_args;
    va_start(p_args, format);

    copy_to_buf(buf, format, p_args);

    va_end(p_args);
    return strlen(buf); //replace_with_s21
}

void copy_to_buf(char *buf, const char *string, va_list p_args) {

    int i[2] = {0, 0};

    for(; i[0] < (int)strlen(string); i[0]++, i[1]++) { //replace_with_s21

        if(string[i[0]] == '%') {
            format_processing(string, i, buf, p_args);
        } else {
            buf[i[1]] = string[i[0]];
        }
        
    }

    buf[i[1]] = '\0';

}

void format_processing(const char *format, int *i, char *buf, va_list p_args) {

    format_t format_data;

    format_data.minus = 0;
    format_data.plus = 0;
    format_data.space = 0;
    format_data.l = 0;
    format_data.h = 0;
    format_data.width = 0;
    format_data.isprecision = 0;
    format_data.precision = 0;
    format_data.spec = '\0';

    for(; i[0] < (int)strlen(format) && strchr("cdifsugGeExXonp", format[i[0]]) == NULL; i[0]++) { //replace_with_s21
        
        switch(format[i[0]]) {
            case '+':
                format_data.plus = 1;
                break;
            case '-':
                format_data.minus = 1;
                break;
            case ' ':
                format_data.space = 1;
                break;
            case 'l':
                format_data.l = 1;
                break;
            case 'h':
                format_data.h = 1;
                break;
            case '.':
                format_data.isprecision = 1;
                break;
        }

        if(format_data.isprecision && (format[i[0]] > 47 && format[i[0]] < 58)) {

            format_data.precision = format_data.width * 10 + format[i[0]] - 48;

        } else if(format[i[0]] > 47 && format[i[0]] < 58) {

            format_data.width = format_data.width * 10 + format[i[0]] - 48;

        }
    }
    
    format_data.spec = format[i[0]];

    format_and_buff(i, buf, p_args, format_data);

}

void format_and_buff(int *i, char *buf, va_list p_args, format_t format_data) {

    // %[flags][width][.precision][length]specifier

    switch(format_data.spec) {
        case 'c':
            c_to_buf(va_arg(p_args, int), format_data, buf, i);
            break;
        case 'd':
            va_arg(p_args, int);
            break;
        case 'i':
            format_data.space = 1;
            break;
        case 'f':
            format_data.l = 1;
            break;
        case 's':
            format_data.h = 1;
            break;
        case 'u':
            format_data.isprecision = 1;
            break;
        case 'g':
            format_data.plus = 1;
            break;
        case 'G':
            format_data.minus = 1;
            break;
        case 'e':
            format_data.space = 1;
            break;
        case 'E':
            format_data.l = 1;
            break;
        case 'x':
            format_data.h = 1;
            break;
        case 'X':
            format_data.isprecision = 1;
            break;
        case 'n':
            format_data.l = 1;
            break;
        case 'o':
            format_data.h = 1;
            break;
        case 'p':
            format_data.isprecision = 1;
            break;
    }

}

void c_to_buf(const char c, format_t format_data, char *buf, int *i) {

    // typedef struct format_struct {
    //     int minus;
    //     int plus;
    //     int space;
    //     int l;
    //     int h;
    //     int width;
    //     int precision;
    //     int isprecision;
    //     char spec;
    // } format_t;

    if(format_data.width && !format_data.minus) {
        for(int j = 0; j < format_data.width - 1; j++) {
            buf[i[1]] = ' ';
            i[1]++;
        }
        buf[i[1]] = c;
    } else if(format_data.width && format_data.minus) {
        buf[i[1]] = c;
        i[1]++;
        for(int j = 0; j < format_data.width - 1; j++) {
            buf[i[1]] = ' ';
            i[1]++;
        }
        i[1]--;
    } else {
        buf[i[1]] = c;
    }

}