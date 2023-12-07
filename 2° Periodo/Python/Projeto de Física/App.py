import dash
from dash import dcc, html, Input, Output
from dash.dependencies import Input, Output, State
import dash_bootstrap_components as dbc
import plotly.express as px
import plotly.graph_objects as go

from math import sqrt
import tkinter as tk
import numpy as np
import sympy as sp
from PIL import Image
import base64


#margem de erro nos graficos
tam = 0.01

tam = float(tam)

main_config = {
    "hovermode": "x unified",
    "legend": {"yanchor":"top", 
                "y":0.9, 
                "xanchor":"left",
                "x":0.1,
                "title": {"text": None},
                "font" :{"color":"white"},
                "bgcolor": "rgba(0,0,0,0.5)"},
    "margin": {"l":0, "r":0, "t":10, "b":0}
}

def Corrida():
    janela = tk.Tk()
    janela.title("Simulador de Corrida de Carro")
    # Defina o tamanho da janela para 1200x900 pixels
    janela.geometry("1200x900")
    janela.mainloop()
    
def calcular_tempo(s, s0, v0, a):
    s = float(s)
    s0 = float(s0)
    v0 = float(v0)
    a = float(a)
    t = sp.symbols('t')
    eq = sp.Eq(s, s0 + v0 * t + 0.5 * a * t**2)
    solucoes = sp.solve(eq, t)

    # Verificar soluções reais positivas
    tempos_reais = [solucao.evalf() for solucao in solucoes if solucao.is_real and solucao.evalf() >= 0]

    if not tempos_reais:
        return 0

    return max(tempos_reais)

def distanciaGrafico(tempo,vo, a):
    deslocamento = [vo*t+0.5*a*t**2 for t in tempo]
    return deslocamento

def velocidadeGrafico(diatancia, vo, a):
    velocidade = [sqrt(vo**2 + 2*a*x) for x in diatancia]
    return velocidade

app = dash.Dash(__name__, external_stylesheets=[dbc.themes.BOOTSTRAP])

app.layout = html.Div(
    children=[
        dbc.Row([
            #Coluna do menu
            dbc.Col(
                dbc.Card([
                    html.H3("Corrida de Carro", style={"text-align": "center"}),
                    html.Hr(),

                    html.Label("Tamanho da Pista (KM):", style={"padding": "6px"}),
                    dbc.Input(id="input_pista", type="text", value=0),

                    html.H4("Carro Vermelho", style={"paddingTop": "30px", "paddingBottom": "10px"}),
                    html.Label("Velocidade Inicial (m/s):", style={"padding": "6px"}),
                    dbc.Input(id="input_velocidade_inicial_cv", type="text", value=0),

                    html.Label("Aceleração (m/s²):", style={"padding": "6px"}),
                    dbc.Input(id="input_aceleracao_cv", type="text", value=0),

                    html.H4("Carro Azul", style={"paddingTop": "30px", "paddingBottom": "10px"}),
                    html.Label("Velocidade Inicial (m/s):", style={"padding": "6px"}),
                    dbc.Input(id="input_velocidade_inicial_ca", type="text", value=0),

                    html.Label("Aceleração (m/s²):", style={"padding": "6px"}),
                    dbc.Input(id="input_aceleracao_ca", type="text", value=0),

                    html.Div([
                        dbc.Button("Começar", id="button_iniciar", style={"padding": "6px", "margin": "10px", "background": "green", "border": "green", "font-size": "17px"}),
                    ], style={"text-align": "center", "padding": "20px"})

                ], style={"height": "97vh", "padding": "20px"}
                ), sm=3
            ),
            #Coluna das informações
            dbc.Col([
                dbc.Row([
                    dbc.Col(
                        dbc.Card([
                            html.H4(children="Esperando o Vencedor", id= "titulo_ganhador"),
                            html.Img(id="img_ganhador", src="", style={'marginTop':'20px','class':"fit-picture"})                        ], style={"height": "45vh", "text-align": "center","padding": "20px"}),
                        sm=4,style={"text-align": "center"}
                    ),
                    dbc.Col([
                        dbc.Row([
                            dbc.Row([
                                    dbc.Card([
                                        dbc.Row([
                                            html.H4(children="Equações Utilizadas", id= "titulo_vermelho"),
                                            html.Hr()
                                        ]),
                                        dbc.Row([
                                            dbc.Col([
                                                html.H4(children=" S = So + VoT + 0.5aT²", style={'fontFamily': 'Sunday Morning', 'paddingTop':'20px'}),
                                            ]),
                                            dbc.Col([
                                                html.H4(children=" V² = Vo² + 2a(S-So)", style={'fontFamily': 'Sunday Morning', 'paddingTop':'20px'}),                                            ])
                                        ])
                                    ], style={"height": "18vh","padding": "20px"})
                            ], style={"marginBottom":"27px",'text-align':'center'}),
                            dbc.Row([
                                    dbc.Card([
                                        dbc.Row([
                                            dbc.Col([
                                                html.H4(children="Dados do Carro Vermelho", id= "titulo_vermelho"),
                                                html.Hr(),
                                                html.H6(children="Tempo: --", id= "cv_tempo"),
                                                html.H6(children="Aceleração: --", id= "cv_aceleracao"),
                                                html.H6(children="Velocidade Inicial: --", id= "cv_velocidadeI"),
                                                html.H6(children="Velocidade Final: --", id= "cv_velociadeF"),
                                            ]),
                                            dbc.Col([
                                                html.H4(children="Dados do Carro Azul", id= "titulo_vermelho"),
                                                html.Hr(),
                                                html.H6(children="Tempo: --", id= "ca_tempo"),
                                                html.H6(children="Aceleração: --", id= "ca_aceleracao"),
                                                html.H6(children="Velocidade Inicial: --", id= "ca_velocidadeI"),
                                                html.H6(children="Velocidade Final: --", id= "ca_velociadeF"),
                                            ])
                                        ])
                                    ], style={"height": "24vh","padding": "20px"})
                            ])
                        ])

                    ], style={"marginLeft":"17px"})

                ],style={"marginBottom": "27px"}
                ),
                dbc.Row([
                    dbc.Col(
                        dbc.Card([
                            html.Label(id="titulo_ganhadorr", children=""),
                            dcc.Graph(id = "figura1"),
                        ], style={"height": "49vh"}),
                        sm=6
                    ),
                    dbc.Col(
                        dbc.Card([
                            dcc.Graph(id = "figura2"),
                        ], style={"height": "49vh"}),
                        sm=6
                    )
                ]
                )
            ])

        ], style={"margin": "10px"})
    ], 
)

