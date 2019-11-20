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
    tag = request.args.get("tag", "")
    result = {'status':'ERR'}
    if station != "" and tag != "":        
        result['status'] = 'OK'
        station = int(station)
        conn = sqlite3.connect('nov15.db')
        c = conn.cursor()
        c.execute('''INSERT INTO products(station,tag) 
            VALUES (%d, "%s")'''%(station,tag))
        conn.commit()
        conn.close()
    return json.dumps(result)

# URL for data query
@app.route('/query')
def query():
    tag = request.args.get("tag", "")
    result = {'status':'ERR'}
    if tag != "":
        result['status'] = 'OK'
        conn = sqlite3.connect('nov15.db')
        c = conn.cursor()
        c.execute('''SELECT * FROM products WHERE tag = "%s"'''%(tag))
        result['tag'] = tag
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
             tag TEXT)''')
    conn.commit()
    conn.close()
    # start web service
    app.run('0.0.0.0')