#include "libmx.h"

char *mx_itoa(int number){
    int num_length = 0;
    int num_copy= number;

    while (num_copy != 0){
        if (num_copy < 0){
	    num_length++;
	    num_copy *= -1;
	}

	num_length ++;
	num_copy /= 10;

    }
    if (number == 0){
        num_length = 1;
    }
    char *a = mx_strnew(num_length);

    if (number == 0){
        a[0] = 48;
    }

    for (int i = num_length; number != 0; i--){
        if (number < 0){
	    a[0] = 45;
	    number *= -1;
	}
	
	a[i - 1] = (number % 10) + 48;
	number /= 10;
    }

    return a;
}
