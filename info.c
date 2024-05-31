#include <stdio.h>

int main(){
	// q1
	double a = 5;
	double b = 3;
	printf("%lf\n", a + b);
	printf("%lf\n", a - b);
	printf("%lf\n", a * b);
	printf("%lf\n", a / b);

	// q2
	int s = 0;
	for (int i=0;i<100;i++){
		s += i + 1;
	}
	printf("%d\n", s);

	// q3
	for (int i=0;i<100;i++){
		if ((i + 1) % 3 == 0){
			printf("%d\n", (i + 1));
		}
	}

	// q4
	for (int i=0;i<100;i++){
		if ((i + 1) % 4 == 0){
			printf("%d\n", (i + 1));
		}
	}

	// q5
	for (int i=0;i<100;i++){
		if ((i + 1) % 12 == 0){
			printf("%d\n", (i + 1));
		}
	}
}
