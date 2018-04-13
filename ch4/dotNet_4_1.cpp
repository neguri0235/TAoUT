/*
 * dotNet_3.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */


#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer4_1.h"

// Mock을 test framework을 사용하지 않고 테스트 용으로 만듬.

/*
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
*/


void Analyze_TooShortFileName_CallWebService()
{
	std::shared_ptr<MockService> mockService = std::make_shared<MockService>();
	std::shared_ptr<LogAnalyzer> logAn = std::make_shared<LogAnalyzer>(mockService);
	std::string tooShortFileName = "abc.svg";
	logAn->Analyze(tooShortFileName);
	ASSERT_STREQ("fileName length error", mockService->LastError.c_str());

	std::string tooLongFileName = "abcdefghi.svg";
	logAn->Analyze(tooLongFileName);
	ASSERT_STRNE("fileName length error", mockService->LastError.c_str());
}

class LogAnalyzerTest : public :: testing :: Test {
protected:
	std::shared_ptr<LogAnalyzer> plogAn = nullptr;
	virtual void SetUp(){
	//	plogAn = std::make_shared<LogAnalyzer>();
	}
	virtual void TearDown(){
		plogAn = nullptr;
	}
};

TEST_F(LogAnalyzerTest, mockTest) {
	Analyze_TooShortFileName_CallWebService();
}

int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!! !!" << endl; // prints !!!Hello World!!!
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
