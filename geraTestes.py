import matplotlib.pyplot as plt
import subprocess
import random
import numpy as np

random.seed(21312412)
numeroCidadesMax = 14
numeroTestePorCidade = 1
mediasDosTemposDasCidades = list()
desvioPadraoDosTemposDasCidades = list()
for i in range(1, numeroCidadesMax+1):
    temposDasCidades = list()
    for j in range(numeroTestePorCidade):
        saida = subprocess.Popen(['./trabalhoApa', str(i), str(random.randrange(7000)), '0'], stdout=subprocess.PIPE)
        saida, err = saida.communicate()
        print(str(saida).split('\\n')[3].split()[2])
        temposDasCidades.append((float(str(saida).split('\\n')[3].split()[2])*1000))
    mediasDosTemposDasCidades.append(np.mean(temposDasCidades))
    desvioPadraoDosTemposDasCidades.append(np.std(temposDasCidades))

x = np.arange(1, numeroCidadesMax+1)
plt.errorbar(x, mediasDosTemposDasCidades, yerr=desvioPadraoDosTemposDasCidades, linewidth=0.5, ecolor='r')

plt.title('Gráfico de para visualização do tsp')
plt.xlabel('numero de cidades (u)')
plt.ylabel('tempo (ms)')
plt.savefig('graficoDaExecucaoPorTempo.eps')
plt.close()
