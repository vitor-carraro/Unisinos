CREATE DATABASE Exercicio1;

USE Exercicio1;

CREATE TABLE
    Convenios (
        idConvenio INT AUTO_INCREMENT PRIMARY KEY,
        nome VARCHAR(100) not null,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
    );

CREATE TABLE
    Medicos (
        idMedico INT auto_increment primary key,
        nome varchar(50) not null,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
    );

CREATE TABLE
    Pacientes (
        idPaciente int auto_increment primary key,
        dtNascimento date not null,
        nome varchar(50) not null,
        diversos varchar(50),
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
        idConvenio int,
        CONSTRAINT fkConvenioPacientes FOREIGN KEY (idConvenio) REFERENCES Convenios (idConvenio)
    );

CREATE TABLE
    Consultas (
        idConsulta INT auto_increment primary key,
        dtConsulta date not null,
        diagnostico varchar(100),
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
        idPaciente INT not null,
        idMedico INT not null,
        CONSTRAINT fk_paciente_consultas FOREIGN KEY (idPaciente) REFERENCES Pacientes (idPaciente),
        CONSTRAINT fk_medico_consultas FOREIGN KEY (idMedico) REFERENCES Medicos (idMedico)
    );

CREATE TABLE
    Exames (
        idExame INT auto_increment primary key,
        dtExame date not null,
        resultados varchar(100),
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
        idConsulta INT not null,
        CONSTRAINT fk_consultas_exames FOREIGN KEY (idConsulta) REFERENCES Consultas (idConsulta)
    );

INSERT INTO
    Convenios (nome)
VALUES
    ('Unimed'),
    ('Bradesco Saúde'),
    ('SulAmérica');

INSERT INTO
    Medicos (nome)
VALUES
    ('Dr. João Silva'),
    ('Dra. Maria Souza'),
    ('Dr. Carlos Lima');

INSERT INTO
    Pacientes (dtNascimento, nome, diversos, idConvenio)
VALUES
    (
        '1995-03-10',
        'Vitor Alves',
        'Alergia a penicilina',
        1
    ),
    ('1988-07-22', 'Ana Costa', NULL, 2),
    ('2000-01-15', 'Lucas Pereira', 'Diabético', 1),
    ('1992-11-30', 'Mariana Rocha', NULL, 3);

INSERT INTO
    Consultas (dtConsulta, diagnostico, idPaciente, idMedico)
VALUES
    ('2026-04-01', 'Gripe', 1, 1),
    ('2026-04-02', 'Dor de cabeça', 2, 2),
    ('2026-04-03', 'Check-up', 3, 1),
    ('2026-04-04', 'Dor abdominal', 4, 3);

INSERT INTO
    Exames (dtExame, idConsulta, resultados)
VALUES
    ('2026-04-01', 1, 'Inflamação leve'),
    ('2026-04-02', 2, 'Sem alterações'),
    ('2026-04-03', 3, 'Exames normais'),
    ('2026-04-04', 4, 'Suspeita de gastrite');

SELECT
    p.nome AS paciente,
    m.nome AS medico,
    c.dtConsulta,
    c.diagnostico
FROM
    Consultas c
    JOIN Pacientes p ON p.idPaciente = c.idPaciente
    JOIN Medicos m ON m.idMedico = c.idMedico
ORDER BY
    c.dtConsulta;