#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void revstr(char *str1)  {
    int i = 0;
	int len = strlen(str1);
	int temp;  
    while (i < len/2)  {  
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
		i++;
    }
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			printf("%s",param);
		} else if ((format_string[i] == '#') && (format_string[i+1] == 'g')) {
			int isParamValidNumber = 1;
			int strIterator = 0;
			i++;
			while (strIterator < strlen(param)) {
				if (!isdigit(param[strIterator])) {
					isParamValidNumber = 0;
					break;
				}

				strIterator++;
			}
			if (!isParamValidNumber) {
				puts("");
				return 0;
			}
			revstr(param);
			printf("%d", atoi(param));
		} else if ((format_string[i] == '#') && (format_string[i + 1] == 'X') && (format_string[i + 2] == 'g')) {
			int isParamValidNumber = 1;
			int strIterator = 0;
			i++;
			while (strIterator < strlen(param)) {
				if (!isdigit(param[strIterator])) {
					isParamValidNumber = 0;
					break;
				}
				if (param[strIterator] == '0') {
					param[strIterator] = '9';
				}
				else if (param[strIterator] == '1')
				{
					param[strIterator] = '0';
				}
				else if (param[strIterator] == '2')
				{
					param[strIterator] = '1';
				}
				else if (param[strIterator] == '3')
				{
					param[strIterator] = '2';
				}
				else if (param[strIterator] == '4')
				{
					param[strIterator] = '3';
				}
				else if (param[strIterator] == '5')
				{
					param[strIterator] = '0';
				}
				else if (param[strIterator] == '5')
				{
					param[strIterator] = '0';
				}
				else if (param[strIterator] == '5')
				{
					param[strIterator] = '0';
				}
				else if (param[strIterator] == '5')
				{
					param[strIterator] = '0';
				}
				else if (param[strIterator] == '5')
				{
					param[strIterator] = '0';
				}


				strIterator++;
			}
			if (!isParamValidNumber) {
				puts("");
				return 0;
			}
			printf("%d", atoi(param));
		} else {
			putchar(format_string[i]);
		}
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}

