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

//step4. 테스트 대상 클래스에 stub을 주입
// 새로운 파일로. LogAnalyzer3_4_3.h


class IExtensionManager {
public:
	IExtensionManager()=default;
	virtual ~IExtensionManager()=default;
	virtual bool IsValid(std::string& str) = 0;
};

class FileExtensionManager : public IExtensionManager {
public:
	bool IsValid(std::string& fn) {
		return fileName.EndsWith(fn, ".SLF");
	}
};

class StubExtensionManager : public IExtensionManager {

public:
	bool ShouldExtesionBeValid;

	bool IsValid(std::string& fn) {
		return ShouldExtesionBeValid;
	}
};

class LogAnalyzer {
protected:
	std::shared_ptr<IExtensionManager> manager;
public:
	LogAnalyzer() {
		 manager = std::make_shared<FileExtensionManager>();
	}

	LogAnalyzer(std::shared_ptr<IExtensionManager> mgr) {
		manager = mgr;
	}

	bool IsValidLogfileName(string& filename) {
		return manager->IsValid(filename);
	}
};


#endif /* LOGANALYZER_LOGANALYZER3_H_ */
