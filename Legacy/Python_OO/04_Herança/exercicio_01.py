# Informe abaixo um código que contenha:
# Uma classe chamada Aritmetica, que contenha um método chamado subtracao. Este método deve receber por parâmetro dois valores e retornar a subtração entre eles.

# Uma classe chamada Sub, que herde a classe Aritmetica.

# Entrada de dados
# 2
# 20 10
# 99 45
# Saída esperada
# Minha superclasse é: <class '__main__.Aritmetica'>
# 10
# 54

class Aritmetica():
    def subtracao(self, val1, val2):
        return (val1 - val2)

class Sub(Aritmetica):
    pass
    # def __init__(self) -> None:
    #     super().__init__() 

if __name__ == "__main__":
    s = Sub()
    
    # Exibe o nome da superclasse
    print("Minha superclasse é: " + str(s.__class__.__bases__[0]))	
    
    t = int(input())
    
    for i in range(0, t):
        var1, var2 = input().split()
        print(s.subtracao(int(var1),int(var2)))