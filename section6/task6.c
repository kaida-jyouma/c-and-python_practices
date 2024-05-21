#include <stdio.h>

int main(void){
	printf("continue until you input odd number 5 times\n");

	int ct = 0;
	int x = 0;
	printf("input number:");
	scanf(" %d ", &x);
	while (ct < 5){
		if (x % 2 == 1){
			ct ++;
			printf("%d time(s) left...\n", 5 - ct);
		}else{
			ct = 0;
			printf("it's an even number...\n");
		}
		printf("input number:");
		scanf(" %d ", &x);
	}
	printf("complete\n");
}
