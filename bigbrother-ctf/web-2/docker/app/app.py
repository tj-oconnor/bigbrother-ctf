from flask import Flask, request, render_template, make_response,render_template_string

app = Flask(__name__)

@app.route('/admin')
def cookie_checker():
    admin_cookie = request.cookies.get('admin')
    
    if admin_cookie == 'true':
        flag=render_template('index.html',message="You are admin! Here's the flag: bbctf{D0_n0t_Eat_y0ur_br0th3r's_cooki3s}")
        return flag
    else:
        response = make_response(render_template('index.html',message='The Ministry only allows administrators inside the store.'))
        response.set_cookie('admin', 'false')
        return response

@app.route('/robots.txt')
def robots():
    robots_txt = "User-agent: *\nDisallow: /admin"
    return robots_txt
    
@app.route('/')
def index_page():
    index_page = render_template('index.html',message='There store is locked. You must ask the robots if you want anything more from the Ministry.')
    return index_page

        
if __name__ == '__main__':
    app.run(host="0.0.0.0")
