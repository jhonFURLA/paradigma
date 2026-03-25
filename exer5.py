# ==========================================
# ESTOQUE NO ESCOPO PRINCIPAL
# ==========================================
estoque = [100, 200, 300]

print("Estoque original:", estoque)


# ==========================================
# FUNÇÃO COM EFEITO COLATERAL
# ==========================================
def aplicar_desconto(lista, desconto):
    """
    Esta função recebe uma lista e modifica diretamente seus elementos.

    IMPORTANTE:
    - 'lista' NÃO é uma cópia
    - 'lista' referencia o MESMO objeto em memória
    """
    for i in range(len(lista)):
        lista[i] -= desconto  # mutação direta do objeto


# ==========================================
# CHAMADA DA FUNÇÃO
# ==========================================
aplicar_desconto(estoque, 10)

print("Estoque após desconto:", estoque)