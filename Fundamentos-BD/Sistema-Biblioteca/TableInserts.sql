USE Biblioteca;

-- Editora
INSERT INTO
    Editora (nome)
VALUES
    ('Editora Atlas'),
    ('Companhia das Letras'),
    ('Saraiva'),
    ('Novatec'),
    ('Pearson'),
    ('O Reilly'),
    ('Alta Books'),
    ('Campus'),
    ('Elsevier'),
    ('Bookman');

-- Leitor
INSERT INTO
    Leitor (nome, email, telefone)
VALUES
    ('João Silva', 'joao@email.com', '51999910001'),
    ('Maria Souza', 'maria@email.com', '51999910002'),
    ('Carlos Lima', 'carlos@email.com', '51999910003'),
    ('Ana Paula', 'ana@email.com', '51999910004'),
    ('Bruno Costa', 'bruno@email.com', '51999910005'),
    ('Fernanda Alves', 'fernanda@email.com', '51999910006'),
    ('Lucas Pereira', 'lucas@email.com', '51999910007'),
    ('Juliana Rocha', 'juliana@email.com', '51999910008'),
    ('Rafael Martins', 'rafael@email.com', '51999910009'),
    ('Patricia Gomes', 'patricia@email.com', '51999910010');

-- Carteira (1:1 com Leitor)
INSERT INTO
    Carteira (dtEmissao, idLeitor)
VALUES
    ('2024-01-01', 1),
    ('2024-01-02', 2),
    ('2024-01-03', 3),
    ('2024-01-04', 4),
    ('2024-01-05', 5),
    ('2024-01-06', 6),
    ('2024-01-07', 7),
    ('2024-01-08', 8),
    ('2024-01-09', 9),
    ('2024-01-10', 10);

-- Autor
INSERT INTO
    Autor (nome)
VALUES
    ('Machado de Assis'),
    ('Clarice Lispector'),
    ('George Orwell'),
    ('J.K. Rowling'),
    ('Stephen King'),
    ('Agatha Christie'),
    ('Dan Brown'),
    ('Yuval Harari'),
    ('Robert Martin'),
    ('Martin Fowler');

-- Livro
INSERT INTO
    Livro (titulo, anoPublicacao, idEditora)
VALUES
    ('Dom Casmurro', 1899, 1),
    ('A Hora da Estrela', 1977, 2),
    ('1984', 1949, 3),
    ('Harry Potter', 1997, 4),
    ('O Iluminado', 1977, 5),
    ('Assassinato no Expresso do Oriente', 1934, 6),
    ('Código Da Vinci', 2003, 7),
    ('Sapiens', 2011, 8),
    ('Clean Code', 2008, 9),
    ('Refactoring', 1999, 10);

-- Livro_Autor (N:N)
INSERT INTO
    Livro_Autor (idLivro, idAutor)
VALUES
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4),
    (5, 5),
    (6, 6),
    (7, 7),
    (8, 8),
    (9, 9),
    (10, 10);

-- Exemplar
INSERT INTO
    Exemplar (status, idLivro)
VALUES
    ('Disponível', 1),
    ('Disponível', 2),
    ('Emprestado', 3),
    ('Disponível', 4),
    ('Emprestado', 5),
    ('Disponível', 6),
    ('Disponível', 7),
    ('Emprestado', 8),
    ('Disponível', 9),
    ('Disponível', 10);

-- Emprestimo
INSERT INTO
    Emprestimo (dtEmprestimo, dtDevolucao, idLeitor, idExemplar)
VALUES
    ('2024-03-01', '2024-03-10', 1, 3),
    ('2024-03-02', '2024-03-11', 2, 5),
    ('2024-03-03', '2024-03-12', 3, 8),
    ('2024-03-04', '2024-03-13', 4, 1),
    ('2024-03-05', '2024-03-14', 5, 2),
    ('2024-03-06', '2024-03-15', 6, 4),
    ('2024-03-07', '2024-03-16', 7, 6),
    ('2024-03-08', '2024-03-17', 8, 7),
    ('2024-03-09', '2024-03-18', 9, 9),
    ('2024-03-10', '2024-03-19', 10, 10);