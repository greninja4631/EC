<<<<<<< HEAD
from custom_exceptions import InvalidOperationError

def perform_operation(condition):
    if not condition:
        raise InvalidOperationError("操作が無効です：条件が満たされていません")

try:
    perform_operation(False)
except InvalidOperationError as e:
    print(f"エラーが発生しました: {e}")
=======
def long_function_name(var_one, var_two, var_three, var_four):
    print(var_one)
>>>>>>> c3ec9d7 (コミットメッセージ)
