import time
import random

def gerador_log():
    """
    Gerador que simula a leitura de um arquivo de log infinito.
    A cada chamada de next(), emite um novo registro.
    """
    contador = 1
    while True:  # loop infinito, mas sem consumir RAM
        # Simula criação de um registro de log
        registro = f"[{time.strftime('%H:%M:%S')}] Registro #{contador} - valor={random.randint(0, 100)}"
        yield registro
        contador += 1
        # time.sleep(0.5)  # opcional: simula atraso de chegada de logs

# ==========================================
# USO DO GERADOR
# ==========================================
log_infinito = gerador_log()

# Simula leitura de apenas 5 registros por vez
for _ in range(5):
    print(next(log_infinito))
    