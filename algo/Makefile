<<<<<<< HEAD
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
=======
# --------- 共通設定 ---------
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# --------- Cアプリケーション ---------
C_SRC = statistics.c
C_BIN = stats

# --------- Cテスト ---------
C_TEST_SRC = test/sample_assert.c
C_TEST_BIN = test/sample_assert

# --------- Pythonテスト ---------
PYTEST_SRC = test/sample_assert.py

# --------- デフォルト（Cビルド＋実行） ---------
all: build run

# --------- ビルド＆実行 ---------
build:
	@echo "[INFO] Cコードをビルド中..."
	$(CC) $(CFLAGS) -o $(C_BIN) $(C_SRC)

run:
	@echo "[INFO] Cプログラムを実行..."
	./$(C_BIN) 2>&1 | tee log.txt

# --------- メモリ検査（Valgrind） ---------
memcheck:
	@echo "[INFO] valgrind によるメモリ検査中..."
	valgrind --leak-check=full ./$(C_BIN) 2>&1 | tee memcheck.log

# --------- テスト（C + Python） ---------
test: test_c test_py

test_c:
	@echo "[TEST] Cテストをビルド＆実行中..."
	$(CC) $(CFLAGS) -o $(C_TEST_BIN) $(C_TEST_SRC)
	./$(C_TEST_BIN)

test_py:
	@echo "[TEST] Pythonテストを実行中..."
	pytest $(PYTEST_SRC)

# --------- クリーンアップ ---------
clean:
	@echo "[INFO] クリーン中..."
	rm -f $(C_BIN) $(C_TEST_BIN) log.txt memcheck.log
	@echo "[INFO] クリーン完了"

# --------- 明示的に phony 指定 ---------
.PHONY: all build run memcheck test test_c test_py cleanつ
>>>>>>> pre
