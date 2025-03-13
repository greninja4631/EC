from custom_exceptions import InvalidOperationError

def perform_operation(condition):
    if not condition:
        raise InvalidOperationError("操作が無効です：条件が満たされていません")

try:
    perform_operation(False)
except InvalidOperationError as e:
    print(f"エラーが発生しました: {e}")