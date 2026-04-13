USE Biblioteca;

-- 1. Leitor + Carteira (1:1)
SELECT 
    l.idLeitor,
    l.nome AS nome_leitor,
    c.idCarteira,
    c.dtEmissao
FROM Leitor l
JOIN Carteira c ON c.idLeitor = l.idLeitor;

-- 2. Livro + Editora (1:N)
SELECT 
    li.idLivro,
    li.titulo,
    e.nome AS editora
FROM Livro li
JOIN Editora e ON li.idEditora = e.idEditora;

-- 3. Livro + Autor (N:N via tabela associativa)
SELECT 
    li.titulo,
    a.nome AS autor
FROM Livro li
JOIN Livro_Autor la ON la.idLivro = li.idLivro
JOIN Autor a ON a.idAutor = la.idAutor;

-- 4. Livro + Exemplar (1:N)
SELECT 
    li.titulo,
    ex.idExemplar,
    ex.status
FROM Livro li
JOIN Exemplar ex ON ex.idLivro = li.idLivro;

-- 5. Empréstimo completo (integra tudo)
SELECT 
    emp.idEmprestimo,
    l.nome AS leitor,
    li.titulo AS livro,
    ex.idExemplar,
    emp.dtEmprestimo,
    emp.dtDevolucao
FROM Emprestimo emp
JOIN Leitor l ON emp.idLeitor = l.idLeitor
JOIN Exemplar ex ON emp.idExemplar = ex.idExemplar
JOIN Livro li ON ex.idLivro = li.idLivro;

-- 6. Consulta consolidada (visão geral do sistema)
SELECT 
    l.nome AS leitor,
    li.titulo,
    a.nome AS autor,
    e.nome AS editora,
    emp.dtEmprestimo
FROM Emprestimo emp
JOIN Leitor l ON emp.idLeitor = l.idLeitor
JOIN Exemplar ex ON emp.idExemplar = ex.idExemplar
JOIN Livro li ON ex.idLivro = li.idLivro
JOIN Editora e ON li.idEditora = e.idEditora
JOIN Livro_Autor la ON li.idLivro = la.idLivro
JOIN Autor a ON la.idAutor = a.idAutor;