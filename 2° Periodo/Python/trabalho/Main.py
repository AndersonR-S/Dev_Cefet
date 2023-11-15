import pandas as pd
import matplotlib.pyplot as plt

planilha = pd.read_excel("dados_de_vendas.xlsx",sheet_name= "Vendas")

media_vendas_anual = planilha["valor_da_venda"].mean()
media_vendas_mensal = planilha.groupby("meses")["valor_da_venda"].mean()

valor_total_anual = planilha["valor_da_venda"].sum()
valor_total_mensal = planilha.groupby("meses")["valor_da_venda"].sum()

produto_mais_vendido_anual = planilha["produto"].value_counts()
produto_mais_vendido_mensal = planilha.groupby("meses")["produto"].value_counts()


plt.plot(planilha["meses"], planilha["valor_da_venda"])
plt.title("Gráfico de vendas")
plt.xlabel("Data")
plt.show()
plt.ylabel("Valor da venda")


