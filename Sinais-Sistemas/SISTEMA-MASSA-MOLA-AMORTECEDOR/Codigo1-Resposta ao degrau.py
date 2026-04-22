import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# ============================================================
# SISTEMA MASSA-MOLA-AMORTECEDOR
# H(s) = 1 / (m*s^2 + c*s + k)
# Entrada degrau deslocado: F(t) = F0 * u(t - t0)
# ============================================================

# ----------------------------
# Parâmetros físicos
# ----------------------------
m = 250.0       # massa [kg]
k = 16000.0     # constante da mola [N/m]
F0 = 1000.0     # amplitude da força [N]
t0 = 1.0        # instante de aplicação do degrau [s]

# Amortecimento crítico
c_crit = 2 * np.sqrt(m * k)

# Três regimes
regimes = {
    "Subamortecido": 0.5 * c_crit,
    "Criticamente amortecido": c_crit,
    "Superamortecido": 2.0 * c_crit
}

# ----------------------------
# Eixo do tempo
# ----------------------------
t_final = 8.0
n_pontos = 4000
t = np.linspace(0, t_final, n_pontos)

# Entrada degrau deslocado
u = (t >= t0).astype(float)
F_t = F0 * u

# ----------------------------
# Função para simular resposta
# ----------------------------
def simular_resposta_degrau(m, c, k, t, F_t):
    # Função de transferência: 1 / (m s^2 + c s + k)
    sistema = signal.TransferFunction([1.0], [m, c, k])

    # Resposta para entrada arbitrária F(t)
    tout, y, _ = signal.lsim(sistema, U=F_t, T=t)
    return tout, y

# ----------------------------
# Geração dos gráficos
# ----------------------------
fig, axes = plt.subplots(3, 1, figsize=(12, 12), sharex=True)
#fig.suptitle("Sistema massa-mola-amortecedor - Resposta à entrada degrau", fontsize=5)

for ax, (nome_regime, c) in zip(axes, regimes.items()):
    tout, y = simular_resposta_degrau(m, c, k, t, F_t)

    ax.plot(tout, F_t, label="Entrada F(t)", linewidth=2)
    ax.plot(tout, y, label="Saída y(t)", linewidth=2)

    ax.set_title(f"{nome_regime} | c = {c:.2f} N·s/m")
    ax.set_ylabel("Amplitude")
    ax.grid(True)
    ax.legend()

axes[-1].set_xlabel("Tempo [s]")
plt.tight_layout()
plt.show()

# ----------------------------
# Informações no terminal
# ----------------------------
print("=== Parâmetros utilizados ===")
print(f"m = {m} kg")
print(f"k = {k} N/m")
print(f"F0 = {F0} N")
print(f"t0 = {t0} s")
print(f"c_crit = {c_crit:.4f} N·s/m")
for nome, c in regimes.items():
    print(f"{nome}: c = {c:.4f} N·s/m")