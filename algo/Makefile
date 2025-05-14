# Makefile: オンプレCI/CDの基礎用

# コンパイル対象
TARGET = stats
SRC = statistics.c

# コンパイルオプション
CFLAGS = -Wall -Wextra -g

all: build run

build:
	@echo "[INFO] ビルド中..."
	gcc -Wall -Wextra -g -o stats statistics.c

run:
	@echo "[INFO] 実行中..."
	./stats 2>&1 | tee log.txt

memcheck:
	@echo "[INFO] valgrind による検査..."
	valgrind --leak-check=full ./stats 2>&1 | tee memcheck.log

clean:
	@rm -f stats log.txt memcheck.log
	@echo "[INFO] クリーン完了"

# --enable=all　すべての解析チェックを有効にする（通常は一部だけ）
# --inconclusive　 結果に自信がないものも含めて報告する（疑わしい箇所も拾う）
# --std=c99　C言語のC99規格で解析する（古い書き方や標準に沿ってチェック）
# --language=c　C言語として解析する（C++でないと明示する）
# $(SRC)　チェック対象のソースファイル（例：statistics.c）


# メモリリーク検出（valgrind）
memcheck:
	@echo "[INFO] valgrind によるメモリ検査..."
	valgrind --leak-check=full ./stats 2>&1 | tee memcheck.log

# valgrind 実行中のメモリ状態を検査するツール



# クリーンアップ
clean:
	@rm -f $(TARGET) log.txt
	@echo "[INFO] クリーン完了"

# .PHONY: all build run lint memcheck clean

# 🔹 clean:（ターゲット名）
# 	•	make clean と打つことでこのセクションが実行される
# 	•	よくある「後始末」作業を自動化するための定番ターゲット

# ⸻

# 🔹 @rm -f $(TARGET) log.txt
# 	•	rm：ファイル削除コマンド（Remove）
# 	•	-f：ファイルが存在しなくてもエラーにしない（強制削除）
# 	•	$(TARGET)：たとえば stats（コンパイルでできた実行ファイル）
# 	•	log.txt：run: ターゲットで保存されたログファイル

# つまり、「生成物（バイナリとログ）」を削除する

# ⸻

# 🔹 @echo "[INFO] クリーン完了"
# 	•	実行ログとして「クリーン作業が終わったこと」を明示