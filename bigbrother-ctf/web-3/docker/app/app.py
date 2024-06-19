import sqlite3
from flask import Flask, request, render_template,render_template_string

app = Flask(__name__)

@app.route('/')
def search():
    # Get the search query from the request
    db = sqlite3.connect('test.db')
    cursor = db.cursor()
    
    query = request.args.get('q')
    try:
        if query:
            cursor.execute('SELECT * FROM BBCTF WHERE name == "'+str(query)+'"')
            results = cursor.fetchall()
            message=''
            for result in results:
                message+=str(result[2])
            return render_template('index.html',message=message)
        else:
            return render_template('index.html')
    except:
        return render_template('index.html',message='You have broken the Ministrys Database; Keep Trying.')
        
if __name__ == '__main__':
    app.run(host="0.0.0.0")

