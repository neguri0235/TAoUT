/*
 * dotNet_3.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */


#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer3_6.h"

//생성자가 호출되기 이전에 factory class에서 stub를 생성함.
//factory class를 부르지 않으면 default product code로 동작함. 그렇지 않으면
//생성한 stub를 주입함

class LogAnalyzerTest : public :: testing :: Test {
protected:
	std::shared_ptr<LogAnalyzer> plogAn = nullptr;
	virtual void SetUp(){
		std::shared_ptr<stubTrueManager> stub = std::make_shared<stubTrueManager>();
		managerFactory.setManager(stub);
		plogAn = std::make_shared<LogAnalyzer>();
	}
	virtual void TearDown(){
		plogAn = nullptr;
	}
};

TEST_F(LogAnalyzerTest, exptectTrue) {
	string filename = "abc.SLF";
	ASSERT_TRUE(plogAn->IsValidLogfileName(filename));
}

TEST_F(LogAnalyzerTest, exptectFalse) {
	string filename = "abc.SXF";
	ASSERT_FALSE(plogAn->IsValidLogfileName(filename));
}

int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!! !!" << endl; // prints !!!Hello World!!!
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
