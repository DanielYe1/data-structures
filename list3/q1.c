#include <stdio.h>
#include <stdlib.h>

void shift_troca_string(char *str){
	int i = 0;
	while(str[i] != '\0'){
		if(str[i]>=65 && str[i] <= 90){
			str[i]=(int) str[i]+33;

		}else if(str[i]>=97 && str[i] <= 122){
			str[i]=(int) str[i]-33;

		}else{
			str[i] = 33;
		}
		i++;
	}
} 

int main(){
	char *sentence = malloc(sizeof(char)*500);
	scanf("%s",sentence);

	shift_troca_string(sentence);
	int i;
	for (i = 0; sentence[i]!= '\0'; ++i){
		printf("%c\n", sentence[i]);	
	}
	

	free(sentence);
	return 0;
}