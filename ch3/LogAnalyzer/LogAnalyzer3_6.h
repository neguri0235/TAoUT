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



// 의존성 주입을 취해서 Factory class를 사용

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

class stubFalseManager : public IExtensionManager {
public:
	bool IsValid(std::string& fn) {
		std::cout<<"subFalseManager"<<std::endl;
		return false;
	}
};


class stubTrueManager : public IExtensionManager {
public:
	bool IsValid(std::string& fn) {
		std::cout<<"subTrueManager"<<std::endl;
		return true;
	}
};


class ExtensionManagerFactory {
private:
	std::shared_ptr<IExtensionManager> customManager = nullptr;
public:
	std::shared_ptr<IExtensionManager> Create() {
		if(customManager == nullptr){
			customManager = std::make_shared<FileExtensionManager>();
		}
		return customManager;
	}

	void setManager(std::shared_ptr<IExtensionManager> mgr) {
		customManager = mgr;
	}
};

// Factory class를 위해서 여기에 선언함.
// 좀더 스마트한 방법이 있어야 하는데.
ExtensionManagerFactory managerFactory;

class LogAnalyzer{
private:
	std::shared_ptr<IExtensionManager> manager = nullptr;
public:
	LogAnalyzer(){
		manager = managerFactory.Create();
	}

	bool IsValidLogfileName(string& filename) {
		return manager->IsValid(filename);
	}

};


#endif /* LOGANALYZER_LOGANALYZER3_H_ */
