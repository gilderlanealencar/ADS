class Jogador {
    força: number;
    nivel: number;
    pontos_atuais: number;

    constructor(força: number, nivel: number, pontos_atuais: number) {
        this.força = força;
        this.nivel = nivel;
        this.pontos_atuais = pontos_atuais
    }

    calcularAtaque(): number {
        return this.força * this.nivel;
    }

    atacar(player: Jogador): void {
        if (player.estaVivo()) {
            player.pontos_atuais -= this.calcularAtaque()
        } else {
            console.log("Its already dead !!!")
        }
    }

    estaVivo(): boolean {
        return this.pontos_atuais > 0
    }

    toString(): string {
        return `Força: ${this.força} Nível: ${this.nivel} Pontos Atuais: ${this.pontos_atuais}`
    }
}

let jogador1: Jogador = new Jogador(5, 20, 1000)
let jogador2: Jogador = new Jogador(8, 20, 1500)

console.log(jogador1.calcularAtaque())
console.log(jogador2.calcularAtaque())

jogador1.atacar(jogador2)
jogador2.atacar(jogador1)

console.log(jogador1.toString())
console.log(jogador2.toString())
