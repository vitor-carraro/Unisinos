-- =====================================================
-- AULA 13/04/2026 - BLOCO 1
-- Banco único com tabelas criadas do zero
-- =====================================================

DROP DATABASE IF EXISTS MODELO_FISICO_V1;
CREATE DATABASE MODELO_FISICO_V1;
USE MODELO_FISICO_V1;

-- =====================================================
-- TABELA 1: LIVROS
-- Baseada na estrutura original de LIVROS do script 06/04/2026.
-- =====================================================

CREATE TABLE LIVROS (
    id INT PRIMARY KEY AUTO_INCREMENT,
    titulo VARCHAR(255) NOT NULL,
    isbn VARCHAR(20) NOT NULL UNIQUE,
    ano_publicacao INT,
    editora VARCHAR(255),
    numero_paginas INT,
    idioma VARCHAR(50),
    tipo VARCHAR(20) NOT NULL,              -- físico / digital
    area VARCHAR(100),                      -- tecnologia, literatura etc.
    data_cadastro DATE 
);

-- =====================================================
-- TABELA 2: ALUNOS
-- Baseada na estrutura original de ALUNOS do script 06/04/2026.
-- =====================================================

CREATE TABLE ALUNOS (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    cpf VARCHAR(14) UNIQUE,
    dt_nascimento DATE,
    email VARCHAR(255),
    telefone VARCHAR(20),
    status VARCHAR(20) DEFAULT 'Ativo',
    data_matricula DATE 
);

-- =====================================================
-- TABELA 3: PRODUTOS
-- Baseada na estrutura original de PRODUTOS do script 06/04/2026,
-- com acréscimo de MARCA.
-- =====================================================

CREATE TABLE PRODUTOS (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    descricao TEXT,
    preco DECIMAL(10,2) NOT NULL,
    sku VARCHAR(50) NOT NULL UNIQUE,
    marca VARCHAR(100) NOT NULL,
    peso DECIMAL(10,2),
    altura DECIMAL(10,2),
    largura DECIMAL(10,2),
    profundidade DECIMAL(10,2),
    data_cadastro DATE
);

-- =====================================================
-- TABELA 4: FUNCIONARIOS
-- Baseada na estrutura original de FUNCIONARIOS do script 06/04/2026,
-- com acréscimo de tipo_contrato e data_demissao.
-- =====================================================

CREATE TABLE FUNCIONARIOS (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    cargo VARCHAR(100),
    tipo_contrato VARCHAR(10) NOT NULL,     -- CLT / PJ
    data_contratacao DATE,
    data_demissao DATE,
    salario DECIMAL(10,2),
    email_corporativo VARCHAR(255) UNIQUE,
    status VARCHAR(20) DEFAULT 'Ativo'
);

-- =====================================================
-- TABELA 5: CURSOS
-- Baseada na estrutura original de CURSOS do script 06/04/2026,
-- com acréscimo de pre_requisito textual.
-- =====================================================

CREATE TABLE CURSOS (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    descricao TEXT,
    carga_horaria INT,
    nivel VARCHAR(50),
    pre_requisito VARCHAR(255),
    data_criacao DATE,
    status VARCHAR(20) DEFAULT 'Ativo'
);

-- =====================================================
-- EXERCÍCIO 1 – BIBLIOTECA UNIVERSITÁRIA
-- Condições:
-- - 5 registros
-- - pelo menos 2 digitais
-- - títulos diferentes
-- - ISBNs únicos
-- - pelo menos 1 da área de tecnologia
-- =====================================================

INSERT INTO LIVROS
(titulo, isbn, ano_publicacao, editora, numero_paginas, idioma, tipo, area)
VALUES
('Algoritmos e Estruturas de Dados', '9788575221019', 2022, 'Alta Books', 520, 'Português', 'Digital', 'Tecnologia'),
('Banco de Dados Relacionais', '9788536509804', 2021, 'Érica', 410, 'Português', 'Físico', 'Tecnologia'),
('Literatura Brasileira Contemporânea', '9786555601202', 2020, 'Atlas', 280, 'Português', 'Físico', 'Literatura'),
('Introdução à Pesquisa Científica', '9788597012345', 2019, 'Saraiva', 190, 'Português', 'Digital', 'Educação'),
('História da Filosofia Moderna', '9788526814505', 2018, 'LTC', 360, 'Português', 'Físico', 'Filosofia');

-- =====================================================
-- EXERCÍCIO 2 – CADASTRO ACADÊMICO
-- Condições:
-- - 6 alunos
-- - 3 Ativo
-- - 1 Trancado
-- - 1 email não informado
-- - 1 telefone não informado
-- =====================================================

