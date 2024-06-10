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



// 9task22 ..... Under Construcion

// copy from 8task22 and rewrite in C language

int main(){

	// Sieve of Eratosthenes
	int mxm = 10000;
	int sq_f = floor(sqrt(mxm));
	int nonprimes[mxm] = {0};
	primeFlags[0] = 1; // 1 is not prime number
	for (i=0;i<10000;i++){
		if (primeFlags[i] == 0){
			// primeFlag == 0 -> the number cannot divide any number other than 1
			for (int j=i+1;j<)
		}else{ 
			// primeFlag == 1 -> divisible by some numbers other than 1
			continue;
		}
	}
}
