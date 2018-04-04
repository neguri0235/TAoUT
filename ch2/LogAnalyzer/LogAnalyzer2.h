/*
 * LogAnalyzer.h
 *
 *  Created on: Mar 28, 2018
 *      Author: lts
 */

#ifndef LOGANALYZER_LOGANALYZER2_H_
#define LOGANALYZER_LOGANALYZER2_H_

#include <iostream>
#include <string>

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

class LogAnalyzer1
{
public:
	bool IsValidLogfileName(string&& filename){

		if(!fileName.EndsWith(filename, ".SLF")){

			return false;
		}
		return true;
	}
};


class LogAnalyzer3{
private:
	bool wasLastFileNameValid;
public:
	bool IsValidLogfileName(string&& filename){

		if(!fileName.EndsWith(filename, ".SLF")){
			wasLastFileNameValid = false;
			return false;
		}
		wasLastFileNameValid = true;
		return true;
	}

	bool getLastFileNameValid(){
		return wasLastFileNameValid;
	}
};


#endif /* LOGANALYZER_LOGANALYZER2_H_ */
