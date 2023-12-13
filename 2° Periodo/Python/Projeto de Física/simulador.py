import tkinter as tk
from PIL import Image, ImageTk

class CorridaSimulator:
    def __init__(self, distancia, deslocamentos_cv, deslocamentos_ca):
        self.distancia = distancia
        self.deslocamentos_cv = deslocamentos_cv
        self.deslocamentos_ca = deslocamentos_ca
        self.posicao_cv = 0
        self.posicao_ca = 13
        self.setup_interface()

    def carregar_imagens(self):
        carro_imagem_vermelho = Image.open("img/carro_vermelho.png").resize((100, 80), Image.ANTIALIAS)
        self.carro_imagem_vermelho = ImageTk.PhotoImage(carro_imagem_vermelho)

        carro_imagem_azul = Image.open("img/carro_azul.png").resize((80, 40), Image.ANTIALIAS)
        self.carro_imagem_azul = ImageTk.PhotoImage(carro_imagem_azul)

    def configurar_canvas(self):
        self.canvas_vermelho = tk.Canvas(self.janela, width=1100, height=140)
        self.canvas_vermelho.pack()

        self.canvas_azul = tk.Canvas(self.janela, width=1100, height=140)
        self.canvas_azul.pack()

    def posicionar_carros(self):
        self.carro_vermelho = self.canvas_vermelho.create_image(self.posicao_cv, 100, anchor=tk.W, image=self.carro_imagem_vermelho)
        self.carro_azul = self.canvas_azul.create_image(self.posicao_ca, 20, anchor=tk.W, image=self.carro_imagem_azul)

    def mover_carros(self):
        for deslocamento_cv, deslocamento_ca in zip(self.deslocamentos_cv, self.deslocamentos_ca):
            self.posicao_cv = (deslocamento_cv*1000) / self.distancia
            self.posicao_ca =13 + ((deslocamento_ca*1000) / self.distancia)

            # Verifica se a posição ultrapassa o limite
            if self.posicao_cv  >= 1000:
                self.posicao_cv = 1000

            if self.posicao_ca >= 1000:
                self.posicao_ca = 1000

            self.canvas_vermelho.coords(self.carro_vermelho, self.posicao_cv, 100)
            self.canvas_azul.coords(self.carro_azul, self.posicao_ca, 20)

            self.janela.update()
            self.janela.after(100)  # Aguarda 100 milissegundos entre os movimentos

            # Se ambos os carros atingirem o limite, interrompa o loop
            if self.posicao_cv >= 1000 and self.posicao_ca >= 1000:
                break

    def setup_interface(self):
        self.janela = tk.Tk()
        self.janela.title("Simulador de Corrida de Carro")

        self.tempo = tk.Label(self.janela, text="", font=("Arial", 16))
        self.tempo.pack(padx=40)

        self.carregar_imagens()
        self.configurar_canvas()
        self.posicionar_carros()

        container_buttons = tk.Frame(self.janela)
        container_buttons.pack(pady=10, padx=20, anchor="sw")

        self.reiniciar_sair = tk.Button(
            container_buttons,
            text="Reiniciar",
            command=self.iniciar_corrida,
            font=("Arial", 14),
            bg="#60D116",
            fg="white",
            relief=tk.RAISED,
            padx=15,
            pady=5
        )
        self.reiniciar_sair.pack(side=tk.LEFT,padx=10, pady=10,fill=tk.X)

        self.botao_sair = tk.Button(
            container_buttons,
            text="Sair",
            command=self.janela.destroy,
            font=("Arial", 14),
            bg="#FF5733",
            fg="white",
            relief=tk.RAISED,
            padx=15,
            pady=5
        )
        self.botao_sair.pack(side=tk.LEFT, padx=10, pady=10,fill=tk.X)

        self.janela.geometry("1200x500")


    def iniciar_corrida(self):

        for i in range(4, -1, -1):
            self.tempo['text'] = f'Começa em {i}'
            self.janela.update()
            self.janela.after(1000)

            
        self.mover_carros()
        self.janela.mainloop()

