"#Python is a protocol orienated lang; every top-level function or syntax has a corresponding duner method implemented;" 

import sqlite3

def dml(db: str)->None:
    with sqlite3.connect(db) as conn:
        cur = conn.cursor()

        cur.execute('CREATE TABLE points(x int, y int);')
        cur.execute('INSERT INTO points(x, y) VALUES(1, 1);')
        cur.execute('INSERT INTO points(x, y) VALUES(1, 1);')
        cur.execute('INSERT INTO points(x, y) VALUES(1, 1);')
        cur.execute('INSERT INTO points(x, y) VALUES(1, 1);')
        
        for row in cur.execute('SELECT x, y FROM points;'):
            print(row)

        for row in cur.execute('SELECT SUM(x + y) FROM points;'):
            print(row)
            
        cur.execute('DROP TABLE points;')

if __name__ == "__main__":
    db = 'test.db'
    dml(db)