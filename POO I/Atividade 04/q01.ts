// Resposta: Não, pois no método adicionarReserva falta apontar pra propriedade da classe Hotel com o termo this.

class Hotel {
    quantReservas : number;
    adicionarReserva() : void {
        quantReservas++;
    } 
}
