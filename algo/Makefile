# Makefile: オンプレCI/CDの基礎用

# コンパイル対象とオプション
TARGET = stats
SRC = statistics.c
CFLAGS = -Wall -Wextra -g

# デフォルトターゲット
all: build run

# ビルド
build:
	@echo "[INFO] ビルド中..."
	gcc $(CFLAGS) -o $(TARGET) $(SRC)

# 実行＋ログ保存
run:
	@echo "[INFO] 実行中..."
	./$(TARGET) 2>&1 | tee log.txt

# メモリ検査（valgrind）
memcheck:
	@echo "[INFO] valgrind によるメモリ検査..."
	valgrind --leak-check=full ./$(TARGET) 2>&1 | tee memcheck.log

# クリーンアップ
clean:
	@echo "[INFO] クリーン中..."
	@rm -f $(TARGET) log.txt memcheck.log
	@echo "[INFO] クリーン完了"

# 明示的に phony ターゲット指定（エラー防止）
.PHONY: all build run memcheck clean