def is_float(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

def validate_inputs(*input_values):
    validation_results = [is_float(value) for value in input_values]
    return validation_results

@app.callback(
    [Output('input_pista', 'style'),
     Output('input_velocidade_inicial_cv', 'style'),
     Output('input_aceleracao_cv', 'style'),
     Output('input_velocidade_inicial_ca', 'style'),
     Output('input_aceleracao_ca', 'style')],
    [Input('button_iniciar', 'n_clicks')],
    [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def highlight_inputs(n_clicks, distancia, velocidade_inicial_cv, aceleracao_cv, velocidade_inicial_ca, aceleracao_ca):
    validation_results = validate_inputs(distancia, velocidade_inicial_cv, aceleracao_cv, velocidade_inicial_ca, aceleracao_ca)

    style_valid = {'border-color': 'black'}
    style_invalid = {'border-color': 'red'}

    return (
        style_valid if validation_results[0] else style_invalid,
        style_valid if validation_results[1] else style_invalid,
        style_valid if validation_results[2] else style_invalid,
        style_valid if validation_results[3] else style_invalid,
        style_valid if validation_results[4] else style_invalid
    )

#ganhador
@app.callback([
    Output('titulo_ganhador','children'),
    Output('img_ganhador','src')
],
     [Input('button_iniciar', 'n_clicks')],
     [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def ganhador(n_clicks, distancia,velocidade_icv = 0, aceleracao_cv=0, velocidade_ica=0, aceleracao_ca=0):
    if distancia == 0 and velocidade_icv == 0 and aceleracao_cv == 0 and velocidade_ica == 0 and aceleracao_ca == 0:
        return 'Informe os valores corretamente', ""


    tempo_cv = calcular_tempo(distancia, 0, velocidade_icv, aceleracao_cv)
    tempo_ca = calcular_tempo(distancia, 0,velocidade_ica, aceleracao_ca)

    image_file= ""

    if tempo_ca != 0 and tempo_cv != 0:
            if tempo_ca < tempo_cv:
                mensagem = 'O ganhador é o Carro Azul'
                return mensagem , image_file
            elif tempo_ca == tempo_cv:
                mensagem = "Deu Empate"
                return mensagem , image_file
            else:
                mensagem = 'O ganhador é o Carro Vermelho'
                return mensagem , image_file
    elif tempo_ca !=0 and tempo_cv ==0:
        mensagem = 'O ganhador é o Carro Azul'
        return mensagem , image_file
    
    elif tempo_ca ==0 and tempo_cv !=0:
        mensagem = 'O ganhador é o Carro Vermelho'
        return mensagem , image_file
    else:
        return 'Informe os valores corretamente'

#grafico 1 
@app.callback([
     Output('figura1','figure'),
     Output('cv_tempo','children'),
     Output('ca_tempo','children'),
     Output('cv_aceleracao','children'),
     Output('ca_aceleracao','children'),
     Output('cv_velocidadeI','children'),
     Output('ca_velocidadeI','children')
],
     [Input('button_iniciar', 'n_clicks')],
     [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def graf1(n_clicks, distancia =0 , velocidade_icv= 0, aceleracao_cv= 0, velocidade_ica= 0, aceleracao_ca= 0):
    tempo_cv= calcular_tempo(distancia, 0, velocidade_icv, aceleracao_cv)
    tempo_ca = calcular_tempo(distancia, 0, velocidade_ica, aceleracao_ca)

    vec_tempo_cv = np.arange(0, tempo_cv + tam, tam)
    vec_tempo_ca = np.arange(0, tempo_ca + tam, tam)

    deslocamento_cv = distanciaGrafico(vec_tempo_cv, float(velocidade_icv), float(aceleracao_cv))
    deslocamento_ca = distanciaGrafico(vec_tempo_ca, float(velocidade_ica), float(aceleracao_ca))

    fig = go.Figure()

    fig.add_trace(go.Scatter(x=vec_tempo_cv, y=deslocamento_cv, mode='lines', name='Carro Vermelho', line=dict(color='red')))
    fig.add_trace(go.Scatter(x=vec_tempo_ca, y=deslocamento_ca, mode='lines', name='Carro Azul', line=dict(color='blue')))

    fig.update_layout(main_config, yaxis={'title': 'Distância(m)'}, xaxis={'title': "Tempo(s)"}, height=425)
    fig.update_layout({"legend": {"yanchor": "top", "y": 0.99, "font": {"color": "white", 'size': 10}}})
    
    return fig, f'Tempo: {float(tempo_cv):.2f} s', f'Tempo: {float(tempo_ca):.2f} s', f'Aceleracao: {float(aceleracao_cv):.2f} m/s²', f'Aceleracao: {float(aceleracao_ca):.2f} m/s²', f'Velociade: {float(velocidade_icv):.2f} m/s', f'Velociade: {float(velocidade_ica):.2f} m/s'

#grafico 2
@app.callback([
     Output('figura2','figure'),
     Output('cv_velociadeF','children'),
     Output('ca_velociadeF','children')
],
     [Input('button_iniciar', 'n_clicks')],
     [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def graf2(n_clicks, distancia = 0, velocidade_icv = 0, aceleracao_cv = 0, velocidade_ica = 0, aceleracao_ca = 0):
    tempo_cv= calcular_tempo(distancia, 0, velocidade_icv, aceleracao_cv)
    tempo_ca = calcular_tempo(distancia, 0, velocidade_ica, aceleracao_ca)

    vec_tempo_cv = np.arange(0, tempo_cv + tam, tam)
    vec_tempo_ca = np.arange(0, tempo_ca + tam, tam)

    deslocamento_cv = distanciaGrafico(vec_tempo_cv, float(velocidade_icv), float(aceleracao_cv))
    deslocamento_ca = distanciaGrafico(vec_tempo_ca, float(velocidade_ica), float(aceleracao_ca))

    velocidade_cv = velocidadeGrafico(deslocamento_cv, float(velocidade_icv), float(aceleracao_cv))
    velocidade_ca = velocidadeGrafico(deslocamento_ca, float(velocidade_ica), float(aceleracao_ca))

    velocidadeF_cv = float(velocidade_cv[-1])
    velocidadeF_ca = float(velocidade_ca[-1])

    fig = go.Figure()

    fig.add_trace(go.Scatter(x=deslocamento_cv, y=velocidade_cv, mode='lines', name='Carro Vermelho', line=dict(color='red')))
    fig.add_trace(go.Scatter(x=deslocamento_ca, y=velocidade_ca, mode='lines', name='Carro Azul', line=dict(color='blue')))

    fig.update_layout(main_config, yaxis={'title': 'Velociade(m/s)'}, xaxis={'title': "Distância(m)"}, height=425)
    fig.update_layout({"legend": {"yanchor": "top", "y": 0.99, "font": {"color": "white", 'size': 10}}})
    
    return fig, f'Velocidade Final: {velocidadeF_cv:.2f} m/s', f'Velocidade Final: {velocidadeF_ca:.2f} m/s'

if __name__ == "__main__":
    app.run_server(debug=True)
