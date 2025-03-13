# exception_hierarchy.py のコード
def multiple_exception_handling(divisor):
    try:
        result = 10 / divisor
    except ZeroDivisionError:
        print("ゼロ除算のエラーが発生しました。")
    except TypeError:
        print("不正なタイプの操作がありました。")
    except Exception as e:
        print(f"予期しないエラーが発生しました: {e}")

multiple_exception_handling(0)
multiple_exception_handling("2")