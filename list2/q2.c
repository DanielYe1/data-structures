#include <stdio.h>

int main(){
 	char sentence1[1000];
 	char sentence2[1000];
 	int i;

 	scanf("%s",sentence1);
 	scanf("%s",sentence2);
 	
 	int num1[10] = {0};
 	int num2[10] = {0};

 	for (i = 0; sentence1[i] != '\0'; ++i){
 		num1[(int)sentence1[i] - 48]+=1;
 	}

 	for (i = 0; sentence2[i] != '\0'; ++i){
		num2[(int)sentence2[i] - 48]+=1;
 	}

 	int valid = 1;
 	for (i = 0; i < 10; ++i)
 	{
 		if(num1[i]!=num2[i]){
 			valid = 0;
 			break;
 		}
 	}

 	if(valid){
 		printf("valido\n");
 	}else{
 		printf("invalido\n");
	}
    
    return 0;
}