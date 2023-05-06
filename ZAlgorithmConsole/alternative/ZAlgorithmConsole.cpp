// ZAlgorithmConsole.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include<conio.h>
#include "ZFunction.h"

#include <random>

#define NORMAL_STYLE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define HIGHLINE_STYLE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_BLUE & FOREGROUND_GREEN & FOREGROUND_RED)

using namespace std;
using namespace ZAlgorithm;

/*
example 1 : "ccchhhccccee" = { 12, 2, 1, 0, 0, 0, 3, 3, 2, 1, 0, 0 }
example 2 : "aabcaabcaaaab" = { 13, 1, 0, 0, 6, 1, 0, 0, 2, 2, 3, 1, 0 }
example 3 : "aabcaabxaaaz" = { 12, 1, 0, 0, 3, 1, 0, 0, 2, 2, 1, 0 }
example 4 : "aaaaaa" = { 6, 5, 4, 3, 2, 1 }
example 5 : "aab$baabaa" = {10, 1, 0, 0, 0, 3, 1, 0, 2, 1}
example 6 : "aaaaabaaaaaaaaaaz" = {17, 4, 3, 2, 1, 0, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0}
example 7 : "aaaaabaaaaaaaaaab" = {17, 4, 3, 2, 1, 0, 5, 5, 5, 5, 5, 6, 4, 3, 2, 1, 0}
example 8 : "aaaaaaaaabaaaaz" = {15, 8, 7, 6, 5, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0}
*/

int main()
{
    string keyword = "";

    char operKey = 'E';
    do {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        //title
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE ^ BACKGROUND_RED);
        cout << "Z Algorithm";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << endl << "------------------------------------------------------------------------------------------" << endl;
        string inputWord = "";
        char temp;

        cout << "Please input ";
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE);
        cout << "Keyword";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << " : " << "\n";
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE);

        //insert words
        inputWord = "";
        temp;
        while (cin.get(temp) && temp != '\n') {
            inputWord += temp;
        }
        keyword = inputWord;

        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);

        cout << "------------------------------------------------------------------------------------------" << endl;

        int* zArray = NULL;
        int length = ZFunction::GetZArray(keyword, zArray);

        //show the length of z array
        cout << "Length : ";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_BLUE);
        cout << to_string(length) << endl;
        if (length > 0) {
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << "Z array : { ";
            //show z array
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
            cout << to_string(zArray[0]);
            for (int i = 1; i < length; i++) {
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
                cout << ", ";
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
                cout << to_string(zArray[i]);
            }
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << " }";
        }

        delete[] zArray;

        cout << endl << endl;

        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        //check continue
        cout << "Press Any Key to start from Keyword; \"E\" for Exit : ";
        operKey = _getch();
        cout << "\n=========================================================================" << endl;
    } while (operKey != 'e' && operKey != 'E');
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
