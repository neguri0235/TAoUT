//============================================================================
// Name        : dotNET.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer2.h"

using namespace std;



class LogAnalyzerTest1 : public ::testing :: Test {
protected:
	LogAnalyzer1* plogAn = nullptr;

	virtual void SetUp() {
		plogAn = new LogAnalyzer1();
	}

	virtual void TearDown(){
		delete plogAn;
		plogAn = nullptr;
	}
};

TEST_F(LogAnalyzerTest1, exptectTrue) {
	ASSERT_TRUE(plogAn->IsValidLogfileName("abc.SLF"));
}

TEST_F(LogAnalyzerTest1, expectFalse) {
	ASSERT_FALSE(plogAn->IsValidLogfileName("abc.SLX"));
}


class LogAnalyzerTest3 : public ::testing :: Test {
protected:
	LogAnalyzer3* plogAn = nullptr;

	virtual void SetUp() {
		plogAn = new LogAnalyzer3();
	}

	virtual void TearDown(){
		delete plogAn;
		plogAn = nullptr;
	}
};

TEST_F(LogAnalyzerTest3, exptectTrue) {
	plogAn->IsValidLogfileName("abc.SLF");
	ASSERT_TRUE(plogAn->getLastFileNameValid());
}

TEST_F(LogAnalyzerTest3, expectFalse) {
	plogAn->IsValidLogfileName("abc.SLX");
	ASSERT_FALSE(plogAn->getLastFileNameValid());
}



int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!! !!" << endl; // prints !!!Hello World!!!
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
