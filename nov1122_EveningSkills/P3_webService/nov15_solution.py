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
    station = request.args.get("station", "")
    id = request.args.get("id", "")
    result = {'status':'ERR'}
    if station != "" and id != "":        
        result['status'] = 'OK'
        station = int(station)
        conn = sqlite3.connect('nov15.db')
        c = conn.cursor()
        c.execute('''INSERT INTO products(station,product) 
            VALUES (%d, "%s")'''%(station,id))
        conn.commit()
        conn.close()
    return json.dumps(result)

# URL for data query
@app.route('/query')
def query():
    id = request.args.get("id", "")
    result = {'status':'ERR'}
    if id != "":
        result['status'] = 'OK'
        conn = sqlite3.connect('nov15.db')
        c = conn.cursor()
        c.execute('''SELECT * FROM products WHERE product = "%s"'''%(id))
        result['id'] = id
        result['station'] = []
        result['timestamp'] = []
        rows = c.fetchall()
        for row in rows:
            result['station'].append(row[2])
            result['timestamp'].append(row[1])
        conn.commit()
        conn.close()        
    return json.dumps(result)

if __name__ == '__main__':
    conn = sqlite3.connect('nov15.db')
    c = conn.cursor()
    # Create table
    c.execute('''CREATE TABLE IF NOT EXISTS products
             (_id INTEGER PRIMARY KEY, 
             timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
             station INTEGER,
             product TEXT)''')
    conn.commit()
    conn.close()
    app.run('0.0.0.0')
    