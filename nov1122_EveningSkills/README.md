# บันทึกกิจกรรม <เรียนรู้ในสิ่งที่ไม่มีสอนในหลักสูตรแต่ธุรกิจ/อุตสาหกรรมอยากให้ทำเป็น>

repository นี้บันทึกรายละเอียดต่างๆของกิจกรรม “เรียนรู้ในสิ่งที่ไม่มีสอนในหลักสูตรแต่ธุรกิจ/อุตสาหกรรมอยากให้ทำเป็น” ที่เรียกนักศึกษามาทดลองเขียนโค้ดเพื่อเรียนรู้การแก้ปัญหาจากโจทย์ในอุตสาหกรรม  เนื้อหาของกิจกรรมแบ่งออกเป็นส่วนๆโดยใช้โจทย์เป็นเป้าหมายแล้วอธิบายเครื่องมือและโค้ดตัวอย่างที่ใช้แก้ปัญหานั้นๆ โดยแบ่งโจทย์ให้มีเนื้อหาที่เหมาะสมกับการเรียนรู้ภายใน 1 สัปดาห์ (เรียนช่วงเย็น สัปดาห์ละ 3 วัน)

## ระบบบันทึกข้อมูลการผลิต

สัปดาห์แรกที่เปิดตัวเลยจับเอาโจทย์ traceability (การตรวจย้อนกลับ) มาอธิบายเป็นไอเดีย   โจทย์ของ traceability ถือได้ว่าเป็น critical ของอุตสาหกรรมการผลิตปัจจุบันที่ต้องการเพิ่ม yield ให้ถึงขีดสุด และลดความเสี่ยงในการผลิตของที่มีตำหนิ จึงต้องการเห็นสถานะของผลิตภัณฑ์ตลอดช่วงการผลิต/จัดเก็บ/ส่งมอบ   การจัดเก็บข้อมูลในระหว่างการผลิตที่ใช้จริงมีใช้ทั้งเทคโนโลยี barcode (อ่านจากภาพ) และ/หรือ RFID  (อ่านจาก wireless) ผสมกัน เลยเลือก QR code มาใช้เป็นตัวอย่าง เพราะสามารถบรรจุข้อมูลได้มากและไม่ต้องซื้อฮาร์ดแวร์มาแจก (อันนี้สำคัญ)  จากนั้นข้อมูลจะถูกส่งผ่านไปจัดเก็บบนเซิร์ฟเวอร์เพื่อรอเอามาประมวลผลต่อ   แต่การไปเดินตาม auditor ในช่วงตรวจ ISO9000 เลยเจอว่ามีโรงงานที่ยังพึ่งพาคนในการบันทึก หรือ copy ไฟล์จากเครื่องก่อนมานั่งเปิดทีละไฟล์มา copy/paste ข้อมูลมารวมเป็นไฟล์ Excel ใหญ่ เพื่อทำกราฟสรุปไปทำเอกสาร powerpoint เพื่อประชุม   ตอนคิดถึงสภาพแบบนั้นเลยแบ่งโจทย์ออกมาเป็น 3 ขั้น เรียนรู้จากสภาพตอนนี้ไปสู่รูปแบบที่อยากให้เป็น 
  1. อ่าน QR code แล้วบันทึกเป็นไฟล์ 
  2. การทำ batch processing เพื่ออ่านไฟล์ CSV จำนวนมากมารวมแล้วประมวลผล
  3. การเชื่อมต่อแบบออนไลน์ แล้วใช้เครื่องมือสาย data processing มาดึงไปประมวลผล

การแก้โจทย์รอบนี้เลือกใช้ภาษา Python เป็นเครื่องมือในการทำให้เป็นจริง  การสอนจะเน้นที่ Windows เป็นหลัก เพราะไม่มี Mac และไม่อยากต้องเริ่มสอนจากวิธีใช้ Linux โดยเลือกใช้ Visual Studio Code เป็นเครื่องมือพัฒนาเพราะลองใช้แล้ว เร็วและสะดวกกว่าพวก Python IDE โดยเฉพาะเช่น Pycharm และอยากให้ลองเขียนเขียนโค้ดแบบองค์รวมมากกว่าการเขียนเป็นท่อนๆ (cell ของ Jupyter Notebook) ที่เหมาะกับสาย data analytics 

