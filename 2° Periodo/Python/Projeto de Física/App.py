import dash
from dash import dcc, html, Input, Output
from dash.dependencies import Input, Output, State
import dash_bootstrap_components as dbc
import plotly.express as px
import plotly.graph_objects as go

import sympy as sp
from PIL import Image

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

def calcular_tempo(s, s0, v0, a):
    s = int(s)
    s0 = int(s0)
    v0 = int(v0)
    a = int(a)
    t = sp.symbols('t')
    eq = sp.Eq(s, s0 + v0 * t + 0.5 * a * t**2)
    solucoes = sp.solve(eq, t)

    # Verificar soluções reais positivas
    tempos_reais = [solucao.evalf() for solucao in solucoes if solucao.is_real and solucao.evalf() >= 0]

    if not tempos_reais:
        print("Erro: A equação não possui solução real positiva.")
        return 0

    return max(tempos_reais)

def distanciaGrafico(tempo,vo, a):
    deslocamento = [vo*t+0.5*a*t**2 for t in tempo]
    return deslocamento


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
                        dbc.Button("Limpar", id="button_limpar", style={"padding": "6px", "margin": "10px", "font-size": "17px"}),
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
                            html.Img(id="img_ganahdor", src="", width="60%", className="mx-auto d-block", style={'marginTop':'20px'})                        ], style={"height": "45vh", "text-align": "center","padding": "20px"}),
                        sm=4,style={"text-align": "center"}
                    ),
                    dbc.Col([
                        dbc.Row([
                            dbc.Row([
                                    dbc.Card([], style={"height": "21vh", "text-align": "center","padding": "20px"})
                            ], style={"marginBottom":"27px"}),
                            dbc.Row([
                                    dbc.Card([], style={"height": "21vh", "text-align": "center","padding": "20px"})
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
    Output('img_ganahdor','src')
],
     [Input('button_iniciar', 'n_clicks')],
     [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def ganhador(n_clicks, distancia,velocidade_icv, aceleracao_cv, velocidade_ica, aceleracao_ca):
    if distancia == 0 and velocidade_icv == 0 and aceleracao_cv == 0 and velocidade_ica == 0 and aceleracao_ca == 0:
        return 'Informe os valores corretamente', ""


    tempo_cv = calcular_tempo(distancia, 0, velocidade_icv, aceleracao_cv)
    tempo_ca = calcular_tempo(distancia, 0,velocidade_ica, aceleracao_ca)


    if tempo_ca != 0 and tempo_cv != 0:
            if tempo_ca < tempo_cv:
                mensagem = 'O ganhador é o Carro Azul'
                return mensagem , "carro.png"
            elif tempo_ca == tempo_cv:
                mensagem = "Deu Empate"
                return mensagem , "carro.png"
            else:
                mensagem = 'O ganhador é o Carro Vermelho'
                return mensagem , "carro.png"
    elif tempo_ca !=0 and tempo_cv ==0:
        mensagem = 'O ganhador é o Carro Azul'
        return mensagem , "carro.png"
    
    elif tempo_ca ==0 and tempo_cv !=0:
        mensagem = 'O ganhador é o Carro Vermelho'
        return mensagem , "carro.png"
    else:
        return 'Informe os valores corretamente', ""
#grafico 1 e 2
@app.callback([
    #Output('titulo_ganhadorr','children')
     Output('figura1','figure'),
   # Output('figuera2','figure')
],
     [Input('button_iniciar', 'n_clicks')],
     [State('input_pista', 'value'),
     State('input_velocidade_inicial_cv', 'value'),
     State('input_aceleracao_cv', 'value'),
     State('input_velocidade_inicial_ca', 'value'),
     State('input_aceleracao_ca', 'value')]
)
def graf1(n_clicks, distancia, velocidade_icv, aceleracao_cv, velocidade_ica, aceleracao_ca):
    tempo_cv = calcular_tempo(distancia, 0, velocidade_icv, aceleracao_cv)
    tempo_ca = calcular_tempo(distancia, 0, velocidade_ica, aceleracao_ca)

    vec_tempo_cv = [x for x in range(int(tempo_cv) + 1)]
    vec_tempo_ca = [x for x in range(int(tempo_ca) + 1)]

    deslocamento_cv = distanciaGrafico(vec_tempo_cv, int(velocidade_icv), int(aceleracao_cv))
    deslocamento_ca = distanciaGrafico(vec_tempo_ca, int(velocidade_ica), int(aceleracao_ca))

    fig = go.Figure()

    # Add traces for Carro Vermelho (cv) and Carro Azul (ca)
    fig.add_trace(go.Scatter(x=vec_tempo_cv, y=deslocamento_cv, mode='lines', name='Carro Vermelho'))
    fig.add_trace(go.Scatter(x=vec_tempo_ca, y=deslocamento_ca, mode='lines', name='Carro Azul'))

    # Set colors for each trace
    fig.update_traces(marker=dict(color=['red']), selector=dict(name='Carro Vermelho'))
    fig.update_traces(marker=dict(color=['blue']), selector=dict(name='Carro Azul'))

    fig.update_layout(main_config, yaxis={'title': 'Distância(m)'}, xaxis={'title': "Tempo(s)"}, height=425)
    fig.update_layout({"legend": {"yanchor": "top", "y": 0.99, "font": {"color": "white", 'size': 10}}})
    return [fig]

if __name__ == "__main__":
    app.run_server(debug=True)
