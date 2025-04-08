import os
import asyncio
import wave
import resource
import multiprocessing
import sounddevice as sd
import numpy as np

# === グローバル設定 ===
SAMPLERATE = 16000
DURATION = 3  # 録音時間（秒）
FILENAME = "sample.wav"

# === ファイルI/O：録音してWAV保存 ===
def record_audio(filename):
    print(f"[録音] {DURATION}秒間録音します...")
    audio = sd.rec(int(SAMPLERATE * DURATION), samplerate=SAMPLERATE, channels=1, dtype='int16')
    sd.wait()
    with wave.open(filename, 'w') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)  # int16 = 2バイト
        wf.setframerate(SAMPLERATE)
        wf.writeframes(audio.tobytes())
    print(f"[保存完了] {filename}")

# === 仮想メモリ使用量の確認 ===
def print_memory_usage(tag=""):
    usage = resource.getrusage(resource.RUSAGE_SELF)
    print(f"[{tag}] 仮想メモリ使用量: {usage.ru_maxrss / 1024:.2f} MB")

# === プロセス処理（fork + wait + pid表示）===
def audio_process_worker():
    print(f"[子プロセス] PID: {os.getpid()} にて録音処理開始")
    print_memory_usage("子プロセス録音前")
    record_audio(FILENAME)
    print_memory_usage("子プロセス録音後")

# === 非同期で録音ファイルを再生 ===
async def async_play_audio(filename):
    print(f"[非同期] {filename} を再生します...")
    with wave.open(filename, 'rb') as wf:
        frames = wf.readframes(wf.getnframes())
        data = np.frombuffer(frames, dtype='int16')
        sd.play(data, wf.getframerate())
        await asyncio.sleep(DURATION)
        sd.stop()
    print(f"[再生完了]")

# === メイン関数 ===
def main():
    print(f"[メイン] PID: {os.getpid()}")

    # プロセスを作って録音
    p = multiprocessing.Process(target=audio_process_worker)
    p.start()
    p.join()  # wait()

    # 非同期で再生
    asyncio.run(async_play_audio(FILENAME))

    print("[メイン] 処理完了")

if __name__ == "__main__":
    main()