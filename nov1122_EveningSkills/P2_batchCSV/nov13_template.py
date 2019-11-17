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
    for f in files:
        print(f + ' is CSV file')
    return records

# main program
if __name__=='__main__':
    files = scan_folder(folder)
    if len(files['CSV']) > 0:
        records = extract_csv(files['CSV'])