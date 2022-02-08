# Autocomplete

## Para compilar

- Você deve possuir cmake com versão igual ou superior a 3.0

- Para compilar, digite em seu console:

```
mkdir build
cd build
cmake ../
cmake --build .
```

## Para executar

Com o programa compilado, você pode executar o autocomplete da seguinte maneira:
 
```
cd build
./autocomplete <arquivo_contendo_os_dados>
```

- Exemplo de execução:

```
./autocomplete ../data/cities.txt
```

- Para verificar com mais clareza a ordenação por peso, sugiro que execute o programa com o arquivo "desord.txt":

```
./autocomplete ../data/desord.txt
```


# Avaliação

## Ler e validar os argumentos da linha de comando | 8 / 10

- Faltou validar o conteúdo da base de dados

## Ler os dados da base de dados e armazená-los em uma classe apropriada | 10 / 10

- ok

## Separar a interface textual das demais classes do sistema concentrando os couts e cins em um único objeto | 8 / 10

- Parte da impressão ficou na classe "Process", a ideia aqui era você retornar o resultado e imprimir em "interface"

## Implementação de uma classe para conter o resultado da requisição do usuário | 10 / 10

- Vou considerar, embora o nome "Process" tenha ficado ruim. Ao invés de armazenar internamente em database, voce poderia, naquele método "busca" retornar
uma instancia de Process para que o main recebesse e passasse para a interface imprimir.

## Implementação eficiente através de referencias e algoritmos de busca binária | 3 / 10

- Embora você não tenha usado busca binária, a implementação está ok em termos de otimização de memória. Você não usou referencias, pois acabou não sendo
necessário, mas também não retornou objetos nos métodos o que ajuda a economizar.

## Organização do código em src, include, data | 5 / 5

- ok

## Documentação do código usando o padrão doxygen | 5 / 5

- ok

## Implementação e documentação de arquivos de teste | 5 / 10

- Você implementou uma base a mais, porém, em termos de testes nada foi documentado. Um forma seria vc colocar exemplos de saída "No match" ou de 
palavras específicas.