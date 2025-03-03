#include "SimpleRPG.h"

#include <iostream>

int main() {
	try {
		// 問題204:コンソール版のミニRPG
		SimpleRPG simpleRPG;
		simpleRPG.execute();
	}
	catch (const std::exception e) {
		std::cout << "例外が発生しました。内容 = " << e.what() << std::endl;
		std::cout << "処理を中断します。" << std::endl;
	}

	return 0;
}