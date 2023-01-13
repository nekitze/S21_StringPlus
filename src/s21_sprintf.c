#include "s21_string.h"

int s21_sprintf(char *buf, const char *format, ...) {

    // Specs: %c d i f s u
    // Flags: - + space
    // Width: (number)
    // prec: .(number)
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

    format_t params;

    params.minus = 0;
    params.plus = 0;
    params.space = 0;
    params.zero = 0;
    params.length = ' ';
    params.width = 0;
    params.isprec = 0;
    params.prec = 0;
    params.spec = '\0';

    for(; i[0] < (int)strlen(format) && strchr("cdifsugGeExXonp", format[i[0]]) == NULL; i[0]++) { //replace_with_s21
        
        switch(format[i[0]]) {
            case '0':
                if(!params.isprec && !params.zero) {
                    params.zero = 1;
                }
                break;
            case '+':
                params.plus = 1;
                break;
            case '-':
                params.minus = 1;
                break;
            case ' ':
                params.space = 1;
                break;
            case 'l':
                params.length = 'l';
                break;
            case 'h':
                params.length = 'h';
                break;
            case 'L':
                params.length = 'L';
                break;
            case '.':
                params.isprec = 1;
                break;
        }

        if(params.isprec && (format[i[0]] > 47 && format[i[0]] < 58)) {

            params.prec = params.width * 10 + format[i[0]] - 48;

        } else if(format[i[0]] > 47 && format[i[0]] < 58) {

            params.width = params.width * 10 + format[i[0]] - 48;

        }
    }
    
    params.spec = format[i[0]];

    format_and_buff(i, buf, p_args, params);

}

void format_and_buff(int *i, char *buf, va_list p_args, format_t params) {

    // %[flags][width][.prec][length]specifier

    switch(params.spec) {
        case 'c':
            c_to_buf(va_arg(p_args, int), params, buf, i);
            break;
        case 'd':
            if(params.length == 'l') d_to_buf(va_arg(p_args, long int), params, buf, i);
            else d_to_buf(va_arg(p_args, int), params, buf, i);
            break;
        case 'i':
            d_to_buf(va_arg(p_args, int), params, buf, i);
            break;
        case 'f':
            break;
        case 's':
            break;
        case 'u':
            break;
        case 'g':
            break;
        case 'G':
            break;
        case 'e':
            break;
        case 'E':
            break;
        case 'x':
            break;
        case 'X':
            break;
        case 'n':
            break;
        case 'o':
            break;
        case 'p':
            break;
    }

}

void c_to_buf(const char c, format_t params, char *buf, int *i) {

    if(params.width && !params.minus) {
        for(int j = 0; j < params.width - 1; j++) {
            buf[i[1]] = ' ';
            i[1]++;
        }
        buf[i[1]] = c;
    } else if(params.width && params.minus) {
        buf[i[1]] = c;
        i[1]++;
        for(int j = 0; j < params.width - 1; j++) {
            buf[i[1]] = ' ';
            i[1]++;
        }
        i[1]--;
    } else {
        buf[i[1]] = c;
    }

}

void d_to_buf(int64_t d, format_t params, char *buf, int *i) {

    int m = 0;

    if(d < 0 && d != 0) {
        d = -d;
        m = 1;
    }

    char temp[BUFF_SIZE] = {'\0'};
    int j = 0;

    if (d == 0) {
        temp[0] = '0';
        j++;
    }
    else {
        while(d != 0) {
            temp[j] = d%10 + 48;
            j++;
            d /= 10;
        }
    }

    if(params.space && !m) temp[j] = ' ';
    if(m) temp[j] = '-';

    format_flag(temp, params, buf, i);

}

void format_flag(char *temp, format_t params, char *buf, int *i) {

    if(params.width && params.minus) {

        for(int j = 0; j < (int)strlen(temp); j++) { //replace_with_s21
            if(params.prec && params.prec == j + 1) break;
            buf[i[1]++] = temp[strlen(temp) - 1 - j]; //replace_with_s21
        }

        for(int j = 0; j < params.width - (int)strlen(temp); j++) { //replace_with_s21
            buf[i[1]++] = ' ';
        }
        
        i[1]--;

    } else if (params.width && !params.minus) {
        
        for(int j = 0; j < params.width - (int)strlen(temp); j++) { //replace_with_s21
            buf[i[1]++] = ' ';
        }
        for(int j = 0; j < (int)strlen(temp); j++) { //replace_with_s21
            if(params.prec && params.prec == j + 1) break;
            buf[i[1]++] = temp[strlen(temp) - 1 - j]; //replace_with_s21
        }
        i[1]--;
    } else {
        for(int j = 0; j < (int)strlen(temp); j++) { //replace_with_s21
            buf[i[1]++] = temp[strlen(temp) - 1 - j]; //replace_with_s21
        }
        i[1]--;
    }

}