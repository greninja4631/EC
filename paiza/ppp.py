import mmap
import os

# 10MBのファイル作成
with open("test.bin", "wb") as f:
    f.write(b'\x00' * 10 * 1024 * 1024)

# mmapで仮想メモリマッピング（まだRAMには来てない）
with open("test.bin", "r+b") as f:
    mm = mmap.mmap(f.fileno(), 0)
    print("まだRAMに読み込んでない状態")

    # ページフォールトを起こす！ = 実際にアクセスした瞬間
    print("ページフォールトを発生させます...")
    print(mm[0])  # ここで初めてRAMに読み込まれる

    mm.close()