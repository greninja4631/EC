<<<<<<< HEAD
def check_permission(has_permission):
    if not has_permission:
        print("アクセス拒否")
    else:
        print("アクセス許可")

check_permission(False)  # → アクセス拒否
check_permission(True)   # → アクセス許可



def check_permission(has_permission):
    if  has_permission:
        print("アクセス許可")
        
    else:
        print("アクセス拒否")

check_permission(True) 
check_permission(False)  # → アクセス拒否
  # → アクセス許可
=======
# リファクタリング前のコード
def long_line_code(x: int):
    return x * x
>>>>>>> c3ec9d7 (コミットメッセージ)
