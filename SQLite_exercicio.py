import sqlite3

def printar_livros(texto, fetchall):
    for tupla in fetchall:
        print(f"{texto} {tupla}\n")

conn = sqlite3.connect("livraria.db")

cursor = conn.cursor()

cursor.execute(""" CREATE TABLE IF NOT EXISTS livros(
id INTEGER PRIMARY KEY AUTOINCREMENT,
titulo TEXT,
autor TEXT,
ano_publicacao INTEGER,
genero TEXT) """)

add_livros = [
("O Senhor dos Anéis: A Sociedade do Anel", "J.R.R. Tolkien", 1954, "Fantasia, Aventura"),
("A Guerra dos Tronos", "George R.R. Martin", 1996, "Fantasia, Política, Drama"),
("O Nome do Vento", "Patrick Rothfuss", 2007, "Fantasia, Aventura, Ficção"),
("Eragon (Ciclo da Herança, #1)", "Christopher Paolini",  2002, "Fantasia, Aventura, Ação"),
("Neuromancer", "William Gibson", 1984, "Ficção Científica, Cyberpunk")]

cursor.executemany(""" INSERT INTO livros(titulo, autor, ano_publicacao, genero)
VALUES(?,?,?,?)""", add_livros)

conn.commit()

#Consulte todos os livros que foram publicados após o ano de 2000.
cursor.execute("SELECT * FROM livros WHERE ano_publicacao > 2000")
printar_livros("Publicação > que 2000:", cursor.fetchall())

#Consulte os livros de um autor específico.
cursor.execute("SELECT * FROM livros WHERE autor == 'J.R.R. Tolkien'")
printar_livros("Autor é J.R.R Tolkien:", cursor.fetchall())

#Consulte o título e o autor do livro mais recente.
cursor.execute("SELECT titulo, autor FROM livros ORDER BY ano_publicacao DESC LIMIT 1")
print("Mais Recente:", cursor.fetchall())


#Atualize o ano de publicação de um livro de sua escolha.
cursor.execute("UPDATE livros SET ano_publicacao = 3000 WHERE ano_publicacao == 2002")
conn.commit()
cursor.execute("SELECT * FROM livros")
printar_livros("Todos:", cursor.fetchall())

#Exclua um livro da tabela.
cursor.execute("DELETE FROM livros WHERE id == 2")
conn.commit()
printar_livros("Todos:", cursor.fetchall())

cursor.execute("DROP TABLE IF EXISTS livros") #Limpar Tabela
conn.commit()



conn.close()
