import sqlite3
import requests
import json

DB_ADDRESS = "../TriviaServer/OurDB.sqlite"

def connect_to_db(db):
    conn = None
    try:
        conn = sqlite3.connect(db)
    except Exception as e:
        print(e)
    
    return conn

def get_data_from_site(url):
    data = requests.get(url)
    data = data.text.replace("&quot;",'``')
    data = data.replace("&#039","`")
    return json.loads(data)

def insert_to_db(cur,data):
    incorrect = data["incorrect_answers"]
    sql_query = '''INSERT INTO Questions(Question,Category,Difficulty,Correct_Ans,Ans2,Ans3,Ans4) Values(\"{}\",\"{}\",\"{}\",\"{}\",\"{}\",\"{}\",\"{}\")'''.format(data["question"],data["category"],data["difficulty"],data["correct_answer"],incorrect[0],incorrect[1],incorrect[2])
    print(sql_query)
    cur.execute(sql_query)
    
def main():
    db_connection = connect_to_db(DB_ADDRESS)
    data = get_data_from_site(input())
    if data['response_code'] != 0:
        print("error has occurred")
        exit()
    
    questions = data['results']
    cur = db_connection.cursor()
    for question in questions:
        insert_to_db(cur,question)
        db_connection.commit()
        
    cur.close()
    db_connection.commit()
    print("that's it mate")
if __name__ == "__main__":
    main()
