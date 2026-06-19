global [
    x, y: int;
    v[10]: int;
]

funcao [
    soma(a: int, b: int): int {
        retorne a + b;
    }
]

principal {
    x = 10;
    y = 5;
    v[0] = soma(x, y);
    escreva "Resultado:";
    novalinha;
    escreva v[0];
    novalinha;
}
