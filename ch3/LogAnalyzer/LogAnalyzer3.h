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




//step 1.  product code start
// 기본 소스 코드
class FileExtensionManager{
public:
	FileExtensionManager() = default;
	bool IsValid(string& fn) {
		return fileName.EndsWith(fn, ".SLF");
	}
};

class LogAnalyzer{
public:
	bool IsValidLogfileName(string& filename){
		std::shared_ptr<FileExtensionManager> mgr = std::make_shared<FileExtensionManager>();
		return mgr->IsValid(filename);
	}
};
// product code end



//step 2.
//IExtensionManager를 추가하여 IExtentionManger 이하를 stub으로 대체가능
//step2에서는 아직 대체하지 않음.
class IExtensionManager {
public:
	IExtensionManager()=default;
	virtual ~IExtensionManager()=default;
	virtual bool IsValid(std::string& str) = 0;
};

class FileExtensionManager_T : public IExtensionManager {
public:
	bool IsValid(std::string& fn) {
		return fileName.EndsWith(fn, ".SLF");
	}
};

class LogAnalyzer_T {
public:
	bool IsValidLogfileName(string& filename) {
		std::shared_ptr<IExtensionManager> mgr = std::make_shared<FileExtensionManager_T>();
		return mgr->IsValid(filename);
	}

};


//step3. stub으로 기존의 FileExtensionManager_T 를 대체해 보자
// 그렇지만 현재는 IsValidLogfileName( ) 은 StubExtensionManager class 가 아닌 FileExtensionManager_T class 를 이용함.

class StubExtensionManager : public IExtensionManager {
public:
	bool IsValid(std::string& fn) {
		return true;
	}
};

//step4. 테스트 대상 클래스에 stub을 주입
// 새로운 파일로. LogAnalyzer3_4_3.h

#endif /* LOGANALYZER_LOGANALYZER3_H_ */
