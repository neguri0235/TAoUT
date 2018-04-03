/*
 * dotNet_3.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */


#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer3_4_3.h"


//생성자에 주입을 하고 있음

class LogAnalyzerTest : public :: testing :: Test {
protected:
	std::shared_ptr<LogAnalyzer> plogAn = nullptr;
	std::shared_ptr<StubExtensionManager> fakeManager = nullptr;

	virtual void SetUp(){
		fakeManager = std::make_shared<StubExtensionManager>();
		fakeManager->ShouldExtesionBeValid = true;
		plogAn = std::make_shared<LogAnalyzer>(fakeManager);
	}

	virtual void TearDown(){
		plogAn = nullptr;
		fakeManager = nullptr;
	}

};


TEST_F(LogAnalyzerTest, exptectTrue) {
	string filename = "abc.SLF";
	ASSERT_TRUE(plogAn->IsValidLogfileName(filename));
}

TEST_F(LogAnalyzerTest, exptectFalse) {
	string filename = "abc.SXF";
	fakeManager->ShouldExtesionBeValid = false;
	ASSERT_FALSE(plogAn->IsValidLogfileName(filename));
}


int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!! !!" << endl; // prints !!!Hello World!!!
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
