# exception_example.py のコード
def divide_by_zero():
    try:
        result = 10 / 0
    except Exception as e:
        print(f"例外が発生しました: {e}")

divide_by_zero()