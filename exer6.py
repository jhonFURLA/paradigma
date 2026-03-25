# ==========================================
# 📁 ESTRUTURA DE PASTAS ANINHADAS
# ==========================================
sistema_arquivos = {
    "home": {
        "user": {
            "documentos": {
                "curriculo.pdf": None,
                "projeto.docx": None
            },
            "fotos": {
                "viagem.jpg": None
            }
        }
    },
    "etc": {
        "config.cfg": None
    }
}

# ==========================================
# 🔍 FUNÇÃO RECURSIVA
# ==========================================
def buscar_arquivo(pasta, nome_arquivo):
    """
    Busca um arquivo dentro de uma estrutura hierárquica (árvore).
    """

    # ==========================================
    # 🛑 CASO BASE (condição de parada)
    # ==========================================
    # Se o arquivo está na pasta atual, paramos
    if nome_arquivo in pasta:
        return True

    # ==========================================
    # 🔁 PASSO RECURSIVO
    # ==========================================
    # Percorre cada item da pasta
    for nome, conteudo in pasta.items():

        # Se for uma subpasta (outro dicionário)
        if isinstance(conteudo, dict):

            # Chamada recursiva para explorar níveis mais profundos
            if buscar_arquivo(conteudo, nome_arquivo):
                return True

    # Se não encontrou em nenhum nível
    return False

# ==========================================
# ▶️ TESTES
# ==========================================
print("Buscar curriculo.pdf:", buscar_arquivo(sistema_arquivos, "curriculo.pdf"))
print("Buscar viagem.jpg:", buscar_arquivo(sistema_arquivos, "viagem.jpg"))
print("Buscar config.cfg:", buscar_arquivo(sistema_arquivos, "config.cfg"))
print("Buscar inexistente.txt:", buscar_arquivo(sistema_arquivos, "inexistente.txt"))