# Analisador de Legibilidade (Coleman-Liau)

Este programa calcula o nível de escolaridade de um texto baseado na quantidade de letras, palavras e frases, utilizando a fórmula de Coleman-Liau.

**Resultado:**
O programa solicitará um texto e retornará o nível:
* `Before Grade 1`: Texto muito simples.
* `Grade X`: Nível correspondente ao ano escolar americano.
* `Grade 16+`: Nível universitário ou superior.

## 🧮 A Fórmula
O cálculo baseia-se em:

index = 0.0588 * L - 0.296 * S - 15.8

Onde **L** é a média de letras por 100 palavras e **S** é a média de frases por 100 palavras.