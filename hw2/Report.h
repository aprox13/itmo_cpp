#pragma once


class Report {
public:
	Report();
	void readInfo(int admissionNumber, const char* name, const float* marks);
	void displayInfo() const;

private:
	static const int MIN_ADNO = 0;
	static const int MAX_ADNO = 9999;
	static const int NAME_LEN = 20;
	static const int MARKS_LEN = 5;
	static const int MAX_ADNO_LEN = 4;


	int   mAdmissionNumber;
	int   mAdmissionNumberArray[MAX_ADNO_LEN];
	char  mName[NAME_LEN];
	float mMarks[MARKS_LEN];
	float mAverage;
	bool  mErrorOccurred;

	void  getAverage();

};