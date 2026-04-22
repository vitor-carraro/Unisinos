import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# ============================================================
# SISTEMA MASSA-MOLA-AMORTECEDOR
# H(s) = 1 / (m*s^2 + c*s + k)
# Entrada senoidal: F(t) = F0 * cos(w0*t)
# ============================================================

# ----------------------------
# Parâmetros físicos
# ----------------------------
m = 250.0       # massa [kg]
k = 16000.0     # constante da mola [N/m]
F0 = 1000.0     # amplitude da força [N]
w0 = 7.0        # frequência angular [rad/s]

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
t_final = 10.0
n_pontos = 5000
t = np.linspace(0, t_final, n_pontos)

# Entrada senoidal
F_t = F0 * np.cos(w0 * t)

# ----------------------------
# Função para simular resposta
# ----------------------------
def simular_resposta_senoidal(m, c, k, t, F_t):
    sistema = signal.TransferFunction([1.0], [m, c, k])
    tout, y, _ = signal.lsim(sistema, U=F_t, T=t)
    return tout, y

# ----------------------------
# Geração dos gráficos
# ----------------------------
fig, axes = plt.subplots(3, 1, figsize=(12, 12), sharex=True)
#fig.suptitle("Sistema massa-mola-amortecedor - Resposta à entrada senoidal", fontsize=14)

for ax, (nome_regime, c) in zip(axes, regimes.items()):
    tout, y = simular_resposta_senoidal(m, c, k, t, F_t)

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
print(f"w0 = {w0} rad/s")
print(f"c_crit = {c_crit:.4f} N·s/m")
for nome, c in regimes.items():
    print(f"{nome}: c = {c:.4f} N·s/m")