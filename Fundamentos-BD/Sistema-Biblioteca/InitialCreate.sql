CREATE DATABASE Biblioteca;

USE Biblioteca;

CREATE TABLE
    Leitor (
        idLeitor INT AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(100) NOT NULL,
        email VARCHAR(100),
        telefone VARCHAR(20)
    );

CREATE TABLE
    Carteira (
        idCarteira INT AUTO_INCREMENT PRIMARY KEY,
        dtEmissao DATE,
        idLeitor INT UNIQUE,
        FOREIGN KEY (idLeitor) REFERENCES Leitor (idLeitor)
    );

CREATE TABLE
    Editora (
        idEditora INT AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(100) NOT NULL
    );

CREATE TABLE
    Livro (
        idLivro INT AUTO_INCREMENT PRIMARY KEY,
        titulo VARCHAR(150) NOT NULL,
        anoPublicacao INT,
        idEditora INT,
        FOREIGN KEY (idEditora) REFERENCES Editora (idEditora)
    );

CREATE TABLE
    Autor (
        idAutor INT AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(100) NOT NULL
    );

CREATE TABLE
    Livro_Autor (
        idLivro INT,
        idAutor INT,
        PRIMARY KEY (idLivro, idAutor),
        FOREIGN KEY (idLivro) REFERENCES Livro (idLivro),
        FOREIGN KEY (idAutor) REFERENCES Autor (idAutor)
    );

CREATE TABLE
    Exemplar (
        idExemplar INT AUTO_INCREMENT PRIMARY KEY,
        status VARCHAR(50),
        idLivro INT,
        FOREIGN KEY (idLivro) REFERENCES Livro (idLivro)
    );

CREATE TABLE
    Emprestimo (
        idEmprestimo INT AUTO_INCREMENT PRIMARY KEY,
        dtEmprestimo DATE,
        dtDevolucao DATE,
        idLeitor INT,
        idExemplar INT,
        FOREIGN KEY (idLeitor) REFERENCES Leitor (idLeitor),
        FOREIGN KEY (idExemplar) REFERENCES Exemplar (idExemplar)
    );