#include <iostream>
#include "Report.h"

void Report::getAverage() {
	mAverage = 0;
	for (int i = 0; i < MARKS_LEN; i++) {
		mAverage += mMarks[i];
	}
	mAverage /= MARKS_LEN;
}

void Report::readInfo(int admissionNumber, const char* name, const float* marks) {
	if (admissionNumber < MIN_ADNO || admissionNumber > MAX_ADNO) {
		std::cout << "Admission number number need to be more than " << MIN_ADNO << " and less then " << MAX_ADNO << std::endl;
		mErrorOccurred = true;
		return;
	}
	else {
		mErrorOccurred = false;
		int tmpAdmissionNumber = admissionNumber;
		int i = MAX_ADNO_LEN - 1;
		while (tmpAdmissionNumber != 0)
		{
			mAdmissionNumberArray[i] = tmpAdmissionNumber % 10;
			tmpAdmissionNumber /= 10;
			i--;
		}
	}
	this->mAdmissionNumber = admissionNumber;
	std::copy(name, name + NAME_LEN, this->mName);
	std::copy(marks, marks + MARKS_LEN, this->mMarks);
	this->getAverage();
}

void Report::displayInfo() const {
	if (mErrorOccurred) {
		std::cout << "Unable to perform operation" << std::endl;
		return;
	}
	std::cout << "AdmissionNumber: ";
	for (int i = 0; i < MAX_ADNO_LEN; i++) {
		std::cout << mAdmissionNumberArray[i];
	}
	std::cout << std::endl;
	std::cout << "Name: " << mName << std::endl;
	std::cout << "Marks: ";
	for (int i = 0; i < MARKS_LEN; i++) {
		std::cout << mMarks[i] << " ";
	}
	std::cout << std::endl << "Average: " << mAverage << std::endl;
}

Report::Report() : mAdmissionNumber(0), mAverage(0), mErrorOccurred(false) {
	for (int i = 0; i < MAX_ADNO_LEN; i++) {
		mAdmissionNumberArray[i] = 0;
	}
}