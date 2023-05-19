# 学习python的第N天
import os
import subprocess
from aip import AipSpeech
import time

""" APPID AK SK """
APP_ID = '33513297'
API_KEY = 'a6AW7ML0c42PUdpBgz8Miv8f'
#################

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

# 读取数据
with open('/home/pi/log/log.txt', mode='r', encoding='utf-8') as f:
    text = f.read()

with open('/home/pi/log/log.txt', mode='r', encoding='utf-8') as txt_user:
    canshu1, canshu2, canshu3 = txt_user.readline().split()

result = client.synthesis(text, 'zh', 1, {
    'vol': 8,
    'per': 5118,
    'pit': 6,
})

# 识别正确返回语音二进制 错误则返回dict
if not isinstance(result, dict):
    # 保存MP3文件

    with open('/home/pi/audio/audio1/5118.mp3', 'wb') as file:
        file.write(result)

    # 播放MP3文件
    subprocess.Popen(['vlc', '--play-and-exit', '/home/pi/audio/audio1/5118.mp3'])

    # 等待几秒钟
    time.sleep(10)

    # 删除MP3文件
    os.remove('/home/pi/audio/audio1/5118.mp3')