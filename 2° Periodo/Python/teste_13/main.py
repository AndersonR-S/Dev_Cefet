def verificador(linha):
     if (len(linha)-1)>6:
         print(f'{linha[0]} com {len(linha)-1} notas : {linha[1:]}')
        
arquivo = open("//home/anderson/Documentos/Python/teste_14/notas_alunos.dat",'r')
linhas = arquivo.readlines()

for linha in linhas:
  verificador(linha.split())

arquivo.close()
