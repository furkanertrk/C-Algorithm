#include <iostream>
#include <iomanip>
using namespace std;

void downloadtimecalculate(double a, double b);
int main()
{
	cout << "Download speed (MB/s)==>";
	double downloadspeed = 0;
	cin >> downloadspeed;
	cout << "File size (GB)==>";
	double filesize = 0;
	cin >> filesize;
	downloadtimecalculate(filesize, downloadspeed);
	return 0;
}

void downloadtimecalculate(double a, double b) {
	double sec = 0;
	a = a * 1024; //converting gb to mb
	int minute = 0,clock=0;
	sec = a / b;
		while (sec>=60) {
			minute++;
			sec -= 60;
			if (minute >= 60) {
				clock++;
				minute -= 60;
				}
			continue;
			}

		//just I want nice timer
		if (sec >= 10) {
			if (clock != 0) cout << clock << ":" << minute << ":" << fixed << setprecision(0) << sec;
			else if (clock == 0 && minute != 0) cout << minute << ":" << fixed << setprecision(0) << sec;
			else if (clock != 0 && minute == 0) cout << clock << ":" << fixed << setprecision(0) << sec;
			else cout << "Second:" << sec;
		}
		else {
			if (clock != 0) cout << clock << ":" << minute << ":" << fixed << setprecision(0) << "0" << sec;
			else if (clock == 0 && minute != 0) cout << minute << ":" << fixed << setprecision(0) << "0" << sec;
			else if (clock != 0 && minute == 0) cout << clock << ":" << fixed << setprecision(0) << "0" << sec;
			else cout << "Second:" << sec;
		}
}
