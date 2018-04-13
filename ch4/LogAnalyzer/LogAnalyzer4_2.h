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

//using namespace std;

class FileName
{
public:
	bool EndsWith(std::string& fn, std::string&& ends) {

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

class IEmailService {
public:
	virtual void SendEmail(std::string&& to, std::string&& object, std::string&& body) = 0;
};




class MockService : public IWebService {
public:
	std::string LastError;
	void LogError(std::string&& message) {
		LastError = message;
	}
};

class MockEmailServcie : public IEmailService {
public:
	std::string To;
	std::string Subject;
	std::string Body;

	void SendEmail(std::string&& to, std::string&& object, std::string&& body) {
		To = to, Subject = object, Body = body;
	}
};


class StubService : public IWebService {
public:
	int errorCode = 0 ;
	void LogError(std::string&& message) {
		if(message == "throw")
			errorCode = 99;
	}
};


class LogAnalyzer {
protected:
	std::shared_ptr<IWebService> service = nullptr;
	std::shared_ptr<IEmailService> email = nullptr;
public:
	LogAnalyzer() {

	}

	void setWebService(std::shared_ptr<IWebService> _service) {
		service = _service;
	}

	void setEmail(std::shared_ptr<IEmailService> _email) {
		email = _email;
	}


	void Analyze(std::string& fileName) {
		if(fileName.length() < 8) {
			service->LogError("fileName length error");
		}else{
			email->SendEmail("mock","fileName","Name Good");
		}
	}
};

#endif /* LOGANALYZER_LOGANALYZER3_H_ */
