from flask import Flask, render_template, request
from jinja2 import Template
import csv

def read_csv(filename):
    data = []
    with open(filename, newline='') as file:
        reader = csv.reader(file)
        for row in reader:
            data.append([float(cell) for cell in row])
    return data

def calculate_average(v):
    return sum(v) / len(v)


app= Flask(__name__)
@app.route('/')
def index():
    return render_template('Cetaceans_SP.html')

@app.route('/', methods=['POST'])
def getvalue ():
    data = read_csv(request.form['file-upload'])
    n = len(data)
    last_21_days = [data[i][3] for i in range(n - 1, n - 22, -1)]
    last_3_days = [data[i][3] for i in range(n - 1, n - 4, -1)]
    avg_last_21_days = calculate_average(last_21_days)
    avg_last_3_days = calculate_average(last_3_days)
    if avg_last_3_days > avg_last_21_days:
        updown='UP'
        highest_so_far = max(last_21_days)
        currntpri=data[n-1][3]
        exeppric=highest_so_far
    else:
        updown='DOWN'
        lowest_so_far = min(last_21_days)
        currntpri=data[n-1][3]
        exeppric=lowest_so_far


    return render_template('result.html',n=updown,c=currntpri,e=exeppric)

if __name__ == '__main__':
    app.run(debug=True)







