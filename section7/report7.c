#include <stdio.h>

double sameDayInAd1(double dateNum){
	// date, target = yyyymmdd
	double year = (dateNum - dateNum % 10000) / 10000;
	double month = ((dateNum - year * 10000) - (dateNum - year * 10000) % 100) / 100;
	double date = dateNum % 100;
	// double tyear = (target - target % 10000) / 10000;
	// double tmonth = ((target - tyear * 10000) - (dateNum - year * 10000) % 100) / 100;
	// double tdate = target % 100;

	if (year > 1){
		


	}else if (){

	}else{

	}
}



int main(){
	double year = 0;
	double month = 0;
	double date = 0;
	scanf("%lf %lf %lf", year, month, day);
}
