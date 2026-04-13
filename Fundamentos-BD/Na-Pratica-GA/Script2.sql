USE escola;

INSERT INTO
    Professor (IDProfessor, NomeProfessor, Sexo, DataNascimento)
VALUES
    (1, 'Carlos Silva', 'M', '1980-05-10'),
    (2, 'Ana Souza', 'F', '1985-08-15'),
    (3, 'Marcos Lima', 'M', '1979-11-20'),
    (4, 'Fernanda Rocha', 'F', '1990-03-12'),
    (5, 'Ricardo Alves', 'M', '1982-07-01'),
    (6, 'Juliana Costa', 'F', '1988-09-25'),
    (7, 'Paulo Mendes', 'M', '1975-01-30'),
    (8, 'Camila Ferreira', 'F', '1992-06-18'),
    (9, 'Roberto Nunes', 'M', '1983-12-05'),
    (10, 'Patricia Gomes', 'F', '1987-04-22');

INSERT INTO
    Sala (IDSala, Nome)
VALUES
    (1, 'Sala A101'),
    (2, 'Sala A102'),
    (3, 'Sala B201'),
    (4, 'Sala B202'),
    (5, 'Laboratorio 1'),
    (6, 'Laboratorio 2'),
    (7, 'Sala C301'),
    (8, 'Sala C302'),
    (9, 'Auditorio'),
    (10, 'Sala D401');

INSERT INTO
    Disciplina (
        IDDisciplina,
        NomeDisciplina,
        CargaHoraria,
        NumeroCreditos,
        IDProfessor
    )
VALUES
    (1, 'Matematica', 60, 4, 1),
    (2, 'Portugues', 60, 4, 2),
    (3, 'Historia', 40, 3, 3),
    (4, 'Geografia', 40, 3, 4),
    (5, 'Fisica', 60, 4, 5),
    (6, 'Quimica', 60, 4, 6),
    (7, 'Biologia', 60, 4, 7),
    (8, 'Informatica', 80, 5, 8),
    (9, 'Sociologia', 40, 2, 9),
    (10, 'Filosofia', 40, 2, 10);

INSERT INTO
    Turma (IDTurma, Horario, Data, IDProfessor, IDSala)
VALUES
    (1, '08:00:00', '2026-02-10', 1, 1),
    (2, '09:40:00', '2026-02-10', 2, 2),
    (3, '11:00:00', '2026-02-11', 3, 3),
    (4, '13:30:00', '2026-02-11', 4, 4),
    (5, '15:00:00', '2026-02-12', 5, 5),
    (6, '16:20:00', '2026-02-12', 6, 6),
    (7, '18:00:00', '2026-02-13', 7, 7),
    (8, '19:20:00', '2026-02-13', 8, 8),
    (9, '20:40:00', '2026-02-14', 9, 9),
    (10, '21:30:00', '2026-02-14', 10, 10);

INSERT INTO
    Aluno (IDMatricula, Nome, CPF)
VALUES
    (1, 'Joao Pedro', 11111111111),
    (2, 'Maria Clara', 22222222222),
    (3, 'Lucas Martins', 33333333333),
    (4, 'Beatriz Lima', 44444444444),
    (5, 'Gabriel Souza', 55555555555),
    (6, 'Larissa Alves', 66666666666),
    (7, 'Felipe Costa', 77777777777),
    (8, 'Amanda Rocha', 88888888888),
    (9, 'Thiago Ferreira', 99999999999),
    (10, 'Julia Gomes', 10101010101);

INSERT INTO
    Matricula (IDMatricula, IDTurma, Data, Situacao, Nota)
VALUES
    (1, 1, '2026-02-15', 'Ativa', 8.50),
    (2, 2, '2026-02-15', 'Ativa', 7.80),
    (3, 3, '2026-02-16', 'Ativa', 9.00),
    (4, 4, '2026-02-16', 'Trancada', 6.50),
    (5, 5, '2026-02-17', 'Ativa', 8.90),
    (6, 6, '2026-02-17', 'Ativa', 7.20),
    (7, 7, '2026-02-18', 'Concluida', 9.50),
    (8, 8, '2026-02-18', 'Ativa', 8.00),
    (9, 9, '2026-02-19', 'Ativa', 7.60),
    (10, 10, '2026-02-19', 'Concluida', 9.10);

INSERT INTO
    TurmaDisciplina (IDDisciplina, IDTurma, DataCadastro)
VALUES
    (1, 1, '2026-02-01'),
    (2, 2, '2026-02-01'),
    (3, 3, '2026-02-02'),
    (4, 4, '2026-02-02'),
    (5, 5, '2026-02-03'),
    (6, 6, '2026-02-03'),
    (7, 7, '2026-02-04'),
    (8, 8, '2026-02-04'),
    (9, 9, '2026-02-05'),
    (10, 10, '2026-02-05');