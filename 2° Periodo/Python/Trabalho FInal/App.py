import dash
from dash import html, dcc, Input, Output, State
import dash_bootstrap_components as dbc
import plotly.express as px
import plotly.graph_objects as go
import pandas as pd

app = dash.Dash(external_stylesheets=[dbc.themes.MINTY])
server = app.server

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

# ====== Ajeitando os Dados para a manipulação =======#
file = pd.read_csv("supermarket_sales.csv")

# removendo as colunas que não vao usar
file.drop(
    ['Invoice ID', 'Branch', 'Customer type', 'Gender',
     'Time', 'gross margin percentage', 'cogs', 'gross income',
     'Rating'],
    inplace=True, axis=1
)
# Renomeando as colunas
file.rename(
    columns={'City': 'CIDADE',
             'Product line': 'PRODUTO',
             'Unit price': 'PREÇO UNI',
             'Quantity': 'QUANTIDADE',
             'Tax 5%': 'TAXA',
             'Total': 'TOTAL C. TAXA',
             'Date': 'DATA',
             'Payment': 'PAGAMENTO'
             },
    inplace=True
)

# Converte e ordena a Coluna Date de forma crescente
file["DATA"] = pd.to_datetime(file["DATA"])
file = file.sort_values(by="DATA")


# Adicionando uma Coluna 'MES'(nomes traduzidos)
file['MES'] = file['DATA'].dt.strftime('%B')
meses_mapping = {
    'January': 'Janeiro',
    'February': 'Fevereiro',
    'March': 'Março',
    'April': 'Abril',
    'May': 'Maio',
    'June': 'Junho',
    'July': 'Julho',
    'August': 'Agosto',
    'September': 'Setembro',
    'October': 'Outubro',
    'November': 'Novembro',
    'December': 'Dezembro'
}

meses_mapping_num= {
    'Janeiro': 1 ,
    'Fevereiro':2,
    'Março':3,
    'Abril':4,
    'Maio':5,
    'Junho':6,
    'Julho':7,
    'Agosto':8,
    'Setembro':9,
    'Outubro':10,
    'Novembro':11,
    'Dezembro':12
}

file['MES'].replace(meses_mapping, inplace=True)

cidades = file["CIDADE"].unique()
anos = file["DATA"].apply(lambda x: str(x.year)).unique()
meses = file['MES'].unique()

# ======= Layout =======#
app.layout = html.Div(
    children=[
        dbc.Row([
            dbc.Col([
                dbc.Card([
                    html.Label("Análise de Vendas", style={
                               "font-family": "Voltaire", "font-size": "30px", "text-align": "center"}),
                    html.Hr(),

                    html.Label("Cidades:", style={
                               "font-size": "18px", "marginTop": "10px"}),
                    dcc.Dropdown(cidades, cidades, multi=True,
                                 id='selec_cidade'),

                    html.Label("Anos:", style={
                               "font-size": "18px", "marginTop": "10px"}),
                    dcc.Dropdown(anos, anos, multi=True, id="select_ano"),

                    html.Label("Meses:", style={
                               "font-size": "18px", "marginTop": "10px"}),
                    dcc.Dropdown(meses, meses, multi=True, id="selec_mes"),

                ], style={"height": "95vh", "padding": "20px"})
            ], sm=3
            ),
            dbc.Col([
                dbc.Row([
                    dbc.Col([
                        html.H6("VALOR TOTAL C/ TAXA ",
                                style={'font-size': '18px'}),
                        html.H6(id="valor_total_c", children='',
                                style={'font-size': '18px'})
                    ]),
                    dbc.Col([
                        html.H6("VALOR TOTAL S/ TAXA ",
                                style={'font-size': '18px'}),
                        html.H6(id="valor_total_s", children='',
                                style={'font-size': '18px'})
                    ]),
                    dbc.Col([
                        html.H6("CIDADE COM MAIOR VENDA ",
                                style={'font-size': '18px'}),
                        html.H6(id="maior_cidade", children='',
                                style={'font-size': '18px'})
                    ]),
                    dbc.Col([
                        html.H6("PRODUTO MAIS VENDIDO ",
                                style={'font-size': '18px'}),
                        html.H6(id="mais_vendido", children='',
                                style={'font-size': '18px'})
                    ]),
                    html.Hr()
                ], style={"height": "5 vh", "text-align": "center"}),

                dbc.Row([
                            html.H6("OS MELHORES PRODUTOS EM RELAÇÃO AOS MESES"),
                            dbc.Col([dcc.Graph(id="figura2"),], sm=12),

                        ],style={"text-align": "center", "padding":"19px"}),
                dbc.Row([
                            html.H6(id="id_figura", children = " "),
                            dbc.Col([dcc.Graph(id="figura"),], sm=12, ),

                        ],style={"text-align": "center", "padding":"19px"}),


            ], sm=9, style={"height": "100%"})
        ], style={"margin": "20px"})
    ]
)


