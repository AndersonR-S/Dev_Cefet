
class Pessoa:
	def __init__(self, nome: str, idade: int):
		self.__nome = nome
		self.__idade = idade

	def __str__(self):
		return f'Nome: {self.__nome}, Idade: {self.__idade}'

	def getNome(self):
		return self.__nome
	
	def getIdade(self):
		return self.__idade
	
	def setNome(self, novo_nome: str):
		self.__nome = novo_nome

	def setIdade(self, nova_idade: int):
		self.__idade = nova_idade
	
	
class Aluno(Pessoa):
	def __init__(self, nome: str, idade: int, matricula: str):
		super().__init__(nome, idade)
		self.__matricula = matricula

	def __str__(self):
		return f'{super().__str__()}, Matricula: {self.__matricula}'
	
	def getMatricula(self):
		return self.__matricula
	

class Gerenciamento:
	alunos = []

	@classmethod
	def criarAluno(cls, nome: str, idade: int, matricula: str):
		aluno = Aluno(nome, idade, matricula)
		cls.alunos.append(aluno)

	@classmethod
	def listarAluno(cls):
		for aluno in cls.alunos:
			print(aluno)

	@classmethod
	def buscarAluno(cls, matricula: str): 
		for aluno in cls.alunos:
			if aluno.getMatricula() == matricula:
				return aluno
		return None
	
	
	@classmethod
	def excluirAluno(cls, matricula: str):
		aluno = cls.buscarAluno(matricula)
		if aluno:
			cls.alunos.remove(aluno)
			print("ALUNO REMOVIDO")
		else:
			print("ALUNO NÃO ENCONTRADO")

	@classmethod
	def menuAlterar(cls, aluno): 
		while 1:
			print("\nMENU ALTERAR:")
			print("1 - ATUALIZAR NOME")
			print("2 - ATUALIZAR IDADE")
			print("3 - ATUALIZAR O NOME E A IDADE")
			print("4 - MENU PRINCIPAL")
			opcao = input("\nESCOLHE UMA OPCAO: ")
			
			if opcao == '1':
				novo_nome = input("DIGITE O NOVO NOME: ")
				aluno.setNome(novo_nome)
				#cls.atualizarAluno(aluno.getMatricula(),novo_nome,aluno.getIdade())

			elif opcao == '2':
				nova_idade = int(input("DIGITE A NOVA IDADE: "))
				aluno.setIdade(nova_idade)
				
				#cls.atualizarAluno(aluno.getMatricula(),aluno.getNome(),nova_idade)
			
			elif opcao == '3':
				novo_nome = input("\nDIGITE O NOVO NOME: ")
				nova_idade = int(input("DIGITE A NOVA IDADE: "))

				aluno.setNome(novo_nome)
				aluno.setIdade(nova_idade)
				#cls.atualizarAluno(aluno.getMatricula(),novo_nome,nova_idade)
		
			elif opcao == '4':
				break
			else:
				print("\nOPCAO INVALIDA\n")

	@classmethod
	def menuPrincipal(cls):
		while 1:
			print("\nMENU ALTERAR:")
			print("1 - CRIAR ALUNO")
			print("2 - LISTAR ALUNOS")
			print("3 - BUSCAR ALUNO")
			print("4 - ATUALIZAR ALUNO")
			print("5 - EXCLUIR ALUNO")
			print("6 - SAIR")

			opcao = input("\nESCOLHE UMA OPÇÃO: ")

			if opcao == '1':
				nome = input("\nDIGITE O NOME: ")
				idade = int(input("DIGITE A IDADE: "))
				matricula = input("DIGITE A MATRICULA: ")

				cls.criarAluno(nome,idade,matricula)
			elif opcao == '2':
				if len(cls.alunos)>0:
					cls.listarAluno()
				else:
					print("LISTA VAZIA")

			elif opcao =='3':
				matricula = input("\nDIGITE A MATRICULA: ")
				aluno = cls.buscarAluno(matricula)
				if aluno:
					print(aluno)

				else:
					print("ALUNO NÃO ENCONTRADO")

			elif opcao == '4':
				if len(cls.alunos)>0:
					matricula = input("\nDIGITE A MATRICULA: ")
					aluno = cls.buscarAluno(matricula)
					if aluno:
						cls.menuAlterar(aluno)

					else:
						print("ALUNO NÃO ENCONTRADO")
				else:
					print("LISTA VAZIA")


			elif opcao == '5':
				if len(cls.alunos)>0:
					matricula = input("\nDIGITE A MATRICULA: ")
					cls.excluirAluno(matricula)
				else:
					print("\nLISTA VAZIA")


			elif opcao == '6':
				break

			else:
				print("OPCAO INVALIDA")
				


Gerenciamento.menuPrincipal()

