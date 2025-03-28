#include "int_to_char.h"

char* int_to_char(int n, char* s) {
    int i = 0;

     do {
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     s[i] = '\0';
     
     int start = 0, end = i - 1;
     char tmp;
 
     while (start < end) {
         tmp = s[start];
         s[start] = s[end];
         s[end] = tmp;
         start++;
         end--;
    }

    return s;
}