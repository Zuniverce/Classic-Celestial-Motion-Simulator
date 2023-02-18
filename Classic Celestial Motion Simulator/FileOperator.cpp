#include "FileOperator.h"

FileOperator::FileOperator()
{
	cinbackup = cin.rdbuf();
	coutbackup = cout.rdbuf();
	fin.open("C:\\Users\\Administrator\\Desktop\\in.txt");
	fout.open("C:\\Users\\Administrator\\Desktop\\out.txt");
	finbackup = fin.rdbuf();
	foutbackup = fout.rdbuf();
	openIn();
	openOut();
}

FileOperator::~FileOperator()
{
	closeIn();
	closeOut();
}

bool FileOperator::openIn()
{
	if (!fin.is_open()) {
		fin.open("C:\\Users\\Administrator\\Desktop\\in.txt");
	}
	if (inMode == 0) {
		fin.set_rdbuf(cinbackup);
	}
	else {
		fin.set_rdbuf(finbackup);
	}
	if (fin.is_open()) {
		cout << "输入通道打开 成功." << endl;
		return true;
	}
	else {
		cout << "输入通道打开 失败." << endl;
		cout << "没有找到指定的输入文件, 已启动手动输入." << endl;

		return false;
	}
	return false;
}

bool FileOperator::openOut()
{
	if (!fout.is_open()) {
		fout.open("C:\\Users\\Administrator\\Desktop\\out.txt");
	}
	else {
		if (outMode == 0) {
			fout.set_rdbuf(coutbackup);
		}
		else {
			fout.set_rdbuf(foutbackup);
		}
	}
	if (fout.is_open()) {
		cout << "输出文件打开(创建) 成功." << endl;
		return true;
	}
	else {
		cout << "输出文件打开(创建) 失败." << endl;
		return false;
	}
	return false;
}

bool FileOperator::closeIn()
{
	if (fin.is_open())
	{
		fin.close();
		if (!fin.is_open()) {
			cout << "输入文件关闭 成功." << endl;
			return true;
		}
		else {
			cout << "输入文件关闭 失败." << endl;
			return false;
		}
	}
	return false;
}

bool FileOperator::closeOut()
{
	if (fout.is_open())
	{
		fout.close();
		if (!fout.is_open()) {
			cout << "输出文件关闭 成功." << endl;
			return true;
		}
		else {
			cout << "输出文件关闭 失败." << endl;
			return false;
		}
	}
	return false;
}

void FileOperator::selectOut()
{
	while (true) {
		cout << "选择输出方式(0 终端 / 1 文件):" << endl;
		cin >> outMode;
		if (outMode == 0 || outMode == 1) {
			break;
		}
	}
	openOut();
	/*if (mode == 0) {
		fout.set_rdbuf(coutbackup);
	}
	else {
		fout.set_rdbuf(foutbackup);
	}*/
}
