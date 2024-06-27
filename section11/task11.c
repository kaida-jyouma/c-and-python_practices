#include <stdio.h>
#include <math.h>

#define PI = 3.141592653979323846264338327950288419716939937510582897494459230781

int actions_uketori(void){
	printf("Select:\n");
	printf("1. Input coefficient (Default: 0)\n");
	printf("2. Display coefficient\n");
	printf("3. transition (x axis)\n");
	printf("4. transition (y axis)\n");
	printf("5. Rotate around (0, 0)\n");
	printf("Other: Quit\n");

	int ans;
	scanf("%d", &ans);
	printf("\n");
	return ans;
}

void hyouji_curve(double B[][3]){
	if (B[0][1] != B[1][0] || B[0][2] != B[2][0] || B[1][2] != B[2][1]){
		printf("Error: Something was wrong......\n");
	}
	printf("The coefficient of x^2 is %lf\n", B[0][0]);
	printf("The coefficient of xy is %lf\n", 2 * B[0][1]);
	printf("The coefficient of y^2 is %lf\n", B[1][1]);
	printf("The coefficient of x is %lf\n", 2 * B[0][2]);
	printf("The coefficient of y is %lf\n", 2 * B[1][2]);
	printf("The constant term is %lf\n", B[2][2]);
}

void nyuuryoku_curve(double B[][3]){
	double a20, a11, a02, a10, a01, a00;
	printf("Enter the coefficients of the quadratic curve: \n");

	printf("The coefficient of x^2: \n");
	scanf("%lf", &a20);
	printf("\n");
	printf("The coefficient of xy: \n");
	scanf("%lf", &a11);
	printf("\n");
	printf("The coefficient of y^2: \n");
	scanf("%lf", &a02);
	printf("\n");
	printf("The coefficient of x: \n");
	scanf("%lf", &a10);
	printf("\n");
	printf("The coefficient of y: \n");
	scanf("%lf", &a01);
	printf("\n");
	printf("The constant term is : \n");
	scanf("%lf", &a00);
	printf("\n");
	B[0][0]=a20;
	B[1][0]=a11 / 2;
	B[0][1]=a11 / 2;
	B[1][1]=a02;
	B[2][0]=a10 / 2;
	B[0][2]=a10 / 2;
	B[1][2]=a01 / 2;
	B[2][1]=a01 / 2;
	B[2][2]=a00;
}

void henkan_B_ATBA(double B[][3], double A[][3]){
	double Bcopy[3][3];
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j+;){
			Bcopy[i][j]=B[i][j];
		}
	}
	
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			B[i][j]=0;
			for (int k=0;k<3;k++){
				for (int l=0;l<3;l++){
					B[i][j] += A[k][i] * Bcopy[k][l] * A[l][i];
				}
			}
		}
	}
}

void heikouidou_x(double B[][3]){
	printf("distance (x axis): \n");
	double Dx;
	scanf("%lf", &Dx);
	double A[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	A[0][2] = -Dx;
	henkan_B_ATBA(B, A);
}

void heikouidou_y(double B[][3]){
	printf("distance (y axis): \n");
	double Dy;
	scanf("%lf", &Dy);
	double A[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	A[1][2] = -Dy;
	henkan_B_ATBA(B, A);
}

void rotate0_0(double B[][3]){
	printf("rotate degree ( around (0,0) / 1~359 ): \n");
	double Dr;
	scanf("%lf", &Dr);
	double rad = Dr * PI / 180;
	double A[3][3] = {{cos(rad), (-1) * sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1}};
	henkan_B_ATBA(B, A);
}

int main(void){
	void (*actions[5])(double B[][3]) = {
		nyuuryoku_curve,
		hyouji_curve,
		heikouidou_x,
		heikouidou_y,
		rotate0_0
	};
	double B[3][3] =  {0};
	int ans;
	while (1){
		ans = actions_uketori();
		if (1 <= ans && ans <= 5){
			actions[ans - 1](B);
		}else{
			break;
		}
	}
	return 0;
}
