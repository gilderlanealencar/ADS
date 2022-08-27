const prompt = require('prompt-sync')();

// converter de real para bitcoin

var real, bitcoin, cotacao;

bitcoin = prompt('Digite o valor em U$$:')
cotacao = prompt('Digite a cotacao atual:')
real = dolar*cotacao;
console.log('Valor convertido: ' + real);