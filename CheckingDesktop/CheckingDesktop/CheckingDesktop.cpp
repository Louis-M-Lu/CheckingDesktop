#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <io.h>
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )	//后台运行
using namespace std;

int na = 0;	//存名字变量 
string path = "D:/test1"; //桌面位置，需要修改
									   //学校：C:/Users/Administrator/Desktop
string ToPath = "D:/test";	//目标位置，需要修改
int Files;	//统计文件数
int BefFiles = 3;	//原来的文件数，需要修改
string FilesName[1001] = { "" };	//存文件名

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}

int CountFiles()
{
	path = "D:/test1";
	path = path + "/*.*";
	HANDLE hFind;
	WIN32_FIND_DATA dataFind;
	BOOL bMoreFiles = TRUE;
	int iCount = 0;//统计文件数的变量

	
	//m_strDir就是你要指定的路径
	hFind = FindFirstFile(stringToLPCWSTR(path), &dataFind);//找到路径中所有文件

	//遍历路径中所有文件
	while (hFind != INVALID_HANDLE_VALUE && bMoreFiles == TRUE)
	{
		if (dataFind.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)//判断是否是文件
		{
			iCount++;
		}
		bMoreFiles = FindNextFile(hFind, &dataFind);
	}
	FindClose(hFind);

	return iCount;
}

void FindFiles()
{
	//目标文件夹路径
	path = "D:/test1";
	std::string inPath = path + "/*.*";//遍历文件夹下的所有文件
	//用于查找的句柄
	long handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return ;
	do
	{
		//找到的文件的文件名
		//printf("%s\n", fileinfo.name);
		FilesName[na++] = fileinfo.name;

	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);
}

int main()
{

	while (true)
	{
		Files = CountFiles();
		cout << Files << endl;
		if (Files >= BefFiles)
		{
			FindFiles();
			
		}

		Sleep(1000);
	}

}