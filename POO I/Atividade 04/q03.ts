class Radio {
    volume : number;
    constructor(volume : number) {
        this.volume = volume;
    }
}

let r : Radio = new Radio();
r.volume = 10;

// Falta um argumento pro construtor do objeto r. A solução é adicionar o valor do volume no construtor.
