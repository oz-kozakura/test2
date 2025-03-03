#pragma once

#include "MainCharactor.h"
#include "Monster.h"

class SimpleRPG
{
public:
	// 実行する
	void execute();

private:
	// ゲーム名
	const std::string gameName = "simpleRPG";

	// 区切り線（画面出力用）
	const std::string separatorLine = "-------------------------------------------------------------------";

	// 戦う
	void battle(MainCharactor& mainChar, Monster& monster);

	// 戦闘時の選択コマンドを取得
	std::string get_command();

	// 終了するかどうかの確認
	bool is_quit();

	// 終了する
	void quit();
};

