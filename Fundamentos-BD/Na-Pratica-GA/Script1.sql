CREATE DATABASE escola;

USE escola;

CREATE TABLE
    Professor (
        IDProfessor INT PRIMARY KEY,
        NomeProfessor VARCHAR(40) NOT NULL,
        Sexo VARCHAR(1) NOT NULL,
        DataNascimento DATE NOT NULL
    );

CREATE TABLE
    Sala (IDSala INT PRIMARY KEY, Nome VARCHAR(40) NOT NULL);

CREATE TABLE
    Disciplina (
        IDDisciplina INT PRIMARY KEY,
        NomeDisciplina VARCHAR(40) NOT NULL,
        CargaHoraria INT NOT NULL,
        NumeroCreditos INT NOT NULL,
        IDProfessor INT NOT NULL,
        CONSTRAINT fk_disciplina_professor FOREIGN KEY (IDProfessor) REFERENCES Professor (IDProfessor)
    );

CREATE TABLE
    Turma (
        IDTurma INT PRIMARY KEY,
        Horario TIME NOT NULL,
        Data DATE NOT NULL,
        IDProfessor INT NOT NULL,
        IDSala INT NOT NULL,
        CONSTRAINT fk_turma_professor FOREIGN KEY (IDProfessor) REFERENCES Professor (IDProfessor),
        CONSTRAINT fk_turma_sala FOREIGN KEY (IDSala) REFERENCES Sala (IDSala)
    );

CREATE TABLE
    Aluno (
        IDMatricula INT PRIMARY KEY,
        Nome VARCHAR(40) NOT NULL,
        CPF BIGINT NOT NULL UNIQUE
    );

CREATE TABLE
    Matricula (
        IDMatricula INT PRIMARY KEY,
        IDTurma INT NOT NULL,
        Data DATE NOT NULL,
        Situacao VARCHAR(40) NOT NULL,
        Nota DECIMAL(10, 2),
        CONSTRAINT fk_matricula_aluno FOREIGN KEY (IDMatricula) REFERENCES Aluno (IDMatricula),
        CONSTRAINT fk_matricula_turma FOREIGN KEY (IDTurma) REFERENCES Turma (IDTurma)
    );

CREATE TABLE
    TurmaDisciplina (
        IDDisciplina INT NOT NULL,
        IDTurma INT NOT NULL,
        DataCadastro DATE NOT NULL,
        PRIMARY KEY (IDDisciplina, IDTurma),
        CONSTRAINT fk_turmadisciplina_disciplina FOREIGN KEY (IDDisciplina) REFERENCES Disciplina (IDDisciplina),
        CONSTRAINT fk_turmadisciplina_turma FOREIGN KEY (IDTurma) REFERENCES Turma (IDTurma)
    );