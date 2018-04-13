/*
 * dotNet_3.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */


#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer4_2.h"

// Mock을 test framework을 사용하지 않고 테스트 용으로 만듬.
// Mock과 stub를 두개 사용하려고 하면,

class LogAnalyzerTest : public :: testing :: Test {
protected:
	std::shared_ptr<LogAnalyzer> plogAn = nullptr;
	virtual void SetUp(){
		//plogAn = std::make_shared<LogAnalyzer>();
	}
	virtual void TearDown(){
		plogAn = nullptr;
	}
};


void Analyze_WebServiceOrSendEmail()
{
	std::shared_ptr<LogAnalyzer> plogAn = std::make_shared<LogAnalyzer>();
	std::shared_ptr<StubService> stubService = std::make_shared<StubService>();
	stubService->LogError("throw");

	std::shared_ptr<MockEmailServcie> emailService = std::make_shared<MockEmailServcie>();
	plogAn->setWebService(stubService);
	plogAn->setEmail(emailService);

	std::string tooShortFileName = "abcdefgh.svg";
	plogAn->Analyze(tooShortFileName);
	ASSERT_STREQ("mock",emailService->To.c_str());
	ASSERT_STREQ("fileName",emailService->Subject.c_str());
	ASSERT_STREQ("Name Good",emailService->Body.c_str());
}

TEST_F(LogAnalyzerTest, mockTest) {
	Analyze_WebServiceOrSendEmail();
}

int main(int argc, char* argv[]) {
	std::cout << "!!!Hello World!!! !!" << std::endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
