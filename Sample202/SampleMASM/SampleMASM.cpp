// SampleMASM.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

struct Vector {
	float x;
	float y;
	float z;
	float w;
};


extern "C" float funcSample(Vector* v);

int main()
{
	Vector v = { 1.5f,2.3f,3.4f,4.5f };

	std::cout << funcSample(&v) << "\n";
}
