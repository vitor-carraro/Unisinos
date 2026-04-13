-- EXERCICIO 1: LIVROS

CREATE DATABASE BIBLIOTECA;

USE BIBLIOTECA;

CREATE TABLE
    LIVROS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        titulo VARCHAR(255) NOT NULL,
        isbn VARCHAR(20) UNIQUE,
        ano_publicacao INT,
        editora VARCHAR(255),
        numero_paginas INT,
        idioma VARCHAR(50),
        data_cadastro DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 2: ALUNOS

CREATE DATABASE ESCOLA_TECNICA;

USE ESCOLA_TECNICA;

CREATE TABLE
    ALUNOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        cpf VARCHAR(14) UNIQUE,
        dt_nascimento DATE,
        email VARCHAR(255),
        telefone VARCHAR(20),
        status VARCHAR(20) DEFAULT 'ativo',
        data_matricula DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 3: PRODUTOS

CREATE DATABASE LOJA_VIRTUAL;

USE LOJA_VIRTUAL;

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        descricao TEXT,
        preco DECIMAL(10, 2) NOT NULL,
        sku VARCHAR(50) UNIQUE,
        peso DECIMAL(10, 2),
        altura DECIMAL(10, 2),
        largura DECIMAL(10, 2),
        profundidade DECIMAL(10, 2),
        data_cadastro DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 4: FUNCIONARIOS

CREATE DATABASE EMPRESA;

USE EMPRESA;

CREATE TABLE
    FUNCIONARIOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        cpf VARCHAR(14) UNIQUE,
        cargo VARCHAR(50),
        data_contratacao DATE DEFAULT CURRENT_DATE,
        salario DECIMAL(10, 2),
        email_corporativo VARCHAR(255) UNIQUE,
        status VARCHAR(20) DEFAULT 'ativo'
    );


-- EXERCICIO 5: CURSOS

CREATE DATABASE PLATAFORMA_EDUCACIONAL;

USE PLATAFORMA_EDUCACIONAL;

CREATE TABLE
    CURSOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        descricao TEXT,
        carga_horaria INT,
        nivel VARCHAR(50),
        data_criacao DATE,
        ativo BOOLEAN DEFAULT TRUE
    );


-- EXERCICIO 6: CLIENTES

CREATE DATABASE SISTEMA_VENDAS;

USE SISTEMA_VENDAS;

CREATE TABLE
    CLIENTES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        cpf VARCHAR(14) UNIQUE,
        email VARCHAR(255),
        telefone VARCHAR(20),
        data_cadastro DATE,
        limite_credito DECIMAL(10, 2),
        status VARCHAR(20) DEFAULT 'ativo'
    );


-- EXERCICIO 7: FORNECEDORES

CREATE DATABASE GESTAO_FORNECEDORES;

USE GESTAO_FORNECEDORES;

CREATE TABLE
    FORNECEDORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        razao_social VARCHAR(255),
        cnpj VARCHAR(18) UNIQUE,
        nome_fantasia VARCHAR(255),
        telefone VARCHAR(20),
        email VARCHAR(255),
        endereco VARCHAR(255),
        data_cadastro DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 8: VEICULOS

CREATE DATABASE LOCADORA;

USE LOCADORA;

CREATE TABLE
    VEICULOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        marca VARCHAR(50),
        modelo VARCHAR(50),
        ano INT,
        placa VARCHAR(20) UNIQUE,
        quilometragem INT,
        status VARCHAR(20) DEFAULT 'disponível',
        data_aquisicao DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 9: DEPARTAMENTOS

CREATE DATABASE GESTAO_EMPRESARIAL;

USE GESTAO_EMPRESARIAL;

CREATE TABLE
    DEPARTAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        descricao TEXT,
        ramal VARCHAR(20),
        data_criacao DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 10: ESTOQUES

CREATE DATABASE GESTAO_ESTOQUE;

USE GESTAO_ESTOQUE;

CREATE TABLE
    ESTOQUES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        produto_id INT,
        quantidade INT,
        quantidade_minima INT,
        localizacao VARCHAR(255),
        data_atualizacao DATE DEFAULT CURRENT_DATE
    );


