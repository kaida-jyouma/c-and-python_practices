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
			return sameDayInAd1(((year - 400) % 400) * 10000 + month * 100 + date);
		}else if (year > 100){
			if (date < 3){
				return sameDayInAd1(((year - 100) % 400) * 10000 + month * 100 + date + 5);
			}else{
				return sameDayInAd1(((year - 100) % 400) * 10000 + month * 100 + date - 2);
			}
		}else if (year > 4){
			if (date < 3){
				return sameDayInAd1(((year - 4) % 400) * 10000 + month * 100 + date + 5);
			}else{
				return sameDayInAd1(((year - 4) % 400) * 10000 + month * 100 + date - 2);
			}
		}else{
			if (date < 7){
				return sameDayInAd1(((year - 1) % 400) * 10000 + month * 100 + date + 1);
			}else{
				return sameDayInAd1(((year - 1) % 400) * 10000 + month * 100 + date - 6);
			}
	}else if (year < 1){

	}else{
		return year * 10000 + month * 100 + date;
	}
}



int main(){
	double year = 0;
	double month = 0;
	double date = 0;
	scanf("%lf %lf %lf\n", year, month, date);
	printf("%lf %lf %lf\n", year, month, date);
	double dateNum = year * 10000 + month * 100 + date;
	printf("%lf\n", sameDayInAd1(dateNum));
}
