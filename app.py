from flask import Flask, render_template, request

app = Flask(__name)

@app.route('/')
def index():
    return """
<!DOCTYPE html>
<html>
<head>
    <title>Python and HTML Example</title>
</head>
<body>
    <h1>Welcome to the Python and HTML Example</h1>
    <form action="/submit" method="POST">
        <label for="name">Enter your name:</label>
        <input type="text" id="name" name="name">
        <input type="submit" value="Submit">
    </form>
</body>
</html>
"""

@app.route('/submit', methods=['POST'])
def submit():
    if request.method == 'POST':
        name = request.form['name']
        return f'Hello, {name}!'

if __name__ == '__main__':
    app.run(debug=True)
