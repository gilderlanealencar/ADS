// Crie uma função que recebe como parâmetro um número e retorna true se o número for primo e false caso contrário.

function primo(n: number): any{
    for(let i = 2; i < n; i++){
        if(n % i === 0){
            return false;
        }
        return true;
    }
}

const num = primo(7);
const n1 = primo(10);
console.log(num, n1);