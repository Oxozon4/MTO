#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char answers_line[1024],output_line[1024],cmd_line[1024];
	FILE *answers,*output;
	int ans=0,total=0;
	if(argc < 2){
		puts("No app specified as parameter!");
		exit(-1);
	}
	sprintf(cmd_line,"%s < input.txt > output.txt",argv[1]);
	system(cmd_line);
	answers=fopen("answers.txt","r");
	output=fopen("output.txt","r");
	if(answers && output){
		while(fgets(answers_line,1024,answers) && fgets(output_line,1024,output)){
			if(!strcmp(answers_line,output_line)){
				ans++;
			}
			total++;
		}
		fclose(answers);
		fclose(output);
	}
	printf("%d/%d\n",ans,total);
	return 0;
}
