#include <cstdio>
#include <cmath>
using namespace std;
const int MAX_CAR_NUM = 1000;
const int POS_INFINITE = 999999999.0;
double calc_time(double home_x, double home_y, 
					   double car_x, double car_y, 
					   double speed)
{
    double result = 0.0;
	double dis_x = home_x - car_x;
	double dis_y = home_y - car_y;
	double dis = sqrt(dis_x * dis_x + dis_y * dis_y);
	if (abs(speed - 0.0) > 0.0)
	{
		result = dis / speed;
	}
	else
	{
		result = POS_INFINITE;
	}
	return result;
}
int main()
{
	double home_x = 0.0, home_y = 0.0;
	int n_cars = 0;
	double x[MAX_CAR_NUM] = {0.0};
	double y[MAX_CAR_NUM] = {0.0};
	double v[MAX_CAR_NUM] = {0.0};
	scanf("%lf %lf", &home_x, &home_y);
	scanf("%d", &n_cars);
	for (int i = 0; i < n_cars; i++)
	{
		scanf("%lf %lf %lf", &x[i], &y[i], &v[i]);
	}
	//Input done

	double time = POS_INFINITE;
	double current_time = 0.0;
	for (int i = 0; i < n_cars; i++)
	{
		current_time = calc_time(home_x, home_y, x[i], y[i], v[i]);
//		printf("Num %d, Car_x %lf, Car_y %lf, Home_x %lf, Home_y %lf, Speed %lf, Time %lf\n",
//				i, x[i], y[i], home_x, home_y, v[i], current_time);
		if ( current_time < time )
		{
			time = current_time;
		}
	}
	printf("%lf\n", time);
	return 0;
}