# Os dados
@app.callback(
    Output('valor_total_c', 'children'),
    Output('valor_total_s', 'children'),
    Output('maior_cidade', 'children'),
    Output('mais_vendido', 'children'),
  
    [
        Input('selec_cidade', 'value'),
        Input('select_ano', 'value'),
        Input('selec_mes', 'value')
    ]
)
def renderizarDados(cidade, ano, mes):

    # Verificar se tem alguma variavel vazia
    if not cidade or not ano or not mes:
        return '---', '---', '---', '---'

    # Convertendo cada elemento da lista para inteiro
    anos_inteiros = list(map(int, ano))

    # filtragem
    dados_filtrados = file[file['CIDADE'].isin(
        cidade) & file['DATA'].dt.year.isin(anos_inteiros) & file['MES'].isin(mes)]

    #Operando dados 

    total_com = dados_filtrados['TOTAL C. TAXA'].sum()
    total_sem= dados_filtrados['TOTAL C. TAXA'].sum() - dados_filtrados['TAXA'].sum()

    vtc = f" R$ {total_com:,.2f}"
    vts = f" R$ {total_sem:,.2f}"
    mc = dados_filtrados.groupby('CIDADE')['QUANTIDADE'].sum().idxmax()
    mv = dados_filtrados.groupby('PRODUTO')['QUANTIDADE'].sum().idxmax()

    return vtc, vts, mc, mv

#Os graficos
@app.callback(
    Output('figura2', 'figure'),
  
    [
        Input('selec_cidade', 'value'),
        Input('select_ano', 'value'),
        Input('selec_mes', 'value')
    ]
)
def graficos(cidade, ano, mes):
    # Convertendo cada elemento da lista para inteiro
    anos_inteiros = sorted(list(map(int, ano)))

    #filtro
    dados_filtrados = file[file['CIDADE'].isin(cidade) & file['DATA'].dt.year.isin(anos_inteiros) & file['MES'].isin(mes)]

    # Agrupamento por mês e produto 
    fig2 = dados_filtrados.groupby(['MES', 'PRODUTO'])['QUANTIDADE'].sum().reset_index()
    fig2['MES_NUMERO'] = fig2['MES'].map(meses_mapping_num)
    fig2 = fig2.sort_values(by="MES_NUMERO")


    # Agrupamento por mês para linhas totais
    df_2 = dados_filtrados.groupby(['MES'])['QUANTIDADE'].sum().reset_index()
    df_2['MES_NUMERO'] = df_2['MES'].map(meses_mapping_num)
    df_2 = df_2.sort_values(by="MES_NUMERO")


    # Criando gráfico de linha
    fig2 = px.line(fig2, y="QUANTIDADE", x="MES", color="PRODUTO")

    # Adicionando linhas totais ao gráfico de linha
    fig2.add_trace(go.Scatter(y=df_2["QUANTIDADE"], x=df_2["MES"], mode='lines+markers', fill='tonexty', name='Total de Quantidades'))

    # Configurações de layout
    fig2.update_layout(main_config, yaxis={'title': None}, xaxis={'title': None}, height=325)
    fig2.update_layout({"legend": {"yanchor": "top", "y": 0.99, "font": {"color": "white", 'size': 10}}})

    return fig2

@app.callback(
    Output('figura', 'figure'),
    Output('id_figura', 'children'),
  
    [
        Input('selec_cidade', 'value'),
        Input('select_ano', 'value'),
        Input('selec_mes', 'value')
    ]
)
def graficos_1(cidade, ano, mes):

    # Convertendo cada elemento da lista para inteiro
    anos_inteiros = sorted(list(map(int, ano)))
    
    anos_inteiros.sort()
    anos_inteiros = anos_inteiros[-10:]

    #filtro
    dados_filtrados = file[file['CIDADE'].isin(cidade) & file['DATA'].dt.year.isin(anos_inteiros) & file['MES'].isin(mes)]
    dados_filtrados = dados_filtrados.copy()

    # Adicione a coluna "ANO"
    dados_filtrados["ANO"] = dados_filtrados["DATA"].apply(lambda x: str(x.year))

    # Agrupamento por ano
    fig = dados_filtrados.groupby('ANO', as_index=False)['TOTAL C. TAXA'].sum()

    # Grafico
    fig = px.line(fig, y="TOTAL C. TAXA", x="ANO")
    fig.update_layout(main_config, yaxis={'title': None}, xaxis={'title': None}, height=325)
    fig.update_layout({"legend": {"yanchor": "top", "y": 0.99, "font": {"color": "white", 'size': 10}}})

    
    value = f"VENDA ENTRE OS INTERVALOS {anos_inteiros[0]} - {anos_inteiros[9]}"

    return fig, value


# =========  Run server  =========== #
if __name__ == "__main__":
    app.run_server(debug=False)
