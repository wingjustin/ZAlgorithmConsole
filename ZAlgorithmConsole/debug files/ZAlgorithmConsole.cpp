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

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 5); // character range 0 - 25

    std::random_device dev2;
    std::mt19937 rng2(dev2());
    std::uniform_int_distribution<std::mt19937::result_type> dist7(1, 220); //string length

    std::random_device dev3;
    std::mt19937 rng3(dev3());
    std::uniform_int_distribution<std::mt19937::result_type> dist8(0, 2); //repeat length

    string keyword = "";

    int round = 0;
    int totRound = 100;

    bool health = true;

    //string keyword = "";

    char operKey = 'E';
    do {
        int randomLength = dist7(rng2);


        keyword = "";
        for (int r = 0; r < randomLength; r++) {
            int charIndex = dist6(rng) + 97;

            keyword += (char)charIndex;

            int repeatCount = dist8(rng3);
            string repeat = keyword;
            for (int rrp = 0; rrp < repeatCount; rrp++) {
                keyword += repeat;
                r+= repeatCount * (int)repeat.length();
            }
        }
        cout << "Round : " << to_string(round+1) << endl;

        //keyword = "ccchhhccccee";
        //keyword = "aaaaaa";
        //keyword = "aabcaabxaaaz";
        //keyword = "aabcaabcaaaab";

        //keyword = "ccccchhhccccccee";
        //keyword = "aaxaaabcaaxaaabcaaxaaaaaaaxaaab";


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

        ////insert words
        //inputWord = "";
        //temp;
        //while (cin.get(temp) && temp != '\n') {
        //    inputWord += temp;
        //}
        //keyword = inputWord;

        cout << keyword << endl;

        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);

        cout << "------------------------------------------------------------------------------------------" << endl;

        
        int* zArray=NULL;

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

        cout << endl;

        int* reverseZArray = NULL;
        string reverseKeyword(keyword.rbegin(), keyword.rend());
        int reverseLength = ZFunction::GetReverseZArray(reverseKeyword, reverseZArray);

        //show the length of z array
        cout << "Length : ";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_BLUE);
        cout << to_string(length) << endl;
        if (length > 0) {
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << "Z array : { ";
            //show z array
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
            cout << to_string(zArray[length - 1]);
            for (int i = length - 2; i > -1; i--) {
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
                cout << ", ";
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
                cout << to_string(zArray[i]);
            }
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << " }";
        }


        cout << endl;
        int* cz=NULL;

        int debugLength = ZFunction::DebugGetZarr(keyword, cz);

        //show the length of z array
        cout << " Correct Length : ";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_BLUE);
        cout << to_string(length) << endl;
        if (length > 0) {
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << "correct Z array : { ";
            //show z array
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
            cout << to_string(cz[0]);
            for (int i = 1; i < length; i++) {
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
                cout << ", ";
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_RED);
                cout << to_string(cz[i]);
            }
            SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            cout << " }";
        }

        //check
        for (int i = 0; i < length; i++) {
            if (zArray[i] != cz[i])
            {
                health = false;
                break;
            }
        }

        cout << endl;
        cout << "health : " << (health ? "OK, no bug" : "Warning, There have bug") << endl;

        //check
        for (int i = 0; i < reverseLength; i++) {
            if (reverseZArray[reverseLength - 1 - i] != cz[i])
            {
                health = false;
                break;
            }
        }

        cout << endl;
        cout << "reverse health : " << (health ? "OK, no bug" : "Warning, There have bug") << endl;


        delete[] zArray;

        delete[] cz;

        cout << endl << endl;

        ////check continue
        //cout << "Press Any Key to start from Keyword; \"E\" for Exit : ";
        //operKey = _getch();
        //cout << "\n=========================================================================" << endl;
    } //while (operKey != 'e' && operKey != 'E');
    while (health && ++round < totRound);
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
