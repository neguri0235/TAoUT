/*
 * dotNet_3.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: lts
 */


#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "LogAnalyzer/LogAnalyzer3.h"

using namespace std;




class LogAnalyzerTest : public ::testing :: Test {
protected:
	LogAnalyzer* plogAn = nullptr;

	virtual void SetUp() {
		plogAn = new LogAnalyzer();
	}

	virtual void TearDown(){
		delete plogAn;
		plogAn = nullptr;
	}
};

TEST_F(LogAnalyzerTest, exptectTrue) {
	string filename = "abc.SLF";
	ASSERT_TRUE(plogAn->IsValidLogfileName(filename));
}

TEST_F(LogAnalyzerTest, exptectFalse) {
	string filename = "abc.SLX";
	ASSERT_FALSE(plogAn->IsValidLogfileName(filename));
}



class LogAnalyzer_T_test : public :: testing :: Test {
protected:
	LogAnalyzer_T* plogAn= nullptr;

	virtual void SetUp(){
		plogAn = new LogAnalyzer_T();
	}

	virtual void TearDown(){
		delete plogAn;
		plogAn = nullptr;
	}

};


TEST_F(LogAnalyzer_T_test, exptectTrue) {
	string filename = "abc.SLF";
	ASSERT_TRUE(plogAn->IsValidLogfileName(filename));
}

TEST_F(LogAnalyzer_T_test, exptectFalse) {
	string filename = "abc.SLX";
	ASSERT_FALSE(plogAn->IsValidLogfileName(filename));
}



int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!! !!" << endl; // prints !!!Hello World!!!
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}