-- EXERCICIO 11: PROFESSORES

CREATE DATABASE UNIVERSIDADE;

USE UNIVERSIDADE;

CREATE TABLE
    PROFESSORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        cpf VARCHAR(14) UNIQUE,
        email VARCHAR(255),
        telefone VARCHAR(20),
        titulacao VARCHAR(50),
        area_atuacao VARCHAR(255),
        regime_trabalho VARCHAR(50),
        data_contratacao DATE DEFAULT CURRENT_DATE,
        status VARCHAR(20) DEFAULT 'ativo'
    );


-- EXERCICIO 12: TURMAS

USE UNIVERSIDADE;

CREATE TABLE
    TURMAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        codigo VARCHAR(20) UNIQUE,
        nome VARCHAR(255) NOT NULL,
        turno VARCHAR(20),
        capacidade INT,
        periodo_letivo VARCHAR(20),
        sala VARCHAR(20),
        data_inicio DATE,
        data_fim DATE,
        status VARCHAR(20) DEFAULT 'ativa'
    );


-- EXERCICIO 13: PAGAMENTOS

CREATE DATABASE FINANCEIRO;

USE FINANCEIRO;

CREATE TABLE
    PAGAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        descricao VARCHAR(255),
        tipo_pagamento VARCHAR(50),
        valor DECIMAL(10, 2),
        data_vencimento DATE,
        data_pagamento DATE,
        forma_pagamento VARCHAR(50),
        numero_documento VARCHAR(100),
        status VARCHAR(30),
        observacao TEXT
    );


-- EXERCICIO 14: CHAMADOS TECNICOS

CREATE DATABASE SUPORTE_EMPRESA;

USE SUPORTE_EMPRESA;

CREATE TABLE
    CHAMADOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        titulo VARCHAR(255),
        descricao TEXT,
        categoria VARCHAR(100),
        prioridade VARCHAR(30),
        status VARCHAR(30),
        data_abertura DATE,
        data_fechamento DATE,
        canal_abertura VARCHAR(50),
        responsavel VARCHAR(255)
    );


-- EXERCICIO 15: RESERVAS

CREATE DATABASE HOTELARIA;

USE HOTELARIA;

CREATE TABLE
    RESERVAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_nome VARCHAR(255),
        cpf_cliente VARCHAR(14),
        data_reserva DATE,
        data_checkin DATE,
        data_checkout DATE,
        numero_hospedes INT,
        tipo_acomodacao VARCHAR(100),
        valor_total DECIMAL(10, 2),
        status VARCHAR(30)
    );


-- EXERCICIO 16: AUTORES E LIVROS

CREATE DATABASE BIBLIOTECA_AUTORES;

USE BIBLIOTECA_AUTORES;

CREATE TABLE
    AUTORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255) NOT NULL,
        nacionalidade VARCHAR(100),
        data_nascimento DATE,
        site_oficial VARCHAR(255),
        biografia_resumida TEXT
    );

CREATE TABLE
    LIVROS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        titulo VARCHAR(255),
        isbn VARCHAR(20),
        ano_publicacao INT,
        editora VARCHAR(255),
        idioma VARCHAR(50),
        autor_id INT,
        FOREIGN KEY (autor_id) REFERENCES AUTORES (id)
    );


-- EXERCICIO 17: CLIENTES E PEDIDOS

CREATE DATABASE LOJA_PEDIDOS;

USE LOJA_PEDIDOS;

CREATE TABLE
    CLIENTES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        email VARCHAR(255),
        telefone VARCHAR(20),
        data_cadastro DATE
    );

CREATE TABLE
    PEDIDOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        data_pedido DATE,
        valor_total DECIMAL(10, 2),
        desconto DECIMAL(10, 2),
        frete DECIMAL(10, 2),
        forma_pagamento VARCHAR(50),
        status VARCHAR(30),
        observacao TEXT,
        FOREIGN KEY (cliente_id) REFERENCES CLIENTES (id)
    );


-- EXERCICIO 18: CATEGORIAS E PRODUTOS

