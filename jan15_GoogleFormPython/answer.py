#!/usr/bin/python
#-*-coding: utf-8 -*-
import re

idx = ['timestamp','year','studyMajor','workMajor','jobDescription','engineerLicense','licenseBenefit','benefitSubject','needSubject','nonengineerSubject']

def printList(l):
    for i in l:
        print i

# 1. import data
f = open(u'แบบสอบถามเพื่อจัดทำหลักสูตรไฟฟ้า.csv')
txt = f.read()
matches = re.findall(r'"([^"]*)"', txt)
header = [matches.pop(0) for i in range(10)]
lines = []
while len(matches) > 0:
    data = {}
    for i in range(10):
        data[idx[i]] = matches.pop(0)
    lines.append(data)

# remove duplicates
duplines = list(lines)
for line in duplines:
    del line['timestamp']
print 'จำนวนข้อมูล', len(duplines)
uniquelines = [dict(t) for t in set([tuple(line.items()) for line in duplines])]
print 'จำนวนข้อมูลไม่ซ้ำ', len(uniquelines)

# Trend of power major
PowerWorkPower = []
PowerWorkNotPower = []
for line in uniquelines:
    if (line['studyMajor'] == 'ไฟฟ้ากำลัง'):
        if line['workMajor'] == 'ไฟฟ้ากำลัง':
            PowerWorkPower.append(line['jobDescription'])
        else:
            PowerWorkNotPower.append(line['jobDescription'])
print 'คนเรียนไฟฟ้ากำลังและทำงานตรงสาย', len(PowerWorkPower)
print 'คนเรียนไฟฟ้ากำลังแต่ทำงานไม่ตรงสาย', len(PowerWorkNotPower)

# Trend of communication major
CommWorkComm = []
CommWorkNotComm = []
for line in uniquelines:
    if (line['studyMajor'] == 'ไฟฟ้าสื่อสาร'):
        if line['workMajor'] == 'ไฟฟ้าสื่อสาร':
            CommWorkComm.append(line['jobDescription'])
        else:
            CommWorkNotComm.append(line['jobDescription'])
print 'คนเรียนไฟฟ้าสื่อสารและทำงานตรงสาย', len(CommWorkComm)
print 'คนเรียนไฟฟ้าสื่อสารแต่ทำงานไม่ตรงสาย', len(CommWorkNotComm)


# Trend of electronics major
ElecWorkElec = []
ElecWorkNotElec = []
for line in uniquelines:
    if (line['studyMajor'] == 'อิเล็กทรอนิกส์'):
        if line['workMajor'] == 'อิเล็กทรอนิกส์':
            ElecWorkElec.append(line['jobDescription'])
        else:
            ElecWorkNotElec.append(line['jobDescription'])
print 'คนเรียนอิเล็กทรอนิกส์และทำงานตรงสาย', len(ElecWorkElec)
print 'คนเรียนอิเล็กทรอนิกส์แต่ทำงานไม่ตรงสาย', len(ElecWorkNotElec)

# Trend of control major
ControlWorkControl = []
ControlWorkNotControl = []
for line in uniquelines:
    if (line['studyMajor'] == 'ระบบควบคุม'):
        if line['workMajor'] == 'ระบบควบคุม':
            ControlWorkControl.append(line['jobDescription'])
        else:
            ControlWorkNotControl.append(line['jobDescription'])
print 'คนเรียนระบบควบคุมและทำงานตรงสาย', len(ControlWorkControl)
print 'คนเรียนระบบควบคุมแต่ทำงานไม่ตรงสาย', len(ControlWorkNotControl)

# Benefits of engineering license
licenseBenefit = []
for line in uniquelines:
    if (line['engineerLicense'] == 'มี'):
        licenseBenefit.append(line['licenseBenefit'])
printList(licenseBenefit)

# Grouping benefit subjects
keywords = ['Power', 'power', 'high', 'High', 'กำลัง', 'protect', 'Protect', 'relay', 'Relay']
#keywords = ['wireless', 'Wireless', 'comm', 'Comm', 'network', 'Network', 'mobile', 'Mobile']
#keywords = ['opto', 'Opto', 'optic', 'Optic','nano','photo']
#keywords = ['การวัด', 'measurement', 'Measurement', 'ควบคุม', 'Control', 'control']
#keywords = ['embedded', 'Embedded', 'micro', 'microcontroller', 'ไมโคร']
#keywords = ['โปรแกรม', 'ภาษา', 'programming', 'Programming']
#keywords = ['PLC', 'plc', 'Plc', 'auto']
#keywords = ['MATLAB', 'matlab', 'Matlab']
printList(keywords)

benefitSubject = []
for line in uniquelines:
    benefitSubject.append(line['benefitSubject'])
allSubjects = ','.join(benefitSubject)
allSubjects = allSubjects.replace('\n', ',')
allSubjects = allSubjects.split(',')
allSubjects = map(lambda x: x.strip(), allSubjects)
counts = map(lambda x: [x.count(k) for k in keywords], allSubjects)
counts = map(lambda x: (sum(x) > 0), counts)
print 'เรียนแล้วใช้ประโยชน์', sum(counts)

# Need to learn subjects
needSubject = []
for line in uniquelines:
    needSubject.append(line['needSubject'])
allSubjects = ','.join(needSubject)
allSubjects = allSubjects.replace('\n', ',')
allSubjects = allSubjects.split(',')
allSubjects = map(lambda x: x.strip(), allSubjects)
counts = map(lambda x: [x.count(k) for k in keywords], allSubjects)
counts = map(lambda x: (sum(x) > 0), counts)
print 'อยากเรียน', sum(counts)
