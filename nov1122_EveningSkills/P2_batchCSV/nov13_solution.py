# import os, csv, datetime and openpyxl libraries
import os
import csv
from datetime import datetime
from openpyxl import Workbook

folder = './data'

# function to scan folder for xlsx and csv files
def scan_folder(folder):
    print(os.getcwd())
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
    id_list = []
    for f in files:
        fname = './data/' + f
        with open(fname, newline='') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                #print(f,row['timestamp'], row['id'])
                if row['id'] not in id_list:
                    id_list.append(row['id'])
                    machine = f.split('.')[0]
                    new_record = {'id':row['id'], machine:row['timestamp']}
                    records.append(new_record)
                else:
                    for record in records:
                        if record['id'] == row['id']:
                            machine = f.split('.')[0]
                            record[machine] = row['timestamp']
                            break
    return records

def gen_sumfile(records):
    # create new workbook and prepare worksheet
    wb = Workbook()
    ws1 = wb.active
    ws1.title = 'Raw data'
    ws1['A1'] = 'id'
    ws1['B1'] = 'station1'
    ws1['C1'] = 'station2'
    for record in records:
        ws1.append([record['id'],record['station1'],record['station2'], '=A1'])
    ws2 = wb.create_sheet(title='Summary')
    ws2['A1'] = 'Number of products'
    ws2['B1'] = len(records)
    ws2['A2'] = 'Period of Station1 (hour)'
    ws2['A3'] = 'Period of Station1 (minute)'
    ws2['A4'] = 'Period of Station1 (second)'
    fmt = '%Y-%m-%d %H:%M:%S.%f'
    t1st = datetime.strptime( records[0]['station1'], fmt )
    tend = datetime.strptime( records[-1]['station1'], fmt )
    tdiff = tend - t1st
    hours, remainder = divmod(tdiff.seconds, 3600)
    minutes, seconds = divmod(remainder, 60)
    ws2['B2'] = hours
    ws2['B3'] = minutes
    ws2['B4'] = seconds
    wb.save("summary.xlsx")    

# main program
if __name__=='__main__':
    files = scan_folder(folder)
    if len(files['CSV']) > 0:
        records = extract_csv(files['CSV'])
    gen_sumfile(records)