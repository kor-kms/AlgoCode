#include <string>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	if (a == 2 || a == 8) {//mon
		if (b % 7 == 5) {
			answer = "FRI";
		}
		else if (b % 7 == 6) {
			answer = "SAT";
		}
		else if (b % 7 == 0) {
			answer = "SUN";
		}
		else if (b % 7 == 1) {
			answer = "MON";
		}
		else if (b % 7 == 2) {
			answer = "TUE";
		}
		else if (b % 7 == 3) {
			answer = "WED";
		}
		else if (b % 7 == 4) {
			answer = "THU";
		}
	}
	else if (a == 3 || a == 11) {//tue
		if (b % 7 == 4) {
			answer = "FRI";
		}
		else if (b % 7 == 5) {
			answer = "SAT";
		}
		else if (b % 7 == 6) {
			answer = "SUN";
		}
		else if (b % 7 == 0) {
			answer = "MON";
		}
		else if (b % 7 == 1) {
			answer = "TUE";
		}
		else if (b % 7 == 2) {
			answer = "WED";
		}
		else if (b % 7 == 3) {
			answer = "THU";
		}
	}
	else if (a == 6) {//wed
		if (b % 7 == 3) {
			answer = "FRI";
		}
		else if (b % 7 == 4) {
			answer = "SAT";
		}
		else if (b % 7 == 5) {
			answer = "SUN";
		}
		else if (b % 7 == 6) {
			answer = "MON";
		}
		else if (b % 7 == 0) {
			answer = "TUE";
		}
		else if (b % 7 == 1) {
			answer = "WED";
		}
		else if (b % 7 == 2) {
			answer = "THU";
		}
	}
	else if (a == 9 || a == 12) {//thu
		if (b % 7 == 2) {
			answer = "FRI";
		}
		else if (b % 7 == 3) {
			answer = "SAT";
		}
		else if (b % 7 == 4) {
			answer = "SUN";
		}
		else if (b % 7 == 5) {
			answer = "MON";
		}
		else if (b % 7 == 6) {
			answer = "TUE";
		}
		else if (b % 7 == 0) {
			answer = "WED";
		}
		else if (b % 7 == 1) {
			answer = "THU";
		}
	}
	else if (a == 1 || a == 4 || a == 7) {//fri
		if (b % 7 == 1) {
			answer = "FRI";
		}
		else if (b % 7 == 2) {
			answer = "SAT";
		}
		else if (b % 7 == 3) {
			answer = "SUN";
		}
		else if (b % 7 == 4) {
			answer = "MON";
		}
		else if (b % 7 == 5) {
			answer = "TUE";
		}
		else if (b % 7 == 6) {
			answer = "WED";
		}
		else if (b % 7 == 0) {
			answer = "THU";
		}
	}
	else if (a == 10) {//sat
		if (b % 7 == 0) {
			answer = "FRI";
		}
		else if (b % 7 == 1) {
			answer = "SAT";
		}
		else if (b % 7 == 2) {
			answer = "SUN";
		}
		else if (b % 7 == 3) {
			answer = "MON";
		}
		else if (b % 7 == 4) {
			answer = "TUE";
		}
		else if (b % 7 == 5) {
			answer = "WED";
		}
		else if (b % 7 == 6) {
			answer = "THU";
		}
	}
	else if (a == 5) {//sun
		if (b % 7 == 6) {
			answer = "FRI";
		}
		else if (b % 7 == 0) {
			answer = "SAT";
		}
		else if (b % 7 == 1) {
			answer = "SUN";
		}
		else if (b % 7 == 2) {
			answer = "MON";
		}
		else if (b % 7 == 3) {
			answer = "TUE";
		}
		else if (b % 7 == 4) {
			answer = "WED";
		}
		else if (b % 7 == 5) {
			answer = "THU";
		}
	}

	return answer;
}