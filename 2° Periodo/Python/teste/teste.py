import tkinter as tk
from tkinter import ttk

def sair():
    exit()

def change_border_color(widget, color):
    style = ttk.Style()
    style.map('TEntry', fieldbackground=[('active', color)])

def verificar():

    style = ttk.Style()
    style.map('TEntry', fieldbackground=[('active', 'red')])

    
    entrada_diatanciaMax.config(style='custom.TEntry')


    label_textAviso.config(text="erro", fg="red", font="Times 16")

    entrada_diatanciaMax.config(fieldbackground="red")

    distancia_max = entrada_diatanciaMax.get()
    aceleracao_cv = entrada_aceleracaoCV.get()
    aceleracao_ca = entrada_aceleracaoCA.get()

    if aceleracao_ca == "0":
        change_border_color(entrada_aceleracaoCA, "red")
    else:
        change_border_color(entrada_aceleracaoCA, "SystemWindowFrame")
    

def inicializar():
    verificar()
    pass

janela = tk.Tk()
janela.title("Corrida de Carro")
janela.geometry("1200x900")

conteiner_1 = tk.Frame(janela)
conteiner_1.pack(pady=10, padx=20, anchor="w")

conteiner_2 = tk.Frame(janela)
conteiner_2.pack(pady=10, padx=20, anchor="w")

subConteiner_21 = tk.Frame(conteiner_2)
subConteiner_21.pack(side="left")
subConteiner_22 = tk.Frame(conteiner_2)
subConteiner_22.pack(side="right")

conteiner_3 = tk.Frame(janela)
conteiner_3.pack(padx=20, anchor="w")

subConteiner_31 = tk.Frame(conteiner_3)
subConteiner_31.pack(side="left")
subConteiner_32 = tk.Frame(conteiner_3)
subConteiner_32.pack(side="right")

conteiner_4 = tk.Frame(janela)
conteiner_4.pack(pady=10, padx=20, anchor="w")

# entradas
label_distanciaMax = tk.Label(conteiner_1, text="Largura da pista(m): ")
label_distanciaMax.pack(side="left")
entrada_diatanciaMax = tk.Entry(conteiner_1, width=10)
entrada_diatanciaMax.insert(0, "0")
entrada_diatanciaMax.pack(side="left")

label_aceleracaoCV = tk.Label(subConteiner_21, text="Aceleração do Carro Vermelho(m/s²): ")
label_aceleracaoCV.pack(side="left")
entrada_aceleracaoCV = tk.Entry(subConteiner_21, width=10)
entrada_aceleracaoCV.insert(0, "0")
entrada_aceleracaoCV.pack(side="left")

label_aceleracaoCA = tk.Label(subConteiner_22, text="Aceleração do Carro Azul(m/s²): ")
label_aceleracaoCA.pack(side="left")
entrada_aceleracaoCA = tk.Entry(subConteiner_22, width=10)
entrada_aceleracaoCA.insert(0, "0")
entrada_aceleracaoCA.pack(side="left")

label_velocidadeIniCV = tk.Label(subConteiner_31, text="Velocidade Inicial do Carro Vermelho(m/s): ")
label_velocidadeIniCV.pack(side="left")
entrada_velocidadeIniCV = tk.Entry(subConteiner_31, width=10)
entrada_velocidadeIniCV.insert(0, "0")
entrada_velocidadeIniCV.pack(side="left")

label_velocidadeIniCA = tk.Label(subConteiner_32, text="Velocidade Inicial do Carro Azul(m/s): ")
label_velocidadeIniCA.pack(side="left")
entrada_velocidadeIniCA = tk.Entry(subConteiner_32, width=10)
entrada_velocidadeIniCA.insert(0, "0")
entrada_velocidadeIniCA.pack(side="left")

button_butaoIniciar = tk.Button(conteiner_4, text="Iniciar", command=inicializar, padx=5, pady=5)
button_butaoIniciar.pack(side="left", padx= 20)
button_sair = tk.Button(conteiner_4, text="Sair", command=sair, padx=5, pady=5)
button_sair.pack(side="left")

label_textAviso = tk.Label(conteiner_4, text= "")
label_textAviso.pack(side="right")

janela.mainloop()