CREATE DATABASE CATALOGO_LOJA;

USE CATALOGO_LOJA;

CREATE TABLE
    CATEGORIAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        descricao TEXT,
        categoria_pai INT,
        status VARCHAR(30),
        FOREIGN KEY (categoria_pai) REFERENCES CATEGORIAS (id)
    );

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        descricao TEXT,
        preco DECIMAL(10, 2),
        sku VARCHAR(50),
        marca VARCHAR(100),
        categoria_id INT,
        data_cadastro DATE,
        FOREIGN KEY (categoria_id) REFERENCES CATEGORIAS (id)
    );


-- EXERCICIO 19: DEPARTAMENTOS E FUNCIONARIOS

CREATE DATABASE EMPRESA_DEPARTAMENTOS;

USE EMPRESA_DEPARTAMENTOS;

CREATE TABLE
    DEPARTAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        sigla VARCHAR(20),
        ramal VARCHAR(20),
        centro_custo VARCHAR(50)
    );

CREATE TABLE
    FUNCIONARIOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        cargo VARCHAR(100),
        salario DECIMAL(10, 2),
        email_corporativo VARCHAR(255),
        departamento_id INT,
        data_admissao DATE,
        status VARCHAR(30),
        FOREIGN KEY (departamento_id) REFERENCES DEPARTAMENTOS (id)
    );


-- EXERCICIO 20: ALUNOS, CURSOS E MATRICULAS

CREATE DATABASE ACADEMICO;

USE ACADEMICO;

CREATE TABLE
    ALUNOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        email VARCHAR(255),
        status_academico VARCHAR(50)
    );

CREATE TABLE
    CURSOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        carga_horaria INT,
        nivel VARCHAR(50),
        status VARCHAR(30)
    );

CREATE TABLE
    MATRICULAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        aluno_id INT,
        curso_id INT,
        data_matricula DATE,
        situacao_matricula VARCHAR(50),
        percentual_conclusao DECIMAL(5, 2),
        FOREIGN KEY (aluno_id) REFERENCES ALUNOS (id),
        FOREIGN KEY (curso_id) REFERENCES CURSOS (id)
    );


-- EXERCICIO 21: PEDIDOS, PRODUTOS E ITENS_PEDIDO

CREATE DATABASE PEDIDOS_ITENS;

USE PEDIDOS_ITENS;

CREATE TABLE
    PEDIDOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        data_pedido DATE,
        status VARCHAR(30)
    );

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        preco DECIMAL(10, 2),
        sku VARCHAR(50)
    );

CREATE TABLE
    ITENS_PEDIDO (
        id INT PRIMARY KEY AUTO_INCREMENT,
        pedido_id INT,
        produto_id INT,
        quantidade INT,
        preco_unitario DECIMAL(10, 2),
        subtotal DECIMAL(10, 2),
        FOREIGN KEY (pedido_id) REFERENCES PEDIDOS (id),
        FOREIGN KEY (produto_id) REFERENCES PRODUTOS (id)
    );


-- EXERCICIO 22: MOTORISTAS E VEICULOS

CREATE DATABASE TRANSPORTADORA;

USE TRANSPORTADORA;

CREATE TABLE
    MOTORISTAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        cnh VARCHAR(30),
        categoria_cnh VARCHAR(10),
        validade_cnh DATE,
        telefone VARCHAR(20),
        status VARCHAR(30)
    );

CREATE TABLE
    VEICULOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        placa VARCHAR(20),
        modelo VARCHAR(100),
        marca VARCHAR(100),
        status VARCHAR(30),
        motorista_id INT,
        FOREIGN KEY (motorista_id) REFERENCES MOTORISTAS (id)
    );


-- EXERCICIO 23: CLIENTES E ENDERECOS

CREATE DATABASE CLIENTES_ENDERECOS;

USE CLIENTES_ENDERECOS;

CREATE TABLE
    CLIENTES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        email VARCHAR(255),
        telefone VARCHAR(20)
    );

