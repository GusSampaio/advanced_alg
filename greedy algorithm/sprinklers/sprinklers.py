
from cmath import sqrt

def intervalo(centro, raio, altura, largura):
    coord = [0]*2
    dx = abs(sqrt(raio**2 - ((altura**2)/4)))
    coord[0] = centro - dx
    coord[1] = centro + dx
    if(coord[0] < 0):
        coord[0] = 0
    if(coord[1] > largura):
        coord[1] = largura
    return coord

def minimo(n, l, intervals):
    
    resultado = 0
    ultimo = 0
    i = -1
    while i < n - 1:
        j = i + 1
        if intervals[j][0] > ultimo:
            return -1
        primeiro = ultimo
        while j < n:
            if intervals[j][0] <= ultimo:
                primeiro = max(primeiro, intervals[j][1])
                i += 1
            j += 1
        ultimo = primeiro
        resultado += 1
        if ultimo >= l:
            return resultado
    return resultado if ultimo >= l else -1
    
if '__name__' == '__main__':

    while True:
        try:
            entrada =  list(map(int,input().split()))
            qtde = entrada[0]
            largura = entrada[1]
            altura = entrada[2]
            irr = []
            intervalos = []
            for i in range(qtde):
                irr.append(list(map(int,input().split())))
                if(irr[i][1] >= altura/2):
                    intervalos.append(intervalo(irr[i][0],irr[i][1],altura, largura))
            intervalos.sort()
            #print(intervalos)
            print(minimo(len(intervalos), largura, intervalos))

        except EOFError:
            break
