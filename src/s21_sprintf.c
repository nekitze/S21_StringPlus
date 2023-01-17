#include "s21_string.h"

int s21_sprintf(char *buf, const char *format, ...) {
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

        if(params.isprec && format[i[0]] == '-') params.prec = 0;
        else if(params.isprec && format[i[0]] == '*') params.prec = va_arg(p_args, int);
        else if(params.isprec && (format[i[0]] > 47 && format[i[0]] < 58)) {

            params.prec = params.prec * 10 + format[i[0]] - 48;

        } else if(format[i[0]] > 47 && format[i[0]] < 58) {

            params.width = params.width * 10 + format[i[0]] - 48;

        } else if(format[i[0]] == '*') params.width = va_arg(p_args, int);
    }
    
    params.spec = format[i[0]];

    format_and_buff(i, buf, p_args, params);

}

void format_and_buff(int *i, char *buf, va_list p_args, format_t params) {

    // %[flags][width][.prec][length]specifier

    switch(params.spec) {
        case 'c':
            if(params.length == 'l') lc_to_buf(va_arg(p_args, wchar_t), params, buf, i);
            else if(params.length == 'h') lc_to_buf(va_arg(p_args, wint_t), params, buf, i);
            else c_to_buf(va_arg(p_args, int), params, buf, i);
            break;
        case 'd':
        case 'i':
            if(params.length == 'l') d_to_buf(va_arg(p_args, long int), params, buf, i);
            else if(params.length == 'h') d_to_buf((short) va_arg(p_args, int), params, buf, i);
            else if(params.length == 'L') d_to_buf(va_arg(p_args, long long), params, buf, i);
            else d_to_buf(va_arg(p_args, int), params, buf, i);
            break;
        case 'f':
            if(params.length == 'L') f_to_buf(va_arg(p_args, long double), params, buf, i);
            else f_to_buf(va_arg(p_args, double), params, buf, i);
            break;
        case 's':
            s_to_buf(p_args, params, buf, i);
            break;
        case 'u':
            u_to_buf(va_arg(p_args, uint64_t), params, buf, i);
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

    int len = (int)strlen(temp); //replace_with_s21

    while(len < params.prec) {
        temp[j++] = '0';
        params.prec--;
    }

    if(params.space && !m) temp[j] = ' ';
    if(params.plus && !m) temp[j] = '+';
    if(m) temp[j] = '-';

    format_flag(temp, params, buf, i, 0);

}

void format_flag(char *temp, format_t params, char *buf, int *i, int mode) {

    int base_w = (int)strlen(temp); //replace_with_s21

    if(params.width && !params.minus) {
        for(int j = 0; j < params.width - mode - base_w; j++) buf[i[1]++] = ' ';
        for(int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
        i[1]--;
    } else if(params.width && params.minus) {
        for(int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
        for(int j = 0; j < params.width - mode - base_w; j++) buf[i[1]++] = ' ';
        i[1]--;
    } else {
        for(int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
        i[1]--;
    }

}

void f_to_buf(long double f, format_t params, char *buf, int *i) {
    
    int m = 0;

    if(f < 0. && f != 0.) {
        f = -f;
        m = 1;
    }

    int count = 0;
    long double man = 0, ipartd = 0;
    long long ipart = 0;
    char temp[BUFF_SIZE] = {'\0'};

    man += modfl(f, &ipartd);
    ipart = ipartd;

    long long del = 0;

    if(params.prec) {
        del = pow(10, params.prec);
        man = roundl(man*del)/del;
    } else {
        del = pow(10, 6);
        man = roundl(man*del)/del;
    }
    
    if(!params.prec && params.isprec) man = roundl(man);
    
    int j = 0;
    if(!(!params.prec && params.isprec)) temp[j++] = '.';

    if (ipart == 0) temp[j++] = '0';

    while(ipart != 0) {
        temp[j] = (long int)ipart % 10 + '0';
        j++;
        ipart /= 10;
    }

    if(params.space && !m) temp[j] = ' ';
    if(params.plus && !m) temp[j] = '+';
    if(m) temp[j] = '-';

    if(params.spec == 'f' && !params.prec) count = 6;
    else if(params.prec) count = params.prec;

    format_flag(temp, params, buf, i, count);
    
    i[1]++;

    if(!(!params.prec && params.isprec)) {
        long long mani = man * pow(10, count) + 0.05;
        char temp1[BUFF_SIZE] = {'\0'};

        int k = 0;
        for(; k < count; k++) {
            temp1[k] = mani % 10 + '0';
            mani /= 10;
        }
        k--;
        for(; k >= 0; k--) {
            buf[i[1]++] = temp1[k];
        }
    }

    i[1]--;
    
}

void s_to_buf(va_list p_args, format_t params, char *buf, int *i) {
    int j = 0;
    char temp[BUFF_SIZE] = {'\0'};

    if(params.length == 'l') {
        const wchar_t *wstr = va_arg(p_args, wchar_t *);
        j = wcstombs(temp, wstr, BUFF_SIZE);

        if(params.width && !params.minus) {
            for(int k = 0; k < params.width - j; k++) {
                buf[i[1]++] = ' ';
            }
        }
        j = 0;
        while(temp[j] != '\0' && (!params.isprec || j < params.prec)) {
            buf[i[1]++] = temp[j++];
        }
        if(params.width && params.minus) {
            for(int k = 0; k < params.width - j; k++) {
                buf[i[1]++] = ' ';
            }
        }
        i[1]--;
    } else {
        char *str = va_arg(p_args, char *);
        j = strlen(str);
        if(params.width && !params.minus) {
            for(int k = 0; k < params.width - j; k++) {
                buf[i[1]++] = ' ';
            }
        }
        j = 0;
        while(*str != '\0' && (!params.isprec || j < params.prec)) {
            buf[i[1]++] = *str;
            str++;
            j++;
        }

        if(params.width && params.minus) {
            for(int k = 0; k < params.width - j; k++) {
                buf[i[1]++] = ' ';
            }
        }
        i[1]--;
    }
    
}

void lc_to_buf(wchar_t c1, format_t params, char *buf, int *i) {

    char c = 0;
    mbstate_t mbstate;
    wcrtomb(&c, c1, &mbstate);
    if(c != '\0'){
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
}

void u_to_buf(uint64_t d, format_t params, char *buf, int *i) {

    if(params.length == 'l') d = (uint64_t)d;
    else if(params.length == 'h') d = (uint16_t)d;
    else if(params.length == ' ') d = (uint32_t)d;

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

    int len = (int)strlen(temp); //replace_with_s21

    while(len < params.prec) {
        temp[j++] = '0';
        params.prec--;
    }

    if(params.space) temp[j] = ' ';
    if(params.plus) temp[j] = '+';

    format_flag(temp, params, buf, i, 0);

}