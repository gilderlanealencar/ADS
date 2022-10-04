class Saudacao{
    texto: string;
    destinatario: string;
    constructor(texto: string, destinatario: string){
        this.texto = texto;
        this.destinatario = destinatario;
    }
    obterSaudacao(): void{
        console.log(this.texto, this.destinatario);
    }
}

let saudacao = new Saudacao("Bom dia","Gilderlane");
saudacao.obterSaudacao();
