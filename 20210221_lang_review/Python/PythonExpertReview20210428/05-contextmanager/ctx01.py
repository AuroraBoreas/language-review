"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 


"""
[ resource management ]
===
* concept: resource management or resource control; it is similar to "resource management is initialization" in C++;
* pattern:
__enter__
__exit__

===
"""
import sqlite3

with sqlite3.connect('test.db') as conn:
    cur = conn.cursor()

    # __enter__
    cur.execute('CREATE TABLE points(x int, y int);')
    
    # operations in btwn
    cur.execute('INSERT INTO points(x, y) VALUES(1, 1);')
    cur.execute('INSERT INTO points(x, y) VALUES(1, 2);')
    cur.execute('INSERT INTO points(x, y) VALUES(2, 1);')
    cur.execute('INSERT INTO points(x, y) VALUES(2, 2);')

    for row in cur.execute('SELECT x, y FROM points;'):
        print(row)

    for row in cur.execute('SELECT sum(x * y) FROM points;'):
        print(row)

    # __exit__
    cur.execute('DROP TABLE points;')