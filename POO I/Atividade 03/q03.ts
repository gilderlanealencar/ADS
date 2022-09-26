//Crie uma função que receba como parâmetros um nome e um pronome de tratamento opcional.
// Caso esse último não seja fornecido, deve ser considerado o valor “Sr”. Ao final,
// imprima uma saudação semelhante a “Sra. Sávia”.

function saudadaçao(nome: string, pronome?: string): string {
    if (pronome) {
        return nome + " " + pronome
    }

    return "Sra. " + nome
}

console.log(saudadaçao("Gilderlane"))
console.log(saudadaçao("Sra", "Gilderlane"))