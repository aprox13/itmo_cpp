#include "Program.h"
#include "SimpleAlgo.h"
#include "ChairMetric.h"
#include "EvklidMetric.h"
#include<fstream>

void Program::assertProgram(const std::string& message) {
	std::cout << "Assert: " << message << std::endl;
	mWasAssert = true;
}

void Program::setAlgo(const std::string & name)
{
	if (name == "simple") {
		mAlgorithm = new SimpleAlgo();
	}
	else {
		assertProgram("Unknow algorithm name: " + name);
	}
}

void Program::setMetric(const std::string & name)
{
	if (name == "chair") {
		mMetric = new ChairMetric;
	}
	else if(name == "ev"){
		mMetric = new EvklidMetric;
	}
	else {
		assertProgram("Unknow metric name: " + name);
	}
}

void Program::setK(const std::string & val)
{
	for (char c : val) {
		if (c < '0' || c > '9') {
			assertProgram("Invalid character at K: " + c);
		}
	}
	std::string::size_type sz;
	mK = std::stoi(val, &sz);
}

void Program::setSource(const std::string & name)
{
	mSource = name;
}

void Program::read()
{
	std::ifstream in(mSource);
	int n;
	in >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		in >> x >> y;
		mPoints.emplace_back(x, y);
	}
	in.close();
}

Program::Program(const std::vector<std::pair<std::string, std::string>>& args) {
	mWasAssert = false;

	mAlgorithm = new SimpleAlgo;
	mMetric = new ChairMetric;
	mSource = "input.txt";
	mK = DEFAULT_K;

	for (auto arg : args) {
		auto name = arg.first;
		if (name == mAlgorithmName) {
			setAlgo(arg.second);
		}
		else if (name == mKArgName) {
			setK(arg.second);
		}
		else if (name == mMetricName) {
			setMetric(arg.second);
		}
		else if (name == mSourceFileName) {
			setSource(arg.second);
		}
		else {
			assertProgram("Unknown argument name " + name);
		}
		if (mWasAssert) {
			break;
		}

	}
	if (!mWasAssert)
	{
		std::cout << "Created program with\nAlgorithm: " << mAlgorithm->getName()
			<< "\nMetric: " << mMetric->getName()
			<< "\nMax points at path: " << mK
			<< "\nSource file: " << mSource << "\n";
		read();
		std::cout << "With " << mPoints.size() << " points\n";
	}
	else {
		std::cout << "Program build failed\n";
	}
}

std::vector<Path> Program::getResult()
{
	if (mWasAssert) {
		std::cout << "Wrong program inizialization\n";
		return std::vector<Path>();
	}
	return mAlgorithm->getPaths(mK, mPoints, *mMetric);
}

void Program::help()
{
	std::cout << "Input arguments:\n" <<
		"\t-k:\n" <<
		"\t\telements in path(default: 10)\n" <<
		"\t\ttype : size_t\n" <<
		"\t-algo :\n" <<
		"\t\tAlgorithm name(default: simple)\n" <<
		"\t\tavailable :\n" <<
		"\t\t\tsimple - SimpleAlgo class\n" <<
		"\t- metric :\n" <<
		"\t\tMetric name(default: chair)\n" <<
		"\t\tavailable :\n" <<
		"\t\t\tchair - Chair metric\n" <<
		"\t\t\tev - Evklid metric\n" <<
		"\t- source\n" <<
		"\t\tSource file path.File format :\n"
		"\t\t\tn - count of points\n" <<
		"\t\t\t2 * n numbers - x, y coordinates\n";
}