CREATE TABLE
    ENDERECOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        tipo_endereco VARCHAR(50),
        logradouro VARCHAR(255),
        numero VARCHAR(20),
        complemento VARCHAR(100),
        bairro VARCHAR(100),
        cidade VARCHAR(100),
        estado VARCHAR(50),
        cep VARCHAR(10),
        principal BOOLEAN,
        FOREIGN KEY (cliente_id) REFERENCES CLIENTES (id)
    );


-- EXERCICIO 24: FORNECEDORES E PRODUTOS

CREATE DATABASE INDUSTRIA_COMPRAS;

USE INDUSTRIA_COMPRAS;

CREATE TABLE
    FORNECEDORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        razao_social VARCHAR(255),
        cnpj VARCHAR(18),
        telefone VARCHAR(20),
        email VARCHAR(255)
    );

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        descricao TEXT,
        sku VARCHAR(50),
        preco_custo DECIMAL(10, 2),
        preco_venda DECIMAL(10, 2),
        fornecedor_id INT,
        data_cadastro DATE,
        FOREIGN KEY (fornecedor_id) REFERENCES FORNECEDORES (id)
    );


-- EXERCICIO 25: PROFESSORES E CURSOS

CREATE DATABASE ENSINO_CURSOS;

USE ENSINO_CURSOS;

CREATE TABLE
    PROFESSORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        email VARCHAR(255),
        titulacao VARCHAR(100),
        area_atuacao VARCHAR(255)
    );

CREATE TABLE
    CURSOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        descricao TEXT,
        carga_horaria INT,
        nivel VARCHAR(50),
        professor_id INT,
        status VARCHAR(30),
        FOREIGN KEY (professor_id) REFERENCES PROFESSORES (id)
    );


-- EXERCICIO 26: HIERARQUIA DE FUNCIONARIOS

CREATE DATABASE HIERARQUIA_EMPRESA;

USE HIERARQUIA_EMPRESA;

CREATE TABLE
    FUNCIONARIOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        cargo VARCHAR(100),
        salario DECIMAL(10, 2),
        email_corporativo VARCHAR(255),
        data_admissao DATE,
        supervisor_id INT,
        status VARCHAR(30),
        FOREIGN KEY (supervisor_id) REFERENCES FUNCIONARIOS (id)
    );


-- EXERCICIO 27: CURSOS COM PRE-REQUISITO

CREATE DATABASE CURSOS_PRE_REQUISITO;

USE CURSOS_PRE_REQUISITO;

CREATE TABLE
    CURSOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        descricao TEXT,
        carga_horaria INT,
        nivel VARCHAR(50),
        pre_requisito_id INT,
        status VARCHAR(30),
        FOREIGN KEY (pre_requisito_id) REFERENCES CURSOS (id)
    );


-- EXERCICIO 28: PEDIDOS E PAGAMENTOS

CREATE DATABASE PEDIDOS_PAGAMENTOS;

USE PEDIDOS_PAGAMENTOS;

CREATE TABLE
    PEDIDOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        data_pedido DATE,
        valor_total DECIMAL(10, 2),
        status VARCHAR(30)
    );

CREATE TABLE
    PAGAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        pedido_id INT,
        valor_pago DECIMAL(10, 2),
        data_pagamento DATE,
        forma_pagamento VARCHAR(50),
        numero_transacao VARCHAR(100),
        status VARCHAR(30),
        observacao TEXT,
        FOREIGN KEY (pedido_id) REFERENCES PEDIDOS (id)
    );


-- EXERCICIO 29: CLIENTES, PRODUTOS E AVALIACOES

CREATE DATABASE AVALIACOES_LOJA;

USE AVALIACOES_LOJA;

CREATE TABLE
    CLIENTES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        email VARCHAR(255)
    );

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        sku VARCHAR(50),
        preco DECIMAL(10, 2)
    );

CREATE TABLE
    AVALIACOES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        produto_id INT,
        nota INT,
        comentario TEXT,
        data_avaliacao DATE,
        status_publicacao VARCHAR(30),
        FOREIGN KEY (cliente_id) REFERENCES CLIENTES (id),
        FOREIGN KEY (produto_id) REFERENCES PRODUTOS (id)
    );


