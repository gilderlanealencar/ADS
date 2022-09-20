class Texto {
    nome : string = "";
    pagamento : number = 0;
    linguagem : string = "";
}

let texto = new Texto();
texto.nome = "Ely";
texto.pagamento = 120.56;
texto.linguagem = "TypeScript";


console.log (texto.nome, "\nMy payment time is", texto.pagamento, "\nand\nmy preffered language is", texto.linguagem);