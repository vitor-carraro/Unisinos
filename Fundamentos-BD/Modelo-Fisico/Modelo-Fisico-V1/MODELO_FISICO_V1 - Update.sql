USE MODELO_FISICO_V1;

-- =====================================================
-- EXERCÍCIO 6 – SITUAÇÃO ACADÊMICA
-- Alterar um aluno de Ativo para Formado
-- =====================================================
UPDATE ALUNOS
SET
    status = 'Formado'
WHERE
    id = 1
    AND status = 'Ativo';

-- =====================================================
-- EXERCÍCIO 7 – REAJUSTE SALARIAL
-- Aumento de 8% para funcionários com status Ativo
-- =====================================================
UPDATE FUNCIONARIOS
SET
    salario = salario * 1.08
WHERE
    status = 'Ativo';

-- =====================================================
-- EXERCÍCIO 8 – AJUSTE DE PREÇOS
-- Aumento de 5% nos produtos da marca Dell
-- =====================================================
UPDATE PRODUTOS
SET
    preco = preco * 1.05
WHERE
    marca = 'Dell';

-- =====================================================
-- EXERCÍCIO 9 – CONTROLE DE ESTOQUE
-- Só funciona se a tabela ESTOQUES existir
-- e possuir os campos quantidade_atual e data_validade
-- =====================================================
UPDATE ESTOQUES
SET
    quantidade_atual = 0
WHERE
    data_validade < CURDATE ();

-- =====================================================
-- EXERCÍCIO 10 – RECLASSIFICAÇÃO DE CURSOS
-- Inativar cursos com carga horária inferior a 20 horas
-- =====================================================
UPDATE CURSOS
SET
    status = 'Inativo'
WHERE
    carga_horaria < 20;

-- =====================================================
-- Observações rápidas:
-- no ESTOQUES, o produto id = 4 foi inserido com validade antiga para ser zerado no exercício 9 e removido no 13;
-- em CHAMADOS, há registros fechados antigos para o exercício 14;
-- em PAGAMENTOS, há registros não quitados e vencidos há mais de 6 meses para o exercício 15.
-- =====================================================
-- =====================================================
-- TABELA 6: ESTOQUES
-- =====================================================
CREATE TABLE
    ESTOQUES (
        id INT PRIMARY KEY AUTO_INCREMENT,
        produto_id INT NOT NULL,
        quantidade_atual INT NOT NULL,
        quantidade_minima INT,
        local_armazenamento VARCHAR(100),
        data_validade DATE,
        FOREIGN KEY (produto_id) REFERENCES PRODUTOS (id)
    );

-- =====================================================
-- TABELA 7: CHAMADOS
-- =====================================================
CREATE TABLE
    CHAMADOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        titulo VARCHAR(255) NOT NULL,
        descricao TEXT,
        status VARCHAR(20) NOT NULL,
        data_abertura DATE NOT NULL,
        data_fechamento DATE
    );

-- =====================================================
-- TABELA 8: PAGAMENTOS
-- =====================================================
CREATE TABLE
    PAGAMENTOS (
        id INT PRIMARY KEY AUTO_INCREMENT,
        descricao VARCHAR(255) NOT NULL,
        valor DECIMAL(10, 2) NOT NULL,
        data_vencimento DATE NOT NULL,
        data_pagamento DATE,
        quitado BOOLEAN NOT NULL DEFAULT FALSE
    );

-- =====================================================
-- DADOS DE EXEMPLO - ESTOQUES
-- Usa os produtos já inseridos anteriormente
-- =====================================================
INSERT INTO
    ESTOQUES (produto_id, quantidade_atual, quantidade_minima, local_armazenamento, data_validade)
VALUES
    (1, 15, 5, 'Corredor A', '2026-12-31'),
    (2, 8, 3, 'Corredor B', '2025-12-01'),
    (3, 20, 4, 'Corredor C', '2026-10-10'),
    (4, 6, 2, 'Corredor D', '2024-11-15'),
    (5, 12, 3, 'Corredor E', '2026-08-20');

-- =====================================================
-- DADOS DE EXEMPLO - CHAMADOS
-- Alguns fechados há mais de 365 dias
-- =====================================================
INSERT INTO
    CHAMADOS (titulo, descricao, status, data_abertura, data_fechamento)
VALUES
    ('Erro no login', 'Usuário não consegue acessar o sistema.', 'Fechado', '2024-01-10', '2024-01-15'),
    ('Falha no pagamento', 'Compra recusada indevidamente.', 'Aberto', '2026-03-05', NULL),
    ('Lentidão no sistema', 'Aplicação com alto tempo de resposta.', 'Fechado', '2025-01-20', '2025-02-01'),
    ('Bug na emissão de relatório', 'PDF gerado com campos incorretos.', 'Fechado', '2023-10-10', '2023-10-20');

-- =====================================================
-- DADOS DE EXEMPLO - PAGAMENTOS
-- Alguns vencidos há mais de 6 meses e não quitados
-- =====================================================
INSERT INTO
    PAGAMENTOS (descricao, valor, data_vencimento, data_pagamento, quitado)
VALUES
    ('Mensalidade da plataforma', 199.90, '2025-06-01', NULL, FALSE),
    ('Assinatura anual', 899.00, '2025-11-15', NULL, FALSE),
    ('Compra de equipamento', 3500.00, '2026-02-10', '2026-02-09', TRUE),
    ('Licença de software', 1200.00, '2024-12-01', NULL, FALSE),
    ('Serviço de manutenção', 650.00, '2026-03-25', NULL, FALSE);

-- =====================================================
-- EXERCÍCIO 9 – CONTROLE DE ESTOQUE
-- Definir quantidade_atual = 0 para itens vencidos
-- =====================================================
UPDATE ESTOQUES
SET
    quantidade_atual = 0
WHERE
    data_validade < CURDATE ();