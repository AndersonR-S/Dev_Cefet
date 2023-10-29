import tkinter as tk
from PIL import Image, ImageTk
from math import sqrt

def simular_corrida():
    # Obtenha os valores iniciais do usuário
    velocidade_inicial = float(entrada_velocidade.get())
    aceleracao = float(entrada_aceleracao.get())
    tempo_total = float(entrada_tempo_total.get())
    comprimento_pista = float(entrada_comprimento_pista.get())

    # Inicialize variáveis
    tempo = 0
    posicao = 0

    # Função para atualizar a simulação em cada iteração
    def atualizar_simulacao():
        nonlocal tempo, posicao

        if tempo <= tempo_total:
            # Atualiza a posição usando a equação de movimento
            posicao = 0.5 * aceleracao * tempo ** 2 + velocidade_inicial * tempo

            # Verifique se a posição do carro excede o comprimento da pista
            if posicao > comprimento_pista:
                posicao = comprimento_pista

            # Atualiza a posição do carro na interface
            canvas.delete("carro")
            carro_x = 10 + (posicao / comprimento_pista) * 1000  # Posição horizontal do carro na tela
            carro_y = 100  # Altura do carro
            canvas.create_image(carro_x, carro_y, anchor=tk.W, image=carro_imagem, tags="carro")

            # Calcula o tempo com base na posição atual
            if aceleracao != 0:
                tempo = sqrt((2 * posicao) / aceleracao)
            else:
                tempo = posicao / velocidade_inicial

            # Calcula o tempo de atualização com base no comprimento da pista
            taxa_atualizacao = (tempo_total / comprimento_pista) * 1000

            # Atualiza o rótulo de exibição
            resultado["text"] = f"Tempo: {tempo:.2f} s, Posição: {posicao:.2f} m"

            # Agende a próxima atualização
            janela.after(int(taxa_atualizacao), atualizar_simulacao)
        else:
            resultado["text"] = "Simulação concluída."

    atualizar_simulacao()

# O restante do código permanece o mesmo

# Cria uma janela com a interface gráfica
janela = tk.Tk()
janela.title("Simulador de Corrida de Carro")

# Defina o tamanho da janela para 1200x900 pixels
janela.geometry("1200x900")

# Crie campos de entrada
tk.Label(janela, text="Velocidade Inicial (m/s):").pack()
entrada_velocidade = tk.Entry(janela)
entrada_velocidade.pack()

tk.Label(janela, text="Aceleração (m/s^2):").pack()
entrada_aceleracao = tk.Entry(janela)
entrada_aceleracao.pack()

tk.Label(janela, text="Tempo Total (s):").pack()
entrada_tempo_total = tk.Entry(janela)
entrada_tempo_total.pack()

# Adicione um campo de entrada para o comprimento da pista
tk.Label(janela, text="Comprimento da Pista (m):").pack()
entrada_comprimento_pista = tk.Entry(janela)
entrada_comprimento_pista.pack()

# Carregue a imagem do carro
carro_imagem_original = Image.open("carro.png")
carro_imagem_redimensionada = carro_imagem_original.resize((80, 40), Image.ANTIALIAS)
carro_imagem = ImageTk.PhotoImage(carro_imagem_redimensionada)

# Crie um botão para iniciar a simulação
botao_simular = tk.Button(janela, text="Simular Corrida", command=simular_corrida)
botao_simular.pack()

# Crie um canvas para exibir o carro
canvas = tk.Canvas(janela, width=1000, height=300)
canvas.pack()

# Rótulo para exibir o resultado da simulação
resultado = tk.Label(janela, text="")
resultado.pack()

janela.mainloop()
