#include "Charactor.h"

#include <iostream>
#include <random>
#include "../test2_sub/sub/subtract.h"

/// <summary>
/// 最小値～最大値の範囲でランダムな値を取得する
/// </summary>
/// <returns>ランダムな数値</returns>
int Charactor::get_random_number(int minimum, int maximum) {
	// 非決定的な乱数生成器を宣言
	std::random_device rnd;
	// メルセンヌ・ツイスタ生成器を生成
	std::mt19937 mt(rnd());
	// 乱数の範囲を指定
	std::uniform_int_distribution<> rand(minimum, maximum);

	return rand(mt);
}

/// <summary>
/// 攻撃する
/// </summary>
/// <param name="attackedSide">攻撃される側</param>
void Charactor::attack(Charactor& attackedSide)
{
	// ダメージ数を取得
	int damages = get_random_number(min_attack_, max_attack_);

	std::cout << name_ << "の攻撃！" << std::endl;
	std::cout << attackedSide.name_ << "に" << damages << "のダメージを与えた！" << std::endl;

	// 現在の体力を更新
	//attackedSide.current_hp_ = attackedSide.current_hp_ - damages;
	attackedSide.current_hp_ = subtract(attackedSide.current_hp_, damages);
}