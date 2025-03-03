#pragma once

#include "Charactor.h"

class Monster :
    public Charactor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="name">名前</param>
	/// <param name="max_hp">最大体力</param>
	/// <param name="max_attack">最大攻撃力</param>
	/// <param name="min_attack">最小攻撃力</param>
	Monster(
		const std::string& name,
		int max_hp,
		int max_attack,
		int min_attack
	) : Charactor(
			name,
			max_hp,
			max_attack,
			min_attack
		)
	{

	}
};

