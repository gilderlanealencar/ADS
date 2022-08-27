const prompt = require('prompt-sync')();

// Progama que mostre o antecessor e o sucessor de número
function sucessor(num){
    num++;
    return num;
}
function antecessor(num){
    num--;
    return num;
}
let numero = prompt('Digite um numero:')
console.log(`NÚMERO: ${numero}`);
console.log('SUCESSOR:' + sucessor(numero));
console.log('ANTECESSOR:' + antecessor(numero));