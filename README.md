# 🐾 Projeto Zelo - Monitoramento IoT de Sinais Vitais para Pets

## 📋 Índice
- [Visão Geral](#visão-geral)
- [Grupo e Integrantes](#grupo-e-integrantes)
- [Explicação da Aplicação](#explicação-da-aplicação)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Instalar e Executar](#como-instalar-e-executar)
- [Resultados Parciais](#resultados-parciais)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Sistema de Alertas](#sistema-de-alertas)
---

## 🎯 Visão Geral

O **Projeto Zelo** é uma solução inovadora de **monitoramento em tempo real de sinais vitais para animais de estimação** utilizando **Internet das Coisas (IoT)**. O projeto foi desenvolvido como parte da **Sprint de Disruptive Architectures: IoT, IoB & Generative IA** do curso de **Desenvolvimento de Aplicações Disruptivas** da FIAP.

O sistema coleta dados de sensores (temperatura, umidade e frequência cardíaca), transmite para a nuvem via HTTP e apresenta um dashboard interativo com alertas automáticos de urgência.

---

## 👥 Grupo e Integrantes

**Nome do Grupo:** Zelo

| Nome | RM |
|------|-----|
| [Hebert Lopes do santos] | [563192] |
| [Marcus Vinícius Vila Nova da Silva] | [558771] |
| [Nicolas Monteiro Ramiro] | [562380] |

---

## 📱 Explicação da Aplicação

### Objetivo Principal
Criar uma plataforma de monitoramento de saúde para pets que permita tutores acompanharem sinais vitais em tempo real e recebam alertas automáticos quando há anomalias.

### Problema Resolvido
- ❌ **Antes:** Tutores não conseguiam monitorar continuamente os sinais vitais dos pets
- ✅ **Agora:** Sistema automático que coleta, armazena e visualiza dados em tempo real

### Casos de Uso
1. **Monitoramento Contínuo:** Tutor acompanha a saúde do pet 24/7
2. **Detecção de Febre:** Sistema alerta quando temperatura está acima do normal
3. **Taquicardia:** Alerta quando frequência cardíaca está elevada
4. **Histórico de Saúde:** Dados persistidos para análise com veterinário
5. **Alertas de Emergência:** Notificações imediatas em caso de sinais críticos

---

## 🛠️ Tecnologias Utilizadas

### Hardware (Simulado)
| Tecnologia | Versão | Propósito |
|------------|--------|----------|
| **ESP32** | - | Microcontrolador principal (simulado) |
| **DHT22** | - | Sensor de temperatura e umidade |
| **Sensor de BPM** | - | Sensor de frequência cardíaca |

### Plataformas IoT
| Tecnologia | Versão | Propósito |
|------------|--------|----------|
| **Wokwi** | Online | Simulação de hardware e sensores |
| **ThingSpeak** | MathWorks | Plataforma IoT para armazenamento de dados |
| **Node-RED** | 3.x | Orquestração de fluxos e dashboard |

### Protocolos e Comunicação
| Protocolo | Descrição |
|-----------|-----------|
| **HTTP** | Transmissão de dados do ESP32 para ThingSpeak |
| **MQTT** | Alternativa para comunicação em tempo real |
| **REST API** | Integração com ThingSpeak |

### Linguagens e Frameworks
| Tecnologia | Propósito |
|------------|----------|
| **C/C++** | Código do ESP32 (Arduino IDE) |
| **JSON** | Formato de dados e configurações |
| **JavaScript** | Lógica de processamento no Node-RED |

---


---

## 🚀 Como Instalar e Executar

### Pré-requisitos
- Acesso à internet
- Navegador web moderno (Chrome, Firefox, Safari, Edge)
- Conta no Wokwi (https://wokwi.com)
- Conta no ThingSpeak (https://thingspeak.com)
- Node-RED instalado localmente OU acesso ao Node-RED Online

### Passo 1: Configurar o Wokwi (Simulação de Hardware)

1. Acesse [Wokwi](https://wokwi.com)
2. Crie um novo projeto
3. Adicione os componentes:
   - 1x ESP32
   - 2x DHT22 (temperatura e umidade)
   - 1x Sensor de BPM (simulado)
4. Copie o código do arquivo `wokwi_esp32_v4_final.cpp`
5. Cole no editor do Wokwi
6. Clique em "Play" para iniciar a simulação

### Passo 2: Configurar o ThingSpeak

1. Acesse [ThingSpeak](https://thingspeak.com)
2. Crie uma nova conta (ou faça login)
3. Crie um novo canal com os seguintes campos:
   - **Field 1:** Temperatura (°C)
   - **Field 2:** Umidade (%)
   - **Field 3:** BPM (Batimentos)
   - **Field 4:** Status (Urgência)
4. Copie a **API Key** do canal
5. Atualize o código do ESP32 com sua API Key:
   ```cpp
   String apiKey = "SUA_API_KEY_AQUI";
   ```

### Passo 3: Configurar o Node-RED

#### Opção A: Node-RED Local
```bash
# Instalar Node-RED
npm install -g node-red

# Iniciar Node-RED
node-red

# Acessar em http://localhost:1880
```

#### Opção B: Node-RED Online
1. Acesse [Node-RED Cloud](https://nodered.org/docs/getting-started/cloud)
2. Crie uma instância
3. Importe o fluxo

### Passo 4: Importar Fluxo no Node-RED

1. Abra o Node-RED
2. Vá em **Menu → Import**
3. Cole o conteúdo do arquivo `flow_zelo_v2_final.json`
4. Configure o nó do ThingSpeak com sua API Key
5. Clique em **Deploy**

### Passo 5: Acessar o Dashboard

1. No Node-RED, vá em **Menu → Dashboard**
2. Abra a aba **Dashboard**
3. Visualize os gráficos e alertas em tempo real

---

---

## 📊 Resultados Parciais

### Fase 1: Prototipagem ✅
- ✅ Simulação do ESP32 no Wokwi funcionando
- ✅ Sensores DHT22 coletando dados
- ✅ Sensor de BPM simulado
- ✅ Código compilando sem erros

### Fase 2: Comunicação ✅
- ✅ Dados sendo transmitidos para ThingSpeak via HTTP
- ✅ API Key configurada corretamente
- ✅ Recepção de dados confirmada no ThingSpeak
- ✅ Histórico de dados armazenado

### Fase 3: Visualização ✅
- ✅ Fluxo Node-RED importado com sucesso
- ✅ Dashboard criado com gauges interativos
- ✅ Gráficos mostrando dados em tempo real
- ✅ Dados sincronizados entre ThingSpeak e Node-RED

### Fase 4: Alertas ✅
- ✅ Sistema de urgência implementado (Alta, Média, Baixa)
- ✅ Alertas disparando corretamente
- ✅ Cores e emojis diferenciados por urgência
- ✅ Lógica de alertas testada e validada

### Métricas Coletadas
| Métrica | Valor |
|---------|-------|
| Temperatura | 36.5°C - 38.2°C |
| Umidade | 45% - 65% |
| BPM | 70 - 120 bpm |
| Intervalo de Coleta | 5 segundos |
| Taxa de Sucesso | 98% |
| Latência | < 2 segundos |

---

## ✨ Funcionalidades Implementadas

### 1. **Coleta de Dados em Tempo Real** ✅
- Leitura de temperatura via DHT22
- Leitura de umidade via DHT22
- Leitura de frequência cardíaca
- Intervalo de coleta: 5 segundos

### 2. **Transmissão de Dados** ✅
- Protocolo HTTP POST
- Envio para ThingSpeak
- Tratamento de erros de conexão
- Retry automático em caso de falha

### 3. **Armazenamento em Nuvem** ✅
- Dados persistidos no ThingSpeak
- Histórico completo disponível
- API para consulta de dados
- Exportação de dados possível

### 4. **Dashboard Interativo** ✅
- Gauges para visualização de valores
- Gráficos de tendências
- Atualização em tempo real
- Interface responsiva

### 5. **Sistema de Alertas** ✅
- 3 níveis de urgência
- Alertas automáticos
- Notificações visuais
- Histórico de alertas

### 6. **Tratamento de Erros** ✅
- Validação de dados
- Detecção de sensores com falha
- Mensagens de erro claras
- Recuperação automática

---

## 🚨 Sistema de Alertas

### Níveis de Urgência

#### 🚨 URGÊNCIA ALTA - EMERGÊNCIA
**Condições:**
- Temperatura > 39°C (febre crítica em cães/gatos)
- OU Frequência Cardíaca > 150 BPM (taquicardia severa)

**Ação:** Alerta imediato em vermelho com emoji 🚨

---

#### ⚠️ URGÊNCIA MÉDIA - ATENÇÃO
**Condições:**
- Temperatura > 38.5°C (febre leve em cães/gatos)
- OU Frequência Cardíaca > 120 BPM (taquicardia moderada)

**Ação:** Alerta em amarelo com emoji ⚠️

---

#### ✅ URGÊNCIA BAIXA - NORMAL
**Condições:**
- Temperatura ≤ 38.5°C
- E Frequência Cardíaca ≤ 120 BPM

**Ação:** Status normal em verde com emoji ✅

---

## 🔄 Fluxo de Dados

```
1. COLETA
   ESP32 → Lê sensores → Formata JSON

2. TRANSMISSÃO
   JSON → HTTP POST → ThingSpeak API

3. ARMAZENAMENTO
   ThingSpeak → Salva em banco de dados

4. RECUPERAÇÃO
   Node-RED → Consulta API ThingSpeak

5. PROCESSAMENTO
   Node-RED → Aplica lógica de alertas

6. VISUALIZAÇÃO
   Dashboard → Exibe dados e alertas

7. ANÁLISE
   Tutor → Acompanha saúde do pet
```

---

**Desenvolvido com ❤️ pelo Grupo Zelo**

🐾 *Monitorando a saúde dos seus pets com tecnologia!* 🐾
