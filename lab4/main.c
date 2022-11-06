#include <stdio.h>
#include <string.h>

void revstr(char *str1)  {
    int i, len, temp;  
    len = strlen(str1);
    for (i = 0; i < len/2; i++) {  
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			printf("%s",param);
		} else if ((format_string[i] == '#') && (format_string[i+1] == 'g')) {
			i++;
			int strIterator = 0;
			int isParamValidNumber = 1;

			while (strIterator < strlen(param)) {
				if (!isdigit(param[strIterator])) {
					isParamValidNumber = 0;
					break;
				}
				putchar(param[strIterator]);
				strIterator++;
			}

			if (isParamValidNumber) {
				revstr(param);
				atoi(param);
				printf("%d", param);
			} else {
				return 0;
			}
		} else
			putchar(format_string[i]);
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
