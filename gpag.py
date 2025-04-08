import heapq
import random
import time

class Process:
    def __init__(self, pid, vruntime=0):
        self.pid = pid
        self.vruntime = vruntime
    
    def __lt__(self, other):
        return self.vruntime < other.vruntime  # heapqで小さい順に並べるため

    def __repr__(self):
        return f"PID:{self.pid}, vruntime:{self.vruntime}"

# プロセスリストを優先度付きキュー（最小ヒープ）として管理
ready_queue = []
heapq.heapify(ready_queue)

# 仮のプロセスを5個作成（全員 vruntime = 0）
for i in range(5):
    heapq.heappush(ready_queue, Process(pid=i+1))

print("🎬 CFSスケジューラ スタート\n")

# 10回スケジューリングしてみる
for t in range(10):
    print(f"🕒 時刻 {t}")

    # 最もCPUを使ってない（vruntimeが最小）なプロセスを選ぶ
    current = heapq.heappop(ready_queue)
    print(f"➡️ 実行対象: {current}")

    # 実行時間（1～10ms）をランダムに割り当てて仮想時間に加算
    exec_time = random.randint(1, 10)
    current.vruntime += exec_time
    print(f"⏱ 実行時間: {exec_time}ms → 新しいvruntime: {current.vruntime}")

    # 再びキューに戻す
    heapq.heappush(ready_queue, current)
    print("📋 現在のキュー:", ready_queue)
    print("-" * 40)
    time.sleep(0.5)  # 見やすくするためちょっと止める

print("✅ スケジューリング終了！")