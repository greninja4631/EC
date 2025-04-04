# デコレータの定義
def foo(func):
    def wrapper():
        print("Before function execution.")
        func()  # 引数として渡された関数を実行
        print("After function execution.")
    return wrapper

# デコレータを関数に適用
@foo
def bar():
    print("Inside the bar function.")

# 関数の実行
bar()