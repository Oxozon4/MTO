#include <stdio.h>
#include <ctype.h>
#include <string.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			int strIterator = 0;
			while (strIterator < strlen(param) || j < ) {
				if (islower(param[strIterator])) {
					param[strIterator] = toupper(param[strIterator]);
				} 
				else if (isupper(param[strIterator])) {
					param[strIterator] = tolower(param[strIterator]);
				}
				putchar(param[strIterator]);
				strIterator++;
			}
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
