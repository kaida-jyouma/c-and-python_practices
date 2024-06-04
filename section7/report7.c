#include <stdio.h>
#include <math.h>

// return same "DAY" date in AD1
double sameDayInAd1(double dateNum){
	// dateNum = yyyymmdd
	int bc = 0;
	if (dateNum < 1) bc = 1;
	dateNum = fabs(dateNum);
	double year = (dateNum - (int)dateNum % 10000) / 10000;
	double month = ((dateNum - year * 10000) - (int)(dateNum - year * 10000) % 100) / 100;
	double date = (int)dateNum % 100;
	// printf("%lf\n", dateNum); // debug
	
	if (year > 1 && bc == 0){
		// AD XXXX
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
		}else if (year == 4 && month > 2){
			if (date < 6){
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date + 2);
			}else{
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date - 5);
			}
		}else{
			if (date < 7){
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date + 1);
			}else{
				return sameDayInAd1(((int)(year - 1) % 400) * 10000 + month * 100 + date - 6);
			}
		}

	}else if (bc == 1){
		// BC XXXX -> throw away
		return sameDayInAd1(dateNum);
	}else{
		// AD1
		// printf("comp\n"); // debug
		return year * 10000 + month * 100 + date;
	}
}

int checkDayInAd1(double dateNumAd1){
	
	// dateNumAd1 = 1mmdd
	
	// printf("%lf\n", dateNumAd1); // debug
	int date = ((int)dateNumAd1 - 10000) % 100;
	int month = ((int)dateNumAd1 - 10000 - date) / 100;
	// printf("%d %d\n", month, date); // debug

	int past = 0;
	if (month == 1){
		past += date;
	}else if (month == 2){
		past += 31 + date;
	}else if (month == 3){
		past += 31 + 28 + date;
	}else if (month == 4){
		past += 31 + 28 + 31 + date;
	}else if (month == 5){
		past += 31 + 28 + 31 + 30 + date;
	}else if (month == 6){
		past += 31 + 28 + 31 + 30 + 31 + date;
	}else if (month == 7){
		past += 31 + 28 + 31 + 30 + 31 + 30 + date;
	}else if (month == 8){
		past += 31 + 28 + 31 + 30 + 31 + 30 + 31 + date;
	}else if (month == 9){
		past += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + date;
	}else if (month == 10){
		past += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + date;
	}else if (month == 11){
		past += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + date;
	}else if (month == 12){
		past += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + date;
	}else{
		past += 730;
	}
	
	// printf("%d\n", past); // debug

	// 0: Sun, 1: Mon, 2: Tue, 3: Wed, 4: Thu, 5: Fri, 6: Sat
	return past % 7;
}


int main(){
	double year = 2024;
	double month = 5;
	double date = 29;
	int y, m, d;
	printf("input yyyy mm dd: ");
	scanf("%d %d %d", &y, &m, &d);

	year = (double)y;
	month = (double)m;
	date = (double)d;
	
	// printf("%lf %lf %lf\n", year, month, date); // debug
	
	double dateNum = year * 10000 + month * 100 + date;
	
	// printf("%lf\n", sameDayInAd1(dateNum)); // debug
	
	int day = checkDayInAd1(sameDayInAd1(dateNum));
	
	if (day == 0){
		printf("Sunday\n");
	}else if (day == 1){
		printf("Monday\n");
	}else if (day == 2){
		printf("Tuesday\n");
	}else if (day == 3){
		printf("Wednesday\n");
	}else if (day == 4){
		printf("Thursday\n");
	}else if (day == 5){
		printf("Friday\n");
	}else if (day == 6){
		printf("Saturday\n");
	}
}