INSERT INTO ALUNOS
(nome, cpf, dt_nascimento, email, telefone, status)
VALUES
('Ana Beatriz Souza',   '111.111.111-01', '2002-03-15', 'ana.souza@email.com',     '(51)99999-1001', 'Ativo'),
('Bruno Henrique Lima', '111.111.111-02', '2001-07-22', 'bruno.lima@email.com',    '(51)99999-1002', 'Ativo'),
('Carla Mendes Rocha',  '111.111.111-03', '2003-01-10', NULL,                       '(51)99999-1003', 'Ativo'),
('Diego Alves Pereira', '111.111.111-04', '2000-11-05', 'diego.pereira@email.com', NULL,             'Trancado'),
('Eduarda Martins',     '111.111.111-05', '2002-08-30', 'eduarda@email.com',       '(51)99999-1005', 'Formado'),
('Felipe Gomes Silva',  '111.111.111-06', '2001-05-18', 'felipe@email.com',        '(51)99999-1006', 'Cancelado');

-- =====================================================
-- EXERCÍCIO 3 – CATÁLOGO DE PRODUTOS
-- Condições:
-- - 5 produtos
-- - preços variados
-- - marcas distintas
-- - 1 descrição nula
-- - 1 peso nulo
-- =====================================================

INSERT INTO PRODUTOS
(nome, descricao, preco, sku, marca, peso, altura, largura, profundidade)
VALUES
('Mouse Gamer RGB', 'Mouse óptico com sensor de alta precisão.', 129.90, 'SKU001', 'Logitech', 0.35, 4.50, 7.00, 12.00),
('Teclado Mecânico TKL', 'Teclado compacto com switches mecânicos.', 289.50, 'SKU002', 'Redragon', 0.90, 3.50, 14.00, 36.00),
('Monitor 24 Polegadas', NULL, 899.99, 'SKU003', 'LG', 3.20, 42.00, 54.00, 18.00),
('Notebook Ultrafino', 'Notebook 14" com SSD de 512GB.', 3599.00, 'SKU004', 'Dell', 1.80, 22.00, 32.00, 1.90),
('Headset Bluetooth', 'Headset sem fio com cancelamento de ruído.', 449.00, 'SKU005', 'JBL', 0.28, 18.00, 16.00, 8.00);

-- =====================================================
-- EXERCÍCIO 4 – RECURSOS HUMANOS
-- Condições:
-- - 4 funcionários
-- - 2 CLT
-- - 1 PJ
-- - 1 Inativo
-- - pelo menos 1 com data_demissao preenchida
-- =====================================================

INSERT INTO FUNCIONARIOS
(nome, cpf, cargo, tipo_contrato, data_contratacao, data_demissao, salario, email_corporativo, status)
VALUES
('Gabriel Nunes',   '222.222.222-01', 'Analista de Sistemas',     'CLT', '2026-02-03', CURDATE(),    5200.00, 'gabriel@empresa.com', 'Ativo'),
('Helena Duarte',   '222.222.222-02', 'Assistente Administrativo','CLT', '2026-02-10', CURDATE(),    3100.00, 'helena@empresa.com',  'Ativo'),
('Igor Martins',    '222.222.222-03', 'Desenvolvedor Backend',    'PJ',  '2026-03-01', CURDATE(),    6800.00, 'igor@empresa.com',    'Ativo'),
('Juliana Freitas', '222.222.222-04', 'Analista de RH',           'CLT', '2025-10-15', '2026-03-20', 4300.00, 'juliana@empresa.com', 'Inativo');

-- =====================================================
-- EXERCÍCIO 5 – PLATAFORMA DE CURSOS
-- Condições:
-- - 4 cursos
-- - níveis diferentes
-- - 1 com pré-requisito textual
-- - 1 Inativo
-- =====================================================

INSERT INTO CURSOS
(nome, descricao, carga_horaria, nivel, pre_requisito, data_criacao, status)
VALUES
('Lógica de Programação', 'Fundamentos de algoritmos e raciocínio lógico.', 40, 'Iniciante', NULL, '2026-04-01', 'Ativo'),
('Banco de Dados SQL', 'Modelagem relacional, SQL e normalização.', 60, 'Intermediário', 'Conhecimentos básicos de lógica de programação.', '2026-04-02', 'Ativo'),
('Desenvolvimento Web Full Stack', 'Frontend, backend e integração com APIs.', 100, 'Avançado', 'Experiência prévia com HTML, CSS e JavaScript.', '2026-04-03', 'Ativo'),
('Segurança da Informação', 'Noções de proteção de dados e redes.', 50, 'Intermediário', NULL, '2026-04-04', 'Inativo');

-- =====================================================
-- CONSULTAS PARA CONFERÊNCIA
-- =====================================================

SELECT * FROM LIVROS;
SELECT * FROM ALUNOS;
SELECT * FROM PRODUTOS;
SELECT * FROM FUNCIONARIOS;
SELECT * FROM CURSOS;