class Conta {
    numero: String;
    saldo: number;
    constructor(numero: string, saldo: number){
        this.numero = numero;
        this.saldo = saldo;
    }
    sacar(valor: number): boolean {
    if(this.saldo > valor){
        this.saldo = this.saldo - valor;
        return true;
    }else{
        return false;
    }
      
    }
    depositar(valor: number): void {
    this.saldo = this.saldo + valor;
    }
    
    consultarSaldo(): number {
    return this.saldo;
    }
    
    transferencia(contaDestino: Conta, valor: number): boolean{
            if(this.sacar(valor)){
                contaDestino.depositar(valor);
                return true;
            }
            else{
                return false;
            }
        }
    }
    let ct: Conta = new Conta("130", 320);
    console.log(ct.sacar(100));
    console.log(ct.depositar(50));
    console.log(ct.consultarSaldo());
    
    let cont: Conta = new Conta("127", 210);
    console.log(cont.sacar(320));
    console.log(ct.transferencia(cont, 400));
    console.log(ct.transferencia(cont,72));
    console.log(cont.consultarSaldo());
