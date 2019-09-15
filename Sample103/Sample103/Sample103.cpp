// Sample103.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

extern "C" int func103(int, int);

int main()
{
	std::cout << func103(70, 50) << "\n";
}

