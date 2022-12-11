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
		} else if ((format_string[i] == '#') && isdigit(format_string[i + 1])) {
			int kCharIndex = 0;
			for (int numberParamIterator = i + 2; numberParamIterator < strlen(format_string); numberParamIterator++){
				if (format_string[numberParamIterator] == 'g'){
					kCharIndex = numberParamIterator;
				} else if (!isdigit(format_string[numberParamIterator])) {
					break;
				}
			}
			if (kCharIndex == 0) {
				putchar(format_string[i]);
				return 0;
			}
			
			char numberArray[kCharIndex + 1];
			strncpy(numberArray, &format_string[i + 2], kCharIndex);
			numberArray[kCharIndex] = '\0';
			int number = atoi(numberArray);
			int stringLength = strlen(param);
			if (number > stringLength) {
				int paddedZeros = number - stringLength;
				while (paddedZeros > 0) {
					putchar('0');
					paddedZeros--;
				}
			}

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
				} else if (param[strIterator] == '1') {
					param[strIterator] = '0';
				} else if (param[strIterator] == '2') {
					param[strIterator] = '1';
				} else if (param[strIterator] == '3') {
					param[strIterator] = '2';
				} else if (param[strIterator] == '4') {
					param[strIterator] = '3';
				} else if (param[strIterator] == '5') {
					param[strIterator] = '4';
				} else if (param[strIterator] == '6') {
					param[strIterator] = '5';
				} else if (param[strIterator] == '7') {
					param[strIterator] = '6';
				} else if (param[strIterator] == '8') {
					param[strIterator] = '7';
				} else if (param[strIterator] == '9') {
					param[strIterator] = '8';
				}
				strIterator++;
			}
			// check for only number
			if (!isParamValidNumber) {
				puts("");
				return 0;
			}
			printf("%d", atoi(param));
		} else if ((format_string[i] == '#') && (format_string[i + 1] == '.') && isdigit(format_string[i + 1])) {
			// #.Xg (%Xd)
			int kCharIndex = 0;
			for (int numberParamIterator = i + 2; numberParamIterator < strlen(format_string); numberParamIterator++) {
				if (format_string[numberParamIterator] == 'g') {
					kCharIndex = numberParamIterator;
				} else if (!isdigit(format_string[numberParamIterator])) {
					break;
				}
			}
			if (kCharIndex == 0) {
				putchar(format_string[i]);
				return 0;
			}
			char numberArray[kCharIndex + 1];
			strncpy(numberArray, &format_string[i + 2], kCharIndex);
			numberArray[kCharIndex] = '\0';
			int number = atoi(numberArray);
			int strIterator = 0;
			int isParamValidNumber = 1;
			int stringLength = strlen(param);
			if (number > stringLength) {
				int paddedZeros = number - stringLength;
				while (paddedZeros > 0) {
					putchar('9');
					paddedZeros--;
				}
			}
			while (strIterator < strlen(param)) {
				if (!isdigit(param[strIterator])) {
					isParamValidNumber = 0;
					break;
				}
				if (param[strIterator] == '0') {
					param[strIterator] = '9';
				} else if (param[strIterator] == '1') {
					param[strIterator] = '0';
				} else if (param[strIterator] == '2') {
					param[strIterator] = '9';
				} else if (param[strIterator] == '3') {
					param[strIterator] = '8';
				} else if (param[strIterator] == '4') {
					param[strIterator] = '7';
				} else if (param[strIterator] == '5') {
					param[strIterator] = '6';
				} else if (param[strIterator] == '6') {
					param[strIterator] = '5';
				} else if (param[strIterator] == '7') {
					param[strIterator] = '4';
				} else if (param[strIterator] == '8') {
					param[strIterator] = '3';
				} else if (param[strIterator] == '9') {
					param[strIterator] = '2';
				}
				strIterator++;
			}
			// check for only number
			if (!isParamValidNumber) {
				puts("");
				return 0;
			}
			printf("%d", atoi(param));
			i += kCharIndex;
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

