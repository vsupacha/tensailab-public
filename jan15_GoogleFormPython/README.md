# Using Python with Google Form

ไฟล์ answer.py จะเป็นโค้ดภาษา Python สำหรับแยกแยะข้อมูลจากผลการสำรวจทาง Google Forms  การทำงานของโค้ดตัวอย่างจะเริ่มจากการนำเข้าข้อมูลจากไฟล์ CSV ที่บันทึกจาก Google Drive กำจัดข้อมูลซ้ำซ้อนแล้วจึงแยกประเด็นออกมา โดยมีขั้นตอนดังนี้ 

## การนำเข้าข้อมูล

1. การประกาศให้รองรับภาษาไทย (UTF-8) 
```python
#-*-coding: utf-8 -*-
```

2. การอ่านและแยกแยะข้อมูลจะใช้แพคเกจ re เพื่อตรวจจับข้อความที่ล้อมด้วย " " 
```python
f = open(u'แบบสอบถามเพื่อจัดทำหลักสูตรไฟฟ้า.csv')
txt = f.read()
matches = re.findall(r'"([^"]*)"', txt)
header = [matches.pop(0) for i in range(10)]
```

3. บันทึกในรูปแบบของ list ของ dict โดยกำหนด key ขึ้นใหม่
```python
idx = ['timestamp','year','studyMajor','workMajor','jobDescription','engineerLicense','licenseBenefit','benefitSubject','needSubject','nonengineerSubject']
lines = []
while len(matches) > 0:
    data = {}
    for i in range(10):
        data[idx[i]] = matches.pop(0)
    lines.append(data)
```

## การกำจัดข้อมูลซ้ำซ้อน

1. ลบข้อมูล timestamp
``` python
duplines = list(lines)
for line in duplines:
    del line['timestamp']
```

2. ตรวจความซ้ำซ้อนจากคำตอบที่เหมือนกันหมด โดยแปลงข้อมูลในรูป set 
``` python
uniquelines = [dict(t) for t in set([tuple(line.items()) for line in duplines])]
```

## การแยกแยะข้อมูลตามคำถาม

1. สัดส่วนของนักศึกษาที่เรียนสาขาไฟฟ้า XX แล้วได้ทำงาน**ตรงสาขา** (หรือ**ต่างสาขา**)
``` python
PowerWorkPower = []
PowerWorkNotPower = []
for line in uniquelines:
    if (line['studyMajor'] == 'ไฟฟ้ากำลัง'):
        if line['workMajor'] == 'ไฟฟ้ากำลัง':
            PowerWorkPower.append(line['jobDescription'])
        else:
            PowerWorkNotPower.append(line['jobDescription'])
``` 

2. ประโยชน์ของการมีใบประกอบวิชาชีพวิศวกรรมควบคุม
``` python
licenseBenefit = []
for line in uniquelines:
    if (line['engineerLicense'] == 'มี'):
        licenseBenefit.append(line['licenseBenefit'])
```

3. ความรู้ที่เรียนแล้วได้ใช้ประโยชน์ในหน้าที่การงาน ซึ่งจะพบปัญหาในประเด็นที่เป็นคำถามแบบเปิด จึงมีการพิมพ์ภาษาไทยผสมภาษาอังกฤษ รวมทั้งอาจมีหลายคำตอบในช่องเดียว   เทคนิคที่ใช้คือ การเชื่อมต่อข้อมูลทั้งหมดเข้าด้วยกันโดยคั่นด้วย , จากนั้นใช้การแยกออกด้วย , สุดท้ายจึงใช้ map() ในการตรวจสอบว่ามี **keyword** อยู่ในคำตอบไหม
``` python
keywords = ['การวัด', 'measurement', 'Measurement', 'ควบคุม', 'Control', 'control']
benefitSubject = []
for line in uniquelines:
    benefitSubject.append(line['benefitSubject'])
allSubjects = ','.join(benefitSubject)
allSubjects = allSubjects.replace('\n', ',')
allSubjects = allSubjects.split(',')
allSubjects = map(lambda x: x.strip(), allSubjects)
counts = map(lambda x: [x.count(k) for k in keywords], allSubjects)
counts = map(lambda x: (sum(x) > 0), counts)
```

