// SampleMASM.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

extern "C" float funcSample(float, float);

int main()
{
	std::cout << funcSample(70.5f, 50.0f) << "\n";
}
