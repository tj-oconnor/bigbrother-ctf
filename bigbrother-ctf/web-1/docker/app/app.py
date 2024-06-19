import os
from flask import Flask, request, render_template

app = Flask(__name__)

# The challenge URL
@app.route('/', methods=['GET', 'POST'])
def ping():
    output = ""
    if request.method == 'POST':
        # Get the URL to ping from the form data
        url = request.form['url']
        
        if url:
            # Execute the ping command and store the output
            command = 'ping -c 1 ' + url
            output = os.popen(command).read()

    # Render the template with the output
    return render_template('ping.html', output=output)

if __name__ == '__main__':
    app.run(host='0.0.0.0')
