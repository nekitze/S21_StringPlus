#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *str_copy = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_copy[i] = (str[i] - 'A') + 'a';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_to_upper(const char *str) {
  char *str_copy = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_copy[i] = (str[i] - 'a') + 'A';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *new_str = NULL;
  if (src && str) {
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);
    size_t new_len = src_len + str_len;
    if (start_index <= new_len) {
      new_str = malloc((new_len + 1) * sizeof(char));
      if (str == NULL && start_index == 0) {
        s21_strcpy(new_str, src);
      } else {
        for (size_t i = 0, m = 0, n = 0; i < new_len; i++) {
          if (i < start_index || i >= start_index + str_len) {
            new_str[i] = src[n];
            n++;
          } else {
            new_str[i] = str[m];
            m++;
          }
        }
      }
      new_str[new_len] = '\0';
    }
  } else if (str) {
    if ((int)s21_strlen(str) > 0) {
      new_str = malloc(s21_strlen(str) * sizeof(char));
      s21_strcpy(new_str, str);
    }
  }
  return new_str;
}

int find_ind(const char *src, const char *trim_chars, int index) {
  index -= 1;
  int res = 0;
  int len = s21_strlen(trim_chars);
  for (int i = 0; i < len; i++) {
    if (src[index] == trim_chars[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      int left = 1, len = s21_strlen(src), right = len;
      while (find_ind(src, trim_chars, left)) left++;
      if (left != right) {
        while (find_ind(src, trim_chars, right)) right--;
      }
      int new_len = right - left;
      new_str = malloc(sizeof(char) * new_len + 1);
      if (new_str) {
        for (int i = left - 1, j = 0; i <= right; i++, j++) {
          new_str[j] = src[i];
        }
        new_str[new_len + 1] = '\0';
      } else {
        new_str = "";
      }
    } else {
      new_str = s21_trim(src, "\t\n");
    }
  }
  return new_str;
}
