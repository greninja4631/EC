# comment_style.pyのコード
def divide(numerator, denominator):
    # denominatorが0でないことを確認
    if denominator == 0:
        raise ValueError("Denominator cannot be zero.")
    return numerator / denominator


print(divide(4, 2))  # 結果: 2.0
