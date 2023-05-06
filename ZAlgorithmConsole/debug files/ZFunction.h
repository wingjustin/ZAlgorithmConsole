#pragma once

#include <string>
#include <sstream>

using namespace std;

namespace ZAlgorithm {
	class ZFunction {
	public:
		static int GetZArray(string keyword, int*& zArray); //return length of z array
		static int GetReverseZArray(string reverseKeyword, int*& zArray); //return length of z array
		static int KeywordSearch(string keyword, string text, int*& locationArray); //return count of matches
		static int DebugGetZarr(string str, int*& Z);
	};
}