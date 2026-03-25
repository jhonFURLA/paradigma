def linha_de_montagem(total_pecas):
    """
    Gerador que processa peças uma a uma.
    A cada chamada de next(), processa uma peça e suspende o estado.
    """

    for i in range(1, total_pecas + 1):
        # Simula processamento da peça
        print(f"Processando peça {i}/{total_pecas}...")

        # Suspende a execução, salvando o estado local
        yield f"Peça {i} pronta"

    print("Todas as peças foram processadas!")

# ==========================================
# USO DO GERADOR
# ==========================================
linha = linha_de_montagem(5)  # cria o gerador para 5 peças

print(next(linha))  # Processa a primeira peça
print(next(linha))  # Processa a segunda
print(next(linha))  # Processa a terceira

# Pode continuar chamando next() a qualquer momento
for resultado in linha:
    print(resultado)  # Processa as peças restantes