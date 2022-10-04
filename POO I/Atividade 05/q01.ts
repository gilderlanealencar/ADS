export class Pessoa {
    nome: string;
    constructor(nome: string) {
        this.nome = nome;
    }
}

export class Conta {
    numero: string;
    saldo: number;
    cliente: Pessoa;

    constructor(numero: string, saldo: number, cliente: Pessoa) {
        this.numero = numero;
        this.saldo = saldo;
        this.cliente = cliente;
    }

    sacar(valor : number): boolean {
        if (this.saldo < valor) {
            return false;
        } else {
            this.saldo = this.saldo - valor;
            return true;
        };
    }

    depositar(valor: number): void {
        this.saldo = this.saldo + valor;
    }

    consultarSaldo(): number {
        return this.saldo;
    }

    transferir(contaDestino: Conta, valor: number) : boolean {
        if (this.sacar(valor) == false) {
            return false;
        } else {
            this.sacar(valor);
            contaDestino.depositar(valor);
            return true;
        }
    }
}

export class Banco {
    contas: Conta[] = [];
    
    // a.
    inserir(conta: Conta): void {
        let i = 0;
        while (i < this.contas.length) {
            if (conta.numero != this.contas[i].numero) {
                i++;
            } else {
                return;
            }
        }
        this.contas.push(conta);
    }
    //
    alterar(conta: Conta): void {}
    excluir(numero: string): void{
        let i = 0;
        while (i < this.contas.length) {
            if (numero == this.contas[i].numero) {
                this.contas.splice(i, 1);
                return;
            } else {
                i++;
            }
        } 
    }

    // b.
    sacar(numero: string, valor: number): void {
        let i = 0;
        while (i < this.contas.length) {
            if (numero == this.contas[i].numero) {
                this.contas[i].saldo -= valor;
                return;
            } else {
                i++;
            }
        }
    }
    //
    depositar(numero: string, valor: number): void {
        let i = 0;
        while (i < this.contas.length) {
            if (numero == this.contas[i].numero) {
                this.contas[i].depositar(valor);
                return;
            } else {
                i++;
            }
        }
    }

    // c.
    transferir(numeroOrigem: string, numeroDestino: string, valor: number): void {
        let i = 0;
        let j = 0;
        while (i < this.contas.length) {
            if (numeroOrigem == this.contas[i].numero) {
                if (numeroDestino == this.contas[j].numero) {
                    this.contas[i].saldo -= valor;
                    this.contas[j].saldo += valor;
                    return;
                } else {
                    j++;
                }
            } else {
                i++;
            }
        }
    }

    // d.
    totalContas() : number {
        return this.contas.length;
    }
    totalDinheiro() : number {
        let soma = 0;
        for (let i = 0; i < this.contas.length; i++) {
            soma += this.contas[i].saldo;
        }
        return soma;
    }
    media() : number {
        return this.totalDinheiro() / this.totalContas();
    }
}
