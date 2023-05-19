        #1. 发送文本文件

import smtplib
import email
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.header import Header
from email.utils import formataddr

sender = '2904017884@qq.com' #发件人邮箱
receiver = '2321901849@qq.com' #收件人邮箱
//////////////////////////////////////////////////////////////////////

#text为邮件正文内容，plain为文本格式，'utf-8'为编码格式
text = 'aa'
message = MIMEMultipart()

#添加Header信息，From，To，Subject分别为发送者信息，接收者消息和邮件主题
message['From'] = formataddr((str(Header('发件人', 'utf-8')), sender))
message['To'] = formataddr((str(Header('收件人', 'utf-8')), receiver))

subject = 'aa'
message['Subject'] = Header('邮件主题', 'utf-8')

# 添加附件
with open('66666.txt', 'rb') as f:
    attachment = MIMEApplication(f.read())
    attachment.add_header('Content-Disposition', 'attachment', filename='66666.txt')
    message.attach(attachment)


try:
    #smtp.xxx.com为邮箱服务类型，25为STMP的端口
    smtpObj = smtplib.SMTP('smtp.qq.com', 25)#smtp.xxx.com为邮箱服务类型，25为STMP
    #smtpObj = smtplib.SMTP_SSL('smtp.xxx.com', 'xxx邮件服务的端口号')     
    
    smtpObj.login(sender, mail_pass)#登录
    smtpObj.sendmail(sender, receiver, message.as_string())#发送
    print ("邮件发送成功")
except smtplib.SMTPAuthenticationError:
    print("Error: 邮箱账号验证失败")
except smtplib.SMTPConnectError:
    print("Error: 无法连接到SMTP服务器")
#except smtplib.SMTPDataError:
    #print("Error: 邮件发送失败，数据错误")
except smtplib.SMTPServerDisconnected:
    print("Error: 连接SMTP服务器失败或连接被断开")
except smtplib.SMTPHeloError:
    print("Error: SMTP服务器拒绝了HELO命令")
except smtplib.SMTPSenderRefused:
    print("Error: 发件人邮箱地址被拒绝")
except smtplib.SMTPRecipientsRefused:
    print("Error: 收件人邮箱地址被拒绝")

#except smtplib.SMTPException:
    #print("Error: 邮件发送失败")
