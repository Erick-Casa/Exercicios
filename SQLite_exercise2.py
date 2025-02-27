import sqlite3

def print_rows(context, fetchall): #Clear print function for sql table's rows
    print(f"{context}")
    for rows in fetchall:
        print(" ".join(map(str, rows)))
    print("")

conn = sqlite3.connect("school.db")

cursor = conn.cursor()

cursor.execute("""CREATE TABLE IF NOT EXISTS Students(
id INTEGER PRIMARY KEY AUTOINCREMENT,
name TEXT,
age INTEGER,
course TEXT,
grade REAL)""")

students_list = [
("Alice", 20, "Engineering", 8.5),
("Bruce", 22, "Medicine", 7.2),
("Carl", 19, "Law", 5.8),
("Daniel", 21, "Computer Science", 9.0),
("Eva", 23, "Architecture", 6.4)
                 ]

cursor.executemany("""INSERT INTO Students(name,age,course,grade)
                   VALUES(?,?,?,?)""", students_list)
conn.commit()


cursor.execute("SELECT * FROM Students") #Show all registered students
print_rows("Registered Students: ",cursor.fetchall())

cursor.execute("SELECT * FROM Students WHERE grade > 7") #Show all student with grade higher than 7
print_rows("Students with grade 7 or higher:", cursor.fetchall())

cursor.execute("UPDATE Students SET grade = 8 WHERE id = 2") #Update one student's grade
cursor.execute("DELETE FROM Students WHERE id == 1") #Delete row from student id 1
conn.commit() #Update and Delete's commit

cursor.execute("SELECT * FROM Students") #Show all registered students
print_rows("Registered Students: ",cursor.fetchall())

cursor.execute("SELECT COUNT(*) FROM Students")
print_rows("All Students:", cursor.fetchall())

cursor.execute("DROP TABLE IF EXISTS Students") #Clear Table
conn.commit() #Clear Table Commit

conn.close()
