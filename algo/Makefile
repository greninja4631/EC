# Makefile: オンプレCI/CD 練習用（C + Python）

# --------- 共通設定 ---------
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# --------- Cアプリケーション ---------
C_SRC = main.c
C_BIN = main

# --------- Pythonスクリプト ---------
PYTHON_SRC = main.py

# --------- Cテスト ---------
C_TEST_SRC = test/test_main.c
C_TEST_BIN = test/test_main

# --------- Pythonテスト ---------
PYTEST_SRC = test/test_main.py

# デフォルト（ビルドと実行）
all: build run

# --------- 実行 ---------
build:
	@echo "[INFO] Cコードをビルド中..."
	$(CC) $(CFLAGS) -o $(C_BIN) $(C_SRC)

run:
	@echo "[INFO] Cプログラムを実行..."
	./$(C_BIN) 2>&1 | tee log.txt
	@echo "[INFO] Pythonスクリプトを実行..."
	python3 $(PYTHON_SRC)

# --------- メモリ検査 ---------
memcheck:
	@echo "[INFO] valgrind によるメモリ検査中..."
	valgrind --leak-check=full ./$(C_BIN) 2>&1 | tee memcheck.log

# --------- テスト ---------
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

# --------- 明示的な phony ターゲット ---------
.PHONY: all build run memcheck test test_c test_py clean