#pragma once

#include "Charactor.h"

class MainCharactor :
    public Charactor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="name">名前</param>
	/// <param name="max_hp">最大体力</param>
	/// <param name="max_attack">最大攻撃力</param>
	/// <param name="min_attack">最小攻撃良く</param>
	/// <param name="heal_upper_limit">回復回数上限</param>
	/// <param name="max_heal">最大回復量</param>
	/// <param name="min_heal">最小回復量</param>
	MainCharactor(
		const std::string& name,
		int max_hp,
		int max_attack,
		int min_attack,
		int heal_upper_limit,
		int max_heal,
		int min_heal
	) : Charactor(
			name,
			max_hp,
			max_attack,
			min_attack
		),
		count_heal_(0),
		heal_upper_limit_(heal_upper_limit),
		max_heal_(max_heal),
		min_heal_(min_heal)
	{

	}
	
	// 回復回数の確認
	bool can_heal_hp();

	// 回復する
	void heal();

	//　getter
	int get_count_heal() {
		return count_heal_;
	}
	int get_heal_upper_limit() {
		return heal_upper_limit_;
	}

private:
	// 回復回数
	int count_heal_;

	// 回復回数の上限
	int heal_upper_limit_;

	// 最大回復量
	const int max_heal_;

	// 最小回復量
	const int min_heal_;

	// 回復後の体力を取得
	void get_healed_hp();

};

