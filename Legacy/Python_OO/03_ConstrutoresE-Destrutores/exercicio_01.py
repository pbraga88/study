# Defina uma classe chamada Curso que receba pelo construtor três atributos: nome, preco e descricao.
# Entrada de dados
# Você não será responsável pela entrada
# Saída esperada
# Você não será responsável pela saída.



# Adicione o seu código aqui.
class Curso():
    def __init__(self, nome, preco, descricao):
        self.nome = nome
        self.preco = preco
        self.descricao = descricao

if __name__ == "__main__":
    nome = input()
    preco = input()
    descricao = input()
    c = Curso(nome, preco, descricao)
    
    print(f"Nome: {c.nome} - Preço: {c.preco} - Descrição: {c.descricao}")