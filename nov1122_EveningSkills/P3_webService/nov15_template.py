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