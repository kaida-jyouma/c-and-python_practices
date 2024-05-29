#include <stdio.h>

double sameDayInAd1(double dateNum){
	// date, target = yyyymmdd
	double year = (dateNum - (int)dateNum % 10000) / 10000;
	double month = ((dateNum - year * 10000) - (int)(dateNum - year * 10000) % 100) / 100;
	double date = (int)dateNum % 100;
	// double tyear = (target - target % 10000) / 10000;
	// double tmonth = ((target - tyear * 10000) - (dateNum - year * 10000) % 100) / 100;
	// double tdate = target % 100;
	printf("%lf\n", dateNum);
	if (year > 1){
		if (year > 400){
			return sameDayInAd1(((int)(year - 400) % 400) * 10000 + month * 100 + date);
		}else if (year > 100){
			if (date < 3){
				return sameDayInAd1(((int)(year - 100) % 400) * 10000 + month * 100 + date + 5);
			}else{
				return sameDayInAd1(((int)(year - 100) % 400) * 10000 + month * 100 + date - 2);
			}
		}else if (year > 4){
			if (date < 3){
				return sameDayInAd1(((int)(year - 4) % 400) * 10000 + month * 100 + date + 5);
			}else{
				return sameDayInAd1(((int)(year - 4) % 400) * 10000 + month * 100 + date - 2);
			}
		}else{
			if (date < 7){
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date + 1);
			}else{
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date - 6);
			}
		}
	}else if (year < 1){
		return year * 10000 + month * 100 + date;
	}else{
	    printf("comp\n");
		return year * 10000 + month * 100 + date;
	}
}



int main(){
	double year = 2024;
	double month = 5;
	double date = 29;
	int y, m, d;
	printf("input yyyy mm dd:");
	scanf("%d %d %d", &y, &m, &d);
	year = (double)y;
	month = (double)m;
	date = (double)d;
	printf("%lf %lf %lf\n", year, month, date);
	double dateNum = year * 10000 + month * 100 + date;
	printf("%lf\n", sameDayInAd1(dateNum));
}
