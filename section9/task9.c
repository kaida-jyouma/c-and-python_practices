#include <stdio.h>
#include <math.h>

// 9task21

#define NUMBER 200
#define kamoku_num 4

int gainedScore(int 1, int u1, int u2, int u3){
	if ((int)ceil(u1 * sin(u2 * i) + 1) % 4 == 0){
		return 90 + (int)ceil(10 * pow(sin(u3 * i), 3));
	}else if ((int)ceil(u1 * sin(u2 * i)) % 2 == 0){
		return 80 + (int)ceil(10 * pow(sin(u3 * i), 3));
	}else{
		return 70 + (int)ceil(20 * pow(sin(u3 * i), 5));
	}
}

int main(){
	
}



// 9task22 ..... Under Construcion -> Complete

// copy from 8task22 and rewrite in C language

/*

#include <stdio.h>
#include <math.h>

#define MAXIMUM 100000000

int primeFlags[MAXIMUM] = {0};

int main(){

	// Sieve of Eratosthenes
	int sq_f = floor(sqrt(MAXIMUM));
	// int primeFlags[MAXIMUM] = {0}; // -> to global variable
	primeFlags[0] = 1; // 1 is not prime number
	printf("start calculating ......\n");
	for (int i=0;i<MAXIMUM;i++){
		// progress viewer
		if (i % (MAXIMUM / 25) == 0){
			printf("%d\n", i);
		}

		// calculate system
		if (primeFlags[i] == 0){
			// primeFlags == 0 -> the number cannot divide any number other than 1
			for (int j=2*i+1;j<MAXIMUM;j+=(i+1)){
				if (primeFlags[j] == 1){
					continue;
				}
				if ((j + 1) % (i + 1) == 0){
					primeFlags[j] = 1;
				}
			}
		}else{ 
			// primeFlags == 1 -> divisible by some numbers other than 1
			continue;
		}
	}

	int primect = 0;
	int primeList[1500] = {0};
	for (int i=0;i<MAXIMUM;i++){
		if (primeFlags[i] == 0){

			// make primeList
			// primeList[primect] = i + 1; 
			
			// display primeNumber
			// printf("%d ", i + 1);
			
			primect ++;
		}
	}
	printf("end\n");
	printf("%d\n", primect);
	printf("\n");
}

*/