### การตรวจจับ QR code
วันที่ 11 พย. เรียนรู้พื้นฐานของการประมวลผลภาพด้วย OpenCV (ขยายไปสู่ระบบ visual inspection ในอนาคต) เพื่อจำแนกข้อมูลมาบันทึกเป็นไฟล์   การเรียนรู้เริ่มด้วยการติดตั้งเครื่องมือที่เลือกใช้ python 3.6.8 เพื่อให้สามารถติดตั้ง OpenCV ได้ โดย tip คือ **ต้องคลิกเลือก Add Path ในช่วงติดตั้ง** ไม่อย่างนั้นจะรวนตอนเรียกใช้คำสั่งต่างๆของ Python โดยเฉพาะ pip สำหรับติดตั้งไลบรารีต่างๆ   ปัญหาที่เจอตอนสอน Python คือ รุ่นของ Python จะตีกันเอง เพราะบางคนลง Python 2.7 หรือ 3.8 ไว้ หรือแย่กว่าคือ Anaconda ซึ่งจะทำให้มีปัญหาตอนติดตั้งไลบรารี   ไลบรารีที่ต้องติดตั้งเพิ่มเติมคือ OpenCV สำหรับถ่ายภาพ และ pyzbar ที่หุ้มการทำงานของไลบรารี ZBar ที่จัดการ QR code   การติดตั้งไลบรารีใช้การพิมพ์คำสั่ง pip ในหน้าต่าง command prompt (เรียกด้วยคำสั่ง cmd ใน start menu ของ Windows)

```
> pip install opencv-contrib-python pyzbar
```

การเรียนรู้เริ่มจากส่วนโค้ด template ของ OpenCV ในแบบ Python ซึ่งสร้าง capture object สำหรับถ่ายภาพจาก webcam ประมวลผลภาพ แล้ว preview ภาพ

```python
# prepare OpenCV, pyzbar, datetime, csv and winsound libraries
import cv2
from pyzbar.pyzbar import decode
from datetime import datetime
import csv
import winsound

# source preparation: image file, video file, camera
cap = cv2.VideoCapture(0)
while True:
    # read image
    ret,img = cap.read()
    # pre-process image
    img = cv2.flip(img, flipCode=1)
    # extract QR code from image

    # preview image and update GUI
    cv2.imshow('Preview', img)
    if cv2.waitKey(10) == ord('q'):
        break
cap.release()
```

เนื้อหาหลักของการเรียนรู้คือ แนวคิดในการแปลงข้อมูลภาพให้เป็นข้อมูลที่นำไปใช้ต่อได้ ซึ่งแบ่งออกเป็น 3 ส่วนหลักๆคือ
  - การจำแนกรหัส product ในรูปของ QR code จากข้อมูลภาพ ซึ่งง่ายและทำงานได้เร็วด้วยการเรียกใช้ไลบรารี ZBar แต่ยังคงต้องคิดตรรกะในการเลือกเฉพาะ QR code ที่ยังไม่ได้อ่าน เพราะ flow ของข้อมูลภาพจะมาแบบต่อเนื่อง รวมทั้งต้องแจ้งว่ามีการอ่านแล้วเพราะในอุปกรณ์จริงที่ไปติดตั้งอาจไม่มีหน้าจอให้ดู
  - การดึงข้อมูลเวลาปัจจุบันด้วยไลบรารี datetime เพื่อบันทึกเป็น timestamp ร่วมกับข้อมูลที่อ่านจาก QR code ซึ่งเป็นข้อมูลพื้นฐานของการผลิต
  - การจัดการไฟล์ CSV ด้วยการเรียกใช้ไลบรารี csv ซึ่งต้องเข้าใจหลักการของการเปิดไฟล์เพื่อเขียน header และเพิ่มข้อมูลทีละ row

