from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

from tkinter import *

class Aplicativo:
    def __init__(self, master=None):
        self.janela = master
        self.janela.title("Calculadora Gráfica de Movimento")
        self.janela.configure(bg="white")
        self.janela.geometry("1200x700")

        self.segundaColuna = Frame(self.janela, width=840, bg="white")
        self.segundaColuna.grid(row=0, column=1)

        # Estrutura da Primeira coluna
        self.primeiraColuna = Frame(self.janela, width=360, bg="white", padx=20)
        self.primeiraColuna.grid(row=0, column=0)

        # Desenvolvimento da Primeira Coluna
        self.pcParte1SubTitulo = Label(self.primeiraColuna, text="Equação de Torricelli", bg="white", pady=10)
        self.pcParte1SubTitulo["font"] = ("Verdana", "15", "bold")
        self.pcParte1SubTitulo.grid(row=3, column=0, sticky="w")

        self.aceleracao = DoubleVar()
        self.velocidadeIni = DoubleVar()
        self.velocidadeFin= DoubleVar()
        self.deslocamentoIni = DoubleVar()
        self.deslocamentoFin = DoubleVar()

        self.LabelAceleracao = Label(self.primeiraColuna, text="Aceleração em m/s²:", bg="white")
        self.LabelAceleracao.grid(row=4, column=0, sticky="w")
        self.EntryAceleracao = Entry(self.primeiraColuna, textvariable=self.aceleracao, width=20)
        self.EntryAceleracao.grid(row=5, column=0, sticky="w")

        self.espaco1 = Label(self.primeiraColuna, text=" ", bg="white")
        self.espaco1.grid(row=6, column=0)

        self.LabelVelocidadeIni = Label(self.primeiraColuna, text="Velocidade Inicial em m/s:", bg="white")
        self.LabelVelocidadeIni.grid(row=7, column=0, sticky="w")
        self.EntryVelocidadeINi = Entry(self.primeiraColuna, textvariable=self.velocidadeIni, width=20)
        self.EntryVelocidadeINi.grid(row=8, column=0, sticky="w")

        self.espaco2 = Label(self.primeiraColuna, text=" ", bg="white")
        self.espaco2.grid(row=9, column=0)

        self.LabelVelocidadeFin = Label(self.primeiraColuna, text="Velocidade final em m/s:", bg="white")
        self.LabelVelocidadeFin.grid(row=10, column=0, sticky="w")
        self.EntryVelocidadeIFin = Entry(self.primeiraColuna, textvariable=self.velocidadeFin, width=20)
        self.EntryVelocidadeIFin.grid(row=11, column=0, sticky="w")

        self.espaco3 = Label(self.primeiraColuna, text=" ", bg="white")
        self.espaco3.grid(row=12, column=0)

        self.LabelDeslocamentoIni = Label(self.primeiraColuna, text="Deslocamento Inicial em m:", bg="white")
        self.LabelDeslocamentoIni.grid(row=13, column=0, sticky="w")
        self.EntryDeslocamentoINi = Entry(self.primeiraColuna, textvariable=self.deslocamentoIni, width=20)
        self.EntryDeslocamentoINi.grid(row=14, column=0, sticky="w")

        self.espaco4 = Label(self.primeiraColuna, text=" ", bg="white")
        self.espaco4.grid(row=15, column=0)

        self.LabelDeslocamentoFin = Label(self.primeiraColuna, text="Deslocamento final em m:", bg="white")
        self.LabelDeslocamentoFin.grid(row=16, column=0, sticky="w")
        self.EntryDeslocamentoIFin = Entry(self.primeiraColuna, textvariable=self.deslocamentoFin, width=20)
        self.EntryDeslocamentoIFin.grid(row=17, column=0, sticky="w")

        self.Button = Frame(self.primeiraColuna, bg="white", pady=40)
        self.Button.grid(row=20, column=0)

        self.buttonCalcular = Button(self.Button, text="Calcular", bg="green", command=self.plot_graph)
        self.buttonCalcular["font"] = ("Verdana", "10", "bold")
        self.buttonCalcular["width"] = 5
        self.buttonCalcular.grid(row=0, column=0, sticky="snew")

        self.buttonLimpar = Button(self.Button, text="Limpar", command=self.janela.quit)
        self.buttonLimpar["font"] = ("Verdana", "10", "bold")
        self.buttonLimpar["width"] = 5
        self.buttonLimpar.grid(row=0, column=1, sticky="snew")

        self.buttonSair = Button(self.Button, text="Sair", bg="red", command=self.janela.quit)
        self.buttonSair["font"] = ("Verdana", "10", "bold")
        self.buttonSair["width"] = 5
        self.buttonSair.grid(row=0, column=2, sticky="snew")

    def plot_graph(self):
            a = self.aceleracao.get()
            vi = self.velocidadeIni.get()
            vf = self.velocidadeFin.get()
            xi = self.deslocamentoIni.get()
            xf = self.deslocamentoFin.get()

            time = list(range(11))  # Cria uma lista de 0 a 10
            position = [xi + vi * t + 0.5 * a * t ** 2 for t in time]

            #Matplotlib figure
            fig = Figure(figsize=(6, 4), dpi=100)
            ax = fig.add_subplot(111)
            ax.plot(time, position)
            ax.set_xlabel('Time (s)')
            ax.set_ylabel('Position (m)')
            ax.set_title('Position vs. Time')

            canvas = FigureCanvasTkAgg(fig, master=self.segundaColuna)
            canvas.get_tk_widget().grid(row=0, column=0)



janela = Tk()
Aplicativo(janela)
janela.mainloop()
