#include "SimpleRPG.h"

#include <iostream>
#include <string>

/// <summary>
/// メイン処理を実行する
/// </summary>
void SimpleRPG::execute() {
	std::cout << gameName << "スタート！" << std::endl;

	// 主人公・敵キャラのインスタンス生成
	MainCharactor mainChar("勇者", 100, 40, 20, 5, 100, 50);
	Monster monster1("スライム１", 50, 40, 20);
	Monster monster2("スライム２", 40, 50, 25);
	Monster monster3("スライム３", 50, 60, 20);
	Monster monsterList[] = { monster1, monster2, monster3 };

	// 設定した敵を全て倒すまで繰り返す
	for(Monster targetMonster : monsterList) {
		battle(mainChar, targetMonster);
	}

	std::cout << separatorLine << std::endl;
	std::cout << mainChar.get_name() << "の勝利！やったね！" << std::endl;
	quit();
}

/// <summary>
///　戦う
/// </summary>
/// <param name="mainChar">主人公</param>
/// <param name="monster">敵キャラ</param>
void SimpleRPG::battle(MainCharactor& mainChar, Monster& monster) {

	std::cout << separatorLine << std::endl;
	std::cout << monster.get_name() << "が現れた！" << std::endl;

	while(true) {
		// 主人公の状態表示
		std::cout << "現在の" << mainChar.get_name() << "の状態：" << mainChar.get_current_hp() << "/" << mainChar.get_max_hp() << std::endl;
		std::cout << "回復した回数：" << mainChar.get_count_heal() << "/" << mainChar.get_heal_upper_limit() << std::endl;

		// 入力コマンド取得
		std::string inputMode = get_command();

		if (inputMode == "A") {
			// 主人公の攻撃
			mainChar.attack(monster);

			// 敵の体力が0以下の場合
			if (monster.get_current_hp() <= 0) {
				std::cout << monster.get_name() << "を倒した！" << std::endl;
				return;
			}
		}
		else if (inputMode == "R") {
			// 現在の体力が最大体力以上の場合
			if (mainChar.get_current_hp() >= mainChar.get_max_hp()) {
				std::cout << "これ以上回復できないよ！" << std::endl;
				continue;
			}

			// 回復回数の上限に達していない場合
			if (mainChar.can_heal_hp()) {
				mainChar.heal();
			}
			else {
				std::cout << "もう回復できないよ！" << std::endl;
				continue;
			}
		}
		else if (inputMode == "Q") {
			// 終了の再確認
			if (is_quit()) {
				quit();
			} else {
				continue;
			}
		}

		// 敵の攻撃
		monster.attack(mainChar);
		
		// 主人公の体力が0以下になった場合
		if (mainChar.get_current_hp() <= 0) {
			std::cout << mainChar.get_name() << "は倒されてしまった・・" << std::endl;
			quit();
		}
	}
}

/// <summary>
/// 戦闘時の選択コマンドを取得
/// </summary>
/// <returns>指定の入力値</returns>
std::string SimpleRPG::get_command()
{
	// 入力値チェックループ
	while (true) {
		std::cout << "A：攻撃する、R：回復する、Q：ゲームを終了する ＞ ";

		// 入力値受取り
		std::string inputMode = "";
		std::cin >> inputMode;

		if (inputMode == "A" || inputMode == "R" || inputMode == "Q") {
			// 指定の入力値
			return inputMode;
		}
	}
}

/// <summary>
/// 終了するかどうかの確認
/// </summary>
/// <returns>true:終了する、false:終了しない</returns>
bool SimpleRPG::is_quit()
{
	std::cout << "本当にゲームを終了しますか？" << std::endl;
	std::cout << "終了する場合は\"YES\"と入力してください ＞ ";

	// 入力値受取り
	std::string inputKey = "";
	std::cin >> inputKey;

	if (inputKey == "YES") {
		return true;
	}
	return false;
}

/// <summary>
/// メイン処理を終了する
/// </summary>
void SimpleRPG::quit() {
	// 終了メッセージ出力
	std::cout << separatorLine << std::endl;
	std::cout << gameName << "を終了します" << std::endl;
	std::cout << "任意の文字を入力して、Enterを押下してください ＞ ";
	std::string endKey;
	std::cin >> endKey;
	exit(0);
}