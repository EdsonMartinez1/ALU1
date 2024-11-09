int EstadoA=2;
int EstadoB=3;
//ENTRADAS DE CONTROL
int EstadoZ=4;
int EstadoY=5;
int EstadoX=6;
int EstadoW=7;
int a =8;
int b =9;
int c =10;
int d =11;
int e =12;
int f =13;
int g =A5;
int h =A4;
void setup() {
  // put your setup code here, to run once:
  pinMode (EstadoA,INPUT);
  pinMode (EstadoB,INPUT);
  pinMode (EstadoZ,INPUT);//CONTROL 1 Z
  pinMode (EstadoY,INPUT);//CONTROL 2 Y
  pinMode (EstadoX,INPUT);//CONTROL 3 X
  pinMode (EstadoW,INPUT);//CONTROL 4 W
  pinMode (a,OUTPUT);//A
  pinMode (b,OUTPUT);//B
  pinMode (c,OUTPUT);//C
  pinMode (d,OUTPUT);//D
  pinMode (e,OUTPUT);//E
  pinMode (f, OUTPUT);//F
  pinMode (g, OUTPUT);//G
  pinMode (h, OUTPUT);//H
}

void loop() {
  // put your main code here, to run repeatedly:
  //Leer las variables físicas
  EstadoA=digitalRead (2);
  EstadoB=digitalRead (3);
  //ESTADOS DE CONTROL
  EstadoZ=digitalRead (4);
  EstadoY=digitalRead (5);
  EstadoX=digitalRead (6);
  EstadoW=digitalRead (7);
  //inicia ALU
    //XOR ^ (Suma)
    if((!EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(EstadoA^EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    //AND && (Acarreos)
    if((!EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(a,LOW),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,HIGH),digitalWrite(e,LOW),digitalWrite(f,LOW),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
    //(suma)Apagado
    if((!EstadoZ&&!EstadoY&&!EstadoX&&EstadoW)&&(!EstadoA&&!EstadoB)){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}

     //XOR ^ (Resta)
    if((!EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(EstadoA^EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    //0 para cuando el XOR sea 0
    else if(!EstadoZ&&!EstadoY&&EstadoX&&!EstadoW){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
    //AND+NOT(A) ! && (Signo)
    if((!EstadoZ&&!EstadoY&&EstadoX&&!EstadoW)&&(!EstadoA&&EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,HIGH),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    
      //AND && (Multiplicación)
    if((!EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if(!EstadoZ&&!EstadoY&&EstadoX&&EstadoW){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}


    //AND && (División)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if ((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(!EstadoA&&EstadoB)){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
    //AND+NOT && ! (Infinito)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA&&!EstadoB)){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
    //AND+NOT ! && ! (Indefinido)
    if((!EstadoZ&&EstadoY&&!EstadoX&&!EstadoW)&&(!EstadoA&&!EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,LOW),digitalWrite(d,LOW),digitalWrite(e,HIGH),digitalWrite(f,LOW),digitalWrite(g,LOW),digitalWrite(h,LOW);}
  
   //AND && 
    if((!EstadoZ&&EstadoY&&!EstadoX&&EstadoW)&&(EstadoA&&EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if(!EstadoZ&&EstadoY&&!EstadoX&&EstadoW){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}

     //OR ||
    if((!EstadoZ&&EstadoY&&EstadoX&&!EstadoW)&&(EstadoA||EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if(!EstadoZ&&EstadoY&&EstadoX&&!EstadoW){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}

     //NOT A !
    if((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&!EstadoA){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&EstadoA){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
    //NOT B !
    if((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&!EstadoB){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if ((!EstadoZ&&EstadoY&&EstadoX&&EstadoW)&&EstadoB){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}

     //XOR ^
    if((EstadoZ&&!EstadoY&&!EstadoX&&!EstadoW)&&(EstadoA^EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if(!EstadoZ&&!EstadoY&&!EstadoX&&!EstadoW){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}

  
    // NOR (!||)
    if ((EstadoZ && !EstadoY && !EstadoX && EstadoW) && (!EstadoA && !EstadoB)) {digitalWrite(8, LOW),digitalWrite(9, LOW),digitalWrite(10, HIGH),digitalWrite(11, LOW),digitalWrite(12, LOW),digitalWrite(13, HIGH),digitalWrite(A5, LOW),digitalWrite(A4, LOW);} 
    else if ((EstadoZ && !EstadoY && !EstadoX && EstadoW) && (EstadoA || EstadoB)) {digitalWrite(8, HIGH),digitalWrite(9, HIGH),digitalWrite(10, HIGH),digitalWrite(11, LOW),digitalWrite(12, LOW),digitalWrite(13, HIGH),digitalWrite(A5, HIGH),digitalWrite(A4, HIGH);}

  // XNOR (!^!)
    if ((EstadoZ && !EstadoY && EstadoX && !EstadoW) && ((EstadoA && EstadoB) || (!EstadoA && !EstadoB))) {digitalWrite(8, LOW),digitalWrite(9, LOW),digitalWrite(10, HIGH),digitalWrite(11, LOW),digitalWrite(12, LOW),digitalWrite(13, HIGH),digitalWrite(A5, LOW),digitalWrite(A4, LOW);} 
    else if ((EstadoZ && !EstadoY && EstadoX && !EstadoW) && (EstadoA != EstadoB)) {digitalWrite(8, HIGH),digitalWrite(9, HIGH),digitalWrite(10, HIGH),digitalWrite(11, LOW),digitalWrite(12, LOW),digitalWrite(13, HIGH),digitalWrite(A5, HIGH),digitalWrite(A4, HIGH);}

    //NAND &&
    if((EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(!EstadoA||!EstadoB)){digitalWrite(a,LOW),digitalWrite(b,LOW),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,LOW),digitalWrite(h,LOW);}
    else if ((EstadoZ&&!EstadoY&&EstadoX&&EstadoW)&&(EstadoA||EstadoB)){digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
  
  if(!EstadoZ&&!EstadoY&&!EstadoX&&!EstadoW){
  digitalWrite(a,HIGH),digitalWrite(b,HIGH),digitalWrite(c,HIGH),digitalWrite(d,LOW),digitalWrite(e,LOW),digitalWrite(f,HIGH),digitalWrite(g,HIGH),digitalWrite(h,HIGH);}
}


