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
		if (year > 400){
			return sameDayInAd1(year * 10000 + month * 100 + date);
		}else if (year > 100){
			
		}


	}else if (year < 1){

	}else{

	}
}



int main(){
	double year = 0;
	double month = 0;
	double date = 0;
	scanf("%lf %lf %lf", year, month, day);
}
