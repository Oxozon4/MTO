#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			int strIterator = 0;
			while (strIterator < strlen(param)) {
				if (islower(param[strIterator])) {
					param[strIterator] = toupper(param[strIterator]);
				} 
				else if (isupper(param[strIterator])) {
					param[strIterator] = tolower(param[strIterator]);
				}
				putchar(param[strIterator]);
				strIterator++;
			}
		} else if ((format_string[i] == '#') && (format_string[i+1] == '.') && (isdigit(format_string[i+2]))) {
			// #.Xk (%.Xs)
			int kCharIndex = 0;
			for (int numberParamIterator = i + 2; numberParamIterator < strlen(format_string); numberParamIterator++) {
				if (format_string[numberParamIterator] == 'k') {
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
			while (strIterator < strlen(param) && strIterator < number) {
				if (islower(param[strIterator])) {
					param[strIterator] = toupper(param[strIterator]);
				} 
				else if (isupper(param[strIterator])) {
					param[strIterator] = tolower(param[strIterator]);
				}
				putchar(param[strIterator]);
				strIterator++;
			}
			i += kCharIndex;
		} else if ((format_string[i] == '#') && (isdigit(format_string[i + 1]))) {
			// #Xk (%Xs)
			int kCharIndex = 0;
			for (int numberParamIterator = i + 2; numberParamIterator < strlen(format_string); numberParamIterator++) {
				if (format_string[numberParamIterator] == 'k') {
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
			int stringLength = strlen(param);
			while (strIterator < number) {
				if (strIterator >= stringLength) {
					putchar(' ');
				} else {
					if (islower(param[strIterator])) {
						param[strIterator] = toupper(param[strIterator]);
					} 
					else if (isupper(param[strIterator])) {
						param[strIterator] = tolower(param[strIterator]);
					}
					putchar(param[strIterator]);
				}
				strIterator++;
			}
			i += kCharIndex;
		} else {
			putchar(format_string[i]);
		}
	}
	puts("");
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
