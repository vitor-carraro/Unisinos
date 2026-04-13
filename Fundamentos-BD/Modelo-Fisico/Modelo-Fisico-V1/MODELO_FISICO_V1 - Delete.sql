USE MODELO_FISICO_V1;

-- =====================================================
-- EXERCÍCIO 11 – REMOÇÃO DE PRODUTOS INVÁLIDOS
-- Excluir produtos com preço igual a zero
-- =====================================================
DELETE FROM PRODUTOS
WHERE
  preco = 0;

-- =====================================================
-- EXERCÍCIO 12 – LIMPEZA DE FUNCIONÁRIOS DESLIGADOS
-- Excluir colaboradores com status Demitido
-- =====================================================
DELETE FROM FUNCIONARIOS
WHERE
  status = 'Demitido';

-- =====================================================
-- EXERCÍCIO 13 – ESTOQUE ZERADO
-- Só funciona se a tabela ESTOQUES existir
-- =====================================================
DELETE FROM ESTOQUES
WHERE
  quantidade_atual = 0;

-- =====================================================
-- EXERCÍCIO 14 – CHAMADOS ANTIGOS
-- Só funciona se a tabela CHAMADOS existir
-- Campos esperados: status, data_fechamento
-- =====================================================
DELETE FROM CHAMADOS
WHERE
  status = 'Fechado'
  AND data_fechamento < DATE_SUB (CURDATE (), INTERVAL 365 DAY);

-- =====================================================
-- EXERCÍCIO 15 – PAGAMENTOS OBSOLETOS
-- Só funciona se a tabela PAGAMENTOS existir
-- Campos esperados: data_vencimento, quitado
-- =====================================================
DELETE FROM PAGAMENTOS
WHERE
  data_vencimento < DATE_SUB (CURDATE (), INTERVAL 6 MONTH)
  AND quitado = FALSE;

-- =====================================================
-- EXERCÍCIO 13 – ESTOQUE ZERADO
-- Excluir registros cujo estoque ficou zerado
-- =====================================================
DELETE FROM ESTOQUES
WHERE
  quantidade_atual = 0;

-- =====================================================
-- EXERCÍCIO 14 – CHAMADOS ANTIGOS
-- Excluir chamados fechados há mais de 365 dias
-- =====================================================
DELETE FROM CHAMADOS
WHERE
  status = 'Fechado'
  AND data_fechamento < DATE_SUB (CURDATE (), INTERVAL 365 DAY);

-- =====================================================
-- EXERCÍCIO 15 – PAGAMENTOS OBSOLETOS
-- Excluir pagamentos vencidos há mais de 6 meses e não quitados
-- =====================================================
DELETE FROM PAGAMENTOS
WHERE
  data_vencimento < DATE_SUB (CURDATE (), INTERVAL 6 MONTH)
  AND quitado = FALSE;