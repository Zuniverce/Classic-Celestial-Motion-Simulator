#pragma once
#include "Global.h"
class FileOperator //文件操作类
{
private:
	streambuf* cinbackup = NULL;
	streambuf* coutbackup = NULL;
	streambuf* finbackup = NULL;
	streambuf* foutbackup = NULL;
	int inMode = -ONE;
	int outMode = -ONE;
	ifstream fin; // 输入文件
	ofstream fout; //输出文件
public:
	const static inline string FILENAME = "The Three-body Problem Simulator";
	FileOperator();
	~FileOperator();
	bool openIn();
	bool openOut();
	bool closeIn();
	bool closeOut();
	void selectOut();
	void selectIn();
};

