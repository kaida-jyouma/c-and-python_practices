#include <stdio.h>

int main(){
	printf("continue until you input odd number 5 times");
	int ct = 0;
	while (ct < 5){
		int x;
		scanf("input number: %d", &x);
		if (x % 2 == 1){
			ct ++;
			printf("%d time(s) left...", 5 - ct);
		}else{
			ct = 0;
			printf("it's an even number...");
		}
	}
	printf("complete");
}