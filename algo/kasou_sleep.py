import pyautogui
import time
from datetime import datetime, timedelta

start_time = datetime.now()
end_time = start_time + timedelta(hours=9)

print(f"開始: {start_time.strftime('%H:%M:%S')} ～ 終了予定: {end_time.strftime('%H:%M:%S')}")
print("Slackオンライン維持を開始します...")

while datetime.now() < end_time:
    x, y = pyautogui.position()
    pyautogui.moveTo(x + 1, y, duration=0.1)
    pyautogui.moveTo(x, y, duration=0.1)
    pyautogui.click()  # クリックを追加
    pyautogui.press('shift')  # 軽いキーストローク
    print(f"[{datetime.now().strftime('%H:%M:%S')}] アクション実行")
    time.sleep(60)  # 60秒ごとに実行

print("Slackオンライン維持を終了します。")