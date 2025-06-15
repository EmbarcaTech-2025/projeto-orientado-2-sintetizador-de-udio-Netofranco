
# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: **Arthur Franco Neto**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, 15 de Junho de 2025

# Sintetizador de Audio

Este projeto implementa um Sintetizador de Áudio, capaz de gravar e reproduzir áudio, dentro das especificações do sistema – duração do áudio (em segundos), taxa de amostragem, frequência do áudio reproduzido, etc.

## Objetivo

	- Aquisição do sinal analógico via ADC do microfone
	- Bufferização das amostras
	- Reprodução das amostras capturadas via PWM
	- Botões para controle de gravação e reprodução
	- Display OLED para exibição de informações

##  Lista de materiais: 

| Componente            | Conexão na BitDogLab      |
|-----------------------|---------------------------|
| BitDogLab (RP2040)    | -                         |
| Display OLED I2C      | SDA: GPIO14 / SCL: GPIO15 |
| Botões para Controle  | ESQ: GPIO5  / DIR: GPIO6  |
| Microfone			    | GPIO28 					|
| Buzzer			    | GPIO10 					|

## Execução

1. Abra o projeto no VS Code, usando o ambiente com suporte ao SDK do Raspberry Pi Pico (CMake + compilador ARM), utilizado SDK **1.5.1**;
2. Compile o projeto normalmente (Ctrl+Shift+B no VS Code ou via terminal com cmake e make);
3. Conecte sua BitDogLab via cabo USB e coloque a Pico no modo de boot (pressione o botão BOOTSEL e conecte o cabo);
4. Copie o arquivo .uf2 gerado para a unidade de armazenamento que aparece (RPI-RP2);
5. A Pico reiniciará automaticamente e começará a executar o código;
6. Utilize o Botão A para iniciar a gravação. O LED RGB ficara vermelho enquanto a gravação estiver disponivel
7. Utilize o Botão B para iniciar a reprodução dos dados salvor. O LED RGB ficara verde enquanto a reprodução estiver rodando.

## Lógica

- Os dados são aquisitavos via ADC e armazenados na memória RAM durante o periodo de gravação
- Os dados bufferizados na RAM são convertidos via PWM para saida do Buzzer

##  Arquivos


## 🖼️ Imagens do Projeto

Video https://youtube.com/shorts/GRdKsEqrSBg
---

## 📜 Licença
MIT License - MIT GPL-3.0.
