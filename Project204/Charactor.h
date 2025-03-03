#pragma once

#include <string>

class Charactor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="name">名前</param>
	/// <param name="max_hp">最大体力</param>
	/// <param name="max_attack">最大攻撃力</param>
	/// <param name="min_attack">最小攻撃力</param>
	Charactor(
		const std::string& name,
		int max_hp,
		int max_attack,
		int min_attack
	) : name_(name),
		max_hp_(max_hp),
		max_attack_(max_attack),
		min_attack_(min_attack),
		current_hp_(max_hp)
	{

	}

	// 攻撃する
	void attack(Charactor& attackedSide);

	// getter, setter
	// 名前
	std::string get_name() {
		return name_;
	}

	// 最大体力
	int get_max_hp() {
		return max_hp_;
	}

	// 現在の体力
	int get_current_hp() {
		return current_hp_;
	}
	void set_current_hp(int current_hp) {
		current_hp_ = current_hp;
	}

protected:
	// ランダムな数を取得
	int get_random_number(int minimum, int maximum);

private:
	// 名前
	std::string name_;

	// 最大体力
	int max_hp_;

	// 現在の体力
	int current_hp_;

	// 最大攻撃力
	int max_attack_;

	// 最小攻撃力
	int min_attack_;
};

