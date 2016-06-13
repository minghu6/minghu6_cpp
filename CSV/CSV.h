#pragma once

#include <assert.h>
#include <map>
#include <vector>
#include <string>

#include "../minghu6.h"
using std::map;
using std::vector;


typedef unsigned long   u32;

namespace minghu6{
	class CSV
	{
	private:
		map<u32, map<u32, string>> m_stringMap;
		string m_CSVName;
	public:
		CSV(){}
		CSV(const char *path)
		{
			assert(LoadCSV(path));
		}
		~CSV(){}

		bool LoadCSV(const char *path);
		bool SaveCSV(const char *path = NULL);

		bool GetIntValue(u32 uiRow, u32 uiCol, int &riValue);
		bool GetFloatValue(u32 uiRow, u32 uiCol, double &rfValue);
		string* GetStringValue(u32 uiRow, u32 uiCol);

		int GetParamFromString(string str, vector<string> &stringVec, char delim = ',');


		map<u32, map<u32, string>>& GetCSVMap()
		{
			return m_stringMap;
		}


	};
}