### การประมวลผลไฟล์ CSV/xlsx จำนวนมาก
วันที่ 13 พย. เรียนการสแกนโฟลเดอร์แล้ว import ไฟล์ CSV/xlsx มาสร้างเป็นไฟล์ใหม่ ซึ่งเป็นสถานการณ์จริงที่ไปเจอในโรงงานมา   โรงงานมีเครื่องจักรอัตโนมัติในสายการผลิตจำนวนมาก โดยแต่ละเครื่องจะบันทึกข้อมูลผลิตภัณฑ์และสถานะของการทำงานลงในไฟล์ CSV แต่ไม่ออนไลน์ถึงเซิร์ฟเวอร์   หน้าที่หนึ่งของวิศวกรการผลิตจึงเป็นการเอาแฟลชไดร์ฟไป copy ไฟล์จากทุกเครื่องมาเปิดแล้ว copy เฉพาะข้อมูลไปไว้ในไฟล์ Excel หลักที่มีสูตรคำนวณเป็นสถานะการผลิตโดยรวม   ลองถามว่าใช้เวลานานไหม ผิดพลาดบ้างไหม ก็ได้คำตอบว่าต้องรอหลายวันแล้วค่อยทำ 1 รอบและก็มีผิดเป็นบางครั้ง (ลืม copy หรือ copy ซ้ำ)   เนื้อหาครั้งนี้จึงเน้นแนวคิดของการทำ batch processing จัดการไฟล์ข้อมูลที่สมมุติว่าเป็นการอ่าน QR code แบบมี timestamp จากวันที่ 11 พย.   ไลบรารีที่ต้องติดตั้งเพิ่มเติมคือ openpyxl สำหรับจัดการไฟล์ Excel โดยพิมพ์คำสั่ง

```
> pip install openpyxl
```

การเรียนรู้เริ่มจากส่วนโค้ด template ในการสแกนโฟลเดอร์เพื่อหาไฟล์ข้อมูลที่เป็น CSV หรือ Excel

```python
# import os, csv, datetime and openpyxl libraries
import os
import csv
from datetime import datetime
from openpyxl import Workbook

folder = './data/'

# function to scan folder for xlsx and csv files
def scan_folder(folder):
    files = os.listdir(folder)
    xlsx_files = []
    csv_files = []
    # categorize file types
    for f in files:
        fcomp = f.split('.')
        if fcomp[-1] == 'xlsx':
            xlsx_files.append(f)
        if fcomp[-1] == 'csv':
            csv_files.append(f)
    return {'XLSX': xlsx_files, 'CSV':csv_files}

# function to extract CSV contents
def extract_csv(files):
    records = []
    for f in files:
        print(f + ' is CSV file')
    return records

# main program
if __name__=='__main__':
    files = scan_folder(folder)
    if len(files['CSV']) > 0:
        records = extract_csv(files['CSV'])
```

เนื้อหาหลักของการเรียนรู้คือ แนวคิดในการแยกเนื้อหาออกจากไฟล์ข้อมูลมาพักไว้ใน data structure ที่เหมาะสม ซึ่งเลือกใช้ list เพราะยังมีขนาดข้อมูลที่ไม่ใหญ่มาก  จากนั้นจึงนำมารวมแล้วบันทึกลงในไฟล์ Excel ซึ่งต้องเข้าใจหลักการของการเข้าถึง workbook, worksheet และ cell ของ Excel   

### ระบบข้อมูลการผลิตออนไลน์
วันที่ 15 พย.เป็นการขมวดว่าหากโรงงานอยากให้ข้อมูลจากกระบวนการผลิตถูกเชื่อมต่อและนำไปใช้ ต้องการ jigsaw อะไรบ้าง   แนวคิดที่นำเสนอจึงเป็นการสร้างเซิร์ฟเวอร์แบบ web service อย่างง่ายที่อาศัย REST + JSON มาส่งผ่านข้อมูลจากอุปกรณ์ในสายการผลิตไปสู่คอมพิวเตอร์ที่สืบค้นและประมวลผลข้อมูล   ไลบรารีที่เลือกใช้บนฝั่งเซิร์ฟเวอร์จึงเป็น web framework อย่างง่ายคือ Flask ที่ใช้ร่วมกับฐานข้อมูล SQLite   ในขณะที่ฝั่ง workstation ที่สืบค้นและประมวลผลเลือกใช้เป็น pandas และ matplotlib โดยอาศัย Jupyter Notebook เป็นเครื่องมือ เพราะการแบ่งส่วนโค้ดออกเป็น cell ที่ทำหน้าที่เฉพาะ จะเหมาะกับการใช้งานจริงที่คนทำงานต้องปรับแต่งการวิเคราะห์ให้อยู่ในรูปแบบที่ต้องการ  ทั้งนี้การทดสอบเซิร์ฟเวอร์ใช้แอพพลิเคชัน Postman เป็นเครื่องมือเพราะสะดวกในการสั่ง run การเชื่อมต่อในรูปแบบ collection   การติดตั้งไลบรารี pandas jupyter และ matplotlib ใช้คำสั่ง pip

