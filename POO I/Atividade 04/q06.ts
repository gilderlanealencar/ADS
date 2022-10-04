class Triangulo{
    lado1: number;
    lado2: number;
    lado3: number;
    constructor(lado1: number, lado2: number, lado3: number){
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    ehTriangulo(): boolean{
        if((this.lado2 - this.lado3) < this.lado1 && this.lado1 < (this.lado2 + this.lado3)){
            return true;
        }else{
            return false;
        }
    }

    ehIsoceles(): boolean{
        return !this.ehEquilatero() && !this.ehEscaleno();
    }

    ehEquilatero(): boolean{
        if(this.lado1 == this.lado2 || this.lado2 == this.lado3){
            return true;
        }else{
            return false;
        }
    }
    ehEscaleno(): boolean{
        if(this.lado1 != this.lado2 && this.lado2 != this.lado3 && this.lado1 != this.lado3){
            return true;
        }else{
        return false;
    }
    }
}

let tg: Triangulo = new Triangulo(4,3,7);
console.log(tg.ehTriangulo());
console.log(tg.ehEquilatero());
console.log(tg.ehEscaleno());
console.log(tg.ehIsoceles());

let tg1: Triangulo = new Triangulo(2,2,2);
console.log(tg1.ehTriangulo());
console.log(tg1.ehEquilatero());
console.log(tg1.ehEscaleno());
console.log(tg1.ehIsoceles());

let tg2: Triangulo = new Triangulo(1,2,1);
console.log(tg2.ehTriangulo());
console.log(tg2.ehEquilatero());
console.log(tg2.ehEscaleno());
console.log(tg2.ehIsoceles());

let nt: Triangulo = new Triangulo(5,2,1);
console.log(nt.ehTriangulo());
console.log(nt.ehEquilatero());
console.log(nt.ehIsoceles());