-- EXERCICIO 30: HISTORICO ESCOLAR

CREATE DATABASE HISTORICO_ESCOLAR;

USE HISTORICO_ESCOLAR;

CREATE TABLE
    ALUNOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14)
    );

CREATE TABLE
    DISCIPLINAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        carga_horaria INT,
        ementa TEXT
    );

CREATE TABLE
    HISTORICOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        aluno_id INT,
        disciplina_id INT,
        ano_letivo INT,
        semestre INT,
        nota_final DECIMAL(5, 2),
        frequencia DECIMAL(5, 2),
        situacao VARCHAR(30),
        FOREIGN KEY (aluno_id) REFERENCES ALUNOS (id),
        FOREIGN KEY (disciplina_id) REFERENCES DISCIPLINAS (id)
    );


-- EXERCICIO 31: PROFESSORES E TURMAS

CREATE DATABASE TURMAS_PROFESSORES;

USE TURMAS_PROFESSORES;

CREATE TABLE
    PROFESSORES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        email VARCHAR(255),
        titulacao VARCHAR(100)
    );

CREATE TABLE
    TURMAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        codigo_turma VARCHAR(20),
        nome VARCHAR(255),
        turno VARCHAR(20),
        periodo_letivo VARCHAR(20),
        capacidade INT,
        professor_id INT,
        status VARCHAR(30),
        FOREIGN KEY (professor_id) REFERENCES PROFESSORES (id)
    );


-- EXERCICIO 32: TECNICOS E CHAMADOS

CREATE DATABASE CHAMADOS_TECNICOS;

USE CHAMADOS_TECNICOS;

CREATE TABLE
    TECNICOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        email VARCHAR(255),
        especialidade VARCHAR(100),
        nivel VARCHAR(50),
        status VARCHAR(30)
    );

CREATE TABLE
    CHAMADOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        titulo VARCHAR(255),
        descricao TEXT,
        prioridade VARCHAR(30),
        status VARCHAR(30),
        data_abertura DATE,
        data_fechamento DATE,
        tecnico_id INT,
        FOREIGN KEY (tecnico_id) REFERENCES TECNICOS (id)
    );


-- EXERCICIO 33: QUARTOS E RESERVAS

CREATE DATABASE HOTEL_QUARTOS;

USE HOTEL_QUARTOS;

CREATE TABLE
    QUARTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        numero VARCHAR(20),
        andar INT,
        tipo_quarto VARCHAR(100),
        capacidade INT,
        valor_diaria DECIMAL(10, 2),
        status VARCHAR(30)
    );

CREATE TABLE
    RESERVAS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_nome VARCHAR(255),
        cpf_cliente VARCHAR(14),
        data_checkin DATE,
        data_checkout DATE,
        numero_hospedes INT,
        quarto_id INT,
        valor_total DECIMAL(10, 2),
        status VARCHAR(30),
        FOREIGN KEY (quarto_id) REFERENCES QUARTOS (id)
    );


-- EXERCICIO 34: CLIENTES E PAGAMENTOS

CREATE DATABASE PAGAMENTOS_CLIENTES;

USE PAGAMENTOS_CLIENTES;

CREATE TABLE
    CLIENTES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        cpf VARCHAR(14),
        email VARCHAR(255)
    );

CREATE TABLE
    PAGAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        cliente_id INT,
        descricao VARCHAR(255),
        valor DECIMAL(10, 2),
        data_vencimento DATE,
        data_pagamento DATE,
        forma_pagamento VARCHAR(50),
        status VARCHAR(30),
        FOREIGN KEY (cliente_id) REFERENCES CLIENTES (id)
    );


-- EXERCICIO 35: PRODUTOS E ESTOQUES

CREATE DATABASE ESTOQUE_PRODUTOS;

USE ESTOQUE_PRODUTOS;

CREATE TABLE
    PRODUTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        nome VARCHAR(255),
        sku VARCHAR(50),
        marca VARCHAR(100),
        preco DECIMAL(10, 2)
    );

