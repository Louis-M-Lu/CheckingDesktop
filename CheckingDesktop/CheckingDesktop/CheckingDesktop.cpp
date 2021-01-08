#include <fstream>
#include <windows.h>
#include <iostream>
using namespace std;

string path = "C:/Users/dell/Desktop"; //桌面位置，需要修改
int files;

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

int main()
{

	while (true)
	{
		files = CountFiles();
		cout << files << endl;
		Sleep(1000);

	}

}