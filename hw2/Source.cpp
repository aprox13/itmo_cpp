#include<iostream>
#include"Report.h"

int main() {
	float marks[] = { 5, 4, 3, 2, 1 };
	Report report;
	report.readInfo(10240, "IVAN", marks);
	report.displayInfo();
	report.readInfo(0100, "IVAN", marks);
	report.displayInfo();
	system("pause");
	return 0;
}