```
> pip install pandas jupyter matplotlib 
```

การเรียนรู้เริ่มจากส่วนโค้ดบนฝั่งเซิร์ฟเวอร์ที่เปิด URL ให้เข้าถึงได้ 3 ช่องทางคือ 
  - URL http://xxx.xxx.xxx.xxx:5000/ สำหรับให้ข้อมูล
  - URL http://xxx.xxx.xxx.xxx:5000/submit เป็นช่องทางรวบรวมข้อมูลจากอุปกรณ์ในสายการผลิต
  - URL http://xxx.xxx.xxx.xxx:5000/query เป็นช่องทางสำหรับ workstation ในการสืบค้นข้อมูลที่ต้องการ
  
เนื่องจากระบบ IT ในสายการผลิตของ SME มักเป็น Intranet จึงไม่ได้ลงรายละเอียดในส่วน security   ส่วนโค้ด template ในการให้บริการผ่าน URL และจัดเตรียมฐานข้อมูล คือ

```python
# prepare json, flask, sqlite libraries
import json
from flask import Flask, escape, request
import sqlite3

app = Flask(__name__)

# Default URL for basic information
@app.route('/')
def main():
    return "Hello, world"

# URL for data collection
@app.route('/submit')
def submit():
    id = request.args.get("id", "")
    result = {'status':'ERR'}
    return json.dumps(result)

# URL for data query
@app.route('/query')
def query():
    id = request.args.get("id", "")
    result = {'status':'ERR'}
    return json.dumps(result)

if __name__ == '__main__':
    conn = sqlite3.connect('nov15.db')
    c = conn.cursor()
    # SQL command to create table
    c.execute('''CREATE TABLE IF NOT EXISTS products (
        _id INTEGER PRIMARY KEY,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
        station INTEGER,
        product TEXT)''')
    conn.commit()
    conn.close()
    app.run('0.0.0.0')
```
	
เนื้อหาหลักของการเรียนรู้คือ แนวคิดในการทำงานของ web service เริ่มต้นจากการแยกแยะข้อมูลออกจากส่วน argument ของ GET request จากนั้นจึงประมวลผล (บันทึก/สืบค้น) แล้วส่งคำตอบกลับผ่านทาง JSON payload   การทดสอบด้วย Postman ทำให้ทดสอบรายการของ test case ต่างๆทั้งกรณี normal และ abnormal ได้สะดวก   รายละเอียดของการเขียนโค้ดดูได้จากคลิป
เนื้อหาอีกช่วงคือ การเขียนโค้ดบน Jupyter Notebook เพื่อส่ง GET request มาสืบค้นข้อมูลไปประมวลผล   ตัวอย่างที่เลือกมาแสดงในครั้งนี้คือ การใช้ conditional selection ของไลบรารี pandas ทำให้สามารถคัดแยกข้อมูลมาดูได้ง่ายขึ้น โดยไม่จำเป็นต้องเป็นผู้เชี่ยวชาญในการเขียนโค้ดประเภท SQL   ส่วนโค้ดตั้งต้นในการสืบค้นข้อมูลจากเซิร์ฟเวอร์ที่เตรียมไว้คือ

  - cell แรก เป็นการเตรียมไลบรารีที่เกี่ยวข้อง

```python
import pandas
import urllib.request
from datetime import datetime
import matplotlib.pyplot as plt
```

  - cell ที่สอง เป็นโค้ดสำหรับการสืบค้นผ่าน GET request
  
```python
id = 'P5678'
url = 'http://127.0.0.1:5000/query?id=%s'%(id)
resp = urllib.request.urlopen(url)
data = pandas.read_json(resp)
print(data)
```

## แอพพลิเคชันสำหรับพนักงานภาคสนาม
