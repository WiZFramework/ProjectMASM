// Sample102.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

extern "C" int func102(int, int);

int main()
{
    std::cout << func102(20,50) << "\n";
}

