/*
 * LogAnalyzer.h
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */

#ifndef LOGANALYZER_LOGANALYZER3_H_
#define LOGANALYZER_LOGANALYZER3_H_

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class FileName
{
public:
	bool EndsWith(string& fn, string&& ends) {

		auto it = fn.end();
		auto a1 = it-3; auto a2 = it-2; auto a3 = it-1;

		if(*a1 == ends[1] && *a2 == ends[2] && *a3 == ends[3]) {
			return true;
		}else{
			return false;
		}
	}
};

FileName fileName;


class IWebService {
public:
	virtual void LogError(std::string&& message) = 0;
};

class MockService : public IWebService {
public:
	std::string LastError;
	void LogError(std::string&& message) {
		LastError = message;
	}
};


class LogAnalyzer {
protected:
	std::shared_ptr<IWebService> service;
public:
	LogAnalyzer(std::shared_ptr<IWebService> svc) {
		this->service = svc;
	}

	void Analyze(std::string& fileName) {
		if(fileName.length() < 8) {
			service->LogError("fileName length error");
		}else{
			service->LogError("fileName length ok");
		}
	}
};

#endif /* LOGANALYZER_LOGANALYZER3_H_ */