CREATE TABLE
    ESTOQUES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        produto_id INT,
        quantidade_atual INT,
        quantidade_minima INT,
        lote VARCHAR(50),
        data_validade DATE,
        localizacao VARCHAR(255),
        data_atualizacao DATE,
        FOREIGN KEY (produto_id) REFERENCES PRODUTOS (id)
    );


-- EXERCICIO 36: ADICIONAR TELEFONE_SECUNDARIO

ALTER TABLE CLIENTES
ADD COLUMN telefone_secundario VARCHAR(20);


-- EXERCICIO 37: ADICIONAR OBSERVACAO EM PEDIDOS

ALTER TABLE PEDIDOS
ADD COLUMN observacao TEXT;


-- EXERCICIO 38: ALTERAR TIPO DA COLUNA PRECO

ALTER TABLE PRODUTOS MODIFY COLUMN preco DECIMAL(10, 2);


-- EXERCICIO 39: RENOMEAR COLUNA DESCRICAO PARA DETALHES

ALTER TABLE PRODUTOS
RENAME COLUMN descricao TO detalhes;


-- EXERCICIO 40: TORNAR NOME OBRIGATORIO

ALTER TABLE ALUNOS MODIFY COLUMN nome VARCHAR(255) NOT NULL;


-- EXERCICIO 41: ADICIONAR CHAVE ESTRANGEIRA EM PRODUTOS

ALTER TABLE PRODUTOS ADD CONSTRAINT fk_produtos_categorias FOREIGN KEY (categoria_id) REFERENCES CATEGORIAS (id);


-- EXERCICIO 42: CRIAR INDICE EM CLIENTES(NOME)

CREATE INDEX idx_clientes_nome ON CLIENTES (nome);


-- EXERCICIO 43: RENOMEAR FUNCIONARIOS PARA COLABORADORES

RENAME TABLE FUNCIONARIOS TO COLABORADORES;


-- EXERCICIO 44: REMOVER COLUNA CODIGO_ANTIGO

ALTER TABLE PRODUTOS
DROP COLUMN codigo_antigo;


-- EXERCICIO 45: EXCLUIR TABELA TEMPORARIA

DROP TABLE backup_clientes_teste;


-- EXERCICIO 46: ADICIONAR DATA_MODIFICACAO

ALTER TABLE PRODUTOS
ADD COLUMN data_modificacao DATETIME;


-- EXERCICIO 47: RENOMEAR PEDIDOS_VENDA PARA PEDIDOS

RENAME TABLE pedidos_venda TO pedidos;


-- EXERCICIO 48: LOGS_SISTEMA

CREATE DATABASE LOGS_CORPORATIVOS;

USE LOGS_CORPORATIVOS;

CREATE TABLE
    LOGS_SISTEMA (
        id INT PRIMARY KEY AUTO_INCREMENT,
        usuario VARCHAR(255),
        acao VARCHAR(100),
        tabela_afetada VARCHAR(100),
        registro_afetado INT,
        data_evento DATETIME,
        ip_origem VARCHAR(45),
        descricao TEXT
    );


-- EXERCICIO 49: ADICIONAR CAMPO ATIVO

ALTER TABLE CLIENTES
ADD COLUMN ativo BOOLEAN DEFAULT TRUE;

ALTER TABLE PRODUTOS
ADD COLUMN ativo BOOLEAN DEFAULT TRUE;

ALTER TABLE FORNECEDORES
ADD COLUMN ativo BOOLEAN DEFAULT TRUE;


-- EXERCICIO 50: AUDITORIA

CREATE DATABASE AUDITORIA_SISTEMA;

USE AUDITORIA_SISTEMA;

CREATE TABLE
    AUDITORIA (
        id INT PRIMARY KEY AUTO_INCREMENT,
        usuario_responsavel VARCHAR(255),
        tipo_operacao VARCHAR(50),
        nome_tabela VARCHAR(100),
        id_registro INT,
        valor_anterior TEXT,
        valor_novo TEXT,
        data_alteracao DATETIME,
        maquina_origem VARCHAR(100),
        observacao TEXT
    );