# condition1 を事前に定義
condition1 = True  # または条件式を使う

if condition1:
    print("条件が満たされました。")


# 関数内で使用する場合
def check_condition(condition1):
    if condition1:
        print("OK")


# 関数を呼び出す際に condition1 を渡す
check_condition(True)
