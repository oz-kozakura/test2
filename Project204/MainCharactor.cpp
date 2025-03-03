#include "MainCharactor.h"

#include <iostream>

/// <summary>
/// 回復回数の確認
/// </summary>
/// <returns>true:回復可能、false:回復不可</returns>
bool MainCharactor::can_heal_hp()
{
    // 回復回数の上限に達していない場合は回復可能
    if (count_heal_ < heal_upper_limit_) {
        return true;
    }
    return false;
}

/// <summary>
/// 回復する
/// </summary>
void MainCharactor::heal()
{
    // 回復後の体力を取得
    get_healed_hp();

    std::cout << "体力が" << get_current_hp() << "になった！" << std::endl;
    
    // 回復回数のカウント
    count_heal_++;
}

/// <summary>
/// 回復後の体力を取得
/// </summary>
void MainCharactor::get_healed_hp()
{
    // 回復量を取得
    int recoveryQuantity = get_random_number(min_heal_, max_heal_);

    // 回復後の体力を計算する
    int hpAfterRecovery = get_current_hp() + recoveryQuantity;
    
    // 回復後の体力が最大体力を超えている場合、回復後の体力を修正する
    if (hpAfterRecovery > get_max_hp()) {
        hpAfterRecovery = get_max_hp();
    }

    // 現在の体力を更新する
    set_current_hp(hpAfterRecovery);
}
