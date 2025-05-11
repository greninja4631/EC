import pyautogui
import time

# 総ループ回数（4分 × 135回 = 540分 = 9時間）
loop_count = 135

print("🟢 マウス操作スタート（9時間持続）")

for i in range(loop_count):
    pyautogui.moveRel(0, 1)   # 1px動かす
    pyautogui.moveRel(0, -1)  # 戻す
    print(f"✅ {i+1}回目: Mouse moved at {time.strftime('%Y-%m-%d %H:%M:%S')}")
    time.sleep(240)  # 4分待機

print("🔚 9時間のマウス操作が完了しました")